#include "tmomonitorlisteformu.h"
#include "ui_tmomonitorlisteformu.h"
#include<veriler/TANIMLAR.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<veriler/veri_siniflari/tmomonitor.h>
#include<UI/ListeFormlari/tmomonitorlisteformu.h>

#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
TMOMonitorListeFormu::TMOMonitorListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOMonitorListeFormu)
{
    ui->setupUi(this);
    aramaYap();
}

TMOMonitorListeFormu::~TMOMonitorListeFormu()
{
    delete ui;
}

TMOMonitorYoneticisi::VeriListesi TMOMonitorListeFormu::getListe() const
{
    return liste;
}

void TMOMonitorListeFormu::setListe(const TMOMonitorYoneticisi::VeriListesi &value)
{
    liste = value;
}

void TMOMonitorListeFormu::on_pushButton_clicked()
{
    aramaYap();
}

void TMOMonitorListeFormu::ListeGuncelle()
{
    ui->TWTablo->clear();
    //satır sütun ayarlanır
    ui->TWTablo->setRowCount(liste.length()+1);
    ui->TWTablo->setColumnCount(13);
    QStringList basliklar;
    basliklar << tr("Monitor Id") << tr("Monitor Adi") << tr("Monitor ModelNo")<< tr("Monitor HDMI Baglanti Sayisi") << tr("Monitor Yenileme Hizi") << tr("Monitor Boyutu")
              << tr("Monitor Cozunurluk") << tr("Monitor Renk");
    ui->TWTablo->setHorizontalHeaderLabels(basliklar);

    for(int i=0; i<liste.length(); i++){
        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->TWTablo->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem();

        ui->TWTablo->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem();
       // hucre->setText(liste[i]->getId());
        ui->TWTablo->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getMonitorAdi());
        ui->TWTablo->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getMonitorModelNo());
        ui->TWTablo->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem();
       // hucre->setText(liste[i]->getMonitorHDMIBaglantiSayisi());
        ui->TWTablo->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem();
      //  hucre->setText(liste[i]->getMonitorYenilemeHizi());
        ui->TWTablo->setItem(i, 6, hucre);

        hucre = new QTableWidgetItem();
       // hucre->setText(liste[i]->getMonitorBoyutu());
        ui->TWTablo->setItem(i, 7, hucre);

        hucre = new QTableWidgetItem();
       // hucre->setText(liste[i]->getMonitorCozunurluk());
        ui->TWTablo->setItem(i, 8, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getMonitorRenk());
        ui->TWTablo->setItem(i, 9, hucre);

        hucre = new QTableWidgetItem();

        ui->TWTablo->setItem(i, 10, hucre);

        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Parçayı Sil"));
        ui->TWTablo->setCellWidget(i, 7, silmeButonu);

        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap = QMessageBox::question(
                nullptr,
                tr("Silme Onayı"),
                tr("%1 isimli parçayı silmek istediğinize emin misiniz?").arg(veri_i->getMonitorAdi()));
            if (cevap == QMessageBox::Yes) {
                TMOGenelVeriYoneticisi::sec().getMonitor().Sil(veri_i->getId());
                QMessageBox::information(nullptr,
                                         tr("Kayıt Silindi"),
                                         tr("Kayıt Silme işlemi tamamlandı!"));
                this->aramaYap();
            }
        });
        QPushButton *duzeltmeButonu = new QPushButton(this);
        duzeltmeButonu->setText(tr("Parçayı Düzelt"));
        ui->TWTablo->setCellWidget(i, 8, duzeltmeButonu);

        connect(duzeltmeButonu, &QPushButton::clicked, [veri_i, this]() {
                TMOMonitorListeFormu form;
                form.setWindowTitle(tr("%1 Monitör Bilgilerini Düzenle").arg(veri_i->getMonitorAdi()));
              //  form.setListe(veri_i);
                if(form.exec()==QDialog::Accepted){
                    form.getListe();
                    this->ListeGuncelle();
                }

    });
    }
}

void TMOMonitorListeFormu::aramaYap()
{
    auto ekran = this->ui;
    liste=TMOGenelVeriYoneticisi::sec().getMonitor().TumunuBul([ekran](TMOMonitorYoneticisi::Ptr veri)->bool{
            if(ekran->LEPMarkasiDeger->text()=="" && ekran->LEPModeliDeger->text()==""){
            return true;
            }
            if(ekran->LEPMarkasiDeger->text()!=""){
                if(ekran->RBPMarkasiFTIleBaslayan->isChecked()){
                    if(!veri->getMonitorAdi().toLower().startsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPMarkasiFTIleBiten->isChecked()){
                    if(!veri->getMonitorAdi().toLower().endsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPMarkasiFTIceren->isChecked()){
                    if(!veri->getMonitorAdi().toLower().contains(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            if(ekran->LEPModeliDeger->text()!=""){
                if(ekran->RBPModeliFTIleBaslayan->isChecked()){
                    if(!veri->getMonitorAdi().toLower().startsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPModeliIFTIleBiten->isChecked()){
                    if(!veri->getMonitorAdi().toLower().endsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPModeliFTIceren->isChecked()){
                    if(!veri->getMonitorAdi().toLower().contains(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            return true;
    });

    ListeGuncelle();
}
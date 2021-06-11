#include "tmoislemcilisteformu.h"
#include "ui_tmoislemcilisteformu.h"
#include<veriler/TANIMLAR.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<veriler/veri_siniflari/tmoislemci.h>
#include<UI/ListeFormlari/tmoislemcilisteformu.h>

#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
TMOIslemciListeFormu::TMOIslemciListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOIslemciListeFormu)
{
    ui->setupUi(this);
    aramaYap();
}

TMOIslemciListeFormu::~TMOIslemciListeFormu()
{
    delete ui;
}

TMOIslemciYoneticisi::VeriListesi TMOIslemciListeFormu::getListe() const
{
    return liste;
}

void TMOIslemciListeFormu::setListe(const TMOIslemciYoneticisi::VeriListesi &value)
{
    liste = value;
}

void TMOIslemciListeFormu::on_pushButton_clicked()
{
    aramaYap();
}

void TMOIslemciListeFormu::ListeGuncelle()
{
    ui->TWTablo->clear();
    ui->TWTablo->setRowCount(liste.length()+1);
    ui->TWTablo->setColumnCount(15);

    QStringList basliklar;
    basliklar << tr("Islemci Id") << tr("Islemci Adi") << tr("İslemci ModelNo") << tr("Islemci Soket Tipi") << tr("Islemci Hizi")
              << tr("Islemci Cekirdek Sayisi") << tr("Islemci OnBellek") << tr("Islemci Bellek Turu") << tr("Islemci Guc Tuketimi")
              << tr("Islemci Entegre GPU var mi");
    ui->TWTablo->setHorizontalHeaderLabels(basliklar);

    for(int i=0; i<liste.length(); i++){
        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->TWTablo->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem();


        ui->TWTablo->setItem(i, 1, hucre);

        hucre  = new QTableWidgetItem();
     //   hucre->setText(liste[i]->getId());
        ui->TWTablo->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getIslemciAdi());
        ui->TWTablo->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getIslemciModelNo());
        ui->TWTablo->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getIslemciSoketTipi());
        ui->TWTablo->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getIslemciHizi());
        ui->TWTablo->setItem(i, 6, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getIslemciCekirdekSayisi());
        ui->TWTablo->setItem(i, 7, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getIslemciOnBellek());
        ui->TWTablo->setItem(i, 8, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getIslemciBellekTuru());
        ui->TWTablo->setItem(i, 9, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getIslemciGucTuketimi());
        ui->TWTablo->setItem(i, 10, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getIslemciEntegreGPUvarmi());
        ui->TWTablo->setItem(i, 10, hucre);




        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Parçayı Sil"));
        ui->TWTablo->setCellWidget(i, 13, silmeButonu);

        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap = QMessageBox::question(
                nullptr,
                tr("Silme Onayı"),
                tr("%1 isimli parçayı silmek istediğinize emin misiniz?").arg(veri_i->getIslemciAdi()));
            if (cevap == QMessageBox::Yes) {
                TMOGenelVeriYoneticisi::sec().getIslemci().Sil(veri_i->getId());
                QMessageBox::information(nullptr,
                                         tr("Kayıt Silindi"),
                                         tr("Kayıt Silme işlemi tamamlandı!"));
                this->aramaYap();
            }
        });
        QPushButton *duzeltmeButonu = new QPushButton(this);
        duzeltmeButonu->setText(tr("Parçayı Düzelt"));
        ui->TWTablo->setCellWidget(i, 14, duzeltmeButonu);

        connect(duzeltmeButonu, &QPushButton::clicked, [veri_i, this]() {
                TMOIslemciListeFormu form;
                form.setWindowTitle(tr("%1 İşlemci Bilgilerini Düzenle").arg(veri_i->getIslemciAdi()));
               // form.setListe(veri_i);
                if(form.exec()==QDialog::Accepted){
                    form.getListe();
                    this->ListeGuncelle();
                }

    });
    }

}

void TMOIslemciListeFormu::aramaYap()
{
    auto ekran = this->ui;
    liste=TMOGenelVeriYoneticisi::sec().getIslemci().TumunuBul([ekran](TMOIslemciYoneticisi::Ptr veri)->bool{
            if(ekran->LEPMarkasiDeger->text()=="" && ekran->LEPModeliDeger->text()==""){
            return true;
            }
            if(ekran->LEPMarkasiDeger->text()!=""){
                if(ekran->RBPMarkasiFTIleBaslayan->isChecked()){
                    if(!veri->getIslemciAdi().toLower().startsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPMarkasiFTIleBiten->isChecked()){
                    if(!veri->getIslemciAdi().toLower().endsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPMarkasiFTIceren->isChecked()){
                    if(!veri->getIslemciAdi().toLower().contains(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            if(ekran->LEPModeliDeger->text()!=""){
                if(ekran->RBPModeliFTIleBaslayan->isChecked()){
                    if(!veri->getIslemciAdi().toLower().startsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPModeliIFTIleBiten->isChecked()){
                    if(!veri->getIslemciAdi().toLower().endsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPModeliFTIceren->isChecked()){
                    if(!veri->getIslemciAdi().toLower().contains(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            return true;
    });

    ListeGuncelle();
}

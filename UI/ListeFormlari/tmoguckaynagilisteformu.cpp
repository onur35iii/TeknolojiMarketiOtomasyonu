#include "tmoguckaynagilisteformu.h"
#include "ui_tmoguckaynagilisteformu.h"
#include<veriler/TANIMLAR.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<veriler/veri_siniflari/tmoguckaynagi.h>
#include<UI/ListeFormlari/tmoguckaynagilisteformu.h>
#include<UI/VeriFormlari/tmoguckaynagitanimlamaformu.h>
#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
TMOGucKaynagiListeFormu::TMOGucKaynagiListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOGucKaynagiListeFormu)
{
    ui->setupUi(this);
        aramaYap();
}

TMOGucKaynagiListeFormu::~TMOGucKaynagiListeFormu()
{
    delete ui;
}

TMOGucKaynagiYoneticisi::VeriListesi TMOGucKaynagiListeFormu::getListe() const
{
    return liste;
}

void TMOGucKaynagiListeFormu::setListe(const TMOGucKaynagiYoneticisi::VeriListesi &value)
{
    liste = value;
}

void TMOGucKaynagiListeFormu::on_pushButton_clicked()
{
        aramaYap();
}



void TMOGucKaynagiListeFormu::ListeGuncelle()
{
    ui->TWTablo->clear();
    //satır sütun ayarlanır
    ui->TWTablo->setRowCount(liste.length()+1);
    ui->TWTablo->setColumnCount(8);
    QStringList basliklar;
    basliklar << tr("Parça ID") << tr("Parça Türü") << tr("Parça Markası") << tr("Parça Modeli") << tr("Güç Değeri")
              << tr("Fan Boyutu");
    ui->TWTablo->setHorizontalHeaderLabels(basliklar);

    for(int i=0; i<liste.length(); i++){
        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->TWTablo->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getGucKaynagiAdi());
        ui->TWTablo->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getGucKaynagiModelNo());
        ui->TWTablo->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getGucKaynagiFanBoyutu()));
        ui->TWTablo->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getGucKaynagiDegeri()));
        ui->TWTablo->setItem(i, 4, hucre);

        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Parçayı Sil"));
        ui->TWTablo->setCellWidget(i, 5, silmeButonu);

        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap = QMessageBox::question(
                nullptr,
                tr("Silme Onayı"),
                tr("%1 isimli parçayı silmek istediğinize emin misiniz?").arg(veri_i->getGucKaynagiAdi()));
            if (cevap == QMessageBox::Yes) {
                TMOGenelVeriYoneticisi::sec().getGucKaynagi().Sil(veri_i->getId());
                QMessageBox::information(nullptr,
                                         tr("Kayıt Silindi"),
                                         tr("Kayıt Silme işlemi tamamlandı!"));
                this->aramaYap();
            }
        });
        QPushButton *duzeltmeButonu = new QPushButton(this);
        duzeltmeButonu->setText(tr("Parçayı Düzelt"));
        ui->TWTablo->setCellWidget(i, 6, duzeltmeButonu);

        connect(duzeltmeButonu, &QPushButton::clicked, [veri_i, this]() {
                TMOGucKaynagiTanimlamaFormu form;
                form.setWindowTitle(tr("%1 Güç Kaynak Bilgilerini Düzenle").arg(veri_i->getGucKaynagiAdi()));
               form.setVeri(veri_i);
                if(form.exec()==QDialog::Accepted){
                    form.getVeri();
                    this->ListeGuncelle();
                }

    });
    }

}

void TMOGucKaynagiListeFormu::aramaYap()
{
    auto ekran = this->ui;
    liste=TMOGenelVeriYoneticisi::sec().getGucKaynagi().TumunuBul([ekran](TMOGucKaynagiYoneticisi::Ptr veri)->bool{
            if(ekran->LEPMarkasiDeger->text()=="" && ekran->LEPModeliDeger->text()==""){
            return true;
            }
            if(ekran->LEPMarkasiDeger->text()!=""){
                if(ekran->RBPMarkasiFTIleBaslayan->isChecked()){
                    if(!veri->getGucKaynagiAdi().toLower().startsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPMarkasiFTIleBiten->isChecked()){
                    if(!veri->getGucKaynagiAdi().toLower().endsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPMarkasiFTIceren->isChecked()){
                    if(!veri->getGucKaynagiAdi().toLower().contains(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            if(ekran->LEPModeliDeger->text()!=""){
                if(ekran->RBPModeliFTIleBaslayan->isChecked()){
                    if(!veri->getGucKaynagiAdi().toLower().startsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPModeliIFTIleBiten->isChecked()){
                    if(!veri->getGucKaynagiAdi().toLower().endsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPModeliFTIceren->isChecked()){
                    if(!veri->getGucKaynagiAdi().toLower().contains(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            return true;
    });

    ListeGuncelle();

}

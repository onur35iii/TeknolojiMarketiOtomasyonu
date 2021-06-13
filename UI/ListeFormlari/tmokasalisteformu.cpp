#include "tmokasalisteformu.h"
#include "ui_tmokasalisteformu.h"
#include<veriler/TANIMLAR.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<veriler/veri_siniflari/tmokasa.h>
#include<UI/ListeFormlari/tmokasalisteformu.h>
#include<UI/VeriFormlari/tmokasatanimlamaformu.h>
#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
TMOKasaListeFormu::TMOKasaListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOKasaListeFormu)
{
    ui->setupUi(this);
     aramaYap();
}

TMOKasaListeFormu::~TMOKasaListeFormu()
{
    delete ui;
}

TMOKasaYoneticisi::VeriListesi TMOKasaListeFormu::getListe() const
{
    return liste;
}

void TMOKasaListeFormu::setListe(const TMOKasaYoneticisi::VeriListesi &value)
{
    liste = value;
}

void TMOKasaListeFormu::on_pushButton_clicked()
{
     aramaYap();
}

void TMOKasaListeFormu::ListeGuncelle()
{
    ui->TWTablo->clear();
    //satır sütun ayarlanır
    ui->TWTablo->setRowCount(liste.length()+1);
    ui->TWTablo->setColumnCount(18);
    QStringList basliklar;
    basliklar << tr("KasaId") << tr("KasaAdi") << tr("KasaModelNo") << tr("KasaFanSayisi") << tr("KasaGucKaynagivarmi")
              << tr("KasaBoyutu") << tr(" KasaAnakartYapisi") << tr("KasaRenk") ;
    ui->TWTablo->setHorizontalHeaderLabels(basliklar);

    for(int i=0; i<liste.length(); i++){
        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->TWTablo->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem();

        ui->TWTablo->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem();
     //   hucre->setText(liste[i]->getId());
        ui->TWTablo->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKasaAdi());
        ui->TWTablo->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKasaModelNo());
        ui->TWTablo->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKasaFanSayisi());
        ui->TWTablo->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKasaGucKaynagivarmi());
        ui->TWTablo->setItem(i, 6, hucre);

        hucre = new QTableWidgetItem();
   //     hucre->setText(liste[i]->getKasaBoyutu());
        ui->TWTablo->setItem(i, 7, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKasaAnakartYapisi());
        ui->TWTablo->setItem(i, 8, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKasaRenk());
        ui->TWTablo->setItem(i, 9, hucre);

        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Parçayı Sil"));
        ui->TWTablo->setCellWidget(i, 10, silmeButonu);

        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap = QMessageBox::question(
                nullptr,
                tr("Silme Onayı"),
                tr("%1 isimli parçayı silmek istediğinize emin misiniz?").arg(veri_i->getKasaAdi()));
            if (cevap == QMessageBox::Yes) {
                TMOGenelVeriYoneticisi::sec().getKasa().Sil(veri_i->getId());
                QMessageBox::information(nullptr,
                                         tr("Kayıt Silindi"),
                                         tr("Kayıt Silme işlemi tamamlandı!"));
                this->aramaYap();
            }
        });
        QPushButton *duzeltmeButonu = new QPushButton(this);
        duzeltmeButonu->setText(tr("Parçayı Düzelt"));
        ui->TWTablo->setCellWidget(i, 11, duzeltmeButonu);

        connect(duzeltmeButonu, &QPushButton::clicked, [veri_i, this]() {
                TMOKasaTanimlamaFormu form;
                form.setWindowTitle(tr("%1 Kasa Bilgilerini Düzenle").arg(veri_i->getKasaAdi()));
                form.setVeri(veri_i);
                if(form.exec()==QDialog::Accepted){
                    form.getVeri();
                    this->ListeGuncelle();
                }

    });
    }
}

void TMOKasaListeFormu::aramaYap()
{
    auto ekran = this->ui;
    liste=TMOGenelVeriYoneticisi::sec().getKasa().TumunuBul([ekran](TMOKasaYoneticisi::Ptr veri)->bool{
            if(ekran->LEPMarkasiDeger->text()=="" && ekran->LEPModeliDeger->text()==""){
            return true;
            }
            if(ekran->LEPMarkasiDeger->text()!=""){
                if(ekran->RBPMarkasiFTIleBaslayan->isChecked()){
                    if(!veri->getKasaAdi().toLower().startsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPMarkasiFTIleBiten->isChecked()){
                    if(!veri->getKasaAdi().toLower().endsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPMarkasiFTIceren->isChecked()){
                    if(!veri->getKasaAdi().toLower().contains(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            if(ekran->LEPModeliDeger->text()!=""){
                if(ekran->RBPModeliFTIleBaslayan->isChecked()){
                    if(!veri->getKasaAdi().toLower().startsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPModeliIFTIleBiten->isChecked()){
                    if(!veri->getKasaAdi().toLower().endsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPModeliFTIceren->isChecked()){
                    if(!veri->getKasaAdi().toLower().contains(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            return true;
    });

    ListeGuncelle();
}

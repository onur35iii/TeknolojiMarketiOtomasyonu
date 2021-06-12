#include "tmofarelisteformu.h"
#include "ui_tmofarelisteformu.h"
#include<veriler/TANIMLAR.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<veriler/veri_siniflari/tmofare.h>
#include<UI/ListeFormlari/tmofarelisteformu.h>

#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
TMOFareListeFormu::TMOFareListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOFareListeFormu)
{
    ui->setupUi(this);
        aramaYap();
}

TMOFareListeFormu::~TMOFareListeFormu()
{
    delete ui;
}

TMOFareYoneticisi::VeriListesi TMOFareListeFormu::getListe() const
{
    return liste;
}

void TMOFareListeFormu::setListe(const TMOFareYoneticisi::VeriListesi &value)
{
    liste = value;
}

void TMOFareListeFormu::on_pushButton_clicked()
{
     aramaYap();
}



void TMOFareListeFormu::ListeGuncelle()
{
    ui->TWTablo->clear();
    ui->TWTablo->setRowCount(liste.length()+1);
    ui->TWTablo->setColumnCount(9);
    QStringList basliklar;
    basliklar << tr("Fare Id") << tr("Fare Adı") << tr("Fare ModelNO") << tr("Fare Renk") << tr("Fare DPI;")
              << tr("Fare Bağlantı Türü");
    ui->TWTablo->setHorizontalHeaderLabels(basliklar);

    for(int i=0; i<liste.length(); i++){
        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->TWTablo->setItem(i, 0, hucre);

        ui->TWTablo->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem();
//* hucre->setText(liste[i]->getId());
        ui->TWTablo->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getFareAdi());
        ui->TWTablo->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getFareModeli());
        ui->TWTablo->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getFareRenk());
        ui->TWTablo->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem();
//* hucre->setText(liste[i]->getFareDPI());
        ui->TWTablo->setItem(i, 6, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getFareBaglantiTuru());
        ui->TWTablo->setItem(i, 7, hucre);

        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Parçayı Sil"));
        ui->TWTablo->setCellWidget(i, 8, silmeButonu);

        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap = QMessageBox::question(
                nullptr,
                tr("Silme Onayı"),
                tr("%1 isimli parçayı silmek istediğinize emin misiniz?").arg(veri_i->getFareAdi()));
            if (cevap == QMessageBox::Yes) {
                TMOGenelVeriYoneticisi::sec().getFare().Sil(veri_i->getId());
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
                TMOFareListeFormu form;
                form.setWindowTitle(tr("%1 Fare Bilgilerini Düzenle").arg(veri_i->getFareAdi()));
   //*             form.setListe(veri_i);
                if(form.exec()==QDialog::Accepted){
                    form.getListe();
                    this->ListeGuncelle();
                }

    });
    }

}


void TMOFareListeFormu::aramaYap()
{
    auto ekran = this->ui;
    liste=TMOGenelVeriYoneticisi::sec().getFare().TumunuBul([ekran](TMOFareYoneticisi::Ptr veri)->bool{
            if(ekran->LEPMarkasiDeger->text()=="" && ekran->LEPModeliDeger->text()==""){
            return true;
            }
            if(ekran->LEPMarkasiDeger->text()!=""){
                if(ekran->RBPMarkasiFTIleBaslayan->isChecked()){
                    if(!veri->getFareAdi().toLower().startsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPMarkasiFTIleBiten->isChecked()){
                    if(!veri->getFareAdi().toLower().endsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPMarkasiFTIceren->isChecked()){
                    if(!veri->getFareAdi().toLower().contains(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            if(ekran->LEPModeliDeger->text()!=""){
                if(ekran->RBPModeliFTIleBaslayan->isChecked()){
                    if(!veri->getFareAdi().toLower().startsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPModeliIFTIleBiten->isChecked()){
                    if(!veri->getFareAdi().toLower().endsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPModeliFTIceren->isChecked()){
                    if(!veri->getFareAdi().toLower().contains(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            return true;
    });

    ListeGuncelle();

}
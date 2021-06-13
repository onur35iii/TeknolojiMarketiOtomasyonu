#include "tmoanakartlisteformu.h"
#include "ui_tmoanakartlisteformu.h"
#include<veriler/TANIMLAR.h>
#include<veriler/veri_siniflari/tmoanakart.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<UI/VeriFormlari/tmoyenianakarttanimlamaformu.h>

#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>

TMOAnakartListeFormu::TMOAnakartListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOAnakartListeFormu)
{
    ui->setupUi(this);
     aramaYap();
}

TMOAnakartListeFormu::~TMOAnakartListeFormu()
{
    delete ui;
}

TMOAnakartYoneticisi::VeriListesi TMOAnakartListeFormu::getListe() const
{

    return liste;
}

void TMOAnakartListeFormu::setListe(const TMOAnakartYoneticisi::VeriListesi &value)
{
    liste = value;
}

void TMOAnakartListeFormu::on_pushButton_clicked()
{
    aramaYap();
}



void TMOAnakartListeFormu::ListeGuncelle()
{
    ui->TWTablo->clear();

    ui->TWTablo->setRowCount(liste.length()+1);
    ui->TWTablo->setColumnCount(16);
    QStringList basliklar;
    basliklar << tr("Anakart ID  ") << tr("Anakart Adı") << tr("Anakart ModelNO") << tr("Anakart Soket Tipi") << tr("Anakart Chipseti")
              <<  tr("Anakart RAM Tipi ") << tr("Anakart VGA Slotu") << tr("Anakart Boyutu");
    ui->TWTablo->setHorizontalHeaderLabels(basliklar);

    for(int i=0; i<liste.length(); i++)
    {
        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->TWTablo->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getAnakartModelNo());
        ui->TWTablo->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getAnakartSoketTipi());
        ui->TWTablo->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getAnakartChipseti());
        ui->TWTablo->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getAnakartRamTipi());
        ui->TWTablo->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getAnakartVgaSlotu());
        ui->TWTablo->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getAnakartBoyutu());
        ui->TWTablo->setItem(i, 6, hucre);

        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Parçayı Sil"));
        ui->TWTablo->setCellWidget(i, 7, silmeButonu);

        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]()
        {
            auto cevap = QMessageBox::question(
                nullptr,
                tr("Silme Onayı"),
                tr("%1 isimli parçayı silmek istediğinize emin misiniz?").arg(veri_i->getAnakartAdi()));
            if (cevap == QMessageBox::Yes)
             {

                TMOGenelVeriYoneticisi::sec().getAnakart().Sil(veri_i->getId());
                QMessageBox::information(nullptr, tr("Kayıt Silindi"),tr("Kayıt Silme işlemi tamamlandı!"));
                this->aramaYap();
             }
       });
        QPushButton *duzeltmeButonu = new QPushButton(this);
        duzeltmeButonu->setText(tr("Parçayı Düzelt"));
        ui->TWTablo->setCellWidget(i, 8, duzeltmeButonu);

        connect(duzeltmeButonu, &QPushButton::clicked, [veri_i, this]() {
                TMOYeniAnakartTanimlamaFormu form;
                form.setWindowTitle(veri_i->getAnakartAdi());
                form.setVeri(veri_i);
                if(form.exec()==QDialog::Accepted){
                    form.getVeri();
                    this->ListeGuncelle();
                }

    });
    }
}

void TMOAnakartListeFormu::aramaYap()
{
    auto ekran = this->ui;
    liste=TMOGenelVeriYoneticisi::sec().getAnakart().TumunuBul([ekran](TMOAnakartYoneticisi::Ptr veri)->bool{
            if(ekran->LEPMarkasiDeger->text()=="" && ekran->LEPModeliDeger->text()==""){
            return true;
            }
            if(ekran->LEPMarkasiDeger->text()!=""){
                if(ekran->RBPMarkasiFTIleBaslayan->isChecked()){
                    if(!veri->getAnakartAdi().toLower().startsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPMarkasiFTIleBiten->isChecked()){
                    if(!veri->getAnakartAdi().toLower().endsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPMarkasiFTIceren->isChecked()){
                    if(!veri->getAnakartAdi().toLower().contains(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            if(ekran->LEPModeliDeger->text()!=""){
                if(ekran->RBPModeliFTIleBaslayan->isChecked()){
                    if(!veri->getAnakartAdi().toLower().startsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPModeliIFTIleBiten->isChecked()){
                    if(!veri->getAnakartAdi().toLower().endsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPModeliFTIceren->isChecked()){
                    if(!veri->getAnakartAdi().toLower().contains(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            return true;
    });

    ListeGuncelle();
}

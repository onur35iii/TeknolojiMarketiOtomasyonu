#include "tmoramlisteformu.h"
#include "ui_tmoramlisteformu.h"

#include<veriler/TANIMLAR.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<veriler/veri_siniflari/tmoram.h>
#include<UI/ListeFormlari/tmoramlisteformu.h>

#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
TMORAMListeFormu::TMORAMListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMORAMListeFormu)
{
    ui->setupUi(this);
    aramaYap();
}

TMORAMListeFormu::~TMORAMListeFormu()
{
    delete ui;
}

void TMORAMListeFormu::on_pushButton_clicked()
{
    aramaYap();
}

void TMORAMListeFormu::ListeGuncelle()
{
    ui->TWTablo->clear();
    //satır sütun ayarlanır
    ui->TWTablo->setRowCount(liste.length()+1);
    ui->TWTablo->setColumnCount(10);
    QStringList basliklar;
    basliklar << tr("RamId") << tr("RamAdi") << tr("RamModelNo") << tr("Ramtipi") << tr("RamBushizi")
              << tr("RamKapasitesi") << tr("RamGecikmeSuresi");
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
        hucre->setText(liste[i]->getRamAdi());
        ui->TWTablo->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getRamModelNo());
        ui->TWTablo->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getRamtipi());
        ui->TWTablo->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getRamBushizi());
        ui->TWTablo->setItem(i, 6, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getRamKapasitesi());
        ui->TWTablo->setItem(i, 7, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getRamGecikmeSuresi());
        ui->TWTablo->setItem(i, 8, hucre);

        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Parçayı Sil"));
        ui->TWTablo->setCellWidget(i, 9, silmeButonu);

        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap = QMessageBox::question(
                nullptr,
                tr("Silme Onayı"),
                tr("%1 isimli parçayı silmek istediğinize emin misiniz?").arg(veri_i->getRamAdi()));
            if (cevap == QMessageBox::Yes) {
                TMOGenelVeriYoneticisi::sec().getRAM().Sil(veri_i->getId());
                QMessageBox::information(nullptr,
                                         tr("Kayıt Silindi"),
                                         tr("Kayıt Silme işlemi tamamlandı!"));
                this->aramaYap();
            }
        });
        QPushButton *duzeltmeButonu = new QPushButton(this);
        duzeltmeButonu->setText(tr("Parçayı Düzelt"));
        ui->TWTablo->setCellWidget(i, 9, duzeltmeButonu);

        connect(duzeltmeButonu, &QPushButton::clicked, [veri_i, this]() {
                TMORAMListeFormu form;
                form.setWindowTitle(tr("%1 Monitör Bilgilerini Düzenle").arg(veri_i->getRamAdi()));
              //  form.setListe(veri_i);
                if(form.exec()==QDialog::Accepted){
                   // form.getliste();
                    this->ListeGuncelle(); }

    });
    }
}

void TMORAMListeFormu::aramaYap()
{
    auto ekran = this->ui;
    liste=TMOGenelVeriYoneticisi::sec().getRAM().TumunuBul([ekran](TMORAMYoneticisi::Ptr veri)->bool{
            if(ekran->LEPMarkasiDeger->text()=="" && ekran->LEPModeliDeger->text()==""){
            return true;
            }
            if(ekran->LEPMarkasiDeger->text()!=""){
                if(ekran->RBPMarkasiFTIleBaslayan->isChecked()){
                    if(!veri->getRamAdi().toLower().startsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPMarkasiFTIleBiten->isChecked()){
                    if(!veri->getRamAdi().toLower().endsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPMarkasiFTIceren->isChecked()){
                    if(!veri->getRamAdi().toLower().contains(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            if(ekran->LEPModeliDeger->text()!=""){
                if(ekran->RBPModeliFTIleBaslayan->isChecked()){
                    if(!veri->getRamAdi().toLower().startsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPModeliIFTIleBiten->isChecked()){
                    if(!veri->getRamAdi().toLower().endsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPModeliFTIceren->isChecked()){
                    if(!veri->getRamAdi().toLower().contains(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            return true;
    });

    ListeGuncelle();
}

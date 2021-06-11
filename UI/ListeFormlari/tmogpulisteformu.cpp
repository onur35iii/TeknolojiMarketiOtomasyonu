#include "tmogpulisteformu.h"
#include "ui_tmogpulisteformu.h"

#include<veriler/TANIMLAR.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<veriler/veri_siniflari/tmogpu.h>
#include<UI/ListeFormlari/tmogpulisteformu.h>

#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
TMOGPUListeFormu::TMOGPUListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOGPUListeFormu)
{
    ui->setupUi(this);
    aramaYap();
}

TMOGPUListeFormu::~TMOGPUListeFormu()
{
    delete ui;
}

TMOGPUYoneticisi::VeriListesi TMOGPUListeFormu::getListe() const
{
    return liste;
}

void TMOGPUListeFormu::setListe(const TMOGPUYoneticisi::VeriListesi &value)
{
    liste = value;
}

void TMOGPUListeFormu::on_pushButton_clicked()
{
 aramaYap();
}



void TMOGPUListeFormu::ListeGuncelle()
{
    ui->TWTablo->clear();
    ui->TWTablo->setRowCount(liste.length()+1);
    ui->TWTablo->setColumnCount(13);

    QStringList basliklar;
    basliklar << tr("GPUId") << tr("GPU Adı") << tr("GPU ModelNo") << tr("GPU Bellek Hızı") << tr("GPU Slot Sayısı")
              << tr("Güç Tüketimi") << tr("GPU Boyutu")  ;
    ui->TWTablo->setHorizontalHeaderLabels(basliklar);

    for(int i=0; i<liste.length(); i++){
        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->TWTablo->setItem(i, 0, hucre);

        ui->TWTablo->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem();
//**        hucre->setText(liste[i]->getId());
        ui->TWTablo->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getGPUAdi());
        ui->TWTablo->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getGPUModelNo());
        ui->TWTablo->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getGPUBellekHizi());
        ui->TWTablo->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem();
  //**  hucre->setText(liste[i]->getGPUSlotSayisi());
        ui->TWTablo->setItem(i, 6, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getGucTuketimi());
        ui->TWTablo->setItem(i, 7, hucre);

        hucre = new QTableWidgetItem();
 //**   hucre->setText(liste[i]->getGPUBoyutu());
        ui->TWTablo->setItem(i, 7, hucre);

        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Parçayı Sil"));
        ui->TWTablo->setCellWidget(i, 8, silmeButonu);
        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap = QMessageBox::question(
                nullptr,
                tr("Silme Onayı"),
                tr("%1 isimli parçayı silmek istediğinize emin misiniz?").arg(veri_i->getGPUAdi()));
            if (cevap == QMessageBox::Yes) {
                TMOGenelVeriYoneticisi::sec().getGPU().Sil(veri_i->getId());
                QMessageBox::information(nullptr,
                                         tr("Kayıt Silindi"),
                                         tr("Kayıt Silme işlemi tamamlandı!"));
                this->aramaYap();
            }
        });
        QPushButton *duzeltmeButonu = new QPushButton(this);
        duzeltmeButonu->setText(tr("Parçayı Düzelt"));
        ui->TWTablo->setCellWidget(i, 12, duzeltmeButonu);

        connect(duzeltmeButonu, &QPushButton::clicked, [veri_i, this]() {
                TMOGPUListeFormu form;
                form.setWindowTitle(tr("%1 Ekran Kartı Bilgilerini Düzenle").arg(veri_i->getGPUAdi()));
  //*              form.setListe(veri_i);
                if(form.exec()==QDialog::Accepted){
                    form.getListe();
                    this->ListeGuncelle();
                }

        });
    }
}

void TMOGPUListeFormu::aramaYap()
{
    auto ekran = this->ui;
    liste=TMOGenelVeriYoneticisi::sec().getGPU().TumunuBul([ekran](TMOGPUYoneticisi::Ptr veri)->bool{
            if(ekran->LEPMarkasiDeger->text()=="" && ekran->LEPModeliDeger->text()==""){
            return true;
            }
            if(ekran->LEPMarkasiDeger->text()!=""){
                if(ekran->RBPMarkasiFTIleBaslayan->isChecked()){
                    if(!veri->getGPUAdi().toLower().startsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPMarkasiFTIleBiten->isChecked()){
                    if(!veri->getGPUAdi().toLower().endsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPMarkasiFTIceren->isChecked()){
                    if(!veri->getGPUAdi().toLower().contains(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            if(ekran->LEPModeliDeger->text()!=""){
                if(ekran->RBPModeliFTIleBaslayan->isChecked()){
                    if(!veri->getGPUAdi().toLower().startsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPModeliIFTIleBiten->isChecked()){
                    if(!veri->getGPUAdi().toLower().endsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPModeliFTIceren->isChecked()){
                    if(!veri->getGPUAdi().toLower().contains(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            return true;
    });

    ListeGuncelle();

}



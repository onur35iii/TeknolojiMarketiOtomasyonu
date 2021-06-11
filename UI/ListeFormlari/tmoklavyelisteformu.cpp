#include "tmoklavyelisteformu.h"
#include "ui_tmoklavyelisteformu.h"
#include<veriler/TANIMLAR.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<veriler/veri_siniflari/tmoklavye.h>
#include<UI/ListeFormlari/tmoklavyelisteformu.h>

#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
TMOKlavyeListeFormu::TMOKlavyeListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOKlavyeListeFormu)
{
    ui->setupUi(this);
        aramaYap();
}

TMOKlavyeListeFormu::~TMOKlavyeListeFormu()
{
    delete ui;
}

TMOKlavyeYoneticisi::VeriListesi TMOKlavyeListeFormu::getListe() const
{
    return liste;
}

void TMOKlavyeListeFormu::setListe(const TMOKlavyeYoneticisi::VeriListesi &value)
{
    liste = value;
}

void TMOKlavyeListeFormu::on_pushButton_clicked()
{
        aramaYap();
}

void TMOKlavyeListeFormu::ListeGuncelle()
{
    ui->TWTablo->clear();
    //satır sütun ayarlanır
    ui->TWTablo->setRowCount(liste.length()+1);
    ui->TWTablo->setColumnCount(9);
    QStringList basliklar;
    basliklar << tr("KlavyeAdi") << tr("KlavyeModelNo;") << tr("KlavyeTuru") << tr("KlavyeRenk");
    ui->TWTablo->setHorizontalHeaderLabels(basliklar);

    for(int i=0; i<liste.length(); i++){
        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->TWTablo->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem();

        ui->TWTablo->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem();
        //hucre->setText(liste[i]->getId());
        ui->TWTablo->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKlavyeAdi());
        ui->TWTablo->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKlavyeModelNo());
        ui->TWTablo->setItem(i, 4, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKlavyeTuru());
        ui->TWTablo->setItem(i, 5, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getKlavyeRenk());
        ui->TWTablo->setItem(i, 6, hucre);

        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Parçayı Sil"));
        ui->TWTablo->setCellWidget(i, 7, silmeButonu);

        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap = QMessageBox::question(
                nullptr,
                tr("Silme Onayı"),
                tr("%1 isimli parçayı silmek istediğinize emin misiniz?").arg(veri_i->getKlavyeAdi()));
            if (cevap == QMessageBox::Yes) {
                TMOGenelVeriYoneticisi::sec().getKlavye().Sil(veri_i->getId());
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
                TMOKlavyeListeFormu form;
                form.setWindowTitle(tr("%1 Klavye Bilgilerini Düzenle").arg(veri_i->getKlavyeAdi()));
               // form.setListe(veri_i);
                if(form.exec()==QDialog::Accepted){
                    form.getListe();
                    this->ListeGuncelle();
                }

    });
    }
}

void TMOKlavyeListeFormu::aramaYap()
{
    auto ekran = this->ui;
    liste=TMOGenelVeriYoneticisi::sec().getKlavye().TumunuBul([ekran](TMOKlavyeYoneticisi::Ptr veri)->bool{
            if(ekran->LEPMarkasiDeger->text()=="" && ekran->LEPModeliDeger->text()==""){
            return true;
            }
            if(ekran->LEPMarkasiDeger->text()!=""){
                if(ekran->RBPMarkasiFTIleBaslayan->isChecked()){
                    if(!veri->getKlavyeAdi().toLower().startsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPMarkasiFTIleBiten->isChecked()){
                    if(!veri->getKlavyeAdi().toLower().endsWith(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPMarkasiFTIceren->isChecked()){
                    if(!veri->getKlavyeAdi().toLower().contains(ekran->LEPMarkasiDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            if(ekran->LEPModeliDeger->text()!=""){
                if(ekran->RBPModeliFTIleBaslayan->isChecked()){
                    if(!veri->getKlavyeAdi().toLower().startsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                }else if(ekran->RBPModeliIFTIleBiten->isChecked()){
                    if(!veri->getKlavyeAdi().toLower().endsWith(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }else if(ekran->RBPModeliFTIceren->isChecked()){
                    if(!veri->getKlavyeAdi().toLower().contains(ekran->LEPModeliDeger->text().toLower())){
                        return false;
                    }
                 }
            }
            return true;
    });

    ListeGuncelle();
}

#include "tmotedarikcilistewidget.h"
#include "ui_tmotedarikcilistewidget.h"
#include <veriler/veri_siniflari/tmotedarikcibilgileri.h>
#include <UI/VeriFormlari/tmotedarikciformu.h>
#include <veriler/tmogenelveriyoneticisi.h>
#include <QMessageBox>
TMOTedarikciListeWidget::TMOTedarikciListeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TMOTedarikciListeWidget)
{
    ui->setupUi(this);
    arama_yap();
}

TMOTedarikciListeWidget::~TMOTedarikciListeWidget()
{
    delete ui;
}

void TMOTedarikciListeWidget::arama_yap()
{
    auto ekran = this->ui;

    liste = TMOGenelVeriYoneticisi::sec().getTedarikci().TumunuBul(
        [ekran](TMOTedarikciBilgileriYoneticisi::Ptr veri) -> bool {
            if (ekran->leTedarikciAdiDegeri->text() == ""
                && ekran->leYetkiliKisiDegeri->text() == "") {
                return true;
            }
            //410316OnurOkuyucu
                //410306MuharremKorkmaz
                //410305CoskunKocer
            if (ekran->leTedarikciAdiDegeri->text() != "") {
                if (ekran->rbTedarikciAdiIleBaslayan->isChecked()) {
                    if (!veri->getTedarikciAdi().toLower().startsWith(
                            ekran->leTedarikciAdiDegeri->text().toLower())) {
                        return false;
                    }
                } else if (ekran->rbTedarikciAdiIleBiten->isChecked()) {
                    if (!veri->getTedarikciAdi().toLower().endsWith(
                            ekran->leTedarikciAdiDegeri->text().toLower())) {
                        return false;
                    }
                } else if (ekran->rbTedarikciAdiIceren->isChecked()) {
                    if (!veri->getTedarikciAdi().toLower().contains(
                            ekran->leTedarikciAdiDegeri->text().toLower())) {
                        return false;
                    }
                }
            }

            if (ekran->leYetkiliKisiDegeri->text() != "") {
                if (ekran->rbYetkiliKisiIleBaslayan->isChecked()) {
                    if (!veri->getTedarikciYetkiliKisi().toLower().startsWith(
                            ekran->leYetkiliKisiDegeri->text().toLower())) {
                        return false;
                    }
                } else if (ekran->rbYetkiliKisiIleBiten->isChecked()) {
                    if (!veri->getTedarikciYetkiliKisi().toLower().endsWith(
                            ekran->leYetkiliKisiDegeri->text().toLower())) {
                        return false;
                    }
                } else if (ekran->rbYetkiliKisiIceren->isChecked()) {
                    if (!veri->getTedarikciYetkiliKisi().toLower().contains(
                            ekran->leYetkiliKisiDegeri->text().toLower())) {
                        return false;
                    }
                }
            }

            return true;
        });

    listeGuncelle();
}

void TMOTedarikciListeWidget::ara()
{

}

void TMOTedarikciListeWidget::listeGuncelle()
{
    ui->tblVeriler->clear();
    ui->tblVeriler->setRowCount(liste.length());
    ui->tblVeriler->setColumnCount(7);

    QStringList basliklar;
    basliklar << tr("Tedarikçi ID") << tr("Tedarikçi Adı") << tr("Adresi") << tr("Telefon") << tr("Yetkili Kişi") << tr("Tedarikçi Sil") << tr("Tedarikçi Düzelt");
    ui->tblVeriler->setHorizontalHeaderLabels(basliklar);


    for (int i = 0; i < liste.length(); i++)
    {
        QTableWidgetItem *hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(liste[i]->getId()));
        ui->tblVeriler->setItem(i, 0, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getTedarikciAdi());
        ui->tblVeriler->setItem(i, 1, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getTedarikciAdresi());
        ui->tblVeriler->setItem(i, 2, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getTedarikciTelefonNo());
        ui->tblVeriler->setItem(i, 3, hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(liste[i]->getTedarikciYetkiliKisi());
        ui->tblVeriler->setItem(i, 4, hucre);

        QPushButton *silmeButonu = new QPushButton(this);
        silmeButonu->setText(tr("Tedarikçi Sil"));
        ui->tblVeriler->setCellWidget(i, 5, silmeButonu);

        auto veri_i = liste[i];

        connect(silmeButonu, &QPushButton::clicked, [veri_i, this]() {
            auto cevap
                = QMessageBox::question(nullptr,
                                        tr("Silme Onayı"),
                                        tr("%1 isimli tedarikçiyi simek istediğinize emin misiniz?")
                                            .arg(veri_i->getTedarikciAdi()));
            if (cevap == QMessageBox::Yes) {
                TMOGenelVeriYoneticisi::sec().getTedarikci().Sil(veri_i->getId());
                QMessageBox::information(nullptr,
                                         tr("Kayıt Silindi"),
                                         tr("Kayıt Silme işlemi tamamlandı!"));
                this->arama_yap();
            }
        });

        QPushButton *duzeltmeButonu = new QPushButton(this);
        duzeltmeButonu->setText(tr("Tedarikçi Düzelt"));
        ui->tblVeriler->setCellWidget(i, 6, duzeltmeButonu);

        connect(duzeltmeButonu, &QPushButton::clicked, [veri_i, this]() {
            emit this->duzeltmeTalepEdildi(veri_i);

        });
    }
}

void TMOTedarikciListeWidget::on_btnAra_clicked()
{
    arama_yap();
}

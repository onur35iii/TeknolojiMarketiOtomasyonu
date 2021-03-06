#include "tmoyenifaretanimlamaformu.h"
#include "ui_tmoyenifaretanimlamaformu.h"
#include <veriler/veri_siniflari/tmofare.h>
TMOYeniFareTanimlamaFormu::TMOYeniFareTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOYeniFareTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOYeniFareTanimlamaFormu::~TMOYeniFareTanimlamaFormu()
{
    delete ui;
}

TMOFarePtr TMOYeniFareTanimlamaFormu::getVeri() const
{
    veri->setFareAdi(ui->LEMarka->text());
    veri->setFareModeli(ui->LEModeli->text());
    veri->setFareRenk(ui->LERenk->text());
    veri->setFareDPI(ui->SPDPI->value());
    veri->setFareBaglantiTuru(ui->LEBaglantiTuru->text());

    return veri;
}

void TMOYeniFareTanimlamaFormu::setVeri(const TMOFarePtr &value)
{//410316OnurOkuyucu
    //410306MuharremKorkmaz
    //410305CoskunKocer
   veri = value;
   ui->LEMarka->setText(veri->getFareAdi());
   ui->LEModeli->setText(veri->getFareModeli());
   ui->LERenk->setText(veri->getFareRenk());
   ui->SPDPI->setValue(veri->getFareDPI());
   ui->LEBaglantiTuru->setText(veri->getFareBaglantiTuru());

}

#include "tmoislemcitanimlamaformu.h"
#include "ui_tmoislemcitanimlamaformu.h"
#include <veriler/veri_siniflari/tmoislemci.h>
TMOIslemciTanimlamaFormu::TMOIslemciTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOIslemciTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOIslemciTanimlamaFormu::~TMOIslemciTanimlamaFormu()
{
    delete ui;
}

TMOIslemciPtr TMOIslemciTanimlamaFormu::getVeri() const
{
        veri->setIslemciAdi(ui->LEMarka->text());
        veri->setIslemciModelNo(ui->LEModelNo->text());
        veri->setIslemciSoketTipi(ui->LESoketTipi->text());
        veri->setIslemciHizi(ui->LEHizi->text());
        veri->setIslemciCekirdekSayisi(ui->LECekirdekSayisi->text());
        veri->setIslemciOnBellek(ui->LEOnbellek->text());
        veri->setIslemciBellekTuru(ui->LEBellekTuru->text());
        veri->setIslemciGucTuketimi(ui->LEGucTuketimi->text());
        veri->setIslemciEntegreGPUvarmi(ui->LEEntegreCPU->text());

        return veri;
}
//410316OnurOkuyucu
    //410306MuharremKorkmaz
    //410305CoskunKocer
void TMOIslemciTanimlamaFormu::setVeri(const TMOIslemciPtr &value)
{
      veri = value;
       ui->LEMarka->setText(veri->getIslemciAdi());
       ui->LEModelNo->setText(veri->getIslemciModelNo());
       ui->LESoketTipi->setText(veri->getIslemciSoketTipi());
       ui->LEHizi->setText(veri->getIslemciHizi());
       ui->LECekirdekSayisi->setText(veri->getIslemciCekirdekSayisi());
       ui->LEOnbellek->setText(veri->getIslemciOnBellek());
       ui->LEBellekTuru->setText(veri->getIslemciBellekTuru());
       ui->LEGucTuketimi->setText(veri->getIslemciGucTuketimi());
       ui->LEEntegreCPU->setText(veri->getIslemciEntegreGPUvarmi());
}

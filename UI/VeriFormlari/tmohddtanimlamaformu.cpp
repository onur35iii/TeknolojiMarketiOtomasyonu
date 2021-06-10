#include "tmohddtanimlamaformu.h"
#include "ui_tmohddtanimlamaformu.h"
#include <veriler/veri_siniflari/tmohdd.h>
TMOHDDTanimlamaFormu::TMOHDDTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOHDDTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOHDDTanimlamaFormu::~TMOHDDTanimlamaFormu()
{
    delete ui;
}

TMOHDDPtr TMOHDDTanimlamaFormu::getVeri() const
{
      veri->setHDDAdi(ui->LEMarka->text());
      veri->setHDDBaglantiArayuzu(ui->LEBaglantiArayuzu->text());
      veri->setHDDKapasitesi(ui->LEKapasitesi->text());
      veri->setHDDOnbellek(ui->LEOnbellek->text());
      veri->setHDDDonusHizi(ui->LEDonusHizi->text());
      veri->setHDDBoyutu(ui->LEBoyutu->text());
      return veri;
}

void TMOHDDTanimlamaFormu::setVeri(const TMOHDDPtr &value)
{
    veri = value;
        ui->LEMarka->setText(veri->getHDDAdi());
        ui->LEBaglantiArayuzu->setText(veri->getHDDBaglantiArayuzu());
        ui->LEKapasitesi->setText(veri->getHDDKapasitesi());
        ui->LEOnbellek->setText(veri->getHDDOnbellek());
        ui->LEDonusHizi->setText(veri->getHDDDonusHizi());
        ui->LEBoyutu->setText(veri->getHDDBoyutu());
}

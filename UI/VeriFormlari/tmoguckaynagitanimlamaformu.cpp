#include "tmoguckaynagitanimlamaformu.h"
#include "ui_tmoguckaynagitanimlamaformu.h"
#include <veriler/veri_siniflari/tmoguckaynagi.h>
TMOGucKaynagiTanimlamaFormu::TMOGucKaynagiTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOGucKaynagiTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOGucKaynagiTanimlamaFormu::~TMOGucKaynagiTanimlamaFormu()
{
    delete ui;
}

TMOGucKaynagiPtr TMOGucKaynagiTanimlamaFormu::getVeri() const
{
        veri->setGucKaynagiAdi(ui->LEMarka->text());
        veri->setGucKaynagiModelNo(ui->LEModel->text());
       veri->setGucKaynagiFanBoyutu(ui->SBFanBoyutu->value());
        veri->setGucKaynagiDegeri(ui->SBDegeri->value());

        return veri;
}

void TMOGucKaynagiTanimlamaFormu::setVeri(const TMOGucKaynagiPtr &value)
{
        veri = value;
        ui->LEMarka->setText(veri->getGucKaynagiAdi());
        ui->LEModel->setText(veri->getGucKaynagiModelNo());
        ui->SBFanBoyutu->setValue(veri->getGucKaynagiFanBoyutu());
        ui->SBDegeri->setValue(veri->getGucKaynagiDegeri());
}

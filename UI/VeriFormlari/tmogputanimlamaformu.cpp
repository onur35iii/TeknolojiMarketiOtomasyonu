#include "tmogputanimlamaformu.h"
#include "ui_tmogputanimlamaformu.h"
#include<veriler/veri_siniflari/tmogpu.h>

TMOGPUTanimlamaFormu::TMOGPUTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOGPUTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOGPUTanimlamaFormu::~TMOGPUTanimlamaFormu()
{
    delete ui;
}

TMOGPUPtr TMOGPUTanimlamaFormu::getVeri() const
{

    veri->setGPUAdi(ui->LEMarka->text());
    veri->setGPUModelNo(ui->LEModelNo->text());
    veri->setGucTuketimi(ui->LEGucTuketimi->text());
    veri->setGPUSlotSayisi(ui->SBSlotSayisi->value());
    veri->setGPUBellekHizi(ui->LEBellekHizi->text());
    veri->setGPUBoyutu(ui->SBGPUBoyutu->value());
    return veri;
}//410316OnurOkuyucu
//410306MuharremKorkmaz
//410305CoskunKocer

void TMOGPUTanimlamaFormu::setVeri(const TMOGPUPtr &value)
{
    veri = value;
    ui->LEMarka->setText(veri->getGPUAdi());
     ui->LEModelNo->setText(veri->getGPUModelNo());
     ui->LEGucTuketimi->setText(veri->getGucTuketimi());
     ui->SBSlotSayisi->setValue(veri->getGPUSlotSayisi());
     ui->LEBellekHizi->setText(veri->getGPUBellekHizi());
     ui->SBGPUBoyutu->setValue(veri->getGPUBoyutu());


}

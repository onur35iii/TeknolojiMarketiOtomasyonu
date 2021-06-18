#include "tmomonitortanimlamaformu.h"
#include "ui_tmomonitortanimlamaformu.h"
#include <veriler/veri_siniflari/tmomonitor.h>
TMOMonitorTanimlamaFormu::TMOMonitorTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOMonitorTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOMonitorTanimlamaFormu::~TMOMonitorTanimlamaFormu()
{
    delete ui;
}

TMOMonitorPtr TMOMonitorTanimlamaFormu::getVeri() const
{
    veri->setMonitorAdi(ui->LEMarka->text());
    veri->setMonitorModelNo(ui->LEModelNo->text());
    veri->setMonitorHDMIBaglantiSayisi(ui->SBHDMISayisi->value());
    veri->setMonitorYenilemeHizi(ui->SBYenilemeHizi->value());
    veri->setMonitorBoyutu(ui->SBBoyut->value());
    veri->setMonitorCozunurluk(ui->SBCozunurluk->value());
    veri->setMonitorRenk(ui->LERenk->text());
    return veri;
}

void TMOMonitorTanimlamaFormu::setVeri(const TMOMonitorPtr &value)
{//410316OnurOkuyucu
    //410306MuharremKorkmaz
    //410305CoskunKocer
    veri = value;
     ui->LEMarka->setText(veri->getMonitorAdi());
     ui->LEModelNo->setText(veri->getMonitorModelNo());
     ui->SBHDMISayisi->setValue(veri->getMonitorHDMIBaglantiSayisi());
     ui->SBYenilemeHizi->setValue(veri->getMonitorYenilemeHizi());
     ui->SBBoyut->setValue(veri->getMonitorBoyutu());
    ui->SBCozunurluk->setValue(veri->getMonitorCozunurluk());
     ui->LERenk->setText(veri->getMonitorRenk());
}

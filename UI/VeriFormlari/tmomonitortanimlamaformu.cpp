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
    veri->setMonitorHDMIBaglantiSayisi(ui->LEHDMISayisi->text().toInt());
    veri->setMonitorYenilemeHizi(ui->LEYenilemeHizi->text().toInt());
    veri->setMonitorBoyutu(ui->LEBoyut->text().toInt());
    veri->setMonitorCozunurluk(ui->LECozunurluk->text().toInt());
    veri->setMonitorRenk(ui->LERenk->text());
    return veri;
}

void TMOMonitorTanimlamaFormu::setVeri(const TMOMonitorPtr &value)
{
    veri = value;
     ui->LEMarka->setText(veri->getMonitorAdi());
     ui->LEModelNo->setText(veri->getMonitorModelNo());
     //ui->LEHDMISayisi->setText(veri->getMonitorHDMIBaglantiSayisi());
    // ui->LEYenilemeHizi->setText(veri->getMonitorYenilemeHizi());
    // ui->LEBoyut->setText()veri->getMonitorBoyutu());
   //  ui->LECozunurluk->setText(veri->getMonitorCozunurluk());
     ui->LERenk->setText(veri->getMonitorRenk());
}

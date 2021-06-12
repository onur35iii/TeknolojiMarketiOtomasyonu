#include "tmoyenianakarttanimlamaformu.h"
#include "ui_tmoyenianakarttanimlamaformu.h"
#include <veriler/veri_siniflari/tmoanakart.h>
TMOYeniAnakartTanimlamaFormu::TMOYeniAnakartTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOYeniAnakartTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOYeniAnakartTanimlamaFormu::~TMOYeniAnakartTanimlamaFormu()
{
    delete ui;
}

TMOAnakartPtr TMOYeniAnakartTanimlamaFormu::getVeri() const
{
    veri->setAnakartAdi(ui->LEMarka->text());
    veri->setAnakartModelNo(ui->LEModelNo->text());
    veri->setAnakartSoketTipi(ui->LESoketTipi->text());
    veri->setAnakartRamTipi(ui->LERamTipi->text());
    veri->setAnakartChipseti(ui->LEChipseti->text());
    veri->setAnakartVgaSlotu(ui->LEVGASlotSayisi->text());
    veri->setAnakartBoyutu(ui->LEAnakartBoyutu->text());
    return veri;
}

void TMOYeniAnakartTanimlamaFormu::setVeri(const TMOAnakartPtr & value)
{
    ui->LEMarka->setText(veri->getAnakartAdi());
    ui->LEModelNo->setText(veri->getAnakartModelNo());
    ui->LESoketTipi->setText(veri->getAnakartSoketTipi());
    ui->LERamTipi->setText(veri->getAnakartRamTipi());
    ui->LEChipseti->setText(veri->getAnakartChipseti());
    ui->LEVGASlotSayisi->setText(veri->getAnakartVgaSlotu());
    ui->LEAnakartBoyutu->setText(veri->getAnakartBoyutu());
}
//git

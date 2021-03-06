#include "tmokasatanimlamaformu.h"
#include "ui_tmokasatanimlamaformu.h"
#include <veriler/veri_siniflari/tmokasa.h>
TMOKasaTanimlamaFormu::TMOKasaTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOKasaTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOKasaTanimlamaFormu::~TMOKasaTanimlamaFormu()
{
    delete ui;
}

TMOKasaPtr TMOKasaTanimlamaFormu::getVeri() const
{
    veri->setKasaAdi(ui->LEMarka->text());
    veri->setKasaModelNo(ui->LEModelNo->text());
    veri->setKasaFanSayisi(ui->LEFanSayisi->text());
    veri->setKasaGucKaynagivarmi(ui->LEKasaAnakartYapisi->text());
    veri->setKasaBoyutu(ui->SBKasaBoyutu->value());
    veri->setKasaAnakartYapisi(ui->LEKasaAnakartYapisi->text());
    veri->setKasaRenk(ui->LEKasaRenk->text());
    return veri;
}

void TMOKasaTanimlamaFormu::setVeri(const TMOKasaPtr &value)
{//410316OnurOkuyucu
    //410306MuharremKorkmaz
    //410305CoskunKocer
    veri = value;
     ui->LEMarka->setText(veri->getKasaAdi());
     ui->LEModelNo->setText(veri->getKasaModelNo());
     ui->LEFanSayisi->setText(veri->getKasaFanSayisi());
     ui->LEGucKaynagi->setText(veri->getKasaGucKaynagivarmi());
     ui->SBKasaBoyutu->setValue(veri->getKasaBoyutu());
     ui->LEKasaAnakartYapisi->setText(veri->getKasaAnakartYapisi());
     ui->LEKasaRenk->setText(veri->getKasaRenk());
}

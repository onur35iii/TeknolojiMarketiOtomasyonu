#include "tmoklavyetanimlamaformu.h"
#include "ui_tmoklavyetanimlamaformu.h"
#include <veriler/veri_siniflari/tmoklavye.h>
TMOKlavyeTanimlamaFormu::TMOKlavyeTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOKlavyeTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOKlavyeTanimlamaFormu::~TMOKlavyeTanimlamaFormu()
{
    delete ui;
}

TMOKlavyePtr TMOKlavyeTanimlamaFormu::getVeri() const
{
    veri->setKlavyeAdi(ui->LEMarka->text());
    veri->setKlavyeModelNo(ui->LEModelNo->text());
    veri->setKlavyeTuru(ui->LEKlavyeTuru->text());
    veri->setKlavyeRenk(ui->LEKlavyeRenk->text());

    return veri;
}

void TMOKlavyeTanimlamaFormu::setVeri(const TMOKlavyePtr &value)
{//410316OnurOkuyucu
    //410306MuharremKorkmaz
    //410305CoskunKocer
    veri = value;
     ui->LEMarka->setText(veri->getKlavyeAdi());
     ui->LEModelNo->setText(veri->getKlavyeModelNo());
     ui->LEKlavyeTuru->setText(veri->getKlavyeTuru());
     ui->LEKlavyeRenk->setText(veri->getKlavyeRenk());

}

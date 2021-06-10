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
    return veri;
}

void TMOIslemciTanimlamaFormu::setVeri(const TMOIslemciPtr &value)
{
    veri = value;
}

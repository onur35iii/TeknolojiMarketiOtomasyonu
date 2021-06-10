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
    return veri;
}

void TMOYeniAnakartTanimlamaFormu::setVeri(const TMOAnakartPtr &value)
{
    veri = value;
}
//git

#include "tmoyenifaretanimlamaformu.h"
#include "ui_tmoyenifaretanimlamaformu.h"
#include <veriler/veri_siniflari/tmofare.h>
TMOYeniFareTanimlamaFormu::TMOYeniFareTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOYeniFareTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOYeniFareTanimlamaFormu::~TMOYeniFareTanimlamaFormu()
{
    delete ui;
}

TMOFarePtr TMOYeniFareTanimlamaFormu::getVeri() const
{
    return veri;
}

void TMOYeniFareTanimlamaFormu::setVeri(const TMOFarePtr &value)
{
    veri = value;
}

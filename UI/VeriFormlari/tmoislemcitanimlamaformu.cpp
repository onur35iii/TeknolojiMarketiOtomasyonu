#include "tmoislemcitanimlamaformu.h"
#include "ui_tmoislemcitanimlamaformu.h"

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

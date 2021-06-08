#include "tmohddtanimlamaformu.h"
#include "ui_tmohddtanimlamaformu.h"

TMOHDDTanimlamaFormu::TMOHDDTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOHDDTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOHDDTanimlamaFormu::~TMOHDDTanimlamaFormu()
{
    delete ui;
}

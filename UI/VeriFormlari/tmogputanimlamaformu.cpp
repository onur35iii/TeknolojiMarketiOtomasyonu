#include "tmogputanimlamaformu.h"
#include "ui_tmogputanimlamaformu.h"

TMOGPUTanimlamaFormu::TMOGPUTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOGPUTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOGPUTanimlamaFormu::~TMOGPUTanimlamaFormu()
{
    delete ui;
}

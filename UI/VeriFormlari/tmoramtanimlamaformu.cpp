#include "tmoramtanimlamaformu.h"
#include "ui_tmoramtanimlamaformu.h"

TMORAMTanimlamaFormu::TMORAMTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMORAMTanimlamaFormu)
{
    ui->setupUi(this);
}

TMORAMTanimlamaFormu::~TMORAMTanimlamaFormu()
{
    delete ui;
}

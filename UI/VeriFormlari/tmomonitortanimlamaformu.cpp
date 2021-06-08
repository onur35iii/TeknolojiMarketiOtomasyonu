#include "tmomonitortanimlamaformu.h"
#include "ui_tmomonitortanimlamaformu.h"

TMOMonitorTanimlamaFormu::TMOMonitorTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOMonitorTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOMonitorTanimlamaFormu::~TMOMonitorTanimlamaFormu()
{
    delete ui;
}

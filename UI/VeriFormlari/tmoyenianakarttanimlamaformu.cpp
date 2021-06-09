#include "tmoyenianakarttanimlamaformu.h"
#include "ui_tmoyenianakarttanimlamaformu.h"

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
//git

#include "tmoyenifaretanimlamaformu.h"
#include "ui_tmoyenifaretanimlamaformu.h"

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

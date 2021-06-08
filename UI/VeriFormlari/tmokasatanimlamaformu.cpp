#include "tmokasatanimlamaformu.h"
#include "ui_tmokasatanimlamaformu.h"

TMOKasaTanimlamaFormu::TMOKasaTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOKasaTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOKasaTanimlamaFormu::~TMOKasaTanimlamaFormu()
{
    delete ui;
}

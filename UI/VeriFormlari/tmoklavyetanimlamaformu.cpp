#include "tmoklavyetanimlamaformu.h"
#include "ui_tmoklavyetanimlamaformu.h"

TMOKlavyeTanimlamaFormu::TMOKlavyeTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOKlavyeTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOKlavyeTanimlamaFormu::~TMOKlavyeTanimlamaFormu()
{
    delete ui;
}

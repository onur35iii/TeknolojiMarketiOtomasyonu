#include "tmoguckaynagitanimlamaformu.h"
#include "ui_tmoguckaynagitanimlamaformu.h"

TMOGucKaynagiTanimlamaFormu::TMOGucKaynagiTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOGucKaynagiTanimlamaFormu)
{
    ui->setupUi(this);
}

TMOGucKaynagiTanimlamaFormu::~TMOGucKaynagiTanimlamaFormu()
{
    delete ui;
}

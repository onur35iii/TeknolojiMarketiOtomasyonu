#include "tmotedarikciformu.h"
#include "ui_tmotedarikciformu.h"

TMOTedarikciFormu::TMOTedarikciFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOTedarikciFormu)
{
    ui->setupUi(this);
}

TMOTedarikciFormu::~TMOTedarikciFormu()
{
    delete ui;
}

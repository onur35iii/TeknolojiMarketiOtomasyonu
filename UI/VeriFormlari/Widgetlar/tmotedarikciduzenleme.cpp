#include "tmotedarikciduzenleme.h"
#include "ui_tmotedarikciduzenleme.h"

TMOTedarikciDuzenleme::TMOTedarikciDuzenleme(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOTedarikciDuzenleme)
{
    ui->setupUi(this);
}

TMOTedarikciDuzenleme::~TMOTedarikciDuzenleme()
{
    delete ui;
}

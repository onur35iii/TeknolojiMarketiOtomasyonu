#include "tmoanapencere.h"
#include "ui_tmoanapencere.h"

TMOAnaPencere::TMOAnaPencere(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TMOAnaPencere)
{
    ui->setupUi(this);
}

TMOAnaPencere::~TMOAnaPencere()
{
    delete ui;
}


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

// Tamsayi veri türünü lineeditten nasıl çekeriz
//radiobuttondan veri çekme veri türü hatasi
// comboboxtan veri çekme nasıl oluyor
//  datastream hataları


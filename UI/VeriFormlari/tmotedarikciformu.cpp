#include "tmotedarikciformu.h"
#include "ui_tmotedarikciformu.h"

#include<UI/ListeFormlari/tmotedarikcilistewidget.h>
#include <UI/VeriFormlari/Widgetlar/tmotedarikciduzenleme.h>

#include <veriler/veri_siniflari/tmotedarikcibilgileri.h>
#include <veriler/tmogenelveriyoneticisi.h>
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



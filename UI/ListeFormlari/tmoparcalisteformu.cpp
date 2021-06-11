#include "tmoparcalisteformu.h"
#include "ui_tmoparcalisteformu.h"
#include<veriler/TANIMLAR.h>
#include<veriler/tmogenelveriyoneticisi.h>
#include<veriler/veri_siniflari/tmofare.h>
#include<UI/ListeFormlari/tmofarelisteformu.h>

#include <QStringList>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QMessageBox>
TMOParcaListeFormu::TMOParcaListeFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOParcaListeFormu)
{
    ui->setupUi(this);
}

TMOParcaListeFormu::~TMOParcaListeFormu()
{
    delete ui;
}

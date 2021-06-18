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
    //aramaYap();
}

TMOParcaListeFormu::~TMOParcaListeFormu()
{
    delete ui;
}

void TMOParcaListeFormu::on_pushButton_clicked()
{
    // aramaYap();
}
//410316OnurOkuyucu
    //410306MuharremKorkmaz
    //410305CoskunKocer
void TMOParcaListeFormu::ListeGuncelle()
{

}

void TMOParcaListeFormu::aramaYap()
{

}

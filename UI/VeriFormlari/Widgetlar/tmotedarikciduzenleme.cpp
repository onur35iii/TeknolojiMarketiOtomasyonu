#include "tmotedarikciduzenleme.h"
#include "ui_tmotedarikciduzenleme.h"
#include<veriler/veri_siniflari/tmotedarikcibilgileri.h>


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

TMOTedarikciBilgileriPtr TMOTedarikciDuzenleme::getVeri() const
{
    veri->setTedarikciAdresi(ui->PTTedarikciAdresi->toPlainText());
    veri->setTedarikciAdi(ui->LETedarikciAdi->text());
    veri->setTedarikciTelefonNo(ui->LETedarikciTelefon->text());
    veri->setTedarikciYetkiliKisi(ui->LETedarikciYetkiliKisi->text());
    return veri;
}

void TMOTedarikciDuzenleme::setVeri(const TMOTedarikciBilgileriPtr &value)
{
    ui->LETedarikciAdi->setText(veri->getTedarikciAdi());
    ui->LETedarikciTelefon->setText(veri->getTedarikciTelefonNo());
    ui->LETedarikciYetkiliKisi->setText(veri->getTedarikciYetkiliKisi());
    ui->PTTedarikciAdresi->setPlainText(veri->getTedarikciAdresi());
    veri = value;
}

void TMOTedarikciDuzenleme::on_btnKaydet_clicked()
{
     emit kaydetKapat();
}

void TMOTedarikciDuzenleme::on_btnIptal_clicked()
{
     emit iptalKapat();
}

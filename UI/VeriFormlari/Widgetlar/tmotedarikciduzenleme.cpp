#include "tmotedarikciduzenleme.h"
#include "ui_tmotedarikciduzenleme.h"
#include<veriler/veri_siniflari/tmotedarikcibilgileri.h>
TMOTedarikciDuzenleme::TMOTedarikciDuzenleme(QWidget *parent) :
    QWidget(parent),
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
    veri->setTedarikciAdresi(ui->pteTedarikciAdresi->toPlainText());
    veri->setTedarikciAdi(ui->leTedarikciAdi->text());
    veri->setTedarikciTelefonNo(ui->leTedarikciTelefon->text());
    veri->setTedarikciYetkiliKisi(ui->leTedarikciYetkiliKisi->text());
    return veri;
}

void TMOTedarikciDuzenleme::setVeri(const TMOTedarikciBilgileriPtr &value)
{
    veri=value;
    ui->leTedarikciAdi->setText(veri->getTedarikciAdi());
    ui->leTedarikciTelefon->setText(veri->getTedarikciTelefonNo());
    ui->leTedarikciYetkiliKisi->setText(veri->getTedarikciYetkiliKisi());
    ui->pteTedarikciAdresi->setPlainText(veri->getTedarikciAdresi());
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

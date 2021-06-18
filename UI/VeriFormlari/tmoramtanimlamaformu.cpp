#include "tmoramtanimlamaformu.h"
#include "ui_tmoramtanimlamaformu.h"
#include <veriler/veri_siniflari/tmoram.h>
TMORAMTanimlamaFormu::TMORAMTanimlamaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMORAMTanimlamaFormu)
{
    ui->setupUi(this);
}

TMORAMTanimlamaFormu::~TMORAMTanimlamaFormu()
{
    delete ui;
}

TMORAMPtr TMORAMTanimlamaFormu::getVeri() const
{
    veri->setRamAdi(ui->LEMarka->text());
    veri->setRamModelNo(ui->LEModelNo->text());
    veri->setRamtipi(ui->LERAMTipi->text());
    veri->setRamBushizi(ui->LEBusHizi->text());
    veri->setRamKapasitesi(ui->LEKapasitesi->text());
    veri->setRamGecikmeSuresi(ui->LEGecikmeSuresi->text());
    return veri;
}

void TMORAMTanimlamaFormu::setVeri(const TMORAMPtr &value)
{//410316OnurOkuyucu
    //410306MuharremKorkmaz
    //410305CoskunKocer
    veri = value;
   ui->LEMarka->setText(veri->getRamAdi());
   ui->LEModelNo->setText(veri->getRamModelNo());
   ui->LERAMTipi->setText(veri->getRamtipi());
   ui->LEBusHizi->setText(veri->getRamBushizi());
   ui->LEKapasitesi->setText(veri->getRamKapasitesi());
   ui->LEGecikmeSuresi->setText(veri->getRamGecikmeSuresi());
}

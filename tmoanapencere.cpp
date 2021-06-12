#include "tmoanapencere.h"
#include "ui_tmoanapencere.h"
#include <QDir>
#include <QFile>
#include <QDataStream>
#include <QStandardPaths>
#include <veriler/tmogenelveriyoneticisi.h>
#include <veriler/TANIMLAR.h>

#include<UI/VeriFormlari/tmoyenianakarttanimlamaformu.h>
#include<UI/VeriFormlari/tmogputanimlamaformu.h>
#include<UI/VeriFormlari/tmoguckaynagitanimlamaformu.h>
#include<UI/VeriFormlari/tmohddtanimlamaformu.h>
#include<UI/VeriFormlari/tmoislemcitanimlamaformu.h>
#include<UI/VeriFormlari/tmokasatanimlamaformu.h>
#include<UI/VeriFormlari/tmoklavyetanimlamaformu.h>
#include<UI/VeriFormlari/tmomonitortanimlamaformu.h>
#include<UI/VeriFormlari/tmoramtanimlamaformu.h>
#include<UI/VeriFormlari/tmoyenifaretanimlamaformu.h>
#include<UI/VeriFormlari/tmotedarikciformu.h>
#include<UI/VeriFormlari/Widgetlar/tmotedarikciduzenleme.h>


#include<UI/ListeFormlari/tmoanakartlisteformu.h>
#include<UI/ListeFormlari/tmofarelisteformu.h>
#include<UI/ListeFormlari/tmogpulisteformu.h>
#include<UI/ListeFormlari/tmoguckaynagilisteformu.h>
#include<UI/ListeFormlari/tmohddlisteformu.h>
#include<UI/ListeFormlari/tmoislemcilisteformu.h>
#include<UI/ListeFormlari/tmokasalisteformu.h>
#include<UI/ListeFormlari/tmoklavyelisteformu.h>
#include<UI/ListeFormlari/tmomonitorlisteformu.h>
#include<UI/ListeFormlari/tmoramlisteformu.h>
#include<UI/ListeFormlari/tmoparcalisteformu.h>

#include <veriler/veri_siniflari/tmoanakart.h>
#include <veriler/veri_siniflari/tmofare.h>
#include <veriler/veri_siniflari/tmogpu.h>
#include <veriler/veri_siniflari/tmoguckaynagi.h>
#include <veriler/veri_siniflari/tmohdd.h>
#include <veriler/veri_siniflari/tmoislemci.h>
#include <veriler/veri_siniflari/tmokasa.h>
#include <veriler/veri_siniflari/tmoklavye.h>
#include <veriler/veri_siniflari/tmomonitor.h>
#include <veriler/veri_siniflari/tmoram.h>

#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>
#include<veriler/veri_yoneticileri/tmoanakartyoneticisi.h>

TMOAnaPencere::TMOAnaPencere(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TMOAnaPencere)
{
    ui->setupUi(this);
    TMOGenelVeriYoneticisi::sec();
    QString dosya_yolu=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QDir dosya_klasoru(dosya_yolu);
    if(dosya_klasoru.exists("KODgs.db")){
        QFile dosya(dosya_yolu+"/KODgs.db");
        if(dosya.open(QIODevice::ReadOnly)){
            QDataStream oku(&dosya);
            oku >> TMOGenelVeriYoneticisi::sec();
            dosya.close();
        }
    }
}

TMOAnaPencere::~TMOAnaPencere()
{
    delete ui;
    QString dosya_yolu=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QFile dosya(dosya_yolu+"/KODgs.db");

    if(dosya.open(QIODevice::WriteOnly)){
        QDataStream yaz(&dosya);
        yaz << TMOGenelVeriYoneticisi::sec();
        dosya.close();
    }

}

// Tamsayi veri türünü lineeditten nasıl çekeriz
//radiobuttondan veri çekme veri türü hatasi
// comboboxtan veri çekme nasıl oluyor
//  datastream hataları


void TMOAnaPencere::on_actionAnakart_triggered()
{

    TMOYeniAnakartTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getAnakart().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni Anakart Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getAnakart().ekle(veri);
    }
}

void TMOAnaPencere::on_actionKasalar_triggered()
{
    TMOKasaTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getKasa().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni Kasa Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getKasa().ekle(veri);}
}

void TMOAnaPencere::on_action_lemci_triggered()
{

    TMOIslemciTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getIslemci().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni işlemci Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getIslemci().ekle(veri);
    }
}

void TMOAnaPencere::on_actionRAM_triggered()
{
    TMORAMTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getRAM().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni RAM Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getRAM().ekle(veri);
    }
}

void TMOAnaPencere::on_actionHDD_triggered()
{
    TMOHDDTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getHDD().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni HDD Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getHDD().ekle(veri);
    }
}

void TMOAnaPencere::on_actionGPU_triggered()
{
    TMOGPUTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getGPU().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni GPU Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getGPU().ekle(veri);
    }
}

void TMOAnaPencere::on_actionG_Kayna_triggered()
{
    TMOGucKaynagiTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getGucKaynagi().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni Güç Kaynağı Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getGucKaynagi().ekle(veri);
    }
}

void TMOAnaPencere::on_actionMonit_r_triggered()
{
    TMOMonitorTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getMonitor().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni Monitör Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getMonitor().ekle(veri);
    }
}

void TMOAnaPencere::on_actionKlavye_triggered()
{
    TMOKlavyeTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getKlavye().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni Klavye Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getKlavye().ekle(veri);
    }
}

void TMOAnaPencere::on_actionFare_triggered()
{
    TMOYeniFareTanimlamaFormu form;
    auto veri = TMOGenelVeriYoneticisi::sec().getFare().yeni();

    form.setVeri(veri);
    form.setWindowTitle(tr("Yeni Fare Ekleme"));

    if (form.exec() == QDialog::Accepted) {
        form.getVeri();
        TMOGenelVeriYoneticisi::sec().getFare().ekle(veri);
    }
}

void TMOAnaPencere::on_actionTedarik_iler_triggered()
{
     TMOTedarikciDuzenleme form;
     form.exec();

}

void TMOAnaPencere::on_actionTedarik_i_Ekle_triggered()
{
    TMOTedarikciFormu form;
    form.exec();
}

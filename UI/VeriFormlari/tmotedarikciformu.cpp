#include "tmotedarikciformu.h"
#include "ui_tmotedarikciformu.h"
#include<veriler/TANIMLAR.h>
#include<UI/ListeFormlari/tmotedarikcilistewidget.h>
#include<UI/VeriFormlari/Widgetlar/tmotedarikciduzenleme.h>

#include<veriler/veri_siniflari/tmotedarikcibilgileri.h>
#include<veriler/tmogenelveriyoneticisi.h>
TMOTedarikciFormu::TMOTedarikciFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TMOTedarikciFormu)
{
    ui->setupUi(this);
    TMOTedarikciListeWidget *widget1 = new TMOTedarikciListeWidget(this);

    ui->tabTedarikciIslemleri->addTab(widget1, tr("Tanımlı Tedarikçiler"));

    connect(widget1,
            &TMOTedarikciListeWidget::duzeltmeTalepEdildi,
            this,
            &TMOTedarikciFormu::tedarikciDuzelt);
}

TMOTedarikciFormu::~TMOTedarikciFormu()
{
    delete ui;
}
//410316OnurOkuyucu
    //410306MuharremKorkmaz
    //410305CoskunKocer
void TMOTedarikciFormu::on_tabTedarikciIslemleri_tabCloseRequested(int index){}

void TMOTedarikciFormu::on_btnYeniTedarikci_clicked()
{
    TMOTedarikciDuzenleme *widget = new TMOTedarikciDuzenleme(this);

    auto index = ui->tabTedarikciIslemleri->addTab(widget, tr("Yeni Tedarikçi Ekle"));

    auto veri = TMOGenelVeriYoneticisi::sec().getTedarikci().yeni();

    widget->setVeri(veri);

    ui->tabTedarikciIslemleri->setCurrentIndex(index);

    // Tedarikçi liste widget'ını bulalım...

    TMOTedarikciListeWidget *listeWgt = nullptr;

    for (auto i = 0; i < this->ui->tabTedarikciIslemleri->count(); i++) {
        auto ptr = this->ui->tabTedarikciIslemleri->widget(i);
        listeWgt = static_cast<TMOTedarikciListeWidget *>(ptr);
        if (listeWgt != nullptr) {
            break;
        }
    }

    connect(widget, &TMOTedarikciDuzenleme::iptalKapat, [this, widget]() {
        for (auto i = 0; i < this->ui->tabTedarikciIslemleri->count(); i++) {
            if (this->ui->tabTedarikciIslemleri->widget(i) == widget) {
                this->ui->tabTedarikciIslemleri->removeTab(i);
                return;
            }
        }
    });

    connect(widget, &TMOTedarikciDuzenleme::kaydetKapat, [this, widget, listeWgt]() {
        TMOGenelVeriYoneticisi::sec().getTedarikci().ekle(widget->getVeri());
        listeWgt->arama_yap();

        for (auto i = 0; i < this->ui->tabTedarikciIslemleri->count(); i++) {
            if (this->ui->tabTedarikciIslemleri->widget(i) == widget) {
                this->ui->tabTedarikciIslemleri->removeTab(i);
                return;
            }
        }
    });
}

void TMOTedarikciFormu::tedarikciDuzelt(TMOTedarikciBilgileriPtr tedarikci)
{
    TMOTedarikciDuzenleme *widget = new TMOTedarikciDuzenleme(this);
    auto index = ui->tabTedarikciIslemleri
                     ->addTab(widget, tr("%1 Tedarikçi Düzelt").arg(tedarikci->getTedarikciAdi()));

    widget->setVeri(tedarikci);

    ui->tabTedarikciIslemleri->setCurrentIndex(index);

    // Tedarikçi liste widget'ını bulalım...

    TMOTedarikciListeWidget *listeWgt = nullptr;

    for (auto i = 0; i < this->ui->tabTedarikciIslemleri->count(); i++) {
        auto ptr = this->ui->tabTedarikciIslemleri->widget(i);
        listeWgt = static_cast<TMOTedarikciListeWidget *>(ptr);
        if (listeWgt != nullptr) {
            break;
        }
    }

    connect(widget, &TMOTedarikciDuzenleme::iptalKapat, [this, widget]() {
        for (auto i = 0; i < this->ui->tabTedarikciIslemleri->count(); i++) {
            if (this->ui->tabTedarikciIslemleri->widget(i) == widget) {
                this->ui->tabTedarikciIslemleri->removeTab(i);
                return;
            }
        }
    });

    connect(widget, &TMOTedarikciDuzenleme::kaydetKapat, [this, widget, listeWgt]() {
        widget->getVeri();
        listeWgt->arama_yap();

        for (auto i = 0; i < this->ui->tabTedarikciIslemleri->count(); i++) {
            if (this->ui->tabTedarikciIslemleri->widget(i) == widget) {
                this->ui->tabTedarikciIslemleri->removeTab(i);
                return;
            }
        }
    });
}

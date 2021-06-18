#ifndef TMOTEDARIKCILISTEWIDGET_H
#define TMOTEDARIKCILISTEWIDGET_H
#include<veriler/veri_yoneticileri/tmotedarikcibilgileriyoneticisi.h>
#include <QWidget>

namespace Ui {
class TMOTedarikciListeWidget;
}

class TMOTedarikciListeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TMOTedarikciListeWidget(QWidget *parent = nullptr);
    ~TMOTedarikciListeWidget();
    void arama_yap();

signals:
    void duzeltmeTalepEdildi(TMOTedarikciBilgileriYoneticisi::Ptr tedarikci);
private slots:
    void ara();

    void on_btnAra_clicked();

private:
    void listeGuncelle();
    Ui::TMOTedarikciListeWidget *ui;
    TMOTedarikciBilgileriYoneticisi::VeriListesi liste;
};

#endif // TMOTEDARIKCILISTEWIDGET_H

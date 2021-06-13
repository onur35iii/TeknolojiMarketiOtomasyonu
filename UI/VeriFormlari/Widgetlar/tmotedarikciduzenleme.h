#ifndef TMOTEDARIKCIDUZENLEME_H
#define TMOTEDARIKCIDUZENLEME_H

#include <QWidget>
#include <veriler/TANIMLAR.h>
namespace Ui {
class TMOTedarikciDuzenleme;
}

class TMOTedarikciDuzenleme : public QWidget
{
    Q_OBJECT

public:
    explicit TMOTedarikciDuzenleme(QWidget *parent = nullptr);
    ~TMOTedarikciDuzenleme();
    TMOTedarikciBilgileriPtr getVeri() const;
    void setVeri(const TMOTedarikciBilgileriPtr &value);

signals:
    void kaydetKapat();
    void iptalKapat();
private slots:
    void on_btnKaydet_clicked();

    void on_btnIptal_clicked();
private:
    Ui::TMOTedarikciDuzenleme *ui;
     TMOTedarikciBilgileriPtr veri;
};

#endif // TMOTEDARIKCIDUZENLEME_H

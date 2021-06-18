#ifndef TMOFARELISTEFORMU_H
#define TMOFARELISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmofareyoneticisi.h>
namespace Ui {
class TMOFareListeFormu;
}

class TMOFareListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOFareListeFormu(QWidget *parent = nullptr);
    ~TMOFareListeFormu();
    TMOFareYoneticisi::VeriListesi getListe() const;
    void setListe(const TMOFareYoneticisi::VeriListesi &value);

private slots:
    void on_pushButton_clicked();
    void aramaYap();


    void on_PBKapat_clicked();

    void on_PBAra_clicked();

private:
    void ListeGuncelle();

    Ui::TMOFareListeFormu *ui;
     TMOFareYoneticisi::VeriListesi liste;
};

#endif // TMOFARELISTEFORMU_H

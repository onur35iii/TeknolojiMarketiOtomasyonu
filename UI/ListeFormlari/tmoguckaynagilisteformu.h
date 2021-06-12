#ifndef TMOGUCKAYNAGILISTEFORMU_H
#define TMOGUCKAYNAGILISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmoguckaynagiyoneticisi.h>
namespace Ui {
class TMOGucKaynagiListeFormu;
}

class TMOGucKaynagiListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOGucKaynagiListeFormu(QWidget *parent = nullptr);
    ~TMOGucKaynagiListeFormu();
    TMOGucKaynagiYoneticisi::VeriListesi getListe() const;
    void setListe(const TMOGucKaynagiYoneticisi::VeriListesi &value);

private slots:
    void on_pushButton_clicked();
   // void Ara();

private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMOGucKaynagiListeFormu *ui;
     TMOGucKaynagiYoneticisi::VeriListesi liste;
};

#endif // TMOGUCKAYNAGILISTEFORMU_H

#ifndef TMOKASALISTEFORMU_H
#define TMOKASALISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmokasayoneticisi.h>
namespace Ui {
class TMOKasaListeFormu;
}

class TMOKasaListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOKasaListeFormu(QWidget *parent = nullptr);
    ~TMOKasaListeFormu();
    TMOKasaYoneticisi::VeriListesi getListe() const;
    void setListe(const TMOKasaYoneticisi::VeriListesi &value);

private slots:
    void on_pushButton_clicked();
  //  void Ara();
private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMOKasaListeFormu *ui;
    TMOKasaYoneticisi::VeriListesi liste;
};

#endif // TMOKASALISTEFORMU_H

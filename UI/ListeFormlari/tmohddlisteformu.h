#ifndef TMOHDDLISTEFORMU_H
#define TMOHDDLISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmohddyoneticisi.h>
namespace Ui {
class TMOHDDListeFormu;
}

class TMOHDDListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOHDDListeFormu(QWidget *parent = nullptr);
    ~TMOHDDListeFormu();


    TMOHDDYoneticisi::VeriListesi getListe() const;
    void setListe(const TMOHDDYoneticisi::VeriListesi &value);
private slots:
void on_pushButton_clicked();
void Ara();

private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMOHDDListeFormu *ui;
    TMOHDDYoneticisi::VeriListesi liste;
};

#endif // TMOHDDLISTEFORMU_H

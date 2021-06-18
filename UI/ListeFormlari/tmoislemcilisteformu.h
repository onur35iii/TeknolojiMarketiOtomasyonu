#ifndef TMOISLEMCILISTEFORMU_H
#define TMOISLEMCILISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmoislemciyoneticisi.h>
namespace Ui {
class TMOIslemciListeFormu;
}

class TMOIslemciListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOIslemciListeFormu(QWidget *parent = nullptr);
    ~TMOIslemciListeFormu();
    TMOIslemciYoneticisi::VeriListesi getListe() const;
    void setListe(const TMOIslemciYoneticisi::VeriListesi &value);

private slots:
    void on_pushButton_clicked();

    void on_PBAra_clicked();

private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMOIslemciListeFormu *ui;
    TMOIslemciYoneticisi::VeriListesi liste;
};

#endif // TMOISLEMCILISTEFORMU_H

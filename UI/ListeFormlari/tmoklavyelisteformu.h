#ifndef TMOKLAVYELISTEFORMU_H
#define TMOKLAVYELISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmoklavyeyoneticisi.h>
namespace Ui {
class TMOKlavyeListeFormu;
}

class TMOKlavyeListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOKlavyeListeFormu(QWidget *parent = nullptr);
    ~TMOKlavyeListeFormu();
    TMOKlavyeYoneticisi::VeriListesi getListe() const;
    void setListe(const TMOKlavyeYoneticisi::VeriListesi &value);

private slots:
    void on_pushButton_clicked();

    void on_PBAra_clicked();

private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMOKlavyeListeFormu *ui;
    TMOKlavyeYoneticisi::VeriListesi liste;
};

#endif // TMOKLAVYELISTEFORMU_H

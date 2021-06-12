#ifndef TMOANAKARTLISTEFORMU_H
#define TMOANAKARTLISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmoanakartyoneticisi.h>
namespace Ui {
class TMOAnakartListeFormu;
}

class TMOAnakartListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOAnakartListeFormu(QWidget *parent = nullptr);
    ~TMOAnakartListeFormu();

    TMOAnakartYoneticisi::VeriListesi getListe() const;
    void setListe(const TMOAnakartYoneticisi::VeriListesi &value);

private slots:
    void on_pushButton_clicked();

private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMOAnakartListeFormu *ui;
    TMOAnakartYoneticisi::VeriListesi liste;
};

#endif // TMOANAKARTLISTEFORMU_H

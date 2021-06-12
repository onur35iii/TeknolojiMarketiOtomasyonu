#ifndef TMOPARCALISTEFORMU_H
#define TMOPARCALISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmoanakartyoneticisi.h>
#include<veriler/veri_yoneticileri/tmofareyoneticisi.h>
#include<veriler/veri_yoneticileri/tmogpuyoneticisi.h>
#include<veriler/veri_yoneticileri/tmoguckaynagiyoneticisi.h>
#include<veriler/veri_yoneticileri/tmohddyoneticisi.h>
#include<veriler/veri_yoneticileri/tmoislemciyoneticisi.h>
#include<veriler/veri_yoneticileri/tmokasayoneticisi.h>
#include<veriler/veri_yoneticileri/tmoklavyeyoneticisi.h>
#include<veriler/veri_yoneticileri/tmomonitoryoneticisi.h>
#include<veriler/veri_yoneticileri/tmoramyoneticisi.h>

namespace Ui {
class TMOParcaListeFormu;
}

class TMOParcaListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOParcaListeFormu(QWidget *parent = nullptr);
    ~TMOParcaListeFormu();
private slots:
    void on_pushButton_clicked();
  //  void Ara();
private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMOParcaListeFormu *ui;
    //TKNparcaBilgisiYoneticisi::Verilistesi liste;
};

#endif // TMOPARCALISTEFORMU_H

#ifndef TMOMONITORLISTEFORMU_H
#define TMOMONITORLISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmomonitoryoneticisi.h>
namespace Ui {
class TMOMonitorListeFormu;
}

class TMOMonitorListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOMonitorListeFormu(QWidget *parent = nullptr);
    ~TMOMonitorListeFormu();
    TMOMonitorYoneticisi::VeriListesi getListe() const;
    void setListe(const TMOMonitorYoneticisi::VeriListesi &value);

private slots:
    void on_pushButton_clicked();

    void on_PBAra_clicked();

private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMOMonitorListeFormu *ui;
     TMOMonitorYoneticisi::VeriListesi liste;
};

#endif // TMOMONITORLISTEFORMU_H

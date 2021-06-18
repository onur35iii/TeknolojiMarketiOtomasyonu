#ifndef TMOGPULISTEFORMU_H
#define TMOGPULISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmogpuyoneticisi.h>
namespace Ui {
class TMOGPUListeFormu;
}

class TMOGPUListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOGPUListeFormu(QWidget *parent = nullptr);
    ~TMOGPUListeFormu();
    TMOGPUYoneticisi::VeriListesi getListe() const;
    void setListe(const TMOGPUYoneticisi::VeriListesi &value);

private slots:
    void on_pushButton_clicked();

    void on_PBAra_clicked();

private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMOGPUListeFormu *ui;
    TMOGPUYoneticisi::VeriListesi liste;
};

#endif // TMOGPULISTEFORMU_H

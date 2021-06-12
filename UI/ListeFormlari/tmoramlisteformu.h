#ifndef TMORAMLISTEFORMU_H
#define TMORAMLISTEFORMU_H

#include <QDialog>
#include<veriler/veri_yoneticileri/tmoramyoneticisi.h>
namespace Ui {
class TMORAMListeFormu;
}

class TMORAMListeFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMORAMListeFormu(QWidget *parent = nullptr);
    ~TMORAMListeFormu();
private slots:
    void on_pushButton_clicked();

private:
    void ListeGuncelle();
    void aramaYap();
    Ui::TMORAMListeFormu *ui;
     TMORAMYoneticisi::VeriListesi liste;
};

#endif // TMORAMLISTEFORMU_H

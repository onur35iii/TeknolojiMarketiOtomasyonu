#ifndef TMOTEDARIKCIFORMU_H
#define TMOTEDARIKCIFORMU_H
#include<veriler/TANIMLAR.h>
#include <QDialog>

namespace Ui {
class TMOTedarikciFormu;
}

class TMOTedarikciFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOTedarikciFormu(QWidget *parent = nullptr);
    ~TMOTedarikciFormu();
private slots:
    void on_tabTedarikciIslemleri_tabCloseRequested(int index) ;

    void on_btnYeniTedarikci_clicked();

    void tedarikciDuzelt(TMOTedarikciBilgileriPtr tedarikci);
private:
    Ui::TMOTedarikciFormu *ui;
};

#endif // TMOTEDARIKCIFORMU_H

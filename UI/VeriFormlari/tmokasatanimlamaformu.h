#ifndef TMOKASATANIMLAMAFORMU_H
#define TMOKASATANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
#include <QDialog>

namespace Ui {
class TMOKasaTanimlamaFormu;
}

class TMOKasaTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOKasaTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOKasaTanimlamaFormu();

    TMOKasaPtr getVeri() const;
    void setVeri(const TMOKasaPtr &value);

private:
    Ui::TMOKasaTanimlamaFormu *ui;
    TMOKasaPtr veri;
};

#endif // TMOKASATANIMLAMAFORMU_H

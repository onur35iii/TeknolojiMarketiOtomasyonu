#ifndef TMOYENIFARETANIMLAMAFORMU_H
#define TMOYENIFARETANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
#include <QDialog>

namespace Ui {
class TMOYeniFareTanimlamaFormu;
}

class TMOYeniFareTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOYeniFareTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOYeniFareTanimlamaFormu();

    TMOFarePtr getVeri() const;
    void setVeri(const TMOFarePtr &value);

private:
    Ui::TMOYeniFareTanimlamaFormu *ui;
    TMOFarePtr veri;
};

#endif // TMOYENIFARETANIMLAMAFORMU_H

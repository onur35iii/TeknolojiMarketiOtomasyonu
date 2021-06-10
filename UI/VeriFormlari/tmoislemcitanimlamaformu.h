#ifndef TMOISLEMCITANIMLAMAFORMU_H
#define TMOISLEMCITANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
#include <QDialog>

namespace Ui {
class TMOIslemciTanimlamaFormu;
}

class TMOIslemciTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOIslemciTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOIslemciTanimlamaFormu();

    TMOIslemciPtr getVeri() const;
    void setVeri(const TMOIslemciPtr &value);

private:
    Ui::TMOIslemciTanimlamaFormu *ui;
    TMOIslemciPtr veri;
};

#endif // TMOISLEMCITANIMLAMAFORMU_H

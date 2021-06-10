#ifndef TMOHDDTANIMLAMAFORMU_H
#define TMOHDDTANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
#include <QDialog>

namespace Ui {
class TMOHDDTanimlamaFormu;
}

class TMOHDDTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOHDDTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOHDDTanimlamaFormu();

    TMOHDDPtr getVeri() const;
    void setVeri(const TMOHDDPtr &value);

private:
    Ui::TMOHDDTanimlamaFormu *ui;
    TMOHDDPtr veri;
};

#endif // TMOHDDTANIMLAMAFORMU_H

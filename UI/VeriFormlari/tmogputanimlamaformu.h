#ifndef TMOGPUTANIMLAMAFORMU_H
#define TMOGPUTANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
#include <QDialog>

namespace Ui {
class TMOGPUTanimlamaFormu;
}

class TMOGPUTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOGPUTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOGPUTanimlamaFormu();

    TMOGPUPtr getVeri() const;
    void setVeri(const TMOGPUPtr &value);

private:
    Ui::TMOGPUTanimlamaFormu *ui;

    TMOGPUPtr veri;

};

#endif // TMOGPUTANIMLAMAFORMU_H

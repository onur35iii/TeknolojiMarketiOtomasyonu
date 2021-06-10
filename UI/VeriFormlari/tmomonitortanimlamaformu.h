#ifndef TMOMONITORTANIMLAMAFORMU_H
#define TMOMONITORTANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
#include <QDialog>

namespace Ui {
class TMOMonitorTanimlamaFormu;
}

class TMOMonitorTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOMonitorTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOMonitorTanimlamaFormu();

    TMOMonitorPtr getVeri() const;
    void setVeri(const TMOMonitorPtr &value);

private:
    Ui::TMOMonitorTanimlamaFormu *ui;
    TMOMonitorPtr veri;
};

#endif // TMOMONITORTANIMLAMAFORMU_H

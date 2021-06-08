#ifndef TMOMONITORTANIMLAMAFORMU_H
#define TMOMONITORTANIMLAMAFORMU_H

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

private:
    Ui::TMOMonitorTanimlamaFormu *ui;
};

#endif // TMOMONITORTANIMLAMAFORMU_H

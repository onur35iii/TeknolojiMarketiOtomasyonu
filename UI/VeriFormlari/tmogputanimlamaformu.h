#ifndef TMOGPUTANIMLAMAFORMU_H
#define TMOGPUTANIMLAMAFORMU_H

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

private:
    Ui::TMOGPUTanimlamaFormu *ui;
};

#endif // TMOGPUTANIMLAMAFORMU_H

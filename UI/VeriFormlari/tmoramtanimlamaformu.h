#ifndef TMORAMTANIMLAMAFORMU_H
#define TMORAMTANIMLAMAFORMU_H

#include <QDialog>

namespace Ui {
class TMORAMTanimlamaFormu;
}

class TMORAMTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMORAMTanimlamaFormu(QWidget *parent = nullptr);
    ~TMORAMTanimlamaFormu();

private:
    Ui::TMORAMTanimlamaFormu *ui;
};

#endif // TMORAMTANIMLAMAFORMU_H

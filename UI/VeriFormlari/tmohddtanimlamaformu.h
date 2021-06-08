#ifndef TMOHDDTANIMLAMAFORMU_H
#define TMOHDDTANIMLAMAFORMU_H

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

private:
    Ui::TMOHDDTanimlamaFormu *ui;
};

#endif // TMOHDDTANIMLAMAFORMU_H

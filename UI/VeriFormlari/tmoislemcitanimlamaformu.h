#ifndef TMOISLEMCITANIMLAMAFORMU_H
#define TMOISLEMCITANIMLAMAFORMU_H

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

private:
    Ui::TMOIslemciTanimlamaFormu *ui;
};

#endif // TMOISLEMCITANIMLAMAFORMU_H

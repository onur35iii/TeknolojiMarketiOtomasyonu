#ifndef TMOGUCKAYNAGITANIMLAMAFORMU_H
#define TMOGUCKAYNAGITANIMLAMAFORMU_H

#include <QDialog>

namespace Ui {
class TMOGucKaynagiTanimlamaFormu;
}

class TMOGucKaynagiTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOGucKaynagiTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOGucKaynagiTanimlamaFormu();

private:
    Ui::TMOGucKaynagiTanimlamaFormu *ui;
};

#endif // TMOGUCKAYNAGITANIMLAMAFORMU_H

#ifndef TMOYENIANAKARTTANIMLAMAFORMU_H
#define TMOYENIANAKARTTANIMLAMAFORMU_H

#include <QDialog>

namespace Ui {
class TMOYeniAnakartTanimlamaFormu;
}

class TMOYeniAnakartTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOYeniAnakartTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOYeniAnakartTanimlamaFormu();

private:
    Ui::TMOYeniAnakartTanimlamaFormu *ui;
};
//git
#endif // TMOYENIANAKARTTANIMLAMAFORMU_H

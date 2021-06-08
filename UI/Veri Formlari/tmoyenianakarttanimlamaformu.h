#ifndef TMOYENIANAKARTTANIMLAMAFORMU_H
#define TMOYENIANAKARTTANIMLAMAFORMU_H

#include <QDialog>
#include <veriler/veri_siniflari/tmoanakart.h>
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

#endif // TMOYENIANAKARTTANIMLAMAFORMU_H

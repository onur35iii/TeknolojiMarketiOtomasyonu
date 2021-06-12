#ifndef TMOYENIANAKARTTANIMLAMAFORMU_H
#define TMOYENIANAKARTTANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
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

    TMOAnakartPtr getVeri() const;
    void setVeri(const TMOAnakartPtr &value);

private:
    Ui::TMOYeniAnakartTanimlamaFormu *ui;
    TMOAnakartPtr veri;
};

#endif // TMOYENIANAKARTTANIMLAMAFORMU_H

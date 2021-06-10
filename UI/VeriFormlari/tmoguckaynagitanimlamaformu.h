#ifndef TMOGUCKAYNAGITANIMLAMAFORMU_H
#define TMOGUCKAYNAGITANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
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

    TMOGucKaynagiPtr getVeri() const;
    void setVeri(const TMOGucKaynagiPtr &value);

private:
    Ui::TMOGucKaynagiTanimlamaFormu *ui;
    TMOGucKaynagiPtr veri;
};

#endif // TMOGUCKAYNAGITANIMLAMAFORMU_H

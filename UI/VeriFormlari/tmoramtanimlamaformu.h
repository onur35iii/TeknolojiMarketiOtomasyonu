#ifndef TMORAMTANIMLAMAFORMU_H
#define TMORAMTANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
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

    TMORAMPtr getVeri() const;
    void setVeri(const TMORAMPtr &value);

private:
    Ui::TMORAMTanimlamaFormu *ui;
    TMORAMPtr veri;
};

#endif // TMORAMTANIMLAMAFORMU_H

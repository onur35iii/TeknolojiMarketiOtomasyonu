#ifndef TMOKLAVYETANIMLAMAFORMU_H
#define TMOKLAVYETANIMLAMAFORMU_H
#include<veriler/TANIMLAR.h>
#include <QDialog>

namespace Ui {
class TMOKlavyeTanimlamaFormu;
}

class TMOKlavyeTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOKlavyeTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOKlavyeTanimlamaFormu();

    TMOKlavyePtr getVeri() const;
    void setVeri(const TMOKlavyePtr &value);

private:
    Ui::TMOKlavyeTanimlamaFormu *ui;
    TMOKlavyePtr veri;
};

#endif // TMOKLAVYETANIMLAMAFORMU_H

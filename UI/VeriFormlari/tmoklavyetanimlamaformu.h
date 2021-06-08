#ifndef TMOKLAVYETANIMLAMAFORMU_H
#define TMOKLAVYETANIMLAMAFORMU_H

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

private:
    Ui::TMOKlavyeTanimlamaFormu *ui;
};

#endif // TMOKLAVYETANIMLAMAFORMU_H

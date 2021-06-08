#ifndef TMOKASATANIMLAMAFORMU_H
#define TMOKASATANIMLAMAFORMU_H

#include <QDialog>

namespace Ui {
class TMOKasaTanimlamaFormu;
}

class TMOKasaTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOKasaTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOKasaTanimlamaFormu();

private:
    Ui::TMOKasaTanimlamaFormu *ui;
};

#endif // TMOKASATANIMLAMAFORMU_H

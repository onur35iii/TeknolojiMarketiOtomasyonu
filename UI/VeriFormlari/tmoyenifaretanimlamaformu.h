#ifndef TMOYENIFARETANIMLAMAFORMU_H
#define TMOYENIFARETANIMLAMAFORMU_H

#include <QDialog>

namespace Ui {
class TMOYeniFareTanimlamaFormu;
}

class TMOYeniFareTanimlamaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOYeniFareTanimlamaFormu(QWidget *parent = nullptr);
    ~TMOYeniFareTanimlamaFormu();

private:
    Ui::TMOYeniFareTanimlamaFormu *ui;
};

#endif // TMOYENIFARETANIMLAMAFORMU_H

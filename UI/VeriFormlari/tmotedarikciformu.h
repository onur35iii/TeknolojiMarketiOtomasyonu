#ifndef TMOTEDARIKCIFORMU_H
#define TMOTEDARIKCIFORMU_H

#include <QDialog>

namespace Ui {
class TMOTedarikciFormu;
}

class TMOTedarikciFormu : public QDialog
{
    Q_OBJECT

public:
    explicit TMOTedarikciFormu(QWidget *parent = nullptr);
    ~TMOTedarikciFormu();

private:
    Ui::TMOTedarikciFormu *ui;
};

#endif // TMOTEDARIKCIFORMU_H

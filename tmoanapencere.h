#ifndef TMOANAPENCERE_H
#define TMOANAPENCERE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TMOAnaPencere; }
QT_END_NAMESPACE

class TMOAnaPencere : public QMainWindow
{
    Q_OBJECT

public:
    TMOAnaPencere(QWidget *parent = nullptr);
    ~TMOAnaPencere();

private:
    Ui::TMOAnaPencere *ui;
};
#endif // TMOANAPENCERE_H

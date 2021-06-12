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

private slots:
    void on_actionAnakart_triggered();

    void on_actionKasalar_triggered();

    void on_action_lemci_triggered();

    void on_actionRAM_triggered();

    void on_actionHDD_triggered();

    void on_actionGPU_triggered();

    void on_actionG_Kayna_triggered();

    void on_actionMonit_r_triggered();

    void on_actionKlavye_triggered();

    void on_actionFare_triggered();

    void on_actionTedarik_iler_triggered();

    void on_actionTedarik_i_Ekle_triggered();

private:
    Ui::TMOAnaPencere *ui;
};
#endif // TMOANAPENCERE_H

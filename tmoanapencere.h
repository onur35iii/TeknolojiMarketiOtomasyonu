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

    void on_actionAnakart_Ekle_triggered();

    void on_actionGPU_Ekle_triggered();

    void on_actionG_Kayna_Ekle_triggered();

    void on_actionHDD_Ekle_triggered();

    void on_actionRAM_Ekle_triggered();

    void on_action_lemci_Ekle_triggered();

    void on_actionFare_Ekle_triggered();

    void on_actionKlavye_Ekle_triggered();

    void on_actionMonit_r_Ekle_triggered();

    void on_actionKasa_Ekle_triggered();

    void on_actionTedarik_i_Ekle_triggered();

    void on_actionTedarik_iler_triggered();

    void on_actionAnakart_Listele_triggered();

    void on_actionGPU_Listele_triggered();

    void on_actionG_Kayna_Listele_triggered();

    void on_actionHDD_Listele_triggered();

    void on_actionRAM_Listele_triggered();

    void on_action_lemci_Listele_triggered();

    void on_actionFare_Listele_triggered();

    void on_actionKlavye_Listele_triggered();

    void on_actionMonit_r_Listele_triggered();

    void on_actionKasa_Listele_triggered();

private:
    Ui::TMOAnaPencere *ui;
};
#endif // TMOANAPENCERE_H

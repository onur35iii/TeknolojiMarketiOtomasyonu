#ifndef TMOTEDARIKCIDUZENLEME_H
#define TMOTEDARIKCIDUZENLEME_H

#include <QDialog>

namespace Ui {
class TMOTedarikciDuzenleme;
}

class TMOTedarikciDuzenleme : public QDialog
{
    Q_OBJECT

public:
    explicit TMOTedarikciDuzenleme(QWidget *parent = nullptr);
    ~TMOTedarikciDuzenleme();

private:
    Ui::TMOTedarikciDuzenleme *ui;
};

#endif // TMOTEDARIKCIDUZENLEME_H

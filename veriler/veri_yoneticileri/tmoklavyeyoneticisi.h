#ifndef TMOKLAVYEYONETICISI_H
#define TMOKLAVYEYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOKlavyeYoneticisi : public QObject, public TemelVeriYoneticisi<TMOKlavye,TMOKlavyePtr>
{
    Q_OBJECT
public:
    explicit TMOKlavyeYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOKLAVYEYONETICISI_H

#ifndef TMOHDDYONETICISI_H
#define TMOHDDYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOHDDYoneticisi : public QObject, public TemelVeriYoneticisi<TMOHDD,TMOHDDPtr>
{
    Q_OBJECT
public:
    explicit TMOHDDYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOHDDYONETICISI_H

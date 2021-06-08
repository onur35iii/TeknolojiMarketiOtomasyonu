#ifndef TMORAMYONETICISI_H
#define TMORAMYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMORAMYoneticisi : public QObject, public TemelVeriYoneticisi<TMORAM,TMORAMPtr>
{
    Q_OBJECT
public:
    explicit TMORAMYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMORAMYONETICISI_H

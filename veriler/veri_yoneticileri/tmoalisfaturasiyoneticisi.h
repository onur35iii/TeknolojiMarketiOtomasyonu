#ifndef TMOALISFATURASIYONETICISI_H
#define TMOALISFATURASIYONETICISI_H

#include <QObject>
#include <veriler/TANIMLAR.h>
#include <veriler/veri_yoneticileri/temelveriyoneticisi.h>
class TMOAlisFaturasiYoneticisi : public QObject, public TemelVeriYoneticisi<TMOAlisFaturasi,TMOAlisFaturasiPtr>
{
    Q_OBJECT
public:
    explicit TMOAlisFaturasiYoneticisi(QObject *parent = nullptr);
   Ptr kopyaOlustur(Ptr kaynak)const;


signals:


};


#endif // TMOALISFATURASIYONETICISI_H

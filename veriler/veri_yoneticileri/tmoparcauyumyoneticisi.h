#ifndef TMOPARCAUYUMYONETICISI_H
#define TMOPARCAUYUMYONETICISI_H

#include <QObject>
#include <QObject>
#include <veriler/TANIMLAR.h>
#include<veriler/veri_yoneticileri/temelveriyoneticisi.h>

class TMOParcaUyumYoneticisi : public QObject, public TemelVeriYoneticisi<TMOParcaUyumBilgileri,TMOParcaUyumBilgileriPtr>
{
    Q_OBJECT
public:
    explicit TMOParcaUyumYoneticisi(QObject *parent = nullptr);
 Ptr kopyaOlustur(Ptr kaynak)const;
signals:

};

#endif // TMOPARCAUYUMYONETICISI_H

#ifndef TMOPARCAUYUMBILGILERI_H
#define TMOPARCAUYUMBILGILERI_H

#include <QObject>
#include<veriler/TANIMLAR.h>


class TMOParcaUyumBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit TMOParcaUyumBilgileri(QObject *parent = nullptr);

signals:

};
QDataStream &operator<<(QDataStream &stream, const TMOParcaUyumBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOParcaUyumBilgileriPtr &veri);
#endif // TMOPARCAUYUMBILGILERI_H

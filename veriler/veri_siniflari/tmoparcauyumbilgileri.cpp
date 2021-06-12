#include "tmoparcauyumbilgileri.h"

TMOParcaUyumBilgileri::TMOParcaUyumBilgileri(QObject *parent) : QObject(parent)
{

}

QDataStream &operator<<(QDataStream &stream, TMOParcaUyumBilgileriPtr const &veri){
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOParcaUyumBilgileriPtr &veri){
    return stream;
}

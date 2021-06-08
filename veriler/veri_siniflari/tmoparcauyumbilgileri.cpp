#include "tmoparcauyumbilgileri.h"

TMOParcaUyumBilgileri::TMOParcaUyumBilgileri(QObject *parent) : QObject(parent)
{

}
QDataStream &operator<<(QDataStream &stream, const TMOParcaUyumBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOParcaUyumBilgileriPtr &veri);

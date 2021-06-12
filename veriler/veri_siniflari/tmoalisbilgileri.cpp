#include "tmoalisbilgileri.h"

TMOAlisBilgileri::TMOAlisBilgileri(QObject *parent) : QObject(parent)
{

}

Idturu TMOAlisBilgileri::getId() const
{
    return AlisId;
}

void TMOAlisBilgileri::setId(const Idturu &value)
{
     if(value==AlisId)
    AlisId = value;
     return;
     emit IdDegisti(AlisId);
}

Parabirimi TMOAlisBilgileri::getAlisFiyati() const
{
    return AlisFiyati;
}

void TMOAlisBilgileri::setAlisFiyati(const Parabirimi value)
{
    if(value==AlisFiyati)
      AlisFiyati = value;
       return;
    emit AlisFiyatiDegisti(AlisFiyati);

}

qint32 TMOAlisBilgileri::getAlisMiktari() const
{
    return AlisMiktari;
}

void TMOAlisBilgileri::setAlisMiktari(const qint32 value)
{
    if(value==AlisMiktari)
      AlisMiktari = value;
       return;
    emit AlisMiktariDegisti(AlisMiktari);
}
QDataStream &operator<<(QDataStream &stream,TMOAlisBilgileriPtr const &veri){
    stream<<veri->getId()<<veri->getAlisFiyati()<<veri->getAlisMiktari();
    return stream;

}
QDataStream &operator>>(QDataStream &stream,TMOAlisBilgileriPtr &veri){

    Idturu AlisId;
    Parabirimi AlisFiyati;
    qint32 AlisMiktari;
    stream>>AlisId>>AlisFiyati>>AlisMiktari;
    veri=std::make_shared<TMOAlisBilgileri>();
    veri->setId(AlisId);
    veri->setAlisFiyati(AlisFiyati);
    veri->setAlisMiktari(AlisMiktari);

    return stream;
}

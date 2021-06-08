#include "tmofare.h"

TMOFare::TMOFare(QObject *parent) : QObject(parent)
{

}

Idturu TMOFare::getId() const
{
    return FareId;
}

void TMOFare::setId(const Idturu &value)
{
    if(value==FareId)
        return;
    FareId = value;
    emit IdDegisti(FareId);
}

Metin TMOFare::getFareAdi() const
{
    return FareAdi;
}

void TMOFare::setFareAdi(const Metin &value)
{
    if(value==FareAdi)
        return;
    FareAdi = value;
    emit FareAdiDegisti(FareAdi);
}

Metin TMOFare::getFareModeli() const
{
    return FareModeli;
}

void TMOFare::setFareModeli(const Metin &value)
{
    if(value==FareModeli)
        return;
    FareModeli = value;
    emit FareModeliDegisti(FareModeli);
}

Metin TMOFare::getFareRenk() const
{
    return FareRenk;
}

void TMOFare::setFareRenk(const Metin &value)
{
    if(value==FareRenk)
        return;
    FareRenk = value;
    emit FareRenkDegisti(FareRenk);
}

Tamsayi TMOFare::getFareDPI() const
{
    return FareDPI;
}

void TMOFare::setFareDPI(const Tamsayi &value)
{
    if(value==FareDPI)
        return;
    FareDPI = value;
    emit FareDPIDegisti(FareDPI);
}



Metin TMOFare::getFareBaglantiTuru() const
{
    return FareBaglantiTuru;
}

void TMOFare::setFareBaglantiTuru(const Metin &value)
{
    if(value==FareBaglantiTuru)
        return;
    FareBaglantiTuru = value;
    emit FareBaglantiTuruDegisti(FareBaglantiTuru);
}
QDataStream &operator<<(QDataStream &stream, const TMOFarePtr &veri){
    stream << veri->getId()<<veri->getFareAdi()<<veri->getFareBaglantiTuru()<<veri->getFareDPI()
           <<veri->getFareModeli()<<veri->getFareRenk();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOFarePtr &veri){
    Idturu FareId;
    Metin FareAdi;
    Metin FareModeli;
    Metin FareRenk;
    Tamsayi FareDPI;
    Metin FareBaglantiTuru;
    stream>>FareId>>FareAdi>>FareModeli>>FareRenk>>FareDPI>>FareBaglantiTuru;
 veri=std::make_shared<TMOFare>();
 veri->setId(FareId);
 veri->setFareAdi(FareAdi);
 veri->setFareModeli(FareModeli);
 veri->setFareRenk(FareRenk);
 veri->setFareDPI(FareDPI);
 veri->setFareBaglantiTuru(FareBaglantiTuru);
 return stream;
}



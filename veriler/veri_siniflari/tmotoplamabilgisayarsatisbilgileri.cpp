#include "tmotoplamabilgisayarsatisbilgileri.h"

TMOToplamaBilgisayarSatisBilgileri::TMOToplamaBilgisayarSatisBilgileri(QObject *parent) : QObject(parent)
{

}



Idturu TMOToplamaBilgisayarSatisBilgileri::getId() const
{
    return ToplamaPCId;
}

void TMOToplamaBilgisayarSatisBilgileri::setId(const Idturu &value)
{
    if(value==ToplamaPCId)
        return;
    ToplamaPCId = value;
    emit IdDegisti(ToplamaPCId);
}

Tamsayi TMOToplamaBilgisayarSatisBilgileri::getToplamaPCSatisMiktari() const
{
    return ToplamaPCSatisMiktari;
}

void TMOToplamaBilgisayarSatisBilgileri::setToplamaPCSatisMiktari(const Tamsayi &value)
{
    if(value==ToplamaPCSatisMiktari)
        return;
    ToplamaPCSatisMiktari = value;
    emit ToplamaPCSatisMiktariDegisti(ToplamaPCSatisMiktari);
}

Tamsayi TMOToplamaBilgisayarSatisBilgileri::getToplamaPCSatisFiyati() const
{
    return ToplamaPCSatisFiyati;
}

void TMOToplamaBilgisayarSatisBilgileri::setToplamaPCSatisFiyati(const Tamsayi &value)
{
    if(value==ToplamaPCSatisFiyati)
        return;
    ToplamaPCSatisFiyati = value;
    emit ToplamaPCSatisFiyatiDegisti(ToplamaPCSatisFiyati);
}
QDataStream &operator<<(QDataStream &stream, const TMOToplamaBilgisayarSatisBilgileriPtr &veri){
    stream << veri->getId()<<veri->getToplamaPCSatisFiyati()<<veri->getToplamaPCSatisMiktari();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOToplamaBilgisayarSatisBilgileriPtr &veri){
    Idturu ToplamaPCId;
    Tamsayi ToplamaPCSatisMiktari;
    Tamsayi ToplamaPCSatisFiyati;
    stream >> ToplamaPCId>>ToplamaPCSatisMiktari>>ToplamaPCSatisFiyati;
    veri=std::make_shared<TMOToplamaBilgisayarSatisBilgileri>();
    veri->setId(ToplamaPCId);
    veri->setToplamaPCSatisMiktari(ToplamaPCSatisMiktari);
    veri->setToplamaPCSatisFiyati(ToplamaPCSatisFiyati);
    return stream;
}

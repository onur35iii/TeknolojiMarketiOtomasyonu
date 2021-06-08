#include "tmosatisbilgileri.h"

TMOSatisBilgileri::TMOSatisBilgileri(QObject *parent) : QObject(parent)
{

}

Idturu TMOSatisBilgileri::getId() const
{
    return ParcaSatisId;
}

void TMOSatisBilgileri::setId(const Idturu &value)
{
    if(value==ParcaSatisId)
        return;
    ParcaSatisId = value;
    emit IdDegisti(ParcaSatisId);
}

Tamsayi TMOSatisBilgileri::getParcaSatisMiktari() const
{
    return ParcaSatisMiktari;
}

void TMOSatisBilgileri::setParcaSatisMiktari(const Tamsayi &value)
{
    if(value==ParcaSatisMiktari)
        return;
    ParcaSatisMiktari = value;
    emit ParcaSatisMiktariDegisti(ParcaSatisMiktari);
}

Tamsayi TMOSatisBilgileri::getParcaSatisFiyati() const
{
    return ParcaSatisFiyati;
}

void TMOSatisBilgileri::setParcaSatisFiyati(const Tamsayi &value)
{
    if(value==ParcaSatisFiyati)
        return;
    ParcaSatisFiyati = value;
    emit ParcaSatisFiyatiDegisti(ParcaSatisFiyati);
}
QDataStream &operator<<(QDataStream &stream, const TMOSatisBilgileriPtr &veri){
    stream << veri->getId()<<veri->getParcaSatisFiyati()<<veri->getParcaSatisMiktari();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOSatisBilgileriPtr &veri){
    Idturu  ParcaSatisId;
    Tamsayi ParcaSatisMiktari;
    Tamsayi ParcaSatisFiyati;
    stream >> ParcaSatisId>>ParcaSatisMiktari>>ParcaSatisFiyati;
    veri=std::make_shared<TMOSatisBilgileri>();
    veri->setId(ParcaSatisId);
    veri->setParcaSatisFiyati(ParcaSatisMiktari);
    veri->setParcaSatisMiktari(ParcaSatisFiyati);
    return stream;
}

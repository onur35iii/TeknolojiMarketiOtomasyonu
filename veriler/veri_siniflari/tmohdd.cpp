#include "tmohdd.h"

TMOHDD::TMOHDD(QObject *parent) : QObject(parent)
{

}

Idturu TMOHDD::getId() const
{
    return HDDId;
}

void TMOHDD::setId(const Idturu &value)
{
    if(value==HDDId)
        return;
    HDDId = value;
    emit IdDegisti(HDDId);
}

Metin TMOHDD::getHDDAdi() const
{
    return HDDAdi;
}

void TMOHDD::setHDDAdi(const Metin &value)
{
    if(value==HDDAdi)
        return;
    HDDAdi = value;
    emit HDDAdiDegisti(HDDAdi);
}

Metin TMOHDD::getHDDBaglantiArayuzu() const
{
    return HDDBaglantiArayuzu;
}

void TMOHDD::setHDDBaglantiArayuzu(const Metin &value)
{
    if(value==HDDBaglantiArayuzu)
        return;
    HDDBaglantiArayuzu = value;
    emit HDDBaglantiArayuzuDegisti(HDDBaglantiArayuzu);
}

Metin TMOHDD::getHDDKapasitesi() const
{
    return HDDKapasitesi;
}

void TMOHDD::setHDDKapasitesi(const Metin &value)
{
    if(value==HDDKapasitesi)
        return;
    HDDKapasitesi = value;
    emit HDDKapasitesiDegisti(HDDKapasitesi);
}

Metin TMOHDD::getHDDOnbellek() const
{
    return HDDOnbellek;
}

void TMOHDD::setHDDOnbellek(const Metin &value)
{
    if(value==HDDOnbellek)
        return;
    HDDOnbellek = value;
    emit HDDOnbellekDegisti(HDDOnbellek);
}

Metin TMOHDD::getHDDDonusHizi() const
{
    return HDDDonusHizi;
}

void TMOHDD::setHDDDonusHizi(const Metin &value)
{
    if(value==HDDDonusHizi)
        return;
    HDDDonusHizi = value;
    emit HDDDonusHiziDegisti(HDDDonusHizi);
}

Metin TMOHDD::getHDDBoyutu() const
{
    return HDDBoyutu;
}

void TMOHDD::setHDDBoyutu(const Metin &value)
{
    if(value==HDDBoyutu)
        return;
    HDDBoyutu = value;
    emit HDDBoyutuDegisti(HDDBoyutu);
}
QDataStream &operator<<(QDataStream &stream, const TMOHDDPtr &veri){
    stream << veri->getId()<<veri->getHDDAdi()<<veri->getHDDBaglantiArayuzu()<<veri->getHDDKapasitesi()<<veri->getHDDOnbellek()<<veri->getHDDDonusHizi()<<veri->getHDDBoyutu();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOHDDPtr &veri){
    Idturu HDDId;
    Metin HDDAdi;
    Metin HDDBaglantiArayuzu;
    Metin HDDKapasitesi;
    Metin HDDOnbellek;
    Metin HDDDonusHizi;
    Metin HDDBoyutu;
    stream >> HDDId>>HDDAdi>>HDDBaglantiArayuzu>>HDDKapasitesi>>HDDOnbellek>>HDDDonusHizi>>HDDBoyutu;
    veri=std::make_shared<TMOHDD>();
    veri->setId(HDDId);
    veri->setHDDAdi(HDDAdi);
    veri->setHDDBaglantiArayuzu(HDDBaglantiArayuzu);
    veri->setHDDKapasitesi(HDDKapasitesi);
    veri->setHDDOnbellek(HDDOnbellek);
    veri->setHDDDonusHizi(HDDDonusHizi);
    veri->setHDDBoyutu(HDDBoyutu);
    return stream;

}

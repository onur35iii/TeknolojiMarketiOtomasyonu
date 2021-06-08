#include "tmoram.h"

TMORAM::TMORAM(QObject *parent) : QObject(parent)
{

}

Idturu TMORAM::getId() const
{
    return RamId;
}

void TMORAM::setId(const Idturu &value)
{
    if(value==RamId)
        return;
    RamId = value;
    emit IdDegisti(RamId);
}

Metin TMORAM::getRamAdi() const
{
    return RamAdi;
}

void TMORAM::setRamAdi(const Metin &value)
{
    if(value==RamAdi)
        return;
    RamAdi = value;
    emit RamAdiDegisti(RamAdi);
}

Metin TMORAM::getRamModelNo() const
{
    return RamModelNo;
}

void TMORAM::setRamModelNo(const Metin &value)
{
    if(value==RamModelNo)
        return;
    RamModelNo = value;
    emit RamModelNoDegisti(RamModelNo);
}

Metin TMORAM::getRamtipi() const
{
    return Ramtipi;
}

void TMORAM::setRamtipi(const Metin &value)
{
    if(value==Ramtipi)
        return;
    Ramtipi = value;
    emit RamtipiDegisti(Ramtipi);

}

Metin TMORAM::getRamBushizi() const
{
    return RamBushizi;
}

void TMORAM::setRamBushizi(const Metin &value)
{
    if(value==RamBushizi)
        return;
    RamBushizi = value;
    emit RamBushiziDegisti(RamBushizi);
}

Metin TMORAM::getRamKapasitesi() const
{
    return RamKapasitesi;
}

void TMORAM::setRamKapasitesi(const Metin &value)
{
    if(value==RamKapasitesi)
        return;
    RamKapasitesi = value;
    emit RamKapasitesiDegisti(RamKapasitesi);
}

Metin TMORAM::getRamGecikmeSuresi() const
{
    return RamGecikmeSuresi;
}

void TMORAM::setRamGecikmeSuresi(const Metin &value)
{
    if(value==RamGecikmeSuresi)
        return;
    RamGecikmeSuresi = value;
    emit RamGecikmeSuresiDegisti(RamGecikmeSuresi);
}
QDataStream &operator<<(QDataStream &stream, const TMORAMPtr &veri){
    stream << veri->getId()<<veri->getRamAdi()<<veri->getRamModelNo()<<veri->getRamtipi()<<veri->getRamBushizi()<<veri->getRamKapasitesi()<<veri->getRamGecikmeSuresi();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMORAMPtr &veri){
    Idturu RamId;
    Metin RamAdi;
    Metin RamModelNo;
    Metin Ramtipi;
    Metin RamBushizi;
    Metin RamKapasitesi;
    Metin RamGecikmeSuresi;
    stream >> RamId>>RamAdi>>RamModelNo>>Ramtipi>>RamBushizi>>RamKapasitesi>>RamGecikmeSuresi;
    veri=std::make_shared<TMORAM>();
    veri->setId(RamId);
    veri->setRamAdi(RamAdi);
    veri->setRamModelNo(RamModelNo);
    veri->setRamtipi(Ramtipi);
    veri->setRamBushizi(RamBushizi);
    veri->setRamKapasitesi(RamKapasitesi);
    veri->setRamGecikmeSuresi(RamGecikmeSuresi);
    return stream;
}

#include "tmotedarikcibilgileri.h"

TMOTedarikciBilgileri::TMOTedarikciBilgileri(QObject *parent) : QObject(parent)
{

}

Idturu TMOTedarikciBilgileri::getId() const
{
    return TedarikciId;
}

void TMOTedarikciBilgileri::setId(const Idturu &value)
{
    if(value==TedarikciId)
        return;
    TedarikciId = value;
    emit IdDegisti(TedarikciId);
}

Metin TMOTedarikciBilgileri::getTedarikciAdi() const
{
    return TedarikciAdi;
}

void TMOTedarikciBilgileri::setTedarikciAdi(const Metin &value)
{
    if(value==TedarikciAdi)
        return;
    TedarikciAdi = value;
    emit TedarikciAdiDegisti(TedarikciAdi);
}

Metin TMOTedarikciBilgileri::getTedarikciAdresi() const
{
    return TedarikciAdresi;
}

void TMOTedarikciBilgileri::setTedarikciAdresi(const Metin &value)
{
    if(value==TedarikciAdresi)
        return;
    TedarikciAdresi = value;
    emit TedarikciAdresiDegisti(TedarikciAdresi);
}

Metin TMOTedarikciBilgileri::getTedarikciTelefonNo() const
{
    return TedarikciTelefonNo;
}

void TMOTedarikciBilgileri::setTedarikciTelefonNo(const Metin &value)
{
    if(value==TedarikciTelefonNo)
        return;
    TedarikciTelefonNo = value;
    emit TedarikciTelefonNoDegisti(TedarikciTelefonNo);
}

Metin TMOTedarikciBilgileri::getTedarikciYetkiliKisi() const
{
    return TedarikciYetkiliKisi;
}

void TMOTedarikciBilgileri::setTedarikciYetkiliKisi(const Metin &value)
{
    if(value==TedarikciYetkiliKisi)
        return;
    TedarikciYetkiliKisi = value;
    emit TedarikciYetkiliKisiDegisti(TedarikciYetkiliKisi);
}
QDataStream &operator<<(QDataStream &stream, const TMOTedarikciBilgileriPtr &veri){
    stream << veri->getId()<<veri->getTedarikciAdi()<<veri->getTedarikciAdresi()<<veri->getTedarikciTelefonNo()<<veri->getTedarikciYetkiliKisi();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOTedarikciBilgileriPtr &veri){
    Idturu TedarikciId;
    Metin TedarikciAdi;
    Metin TedarikciAdresi;
    Metin TedarikciTelefonNo;
    Metin TedarikciYetkiliKisi;
    stream >> TedarikciId>>TedarikciAdi>>TedarikciAdresi>>TedarikciTelefonNo>>TedarikciYetkiliKisi;
    veri=std::make_shared<TMOTedarikciBilgileri>();
    veri->setId(TedarikciId);
    veri->setTedarikciAdi(TedarikciAdi);
    veri->setTedarikciAdresi(TedarikciAdresi);
    veri->setTedarikciTelefonNo(TedarikciTelefonNo);
    veri->setTedarikciYetkiliKisi(TedarikciYetkiliKisi);
    return stream;
}

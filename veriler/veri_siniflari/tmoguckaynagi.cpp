#include "tmoguckaynagi.h"

TMOGucKaynagi::TMOGucKaynagi(QObject *parent) : QObject(parent)
{

}

Idturu TMOGucKaynagi::getId() const
{
    return GucKaynagiId;
}

void TMOGucKaynagi::setId(const Idturu &value)
{
    if(value==GucKaynagiId)
        return;
    GucKaynagiId = value;
    emit IdDegisti(GucKaynagiId);
}

Metin TMOGucKaynagi::getGucKaynagiAdi() const
{
    return GucKaynagiAdi;
}

void TMOGucKaynagi::setGucKaynagiAdi(const Metin &value)
{
    if(value==GucKaynagiAdi)
        return;
    GucKaynagiAdi = value;
    emit GucKaynagiAdiDegisti(GucKaynagiAdi);
}

Metin TMOGucKaynagi::getGucKaynagiModelNo() const
{
    return GucKaynagiModelNo;
}

void TMOGucKaynagi::setGucKaynagiModelNo(const Metin &value)
{
    if(value==GucKaynagiModelNo)
        return;
    GucKaynagiModelNo = value;
    emit GucKaynagiModelNoDegisti(GucKaynagiModelNo);
}

Tamsayi TMOGucKaynagi::getGucKaynagiFanBoyutu() const
{
    return GucKaynagiFanBoyutu;
}

void TMOGucKaynagi::setGucKaynagiFanBoyutu(const Tamsayi &value)
{
    if(value==GucKaynagiFanBoyutu)
        return;
    GucKaynagiFanBoyutu = value;
    emit GucKaynagiFanBoyutuDegisti(GucKaynagiFanBoyutu);
}

Tamsayi TMOGucKaynagi::getGucKaynagiDegeri() const
{
    return GucKaynagiDegeri;
}

void TMOGucKaynagi::setGucKaynagiDegeri(const Tamsayi &value)
{
    if(value==GucKaynagiDegeri)
        return;
    GucKaynagiDegeri = value;
    emit GucKaynagiDegeriDegisti(GucKaynagiDegeri);
}
QDataStream &operator<<(QDataStream &stream, const TMOGucKaynagiPtr &veri){
    stream << veri->getId()<<veri->getGucKaynagiAdi()<<veri->getGucKaynagiModelNo()<<veri->getGucKaynagiFanBoyutu()<<veri->getGucKaynagiDegeri();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOGucKaynagiPtr &veri){
    Idturu GucKaynagiId;
    Metin  GucKaynagiAdi;
    Metin  GucKaynagiModelNo;
    Tamsayi GucKaynagiFanBoyutu;
    Tamsayi GucKaynagiDegeri;
    stream >> GucKaynagiId>>GucKaynagiAdi>>GucKaynagiModelNo>>GucKaynagiFanBoyutu>>GucKaynagiDegeri;
    veri=std::make_shared<TMOGucKaynagi>();
    veri->setId(GucKaynagiId);
    veri->setGucKaynagiAdi(GucKaynagiAdi);
    veri->setGucKaynagiModelNo(GucKaynagiModelNo);
    veri->setGucKaynagiFanBoyutu(GucKaynagiFanBoyutu);
    veri->setGucKaynagiDegeri(GucKaynagiDegeri);
    return stream;


}

#include "tmoanakart.h"

TMOAnakart::TMOAnakart(QObject *parent) : QObject(parent)
{

}

Idturu TMOAnakart::getId() const
{
    return AnakartId;
}

void TMOAnakart::setId(const Idturu &value)
{
    if(value==AnakartId)
        return;
    AnakartId = value;
    emit IdDegisti(AnakartId);
}

Metin TMOAnakart::getAnakartAdi() const
{
    return AnakartAdi;
}

void TMOAnakart::setAnakartAdi(const Metin &value)
{
    if(value==AnakartAdi)
        return;
    AnakartAdi = value;
    emit AnakartAdiDegisti(AnakartAdi);
}

Metin TMOAnakart::getAnakartModelNo() const
{
    return AnakartModelNo;
}

void TMOAnakart::setAnakartModelNo(const Metin &value)
{
    if(value==AnakartModelNo)
        return;
    AnakartModelNo = value;
    emit AnakartModelNoDegisti(AnakartModelNo);
}

Metin TMOAnakart::getAnakartSoketTipi() const
{
    return AnakartSoketTipi;
}

void TMOAnakart::setAnakartSoketTipi(const Metin &value)
{
    if(value==AnakartSoketTipi)
        return;
    AnakartSoketTipi = value;
    emit AnakartSoketTipiDegisti(AnakartSoketTipi);
}

Metin TMOAnakart::getAnakartChipseti() const
{
    return AnakartChipseti;
}

void TMOAnakart::setAnakartChipseti(const Metin &value)
{
    if(value==AnakartChipseti)
        return;
    AnakartChipseti = value;
    emit AnakartChipsetiDegisti(AnakartChipseti);
}

Metin TMOAnakart::getAnakartRamTipi() const
{
    return AnakartRamTipi;
}

void TMOAnakart::setAnakartRamTipi(const Metin &value)
{
    if(value==AnakartRamTipi)
        return;
    AnakartRamTipi = value;
    emit AnakartRamTipiDegisti(AnakartRamTipi);
}

Metin TMOAnakart::getAnakartVgaSlotu() const
{
    return AnakartVgaSlotu;
}

void TMOAnakart::setAnakartVgaSlotu(const Metin &value)
{
    if(value==AnakartVgaSlotu)
        return;
    AnakartVgaSlotu = value;
    emit AnakartVgaSlotuDegisti(AnakartVgaSlotu);
}

Metin TMOAnakart::getAnakartBoyutu() const
{
    return AnakartBoyutu;
}

void TMOAnakart::setAnakartBoyutu(const Metin &value)
{
    if(value==AnakartBoyutu)
        return;
    AnakartBoyutu = value;
    emit AnakartBoyutuDegisti(AnakartBoyutu);
}
QDataStream &operator<<(QDataStream &stream,const TMOAnakartPtr &veri){
    stream << veri->getId()<<veri->getAnakartAdi()<<veri->getAnakartModelNo()<<veri->getAnakartSoketTipi()<<veri->getAnakartChipseti()<<veri->getAnakartRamTipi()<<veri->getAnakartVgaSlotu()<<veri->getAnakartBoyutu();
    return stream;
}
QDataStream &operator>>(QDataStream &stream,TMOAnakartPtr &veri){
    Idturu AnakartId ;
    Metin AnakartAdi;
    Metin AnakartModelNo;
    Metin AnakartSoketTipi;
    Metin AnakartChipseti;
    Metin AnakartRamTipi;
    Metin AnakartVgaSlotu;
    Metin AnakartBoyutu;
    stream >> AnakartId>>AnakartAdi>>AnakartModelNo>>AnakartSoketTipi>>AnakartChipseti>>AnakartRamTipi>>AnakartVgaSlotu>>AnakartBoyutu;
    veri=std::make_shared<TMOAnakart>();
    veri->setId(AnakartId);
    veri->setAnakartAdi(AnakartAdi);
    veri->setAnakartBoyutu(AnakartBoyutu);
    veri->setAnakartChipseti(AnakartChipseti);
    veri->setAnakartModelNo(AnakartModelNo);
    veri->setAnakartRamTipi(AnakartRamTipi);
    veri->setAnakartSoketTipi(AnakartSoketTipi);
    veri->setAnakartVgaSlotu(AnakartVgaSlotu);
    return stream;


}


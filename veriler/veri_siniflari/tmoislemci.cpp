#include "tmoislemci.h"

TMOIslemci::TMOIslemci(QObject *parent) : QObject(parent)
{

}

Idturu TMOIslemci::getId() const
{
    return IslemciId;
}

void TMOIslemci::setId(const Idturu &value)
{
    if(value==IslemciId)
        return;
    IslemciId = value;
    emit IdDegisti(IslemciId);
}

Metin TMOIslemci::getIslemciAdi() const
{
    return IslemciAdi;
}

void TMOIslemci::setIslemciAdi(const Metin &value)
{
    if(value==IslemciAdi)
        return;
    IslemciAdi = value;
    emit IslemciAdiDegisti(IslemciAdi);
}

Metin TMOIslemci::getIslemciModelNo() const
{
    return IslemciModelNo;
}

void TMOIslemci::setIslemciModelNo(const Metin &value)
{
    if(value==IslemciModelNo)
        return;
    IslemciModelNo = value;
    emit IslemciModelNoDegisti(IslemciModelNo);
}

Metin TMOIslemci::getIslemciSoketTipi() const
{
    return IslemciSoketTipi;
}

void TMOIslemci::setIslemciSoketTipi(const Metin &value)
{
    if(value==IslemciSoketTipi)
        return;
    IslemciSoketTipi = value;
    emit IslemciSoketTipiDegisti(IslemciSoketTipi);
}

Metin TMOIslemci::getIslemciHizi() const
{
    return IslemciHizi;
}

void TMOIslemci::setIslemciHizi(const Metin &value)
{
    if(value==IslemciHizi)
        return;
    IslemciHizi = value;
    emit IslemciHiziDegisti(IslemciHizi);
}

Metin TMOIslemci::getIslemciCekirdekSayisi() const
{
    return IslemciCekirdekSayisi;
}

void TMOIslemci::setIslemciCekirdekSayisi(const Metin &value)
{
    if(value==IslemciCekirdekSayisi)
        return;
    IslemciCekirdekSayisi = value;
    emit IslemciCekirdekSayisiDegisti(IslemciCekirdekSayisi);
}

Metin TMOIslemci::getIslemciOnBellek() const
{
    return IslemciOnBellek;
}

void TMOIslemci::setIslemciOnBellek(const Metin &value)
{
    if(value==IslemciOnBellek)
        return;
    IslemciOnBellek = value;
    emit IslemciOnBellekDegisti(IslemciOnBellek);
}

Metin TMOIslemci::getIslemciBellekTuru() const
{
    return IslemciBellekTuru;
}

void TMOIslemci::setIslemciBellekTuru(const Metin &value)
{
    if(value==IslemciBellekTuru)
        return;
    IslemciBellekTuru = value;
    emit IslemciBellekTuruDegisti(IslemciBellekTuru);
}

Metin TMOIslemci::getIslemciGucTuketimi() const
{
    return IslemciGucTuketimi;
}

void TMOIslemci::setIslemciGucTuketimi(const Metin &value)
{
    if(value==IslemciGucTuketimi)
        return;
    IslemciGucTuketimi = value;
    emit IslemciGucTuketimiDegisti(IslemciGucTuketimi);
}

Metin TMOIslemci::getIslemciEntegreGPUvarmi() const
{
    return IslemciEntegreGPUvarmi;
}

void TMOIslemci::setIslemciEntegreGPUvarmi(const Metin &value)
{
    if(value==IslemciEntegreGPUvarmi)
        return;
    IslemciEntegreGPUvarmi = value;
    emit IslemciEntegreGPUvarmiDegisti(IslemciEntegreGPUvarmi);
}
QDataStream &operator<<(QDataStream &stream, const TMOIslemciPtr &veri){
    stream << veri->getId()<<veri->getIslemciAdi()<<veri->getIslemciModelNo()<<veri->getIslemciSoketTipi()<<veri->getIslemciHizi()<<veri->getIslemciCekirdekSayisi()<<veri->getIslemciOnBellek()<<veri->getIslemciBellekTuru()<<veri->getIslemciGucTuketimi()<<veri->getIslemciEntegreGPUvarmi();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOIslemciPtr &veri){

    Idturu IslemciId;
    Metin IslemciAdi;
    Metin IslemciModelNo;
    Metin IslemciSoketTipi;
    Metin IslemciHizi;
    Metin IslemciCekirdekSayisi;
    Metin IslemciOnBellek;
    Metin IslemciBellekTuru;
    Metin IslemciGucTuketimi;
    Metin IslemciEntegreGPUvarmi;
    stream >> IslemciId>>IslemciAdi>>IslemciModelNo>>IslemciSoketTipi>>IslemciHizi>>IslemciCekirdekSayisi>>IslemciOnBellek>>IslemciBellekTuru>>IslemciGucTuketimi>>IslemciEntegreGPUvarmi;
    veri=std::make_shared<TMOIslemci>();

    veri->setId(IslemciId);
    veri->setIslemciAdi(IslemciAdi);
    veri->setIslemciModelNo(IslemciModelNo);
    veri->setIslemciSoketTipi(IslemciSoketTipi);
    veri->setIslemciHizi(IslemciHizi);
    veri->setIslemciCekirdekSayisi(IslemciCekirdekSayisi);
    veri->setIslemciOnBellek(IslemciOnBellek);
    veri->setIslemciBellekTuru(IslemciBellekTuru);
    veri->setIslemciGucTuketimi(IslemciGucTuketimi);
    veri->setIslemciEntegreGPUvarmi(IslemciEntegreGPUvarmi);
    return stream;


}

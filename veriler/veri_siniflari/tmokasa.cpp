#include "tmokasa.h"

TMOKasa::TMOKasa(QObject *parent) : QObject(parent)
{

}

Idturu TMOKasa::getId() const
{
    return KasaId;
}

void TMOKasa::setId(const Idturu &value)
{
    if(value==KasaId)
        return;
    KasaId = value;
    emit IdDegisti(KasaId);
}

Metin TMOKasa::getKasaAdi() const
{
    return KasaAdi;
}

void TMOKasa::setKasaAdi(const Metin &value)
{
    if(value==KasaAdi)
        return;
    KasaAdi = value;
    emit KasaAdiDegisti(KasaAdi);
}

Metin TMOKasa::getKasaModelNo() const
{
    return KasaModelNo;
}

void TMOKasa::setKasaModelNo(const Metin &value)
{
    if(value==KasaModelNo)
        return;
    KasaModelNo = value;
    emit KasaModelNoDegisti(KasaModelNo);
}

Metin TMOKasa::getKasaFanSayisi() const
{
    return KasaFanSayisi;
}

void TMOKasa::setKasaFanSayisi(const Metin &value)
{
    if(value==KasaFanSayisi)
        return;
    KasaFanSayisi = value;
    emit KasaFanSayisiDegisti(KasaFanSayisi);
}

Metin TMOKasa::getKasaGucKaynagivarmi() const
{
    return KasaGucKaynagivarmi;
}

void TMOKasa::setKasaGucKaynagivarmi(const Metin &value)
{
    if(value==KasaGucKaynagivarmi)
        return;
    KasaGucKaynagivarmi = value;
    emit KasaGucKaynagivarmiDegisti(KasaGucKaynagivarmi);
}

Tamsayi TMOKasa::getKasaBoyutu() const
{
    return KasaBoyutu;
}

void TMOKasa::setKasaBoyutu(const Tamsayi &value)
{
    if(value==KasaBoyutu)
        return;
    KasaBoyutu = value;
    emit KasaBoyutuDegisti(KasaBoyutu);
}

Metin TMOKasa::getKasaAnakartYapisi() const
{
    return KasaAnakartYapisi;
}

void TMOKasa::setKasaAnakartYapisi(const Metin &value)
{
    if(value==KasaAnakartYapisi)
        return;
    KasaAnakartYapisi = value;
    emit KasaAnakartYapisiDegisti(KasaAnakartYapisi);
}

Metin TMOKasa::getKasaRenk() const
{
    return KasaRenk;
}

void TMOKasa::setKasaRenk(const Metin &value)
{
    if(value==KasaRenk)
        return;
    KasaRenk = value;
    emit KasaRenkDegisti(KasaRenk);
}
QDataStream &operator<<(QDataStream &stream, const TMOKasaPtr &veri){
    stream << veri->getId()<<veri->getKasaAdi()<<veri->getKasaModelNo()<<veri->getKasaFanSayisi()<<veri->getKasaGucKaynagivarmi()<<veri->getKasaBoyutu()<<veri->getKasaAnakartYapisi()<<veri->getKasaRenk();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOKasaPtr &veri){
    Idturu KasaId;
    Metin KasaAdi;
    Metin KasaModelNo;
    Metin KasaFanSayisi;
    Metin KasaGucKaynagivarmi;
    Tamsayi KasaBoyutu;
    Metin KasaAnakartYapisi;
    Metin KasaRenk;
    stream >> KasaId>>KasaAdi>>KasaModelNo>>KasaFanSayisi>>KasaGucKaynagivarmi>>KasaBoyutu>>KasaAnakartYapisi>>KasaRenk;
    veri=std::make_shared<TMOKasa>();
    veri->setId(KasaId);
    veri->setKasaAdi(KasaAdi);
    veri->setKasaModelNo(KasaModelNo);
    veri->setKasaFanSayisi(KasaFanSayisi);
    veri->setKasaGucKaynagivarmi(KasaGucKaynagivarmi);
    veri->setKasaBoyutu(KasaBoyutu);
    veri->setKasaAnakartYapisi(KasaAnakartYapisi);
    veri->setKasaRenk(KasaRenk);
    return stream;
}

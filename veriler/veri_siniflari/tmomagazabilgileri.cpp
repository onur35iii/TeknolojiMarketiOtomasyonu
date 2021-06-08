#include "tmomagazabilgileri.h"

TMOMagazaBilgileri::TMOMagazaBilgileri(QObject *parent) : QObject(parent)
{

}

Idturu TMOMagazaBilgileri::getId() const
{
    return MagazaId;
}

void TMOMagazaBilgileri::setId(const Idturu &value)
{
    if(value==MagazaId)
        return;
    MagazaId = value;
    emit IdDegisti(MagazaId);
}

Metin TMOMagazaBilgileri::getMagazaAdi() const
{
    return MagazaAdi;
}

void TMOMagazaBilgileri::setMagazaAdi(const Metin &value)
{
    if(value==MagazaAdi)
        return;
    MagazaAdi = value;
    emit MagazaAdiDegisti(MagazaAdi);
}

Metin TMOMagazaBilgileri::getMagazaAdresi() const
{
    return MagazaAdresi;
}

void TMOMagazaBilgileri::setMagazaAdresi(const Metin &value)
{
    if(value==MagazaAdresi)
        return;
    MagazaAdresi = value;
    emit MagazaAdresiDegisti(MagazaAdresi);
}

Metin TMOMagazaBilgileri::getMagazaYetkilisi() const
{
    return MagazaYetkilisi;
}

void TMOMagazaBilgileri::setMagazaYetkilisi(const Metin &value)
{
    if(value==MagazaYetkilisi)
        return;
    MagazaYetkilisi = value;
    emit MagazaYetkilisiDegisti(MagazaYetkilisi);
}

Tamsayi TMOMagazaBilgileri::getMagazaTelefonu() const
{
    return MagazaTelefonu;
}

void TMOMagazaBilgileri::setMagazaTelefonu(const Tamsayi &value)
{
    if(value==MagazaTelefonu)
        return;
    MagazaTelefonu = value;
    emit MagazaTelefonuDegisti(MagazaTelefonu);
}
QDataStream &operator<<(QDataStream &stream, const TMOMagazaBilgileriPtr &veri){
    stream << veri->getId()<<veri->getMagazaAdi()<<veri->getMagazaAdresi()<<veri->getMagazaYetkilisi()<<veri->getMagazaTelefonu();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOMagazaBilgileriPtr &veri){
    Idturu MagazaId;
    Metin MagazaAdi;
    Metin MagazaAdresi;
    Metin MagazaYetkilisi;
    Tamsayi MagazaTelefonu;
    stream >> MagazaId>>MagazaAdi>>MagazaAdresi>>MagazaYetkilisi>>MagazaTelefonu;
    veri=std::make_shared<TMOMagazaBilgileri>();
    veri->setId(MagazaId);
    veri->setMagazaAdi(MagazaAdi);
    veri->setMagazaAdresi(MagazaAdresi);
    veri->setMagazaYetkilisi(MagazaYetkilisi);
    veri->setMagazaTelefonu(MagazaTelefonu);
    return stream;
}

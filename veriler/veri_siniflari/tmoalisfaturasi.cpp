#include "tmoalisfaturasi.h"

TMOAlisFaturasi::TMOAlisFaturasi(QObject *parent) : QObject(parent)
{

}

Idturu TMOAlisFaturasi::getId() const
{
    return ParcaAlisFaturaId;
}

void TMOAlisFaturasi::setId(const Idturu &value)
{
    if(value==ParcaAlisFaturaId)
        return;

    ParcaAlisFaturaId = value;
    emit IdDegisti(ParcaAlisFaturaId);
}

Tamsayi TMOAlisFaturasi::getParcaAlisFaturaNo() const
{
    return ParcaAlisFaturaNo;
}

void TMOAlisFaturasi::setParcaAlisFaturaNo(const Tamsayi &value)
{
    if(value==ParcaAlisFaturaNo)
        return;
    ParcaAlisFaturaNo = value;
    emit ParcaAlisFaturaNoDegisti(ParcaAlisFaturaNo);
}

QDate TMOAlisFaturasi::getParcaAlisTarihi() const
{
    return ParcaAlisTarihi;
}

void TMOAlisFaturasi::setParcaAlisTarihi(const QDate &value)
{
    if(value==ParcaAlisTarihi)
        return;
    ParcaAlisTarihi = value;
    emit ParcaAlisTarihiDegisti(ParcaAlisTarihi);
}
QDataStream &operator<<(QDataStream &stream ,const TMOAlisFaturasiPtr &veri)
{
   stream << veri->getId() << veri->getParcaAlisTarihi() << veri->getParcaAlisFaturaNo();
   return stream;
}
QDataStream &operator>>(QDataStream &stream,TMOAlisFaturasiPtr &veri){

    Idturu ParcaAlisFaturaId;
    QDate ParcaAlisTarihi;
    Tamsayi ParcaAlisFaturaNo;
    stream >> ParcaAlisFaturaId >> ParcaAlisTarihi  >>ParcaAlisFaturaNo;
    veri=std::make_shared<TMOAlisFaturasi>();
    veri->setId(ParcaAlisFaturaId);
    veri->setParcaAlisTarihi(ParcaAlisTarihi);
    veri->setParcaAlisFaturaNo(ParcaAlisFaturaNo);
    return stream;


}


#include "tmosatisfaturasi.h"

TMOSatisFaturasi::TMOSatisFaturasi(QObject *parent) : QObject(parent)
{

}

Idturu TMOSatisFaturasi::getId() const
{
    return ParcaSatisFaturaId;
}

void TMOSatisFaturasi::setId(const Idturu &value)
{
    if(value==ParcaSatisFaturaId)
        return;
    ParcaSatisFaturaId = value;
    emit IdDegisti(ParcaSatisFaturaId);
}

Tarih TMOSatisFaturasi::getParcaSatisTarihi() const
{
    return ParcaSatisTarihi;
}

void TMOSatisFaturasi::setParcaSatisTarihi(const Tarih &value)
{
    if(value==ParcaSatisTarihi)
            return;
    ParcaSatisTarihi = value;
    emit ParcaSatisTarihiDegisti(ParcaSatisTarihi);
}

Tamsayi TMOSatisFaturasi::getParcaSatisFaturaNo() const
{
    return ParcaSatisFaturaNo;
}

void TMOSatisFaturasi::setParcaSatisFaturaNo(const Tamsayi &value)
{
    if(value==ParcaSatisFaturaNo)
        return;
    ParcaSatisFaturaNo = value;
    emit ParcaSatisFaturaNoDegisti(ParcaSatisFaturaNo);
}
QDataStream &operator<<(QDataStream &stream, const TMOSatisFaturasiPtr &veri){
    stream << veri->getId()<<veri->getParcaSatisFaturaNo()<<veri->getParcaSatisTarihi();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOSatisFaturasiPtr &veri){
    Idturu ParcaSatisFaturaId;
    Tarih ParcaSatisTarihi;
    Tamsayi ParcaSatisFaturaNo;
    stream >> ParcaSatisFaturaId>>ParcaSatisTarihi>>ParcaSatisFaturaNo;
    veri=std::make_shared<TMOSatisFaturasi>();
    veri->setId(ParcaSatisFaturaId);
    veri->setParcaSatisTarihi(ParcaSatisTarihi);
    veri->setParcaSatisFaturaNo(ParcaSatisFaturaNo);
    return stream;
}

#include "tmotoplamabilgisayarsatisfaturasi.h"

TMOToplamaBilgisayarSatisFaturasi::TMOToplamaBilgisayarSatisFaturasi(QObject *parent) : QObject(parent)
{

}

Idturu TMOToplamaBilgisayarSatisFaturasi::getId() const
{
    return ToplamaPCSatisFaturaId;
}

void TMOToplamaBilgisayarSatisFaturasi::setId(const Idturu &value)
{

    if(value==ToplamaPCSatisFaturaId)
        return;
    ToplamaPCSatisFaturaId = value;
    emit IdDegisti(ToplamaPCSatisFaturaId);
}

Tarih TMOToplamaBilgisayarSatisFaturasi::getToplamaPCSatisFaturaTarihi() const
{
    return ToplamaPCSatisFaturaTarihi;
}

void TMOToplamaBilgisayarSatisFaturasi::setToplamaPCSatisFaturaTarihi(const Tarih &value)
{

    if(value==ToplamaPCSatisFaturaTarihi)
        return;
    ToplamaPCSatisFaturaTarihi = value;
    emit ToplamaPCSatisFaturaTarihiDegisti(ToplamaPCSatisFaturaTarihi);
}

Tamsayi TMOToplamaBilgisayarSatisFaturasi::getToplamaPCSatisFaturaNo() const
{
    return ToplamaPCSatisFaturaNo;
}

void TMOToplamaBilgisayarSatisFaturasi::setToplamaPCSatisFaturaNo(const Tamsayi &value)
{

    if(value==ToplamaPCSatisFaturaNo)
        return;
    ToplamaPCSatisFaturaNo = value;
    emit ToplamaPCSatisFaturaNoDegisti(ToplamaPCSatisFaturaNo);
}
QDataStream &operator<<(QDataStream &stream, const TMOToplamaBilgisayarSatisFaturasiPtr &veri){
    stream << veri->getId()<<veri->getToplamaPCSatisFaturaTarihi()<<veri->getToplamaPCSatisFaturaNo();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOToplamaBilgisayarSatisFaturasiPtr &veri){
    Idturu ToplamaPCSatisFaturaId;
    Tarih ToplamaPCSatisFaturaTarihi;
    Tamsayi ToplamaPCSatisFaturaNo;
    stream >> ToplamaPCSatisFaturaId>>ToplamaPCSatisFaturaTarihi>>ToplamaPCSatisFaturaNo;
    veri=std::make_shared<TMOToplamaBilgisayarSatisFaturasi>();
    veri->setId(ToplamaPCSatisFaturaId);
    veri->setToplamaPCSatisFaturaTarihi(ToplamaPCSatisFaturaTarihi);
    veri->setToplamaPCSatisFaturaNo(ToplamaPCSatisFaturaNo);
    return stream;

}

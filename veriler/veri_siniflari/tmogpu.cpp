#include "tmogpu.h"

TMOGPU::TMOGPU(QObject *parent) : QObject(parent)
{

}

Idturu TMOGPU::getId() const
{
    return GPUId;
}

void TMOGPU::setId(const Idturu &value)
{
    if(value==GPUId)
        return;
    GPUId = value;
    emit IdDegisti(GPUId);
}

Metin TMOGPU::getGPUAdi() const
{
    return GPUAdi;
}

void TMOGPU::setGPUAdi(const Metin &value)
{
    if(value==GPUAdi)
        return;
    GPUAdi = value;
    emit GPUAdiDegisti(GPUAdi);
}

Metin TMOGPU::getGPUModelNo() const
{
    return GPUModelNo;
}

void TMOGPU::setGPUModelNo(const Metin &value)
{
    if(value==GPUModelNo)
        return;
    GPUModelNo = value;
    emit GPUModelNoDegisti(GPUModelNo);
}

Metin TMOGPU::getGPUBellekHizi() const
{
    return GPUBellekHizi;
}

void TMOGPU::setGPUBellekHizi(const Metin &value)
{
    if(value==GPUBellekHizi)
        return;
    GPUBellekHizi = value;
    emit GPUBellekHiziDegisti(GPUBellekHizi);
}

Tamsayi TMOGPU::getGPUSlotSayisi() const
{
    return GPUSlotSayisi;
}

void TMOGPU::setGPUSlotSayisi(const Tamsayi &value)
{
    if(value==GPUSlotSayisi)
        return;
    GPUSlotSayisi = value;
    emit GPUSlotSayisiDegisti(GPUSlotSayisi);
}

Metin TMOGPU::getGucTuketimi() const
{
    return GucTuketimi;
}

void TMOGPU::setGucTuketimi(const Metin &value)
{
    if(value==GucTuketimi)
        return;
    GucTuketimi = value;
    emit GucTuketimiDegisti(GucTuketimi);
}

Tamsayi TMOGPU::getGPUBoyutu() const
{
    return GPUBoyutu;
}

void TMOGPU::setGPUBoyutu(const Tamsayi &value)
{
    if(value==GPUBoyutu)
        return;
    GPUBoyutu = value;
    emit GPUBoyutuDegisti(GPUBoyutu);
}
QDataStream &operator<<(QDataStream &stream, const TMOGPUPtr &veri){
    stream << veri->getId()<<veri->getGPUAdi()<<veri->getGPUModelNo()<<veri->getGPUBellekHizi()<<veri->getGPUSlotSayisi()<<veri->getGucTuketimi()<<veri->getGucTuketimi();
    return stream;
}
QDataStream &operator>>(QDataStream &stream, TMOGPUPtr &veri){
    Idturu GPUId;
    Metin GPUAdi;
    Metin GPUModelNo;
    Metin GPUBellekHizi;
    Tamsayi GPUSlotSayisi;
    Metin GucTuketimi;
    Tamsayi GPUBoyutu;
    stream>>GPUId>>GPUAdi>>GPUModelNo>>GPUBellekHizi>>GPUSlotSayisi>>GucTuketimi>>GPUBoyutu;
    veri=std::make_shared<TMOGPU>();
    veri->setId(GPUId);
    veri->setGPUAdi(GPUAdi);
    veri->setGPUModelNo(GPUModelNo);
    veri->setGPUBellekHizi(GPUBellekHizi);
    veri->setGPUSlotSayisi(GPUSlotSayisi);
    veri->setGucTuketimi(GucTuketimi);
    veri->setGPUBoyutu(GPUBoyutu);
    return stream;

}

#include "tmogenelveriyoneticisi.h"

TMOGenelVeriYoneticisi::TMOGenelVeriYoneticisi(QObject *parent) : QObject(parent)
{

}

TMOGenelVeriYoneticisi &TMOGenelVeriYoneticisi::sec()
{
    static TMOGenelVeriYoneticisi nesne;

    return nesne;
}

TMOAlisBilgileriYoneticisi &TMOGenelVeriYoneticisi::getAlisBilgileri()
{
    return alisbilgileri;
}

TMOAlisFaturasiYoneticisi &TMOGenelVeriYoneticisi::getAlisFaturalari()
{
    return alisFaturalari;
}

TMOAnakartYoneticisi &TMOGenelVeriYoneticisi::getAnakart()
{
    return anakart;
}

TMOFareYoneticisi &TMOGenelVeriYoneticisi::getFare()
{
    return fare;
}

TMOGPUYoneticisi &TMOGenelVeriYoneticisi::getGPU()
{
    return GPU;
}

TMOGucKaynagiYoneticisi &TMOGenelVeriYoneticisi::getGucKaynagi()
{
    return guckaynagi;
}

TMOHDDYoneticisi &TMOGenelVeriYoneticisi::getHDD()
{
    return HDD;
}

TMOIslemciYoneticisi &TMOGenelVeriYoneticisi::getIslemci()
{
    return islemci;
}

TMOKasaYoneticisi &TMOGenelVeriYoneticisi::getKasa()
{
    return kasa;
}

TMOKlavyeYoneticisi &TMOGenelVeriYoneticisi::getKlavye()
{
    return klavye;
}

TMOMagazaBilgileriYoneticisi &TMOGenelVeriYoneticisi::getMagazaBilgileri()
{
    return magazabilgileri;
}

TMOMonitorYoneticisi &TMOGenelVeriYoneticisi::getMonitor()
{
    return monitor;
}

TMOParcaUyumYoneticisi &TMOGenelVeriYoneticisi::getParcaUyum()
{
    return parcauyum;
}

TMORAMYoneticisi &TMOGenelVeriYoneticisi::getRAM()
{
    return RAM;

}

TMOSatisBilgileriYoneticisi &TMOGenelVeriYoneticisi::getSatisBilgileri()
{
    return satisbilgileri;
}

TMOSatisFaturasiYoneticisi &TMOGenelVeriYoneticisi::getSatisFaturasi()
{
    return satisfaturasi;
}

TMOTedarikciBilgileriYoneticisi &TMOGenelVeriYoneticisi::getTedarikci()
{
    return tedarikci;
}

TMOToplamaBilgisayarSatisBilgileriYoneticisi &TMOGenelVeriYoneticisi::getToplamaBilgisayarSatisBilgileri()
{
    return toplamabilgisayarsatisbilgileri;
}

TMOToplamaBilgisayarSatisFaturasiYoneticisi &TMOGenelVeriYoneticisi::getToplamaBilgisayarSatisFaturasi()
{
    return toplamabilgisayarsatisfaturasi;
}
QDataStream &operator<<(QDataStream &a, TMOGenelVeriYoneticisi &b){
    a<<b.alisbilgileri<<b.alisFaturalari<<b.anakart<<b.fare<<b.GPU <<b.guckaynagi<<b.HDD<<b.islemci<<b.kasa<<b.klavye
    <<b.magazabilgileri<<b.monitor<<b.parcauyum<<b.RAM<<b.satisbilgileri<<b.satisfaturasi<<b.tedarikci<<b.toplamabilgisayarsatisbilgileri <<b.toplamabilgisayarsatisfaturasi;
    return a;
}
QDataStream &operator>>(QDataStream &a, TMOGenelVeriYoneticisi &b)
{
    a>>b.alisbilgileri>>b.alisFaturalari>>b.anakart>>b.fare>>b.GPU >>b.guckaynagi>>b.HDD>>b.islemci>>b.kasa<<b.klavye
    >>b.magazabilgileri>>b.monitor>>b.parcauyum>>b.RAM>>b.satisbilgileri>>b.satisfaturasi>>b.tedarikci>>b.toplamabilgisayarsatisbilgileri >>b.toplamabilgisayarsatisfaturasi;
    return a;
}




#ifndef TMOGENELVERIYONETICISI_H
#define TMOGENELVERIYONETICISI_H

#include <QObject>
#include <veriler/veri_yoneticileri/tmoalisbilgileriyoneticisi.h>
#include <veriler/veri_yoneticileri/tmoalisfaturasiyoneticisi.h>
#include <veriler/veri_yoneticileri/tmoanakartyoneticisi.h>
#include <veriler/veri_yoneticileri/tmofareyoneticisi.h>
#include <veriler/veri_yoneticileri/tmogpuyoneticisi.h>
#include <veriler/veri_yoneticileri/tmoguckaynagiyoneticisi.h>
#include <veriler/veri_yoneticileri/tmohddyoneticisi.h>
#include <veriler/veri_yoneticileri/tmoislemciyoneticisi.h>
#include <veriler/veri_yoneticileri/tmokasayoneticisi.h>
#include <veriler/veri_yoneticileri/tmoklavyeyoneticisi.h>
#include <veriler/veri_yoneticileri/tmomagazabilgileriyoneticisi.h>
#include <veriler/veri_yoneticileri/tmomonitoryoneticisi.h>
#include <veriler/veri_yoneticileri/tmoparcauyumyoneticisi.h>
#include <veriler/veri_yoneticileri/tmoramyoneticisi.h>
#include <veriler/veri_yoneticileri/tmosatisbilgileriyoneticisi.h>
#include <veriler/veri_yoneticileri/tmosatisfaturasiyoneticisi.h>
#include <veriler/veri_yoneticileri/tmotedarikcibilgileriyoneticisi.h>
#include <veriler/veri_yoneticileri/tmotoplamabilgisayarsatisbilgileriyoneticisi.h>
#include <veriler/veri_yoneticileri/tmotoplamabilgisayarsatisfaturasiyoneticisi.h>
/*
 * Genel veri yöneticisi sınıfı tüm veri yöneticilerini yönetecek sınıftır.
 * Bu sınıftan sadece 1 adet üretilecektir yazılım süresince.
 *
 * Bu sebeple bu sınıfa Singleton (Tekil) tasarım şablonu uygulanacaktır.
 *
 */



class TMOGenelVeriYoneticisi : public QObject
{
    Q_OBJECT
    private:
    explicit TMOGenelVeriYoneticisi(QObject *parent = nullptr);
public:
    static TMOGenelVeriYoneticisi &sec();

    TMOAlisBilgileriYoneticisi &getAlisBilgileri();
    TMOAlisFaturasiYoneticisi  &getAlisFaturaları();
    TMOAnakartYoneticisi       &getAnakart();
    TMOFareYoneticisi &getFare();
    TMOGPUYoneticisi &getGPU();
    TMOGucKaynagiYoneticisi &getGucKaynagi();
    TMOHDDYoneticisi &getHDD();
    TMOIslemciYoneticisi &getIslemci();
    TMOKasaYoneticisi &getKasa();
    TMOKlavyeYoneticisi &getKlavye();
    TMOMagazaBilgileriYoneticisi &getMagazaBilgileri();
    TMOMonitorYoneticisi &getMonitor();
    TMOParcaUyumYoneticisi &getParcaUyum();
    TMORAMYoneticisi &getRAM();
    TMOSatisBilgileriYoneticisi &getSatisBilgileri();
    TMOSatisFaturasiYoneticisi &getSatisFaturasi();
    TMOTedarikciBilgileriYoneticisi &getTedarikci();
    TMOToplamaBilgisayarSatisBilgileriYoneticisi &getToplamaBilgisayarSatisBilgileri();
    TMOToplamaBilgisayarSatisFaturasiYoneticisi &getToplamaBilgisayarSatisFaturasi();




signals:
private:
    TMOAlisBilgileriYoneticisi alisbilgileri;
    TMOAlisFaturasiYoneticisi alisFaturalari;
    TMOAnakartYoneticisi anakart;
    TMOFareYoneticisi fare;
    TMOGPUYoneticisi GPU;
    TMOGucKaynagiYoneticisi guckaynagi;
    TMOHDDYoneticisi HDD;
    TMOIslemciYoneticisi islemci;
    TMOKasaYoneticisi kasa;
    TMOKlavyeYoneticisi klavye;
    TMOMagazaBilgileriYoneticisi magazabilgileri;
    TMOMonitorYoneticisi monitor;
    TMOParcaUyumYoneticisi parcauyum;
    TMORAMYoneticisi RAM;
    TMOSatisBilgileriYoneticisi satisbilgileri;
    TMOSatisFaturasiYoneticisi  satisfaturasi;
    TMOTedarikciBilgileriYoneticisi tedarikci;
    TMOToplamaBilgisayarSatisBilgileriYoneticisi toplamabilgisayarsatisbilgileri;
    TMOToplamaBilgisayarSatisFaturasiYoneticisi  toplamabilgisayarsatisfaturasi;

    friend QDataStream &operator<<(QDataStream &a, TMOGenelVeriYoneticisi &b);
    friend QDataStream &operator>>(QDataStream &a, TMOGenelVeriYoneticisi &b);
};
 QDataStream &operator<<(QDataStream &a, TMOGenelVeriYoneticisi &b);
 QDataStream &operator>>(QDataStream &a, TMOGenelVeriYoneticisi &b);
#endif // TMOGENELVERIYONETICISI_H

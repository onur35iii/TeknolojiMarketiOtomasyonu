#ifndef TANIMLAR_H
#define TANIMLAR_H
#include <QtCore>
#include <QString>
#include <QDate>
#include <QDateTime>
#include <QTime>

typedef quint64 Idturu;
typedef qint32 Tamsayi ;

typedef double Reelsayi;
typedef float   Parabirimi;

typedef QString Metin ;

typedef QDate Tarih;
typedef QTime Saat ;
typedef QDateTime TarihSaat ;


// POİNTER TANIMLARI
class TMOAlisBilgileri;
class TMOAlisFaturasi;
class TMOAnakart;
class TMOFare;
class TMOGPU;
class TMOGucKaynagi;
class TMOHDD;
class TMOIslemci;
class TMOKasa ;
class TMOKlavye;
class TMOMagazaBilgileri;
class TMOMonitor;
class TMOParcaUyumBilgileri;
class TMORAM;
class TMOSatisBilgileri;
class TMOSatisFaturasi;
class TMOTedarikciBilgileri;
class TMOToplamaBilgisayarSatisBilgileri;
class TMOToplamaBilgisayarSatisFaturasi;


#include <memory>
typedef std::shared_ptr<TMOAlisBilgileri>  TMOAlisBilgileriPtr ;
typedef std::shared_ptr<TMOAlisFaturasi>  TMOAlisFaturasiPtr ;
typedef std::shared_ptr<TMOAnakart>  TMOAnakartPtr ;
typedef std::shared_ptr<TMOFare>  TMOFarePtr ;
typedef std::shared_ptr<TMOGPU>  TMOGPUPtr ;
typedef std::shared_ptr<TMOGucKaynagi>  TMOGucKaynagiPtr ;
typedef std::shared_ptr<TMOHDD>  TMOHDDPtr ;
typedef std::shared_ptr<TMOIslemci> TMOIslemciPtr ;
typedef std::shared_ptr<TMOKasa>  TMOKasaPtr ;
typedef std::shared_ptr<TMOKlavye> TMOKlavyePtr ;
typedef std::shared_ptr<TMOMagazaBilgileri>  TMOMagazaBilgileriPtr ;
typedef std::shared_ptr<TMOMonitor>  TMOMonitorPtr ;
typedef std::shared_ptr<TMOParcaUyumBilgileri>  TMOParcaUyumBilgileriPtr ;
typedef std::shared_ptr<TMORAM>  TMORAMPtr ;
typedef std::shared_ptr<TMOSatisBilgileri>  TMOSatisBilgileriPtr ;
typedef std::shared_ptr<TMOSatisFaturasi>  TMOSatisFaturasiPtr ;
typedef std::shared_ptr<TMOTedarikciBilgileri>  TMOTedarikciBilgileriPtr ;
typedef std::shared_ptr<TMOToplamaBilgisayarSatisBilgileri>  TMOToplamaBilgisayarSatisBilgileriPtr ;
typedef std::shared_ptr<TMOToplamaBilgisayarSatisFaturasi>  TMOToplamaBilgisayarSatisFaturasiPtr ;

QDataStream &operator<<(QDataStream &stream, const TMOAlisBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOAlisBilgileriPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOAlisFaturasiPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOAlisFaturasiPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOAnakartPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOAnakartPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOFarePtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOFarePtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOGPUPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOGPUPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOGucKaynagiPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOGucKaynagiPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOHDDPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOHDDPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOIslemciPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOIslemciPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOKasaPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOKasaPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOKlavyePtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOKlavyePtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOParcaUyumBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOParcaUyumBilgileriPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOMonitorPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOMonitorPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMORAMPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMORAMPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOSatisBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOSatisBilgileriPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOSatisFaturasiPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOSatisFaturasiPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOTedarikciBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOTedarikciBilgileriPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOToplamaBilgisayarSatisBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOToplamaBilgisayarSatisBilgileriPtr &veri);

QDataStream &operator<<(QDataStream &stream, const TMOToplamaBilgisayarSatisFaturasiPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOToplamaBilgisayarSatisFaturasiPtr &veri);




#endif // TANIMLAR_H

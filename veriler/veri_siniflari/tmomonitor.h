#ifndef TMOMONITOR_H
#define TMOMONITOR_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOMonitor : public QObject
{
    Q_OBJECT
public:
    explicit TMOMonitor(QObject *parent = nullptr);

    Q_PROPERTY(Idturu MonitorId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin MonitorModelNo READ getMonitorModelNo WRITE setMonitorModelNo NOTIFY MonitorModelNoDegisti)
    Q_PROPERTY(Tamsayi MonitorHDMIBaglantiSayisi READ getMonitorHDMIBaglantiSayisi WRITE setMonitorHDMIBaglantiSayisi NOTIFY MonitorHDMIBaglantiSayisiDegisti)
    Q_PROPERTY(Tamsayi MonitorYenilemeHizi READ getMonitorYenilemeHizi WRITE setMonitorYenilemeHizi NOTIFY MonitorYenilemeHiziDegisti)
    Q_PROPERTY(Tamsayi MonitorBoyutu READ getMonitorBoyutu WRITE setMonitorBoyutu NOTIFY MonitorBoyutuDegisti)
    Q_PROPERTY(Tamsayi MonitorCozunurluk READ getMonitorCozunurluk WRITE setMonitorCozunurluk NOTIFY MonitorCozunurlukDegisti)
    Q_PROPERTY(Metin MonitorRenk READ getMonitorRenk WRITE setMonitorRenk NOTIFY MonitorRenkDegisti)


    //MODEL ADI EKLENECEK...
    Idturu getId() const;
    Metin getMonitorModelNo() const;
    Tamsayi getMonitorHDMIBaglantiSayisi() const;
    Tamsayi getMonitorYenilemeHizi() const;
    Tamsayi getMonitorBoyutu() const;
    Tamsayi getMonitorCozunurluk() const;
    Metin getMonitorRenk() const;
signals:
    void IdDegisti(const Idturu &value);
    void MonitorModelNoDegisti(const Metin &value);
    void MonitorHDMIBaglantiSayisiDegisti(const Tamsayi &value);
    void MonitorYenilemeHiziDegisti(const Tamsayi &value);
    void MonitorBoyutuDegisti(const Tamsayi &value);
    void MonitorCozunurlukDegisti(const Tamsayi &value);
    void MonitorRenkDegisti(const Metin &value);

public slots:
    void setId(const Idturu &value);
    void setMonitorModelNo(const Metin &value);
    void setMonitorHDMIBaglantiSayisi(const Tamsayi &value);
    void setMonitorYenilemeHizi(const Tamsayi &value);
    void setMonitorBoyutu(const Tamsayi &value);
    void setMonitorCozunurluk(const Tamsayi &value);
    void setMonitorRenk(const Metin &value);

private:
    Idturu MonitorId;
    Metin MonitorModelNo;
    Tamsayi MonitorHDMIBaglantiSayisi;
    Tamsayi MonitorYenilemeHizi;
    Tamsayi MonitorBoyutu;
    Tamsayi MonitorCozunurluk;
    Metin MonitorRenk;


};
QDataStream &operator<<(QDataStream &stream, const TMOMonitorPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOMonitorPtr &veri);
#endif // TMOMONITOR_H

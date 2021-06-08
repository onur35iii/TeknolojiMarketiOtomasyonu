#ifndef TMOISLEMCI_H
#define TMOISLEMCI_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOIslemci : public QObject
{
    Q_OBJECT
public:
    explicit TMOIslemci(QObject *parent = nullptr);

    Q_PROPERTY(Idturu IslemciId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin IslemciAdi READ getIslemciAdi WRITE setIslemciModelNo NOTIFY IslemciModelNoDegisti)
    Q_PROPERTY(Metin IslemciModelNo READ getIslemciModelNo WRITE setIslemciAdi NOTIFY IslemciAdiDegisti)
    Q_PROPERTY(Metin IslemciSoketTipi READ getIslemciSoketTipi WRITE setIslemciHizi NOTIFY IslemciHiziDegisti)
    Q_PROPERTY(Metin IslemciHizi READ getIslemciHizi WRITE setIslemciSoketTipi NOTIFY IslemciSoketTipiDegisti)
    Q_PROPERTY(Metin IslemciCekirdekSayisi READ getIslemciCekirdekSayisi WRITE setIslemciCekirdekSayisi NOTIFY IslemciCekirdekSayisiDegisti)
    Q_PROPERTY(Metin IslemciOnBellek READ getIslemciOnBellek WRITE setIslemciOnBellek NOTIFY IslemciOnBellekDegisti)
    Q_PROPERTY(Metin IslemciBellekTuru READ getIslemciBellekTuru WRITE setIslemciBellekTuru NOTIFY IslemciBellekTuruDegisti)
    Q_PROPERTY(Metin IslemciGucTuketimi READ getIslemciGucTuketimi WRITE setIslemciGucTuketimi NOTIFY IslemciGucTuketimiDegisti)
    Q_PROPERTY(Metin IslemciEntegreGPUvarmi READ getIslemciEntegreGPUvarmi WRITE setIslemciEntegreGPUvarmi NOTIFY IslemciEntegreGPUvarmiDegisti)


    Idturu getId() const;
    Metin getIslemciAdi() const;
    Metin getIslemciModelNo() const;
    Metin getIslemciSoketTipi() const;
    Metin getIslemciHizi() const;
    Metin getIslemciCekirdekSayisi() const;
    Metin getIslemciOnBellek() const;
    Metin getIslemciBellekTuru() const;
    Metin getIslemciGucTuketimi() const;
    Metin getIslemciEntegreGPUvarmi() const;

signals:
    void IdDegisti(const Idturu &value);
    void IslemciModelNoDegisti(const Metin &value);
    void IslemciAdiDegisti(const Metin &value);
    void IslemciHiziDegisti(const Metin &value);
    void IslemciSoketTipiDegisti(const Metin &value);
    void IslemciCekirdekSayisiDegisti(const Metin &value);
    void IslemciOnBellekDegisti(const Metin &value);
    void IslemciBellekTuruDegisti(const Metin &value);
    void IslemciGucTuketimiDegisti(const Metin &value);
    void IslemciEntegreGPUvarmiDegisti(const Metin &value);


public slots:
     void setId(const Idturu &value);
     void setIslemciModelNo(const Metin &value);
     void setIslemciAdi(const Metin &value);
     void setIslemciHizi(const Metin &value);
     void setIslemciSoketTipi(const Metin &value);
     void setIslemciCekirdekSayisi(const Metin &value);
     void setIslemciOnBellek(const Metin &value);
     void setIslemciBellekTuru(const Metin &value);
     void setIslemciGucTuketimi(const Metin &value);
     void setIslemciEntegreGPUvarmi(const Metin &value);


private:
    Idturu IslemciId;
    Metin IslemciAdi;
    Metin IslemciModelNo;
    Metin IslemciSoketTipi;
    Metin IslemciHizi;
    Metin IslemciCekirdekSayisi;
    Metin IslemciOnBellek;
    Metin IslemciBellekTuru;
    Metin IslemciGucTuketimi;
    Metin IslemciEntegreGPUvarmi;


};
QDataStream &operator<<(QDataStream &stream, const TMOIslemciPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOIslemciPtr &veri);
#endif // TMOISLEMCI_H

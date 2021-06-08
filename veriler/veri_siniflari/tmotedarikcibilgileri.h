#ifndef TMOTEDARIKCIBILGILERI_H
#define TMOTEDARIKCIBILGILERI_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOTedarikciBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit TMOTedarikciBilgileri(QObject *parent = nullptr);

    Q_PROPERTY(Idturu TedarikciId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin TedarikciAdi READ getTedarikciAdi WRITE setTedarikciAdi NOTIFY TedarikciAdiDegisti)
    Q_PROPERTY(Metin TedarikciAdresi READ getTedarikciAdresi WRITE setTedarikciAdresi NOTIFY TedarikciAdresiDegisti)
    Q_PROPERTY(Metin TedarikciTelefonNo READ getTedarikciTelefonNo WRITE setTedarikciTelefonNo NOTIFY TedarikciTelefonNoDegisti)
    Q_PROPERTY(Metin TedarikciYetkiliKisi READ getTedarikciYetkiliKisi WRITE setTedarikciYetkiliKisi NOTIFY TedarikciYetkiliKisiDegisti)

    Idturu getId() const;
    Metin getTedarikciAdi() const;
    Metin getTedarikciAdresi() const;
    Metin getTedarikciTelefonNo() const;
    Metin getTedarikciYetkiliKisi() const;
signals:
    void IdDegisti(const Idturu &value);
    void TedarikciAdiDegisti(const Metin &value);
    void TedarikciAdresiDegisti(const Metin &value);
    void TedarikciTelefonNoDegisti(const Metin &value);
    void TedarikciYetkiliKisiDegisti(const Metin &value);
public slots:
    void setId(const Idturu &value);
    void setTedarikciAdi(const Metin &value);
    void setTedarikciAdresi(const Metin &value);
    void setTedarikciTelefonNo(const Metin &value);
    void setTedarikciYetkiliKisi(const Metin &value);
private:
    Idturu TedarikciId;
    Metin TedarikciAdi;
    Metin TedarikciAdresi;
    Metin TedarikciTelefonNo;
    Metin TedarikciYetkiliKisi;

};
QDataStream &operator<<(QDataStream &stream, const TMOTedarikciBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOTedarikciBilgileriPtr &veri);
#endif // TMOTEDARIKCIBILGILERI_H

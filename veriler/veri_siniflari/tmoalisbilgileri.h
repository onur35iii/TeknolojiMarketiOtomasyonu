#ifndef TMOALISBILGILERI_H
#define TMOALISBILGILERI_H

#include <QObject>
#include <veriler/TANIMLAR.h>
class TMOAlisBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit TMOAlisBilgileri(QObject *parent = nullptr);
    Q_PROPERTY(Idturu Id READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Parabirimi AlisFiyati READ getAlisFiyati WRITE setAlisFiyati NOTIFY
                   AlisFiyatiDegisti)
    Q_PROPERTY(qint32 AlisMiktari READ getAlisMiktari WRITE setAlisMiktari NOTIFY AlisMiktariDegisti)

    Idturu getId() const;
    Parabirimi getAlisFiyati() const;
    qint32 getAlisMiktari() const;


signals:
    void IdDegisti(const Idturu &value);
    void AlisFiyatiDegisti(const Parabirimi &value);
    void AlisMiktariDegisti(const qint32 &value);

public slots:
    void setId(const Idturu &value);
    void setAlisFiyati(const Parabirimi &value);
    void setAlisMiktari(const qint32 &value);
private:
    Idturu AlisId;
    Parabirimi AlisFiyati;
    qint32 AlisMiktari;

};
QDataStream &operator<<(QDataStream &stream, const TMOAlisBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOAlisBilgileriPtr &veri);

#endif // TMOALISBILGILERI_H

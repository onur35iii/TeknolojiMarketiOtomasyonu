#ifndef TMOSATISBILGILERI_H
#define TMOSATISBILGILERI_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOSatisBilgileri : public QObject
{
    Q_OBJECT
public:
    explicit TMOSatisBilgileri(QObject *parent = nullptr);

    Q_PROPERTY(Idturu ParcaSatisId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Tamsayi ParcaSatisMiktari READ getParcaSatisMiktari WRITE setParcaSatisMiktari NOTIFY ParcaSatisMiktariDegisti)
    Q_PROPERTY(Tamsayi ParcaSatisFiyati READ getParcaSatisFiyati WRITE setParcaSatisFiyati NOTIFY ParcaSatisFiyatiDegisti)

    Idturu getId() const;
    Tamsayi getParcaSatisMiktari() const;
    Tamsayi getParcaSatisFiyati() const;

signals:
    void IdDegisti(const Idturu &value);
    void ParcaSatisMiktariDegisti(const Tamsayi &value);
    void ParcaSatisFiyatiDegisti(const Tamsayi &value);
public slots:
     void setId(const Idturu &value);
     void setParcaSatisMiktari(const Tamsayi &value);
     void setParcaSatisFiyati(const Tamsayi &value);
private:
    Idturu  ParcaSatisId;
    Tamsayi ParcaSatisMiktari;
    Tamsayi ParcaSatisFiyati;



};
QDataStream &operator<<(QDataStream &stream, const TMOSatisBilgileriPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOSatisBilgileriPtr &veri);
#endif // TMOSATISBILGILERI_H

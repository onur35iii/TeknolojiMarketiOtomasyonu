#ifndef TMOSATISFATURASI_H
#define TMOSATISFATURASI_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOSatisFaturasi : public QObject
{
    Q_OBJECT
public:
    explicit TMOSatisFaturasi(QObject *parent = nullptr);

    Q_PROPERTY(Idturu ParcaSatisFaturaId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Tarih ParcaSatisTarihi READ getParcaSatisTarihi WRITE setParcaSatisTarihi NOTIFY ParcaSatisTarihiDegisti)
    Q_PROPERTY(Tamsayi ParcaSatisFaturaNo READ getParcaSatisFaturaNo WRITE setParcaSatisFaturaNo NOTIFY ParcaSatisFaturaNoDegisti)
    Idturu getId() const;
    Tarih getParcaSatisTarihi() const;
    Tamsayi getParcaSatisFaturaNo() const;
signals:
    void IdDegisti(const Idturu &value);
    void ParcaSatisTarihiDegisti(const Tarih &value);
    void ParcaSatisFaturaNoDegisti(const Tamsayi &value);
public slots:
     void setId(const Idturu &value);
     void setParcaSatisTarihi(const Tarih &value);
     void setParcaSatisFaturaNo(const Tamsayi &value);
private:
    Idturu ParcaSatisFaturaId;
    Tarih ParcaSatisTarihi;
    Tamsayi ParcaSatisFaturaNo;

};
QDataStream &operator<<(QDataStream &stream, const TMOSatisFaturasiPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOSatisFaturasiPtr &veri);
#endif // TMOSATISFATURASI_H

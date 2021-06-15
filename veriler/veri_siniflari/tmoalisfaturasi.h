#ifndef TMOALISFATURASI_H
#define TMOALISFATURASI_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOAlisFaturasi : public QObject
{
    Q_OBJECT

public:
    explicit TMOAlisFaturasi(QObject *parent = nullptr);
    Q_PROPERTY(Idturu  ParcaAlisFaturaId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(QDate ParcaAlisTarihi READ getParcaAlisTarihi WRITE  setParcaAlisTarihi NOTIFY
                   ParcaAlisTarihiDegisti)
    Q_PROPERTY(Tamsayi ParcaAlisFaturaNo READ getParcaAlisFaturaNo WRITE setParcaAlisFaturaNo NOTIFY ParcaAlisFaturaNoDegisti)

    Idturu getId() const;
    QDate getParcaAlisTarihi() const;
    Tamsayi getParcaAlisFaturaNo() const;

public slots:
    void setId(const Idturu &value);
    void setParcaAlisFaturaNo(const Tamsayi &value);
    void setParcaAlisTarihi(const QDate &value);
signals:
    void IdDegisti(const Idturu &value);
    void ParcaAlisFaturaNoDegisti(const Tamsayi &value);
    void ParcaAlisTarihiDegisti(const QDate &value);
private:
    Idturu ParcaAlisFaturaId;
    QDate ParcaAlisTarihi;
    Tamsayi ParcaAlisFaturaNo;



};
QDataStream &operator<<(QDataStream &stream, const TMOAlisFaturasiPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOAlisFaturasiPtr &veri);

#endif // TMOALISFATURASI_H

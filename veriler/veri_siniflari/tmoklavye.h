#ifndef TMOKLAVYE_H
#define TMOKLAVYE_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOKlavye : public QObject
{
    Q_OBJECT
public:
    explicit TMOKlavye(QObject *parent = nullptr);
    Q_PROPERTY(Idturu KlavyeId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin KlavyeAdi READ getKlavyeAdi WRITE setKlavyeAdi NOTIFY KlavyeAdiDegisti)
    Q_PROPERTY(Metin KlavyeModelNo READ getKlavyeModelNo WRITE setKlavyeModelNo NOTIFY KlavyeModelNoDegisti)
    Q_PROPERTY(Metin KlavyeTuru READ getKlavyeTuru WRITE setKlavyeTuru NOTIFY KlavyeTuruDegisti)
    Q_PROPERTY(Metin KlavyeRenk READ getKlavyeRenk WRITE setKlavyeRenk NOTIFY KlavyeRenkDegisti)

    Idturu getId() const;
    Metin getKlavyeAdi() const;
    Metin getKlavyeModelNo() const;
    Metin getKlavyeTuru() const;
    Metin getKlavyeRenk() const;

signals:
    void IdDegisti(const Idturu &value);
    void KlavyeAdiDegisti(const Metin &value);
    void KlavyeModelNoDegisti(const Metin &value);
    void KlavyeTuruDegisti(const Metin &value);
    void KlavyeRenkDegisti(const Metin &value);

public slots:
    void setId(const Idturu &value);
    void setKlavyeAdi(const Metin &value);
    void setKlavyeModelNo(const Metin &value);
    void setKlavyeTuru(const Metin &value);
    void setKlavyeRenk(const Metin &value);

private:
    Idturu KlavyeId;
    Metin KlavyeAdi;
    Metin KlavyeModelNo;
    Metin KlavyeTuru;
    Metin KlavyeRenk;

};
QDataStream &operator<<(QDataStream &stream, const TMOKlavyePtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOKlavyePtr &veri);
#endif // TMOKLAVYE_H

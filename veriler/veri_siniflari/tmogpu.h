#ifndef TMOGPU_H
#define TMOGPU_H
#include <veriler/TANIMLAR.h>
#include <QObject>

class TMOGPU : public QObject
{
    Q_OBJECT
public:
    explicit TMOGPU(QObject *parent = nullptr);

    Q_PROPERTY(Idturu GPUId READ getId WRITE setId NOTIFY IdDegisti)
    Q_PROPERTY(Metin GPUAdi READ getGPUAdi WRITE setGPUAdi NOTIFY GPUAdiDegisti)
    Q_PROPERTY(Metin GPUModelNo READ getGPUModelNo WRITE setGPUModelNo NOTIFY GPUModelNoDegisti)
    Q_PROPERTY(Metin GPUBellekHizi READ getGPUBellekHizi WRITE setGPUBellekHizi NOTIFY GPUBellekHiziDegisti)
    Q_PROPERTY(Tamsayi GPUSlotSayisi READ getGPUSlotSayisi WRITE setGPUSlotSayisi NOTIFY GPUSlotSayisiDegisti)
    Q_PROPERTY(Metin GucTuketimi READ getGucTuketimi WRITE setGucTuketimi NOTIFY GucTuketimiDegisti)
    Q_PROPERTY(Tamsayi GPUBoyutu READ getGPUBoyutu WRITE setGPUBoyutu NOTIFY GPUBoyutuDegisti)




    Idturu getId() const;
    Metin getGPUAdi() const;
    Metin getGPUModelNo() const;
    Metin getGPUBellekHizi() const;
    Tamsayi getGPUSlotSayisi() const;
    Metin getGucTuketimi() const;
    Tamsayi getGPUBoyutu() const;
signals:
    void IdDegisti(const Idturu &value);
    void GPUAdiDegisti(const Metin &value);
    void GPUModelNoDegisti(const Metin &value);
    void GPUBellekHiziDegisti(const Metin &value);
    void GPUSlotSayisiDegisti(const Tamsayi &value);
    void GucTuketimiDegisti(const Metin &value);
    void GPUBoyutuDegisti(const Tamsayi &value);
public slots:
    void setId(const Idturu &value);
    void setGPUAdi(const Metin &value);
    void setGPUModelNo(const Metin &value);
    void setGPUBellekHizi(const Metin &value);
    void setGPUSlotSayisi(const Tamsayi &value);
    void setGucTuketimi(const Metin &value);
    void setGPUBoyutu(const Tamsayi &value);
private:
    Idturu GPUId;
    Metin GPUAdi;
    Metin GPUModelNo;
    Metin GPUBellekHizi;
    Tamsayi GPUSlotSayisi;
    Metin GucTuketimi;
    Tamsayi GPUBoyutu;


};
QDataStream &operator<<(QDataStream &stream, const TMOGPUPtr &veri);
QDataStream &operator>>(QDataStream &stream, TMOGPUPtr &veri);
#endif // TMOGPU_H

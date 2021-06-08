#include "tmoparcauyumyoneticisi.h"
#include <veriler/veri_siniflari/tmoparcauyumbilgileri.h>
TMOParcaUyumYoneticisi::TMOParcaUyumYoneticisi(QObject *parent) : QObject(parent)
{
}

TMOParcaUyumYoneticisi::Ptr TMOParcaUyumYoneticisi::kopyaOlustur(TemelVeriYoneticisi::Ptr kaynak) const
{

    Ptr kopya= yeni();

    return kopya;
}

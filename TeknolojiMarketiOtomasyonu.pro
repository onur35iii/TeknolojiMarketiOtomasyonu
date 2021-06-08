QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    tmoanapencere.cpp \
    veriler/tmogenelveriyoneticisi.cpp \
    veriler/veri_siniflari/tmoalisbilgileri.cpp \
    veriler/veri_siniflari/tmoalisfaturasi.cpp \
    veriler/veri_siniflari/tmoanakart.cpp \
    veriler/veri_siniflari/tmofare.cpp \
    veriler/veri_siniflari/tmogpu.cpp \
    veriler/veri_siniflari/tmoguckaynagi.cpp \
    veriler/veri_siniflari/tmohdd.cpp \
    veriler/veri_siniflari/tmoislemci.cpp \
    veriler/veri_siniflari/tmokasa.cpp \
    veriler/veri_siniflari/tmoklavye.cpp \
    veriler/veri_siniflari/tmomagazabilgileri.cpp \
    veriler/veri_siniflari/tmomonitor.cpp \
    veriler/veri_siniflari/tmoparcauyumbilgileri.cpp \
    veriler/veri_siniflari/tmoram.cpp \
    veriler/veri_siniflari/tmosatisbilgileri.cpp \
    veriler/veri_siniflari/tmosatisfaturasi.cpp \
    veriler/veri_siniflari/tmotedarikcibilgileri.cpp \
    veriler/veri_siniflari/tmotoplamabilgisayarsatisbilgileri.cpp \
    veriler/veri_siniflari/tmotoplamabilgisayarsatisfaturasi.cpp \
    veriler/veri_yoneticileri/tmoalisbilgileriyoneticisi.cpp \
    veriler/veri_yoneticileri/tmoalisfaturasiyoneticisi.cpp \
    veriler/veri_yoneticileri/tmoanakartyoneticisi.cpp \
    veriler/veri_yoneticileri/tmofareyoneticisi.cpp \
    veriler/veri_yoneticileri/tmogpuyoneticisi.cpp \
    veriler/veri_yoneticileri/tmoguckaynagiyoneticisi.cpp \
    veriler/veri_yoneticileri/tmohddyoneticisi.cpp \
    veriler/veri_yoneticileri/tmoislemciyoneticisi.cpp \
    veriler/veri_yoneticileri/tmokasayoneticisi.cpp \
    veriler/veri_yoneticileri/tmoklavyeyoneticisi.cpp \
    veriler/veri_yoneticileri/tmomagazabilgileriyoneticisi.cpp \
    veriler/veri_yoneticileri/tmomonitoryoneticisi.cpp \
    veriler/veri_yoneticileri/tmoparcauyumyoneticisi.cpp \
    veriler/veri_yoneticileri/tmoramyoneticisi.cpp \
    veriler/veri_yoneticileri/tmosatisbilgileriyoneticisi.cpp \
    veriler/veri_yoneticileri/tmosatisfaturasiyoneticisi.cpp \
    veriler/veri_yoneticileri/tmotedarikcibilgileriyoneticisi.cpp \
    veriler/veri_yoneticileri/tmotoplamabilgisayarsatisbilgileriyoneticisi.cpp \
    veriler/veri_yoneticileri/tmotoplamabilgisayarsatisfaturasiyoneticisi.cpp

HEADERS += \
    tmoanapencere.h \
    veriler/TANIMLAR.h \
    veriler/tmogenelveriyoneticisi.h \
    veriler/veri_siniflari/tmoalisbilgileri.h \
    veriler/veri_siniflari/tmoalisfaturasi.h \
    veriler/veri_siniflari/tmoanakart.h \
    veriler/veri_siniflari/tmofare.h \
    veriler/veri_siniflari/tmogpu.h \
    veriler/veri_siniflari/tmoguckaynagi.h \
    veriler/veri_siniflari/tmohdd.h \
    veriler/veri_siniflari/tmoislemci.h \
    veriler/veri_siniflari/tmokasa.h \
    veriler/veri_siniflari/tmoklavye.h \
    veriler/veri_siniflari/tmomagazabilgileri.h \
    veriler/veri_siniflari/tmomonitor.h \
    veriler/veri_siniflari/tmoparcauyumbilgileri.h \
    veriler/veri_siniflari/tmoram.h \
    veriler/veri_siniflari/tmosatisbilgileri.h \
    veriler/veri_siniflari/tmosatisfaturasi.h \
    veriler/veri_siniflari/tmotedarikcibilgileri.h \
    veriler/veri_siniflari/tmotoplamabilgisayarsatisbilgileri.h \
    veriler/veri_siniflari/tmotoplamabilgisayarsatisfaturasi.h \
    veriler/veri_yoneticileri/TMOTemelVeriYöneticisi.h \
    veriler/veri_yoneticileri/temel_veri_yöneticisi.h \
    veriler/veri_yoneticileri/temelveriyoneticisi.h \
    veriler/veri_yoneticileri/tmoalisbilgileriyoneticisi.h \
    veriler/veri_yoneticileri/tmoalisfaturasiyoneticisi.h \
    veriler/veri_yoneticileri/tmoanakartyoneticisi.h \
    veriler/veri_yoneticileri/tmofareyoneticisi.h \
    veriler/veri_yoneticileri/tmogpuyoneticisi.h \
    veriler/veri_yoneticileri/tmoguckaynagiyoneticisi.h \
    veriler/veri_yoneticileri/tmohddyoneticisi.h \
    veriler/veri_yoneticileri/tmoislemciyoneticisi.h \
    veriler/veri_yoneticileri/tmokasayoneticisi.h \
    veriler/veri_yoneticileri/tmoklavyeyoneticisi.h \
    veriler/veri_yoneticileri/tmomagazabilgileriyoneticisi.h \
    veriler/veri_yoneticileri/tmomonitoryoneticisi.h \
    veriler/veri_yoneticileri/tmoparcauyumyoneticisi.h \
    veriler/veri_yoneticileri/tmoramyoneticisi.h \
    veriler/veri_yoneticileri/tmosatisbilgileriyoneticisi.h \
    veriler/veri_yoneticileri/tmosatisfaturasiyoneticisi.h \
    veriler/veri_yoneticileri/tmotedarikcibilgileriyoneticisi.h \
    veriler/veri_yoneticileri/tmotoplamabilgisayarsatisbilgileriyoneticisi.h \
    veriler/veri_yoneticileri/tmotoplamabilgisayarsatisfaturasiyoneticisi.h

FORMS += \
    tmoanapencere.ui

TRANSLATIONS += \
    TeknolojiMarketiOtomasyonu_tr_CY.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

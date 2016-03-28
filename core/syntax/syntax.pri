HEADERS += \
        $$PWD/zScript.tab.h

SOURCES += \
        $$PWD/zScript.tab.c

OTHER_FILES += $$PWD/zScript.y

system(bison -d -v $$PWD/zScript.y)

INCLUDEPATH += $$PWD

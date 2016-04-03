HEADERS += \
        $$PWD/zScript.tab.hpp

SOURCES += \
        $$PWD/zScript.tab.cpp

OTHER_FILES += $$PWD/zScript.yy

system(bison -d -v -L c++ -o zScript.tab.cpp $$PWD/zScript.yy)

INCLUDEPATH += $$PWD

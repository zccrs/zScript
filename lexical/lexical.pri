SOURCES += $$PWD/lex.yy.cpp

OTHER_FILES += $$PWD/zScript.ll

system(flex -+ -o lex.yy.cpp $$PWD/zScript.ll)

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/FlexLexer.h

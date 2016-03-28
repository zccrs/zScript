SOURCES += $$PWD/lex.yy.c

OTHER_FILES += $$PWD/zScript.l

system(flex $$PWD/zScript.l)

INCLUDEPATH += $$PWD

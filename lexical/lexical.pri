SOURCES += $$PWD/lex.yy.cpp

OTHER_FILES += $$PWD/zScript.ll

win*: INCLUDEPATH += $$PWD/../3rdparty
else: system(flex -+ -o lex.yy.cpp $$PWD/zScript.ll)

INCLUDEPATH += $$PWD

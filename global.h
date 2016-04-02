#ifndef GLOBAL_H
#define GLOBAL_H

#define zDebug qDebug().noquote() << __FILE__ << __LINE__ << __FUNCTION__ << "[Debug]:"
#define zError qCritical().noquote() << "[Error]:"
#define zInfo qInfo().noquote() << "[Info]:"
#define zWarning qWarning().noquote() << "[Warning]:"
#define zPrint qDebug()
#define zStandardPrint std::cout
#define zExit(code) exit(code)
#define zErrorQuit zExit(-1)
#define zQuit zExit(0)

#include <QObject>

struct TreeNode
{
    int value;
    QByteArray name;
};

#endif // GLOBAL_H

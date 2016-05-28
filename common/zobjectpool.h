#ifndef ZOBJECTPOOL_H
#define ZOBJECTPOOL_H

#include "zglobal.h"

#include <QList>

Z_BEGIN_NAMESPACE

template<class T>
class ZObjectPool
{
public:
    ~ZObjectPool()
    {
        qDeleteAll(objectList);
        qDeleteAll(usedObjectList);
    }

    inline quint32 usedCount() const
    {
        return usedObjectList.count();
    }

    inline T *reserveObject()
    {
        if (objectList.isEmpty()) {
            objectList << new T();
        }

        usedObjectList << objectList.takeFirst();

        return usedObjectList.last();
    }

    inline void releaseObject(T *obj)
    {
        usedObjectList.removeOne(obj);
        objectList << obj;
    }

    inline void reset()
    {
        objectList << usedObjectList;
        usedObjectList.clear();
    }

private:
    QList<T*> objectList;
    QList<T*> usedObjectList;
};

Z_END_NAMESPACE

#endif // ZOBJECTPOOL_H

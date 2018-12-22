#include <QmlNet/types/NetTypeArrayFacade.h>
#include <QmlNet/types/NetTypeArrayFacadeArray.h>
#include <QmlNet/types/NetTypeArrayFacadeList.h>
#include <QmlNet/types/NetTypeInfo.h>

NetTypeArrayFacade::NetTypeArrayFacade()
{

}

QSharedPointer<NetTypeArrayFacade> NetTypeArrayFacade::fromType(QSharedPointer<NetTypeInfo> type)
{
    if(type->isArray()) {
        QSharedPointer<NetTypeArrayFacade_Array> facade = QSharedPointer<NetTypeArrayFacade_Array>(new NetTypeArrayFacade_Array(type));
        if(facade->isIncomplete()) {
            return nullptr;
        }
        return facade.staticCast<NetTypeArrayFacade>();
    }

    if(type->isList()) {
        QSharedPointer<NetTypeArrayFacade_List> facade = QSharedPointer<NetTypeArrayFacade_List>(new NetTypeArrayFacade_List(type));
        if(facade->isIncomplete()) {
            return nullptr;
        }
        return facade.staticCast<NetTypeArrayFacade>();
    }

    return nullptr;
}

bool NetTypeArrayFacade::isFixed()
{
    return false;
}

uint NetTypeArrayFacade::getLength(QSharedPointer<NetReference>)
{
    return 0;
}

QSharedPointer<NetVariant> NetTypeArrayFacade::getIndexed(QSharedPointer<NetReference>, uint)
{
    return nullptr;
}

void NetTypeArrayFacade::setIndexed(QSharedPointer<NetReference>, uint, QSharedPointer<NetVariant>)
{

}

void NetTypeArrayFacade::push(QSharedPointer<NetReference>, QSharedPointer<NetVariant>)
{

}

QSharedPointer<NetVariant> NetTypeArrayFacade::pop(QSharedPointer<NetReference>)
{
    return nullptr;
}

void NetTypeArrayFacade::deleteAt(QSharedPointer<NetReference>, uint)
{

}

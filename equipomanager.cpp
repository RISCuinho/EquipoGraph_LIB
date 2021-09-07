#include "equipomanager.h"

#include <QtGlobal>

Equipo* EquipoManager::createEquipo()
{
    Equipo *equipo = new Equipo(graphWidget);
    graphWidget->scene()->addItem(equipo);
    equipoList.append(equipo);
    equipo->setPos(getNextX(),getNextY());
    return equipo;
}

qreal EquipoManager::getNextX()
{
    x_equipoPos += 10;
    return x_equipoPos;
}


qreal EquipoManager::getNextY()
{
    y_equipoPos += 10;
    return y_equipoPos;
}

Connection* EquipoManager::createConnection(Equipo *equipo1, Equipo *equipo2)
{
    Connection* equipoConn = new Connection(equipo1,equipo2);
    connectionList.append(equipoConn);

    return equipoConn;
}

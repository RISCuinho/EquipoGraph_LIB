#ifndef EQUIPOMANAGER_H
#define EQUIPOMANAGER_H


#include <QList>
#include "eg_utils.h"
#include "equipo.h"
#include "connection.h"
#include "equipograph.h"

class EquipoManager
{
public:
  static EquipoManager* getInstance(EquipoGraphWidget *p_graphWidget)
  {
      static EquipoManager instance(p_graphWidget);

      printf("EquipoManager!/n");
      return &instance;
  }
  static EquipoManager* getInstance(){
      return getInstance(nullptr);
  }

  Equipo* createEquipo();
  Connection* createConnection(Equipo*, Equipo *);

protected:
  qreal x_equipoPos;
  qreal y_equipoPos;

  qreal getNextX();
  qreal getNextY();

private:
    EquipoManager(EquipoGraphWidget *p_graphWidget){
        if(!p_graphWidget)
            throw eg_utils::NullPointer();

        graphWidget = p_graphWidget;
    }

    EquipoGraphWidget *graphWidget;

    QList<Equipo*> equipoList;
    QList<Connection*> connectionList;


#if (__cplusplus < 201703L)
public:
    EquipoManager(EquipoManager *const)   = delete;
    void operator=(EquipoManager *const) = delete;
#else
private:
    EquipoManager(EquipoManager const&);   // Don't Implement
    void operator=(EquipoManager const&); // Don't implement
#endif

};

#endif // EQUIPOMANAGER_H

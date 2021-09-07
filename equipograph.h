#ifndef EQUIPOGRAPHLIB_H
#define EQUIPOGRAPHLIB_H

#include "equipograph_lib_global.h"
#include <QGraphicsView>

class Equipo;

class EquipoGraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    EquipoGraphWidget(QWidget *parent = 0);

    void itemMoved();

public Q_SLOTS:
    void shuffle();
    void zoomIn();
    void zoomOut();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void scaleView(qreal scaleFactor);

private:
    int timerId;
    Equipo *centerNode;
};

#endif // EQUIPOGRAPHLIB_H

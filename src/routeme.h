#ifndef ROUTEME_H
#define ROUTEME_H

#include <QtGui/QMainWindow>

class RouteMeController;

class QDeclarativeView;
class QDeclarativeContext;

class RouteMe : public QMainWindow
{
    Q_OBJECT

public:
    RouteMe(QWidget *parent = 0);
    ~RouteMe();

private:
    QDeclarativeView *m_view;
    QDeclarativeContext *m_context;
    RouteMeController *m_controller;
};
#endif

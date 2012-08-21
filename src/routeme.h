#ifndef ROUTEME_H
#define ROUTEME_H

#include <QtGui/QMainWindow>

class RouteController;

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
    RouteController *m_controller;
};
#endif

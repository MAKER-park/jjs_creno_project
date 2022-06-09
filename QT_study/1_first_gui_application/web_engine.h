#ifndef WEB_ENGINE_H
#define WEB_ENGINE_H

//for web
#include <QWebEngineView>

class WEB_engine
{
public:
    WEB_engine();
//for web
protected:
   void resizeEvent(QResizeEvent *event);
private:
   QWebEngineView *view;
   void init();
};

#endif // WEB_ENGINE_H

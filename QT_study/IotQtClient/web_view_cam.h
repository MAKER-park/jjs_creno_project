#ifndef WEB_VIEW_CAM_H
#define WEB_VIEW_CAM_H

#include <QWidget>
#include <QWebEngineView>

namespace Ui {
class web_view_cam;
}

class web_view_cam : public QWidget
{
    Q_OBJECT

public:
    explicit web_view_cam(QWidget *parent = nullptr);
    ~web_view_cam();

private:
    Ui::web_view_cam *ui;
    QWebEngineView  *pWebView;
};

#endif // WEB_VIEW_CAM_H

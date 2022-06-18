#ifndef TESTWEBVIEW_H
#define TESTWEBVIEW_H

#include <QWidget>
#include <QWebEngineView>
QT_BEGIN_NAMESPACE
namespace Ui { class TestWebView; }
QT_END_NAMESPACE

class TestWebView : public QWidget
{
    Q_OBJECT

public:
    TestWebView(QWidget *parent = nullptr);
    ~TestWebView();

private:
    Ui::TestWebView *ui;
    QWebEngineView  *pWebView;
    QWebEngineView  *pWebView2;
};
#endif // TESTWEBVIEW_H

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QImageReader>
#include <QImageWriter>
#include <QMessageBox>
#include <QStandardPaths>
#include <QLabel>
#include <QColorSpace>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    bool loadFile(const QString &fileName);
    void setImage(const QImage &newImage);
    void open();

private:
    Ui::Dialog *ui;
    QLabel* qlabel1;
    QLabel* qlabel2;
    QLabel* qlabel3;
public slots:
    void slotInversion(bool);
};
#endif // DIALOG_H

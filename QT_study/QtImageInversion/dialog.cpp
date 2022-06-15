#include "dialog.h"
#include "ui_dialog.h"
#include "MyImage.h"

#include <QDebug>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    qlabel1 = new QLabel(0);
    qlabel1->resize(640,480);
//    qlabel1->show();

    qlabel2 = new QLabel(0);
    qlabel2->resize(640,480);
//    qlabel2->show();
    connect(ui->pushButtonInversion,SIGNAL(clicked(bool)),this,SLOT(slotInversion(bool)));
//    open();
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }

//    QString strPathName = fileName; // 영상 파일 경로 획득
    char strFileName[80];
    sprintf(strFileName,"%s",(const char *)fileName.toStdString().c_str());
    qDebug() << strFileName;

    CByteImage imageIn;
    if (!imageIn.LoadImage(strFileName)) // 영상 읽기
//    if (!imageIn.LoadImage(fileName)) // 영상 읽기
    {
        return false; // 영상 읽기에 실패하면 함수를 종료
    }

    // 입력 영상의 화면 출력, 두번째 인자는 출력 창의 이름
//    ShowImage(imageIn, "Input");
    qlabel1->setPixmap(QPixmap::fromImage(newImage));
    qlabel1->show();
    int nWidth   = imageIn.GetWidth();   // 영상의 너비
    int nHeight  = imageIn.GetHeight();  // 영상의 높이
    int nChannel = imageIn.GetChannel(); // 영상의 채널 수

    CByteImage imageOut(nWidth, nHeight, nChannel); // 결과 영상 클래스 생성

    int r, c, h;
    for (r=0 ; r<nHeight ; r++) // 행 단위 이동
    {
        for (c=0 ; c<nWidth ; c++) // 열 단위 이동
        {
            for (h=0 ; h<nChannel ; h++) // 채널 단위 이동
            {
                // 각 채널 밝기 값을 반전
                imageOut.GetAt(c, r, h) = 255 - imageIn.GetAt(c, r, h);
            }
        }
    }

    imageOut.SaveImage("inversion.bmp"); // 결과 영상의 파일 저장
//    ShowImage(imageOut, "반전 결과");	 // 결과 영상의 화면 출력
//    qlabel2->setPixmap(QPixmap::fromImage("inversion.bmp"));
    qlabel2->setPixmap(QPixmap("inversion.bmp"));
    qlabel2->show();
    return true;
}

static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;

    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen
        ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    for (const QByteArray &mimeTypeName : supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/bmp");
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("bmp");
}

void Dialog::open()
{
    QFileDialog dialog(this, tr("Open File"));
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
}
void Dialog::slotInversion(bool)
{
    open();
}

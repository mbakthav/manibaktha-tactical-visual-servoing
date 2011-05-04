#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

#include <QTimer>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QDir>
#include <QtCore/QStringList>

// move these
#include "cv.h"
#include "highgui.h"

#include "image_functions/Image_Functions.h"
#include "utilities/utilities.h"
//#include "tracking_algorithms/correlation/TuringTracking.h"

#include "tracking_algorithms/Optical_Flow/KLT/KLT.h"

#ifdef linux
#include "SimpleIni.h"
#endif

#include "ImageProcessing.h"

// template libary
#include "third_party/tnt/tnt.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer timer;
    QGraphicsView *graphicsView;
    void trace(QString str);

    // declare image functions
    Utilities *utilities;
    ImageFunctions *imageFunctions;
    //TuringTracking *turingTracking;

    KLT *klt;

private:
    Ui::MainWindow *ui;
    void createActions();
    void listFiles(QString);
    string itos(int i);

    QGraphicsScene *scene;
    QGraphicsScene *scene2;

    bool datasetLoaded;
    QString datasetName;
    QString datasetPath;
    string t;
    QStringList files;
    int datasetWidth;
    int datasetHeight;

    int fitImageToWindow;

    bool windowHeight;
    bool windowWidth;

    string iniFile;
    string dPath;

    int displayOption;

    bool histogramEqualization;

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected Q_SLOTS:

    void exitApplication();
    void toggleHistogramEqualization();
    void toggleFitToWindow();
    void openImageDirectory();
    void updateImageNumber(int);

    void getDisplayOption(int);

private slots:

    void timerEvent(QTimerEvent *);
    void on_pushButtonTrack_clicked();

};

#endif // MAINWINDOW_H

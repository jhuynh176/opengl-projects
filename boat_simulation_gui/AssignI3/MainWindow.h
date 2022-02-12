#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>

class QAction;
class QMenu;
class QPlainTextEdit;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    //~MainWindow();

    //Initiate dock widget
    QDockWidget* dock;

    //Initial Values
    int currentTics = 0;
    int maxTics = 100;
    int gridSize = 4096;

    //Region Appreviation
    QString regionA = "A";
    QString regionB = "B";
    QString regionC = "C";
    QString regionD = "D";

    //This is for random choice between 1-10
    int boatDecisionCode = -1;

    //This is to record boat chosen decision
    QString boatDecisionText;

    //BoatX Location - default center
    int boatXcoordX = 2047;
    int boatXcoordY = 2047;

    //BoatY Location - default outside of grid
    int boatYcoordXInit = -1;
    int boatYcoordYInit = -1;
    int boatYcoordX = -1;
    int boatYcoordY = -1;


    QLCDNumber *lcdCurrentTics = new QLCDNumber;
    QLabel *boatYLocation = new QLabel;

    //Initiate region for (-1,-1) is "inv" as stated
    QString regionAlarm = "Inv";

    //Exceptions = "Alarm" for Y is in the A region
    //          or "Break" for number of tics exceed max tics
    //Will be reassigned in systemExceptionsCheck() function
    bool termination = false;

    //Collect Data
    QMessageBox msgBox;
    int optionSelected = -1;

    //Varible for plot simulation
    QString fileNameOpened = "";

    QVector<int> xVector;
    QVector<int> yVector;
    QVector<QString> regionVector;

    //For dynamic resolution of graph
    int xMaxValue = 0;
    int yMaxValue = 0;

    int xMinValue = 0;
    int yMinValue = 0;


public slots:
    void startSimulation();
    void gridSizeChanged(int);
    void maxTicsChanged(int);
    void coordinateXChanged(int);
    void coordinateYChanged(int);
    void collectData();

    //This will ask user to open a .csv file;
    //  then load that file into the text editor;
    //  then start ploting the provided points to the screen
    void startPlotSimulation();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void documentWasModified();

private:
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void createDockWindow();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QPlainTextEdit *textEdit;
    QWidget* mainWindow;
    QString curFile;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QMenu *viewMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exitAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    void createTextEditor();

    void printBoatStatus();
    void systemExceptionsCheck();

    void boatYCurrentRegion();
    void makeDecision();
    void reachRegionA();

    //This will reset all values back to default,
    //      to be ready for new simulation start
    void resetSimulationValues();

    //This section is for the plot Simulation
    void readCSVFile();
    void resetVectorValues();
    void printVector();
    void createChart();
    void customizeChart();
    void findMin();

};

#endif // MAINWINDOW_H

#include <QtWidgets>
#include <QApplication>
#include <QtGui>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QValueAxis>


QT_CHARTS_USE_NAMESPACE

#include "MainWindow.h"

MainWindow::MainWindow()
{
    createTextEditor();

    createActions();
    createMenus();
    createDockWindow();

    readSettings();

    connect(textEdit->document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

    setCurrentFile("");
    setUnifiedTitleAndToolBarOnMac(true);

    setWindowTitle("Assignment I4");
    resize(1024, 800);

}

void MainWindow::printVector()
{
    for(int i=0; i<xVector.size(); i++)
    {
        QString printLine = QString::fromLatin1(
                            "%1,\t%2,\t%3")
                            .arg(xVector[i])
                            .arg(yVector[i])
                            .arg(regionVector[i]);
        textEdit->appendPlainText(printLine);
    }

}

void MainWindow::createChart()
{
    QLineSeries *series = new QLineSeries();

    for(int i=0; i<xVector.size(); i++)
    {
        *series << QPointF(xVector[i], yVector[i]);
    }

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);

    // Customize series
    QPen pen(QRgb(0xfdb157));
    pen.setWidth(1);
    series->setPen(pen);

    // Customize chart title
    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::white));

    // Customize chart background
    QLinearGradient backgroundGradient;
    backgroundGradient.setStart(QPointF(0, 0));
    backgroundGradient.setFinalStop(QPointF(0, 1));
    backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
    backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    chart->setBackgroundBrush(backgroundGradient);

    // Customize plot area background
    QLinearGradient plotAreaGradient;
    plotAreaGradient.setStart(QPointF(0, 1));
    plotAreaGradient.setFinalStop(QPointF(1, 0));
    plotAreaGradient.setColorAt(0.0, QRgb(0x555555));
    plotAreaGradient.setColorAt(1.0, QRgb(0x55aa55));
    plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    chart->setPlotAreaBackgroundBrush(plotAreaGradient);
    chart->setPlotAreaBackgroundVisible(true);

    QValueAxis *axisX = new QValueAxis;
    QValueAxis *axisY = new QValueAxis;

    // Customize axis label font
    QFont labelsFont;
    labelsFont.setPixelSize(12);
    axisX->setLabelsFont(labelsFont);
    axisY->setLabelsFont(labelsFont);

    // Customize axis colors
    QPen axisPen(QRgb(0xd18952));
    axisPen.setWidth(2);
    axisX->setLinePen(axisPen);
    axisY->setLinePen(axisPen);

    // Customize axis label colors
    QBrush axisBrush(Qt::white);
    axisX->setLabelsBrush(axisBrush);
    axisY->setLabelsBrush(axisBrush);

    // Customize grid lines and shades
    axisX->setGridLineVisible(false);
    axisY->setGridLineVisible(false);
    axisY->setShadesPen(Qt::NoPen);
    axisY->setShadesBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
    axisY->setShadesVisible(true);

    //Plotting the points
    axisX->setRange(xMinValue, xMaxValue);
    axisX->setTickCount(xMaxValue/10);
    axisX->setLabelFormat("%.2f");

    axisY->setRange(yMinValue, yMaxValue);
    axisY->setTickCount(yMaxValue/10);
    axisY->setLabelFormat("%.2f");

    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    dock = new QDockWidget(tr("Chart Area"), this);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);

    //Main group:
    QGroupBox *groupCreateChart = new QGroupBox();

    QVBoxLayout *layoutCreateChart = new QVBoxLayout;
    layoutCreateChart->addWidget(chartView);

    groupCreateChart->setLayout(layoutCreateChart);

    dock->setWidget(groupCreateChart);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    viewMenu->addAction(dock->toggleViewAction());


}


void MainWindow::createTextEditor()
{
    textEdit = new QPlainTextEdit;

    //Main group:
    QGroupBox *groupTextEditor = new QGroupBox();

    QLabel *labelTextEditor = new QLabel("Input text here: ");
    labelTextEditor->setFont(QFont("Times", 12, QFont::Bold));

    //Layout
    QVBoxLayout *layoutTextEditor = new QVBoxLayout;
    layoutTextEditor->addWidget(labelTextEditor);
    layoutTextEditor->addWidget(textEdit);

    groupTextEditor->setLayout(layoutTextEditor);

    groupTextEditor->setMaximumWidth(250);

//    groupTextEditor->setStyleSheet("background-color: #48d1cc");

    setCentralWidget(groupTextEditor);
}

void MainWindow::findMin()
{
    xMinValue = xMaxValue;
    yMinValue = yMaxValue;
    for(int i=0; i<xVector[i]; i++)
    {
        if(xVector[i] >= 0)
        {
            if(xMinValue > xVector[i])
            {
                xMinValue = xVector[i];
            }
        }
        if(yVector[i] >= 0)
        {
            if(yMinValue > yVector[i])
            {
                yMinValue = yVector[i];
            }
        }
    }
}

//![Plot Simulation Section]
void MainWindow::startPlotSimulation()
{
    open();

    //Checking if fileNameOpened received full path of the just opened file
    //  Result: it did received a full root path
    //  This path, will be use in the plot simulation
    //
    QString printLine = QString::fromLatin1(
                        "\nSuccessfully opened file: \n%1")
                        .arg(fileNameOpened);
    textEdit->appendPlainText(printLine + "\n");

    resetVectorValues();

    readCSVFile();

    findMin();

    printVector();

    createChart();
}

void MainWindow::resetVectorValues()
{
    xVector.clear();
    yVector.clear();
    regionVector.clear();
}

void MainWindow::readCSVFile()
{

    //fileNameOpened is the full path of the chosen CSV file
    QFile csvFile(fileNameOpened);
    QStringList csvList;
    csvList.clear();


    //Read and write to the csv file
    if (csvFile.open(QIODevice::ReadWrite)) {
        QTextStream stream(&csvFile);

        while (!stream.atEnd()) {
        csvList.push_back(stream.readLine()); //Save to List
        }

        csvFile.close();
    }
    else {
         QMessageBox::about(NULL, "csv file", "The file is not opened!");
    }
    int i = 0;
    Q_FOREACH(QString str, csvList) // traverse List
    {
        i = i + 1;
        QStringList valsplit = str.split(","); //Delimited string
        if(i > 2) {
        //Get depth, speed of sound, temperature
        QString stringCoordX = valsplit[0];
        QString stringCoordY = valsplit[1];
        QString regionLocation = valsplit[2];

        //Convert QString to Int
        int coordX = stringCoordX.toInt();
        int coordY = stringCoordY.toInt();

        if(xMaxValue < coordX)
            xMaxValue = coordX;

        if(yMaxValue < coordY)
            yMaxValue = coordY;

        //Reading CSV file into Vectors
        xVector.append(coordX);
        yVector.append(coordY);
        regionVector.append(regionLocation);

        }
    }
}
//![Plot Simulation Section]

//![Start Simulation Section]
void MainWindow::startSimulation()
{
    printBoatStatus();

    for(currentTics = 1; currentTics <= maxTics; currentTics++)
    {
        //Region of boat Y location
        boatYCurrentRegion();

        //Boat making new decision
        makeDecision();

        //Checking for termination condition
        //Return bool termination
        systemExceptionsCheck();

        //System update every tics
        printBoatStatus();

        //If termination condition return = true, break the loop
        if(termination == true)
            break;
    }

    //Ask user to save document
    collectData();

    //Calling reset function, to be ready for new simulation start
    resetSimulationValues();
}

void MainWindow::gridSizeChanged(int n)
{
    gridSize = n;
}

void MainWindow::maxTicsChanged(int n)
{
    maxTics = n;
}

void MainWindow::coordinateXChanged(int n)
{
    boatYcoordX = n;

    //Needed to reset boat coordinate in rerun
    boatYcoordXInit = n;
}

void MainWindow::coordinateYChanged(int n)
{
    boatYcoordY = n;

    //Needed to reset boat coordinate in rerun
    boatYcoordYInit = n;
}

void MainWindow::printBoatStatus()
{
    //Output '-1,-1,Inv' into the first line of a .csv file
    QString printLine = QString::fromLatin1(
                        "%1,%2,%3")
                        .arg(boatYcoordX)
                        .arg(boatYcoordY)
                        .arg(regionAlarm);
                        //Region Alarm here should be "Inv" as stated
    textEdit->appendPlainText(printLine);
}

void MainWindow::systemExceptionsCheck()
{

    //If maximum tics reached, exception = break
    if(currentTics == maxTics)
    {
        regionAlarm = "Break";
        termination = true;
    }

    //If boat Y reach region A, exception = alarm
    if(regionAlarm == regionA)
    {
        regionAlarm = "Alarm";
        termination = true;
    }

}

void MainWindow::boatYCurrentRegion()
{
    if((boatYcoordX >= 0 && boatYcoordX <= 4096)
            &&
            (boatYcoordY >= 0 && boatYcoordY <= 4096))
    {
        regionAlarm = regionD;

        if((boatYcoordX >= 1024 && boatYcoordX <= 3072)
                &&
                (boatYcoordY >= 1024 && boatYcoordY <= 3072))
        {
            regionAlarm = regionC;

            if((boatYcoordX >= 1536 && boatYcoordX <= 2560)
                    &&
                    (boatYcoordY >= 1536 && boatYcoordY <= 2560))
            {
                regionAlarm = regionB;

                if((boatYcoordX >= 1792 && boatYcoordX <= 2304)
                        &&
                        (boatYcoordY >= 1792 && boatYcoordY <= 2304))
                {
                    regionAlarm = regionA;
                }
            }
        }
    }

}

void MainWindow::resetSimulationValues()
{
    //Reset currentTics value
    currentTics = 0;

    //Reset region alarm value
    regionAlarm = "Inv";

    //Reset termination flag value
    termination = false;

    //Reset initial Boat Y Coordinates
    boatYcoordX = boatYcoordXInit;
    boatYcoordY = boatYcoordYInit;
}

void MainWindow::makeDecision()
{
    boatDecisionCode = (rand() % 10) + 1;

    if(boatDecisionCode == 1)
    {
//        boatDecisionText = "North";
        //Up
        boatYcoordY++;
//        textEdit->appendPlainText("Random Walk:\t\t Moving North\n");
    }
    else if(boatDecisionCode == 2)
    {
//        boatDecisionText = "North-East";
        //Up
        boatYcoordY++;
        //Right
        boatYcoordX++;
//        textEdit->appendPlainText("Random Walk:\t\t Moving North-East\n");
    }
    else if(boatDecisionCode == 3)
    {
//        boatDecisionText = "East";
        //Right
        boatYcoordX++;
//        textEdit->appendPlainText("Random Walk:\t\t Moving East\n");
    }
    else if(boatDecisionCode == 4)
    {
//        boatDecisionText = "South-East";
        //Down
        boatYcoordY--;
        //Right
        boatYcoordX++;
//        textEdit->appendPlainText("Random Walk:\t\t Moving South-East\n");
    }
    else if(boatDecisionCode == 5)
    {
//        boatDecisionText = "South";
        //Down
        boatYcoordY--;
//        textEdit->appendPlainText("Random Walk:\t\t Moving South\n");
    }
    else if(boatDecisionCode == 6)
    {
//        boatDecisionText = "South-West";
        //Down
        boatYcoordY--;
        //Left
        boatYcoordX--;
//        textEdit->appendPlainText("Random Walk:\t\t Moving South-West\n");
    }
    else if(boatDecisionCode == 7)
    {
//        boatDecisionText = "West";
        //Left
        boatYcoordX--;
//        textEdit->appendPlainText("Random Walk:\t\t Moving West\n");
    }
    else if(boatDecisionCode == 8)
    {
//        boatDecisionText = "North-West";
        //Up
        boatYcoordY++;
        //Left
        boatYcoordX--;
//        textEdit->appendPlainText("Random Walk:\t\t  Moving North-West\n");
    }
    else if(boatDecisionCode == 9)
    {
        //Do nothing
//        boatDecisionText = "Stay";
//        textEdit->appendPlainText("Random Walk:\t\t Boat Y decided to STAY\n");
    }
    else if(boatDecisionCode == 10)
    {
        //Invisible
//        boatDecisionText = "Invisible";
//        textEdit->appendPlainText("Random Walk:\t\t Boat Y decided to be INVISIBLE\n");
    }
}
//![Start Simulation Section]

//![Collect Data]
void MainWindow::collectData()
{
    msgBox.setText("The Boat Simulation has been succesfully performed.");
    msgBox.setInformativeText("Do you want to save your file?\n"
                              "\n\tSave\t = Save As"
                              "\n\tDiscard\t = Clean up Text Editor"
                              "\n\tCancel\t = Do Nothing");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    optionSelected = msgBox.exec();

    switch (optionSelected) {
    case QMessageBox::Save:
        // Save was clicked
        saveAs();
        break;
    case QMessageBox::Discard:
        // Don't Save was clicked
        textEdit->clear();
        break;
    default:
        // should never be reached
        break;
    }
}
//![Collect Data]

//![File Modification]
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::newFile()
{
    if (maybeSave()) {
        textEdit->clear();
        setCurrentFile("");
    }
}

void MainWindow::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
        fileNameOpened = fileName;

//Checking if fileNameOpened received full path of the just opened file
//  Result: it did received a full root path
//  This path, will be use in the plot simulation
//
//        QString printLine = QString::fromLatin1(
//                            "%1")
//                            .arg(fileNameOpened);
//        textEdit->appendPlainText(printLine);

    }
}

bool MainWindow::save()
{
    if (curFile.isEmpty())
    {
        return saveAs();
    }
    else
    {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}

void MainWindow::documentWasModified()
{
    setWindowModified(textEdit->document()->isModified());
}

void MainWindow::createActions()
{
    newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(QIcon(":/images/open.png"), tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(QIcon(":/images/save.png"), tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(QIcon(":/images/saveAs.png"), tr("Save &As..."), this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    exitAct = new QAction(QIcon(":/images/exit.png"), tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    cutAct = new QAction(QIcon(":/images/cut.png"), tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

    copyAct = new QAction(QIcon(":/images/copy.png"), tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

    pasteAct = new QAction(QIcon(":/images/paste.png"), tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

    aboutAct = new QAction(QIcon(":/images/about.png"), tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(QIcon(":/images/about.png"), tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    cutAct->setEnabled(false);
    copyAct->setEnabled(false);
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            cutAct, SLOT(setEnabled(bool)));
    connect(textEdit, SIGNAL(copyAvailable(bool)),
            copyAct, SLOT(setEnabled(bool)));


}

void MainWindow::createMenus()
{
    //FILE MENU
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    //EDIT MENU
    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);

    menuBar()->addSeparator();

    //VIEW MENU
    viewMenu = menuBar()->addMenu(tr("&View"));

    menuBar()->addSeparator();

    //HELP MENU
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDockWindow()
{
    /*
     * Dock: Boat Selection
     *      - Boat Activity
     *      - Boat X,Y Selection
     *      - Boat Coordinates
    */
    dock = new QDockWidget(tr("Activity and Selection"), this);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);

        //Main group:
        QGroupBox *dockGroupBoatSelection = new QGroupBox();

        QVBoxLayout *dockLayoutBoatSelection = new QVBoxLayout;

        //Boat Activity
        QGroupBox *groupBoatActivity = new QGroupBox("Boat Activity: ");

            QComboBox *boatActivity = new QComboBox;
            boatActivity->addItem("Random");
            boatActivity->addItem("Race");
            boatActivity->addItem("Circling");
            boatActivity->addItem("Chase");

            //Setting layout
            QVBoxLayout *layout = new QVBoxLayout;
            layout->addWidget(boatActivity);
            groupBoatActivity->setLayout(layout);

        //Boat Selection
        QGroupBox *groupBoatSelection = new QGroupBox("Boat Selection: ");

            QCheckBox *boatX = new QCheckBox("Boat X");
            QCheckBox *boatY = new QCheckBox("Boat Y");

            boatX->setChecked(true);
            boatY->setChecked(true);

            //Setting Layout
            QHBoxLayout *hbox = new QHBoxLayout;
            hbox->addWidget(boatX);
            hbox->addWidget(boatY);
            hbox->addSpacing(1);
            groupBoatSelection->setLayout(hbox);


        //Group for Boat Coordinates
        QGroupBox *groupBoatCoordinates = new QGroupBox("Boat Coordinates: ");

        //Boat X Coordinates
        QGroupBox *groupCoordinatesBoatX = new QGroupBox("Boat X Coordinates - DEFAULT: ");

            //X-Coordinate Label
            QLabel *boatXLabelX = new QLabel("X-Coordinate: ");
            //X-Coordinate Spinbox
            QLCDNumber *boatXCoordinateX = new QLCDNumber;
            boatXCoordinateX->display(boatXcoordX);
            boatXCoordinateX->setSegmentStyle(QLCDNumber::Flat);
            boatXCoordinateX->setMinimumHeight(30);
            boatXCoordinateX->setStyleSheet("background-color: #90ee90");


            //Y-Coordinate Label
            QLabel *boatXLabelY = new QLabel("Y-Coordinate: ");
            //Y-Coordinate Spinbox
            QLCDNumber *boatXCoordinateY = new QLCDNumber;
            boatXCoordinateY->display(boatXcoordY);
            boatXCoordinateY->setSegmentStyle(QLCDNumber::Flat);
            boatXCoordinateY->setMinimumHeight(30);
            boatXCoordinateY->setStyleSheet("background-color: #90ee90");


            //Setting QGridLayout
            QGridLayout *gridCoordinatesBoatX = new QGridLayout;
                //Grid for X
                gridCoordinatesBoatX->addWidget(boatXLabelX, 0, 0);
                gridCoordinatesBoatX->addWidget(boatXCoordinateX, 1, 0);
                //Grid for Y
                gridCoordinatesBoatX->addWidget(boatXLabelY, 0, 1);
                gridCoordinatesBoatX->addWidget(boatXCoordinateY, 1, 1);

                groupCoordinatesBoatX->setLayout(gridCoordinatesBoatX);

        //Boat Y Coordinates
        QGroupBox *groupCoordinatesBoatY = new QGroupBox("Boat Y Coordinates: ");

            //X-Coordinate Label
            QLabel *boatYLabelX = new QLabel("X-Coordinate: ");
            //X-Coordinate Spinbox
            QSpinBox *boatYCoordinateX = new QSpinBox;
            boatYCoordinateX->setRange(-1, 5000);
            boatYCoordinateX->setSingleStep(1);
            boatYCoordinateX->setValue(boatYcoordX);
            boatYCoordinateX->setMinimumHeight(30);
            boatYCoordinateX->setStyleSheet("background-color: #90ee90");

            connect(boatYCoordinateX, SIGNAL(valueChanged(int)), this, SLOT(coordinateXChanged(int)));


            //Y-Coordinate Label
            QLabel *boatYLabelY = new QLabel("Y-Coordinate: ");
            //Y-Coordinate Spinbox
            QSpinBox *boatYCoordinateY = new QSpinBox;
            boatYCoordinateY->setRange(-1, 5000);
            boatYCoordinateY->setSingleStep(1);
            boatYCoordinateY->setValue(boatYcoordY);
            boatYCoordinateY->setMinimumHeight(30);
            boatYCoordinateY->setStyleSheet("background-color: #90ee90");

            connect(boatYCoordinateY, SIGNAL(valueChanged(int)), this, SLOT(coordinateYChanged(int)));



            //Setting QGridLayout
            QGridLayout *gridCoordinatesBoatY = new QGridLayout;
                //Grid for X
                gridCoordinatesBoatY->addWidget(boatYLabelX, 0, 0);
                gridCoordinatesBoatY->addWidget(boatYCoordinateX, 1, 0);
                //Grid for Y
                gridCoordinatesBoatY->addWidget(boatYLabelY, 0, 1);
                gridCoordinatesBoatY->addWidget(boatYCoordinateY, 1, 1);

                groupCoordinatesBoatY->setLayout(gridCoordinatesBoatY);


            QGridLayout *gridBoatCoordinates = new QGridLayout;
                gridBoatCoordinates->addWidget(groupCoordinatesBoatX, 0, 0);
                gridBoatCoordinates->addWidget(groupCoordinatesBoatY, 1, 0);
                groupBoatCoordinates->setLayout(gridBoatCoordinates);


        //Will add grid
        dockLayoutBoatSelection->addWidget(groupBoatActivity);
        dockLayoutBoatSelection->addWidget(groupBoatSelection);
        dockLayoutBoatSelection->addWidget(groupBoatCoordinates);

        dockGroupBoatSelection->setLayout(dockLayoutBoatSelection);

        dock->setWidget(dockGroupBoatSelection);
        addDockWidget(Qt::LeftDockWidgetArea, dock);
        viewMenu->addAction(dock->toggleViewAction());

    /*
     * Dock: Boat Application
     *      - Grid Size (N x N)
     *      - Maximum Simulation Tics
     *      - Termination Conditions
    */
    dock = new QDockWidget(tr("Boat Application"), this);
    dock->setAllowedAreas(Qt::BottomDockWidgetArea);

        //Main group:
        QGroupBox *dockGroupBoatApplication = new QGroupBox();

        QVBoxLayout *dockLayoutBoatApplication = new QVBoxLayout;


        //Group - Grid Size
        QGroupBox *groupGridSize = new QGroupBox("Grid Size (N x N): ");
        //groupBox->setFlat(true);

            //Label
            QLabel *labelValueN = new QLabel("Select value for N: ");
            //LCD for N
            QLCDNumber *lcdGridSize = new QLCDNumber(4);
            lcdGridSize->setSegmentStyle(QLCDNumber::Flat);
            lcdGridSize->setStyleSheet("background-color: #90ee90");
            lcdGridSize->setMinimumHeight(50);
            lcdGridSize->setMaximumHeight(50);

            //Slider for N
            QSlider *slider = new QSlider(Qt::Horizontal);
            slider->setRange(0, 4096);

            //Connect Slider and LCD
            connect(slider, SIGNAL(valueChanged(int)), lcdGridSize, SLOT(display(int)));
            connect(slider, SIGNAL(valueChanged(int)), this, SLOT(gridSizeChanged(int)));

            slider->setValue(gridSize);

            //Setting layout
            QGridLayout *gridGridSize = new QGridLayout;
            gridGridSize->addWidget(labelValueN, 0, 0);
            gridGridSize->addWidget(lcdGridSize, 0, 2, 2, 2);
            gridGridSize->addWidget(slider, 1, 0, 1, 2);

            groupGridSize->setLayout(gridGridSize);

        //Group - Maximum Simulation Tics
         QGroupBox *groupMaxTics = new QGroupBox("Maximum Simulation Tics");

            //LCD for Tics
            QLCDNumber *lcdMaxTics = new QLCDNumber(4);
            lcdMaxTics->setSegmentStyle(QLCDNumber::Flat);
            lcdMaxTics->setStyleSheet("background-color: #90ee90");
            lcdMaxTics->setMinimumHeight(50);
            lcdMaxTics->setMaximumHeight(50);
            //lcdMaxTics->display(maxTics);

            //Create dial for tics
            QDial *dial = new QDial;
            dial->setRange(0, 500);
            dial->setStyleSheet("background-color: #ff8c00");

            connect(dial, SIGNAL(valueChanged(int)), lcdMaxTics, SLOT(display(int)));
            connect(dial, SIGNAL(valueChanged(int)), this, SLOT(maxTicsChanged(int)));

            dial->setValue(maxTics);

            //Setting layout
            QGridLayout *gridMaxTics = new QGridLayout;
            gridMaxTics->addWidget(lcdMaxTics, 0, 0, 2, 2);
            gridMaxTics->addWidget(dial, 0, 3, 2, 1);

            groupMaxTics->setLayout(gridMaxTics);


        //Group - Termination Conditions
        QGroupBox *groupTermination = new QGroupBox("Termination Conditions");

            //Creating radio button for choices
            QCheckBox *button1 = new QCheckBox("DEFAULT - The Current Tics exceed Maximum Tics");
            QCheckBox *button2 = new QCheckBox("DEFAULT - Boat Y is in subregion A");
            QCheckBox *button3 = new QCheckBox("NOT REQUIRED - Boat Y is close to Boat X");

            button1->setChecked(true);
            button2->setChecked(true);

            //Setting vertical layout
            QVBoxLayout *layoutTermination = new QVBoxLayout;
            layoutTermination->addWidget(button1);
            layoutTermination->addWidget(button2);
            layoutTermination->addWidget(button3);

            groupTermination->setLayout(layoutTermination);

        dockLayoutBoatApplication->addWidget(groupGridSize);
        dockLayoutBoatApplication->addWidget(groupMaxTics);
        dockLayoutBoatApplication->addWidget(groupTermination);

        dockGroupBoatApplication->setLayout(dockLayoutBoatApplication);

        dock->setWidget(dockGroupBoatApplication);
        addDockWidget(Qt::BottomDockWidgetArea, dock);
        viewMenu->addAction(dock->toggleViewAction());


    /*
     * Dock: Check for Exception
     *      - Current Tics
     *      - Boat Y - Region Alarm
     *      - Quit the program
    */
    dock = new QDockWidget(tr("Boat Execution"), this);
    dock->setAllowedAreas(Qt::BottomDockWidgetArea);

        //Main group:
        QGroupBox *dockGroupBoatSystem = new QGroupBox();

        QVBoxLayout *dockLayoutBoatSystem = new QVBoxLayout;

        //Start button
        QGroupBox *groupSimulationButton = new QGroupBox();

        //Start Simulation Button
        QLabel *startLabel = new QLabel("Click to start the Simulation!");
            startLabel->setFont(QFont("Times", 12, QFont::Bold));

            QPushButton *start = new QPushButton(tr("Start"));
            start->setFont(QFont("Times", 18, QFont::Bold));
            start->setStyleSheet("background-color: #1e90ff");
            start->setMinimumHeight(90);

            //Connect quit signal
            connect(start, SIGNAL(clicked()), this, SLOT(startSimulation()));

        //Plot Simulation Button
        QLabel *plotLabel = new QLabel("Click to plot the Opened CSV file!");
            plotLabel->setFont(QFont("Times", 12, QFont::Bold));

            QPushButton *plot = new QPushButton(tr("Plot"));
            plot->setFont(QFont("Times", 18, QFont::Bold));
            plot->setStyleSheet("background-color: #32cd32");
            plot->setMinimumHeight(90);

            //Connect quit signal
            connect(plot, SIGNAL(clicked()), this, SLOT(startPlotSimulation()));

            //Setting layout
            QGridLayout *gridSimulation = new QGridLayout;
            gridSimulation->addWidget(startLabel, 0, 0);
            gridSimulation->addWidget(start, 1, 0);
            gridSimulation->addWidget(plotLabel, 0, 1);
            gridSimulation->addWidget(plot, 1, 1);

            groupSimulationButton->setLayout(gridSimulation);

        //Quit button
        QGroupBox *groupQuitButton = new QGroupBox("Quit the program!");

            QPushButton *quit = new QPushButton(tr("Quit"));
            quit->setFont(QFont("Times", 18, QFont::Bold));
            quit->setStyleSheet("background-color: #ffb6c1");
            quit->setMinimumHeight(90);

            //Connect quit signal
            connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

            //Setting vertical layout
            QVBoxLayout *layoutQuit = new QVBoxLayout;
            layoutQuit->addWidget(quit);

            groupQuitButton->setLayout(layoutQuit);

        dockLayoutBoatSystem->addWidget(groupSimulationButton);
        dockLayoutBoatSystem->addWidget(groupQuitButton);

        dockGroupBoatSystem->setLayout(dockLayoutBoatSystem);

        dock->setWidget(dockGroupBoatSystem);
        addDockWidget(Qt::BottomDockWidgetArea, dock);
        viewMenu->addAction(dock->toggleViewAction());


}

void MainWindow::readSettings()
{
    QSettings settings("Hieu Huynh", "Assignment I3");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(400, 400)).toSize();
    resize(size);
    move(pos);
}

void MainWindow::writeSettings()
{
    QSettings settings("Hieu Huynh", "Assignment I3");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

bool MainWindow::maybeSave()
{
    if (textEdit->document()->isModified()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Application"),
                     tr("The document has been modified.\n"
                        "Do you want to save your changes?"),
                     QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    textEdit->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    out << textEdit->toPlainText();
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    textEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName = "untitled.csv";
    setWindowFilePath(shownName);
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
//![File Modification]

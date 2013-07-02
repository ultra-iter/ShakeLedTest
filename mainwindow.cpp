#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(16);
    ui->tableWidget->setColumnCount(16);

    for (int i = 0; i < 16; i++)
    {
        ui->tableWidget->setRowHeight(i, 18);
        ui->tableWidget->setColumnWidth(i, 18);
    }

    //----------------------------------------------------------

    timer.setParent(this);
    timer.setInterval(14);
    connect(&timer, SIGNAL(timeout()), this, SLOT(slotTimeout()));
    timer.start();

    //----------------------------------------------------------

    cnter = 0;
    charX = " ";

//    showChar(ui->tableWidget, cnter, charX, 0xFF00);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showChar(QTableWidget* tw, int col, QString charX, quint16 mode)
{
    for (int i = 0; i < 16; i++)
    {
        if ((mode & 0x8000) == 0x8000)
        {
            tw->setItem(i, col, new QTableWidgetItem(charX));
            tw->item(i, col)->setBackgroundColor(QColor(Qt::yellow));
            tw->item(i, col)->setTextAlignment(Qt::AlignCenter);
        }
        mode = mode << 1;
    }
}

void MainWindow::slotTimeout()
{
    qDebug() << "timeout ... " << cnter;
    quint16 mode = 0;

    /*
    QTime startTime = QTime::currentTime();
    while (1)
    {
        QTime endTime = QTime::currentTime();

        if (startTime.msecsTo(endTime) > 15)
        {
            break;
        }
    }
    //*/

    ui->tableWidget->clearContents();

    switch (cnter)
    {
        case 0: mode = 0x0000; break;
        case 1: mode = 0x0000; break;
        case 2: mode = 0x1FE0; break;
        case 3: mode = 0x0FC0; break;
        case 4: mode = 0x0840; break;
        case 5: mode = 0x0840; break;
        case 6: mode = 0x0840; break;
        case 7: mode = 0xFFFF; break;
        case 8: mode = 0x7FFE; break;
        case 9: mode = 0x0840; break;
        case 10: mode = 0x0840; break;
        case 11: mode = 0x0840; break;
        case 12: mode = 0x0FE0; break;
        case 13: mode = 0x1FC0; break;
        case 14: mode = 0x0800; break;
        case 15: mode = 0x0000; break;
        default: break;
    }

    showChar(ui->tableWidget, cnter, charX, mode);

    cnter++;
    if (cnter == 16)
    {
        cnter = 0;
    }
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTimer>
#include <QTime>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QTimer timer;
    int cnter;
    QString charX;

    void showChar(QTableWidget* tw, int col, QString charX, quint16 mode);

private slots:
    void slotTimeout();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dothething_clicked();

    void on_browseOldList_clicked();

    void on_browseNewList_clicked();

    void on_browseAddLoc_clicked();

    void on_browseDelLoc_clicked();

    bool textboxErrorCheck();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

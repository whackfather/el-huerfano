#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include <QFileDialog>

const int TIMEOUT = 3000;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_dothething_clicked() {
    std::string oldFilepath = ui->newListTextbox->text().toStdString();
    std::string newFilepath = ui->oldListTextbox->text().toStdString();
    filterCSVs(oldFilepath, newFilepath);
    ui->statusbar->setStyleSheet("QStatusBar {color: green;}");
    ui->statusbar->showMessage(QString("Filtering complete"), TIMEOUT);
}

void MainWindow::on_browseOldList_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select CSV file"), "C:/Users", tr("CSV files (*.csv)"));
    ui->oldListTextbox->setText(fileName);
}

void MainWindow::on_browseNewList_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select CSV file"), "C:/Users", tr("CSV files (*.csv)"));
    ui->newListTextbox->setText(fileName);
}

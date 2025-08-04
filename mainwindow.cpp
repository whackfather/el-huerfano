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
    if (textboxErrorCheck()) {
        ui->statusbar->setStyleSheet("QStatusBar {color: red;}");
        ui->statusbar->showMessage(QString("One or more text boxes are missing file locations"), 5000);
        return;
    }

    const std::vector<std::string> targetCounties = {
        "COUNTY_NAME",
        "BEE",
        "BROOKS",
        "DE WITT",
        "DUVAL",
        "FORT BEND",
        "GOLIAD",
        "HIDALGO",
        "JACKSON",
        "JIM HOGG",
        "JIM WELLS",
        "KARNES",
        "LIVE OAK",
        "MCMULLEN",
        "STARR",
        "VICTORIA",
        "WEBB",
        "WHARTON",
        "ZAPATA"
    };

    QString oldFilepath = ui->oldListTextbox->text();
    QXlsx::Document oldList(oldFilepath);
    int apiColPrevList = ui->apiColPrevList->text().toInt();
    bool oldUsesHeaders = ui->inclHeadersPrev->checkState();
    std::vector<int> oldListTargetRows = getTargetCountyRows(oldList, targetCounties);

    QString newFilepath = ui->newListTextbox->text();
    QXlsx::Document newList(newFilepath);
    int apiColNewList = ui->apiColNewList->text().toInt();
    bool newUsesHeaders = ui->inclHeadersNew->checkState();
    std::vector<int> newListTargetRows = getTargetCountyRows(newList, targetCounties);

    QXlsx::Document* whatCameOff = checkAPIandWrite(oldList, newList, oldListTargetRows, newListTargetRows, apiColPrevList, apiColNewList, oldUsesHeaders);
    QXlsx::Document* whatCameOn = checkAPIandWrite(newList, oldList, newListTargetRows, oldListTargetRows, apiColNewList, apiColPrevList, newUsesHeaders);

    whatCameOff->saveAs(ui->delDownloadLoc->text());
    whatCameOn->saveAs(ui->addDownloadLoc->text());

    delete whatCameOff;
    delete whatCameOn;

    ui->statusbar->setStyleSheet("QStatusBar {color: green;}");
    ui->statusbar->showMessage(QString("Filtering complete"), TIMEOUT);
}

void MainWindow::on_browseOldList_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select .xlsx file"), "C:/", tr("Excel files (*.xlsx)"));
    ui->oldListTextbox->setText(fileName);
}

void MainWindow::on_browseNewList_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select .xlsx file"), "C:/Users", tr("Excel files (*.xlsx)"));
    ui->newListTextbox->setText(fileName);
}

void MainWindow::on_browseAddLoc_clicked() {
    QString saveFileName = QFileDialog::getSaveFileName(this, tr("Save file"), "additions.xlsx", tr("Excel files (*.xlsx)"));
    ui->addDownloadLoc->setText(saveFileName);
}

void MainWindow::on_browseDelLoc_clicked() {
    QString saveFileName = QFileDialog::getSaveFileName(this, tr("Save file"), "deletions.xlsx", tr("Excel files (*.xlsx)"));
    ui->delDownloadLoc->setText(saveFileName);
}

bool MainWindow::textboxErrorCheck() {
    bool error = false;

    if (ui->oldListTextbox->text().isEmpty()) {
        error = true;
    }
    if (ui->newListTextbox->text().isEmpty()) {
        error = true;
    }
    if (ui->addDownloadLoc->text().isEmpty()) {
        error = true;
    }
    if (ui->delDownloadLoc->text().isEmpty()) {
        error = true;
    }

    return error;
}


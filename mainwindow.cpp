#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"

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

    FileInfo* oldFile = new FileInfo;
    QXlsx::Document oldList(ui->oldListTextbox->text());
    oldFile->document = &oldList;
    oldFile->apiCol = ui->apiColPrevList->text().toInt();
    oldFile->usesHeaders = ui->inclHeadersPrev->checkState();
    oldFile->targetRows = getTargetCountyRows(*oldFile->document, targetCounties);

    FileInfo* newFile = new FileInfo;
    QXlsx::Document newList(ui->newListTextbox->text());
    newFile->document = &newList;
    newFile->apiCol = ui->apiColNewList->text().toInt();
    newFile->usesHeaders = ui->inclHeadersNew->checkState();
    newFile->targetRows = getTargetCountyRows(*newFile->document, targetCounties);

    QXlsx::Document* whatCameOff = checkAPIandWrite(*oldFile, *newFile);
    QXlsx::Document* whatCameOn = checkAPIandWrite(*newFile, *oldFile);

    whatCameOff->saveAs(ui->delDownloadLoc->text());
    whatCameOn->saveAs(ui->addDownloadLoc->text());

    delete oldFile;
    delete newFile;
    delete whatCameOff;
    delete whatCameOn;

    ui->statusbar->setStyleSheet("QStatusBar {color: green;}");
    ui->statusbar->showMessage(QString("Filtering complete"), 3000);
}

void MainWindow::on_browseOldList_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select .xlsx file"), "C:/Users", tr("Excel files (*.xlsx)"));
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


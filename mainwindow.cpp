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
    std::vector<int> oldListTargetRows = getTargetCountyRows(oldList, targetCounties);

    QString newFilepath = ui->newListTextbox->text();
    QXlsx::Document newList(newFilepath);
    std::vector<int> newListTargetRows = getTargetCountyRows(newList, targetCounties);

    QXlsx::Document* whatCameOff = checkAPIandWrite(oldList, newList, oldListTargetRows, newListTargetRows);
    QXlsx::Document* whatCameOn = checkAPIandWrite(newList, oldList, newListTargetRows, oldListTargetRows);

    whatCameOff->saveAs("deletions.xlsx");
    whatCameOn->saveAs("additions.xlsx");

    delete whatCameOff;
    delete whatCameOn;

    ui->statusbar->setStyleSheet("QStatusBar {color: green;}");
    ui->statusbar->showMessage(QString("Filtering complete"), TIMEOUT);
}

void MainWindow::on_browseOldList_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select .xlsx file"), "C:/Users", tr("Excel files (*.xlsx)"));
    ui->oldListTextbox->setText(fileName);
}

void MainWindow::on_browseNewList_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select .xlsx file"), "C:/Users", tr("Excel files (*.xlsx)"));
    ui->newListTextbox->setText(fileName);
}

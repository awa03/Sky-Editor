#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settingswindow.h"
#include "QFileDialog"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_File_triggered()
{
    openFile();
}


void MainWindow::setFontSize(int newSize){
    QFont font = ui->plainTextEdit->font();
    font.setPointSize(newSize);
    ui->plainTextEdit->setFont(font);
}

void MainWindow::setHeaderDisplay(std::string newText){
    QString qString = QString::fromStdString(newText);
    this->setWindowTitle(qString);
}

void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file:\n%1").arg(fileName));
        return;
    }

    QTextStream in(&file);
    ui->plainTextEdit->setPlainText(in.readAll());

    currentFileName = fileName;

    file.close();
}


void MainWindow::setTabSpace(int newTabSpace){
    QTextOption option = ui->plainTextEdit->document()->defaultTextOption();
    option.setTabStopDistance(newTabSpace * QFontMetrics(ui->plainTextEdit->font()).averageCharWidth());
    ui->plainTextEdit->document()->setDefaultTextOption(option);
}


void MainWindow::on_actionNew_File_triggered()
{
    openFile();
}

void MainWindow::on_actionNew_File_2_triggered(){
    return;
}

void MainWindow::setEditorFont(const QFont &f){
    ui->plainTextEdit->setFont(f);
}

int MainWindow::getFontSize(){
    return ui->plainTextEdit->font().pointSize();
}

int MainWindow::getTabSpace(){
    return ui->plainTextEdit->tabStopDistance();
}

QFont MainWindow::getSystemFont(){
    return this->font();
}
QFont MainWindow::getEditorFont(){
    return ui->plainTextEdit->font();
}

void MainWindow::on_actionSave_File_triggered()
{
    if (currentFileName.isEmpty()) {
        // If no file is currently open, prompt to save as a new file
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
        if (fileName.isEmpty())
            return;

        currentFileName = fileName; // Update the current file name
    }

    QFile file(currentFileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot save file:\n%1").arg(currentFileName));
        return;
    }

    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();
    file.close();
   }


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Cannot save file:\n%1").arg(fileName));
        return;
    }

    QTextStream out(&file);
    out << ui->plainTextEdit->toPlainText();
    file.close();
}


void MainWindow::on_actionSettings_triggered()
{
    SettingsWindow currSettingsWindow(this);
    currSettingsWindow.setModal(true);
    currSettingsWindow.exec();
}



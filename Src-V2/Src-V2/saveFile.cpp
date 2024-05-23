#include "saveFile.h"
#include "ui_saveFile.h"

newFile::newFile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::newFile)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

newFile::~newFile()
{
    delete ui;
}

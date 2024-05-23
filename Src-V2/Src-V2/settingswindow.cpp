#include "settingswindow.h"
#include "mainwindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(MainWindow *parent)
    : QDialog(parent)
    , ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    parentWindow = parent;
    loadSettings();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::loadSettings(){
    ui->font_box->setValue(parentWindow->getFontSize());
    ui->tab_box->setValue(parentWindow->getTabSpace() / 4);
    ui->AppFont->setCurrentFont(parentWindow->getSystemFont());
    ui->EditorFont->setCurrentFont(parentWindow->getEditorFont());
}



void SettingsWindow::on_font_box_valueChanged(int arg1)
{
    parentWindow->setFontSize(arg1);
}


void SettingsWindow::on_tab_box_valueChanged(int arg1)
{
    parentWindow->setTabSpace(arg1);
}


void SettingsWindow::on_EditorFont_currentFontChanged(const QFont &f)
{
    parentWindow->setEditorFont(f);
}


void SettingsWindow::on_AppFont_currentFontChanged(const QFont &f)
{
    parentWindow->setEditorFont(f);
}


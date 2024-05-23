#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(MainWindow *parent = nullptr);
    ~SettingsWindow();

private slots:
    void loadSettings();

    void on_font_box_valueChanged(int arg1);
    void on_tab_box_valueChanged(int arg1);

    void on_EditorFont_currentFontChanged(const QFont &f);

    void on_AppFont_currentFontChanged(const QFont &f);

private:
    Ui::SettingsWindow *ui;
    MainWindow* parentWindow;
};

#endif // SETTINGSWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void on_actionNew_File_2_triggered();
    void setFontSize(int newSize);
    void setHeaderDisplay(std::string newText);
    void setEditorFont(const QFont &f);
    void setTabSpace(int newTabSpace);

    int getFontSize();
    int getTabSpace();
    QFont getSystemFont();
    QFont getEditorFont();

    ~MainWindow();

private slots:
    // Click Events

    void on_actionOpen_File_triggered();
    void on_actionNew_File_triggered();

    // Abstraction
    void openFile();

    void on_actionSave_File_triggered();
    void on_actionSave_As_triggered();
    void on_actionSettings_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFileName;
};
#endif // MAINWINDOW_H

#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QDialog>

namespace Ui {
class newFile;
}

class newFile : public QDialog
{
    Q_OBJECT

public:
    explicit newFile(QWidget *parent = nullptr);
    ~newFile();

private:
    Ui::newFile *ui;
};

#endif // SAVEFILE_H

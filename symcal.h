#ifndef SYMCAL_H
#define SYMCAL_H

#include <QMainWindow>

namespace Ui {
class SymCal;
}

class SymCal : public QMainWindow
{
    Q_OBJECT

public:
    explicit SymCal(QWidget *parent = 0);
    ~SymCal();

private:
    Ui::SymCal *ui;
};

#endif // SYMCAL_H

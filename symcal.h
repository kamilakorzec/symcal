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

private slots:
    void on_export_triggered();
    void on_calculateValue_triggered();
    void on_convert_triggered();
};

#endif // SYMCAL_H

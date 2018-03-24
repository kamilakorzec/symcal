#include "symcal.h"
#include "ui_symcal.h"

SymCal::SymCal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SymCal)
{
    ui->setupUi(this);
}

SymCal::~SymCal()
{
    delete ui;
}

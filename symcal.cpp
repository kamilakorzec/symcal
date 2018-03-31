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

void SymCal::on_calculateValue_triggered()
{

}

void SymCal::on_convert_triggered()
{

}

void SymCal::on_export_triggered()
{

}

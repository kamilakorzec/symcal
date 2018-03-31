#include <QString>
#include <QCoreApplication>
#include "symcal.h"
#include "ui_symcal.h"
#include "lib/range.h"

//to remove
#include <iostream>

SymCal::SymCal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SymCal)
{
    ui->setupUi(this);
    connectSlots(ui);
}

SymCal::~SymCal()
{
    delete ui;
}

void SymCal::connectSlots(Ui::SymCal *ui)
{
    connect(ui->calcButton, SIGNAL(released()), this, SLOT(on_calculateValue_triggered()));
    connect(ui->convertButton, SIGNAL(released()), this, SLOT(on_convert_triggered()));
}

void SymCal::on_calculateValue_triggered()
{
    double from = ui->calcFromInput->value();
    double to = ui->calcToInput->value();

    Range<double> *range = new Range<double>(from, to);

    std::cout << "from:" << from << "to:" << to << '\n';

}

void SymCal::on_convert_triggered()
{
    QString functionFormula = ui->functionInput->text();
    std::cout << "input:" << functionFormula.toStdString() << '\n';
}

void SymCal::on_export_triggered()
{

}

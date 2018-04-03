#include <QString>
#include <QCoreApplication>
#include "symcal.h"
#include "ui_symcal.h"
#include "lib/range.h"
#include "lib/inputparser.h"

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

    Range<double> range(from, to);

    std::cout << "from:" << from << "to:" << to << endl;

}

void SymCal::on_convert_triggered()
{
    InputParser inputParser;

    string functionFormula = ui->functionInput->text().toStdString();
    bool toStandard = ui->isSuffix->isChecked();

    if(toStandard)
    {
        try
        {
            string parsed = inputParser.parseSuffix(functionFormula);
        }
        catch(string e)
        {
            cerr<<e;
        }
    }
    else
    {
        try
        {
            string parsed = inputParser.parseStandard(functionFormula);

            //TODO: remove;
            cout<<parsed<<endl;
        }
        catch(string e)
        {
            cerr<<e;
        }
    }
}

void SymCal::on_export_triggered()
{

}

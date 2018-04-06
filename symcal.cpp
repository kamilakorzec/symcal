#include <QString>
#include <QCoreApplication>
#include <stdexcept>
#include <iostream>
#include "symcal.h"
#include "ui_symcal.h"
#include "lib/range.h"
#include "lib/inputparser.h"
#include "lib/onevarfunctionparser.h"

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

    if(func.isInitialized())
    {
        try
        {
            func.calculateValues(range);
        }
        catch(invalid_argument e)
        {
            cerr << e.what() << endl;
        }
    }
    else
    {
        cerr << "Can't calculate: no function!" << endl;
    }

}

void SymCal::on_convert_triggered()
{
    InputParser inputParser;
    OneVarFunctionParser functionParser;

    string functionFormula = ui->functionInput->text().toStdString();
    bool toStandard = ui->isSuffix->isChecked();

    if(toStandard)
    {
        try
        {
            string parsed = inputParser.parseSuffix(functionFormula);
        }
        catch(invalid_argument e)
        {
            cerr<<e.what()<<endl;
        }
    }
    else
    {
        try
        {
            string parsed = inputParser.parseStandard(functionFormula);
            func = functionParser.fromStandardNotation(parsed);

            //TODO: remove;
            cout<<"Input:"<<parsed<<endl;
            cout<<"Output:"<<func.toSuffixNotation()<<endl;
        }
        catch(invalid_argument e)
        {
            cerr<<e.what()<<endl;
        }
    }
}

void SymCal::on_export_triggered() {}

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
    bool toInfix = ui->isPostfix->isChecked();

    if(toInfix)
    {
        try
        {
            string parsed = inputParser.parsePostfix(functionFormula);
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
            string parsed = inputParser.parseInfix(functionFormula);
            func = functionParser.fromInfixNotation(parsed);

            //TODO: remove;
            cout<<"Input:"<<parsed<<endl;
            cout<<"Output:"<<func.toPostfixNotation()<<endl;
        }
        catch(invalid_argument e)
        {
            cerr<<e.what()<<endl;
        }
    }
}

void SymCal::on_export_triggered() {}

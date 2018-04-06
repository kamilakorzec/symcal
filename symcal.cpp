#include <QString>
#include <QCoreApplication>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "symcal.h"
#include "ui_symcal.h"
#include "lib/range.h"
#include "lib/inputparser.h"
#include "lib/onevarfunctionparser.h"
#include "lib/exporter.h"

SymCal::SymCal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SymCal)
{
    ui->setupUi(this);
    connectSlots();
}

SymCal::~SymCal()
{
    delete ui;
}

void SymCal::connectSlots()
{
    connect(ui->calcButton, SIGNAL(released()), this, SLOT(on_calculateValue_triggered()));
    connect(ui->convertButton, SIGNAL(released()), this, SLOT(on_convert_triggered()));
    connect(ui->exportButton, SIGNAL(released()), this, SLOT(on_export_triggered()));
}

OneVarFunctionValues SymCal::precalculateValues() {

    double from = ui->calcFromInput->value();
    double to = ui->calcToInput->value();

    Range<double> range(from, to);

    if(func.isInitialized())
    {
        OneVarFunctionValues ovfv = func.calculateValues(range);
        vector<Point> vals = ovfv.getValues();

        return ovfv;
    }
    else
    {
        throw "Can't calculate: no function!";
    }

}

void SymCal::addAndFillChart(vector<Point> vals)
{
    QSplineSeries* series = new QSplineSeries();

    for(vector<Point>::iterator it = vals.begin(); it != vals.end(); ++it)
    {
        series->append(it->getX(), it->getY());
    }

    QChart* chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(QString::fromStdString(func.toInfixNotation()));

    ui->chart->setChart(chart);

}

void SymCal::fillTable(vector<Point> vals, Range<double> range)
{
    // add two additional rows - range is inclusive and header needs its own row
    ui->tableWidget->setRowCount((int)(range.getTo()-range.getFrom())/0.01 + 2);

    for(vector<Point>::iterator it = vals.begin(); it != vals.end(); ++it)
    {
        int dist = distance(vals.begin(), it);

        QLabel* labelx = new QLabel(ui->tableWidget);
        QLabel* labely = new QLabel(ui->tableWidget);

        labelx->setText(QString::fromStdString(to_string(it->getX())));
        labely->setText(QString::fromStdString(to_string(it->getY())));

        ui->tableWidget->setCellWidget(
                    dist,
                    0,
                    labelx
                    );
        ui->tableWidget->setCellWidget(
                    dist,
                    1,
                    labely
                    );
    }
}

void SymCal::on_calculateValue_triggered()
{
    try
    {
        OneVarFunctionValues ovfv = precalculateValues();
        vector<Point> vals = ovfv.getValues();

        double from = ui->calcFromInput->value();
        double to = ui->calcToInput->value();

        Range<double> range(from, to);

        fillTable(vals, range);
        addAndFillChart(vals);
    }
    catch (string e)
    {
        cerr << e << endl;
    }
    catch (invalid_argument e)
    {
        cerr << e.what() << endl;
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
            func = functionParser.fromPostfixNotation(parsed);
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
        }
        catch(invalid_argument e)
        {
            cerr<<e.what()<<endl;
        }
    }
}

void SymCal::on_export_triggered() {
    {
        try
        {
            OneVarFunctionValues ovfv = precalculateValues();
            vector<Point> vals = ovfv.getValues();

            double from = ui->calcFromInput->value();
            double to = ui->calcToInput->value();

            Range<double> range(from, to);

            fillTable(vals, range);
            addAndFillChart(vals);

            Exporter exp;
            OneVarFunction *f = &func;

            exp.exportValues(f, ovfv);
        }
        catch (string e)
        {
            cerr << e << endl;
        }
        catch (invalid_argument e)
        {
            cerr << e.what() << endl;
        }
    }
}

#include "lib/exporter.h"
#include <QFile>
#include <QTextStream>
#include <chrono>
#include <sstream>

using namespace std;

void Exporter::exportValues(OneVarFunction *fun, OneVarFunctionValues values)
{
    stringstream fname;
    fname << "sym_cal_";
    fname << chrono::system_clock::now().time_since_epoch().count();
    fname << ".csv";

    QFile file(QString::fromStdString(fname.str()));
    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }

    QTextStream qts(&file);
    qts << "SymCal \n";
    qts << "Function: " << QString::fromStdString(fun->toInfixNotation()) << '\n';
    qts << "Postfix notation:" << QString::fromStdString(fun->toPostfixNotation()) << '\n';
    qts << "x, y" << '\n';

    vector<Point> vals = values.getValues();

    for(vector<Point>::iterator it = vals.begin(); it != vals.end(); ++it)
    {
        qts << QString::fromStdString(to_string(it->getX()));
        qts << ',';
        qts << QString::fromStdString(to_string(it->getY())) << '\n';
    }

    file.close();
}

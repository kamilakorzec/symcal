#include "ui_symcal.h"

void Ui_SymCal::setupCalcArea()
{
    calcToInput = new QDoubleSpinBox(widget);
    calcToInput->setObjectName(QStringLiteral("calcToInput"));
    calcToInput->setGeometry(QRect(110, 280, 62, 22));
    calcToInput->setMinimum((double) -100);

    calcFromInput = new QDoubleSpinBox(widget);
    calcFromInput->setObjectName(QStringLiteral("calcFromInput"));
    calcFromInput->setGeometry(QRect(110, 250, 62, 22));
    calcFromInput->setMinimum((double) -100);

    calcButton = new QPushButton(widget);
    calcButton->setObjectName(QStringLiteral("calcButton"));
    calcButton->setGeometry(QRect(130, 310, 93, 28));

}

void Ui_SymCal::setupConvertArea()
{
    convertButton = new QPushButton(widget);
    convertButton->setObjectName(QStringLiteral("convertButton"));
    convertButton->setGeometry(QRect(130, 150, 93, 28));

    inputFromLabel = new QLabel(widget);
    inputFromLabel->setObjectName(QStringLiteral("label"));
    inputFromLabel->setGeometry(QRect(20, 250, 55, 16));

    inputToLabel = new QLabel(widget);
    inputToLabel->setObjectName(QStringLiteral("label_2"));
    inputToLabel->setGeometry(QRect(20, 280, 55, 16));

    isInfix = new QRadioButton(widget);
    isInfix->setObjectName(QStringLiteral("isInfix"));
    isInfix->setGeometry(QRect(20, 120, 161, 20));
    isInfix->setChecked(true);

    isPostfix = new QRadioButton(widget);
    isPostfix->setObjectName(QStringLiteral("isPostfix"));
    isPostfix->setGeometry(QRect(20, 80, 161, 20));

    functionInput = new QLineEdit(widget);
    functionInput->setObjectName(QStringLiteral("lineEdit"));
    functionInput->setGeometry(QRect(20, 40, 201, 22));

    enterFormulaLabel = new QLabel(widget);
    enterFormulaLabel->setObjectName(QStringLiteral("enterFormulaLabel"));
    enterFormulaLabel->setGeometry(QRect(20, 20, 121, 16));
}

void Ui_SymCal::setupLayout(QMainWindow *SymCal)
{
    centralWidget = new QWidget(SymCal);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));

    gridLayoutWidget = new QWidget(centralWidget);
    gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
    gridLayoutWidget->setGeometry(QRect(10, 20, 601, 361));

    gridLayout = new QGridLayout(gridLayoutWidget);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    gridLayout->setContentsMargins(0, 0, 0, 0);

    widget = new QWidget(gridLayoutWidget);
    widget->setObjectName(QStringLiteral("gridLayout"));

    chart = new QChartView(widget);
    chart->setObjectName(QStringLiteral("chart"));
    chart->setGeometry(QRect(259, 9, 321, 181));

    tableWidget = new QTableWidget(widget);
    tableWidget->setObjectName(QStringLiteral("tableWidget"));
    tableWidget->setGeometry(QRect(260, 210, 321, 141));
    tableWidget->setColumnCount(2);
    tableWidget->setRowCount(100);
    QStringList labels;
    labels << "x" << "y";
    tableWidget->setHorizontalHeaderLabels(labels);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    gridLayout->addWidget(widget, 0, 0, 1, 1);

    exportButton = new QPushButton(widget);
    exportButton->setObjectName(QStringLiteral("exportButton"));
    exportButton->setGeometry(QRect(10, 310, 93, 28));

    SymCal->setCentralWidget(centralWidget);

    statusBar = new QStatusBar(SymCal);
    statusBar->setObjectName(QStringLiteral("statusBar"));
    SymCal->setStatusBar(statusBar);
}

void Ui_SymCal::setupUi(QMainWindow *SymCal)
{
    if (SymCal->objectName().isEmpty())
        SymCal->setObjectName(QStringLiteral("SymCal"));

    SymCal->resize(600, 410);

    setupLayout(SymCal);
    setupCalcArea();
    setupConvertArea();

    retranslateUi(SymCal);
}

void Ui_SymCal::retranslateUi(QMainWindow *SymCal)
{
    SymCal->setWindowTitle(QApplication::translate("SymCal", "SymCal", nullptr));

    calcButton->setText(QApplication::translate("SymCal", "Calculate", nullptr));

    inputFromLabel->setText(QApplication::translate("SymCal", "From:", nullptr));

    inputToLabel->setText(QApplication::translate("SymCal", "To:", nullptr));

    convertButton->setText(QApplication::translate("SymCal", "Convert", nullptr));

    exportButton->setText(QApplication::translate("SymCal", "Calc + Export", nullptr));

    isInfix->setText(QApplication::translate("SymCal", "Infix > Postfix", nullptr));

    isPostfix->setText(QApplication::translate("SymCal", "Postfix > Infix", nullptr));

    enterFormulaLabel->setText(QApplication::translate("SymCal", "Enter formula:", nullptr));
}

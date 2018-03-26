#include "ui_symcal.h"

void Ui_SymCal::setupUi(QMainWindow *SymCal)
{

    if (SymCal->objectName().isEmpty())
        SymCal->setObjectName(QStringLiteral("SymCal"));

    SymCal->resize(620, 495);

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
    widget->setObjectName(QStringLiteral("widget"));

    widget_2 = new QWidget(widget);
    widget_2->setObjectName(QStringLiteral("widget_2"));
    widget_2->setGeometry(QRect(259, 9, 321, 181));

    tableWidget = new QTableWidget(widget);
    tableWidget->setObjectName(QStringLiteral("tableWidget"));
    tableWidget->setGeometry(QRect(260, 210, 321, 141));

    pushButton = new QPushButton(widget);
    pushButton->setObjectName(QStringLiteral("pushButton"));
    pushButton->setGeometry(QRect(130, 310, 93, 28));

    label = new QLabel(widget);
    label->setObjectName(QStringLiteral("label"));
    label->setGeometry(QRect(20, 250, 55, 16));

    label_2 = new QLabel(widget);
    label_2->setObjectName(QStringLiteral("label_2"));
    label_2->setGeometry(QRect(20, 280, 55, 16));

    doubleSpinBox = new QDoubleSpinBox(widget);
    doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
    doubleSpinBox->setGeometry(QRect(110, 280, 62, 22));

    doubleSpinBox_2 = new QDoubleSpinBox(widget);
    doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
    doubleSpinBox_2->setGeometry(QRect(110, 250, 62, 22));

    pushButton_2 = new QPushButton(widget);
    pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
    pushButton_2->setGeometry(QRect(130, 150, 93, 28));

    radioButton = new QRadioButton(widget);
    radioButton->setObjectName(QStringLiteral("radioButton"));
    radioButton->setGeometry(QRect(20, 120, 161, 20));

    radioButton_2 = new QRadioButton(widget);
    radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
    radioButton_2->setGeometry(QRect(20, 80, 161, 20));

    lineEdit = new QLineEdit(widget);
    lineEdit->setObjectName(QStringLiteral("lineEdit"));
    lineEdit->setGeometry(QRect(20, 40, 201, 22));

    label_3 = new QLabel(widget);
    label_3->setObjectName(QStringLiteral("label_3"));
    label_3->setGeometry(QRect(20, 20, 121, 16));

    gridLayout->addWidget(widget, 0, 0, 1, 1);

    SymCal->setCentralWidget(centralWidget);

    menuBar = new QMenuBar(SymCal);
    menuBar->setObjectName(QStringLiteral("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 620, 26));

    menuSymCal = new QMenu(menuBar);
    menuSymCal->setObjectName(QStringLiteral("menuSymCal"));

    SymCal->setMenuBar(menuBar);

    mainToolBar = new QToolBar(SymCal);
    mainToolBar->setObjectName(QStringLiteral("mainToolBar"));

    SymCal->addToolBar(Qt::TopToolBarArea, mainToolBar);

    statusBar = new QStatusBar(SymCal);
    statusBar->setObjectName(QStringLiteral("statusBar"));

    SymCal->setStatusBar(statusBar);

    menuBar->addAction(menuSymCal->menuAction());

    retranslateUi(SymCal);

    QMetaObject::connectSlotsByName(SymCal);
}

void Ui_SymCal::retranslateUi(QMainWindow *SymCal)
{
    SymCal->setWindowTitle(QApplication::translate("SymCal", "SymCal", nullptr));

    pushButton->setText(QApplication::translate("SymCal", "Calculate", nullptr));

    label->setText(QApplication::translate("SymCal", "From:", nullptr));

    label_2->setText(QApplication::translate("SymCal", "To:", nullptr));

    pushButton_2->setText(QApplication::translate("SymCal", "Convert", nullptr));

    radioButton->setText(QApplication::translate("SymCal", "Standard > Suffix", nullptr));

    radioButton_2->setText(QApplication::translate("SymCal", "Suffix > Standard", nullptr));

    label_3->setText(QApplication::translate("SymCal", "Enter formula:", nullptr));

    menuSymCal->setTitle(QApplication::translate("SymCal", "SymCal", nullptr));
} // retranslateUi

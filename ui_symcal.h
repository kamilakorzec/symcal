#ifndef UI_SYMCAL_H
#define UI_SYMCAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QtCharts>

QT_BEGIN_NAMESPACE

/*
 * Class Ui_Symcal
 * aggregates all UI elements and their layout
 */
class Ui_SymCal
{
private:
    /*
     * Setup area responsible for calculations
     */
    void setupCalcArea();

    /*
     * Setup area responsible for function conversion
     */
    void setupConvertArea();

    /*
     * Setup general layout
     */
    void setupLayout(QMainWindow *SymCal);

public:
    /*
     * Qt widgets - parts of UI
     */
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QChartView *chart;
    QTableWidget *tableWidget;
    QPushButton *calcButton;
    QLabel *inputFromLabel;
    QLabel *inputToLabel;
    QDoubleSpinBox *calcFromInput;
    QDoubleSpinBox *calcToInput;
    QPushButton *convertButton;
    QPushButton *exportButton;
    QRadioButton *isPostfix;
    QRadioButton *isInfix;
    QLineEdit *functionInput;
    QLabel *enterFormulaLabel;
    QMenu *menuSymCal;
    QStatusBar *statusBar;

    /*
     * Aggregate function - setup the whole UI
     */
    void setupUi(QMainWindow *SymCal);

    /*
     * Set text labels in UI
     */
    void retranslateUi(QMainWindow *SymCal);
};

namespace Ui {
    class SymCal: public Ui_SymCal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYMCAL_H

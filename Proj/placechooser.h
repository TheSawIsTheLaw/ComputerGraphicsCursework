#ifndef PLACECHOOSER_H
#define PLACECHOOSER_H

#include <QDialog>

namespace Ui
{
class PlaceChooser;
}

class PlaceChooser : public QDialog
{
    Q_OBJECT

public:
    enum checkBox
    {
        XAXIS,
        YAXIS
    };

    enum stat
    {
        CANCEL,
        OK
    };

    explicit PlaceChooser(QWidget *parent = nullptr);
    ~PlaceChooser();

    void setXCell(int xCell_);
    int getXCell();

    void setYCell(int yCell_);
    int getYCell();

    double getModelLength();
    double getModelHeight();
    checkBox getDirection();

    stat status;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::PlaceChooser *ui;

    int xCell = -1;
    int yCell = -1;

    double modelLength = 0;
    double modelHeight = 0;

    checkBox direction;
};

#endif // PLACECHOOSER_H

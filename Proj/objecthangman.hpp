#ifndef OBJECTHANGMAN_HPP
#define OBJECTHANGMAN_HPP

#include <QDialog>
#include "objects.hpp"

namespace Ui {
class ObjectHangman;
}

class ObjectHangman : public QDialog
{
    Q_OBJECT

public:
    explicit ObjectHangman(CellScene *scene_, QWidget *parent = nullptr);
    ~ObjectHangman();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ObjectHangman *ui;

    int changeModel(int num);

    CellScene *scene;
};

#endif // OBJECTHANGMAN_HPP

#ifndef LISTAINGREDIENTES_H
#define LISTAINGREDIENTES_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class ListaIngredientes;
}

class ListaIngredientes : public QDialog
{
    Q_OBJECT

public:
    explicit ListaIngredientes(QWidget *parent = nullptr);
    ~ListaIngredientes();

private:
    Ui::ListaIngredientes *ui;
    QSqlQueryModel *model;

private slots:
    void handleNew();
    void handleVisualizar();

};

#endif // LISTAINGREDIENTES_H

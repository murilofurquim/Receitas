#ifndef LISTARECEITAS_H
#define LISTARECEITAS_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class ListaReceitas;
}

class ListaReceitas : public QDialog
{
    Q_OBJECT

public:
    explicit ListaReceitas(QWidget *parent = nullptr);
    ~ListaReceitas();

private:
    Ui::ListaReceitas *ui;
    QSqlQueryModel *model;

private slots:
    void handleNew();
    void handleVisualizar();
};

#endif // LISTARECEITAS_H

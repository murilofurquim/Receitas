#ifndef RECEITA_H
#define RECEITA_H

#include <QDialog>

namespace Ui {
class Receita;
}

class Receita : public QDialog
{
    Q_OBJECT

public:
    explicit Receita(QWidget *parent = nullptr);
    explicit Receita(QWidget *parent, int id);
    ~Receita();

private slots:
    void on_Receita_accepted();

private:
    Ui::Receita *ui;
    int id;
    void CarregarReceita(int id_receita);
};

#endif // RECEITA_H

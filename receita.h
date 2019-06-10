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
    ~Receita();

private slots:
    void on_Receita_accepted();

private:
    Ui::Receita *ui;
};

#endif // RECEITA_H

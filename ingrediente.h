#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include <QDialog>

namespace Ui {
class Ingrediente;
}

class Ingrediente : public QDialog
{
    Q_OBJECT

public:
    explicit Ingrediente(QWidget *parent = nullptr);
    explicit Ingrediente(QWidget *parent, int id);
    ~Ingrediente();

private slots:
    void on_Ingrediente_accepted();

private:
    Ui::Ingrediente *ui;
    int id;
    void carregar(int id_ingrediente);
};

#endif // INGREDIENTE_H

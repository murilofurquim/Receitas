#ifndef TELARECEITA_H
#define TELARECEITA_H

#include <QMainWindow>

namespace Ui {
class TelaReceita;
}

class TelaReceita : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaReceita(QWidget *parent = nullptr);
    explicit TelaReceita(QWidget *parent, int id);
    ~TelaReceita();

    int getId() const;
    void setId(int value);

    void CarregarReceita();

signals:
    void registroAlterado();

private slots:
    void on_actionSalvar_triggered();

private:
    Ui::TelaReceita *ui;
    int id;
    void salvarReceita();
};

#endif // TELARECEITA_H

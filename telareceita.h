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
    ~TelaReceita();

    int getId() const;
    void setId(int value);

private:
    Ui::TelaReceita *ui;
    int id;
};

#endif // TELARECEITA_H

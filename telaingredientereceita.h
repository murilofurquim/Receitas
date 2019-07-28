#ifndef TELAINGREDIENTERECEITA_H
#define TELAINGREDIENTERECEITA_H

#include <QWidget>
#include <QDebug>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlDatabase>

namespace Ui {
class TelaIngredienteReceita;
}

class TelaIngredienteReceita : public QWidget
{
    Q_OBJECT

public:
    explicit TelaIngredienteReceita(QWidget *parent = nullptr);
    ~TelaIngredienteReceita();

    int id_ingreidente() const;
    void setId_ingreidente(int id_ingreidente);

    QString unidade() const;
    void setUnidade(const QString &unidade);

    double quantidade() const;
    void setQuantidade(double quantidade);

private slots:
    void on_buttonBox_accepted();

signals:
    void aceitou();

private:
    Ui::TelaIngredienteReceita *ui;
    QSqlQueryModel *ingredienteModel;

    int m_id_ingreidente;
    QString m_unidade;
    double m_quantidade;
};

#endif // TELAINGREDIENTERECEITA_H

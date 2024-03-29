#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionIngredientes_triggered();

    void on_actionReceitas_triggered();

    void on_actionReceita_Novo_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

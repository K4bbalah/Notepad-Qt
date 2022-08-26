#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionSalvar_triggered();

    void on_actionLer_Arquivos_triggered();
    void on_actionSobre_Qt_triggered();
    void on_actionEscuro_triggered();
    void on_actionClaro_triggered();
    void on_actionSobre_Dev_triggered();
    void on_actionSair_triggered();
    void on_actionApagar_triggered();
    void on_actionSalvar_Como_triggered();
    void on_actionNovo_triggered();
    void on_actionCopiar_triggered();
    void on_actionColar_triggered();
    void on_actionDesfazer_triggered();
    void on_actionRefazer_triggered();
    void on_actionRecortar_triggered();
    void on_actionTipo_de_Fonte_triggered();
    void on_actionCor_da_Fonte_2_triggered();
};
#endif // MAINWINDOW_H

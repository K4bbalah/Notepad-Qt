#include <QFile>
#include <QTextStream>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>
#include <QColor>
#include <QFont>
#include <QFontDialog>
#include <QTextStream>
#include <QColorDialog>

QString local_arquivo="";
QString nome_arquivo="";
//Parte do codigo que salva os arquivos

void MainWindow::on_actionSalvar_triggered()
{

    QFile file(local_arquivo);
    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QString Filtro="Todos os Arquivos(*.*);;Arquivos de Texto(*.txt)";
        QString nome_arquivo=QFileDialog::getSaveFileName(this,"Salvar",QDir::homePath(),Filtro);
        QFile file(nome_arquivo);
        local_arquivo=nome_arquivo;
        if(!file.open(QFile::WriteOnly|QFile::Text)){
            QMessageBox::warning(this,"Erro","Arquivo não foi salvo!");
                }
        QTextStream saida(&file);
        QString texto=ui->textEdit->toPlainText();
        saida << texto;
        file.flush();
        file.close();
    }
    QTextStream saida(&file);
    QString texto=ui->textEdit->toPlainText();
    saida << texto;
    file.flush();
    file.close();

}
//Parte do codigo que ler os arquivos

void MainWindow::on_actionLer_Arquivos_triggered(){
    QString Filtro="Todos os Arquivos(*.*);;Arquivos de Texto(*.txt)";
    QString nome_arquivo=QFileDialog::getOpenFileName(this,"Abrir",QDir::homePath(),Filtro);
    QFile file(nome_arquivo);


    if(!file.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::warning(this,"Erro","Arquivo não foi encontrado!");
    return;}

        local_arquivo=nome_arquivo;
        QTextStream entrada1(&file);
        QString texto=entrada1.readAll();
        ui->textEdit->setPlainText(texto);
        file.close();

}
//apenas informações


void MainWindow::on_actionSobre_Qt_triggered(){

    QMessageBox::aboutQt(this,"sobre o qt");

}

//Tema escuro do progama
void MainWindow::on_actionEscuro_triggered()
{
    this->setStyleSheet("background-color:#666;color:#00ced1;selection-background-color:#fff");
    ui->textEdit->setStyleSheet("background-color:#000;color:#0f0");
}
//Tema claro
void MainWindow::on_actionClaro_triggered()
{
    this->setStyleSheet("background-color:#e9e9e9;color:#000;selection-background-color: rgb(6, 101, 255)");

    ui->textEdit->setStyleSheet("background-color:#fff;color:#000");
}
//apenas informações

void MainWindow::on_actionSobre_Dev_triggered(){

    QMessageBox::information(this,"Sobre o Dev","Apenas um Curioso!\n"
                                                "By Kabbalah!");

}
//Fechar o Progama

void MainWindow::on_actionSair_triggered(){


    this->close();
}
//Apgar Texto
void MainWindow::on_actionApagar_triggered(){


    ui->textEdit->clear();


}


void MainWindow::on_actionSalvar_Como_triggered()
{
    QString Filtro="Todos os Arquivos(*.*);;Arquivos de Texto(*.txt)";
    QString nome_arquivo=QFileDialog::getSaveFileName(this,"Salvar Como",QDir::homePath(),Filtro);
    QFile file(nome_arquivo);

    if(!file.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,"Erro","Arquivo não foi salvo!");
           return; }

        local_arquivo=nome_arquivo;
        QTextStream saida(&file);
        QString texto=ui->textEdit->toPlainText();
        saida << texto;
        file.flush();
        file.close();




}
void MainWindow::on_actionNovo_triggered()
{

    ui->textEdit->setFocus();
    ui->textEdit->clear();

}


void MainWindow::on_actionCopiar_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionColar_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionDesfazer_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRefazer_triggered()
{
      ui->textEdit->redo();
}


void MainWindow::on_actionRecortar_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionTipo_de_Fonte_triggered()
{
    bool fonte_check;
    QFont fonte=QFontDialog::getFont(&fonte_check,this);
    if (fonte_check){

        ui->textEdit->setFont(fonte);
    }else
        return;
}


void MainWindow::on_actionCor_da_Fonte_2_triggered()
{
    QColor color=QColorDialog::getColor(Qt::black,this,"Escolha uma Cor");
    ui->textEdit->setTextColor(color);
}


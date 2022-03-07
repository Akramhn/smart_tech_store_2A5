#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Personnel.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlRecord>
#include <QMessageBox>
#include <iostream>

using std::uint8_t;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{
    int cin;
        QString nom,prenom;
        cin=ui->lineEditCin->text().toInt();

        nom=ui->lineEdit_nom->text();
        prenom=ui->lineEdit_pren->text();
        ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

        Personnel P(cin,nom,prenom);


         bool test=P.addPersonnel();
         if(test)
         {
             ui->tableView->setModel(tmpPersonnel.afficherPersonnel());
             QMessageBox::critical(nullptr, QObject::tr("Ajout Validé"),
                         QObject::tr("ADD successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     }
         else
             QMessageBox::critical(nullptr, QObject::tr("Ajout not Validé"),
                         QObject::tr("ADD failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_afficher_clicked()
{
    ui->tableView->setModel(tmpPersonnel.afficherPersonnel());

}

void MainWindow::on_supprimer_clicked()
{
    int cin=ui->lineEditCin_supp->text().toInt();
        tmpPersonnel.removePersonnel(cin);


         bool test=tmpPersonnel.removePersonnel(cin);


        if(test)
        {

            ui->tableView->setModel(tmpPersonnel.afficherPersonnel());
            QMessageBox::critical(nullptr, QObject::tr("supprimer Validé"),
                        QObject::tr("DELETE successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("supprimer not Validé"),
                        QObject::tr("DELETE failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifier_clicked()
{
    int cin;
        QString nom,prenom;

        cin=ui->lineEditCin_modif->text().toInt();
        nom=ui->lineEdit_nom_modif->text();
        prenom=ui->lineEdit_pren_modif->text();

       tmpPersonnel.modifierPersonnel(nom,prenom,cin);
       Personnel P(cin,nom,prenom);


        bool test=P.modifierPersonnel(nom,prenom,cin);

         if(test)
         {
             ui->tableView->setModel(tmpPersonnel.afficherPersonnel());
             QMessageBox::critical(nullptr, QObject::tr("modifier Validé"),
                         QObject::tr("MODIF successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     }
         else
             QMessageBox::critical(nullptr, QObject::tr("modifier not Validé"),
                         QObject::tr("MODIF failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

}



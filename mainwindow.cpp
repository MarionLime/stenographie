#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connecte le bouton à la fonction de comparaison
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(compareAndDisplay()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::compareAndDisplay()
{
    // Défini les espaces ou les textes sont entrés
    QString text1 = ui->textEdit1->toPlainText();
    QString text2 = ui->textEdit2->toPlainText();

    // Permet de séparer les textes en mots
    QStringList text1Words = text1.split(QRegExp("\\W+"), QString::SkipEmptyParts);
    QStringList text2Words = text2.split(QRegExp("\\W+"), QString::SkipEmptyParts);

    // Initialise QStringList pour differencier les mots
    QStringList differentWords;

    // Boucle les mots du texte 1
    for (const QString &word : text1Words) {
        // Si les mots ne sont pas dans le texte 2, ajoute à une liste
        if (!text2Words.contains(word)) {
            differentWords.append(word);
        }
    }

    // Imprime les mots différents
    qDebug() << "Mot de passe: ";
    for (const QString &word : differentWords) {
        qDebug() << word;
    }

    // Affiche les mots différents dans l'interface
    ui->textBrowser->setText(differentWords.join(" "));
}

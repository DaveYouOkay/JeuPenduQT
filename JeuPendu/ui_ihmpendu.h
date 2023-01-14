/********************************************************************************
** Form generated from reading UI file 'ihmpendu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHMPENDU_H
#define UI_IHMPENDU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IHMPendu
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *JouerBut;
    QPushButton *ConfigBut;
    QLabel *JeuduPenduLabel;
    QLabel *FichierMots;
    QLabel *MotsDispo;
    QLineEdit *NameLine;
    QLabel *nomduJoueurLabel;
    QLabel *PhotoErreur;
    QLabel *MotaTrouverLabel;
    QLabel *MotCacher;
    QLabel *nombreErreur;
    QLabel *Result;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *IHMPendu)
    {
        if (IHMPendu->objectName().isEmpty())
            IHMPendu->setObjectName(QString::fromUtf8("IHMPendu"));
        IHMPendu->resize(700, 600);
        IHMPendu->setMinimumSize(QSize(700, 600));
        IHMPendu->setMaximumSize(QSize(700, 600));
        centralwidget = new QWidget(IHMPendu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 370, 611, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        JouerBut = new QPushButton(centralwidget);
        JouerBut->setObjectName(QString::fromUtf8("JouerBut"));
        JouerBut->setGeometry(QRect(520, 100, 111, 51));
        ConfigBut = new QPushButton(centralwidget);
        ConfigBut->setObjectName(QString::fromUtf8("ConfigBut"));
        ConfigBut->setGeometry(QRect(520, 160, 111, 25));
        JeuduPenduLabel = new QLabel(centralwidget);
        JeuduPenduLabel->setObjectName(QString::fromUtf8("JeuduPenduLabel"));
        JeuduPenduLabel->setGeometry(QRect(290, 30, 341, 51));
        QFont font;
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        JeuduPenduLabel->setFont(font);
        JeuduPenduLabel->setAlignment(Qt::AlignCenter);
        FichierMots = new QLabel(centralwidget);
        FichierMots->setObjectName(QString::fromUtf8("FichierMots"));
        FichierMots->setGeometry(QRect(40, 510, 451, 17));
        QFont font1;
        font1.setPointSize(10);
        FichierMots->setFont(font1);
        MotsDispo = new QLabel(centralwidget);
        MotsDispo->setObjectName(QString::fromUtf8("MotsDispo"));
        MotsDispo->setGeometry(QRect(496, 510, 171, 20));
        NameLine = new QLineEdit(centralwidget);
        NameLine->setObjectName(QString::fromUtf8("NameLine"));
        NameLine->setGeometry(QRect(270, 110, 151, 31));
        nomduJoueurLabel = new QLabel(centralwidget);
        nomduJoueurLabel->setObjectName(QString::fromUtf8("nomduJoueurLabel"));
        nomduJoueurLabel->setGeometry(QRect(270, 90, 131, 17));
        PhotoErreur = new QLabel(centralwidget);
        PhotoErreur->setObjectName(QString::fromUtf8("PhotoErreur"));
        PhotoErreur->setGeometry(QRect(40, 40, 201, 301));
        PhotoErreur->setFrameShape(QFrame::Box);
        MotaTrouverLabel = new QLabel(centralwidget);
        MotaTrouverLabel->setObjectName(QString::fromUtf8("MotaTrouverLabel"));
        MotaTrouverLabel->setGeometry(QRect(270, 200, 101, 21));
        MotCacher = new QLabel(centralwidget);
        MotCacher->setObjectName(QString::fromUtf8("MotCacher"));
        MotCacher->setEnabled(true);
        MotCacher->setGeometry(QRect(270, 230, 381, 61));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        MotCacher->setFont(font2);
        MotCacher->setFrameShape(QFrame::Box);
        nombreErreur = new QLabel(centralwidget);
        nombreErreur->setObjectName(QString::fromUtf8("nombreErreur"));
        nombreErreur->setGeometry(QRect(40, 340, 201, 21));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        nombreErreur->setFont(font3);
        Result = new QLabel(centralwidget);
        Result->setObjectName(QString::fromUtf8("Result"));
        Result->setGeometry(QRect(270, 300, 381, 41));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        Result->setFont(font4);
        IHMPendu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(IHMPendu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        IHMPendu->setStatusBar(statusbar);

        retranslateUi(IHMPendu);

        QMetaObject::connectSlotsByName(IHMPendu);
    } // setupUi

    void retranslateUi(QMainWindow *IHMPendu)
    {
        IHMPendu->setWindowTitle(QApplication::translate("IHMPendu", "Jeu du pendu", nullptr));
        JouerBut->setText(QApplication::translate("IHMPendu", "JOUER", nullptr));
        ConfigBut->setText(QApplication::translate("IHMPendu", "Config.", nullptr));
        JeuduPenduLabel->setText(QApplication::translate("IHMPendu", "Jeu du pendu", nullptr));
        FichierMots->setText(QApplication::translate("IHMPendu", "Fichier de mots :", nullptr));
        MotsDispo->setText(QApplication::translate("IHMPendu", "Mots disponible:", nullptr));
        nomduJoueurLabel->setText(QApplication::translate("IHMPendu", "Nom du joueur :", nullptr));
        MotaTrouverLabel->setText(QApplication::translate("IHMPendu", "Mot \303\240 trouver :", nullptr));
        MotCacher->setText(QString());
        nombreErreur->setText(QApplication::translate("IHMPendu", "Erreur", nullptr));
        Result->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class IHMPendu: public Ui_IHMPendu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHMPENDU_H

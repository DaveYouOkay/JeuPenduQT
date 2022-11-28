#include "ihmpendu.h"
#include "ui_ihmpendu.h"
#include "CUJeuPendu.h"
#include <QFile>
#include <QMessageBox>
#include <QSignalMapper>

//const QString signature = "Jeu du pendu"; //le nom du programme

IHMPendu::IHMPendu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IHMPendu)
{
    ui->setupUi(this);

    afficherPendu(0);
    ui->nombreErreur->hide();
}

IHMPendu::~IHMPendu()
{
    delete ui;
}

void IHMPendu::initHMDebutJeu()
{
    //BoutonJouerOnOff(false);
    addJeuPendu->updateWordsFiles();
    afficherNomFichierMots(addJeuPendu->getWordsFile());
    afficherNombreDeMots(addJeuPendu->getWordsNumber());
    afficherPendu(0);
    ui->nombreErreur->show();
}

void IHMPendu::RecupAddJeu(CUJeuPendu *uneAddJeu)
{
    addJeuPendu = uneAddJeu;
}
void IHMPendu::RecupAddFenetreConfig(QWidget *uneAddFenetre)
{
    addFenetreConfig = uneAddFenetre;
}
void IHMPendu::RecupAddLineEdit(QLineEdit *uneAddLine)
{
    addLineEdit = uneAddLine;
}

void IHMPendu::LabelMotATrouverVisible(bool active)
{
    if(active == true)
    {   ui->MotaTrouverLabel->show();   }
    else
    {   ui->MotaTrouverLabel->hide();   }
}

void IHMPendu::BoutonJouerOnOff(bool active)
{
    if(active == true)
    {   ui->JouerBut->setEnabled(true);     }
    else
    {   ui->JouerBut->setDisabled(true);    }
}

void IHMPendu::BoutonConfigOnOff(bool active)
{
    if(active == true)
    {   ui->ConfigBut->setEnabled(true);    }
    else
    {   ui->ConfigBut->setDisabled(true);   }
}

void IHMPendu::NomOnOff(bool active)
{
    if(active == true)
    {   ui->nomduJoueurLabel->setEnabled(true);     }
    else
    {   ui->nomduJoueurLabel->setDisabled(true);    }
}

void IHMPendu::afficher(QString mess)
{
    ui->MotCacher->setText(mess);
    ui->MotCacher->show();
}

void IHMPendu::afficherPendu(int etapeP)
{
    ui->PhotoErreur->setPixmap(QPixmap("Ressource/ImagePendu"+QString::number(etapeP)+".png"));
    if(etapeP!=0)
    {
        ui->nombreErreur->setText(QString::number(etapeP) + " Erreur");
    }
    else
    {
        ui->nombreErreur->setText("Aucune erreur");
    }
}

void IHMPendu::afficherNomFichierMots(QString nomFichierM)
{
    ui->FichierMots->setText("Fichier de mots : " + nomFichierM);
}

void IHMPendu::afficherNombreDeMots(int nbmots)
{
    ui->MotsDispo->setText("Mots disponible: " + QString::number(nbmots));
}

QString IHMPendu::saisirNom()
{
    QString name;


    return name;
}

void IHMPendu::on_ConfigBut_clicked()
{
    QWidget* configWindow = new QWidget();
    configWindow->setFixedWidth(600);
    configWindow->setFixedHeight(400);
    configWindow->setWindowTitle("Configuration");
    configWindow->show();

    QLayout* layoutConfig = new QGridLayout(configWindow);
    layoutConfig[0].setGeometry(QRect(0,0,600,400));
    layoutConfig->setContentsMargins(0,0,0,0);

    QLabel* labelConfig = new QLabel(configWindow);

    //font
    QFont fontConfig;
    fontConfig.setPointSize(16);
    fontConfig.setBold(true);

    //labelConfig
    labelConfig[0].setText("Saisir le nom du fichier contenant les mots :");
    labelConfig[0].setFont(fontConfig);
    layoutConfig->addWidget(&labelConfig[0]);
    //layoutConfig->setAlignment(&labelConfig[0],)

    labelConfig[0].show();

    QLineEdit* lineEditConfig = new QLineEdit(configWindow);
    lineEditConfig[0].setGeometry(100,300,150,30);
    lineEditConfig[0].show();
    //layoutConfig[0].addWidget(labelConfig);


}

void IHMPendu::on_JouerBut_clicked()
{
    initHMDebutJeu();
    BoutonConfigOnOff(false);
    //BoutonJouerOnOff(false);
    NomOnOff(false);

    addJeuPendu->startGame();
    slotBouton();
    ui->MotCacher->setText(addJeuPendu->getWordSelect());

}

void IHMPendu::boutonclic()
{
    QPushButton* button = (QPushButton*)sender();
    QChar letterclick = button->text()[0];
    QString word=addJeuPendu->getWordSelect();
    word = word.toUpper();

    for(int pt=0;pt<word.size();pt++)
    {
        for (int alpha=65;alpha<90;alpha++)
        {

            if(letterclick==word[alpha].toUpper())
            {
                ui->MotCacher->setText("GG");
            }
            else
            {
                ui->MotCacher->setText("LL");
            }
        }
    }
}

void IHMPendu::slotBouton()
{
    int alpha=65;
    QSignalMapper *signalMapper = new QSignalMapper(this);
    for (int i=0;i<26;i++)
    {
        Bouton[i]=new QPushButton (QString(alpha++));
        Bouton[i]->setMinimumWidth(5);
        Bouton[i]->setMinimumHeight(5);

        ui->gridLayout->addWidget(Bouton[i],i/10,i%10);
        signalMapper->setMapping(Bouton[i],i);
        QObject::connect(Bouton[i], SIGNAL(clicked()), this, SLOT(boutonclic()));
    }
    //https://www.siloged.fr/cours/QTCreator/Evenements.html
    //https://www.siloged.fr/cours/QTCreator/Damierabasedeboutons.html
}


void IHMPendu::slotBoutonActualiser()
{

}
void IHMPendu::slotBoutonParcourir()
{

}
void IHMPendu::slotBoutonAnnuler()
{

}


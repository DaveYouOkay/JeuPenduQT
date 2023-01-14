#include "ihmpendu.h"
#include "ui_ihmpendu.h"
#include "CUJeuPendu.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QSignalMapper>
#include <time.h>
#include <QFileDialog>
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

void IHMPendu::initHMDebutJeu() //initialise le jeu
{
    //BoutonJouerOnOff(false);
    addJeuPendu->updateWordsFiles();
    afficherNomFichierMots(addJeuPendu->getWordsFile());
    afficherNombreDeMots(addJeuPendu->getWordsNumber());
    afficherPendu(0);
    ui->Result->hide();
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
    {   ui->NameLine->setEnabled(true);     }
    else
    {   ui->NameLine->setDisabled(true);    }
}

void IHMPendu::afficher(QString mess)  // affiche des espace pour facilité la lecture du nombre de tiret donc de lettre a trouvé pour le joueur
{
    QString messEspace;
    for(int pt=0;pt<mess.size();pt++)
    {
        messEspace+=(mess[pt]+" ");
    }
    ui->MotCacher->setText(messEspace);
    ui->MotCacher->show();
}

void IHMPendu::afficherPendu(int etapeP) // affiche l'image du pendu et son evolution
{
    ui->PhotoErreur->setPixmap(QPixmap("Ressource/ImagePendu"+QString::number(etapeP)+".png"));

    if(etapeP!=0){
        ui->nombreErreur->setText(QString::number(etapeP) + " Erreur");
    }
    else{
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

void IHMPendu::afficherResult(QString leResult,int vict) //affiche le resultat
{
    if(vict==1)
    {
        ui->Result->setText("Victoire ! \nVous avez trouver le mot en "+ QString::number(addJeuPendu->getErrorNb())+" erreurs !");
    }
    if(vict==0)
    {
        ui->Result->setText("Echec ! Le mot etait " + leResult + " !");
    }
}


QString IHMPendu::saisirNom() //Détecte que le joueur à mis son nom, si non affiche une fenetre d'erreur
{
    QString name;
    if(ui->NameLine->text().isEmpty()==false)
    {
        name = ui->NameLine->text();
    }
    else // fenetre d'erreur
    {
        QMessageBox msgBox; QString x;
        msgBox.setIcon(QMessageBox::Information);
        x="Le nom du joueur n'est pas rentré !";
        msgBox.setText(x);
        msgBox.exec();
    }
    return name;
}

void IHMPendu::on_ConfigBut_clicked() // créer une fenetre dynamique pour modifier le fichier de mots
{
    QWidget* configWindow = new QWidget();

    configWindow->setFixedWidth(600);
    configWindow->setFixedHeight(400);
    configWindow->setWindowTitle("Configuration");
    configWindow->show();

    QLabel* labelConfig1 = new QLabel(configWindow);
    QLabel* labelConfig2 = new QLabel(configWindow);
    QLabel* labelConfig3 = new QLabel(configWindow);
    //font
    QFont fontConfig,fontLabel1,fontLabel2;
    fontConfig.setPointSize(16);
    fontConfig.setBold(true);
    fontLabel1.setPointSize(13);
    fontLabel2.setPointSize(10);
    //fontLabel.setBold(true);

    //labelConfig
    labelConfig1->setText("Saisir le nom du fichier contenant les mots :");
    labelConfig1->setFont(fontConfig);
    labelConfig1->setGeometry(80,10,500,75);
    labelConfig1->show();

    labelConfig2->setText("/Ressource/");
    labelConfig2->setFont(fontLabel1);
    labelConfig2->setGeometry(100,100,100,50);
    labelConfig2->show();

    labelConfig3->setText("Le fichier choisit est : "+ addJeuPendu->getWordsFile());
    labelConfig3->setFont(fontLabel2);
    labelConfig3->setGeometry(50,200,500,50);
    labelConfig3->show();

    QLineEdit* lineEditConfig = new QLineEdit(configWindow);
    lineEditConfig->setGeometry(200,100,200,50);
    lineEditConfig->show();
    lineEditConfig->connect(lineEditConfig, SIGNAL(returnPressed()), this, SLOT(slotBoutonParcourir()));


    QPushButton* buttonConfig1 = new QPushButton(configWindow);
    QPushButton* buttonConfig2 = new QPushButton(configWindow);
    QPushButton* buttonConfig3 = new QPushButton(configWindow);

    buttonConfig1->setGeometry(400,100,100,50);
    buttonConfig1->setText("Parcourir");
    buttonConfig1->show();
    buttonConfig1->connect(buttonConfig1, SIGNAL(clicked()), this, SLOT(slotBoutonParcourir()));

    buttonConfig2->setGeometry(220,300,75,50);
    buttonConfig2->setText("OK");
    buttonConfig2->show();
    buttonConfig2->connect(buttonConfig2, SIGNAL(clicked()), this, SLOT(slotBoutonActualiser()));

    buttonConfig3->setGeometry(305,300,75,50);
    buttonConfig3->setText("Annuler");
    buttonConfig3->show();
    buttonConfig3->connect(buttonConfig3, SIGNAL(clicked()), this, SLOT(slotBoutonAnnuler()));

    IHMPendu::hide();


    RecupAddFenetreConfig(configWindow);
}

void IHMPendu::on_JouerBut_clicked()
{
    if(ui->NameLine->text().isEmpty()==true)
    {
        saisirNom();
    }else
    {
        BoutonConfigOnOff(false);
        BoutonJouerOnOff(false);
        NomOnOff(false);

        addJeuPendu->startGame();
        initHMDebutJeu();
        slotBouton();
        afficherPendu(addJeuPendu->getErrorNb());
        ui->MotCacher->hide();
    }
}

void IHMPendu::boutonclic() //Détecte le boutins qui vient d'etre cliqué et fais une comparaison avec les lettres du mot
{
    QPushButton* button = (QPushButton*)sender();
    QChar letterclick = button->text()[0]; //Le bouton a un QString donc compare la premier lettre de la chaine de caractere
    QString wordS = addJeuPendu->getWordSelect(),
            wordP = addJeuPendu->getWordPlay(),
            mess;
    int flag=0,nberror = addJeuPendu->getErrorNb();
    bool finish=false;

    for(int pt=0;pt<wordS.size();pt++)
    {
        if(wordS[pt]==letterclick)
        {
            flag=1;
            button->setEnabled(false);
            button->setStyleSheet("background-color: limegreen;"
                                  "color: black;");
            button->update();

            wordP[pt] = letterclick; //remplacer la pt ième lettre du mot par la lettre cliquée

            addJeuPendu->setWordPlay(wordP);
            afficher(wordP);
        }
        else
        {
            button->setEnabled(false);
        }
    }

    if(flag==0) //détecte que la lettre n'est pas dans le mot
    {
        nberror=nberror+1;
        addJeuPendu->setErrorNb(nberror);
        afficherPendu(nberror);
        button->setStyleSheet("background-color: darkred;"
                              "color: black;");
    }

    //----A GAGNE----//
    if(wordP.contains('_',Qt::CaseSensitivity())==false) //Detecte la présence de tirée et si il n'y en a pas alors détécte la gagne
    {
        mess=ui->NameLine->text() + " Vous avez Gagné !!";
        finish=true;
        afficherResult(wordS,1);
    }

    //----A PERDU----//
    if(nberror == 10) //Dépassé le nombre de 10 erreur le joueur a perdu
    {
        mess=ui->NameLine->text() + " Vous avez perdu !!";
        finish=true;
        afficherResult(wordS,0);
        afficherPendu(10);
    }

    if(finish==true) // lorsque la partie est finis réinitialise la partie pour pouvoir rejouer
    {
        ui->JouerBut->setText("REJOUER");
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText(mess);
        msgBox.exec();
        BoutonConfigOnOff(true);
        BoutonJouerOnOff(true);
        NomOnOff(true);
        ui->Result->show();
        for(int ptd=0;ptd<26;ptd++)
        {
            Bouton[ptd]->setDisabled(true);
            Bouton[ptd]->setStyleSheet("background-color: none;"
                                       "color: grey;");
        }
    }
}

void IHMPendu::slotBouton() //Créer des boutons dynamiquement et leur attrinut un signal si cliquer
{
    int alpha=65;
    QSignalMapper *signalMapper = new QSignalMapper(this);
    for (int pt=0;pt<26;pt++)
    {
        Bouton[pt]= new QPushButton (QString(alpha++));
        Bouton[pt]->setMinimumWidth(5);
        Bouton[pt]->setMinimumHeight(5);

        ui->gridLayout->addWidget(Bouton[pt],pt/10,pt%10); // Met les boutons dans un Layout pour qu'ils soit bien mit
        signalMapper->setMapping(Bouton[pt],pt);
        QObject::connect(Bouton[pt], SIGNAL(clicked()), this, SLOT(boutonclic()));
    }
    //https://www.siloged.fr/cours/QTCreator/Evenements.html
    //https://www.siloged.fr/cours/QTCreator/Damierabasedeboutons.html
}

void IHMPendu::slotBoutonActualiser() //Détecte le changement de fichier de mots
{
    addJeuPendu->updateWordsFiles();
    IHMPendu::show();
    addFenetreConfig->close();

}
void IHMPendu::slotBoutonParcourir() //Permet de créer une fenetre pour parcourir les fichier de l'utilisateur et de le selectionner
{
    QString fichierSelectConfig = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", "FichierDeMots",
            "Fichier Text (*.txt);;Autre (*.*)");

    //ui->NameLine->setText(fichierSelectConfig);
    QFile configFile("Ressource/config.txt");
    configFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    QTextStream configTextF(&configFile);

    configTextF << fichierSelectConfig;
}

void IHMPendu::slotBoutonAnnuler() // ferme la fenetre config et réaffiche la fenetre de base
{
    IHMPendu::show();
    addFenetreConfig->close();
}




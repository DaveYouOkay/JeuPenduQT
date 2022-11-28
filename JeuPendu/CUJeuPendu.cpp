#include "CUJeuPendu.h"
#include "ihmpendu.h"
#include "qfile.h"
#include "qtextstream.h"


CUJeuPendu::CUJeuPendu()
{
    updateWordsFiles();
    findWordsNumber();
}

CUJeuPendu::~CUJeuPendu() { }

void CUJeuPendu::RecupAddIHM(IHMPendu* uneAddIHM)
{    addIHMPendu = uneAddIHM;   }

QString CUJeuPendu::getWordsFile() //get unFichierDeMots
{   return wordsFileName;   }
void CUJeuPendu::setWordsFile(QString aWordsFile) //set unFichierDeMots
{   wordsFileName = aWordsFile;     }

int CUJeuPendu::getErrorNb() //get Nombres d'Erreur
{    return errorNumber;     }

void CUJeuPendu::setErrorNb(int errorNb) //set Nombres d'Erreur
{    errorNumber = errorNb;     }

QString CUJeuPendu::getWordPlay() //get MotEnCours
{   return wordPlay;    }

void CUJeuPendu::setWordPlay(QString aWordPlay) //set MotEnCours
{    wordPlay = aWordPlay;  }

QString CUJeuPendu::getWordSelect() //get MotChois
{    return wordSelect;     }


int CUJeuPendu::randomDraw(int min, int max)  // Tirage aléatoire du mots à trouver
{
    int randomNumber;
    srand(time(NULL));
    randomNumber = rand() % max - min + 1;
    return randomNumber;

}

void CUJeuPendu::updateWordsFiles()  //mettre à jour le fichier de mots
{
    QFile configFile("Ressource/config.txt");
    configFile.open(QIODevice::ReadOnly);
    QTextStream config(&configFile);
    wordsFileName = "Ressource/" + config.readLine();

    configFile.close();
}

QString CUJeuPendu::readWord(int randomnumber)  //lire le mots aleatoire trouver
{
    QFile WordsFile(wordsFileName);
    WordsFile.open(QIODevice::ReadOnly);
    QTextStream WordTextFile(&WordsFile);
    QString word;

    for(int pt=0;pt<randomnumber;pt++)
    {
        word = WordTextFile.readLine(randomnumber);
    }
    wordSelect=word;

    return word;
}

int CUJeuPendu::getWordsNumber()
{
    return wordsNumber;
}

void CUJeuPendu::findWordsNumber()
{
    QFile WordsFile(wordsFileName);
    WordsFile.open(QIODevice::ReadOnly);
    QTextStream WordTextFile(&WordsFile);

    int ptr=0;
    while(WordTextFile.readLine() != "")
    {
        ptr++;
    }
    wordsNumber = ptr;
    WordsFile.close();
}

void CUJeuPendu::startGame()
{
    int r;
    playerName = addIHMPendu->saisirNom();
    r=randomDraw(0,wordsNumber);
    readWord(r);



}





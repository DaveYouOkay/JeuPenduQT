#include "CUJeuPendu.h"
#include "ihmpendu.h"
#include "qfile.h"
#include "qtextstream.h"
#include <random>

CUJeuPendu::CUJeuPendu()
{
    srand(time(NULL));
    updateWordsFiles();

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

    int randomNumber,reinit;
    reinit = rand() % (100-1)+1;

    //std::random_device dev;
    //https://www.reddit.com/r/Cplusplus/comments/wilcxu/srand_function_not_working/
    std::mt19937 rng(reinit);
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max); // distribution in range [1, 6]
    randomNumber = dist6(rng);

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
    int pt=0;
    while(pt<randomnumber)
    {
        word = WordsFile.readLine();
        pt++;
    }

    for(int ptr=0;ptr<word.size();ptr++)
    {
        word[ptr] = word[ptr].toUpper();
    }

    WordsFile.close();
    wordSelect = word;

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

    playerName = addIHMPendu->saisirNom();
    findWordsNumber();
    errorNumber = randomDraw(1,wordsNumber);
    readWord(errorNumber);



    for(int i=0;i<(wordSelect.size());i++)
    {
        wordPlay = wordPlay + "_";
    }
}





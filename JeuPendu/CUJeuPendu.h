#ifndef CUJEUPENDU_H
#define CUJEUPENDU_H
#include <QString>


class CUJeuPendu
{
private:
    QString playerName;
    QString wordsFileName;
    int wordsNumber;
    QString wordSelect;
    QString wordPlay;
    int errorNumber;
    class IHMPendu* addIHMPendu;

public:
    CUJeuPendu();
    ~CUJeuPendu();
    void RecupAddIHM(IHMPendu* uneAddIHM);
    QString getWordsFile();
    void setWordsFile(QString aWordsFile);
    int getErrorNb();
    void setErrorNb(int errorNb);
    QString getWordPlay();
    void setWordPlay(QString aWordPlay);
    QString getWordSelect();
    int randomDraw(int min, int max);
    void updateWordsFiles();
    QString readWord(int rdnb);
    void startGame();
    int getWordsNumber();
    void findWordsNumber();
};


#endif // CUJEUPENDU_H

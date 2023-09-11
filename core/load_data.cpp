#include "load_data.h"
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>
#include <QDebug>

WordDataSet::WordDataSet()
{
    _loadWords();
}

void WordDataSet::_loadWords()
{
    // Load valid answer: explicitly using a list to store
    QString filePath = ":/valid_answer.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        error_code = 1;
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) 
    {
        QString word = in.readLine().trimmed();
        if (!word.isEmpty() && word.length() == 5) 
        {
            validAnswerList.append(word);
        }
    }
    file.close();

    // Load valid word: using 32 hash buckets to store
    // Every bucket contains trimmed words with letters at certain positions
    // In game, the remained positions correspond to the positions of 
    // already-known must-include letters (letters in green)
    filePath = ":/valid_word.txt";
    for (int i = 0; i < 32; i++)
    {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
        {
            error_code = 1;
            return;
        }
        QTextStream in(&file);
        while (!in.atEnd()) 
        {
            QString word = in.readLine().trimmed();
            if (!word.isEmpty() && word.length() == 5) 
            {
                QString word_trimmed = "";
                for (int j = 0; j < 5; j++)
                    if (((i >> (4-j)) & 1) == 1)
                        word_trimmed += word[j];
                validWordBucket[i].insert(word_trimmed, word);
            }
        }
        file.close();
    }
}

QString WordDataSet::generateRandomAnswer()
{
    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    int index = generator.bounded(validAnswerList.length());
    return validAnswerList[index];
}


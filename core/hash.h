#ifndef HASH_H
#define HASH_H

#include <QTextStream>
#include <QString>
#include <QFile>
#include <QHash>
#include <QDir>
#include <QTime>
#include <QRandomGenerator>
#include <QDebug>

class WordSet 
{
public:
    WordSet() 
    {
        loadWords();
        getAnswer();
    }

    bool isValid(const QString& word) const 
    {
        return wordHash.contains(word);
    }

    QString ans_word;
    int error_code = 0;

private:
    QHash<QString, bool> wordHash;

    void loadWords()
    {
//        QString filePath = QDir::currentPath() + "/../src/valid_word.txt";
        QString filePath = ":/valid_word.txt";
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
                wordHash.insert(word, true);
            }
        }
        file.close();
    }

    void getAnswer()
    {
        QRandomGenerator generator = QRandomGenerator::securelySeeded();
        int line = generator.bounded(1, 2310);

        QString filePath = ":/valid_answer.txt";
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) 
        {
            error_code = 1;
            return;
        }
        QTextStream in(&file);
        int cur_line = 0;
        while (!in.atEnd()) 
        {
            QString word = in.readLine().trimmed();
            cur_line++;
            if (cur_line == line) 
            {
                ans_word = word;
                break;
            }
        }
        file.close();
    }
};

#endif // HASH_H

#ifndef HASH_H
#define HASH_H

#include <QTextStream>
#include <QString>
#include <QFile>
#include <QHash>
#include <QDir>

class WordSet 
{
public:
    WordSet() 
    {
        loadWords();
    }

    bool isValid(const QString& word) const 
    {
        return wordHash.contains(word);
    }

    int error_code = 0;

private:
    QHash<QString, bool> wordHash;

    void loadWords()
    {
        QString filePath = QDir::currentPath() + "/src/valid_word.txt";
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            error_code = 1;
            return;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString word = in.readLine().trimmed();
            if (!word.isEmpty() && word.length() == 5) {
                wordHash.insert(word, true);
            }
        }
        file.close();
    }
};

#endif // HASH_H

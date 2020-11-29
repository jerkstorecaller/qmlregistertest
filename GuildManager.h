#ifndef GUILDMANAGER_H
#define GUILDMANAGER_H

#include <QObject>
#include <QtQml>
#include <QList>

#include "Adventurer.h"

class GuildManager : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(QList<Adventurer*> adventurers READ adventurers NOTIFY adventurersChanged)


public:
    explicit GuildManager(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE void addAdventurer(QString name) {
        auto newguy = new Adventurer(name);
        m_adventurers.append(newguy);
    }
    Q_INVOKABLE void removeAdventurer(QString name) {
        QMutableListIterator<Adventurer*> i(m_adventurers);
        while (i.hasNext()) {
            auto current = i.next();
            if (current->name() == name) {
                i.remove();
                current->deleteLater();
                emit adventurersChanged(m_adventurers);
                return;
            }
        }
    }

    QList<Adventurer*> adventurers() const
    {
        return m_adventurers;
    }

signals:
    void adventurersChanged(QList<Adventurer*> adventurers);

private:
    QList<Adventurer*> m_adventurers;
};

#endif // GUILDMANAGER_H

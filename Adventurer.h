#ifndef ADVENTURER_H
#define ADVENTURER_H

#include <QObject>
#include <QtQml>
#include <QDebug>

class Adventurer : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(QString currentTask READ currentTask NOTIFY currentTaskChanged)

public:
    explicit Adventurer(QString name, QObject *parent = nullptr) : QObject(parent), m_name(name)
    {
    }

    Q_INVOKABLE void startQuesting() {
        setTask("questing");
    }

    Q_INVOKABLE void startTrading() {
        setTask("trading");
    }

    QString name() const
    {
        return m_name;
    }

    QString currentTask() const
    {
        return m_currentTask;
    }

public slots:

signals:
    void currentTaskChanged(QString currentTask);

private:
    void setTask(QString task) {
        if (task != m_currentTask) {
            m_currentTask = task;
            emit currentTaskChanged(m_currentTask);
            qDebug() << "Message from C++:" << m_name << "'s task is now" << m_currentTask;
        }
    }

private:
    QString m_name;
    QString m_currentTask;
};

#endif // ADVENTURER_H

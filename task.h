#ifndef Task_H
#define Task_H
#include <QString>
#include <qtextstream>
class Task {
public:
    friend QTextStream& operator<<(QTextStream& output, const Task& p);
    friend QTextStream& operator>>(QTextStream& input, Task& p);
    Task();
    Task(const Task&);
    Task(int,QString,int);
    Task& operator=(const Task &rhs);
	bool operator<(const Task &rhs) const;
    const int getId();
    void setId(int);
    const QString getName() const;
    void setName(QString);
    const int getHours();
    void setHours(int);
    ~Task();
    bool isValid();
private:
    int id;
    QString name;
    int hours;
    };

#endif
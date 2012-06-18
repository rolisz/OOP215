#include "task.h"
        
Task::Task() { } 
Task::Task(int id,QString name,int hours):id(id),name(name),hours(hours) { }
Task::Task(const Task &other) {
    id = other.id;
    name = other.name;
    hours = other.hours;
}
Task& Task::operator=(const Task &other) {
    if (this != &other) { 
           id = other.id;
           name = other.name;
           hours = other.hours;
    }
    return *this; 
}

bool Task::operator<(const Task &rhs) const {
	return this->name < rhs.name;
}
const int Task::getId() { return this->id; }
void Task::setId(int id) { this->id=id; }
const QString Task::getName() const { return this->name; }
void Task::setName(QString name) { this->name=name; }
const int Task::getHours() { return this->hours; }
void Task::setHours(int hours) { this->hours=hours; }
bool Task::isValid() {
	return id > 0 && name != "" && hours > 0;
}
QTextStream& operator<<(QTextStream& output, const Task& p) {
   output<<p.id<<endl<<p.name<<endl<<p.hours<<endl;
   return output;
}
QTextStream& operator>>(QTextStream& input, Task & p) { 
    p.id = input.readLine().toInt();
    p.name = input.readLine();
    p.hours = input.readLine().toInt();
    return input;
} 
Task::~Task(void) {

}    
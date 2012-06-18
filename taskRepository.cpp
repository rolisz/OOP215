#include "taskRepository.h"

class repoException: public exception
{
  virtual const char* what() const throw()
  {
    return "Invalid task!";
  }
} repoEx;
taskRepository::taskRepository() {
	QFile fisier("tasks.txt");
	
	if (!fisier.open(QIODevice::ReadOnly) ) 
		throw QString("Eroare la citirea fisierului");

	QTextStream in(&fisier);
	
	while (!in.atEnd()) {
		Task t;
		in>>t;
		if (t.isValid()) {
			if (t.getId() >= newId) {
				newId = t.getId() +1;
			}
			tasks.append(t);
		}
	}
}

int taskRepository::getNewId() {
	return newId;
}

QVector<Task> taskRepository::getList() {
	qSort(tasks);
	return tasks;
}

void taskRepository::addTask(Task t) {
	if (! t.isValid()) {
		throw repoEx;
	}
	for (QVector<Task>::iterator it = tasks.begin(); it != tasks.end(); it++) {
		if ((*it).getId() == t.getId() ) {
			throw repoEx;
		}
	}
	tasks.push_back(t);
	newId++;
	QFile fisier("tasks.txt");
	
	if (!fisier.open(QIODevice::WriteOnly) ) 
		throw QString("Eroare la citirea fisierului");

	QTextStream out(&fisier);
	
	for (QVector<Task>::iterator it = tasks.begin(); it != tasks.end(); it++) {
		out<<*it;
	}
}

Task taskRepository::getNr(int nr) {
	return tasks[nr];
}
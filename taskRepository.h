#ifndef taskRepo_H
#define taskRepo_H

#include "task.h"
#include <qvector.h>
#include <QFile>
#include <exception>
#include "helper.h"
#include <qalgorithms.h>
using namespace::std;
class repoException;

class taskRepository {
private: 
	QVector<Task> tasks;
	int newId;

public:
	taskRepository();
	int getNewId();
	void addTask(Task t);
	QVector<Task> getList();
	Task getNr(int nr);
};

#endif
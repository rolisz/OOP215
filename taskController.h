#ifndef CONTR_H
#define CONTR_H

#include "taskRepository.h"

class TaskController {
private:
	taskRepository* repo;
public:
	TaskController(taskRepository*);
	QVector<Task> getList();
	void addTask(QString, int);
	Task getNr(int nr);
};


#endif
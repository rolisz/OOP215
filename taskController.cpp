#include "taskController.h"

TaskController::TaskController(taskRepository* repo) {
	this->repo = repo;
}

void TaskController::addTask(QString name,int hours) {
	int id = repo->getNewId();
	Task t(id,name,hours);
	repo->addTask(t);
}

QVector<Task> TaskController::getList() {
	return repo->getList();
}

Task TaskController::getNr(int nr) {
	return repo->getNr(nr);
}

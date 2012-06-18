#include "myTasks.h"

MyTasks::MyTasks(TaskController* contr,QObject *parent):contr(contr),QAbstractTableModel(parent) {
}

int MyTasks::rowCount(const QModelIndex &parent) const {
	return contr->getList().size();
}
int MyTasks::columnCount(const QModelIndex &parent) const {
	return 3;
}

QVariant MyTasks::data(const QModelIndex &index, int role) const {
	if (role == Qt::DisplayRole) {
		switch (index.column()) {
		case 0:
			return contr->getNr(index.row()).getId();
		case 1:
			return contr->getNr(index.row()).getName();
		case 2:
			return contr->getNr(index.row()).getHours();
		default:
			return QVariant();
		}
	}
	return QVariant();
}
QVariant MyTasks::headerData(const QModelIndex &index, Qt::Orientation orientation, int role) const {
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (index.column()) {
				case 0:
					return "Task ID";
				case 1:
					return "Task Name";
				case 2:
					return "Number of hours";
				default:
					return QVariant();
			}
		}
	}
	return QVariant();
}

MyTasks::~MyTasks() {
}

void MyTasks::addTask(QString name, int hours) {
	beginInsertRows(QModelIndex(),contr->getList().size(),contr->getList().size());
	contr->addTask(name,hours);
	endInsertRows();
	emit update();
}


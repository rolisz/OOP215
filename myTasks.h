#ifndef MYTASKS_HS
#define MYTASKS_HS

#include <QAbstractTableModel>
#include <qvector.h>
#include <qfile.h>
#include <qfont.h>
#include "task.h"
#include <qvalidator.h>
#include "taskController.h"
class MyTasks : public QAbstractTableModel
{
	Q_OBJECT

public:
	MyTasks(TaskController* contr,QObject *parent = 0);
	~MyTasks();
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	QVariant headerData(const QModelIndex &index, Qt::Orientation orientation, int role) const;

private:
	TaskController* contr;
public:
	void addTask(QString name,int hours);
signals:
	void update();
};

#endif // SALES_H

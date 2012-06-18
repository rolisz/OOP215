#ifndef EXPOO_H
#define EXPOO_H

#include <QtGui/QMainWindow>
#include <QWidget>
#include <qtableview.h>
#include <qgridlayout.h>
#include <qlayout.h>
#include <qlabel.h>
#include <QtGui/qpushbutton.h>
#include <myTasks.h>
#include <QModelIndex>
#include <qlineedit.h>
#include <exception>
class exPOO : public QWidget
{
	Q_OBJECT

public:
	exPOO(QWidget *parent = 0, Qt::WFlags flags = 0);
	~exPOO();

private:
	QTableView* table;
	QPushButton* add;
	QLabel* total;
	QLabel* error;
	QLineEdit* name;
	QLineEdit* hours;
	MyTasks* model;
	TaskController* contr;

private slots:
	void updateTotal();
	void addTask();
};

#endif // EXPOO_H

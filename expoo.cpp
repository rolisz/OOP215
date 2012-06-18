#include "expoo.h"

exPOO::exPOO(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	QGridLayout* layout = new QGridLayout();
	table = new QTableView(this);
	layout->addWidget(table,0,0);
	contr = new TaskController(new taskRepository);
	model = new MyTasks(contr);
	add = new QPushButton("Adauga");
	name = new QLineEdit();
	QLabel* label1 = new QLabel("Name");
	error = new QLabel();
	hours = new QLineEdit();
	QLabel* label2 = new QLabel("Hours");
	hours->setValidator(new QIntValidator());
	QVBoxLayout* vert1 = new QVBoxLayout;
	vert1->addWidget(label1);
	vert1->addWidget(name);
	vert1->addWidget(label2);
	vert1->addWidget(hours);
	vert1->addWidget(add);
	vert1->addWidget(error);
	vert1->addStretch();

	total = new QLabel("Total ore: 0");
	layout->addWidget(total,1,0);
	layout->addLayout(vert1,0,1);

	table->setModel(model);
	connect(add, SIGNAL(clicked()), this, SLOT(addTask()));
	updateTotal();
	connect(model,SIGNAL(update()),this,SLOT(updateTotal()));
	//table->setSelectionMode(QAbstractItemView::SingleSelection);
	setLayout(layout);
}

exPOO::~exPOO()
{

}
void exPOO::updateTotal() {
	QVector<Task> tasks = contr->getList();
	int ore =0;
	for (QVector<Task>::iterator it = tasks.begin(); it != tasks.end(); it++) {
		ore+= (*it).getHours();
	}
	total->setText("Total: "+QString::number(ore));
}

void exPOO::addTask() {
	try {
		error->setText("");
		model->addTask(name->text(),hours->text().toInt());
	}
	catch (exception& e) {
		error->setText("Task invalid");
	}
}

#include "expoo.h"
#include <QtGui/QApplication>
#include <QString>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	exPOO w;
	w.show();
	return a.exec();
}

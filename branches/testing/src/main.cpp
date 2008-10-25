#include <iostream>
#include <QtGui/QApplication>

#include "aucdialog.h"
int main(int argc, char** argv){
	QApplication application( argc, argv );       

  AucDialog dialog;
  dialog.show();
	return application.exec();
}
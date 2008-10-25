//   -*- c++ -*------------------------------------------------------------
//
//   Author:            Stephan Diederich
//
//   Project name:      atvusb-creator
//
//   Date:              10/2008
//
//   Class:             AucDialog
//
//   Base class:        
//
//   Derived class(es): -
//
//   Exceptions:        
//
//   Description:       Implementation file for main ui dialog. uses platform specific AtvUsbCreatorBase implementation
//
//   ---------------------------------------------------------------------- 


#ifndef AUCDIALOG_H
#define AUCDIALOG_H

#include <QtGui/QDialog>

//forwards
namespace Ui{ struct AucDialog;};
class AtvUsbCreatorBase;

class AucDialog : public QDialog{
  Q_OBJECT;
public:
  AucDialog();
  ~AucDialog();
private:
  Ui::AucDialog* mp_ui;
  AtvUsbCreatorBase* mp_creator;
};

#endif
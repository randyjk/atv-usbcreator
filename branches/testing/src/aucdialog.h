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
  
private slots:
  void selectFile();
  
private:
  //private helpers
  void connectGui();
  void createPlatformSpecificCreator();
  void status(QString f_message);
  void enableWidgets(bool f_enable=true);
  void buildInstaller();
  QString getSelectedDrive();
  
  //members
  Ui::AucDialog* mp_ui;
  AtvUsbCreatorBase* mp_creator;
};

#endif
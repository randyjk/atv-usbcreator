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
#include "aucthread.h"
#include "aucprogressthread.h"
#include "aucdownloadprogress.h"

//forwards
namespace Ui{ struct AucDialog;};
class AtvUsbCreatorBase;
class AucReleaseDownloader;

class AucDialog : public QDialog{
  Q_OBJECT;
public:
  AucDialog();
  ~AucDialog();
  
public slots:
  void status(QString f_message);
  
private slots:
  void selectFile();
  void buildInstaller();
  void downloadComplete(QString);
  void progress(int);
  void maxprogress(int);
private:
  //private helpers
  void connectGui();
  static AtvUsbCreatorBase* createPlatformSpecificCreator();

  void enableWidgets(bool f_enable=true);

  QString getSelectedDrive();
  QString getAtvDmgUrl();
  
  //members
  Ui::AucDialog* mp_ui;
  AtvUsbCreatorBase* mp_creator;
  AucProgressThread m_progress_thread;
  AucThread m_thread;
  AucDownloadProgress m_download_progress;
  AucReleaseDownloader* mp_release_downloader;
};

#endif
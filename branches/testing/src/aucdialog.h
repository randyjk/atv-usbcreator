//   -*- c++ -*------------------------------------------------------------
//
//   Author:            Stephan Diederich
//
//   Project name:      atvusb-creator
//
//   Date:              10/2008
//
//   Class:             aucDialog
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


#ifndef aucDialog_H
#define aucDialog_H

#include <QtGui/QDialog>
#include "aucthread.h"
#include "aucprogressthread.h"
#include "aucdownloadprogress.h"

//forwards
namespace Ui{ struct aucDialog;};
class AtvUsbCreatorBase;
class AucReleaseDownloader;

class aucDialog : public QDialog{
  Q_OBJECT;
public:
  aucDialog();
  ~aucDialog();
  
public slots:
  void status(QString f_message);
  
private slots:
  void selectFile(void);
  void buildInstaller(void);
  void downloadComplete(QString);
  void progress(int);
  void maxprogress(int);
private:
  //private helpers
  void connect_slots(void);
  void set_installers(void);
  void set_installer_pict(void);
  void set_installer_options(void);
  void update_options2(void);
  void update_options3(void);
  void update_options3_fromcheckbox(void);
  void populate_devices(void);
  
  static AtvUsbCreatorBase* createPlatformSpecificCreator();
  void enableWidgets(bool f_enable=true);

  QString getSelectedDrive(void);
  QString getAtvDmgUrl(void);
  
  //members
  Ui::aucDialog*        mp_ui;
  AtvUsbCreatorBase*    mp_creator;
  AucProgressThread     m_progress_thread;
  AucThread             m_thread;
  AucDownloadProgress   m_download_progress;
  AucReleaseDownloader* mp_release_downloader;
};

#endif
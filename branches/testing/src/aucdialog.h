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
  void select_file(void);
  void set_installer_pict(void);
  void set_installer_options(void);
  void update_options2(void);
  void update_options3(void);
  void update_options3_fromcheckbox(void);
  void populate_devices(void);
  void build_installer(void);
  void download_complete(QString);
  void progress(int);
  void maxprogress(int);
private:
  //private helpers
  void set_installers(void);
  void connect_slots(void);
  
  static AtvUsbCreatorBase* createPlatformSpecificCreator();
  void enable_widgets(bool f_enable=true);

  QString get_selected_drive(void);
  QString get_appletv_dmg_url(void);
  
  //members
  Ui::aucDialog*        mp_ui;
  AtvUsbCreatorBase*    mp_creator;
  AucProgressThread     m_progress_thread;
  AucThread             m_thread;
  AucDownloadProgress   m_download_progress;
  AucReleaseDownloader* mp_release_downloader;
};

#endif
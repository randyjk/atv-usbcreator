
//   -*- c++ -*------------------------------------------------------------
//
//   Author:            Stephan Diederich
//
//   Project name:      atvusb-creator
//
//   Date:              10/2008
//
//   Class:             AucReleaseDownloader
//
//   Base class:        
//
//   Derived class(es): 
//
//   Exceptions:        
//
//   Description:       formerly known as ReleaseDownloader
//
//   ---------------------------------------------------------------------- 
#ifndef AUCRELEASEDOWNLOADER_H
#define AUCRELEASEDOWNLOADER_H

#include <QtCore/QThread>
class AtvUsbCreatorBase;
class AucDownloadProgress;

class AucReleaseDownloader : public QThread
{
  Q_OBJECT;
  
public:
	//TODO, proxies?
	AucReleaseDownloader(AtvUsbCreatorBase* fp_creator, QString f_url, AucDownloadProgress* fp_process /*, proxies?!*/);
	~AucReleaseDownloader();
  
  void run();
  
signals:
  void downloadComplete(QString);
  void status(QString);
private:
  QString m_url;
};
#endif //AUCRELEASEDOWNLOADER_H

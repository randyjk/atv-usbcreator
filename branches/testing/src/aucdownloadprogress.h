//   -*- c++ -*------------------------------------------------------------
//
//   Author:            Stephan Diederich
//
//   Project name:      atvusb-creator
//
//   Date:              10/2008
//
//   Class:             AucDownloadProgress
//
//   Base class:        
//
//   Derived class(es): 
//
//   Exceptions:        
//
//   Description:       formerly known as DownloadProgress;     """ A QObject urlgrabber BaseMeter class.
//    This class is called automatically by urlgrabber with our download details.
//    This class then sends signals to our main dialog window to update the
//    progress bar.
//
//   ---------------------------------------------------------------------- 
#ifndef AUCDOWNLOADPROGRESS_H
#define AUCDOWNLOADPROGRESS_H

#include <QtCore/QString>
#include <QtCore/QThread>

class QDate;

//TODO: this class was derived from BaseMeter before
class AucDownloadProgress : public QObject
{
  Q_OBJECT;
  
public:
	AucDownloadProgress();
  ~AucDownloadProgress();
  
  void start(QString f_filename = QString(), QString f_url = QString(), QString f_basename = QString(), int f_size = 0, QDate* fp_now = 0, QString f_text=QString());

  void update(int f_amount_read, QDate* fp_now = 0);
  
  void end(int f_amount_read);
  
signals:
  void progress(int);
  void maxprogress(int);
  
private:
};
#endif //AUCDOWNLOADPROGRESS_H

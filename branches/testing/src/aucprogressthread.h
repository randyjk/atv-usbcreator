//   -*- c++ -*------------------------------------------------------------
//
//   Author:            Stephan Diederich
//
//   Project name:      atvusb-creator
//
//   Date:              10/2008
//
//   Class:             AucProgressThread
//
//   Base class:        
//
//   Derived class(es): 
//
//   Exceptions:        
//
//   Description:       formerly known as ProgressThread A thread that monitors the progress of Live USB creation.
//                      This thread periodically checks the amount of free space left on the 
//                      given drive and sends a signal to our main dialog window to update the
//                      progress bar.
//
//   ---------------------------------------------------------------------- 
#ifndef AUCPROGRESSTHREAD_H
#define AUCPROGRESSTHREAD_H

#include <QtCore/QThread>

class AucProgressThread : public QThread
{
  Q_OBJECT;
  
public:
	AucProgressThread(QObject* fp_parent = 0);
  ~AucProgressThread();
  
  void setData(int f_size, QString f_drive, int f_freebytes);
  
  void run();
  void terminate();
  
signals:
  void maxprogress(int);
  void progress(int);
  
private:
  int m_total_size;
  int m_orig_free;
  int m_get_free_bytes;
  QString m_drive;
};
#endif //AUCPROGRESSTHREAD_H

//   -*- c++ -*------------------------------------------------------------
//
//   Author:            Stephan Diederich
//
//   Project name:      atvusb-creator
//
//   Date:              10/2008
//
//   Class:             AucThread
//
//   Base class:        
//
//   Derived class(es): 
//
//   Exceptions:        
//
//   Description:       formerly known as LiveUSBThread,  main creator thread
//
//   ---------------------------------------------------------------------- 



#ifndef AUCTHREAD_H
#define AUCTHREAD_H

#include <QtCore/QThread>

class AtvUsbCreatorBase;
class AucProgressThread;

class AucThread : public QThread
{
  Q_OBJECT;
public:
  //TODO:thread and creator are not optional, use references
  AucThread(AtvUsbCreatorBase* fp_creator, AucProgressThread* fp_progress, QObject* fp_parent = 0);
  ~AucThread();

  void setMaxProgress(int f_max){
    emit(maxprogress(f_max)); 
  }
  
  void updateProcess(int f_value){
      emit(progress(f_value));
  }
  
  void run();
  
signals:
  void progress(int);
  void maxprogress(int);
  void status(QString);
    
private:
  AtvUsbCreatorBase* mp_creator; 
  AucProgressThread* mp_progress; 
};
#endif //AUCTHREAD_H

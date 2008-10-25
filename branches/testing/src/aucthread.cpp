#include "aucthread.h"
#include "aucprogressthread.h"
#include "atvusbcreatorbase.h"

AucThread::AucThread(AtvUsbCreatorBase* fp_creator, AucProgressThread* fp_progress, QObject* fp_parent):
  QThread(fp_parent), mp_creator(fp_creator), mp_progress(fp_progress)
{
}

AucThread::~AucThread(){
  wait();
}

void AucThread::run(){
}
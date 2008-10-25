#include "aucprogressthread.h"

AucProgressThread::AucProgressThread(QObject* fp_parent):
  QThread(fp_parent), m_size(0), m_freebytes(0), m_get_free_bytes(0)
{
}

AucProgressThread::~AucProgressThread(){
  wait();
}

void AucProgressThread::setData(int f_size, QString f_drive, int f_freebytes){
/*
#---------------------------------------------------------------------------------
  def set_data(self, size, drive, freebytes):
  self.totalsize = size / 1024
  self.drive = drive
  self.get_free_bytes = freebytes
  self.orig_free = self.get_free_bytes()
  self.emit(QtCore.SIGNAL("maxprogress(int)"), self.totalsize)
  */
}


void AucProgressThread::run(){
/*
#---------------------------------------------------------------------------------
def run(self):
while True:
free = self.get_free_bytes()
value = (self.orig_free - free) / 1024
self.emit(QtCore.SIGNAL("progress(int)"), value)
if value >= self.totalsize:
break
sleep(4)
*/
}

void AucProgressThread::terminate(){
/*
#---------------------------------------------------------------------------------
def terminate(self):
self.emit(QtCore.SIGNAL("progress(int)"), self.totalsize)
QtCore.QThread.terminate(self)
*/
}
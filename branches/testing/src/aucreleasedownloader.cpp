#include "aucreleasedownloader.h"

#include <iostream>
#include <QtCore/QFile>

#include "aucdownloadprogress.h"

AucReleaseDownloader::AucReleaseDownloader(AtvUsbCreatorBase* fp_creator, QString f_url, AucDownloadProgress* fp_process /*, proxies?!*/):
  m_url(f_url){
}

AucReleaseDownloader::~AucReleaseDownloader(){
}

void AucReleaseDownloader::run(){
  emit status(QString("Downloading %1...").arg(m_url));
  QString dmg;
  //TODO   
  assert(0);
//  grabber = URLGrabber(progress_obj=self.progress, proxies=self.proxies)
  try{
    //TODO port me
    assert(0);
    QString dst;
    //dst = os.path.join(self.live.downloads, os.path.basename(self.url) )
    if ( QFile::exists(dst) ){
      QFile::remove(dst);
    }
    assert(0);
    //TODO port me
    //dmg = grabber.urlgrab(self.url, filename=dst, reget='simple')
  } catch (std::exception e) { //TODO std::exception is only a placeholder, for waht grabber can throw URLGrabError, e:
    emit downloadComplete(QString::fromStdString(e.what()));
    return;
  }
  emit downloadComplete(dmg);
}
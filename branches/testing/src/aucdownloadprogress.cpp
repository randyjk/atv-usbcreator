#include "aucdownloadprogress.h"
#include <QtCore/QDate>

AucDownloadProgress::AucDownloadProgress(){
}

AucDownloadProgress::~AucDownloadProgress(){
}

void AucDownloadProgress::start(QString /*f_filename*/, QString /*f_url*/, QString /*f_basename*/, int f_size, QDate* /*fp_now*/, QString /*f_text*/){
  emit maxprogress( f_size );
}

void AucDownloadProgress::update(int f_amount_read, QDate* /*fp_now*/){
  /* Update our download progressbar.
  
  :read: the number of bytes read so far
  */
  emit progress(f_amount_read);
}

void AucDownloadProgress::end(int f_amount_read){
  update(f_amount_read);
}

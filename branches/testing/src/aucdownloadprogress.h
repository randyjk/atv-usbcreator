//   -*- c++ -*------------------------------------------------------------
//
//   Author:            Scott Davilla / Stephan Diederich
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
//   Copyright (C) 2008  TeamXBMC
//   This program is free software; you can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your option) any later version.
//   
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//   
//   You should have received a copy of the GNU General Public License
//   along with this program; if not, write to the Free Software
//   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
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


//   -*- c++ -*------------------------------------------------------------
//
//   Author:           Scott Davilla /  Stephan Diederich
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

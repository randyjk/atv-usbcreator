
#include <stdexcept>

#include <QtGui/QFileDialog>

//include our generated ui_h
#include "ui_atvusb.h"
//
#include "aucDialog.h"
#include "aucreleasedownloader.h"

//probably move this include hassle into an atvusbcreatorfactory.h
#ifdef WIN32
  #error "nothing here yet..implement me!"
  #include "win32/atvusbcreatorwin32.h"
#else
#ifdef __APPLE__
  #include "osx/atvusbcreatorosx.h"
#else
 //linux
 #error "nothing here yet..implement me!"
 #include "osx/atvusbcreatorlinux.h"
#endif
#endif

//---------------------------------------------------------------------- 
//---------------------------------------------------------------------- 
aucDialog::aucDialog(): QDialog(), mp_ui(new Ui::aucDialog), 
  mp_creator(createPlatformSpecificCreator()), 
  m_progress_thread(), 
  m_thread(mp_creator, &m_progress_thread, this)
{
  mp_ui->setupUi(this);
  
  set_installers();
  set_installer_options();
  populate_devices();

  connect_slots();

  // plugin name can get long so let the view size expand
  //QAbstractItemView *view = mp_ui->installMenu_3->view();
  //view->setSizePolicy(QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Preferred);
}

//---------------------------------------------------------------------- 
aucDialog::~aucDialog() {
  delete mp_ui;  
  delete mp_creator;
}

//---------------------------------------------------------------------- 
void aucDialog::selectFile(void) {
  QString dmgfile = QFileDialog::getOpenFileName(this,"Select AppleTV Update DMG", ".", "DMG (*.dmg)" );
  if( dmgfile.size() ) {
    try {
      //TODO what's the _to_unicode_thing? how can it go wrong?
      //self.live.dmg = self._to_unicode(dmgfile)
      mp_creator->setDMGPath(dmgfile.toStdString());
    } catch (std::exception& e){ 
      //TODO no loggin yet
      mp_creator->logger().error(e.what());
      status("Sorry, I'm having trouble encoding the filename "
            "of your livecd.  You may have better luck if "
            "you move your DMG to the root of your drive "
             "(ie: C:\)");
    }
    status(dmgfile + " selected");
  }
}

//---------------------------------------------------------------------- 
void aucDialog::connect_slots(void) {
  connect(mp_ui->browseButton, SIGNAL(clicked()), this, SLOT(selectFile()));
  connect(mp_ui->startButton,  SIGNAL(clicked()), this, SLOT(buildInstaller()));
  connect(mp_ui->installerMenu,  SIGNAL(currentIndexChanged(int)), this, SLOT(set_installer_pict()));
  connect(mp_ui->installerMenu,  SIGNAL(currentIndexChanged(int)), this, SLOT(set_installer_options()));
  connect(mp_ui->installMenu_2,  SIGNAL(currentIndexChanged(int)), this, SLOT(update_options2()));
  connect(mp_ui->installMenu_3,  SIGNAL(currentIndexChanged(int)), this, SLOT(update_options3()));
  connect(mp_ui->installCheckbox,  SIGNAL(stateChanged(int)), this, SLOT(update_options3_fromcheckbox()));
  connect(mp_ui->deviceRefreshButton, SIGNAL(clicked()), this, SLOT(populate_devices()));
  connect(&m_thread,  SIGNAL(status(QString)), this, SLOT(status(QString)));
  connect(&m_thread,  SIGNAL(finished()), this, SLOT(enable_widgets(true)));
  connect(&m_thread,  SIGNAL(terminated()), this, SLOT(enable_widgets(true)));
  connect(&m_thread,  SIGNAL(progress(int)), this, SLOT(progress(int)));
  connect(&m_thread,  SIGNAL(maxprogress(int)), this, SLOT(maxprogress(int)));
  connect(&m_progress_thread, SIGNAL(progress(int)), this, SLOT(progress(int)));
  connect(&m_progress_thread, SIGNAL(maxprogress(int)), this, SLOT(maxprogress(int)));
  connect(&m_download_progress, SIGNAL(progress(int)), this, SLOT(progress(int)));
  connect(&m_download_progress, SIGNAL(maxprogress(int)), this, SLOT(maxprogress(int)));
}

//---------------------------------------------------------------------- 
void aucDialog::set_installers(void) {
/*
        for info in self.live.installers:
            self.installerMenu.addItem(info['name'])
            #self.installerMenu.item[self.installerMenu.currentIndex].setSelectable(False)
        self.installerMenu.setCurrentIndex(1);
*/
}

//---------------------------------------------------------------------- 
void aucDialog::set_installer_pict(void) {
/*
        # change the header image to match installer
        installer = self.live.installers[self.installerMenu.currentIndex()]
        self.headerLabel.setPixmap(QtGui.QPixmap( installer['pict'] ))
*/
}

//---------------------------------------------------------------------- 
void aucDialog::set_installer_options(void) {
/*
        for installer in self.live.installers:
            installer['install'] = False;

        # populate first options menu
        installer = self.live.installers[self.installerMenu.currentIndex()]
        installer['install'] = True;
        
        #
        self.installMenu_1.clear()
        self.installMenu_1.setEnabled(True)
        option1 = installer['option1']
        if option1 == 'backup':
            for info in backup:
                self.installMenu_1.addItem(info['name'])
        elif option1 == 'restore':
            for info in restore:
                self.installMenu_1.addItem(info['name'])
        else:
            self.installMenu_1.setEnabled(False)
        # populate second options menu
        self.installMenu_2.clear()
        self.installMenu_2.setEnabled(True)
        option2 = installer['option2']
        if option2 == 'patchsticks':
            self.live.load_patchsticks();
            for info in self.live.patchsticks:
                self.installMenu_2.addItem(info['name'])
        elif option2 == 'linux_video':
            for info in linux_video:
                self.installMenu_2.addItem(info['name'])
        elif option2 == 'linux_ir':
            for info in linux_ir:
                self.installMenu_2.addItem(info['name'])
        else:
            self.installMenu_2.setEnabled(False)
        #
        # third options menu is always setup depending on the
        # contents of the second options menu
        self.update_options2();
*/
}

//---------------------------------------------------------------------- 
void aucDialog::update_options2(void) {
/*
        # second options menu changed, update third options menu
        installer = self.live.installers[self.installerMenu.currentIndex()]
        #
        self.installMenu_3.clear()
        # watch the enable state, we start disabled here and
        # only enable it there are items in the menu
        self.installMenu_3.setEnabled(False)
        self.installCheckbox.setEnabled(False)
        if installer['option2'] == 'patchsticks':
            patchstick = self.live.patchsticks[self.installMenu_2.currentIndex()]
            if 'atv-' in patchstick['depends']:
                self.live.load_packages(patchstick);
                for package in self.live.packages:
                    if package['install']:
                        icon = QtGui.QIcon(":/install.png")
                    else:
                        icon = QtGui.QIcon(":/uninstall.png")
                    self.installMenu_3.addItem(icon, package['name'])
                self.installMenu_3.setCurrentIndex(0);
                #
                package = self.live.packages[self.installMenu_3.currentIndex()]
                if package['install']:
                    self.installCheckbox.setCheckState(QtCore.Qt.Checked)
                else:
                    self.installCheckbox.setCheckState(QtCore.Qt.Unchecked)
        if self.installMenu_3.count() > 0:
            self.installMenu_3.setEnabled(True)
            self.installCheckbox.setEnabled(True)
*/
}

//---------------------------------------------------------------------- 
void aucDialog::update_options3(void) {
/*
        # third options menu changed, update checkbox state 
        package = self.live.packages[self.installMenu_3.currentIndex()]
        if package['install']:
            self.installCheckbox.setCheckState(QtCore.Qt.Checked)
        else:
            self.installCheckbox.setCheckState(QtCore.Qt.Unchecked)
*/
}

//---------------------------------------------------------------------- 
void aucDialog::update_options3_fromcheckbox(void) {
/*
        # checkbox state changed, update third options menu icon 
        package = self.live.packages[self.installMenu_3.currentIndex()]
        # special check for only one composite video selection enabled.
        # this touches package so remember to reload it at end
        if 'Composite' in package['name']:
            # if the selection is a composite video entry, turn off
            # previous composite video entry
            index = 0
            for package in self.live.packages:
                if 'Composite' in package['name']:
                    package['install'] = False
                    icon = QtGui.QIcon(":/uninstall.png")
                    self.installMenu_3.setItemIcon(index, icon);
                index = index + 1
            package = self.live.packages[self.installMenu_3.currentIndex()]
        # now we can do the install toggle
        if self.installCheckbox.checkState() == QtCore.Qt.Checked:
            package['install'] = True
            icon = QtGui.QIcon(":/install.png")
        else:
            package['install'] = False
            icon = QtGui.QIcon(":/uninstall.png")
        self.installMenu_3.setItemIcon(self.installMenu_3.currentIndex(), icon);
*/
}

//---------------------------------------------------------------------- 
void aucDialog::populate_devices(void) {
/*
        self.deviceCombo.clear()
        self.statusInfoEdit.clear()
        try:
            self.live.detect_removable_drives()
            for device, info in self.live.drives.items():
                self.deviceCombo.addItem(device)
            self.startButton.setEnabled(True)
        except LiveUSBError, e:
            self.statusInfoEdit.setPlainText(str(e))
            self.startButton.setEnabled(False)
*/
}

//---------------------------------------------------------------------- 
AtvUsbCreatorBase* aucDialog::createPlatformSpecificCreator(void) {
//probably move this include hassle into an atvusbcreatorfactory.h
#ifdef WIN32
  return new AtvUsbCreatorWin32;
#else
#ifdef __APPLE__
  return new AtvUsbCreatorOSX;
#else
  return new AtvUsbCreatorLinux;
#endif
#endif  
}

//---------------------------------------------------------------------- 
void aucDialog::status(QString f_message) {
  mp_ui->statusInfoEdit->append(f_message);
}

//---------------------------------------------------------------------- 
void aucDialog::enableWidgets(bool f_enable) {
  mp_ui->startButton->setEnabled(f_enable);
  mp_ui->browseButton->setEnabled(f_enable);
  mp_ui->installerMenu->setEnabled(f_enable);
  mp_ui->installMenu_1->setEnabled(f_enable);
  mp_ui->installMenu_2->setEnabled(f_enable);
  mp_ui->installMenu_3->setEnabled(f_enable);
  mp_ui->installCheckbox->setEnabled(f_enable);
  mp_ui->deviceCombo->setEnabled(f_enable);
  mp_ui->deviceRefreshButton->setEnabled(f_enable);
}

//---------------------------------------------------------------------- 
void aucDialog::buildInstaller(void) {
  enableWidgets(false);
  //
  mp_creator->setDrive(getSelectedDrive().toStdString());
  //
  if (QFile::exists(QString::fromStdString(mp_creator->getcrBootEFIPath()))){
    //if boot.efi exits just use it
    m_thread.start();
  } else {
    if (! mp_creator->getcrDMGPath().empty()){
      //If the user has selected an DMG, use it.
      m_thread.start();
    } else {
      assert(0); //TODO
      //If no selected DMG, download one.
      //TODO proxies
      mp_release_downloader = new AucReleaseDownloader(mp_creator, getAtvDmgUrl(), &m_download_progress);
    /*
          self.downloader = ReleaseDownloader(
                                              self.live,
                                              self.atv_dmg_url,
                                              progress=self.download_progress,
                                              proxies=self.live.get_proxies())
     */
      connect(mp_release_downloader, SIGNAL(dlcomplete(QString)), this, SLOT(downloadComplete(QString)));
      connect(mp_release_downloader, SIGNAL(status(QString)), this, SLOT(status(QString)));
      mp_release_downloader->start();
    }
  }
}

//---------------------------------------------------------------------- 
void aucDialog::downloadComplete(QString f_path) {
  /* Called by our ReleaseDownloader thread upon completion.

  Upon success, the thread passes in the filename of the downloaded
  release.  If the 'dmg' argument is not an existing file, then
  it is assumed that the download failed and 'dmg' should contain
   the error message.
   */
  if (QFile::exists(f_path)){
    status("Download complete!");
    mp_creator->setDMGPath(f_path.toStdString());
    m_thread.start();
  } else {
    status("Download failed: " + f_path);
    status("You can try again to resume your download");
    enableWidgets(true);
  }
  delete mp_release_downloader;
  mp_release_downloader = 0;
}

//---------------------------------------------------------------------- 
void aucDialog::progress(int f_val) {
  mp_ui->progressBar->setValue(f_val);
}

//---------------------------------------------------------------------- 
void aucDialog::maxprogress(int f_val) {
  mp_ui->progressBar->setMaximum(f_val);
}

//---------------------------------------------------------------------- 
QString aucDialog::getSelectedDrive(void) {
  //TODO: fix this when we know what needs to be done here
  return mp_ui->deviceCombo->currentText();
  //.split()[0];
}

//---------------------------------------------------------------------- 
QString aucDialog::getAtvDmgUrl(void) {

  assert(0);
  /*
   #import urllib
   #from xml.dom import minidom
   #
   #xml_doc = minidom.parse(urllib.urlopen('http://mesu.apple.com/version.xml'))
   #self.atv_dmg_url = xml_doc.getElementsByTagName('dict')[1].getElementsByTagName('string')[1].firstChild.data
   #self.atv_dmg_url = 'http://mesu.apple.com/data/OS/061-4632.2080414.gt5rW/2Z694-5428-3.dmg'
   self.atv_dmg_url = atv_dmg_info[0]['url']
   
  */
}
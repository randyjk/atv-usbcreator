# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'data/atvusb.ui'
#
# Created: Sun Jul 13 20:32:10 2008
#      by: PyQt4 UI code generator 4.4.2
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_aucDialog(object):
    def setupUi(self, aucDialog):
        aucDialog.setObjectName("aucDialog")
        aucDialog.setWindowModality(QtCore.Qt.NonModal)
        aucDialog.resize(430,445)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed,QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(aucDialog.sizePolicy().hasHeightForWidth())
        aucDialog.setSizePolicy(sizePolicy)
        aucDialog.setAutoFillBackground(False)
        aucDialog.setSizeGripEnabled(False)
        aucDialog.setModal(False)
        self.statusInfoEdit = QtGui.QTextEdit(aucDialog)
        self.statusInfoEdit.setGeometry(QtCore.QRect(8,248,414,111))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.statusInfoEdit.setFont(font)
        self.statusInfoEdit.setReadOnly(True)
        self.statusInfoEdit.setObjectName("statusInfoEdit")
        self.progressBar = QtGui.QProgressBar(aucDialog)
        self.progressBar.setGeometry(QtCore.QRect(8,364,414,26))
        self.progressBar.setProperty("value",QtCore.QVariant(0))
        self.progressBar.setObjectName("progressBar")
        self.browseGroup = QtGui.QGroupBox(aucDialog)
        self.browseGroup.setGeometry(QtCore.QRect(8,188,190,53))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.browseGroup.setFont(font)
        self.browseGroup.setObjectName("browseGroup")
        self.browseButton = QtGui.QPushButton(self.browseGroup)
        self.browseButton.setGeometry(QtCore.QRect(21,20,141,28))
        self.browseButton.setIconSize(QtCore.QSize(16,16))
        self.browseButton.setObjectName("browseButton")
        self.deviceGroup = QtGui.QGroupBox(aucDialog)
        self.deviceGroup.setGeometry(QtCore.QRect(192,384,190,53))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.deviceGroup.setFont(font)
        self.deviceGroup.setObjectName("deviceGroup")
        self.deviceCombo = QtGui.QComboBox(self.deviceGroup)
        self.deviceCombo.setGeometry(QtCore.QRect(28,20,153,26))
        self.deviceCombo.setEditable(False)
        self.deviceCombo.setInsertPolicy(QtGui.QComboBox.InsertAtTop)
        self.deviceCombo.setDuplicatesEnabled(False)
        self.deviceCombo.setObjectName("deviceCombo")
        self.deviceRefreshButton = QtGui.QPushButton(self.deviceGroup)
        self.deviceRefreshButton.setGeometry(QtCore.QRect(0,20,30,26))
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(":/refresh.png"),QtGui.QIcon.Normal,QtGui.QIcon.Off)
        self.deviceRefreshButton.setIcon(icon)
        self.deviceRefreshButton.setFlat(True)
        self.deviceRefreshButton.setObjectName("deviceRefreshButton")
        self.headerLabel = QtGui.QLabel(aucDialog)
        self.headerLabel.setGeometry(QtCore.QRect(0,0,430,128))
        self.headerLabel.setPixmap(QtGui.QPixmap(":/atv-bootloader.png"))
        self.headerLabel.setObjectName("headerLabel")
        self.installerGroup = QtGui.QGroupBox(aucDialog)
        self.installerGroup.setGeometry(QtCore.QRect(8,132,190,53))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.installerGroup.setFont(font)
        self.installerGroup.setObjectName("installerGroup")
        self.installerMenu = QtGui.QComboBox(self.installerGroup)
        self.installerMenu.setGeometry(QtCore.QRect(8,20,176,26))
        self.installerMenu.setEditable(False)
        self.installerMenu.setMaxVisibleItems(25)
        self.installerMenu.setMaxCount(100)
        self.installerMenu.setDuplicatesEnabled(False)
        self.installerMenu.setObjectName("installerMenu")
        self.installGroup = QtGui.QGroupBox(aucDialog)
        self.installGroup.setGeometry(QtCore.QRect(208,132,213,109))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.installGroup.setFont(font)
        self.installGroup.setObjectName("installGroup")
        self.installMenu_1 = QtGui.QComboBox(self.installGroup)
        self.installMenu_1.setGeometry(QtCore.QRect(8,20,197,26))
        self.installMenu_1.setEditable(False)
        self.installMenu_1.setDuplicatesEnabled(False)
        self.installMenu_1.setObjectName("installMenu_1")
        self.installMenu_2 = QtGui.QComboBox(self.installGroup)
        self.installMenu_2.setGeometry(QtCore.QRect(8,48,197,26))
        self.installMenu_2.setEditable(False)
        self.installMenu_2.setDuplicatesEnabled(False)
        self.installMenu_2.setObjectName("installMenu_2")
        self.installMenu_3 = QtGui.QComboBox(self.installGroup)
        self.installMenu_3.setGeometry(QtCore.QRect(28,76,176,26))
        self.installMenu_3.setEditable(False)
        self.installMenu_3.setDuplicatesEnabled(False)
        self.installMenu_3.setObjectName("installMenu_3")
        self.installCheckbox = QtGui.QCheckBox(self.installGroup)
        self.installCheckbox.setGeometry(QtCore.QRect(9,80,21,21))
        self.installCheckbox.setObjectName("installCheckbox")
        self.startButton = QtGui.QPushButton(aucDialog)
        self.startButton.setEnabled(True)
        self.startButton.setGeometry(QtCore.QRect(40,402,140,34))
        self.startButton.setObjectName("startButton")

        self.retranslateUi(aucDialog)
        self.installerMenu.setCurrentIndex(-1)
        self.installMenu_1.setCurrentIndex(-1)
        self.installMenu_2.setCurrentIndex(-1)
        self.installMenu_3.setCurrentIndex(-1)
        QtCore.QMetaObject.connectSlotsByName(aucDialog)

    def retranslateUi(self, aucDialog):
        aucDialog.setWindowTitle(QtGui.QApplication.translate("aucDialog", "ATV USB Creator", None, QtGui.QApplication.UnicodeUTF8))
        self.browseGroup.setTitle(QtGui.QApplication.translate("aucDialog", "Download AppleTV Update DMG or", None, QtGui.QApplication.UnicodeUTF8))
        self.browseButton.setText(QtGui.QApplication.translate("aucDialog", "Choose a DMG", None, QtGui.QApplication.UnicodeUTF8))
        self.browseButton.setShortcut(QtGui.QApplication.translate("aucDialog", "Alt+B", None, QtGui.QApplication.UnicodeUTF8))
        self.deviceGroup.setTitle(QtGui.QApplication.translate("aucDialog", "USB Target Device", None, QtGui.QApplication.UnicodeUTF8))
        self.installerGroup.setTitle(QtGui.QApplication.translate("aucDialog", "Choose an Installation", None, QtGui.QApplication.UnicodeUTF8))
        self.installGroup.setTitle(QtGui.QApplication.translate("aucDialog", "Installation Options", None, QtGui.QApplication.UnicodeUTF8))
        self.startButton.setText(QtGui.QApplication.translate("aucDialog", "Create Using ->", None, QtGui.QApplication.UnicodeUTF8))

import resources_rc

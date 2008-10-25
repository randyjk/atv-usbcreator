cmake_minimum_required(VERSION 2.6)

PROJECT( atvusb-creator )

#setup qt4
find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})

#setup other dependencies
include_directories(src)

#gather cpps
SET(atvusb-creator_SRCS 
	src/main.cpp src/aucdialog.h 
	src/aucdialog.cpp 
	src/atvusbcreatorbase.h 
	src/atvusbcreatorbase.cpp)

IF(WIN32)
	error("no win32 stuff here yet, sorry")
ELSE(WIN32)
 IF(APPLE)
	 SET(atvusb-creator_SRCS ${atvusb-creator_SRCS} src/osx/atvusbcreatorosx.h src/osx/atvusbcreatorosx.cpp)
 ELSE(APPLE)
 	#linux
	error("no linux stuff here yet, sorry")
 ENDIF(APPLE)
ENDIF(WIN32)


#gather uis
SET(atvusb-creator_UIS data/atvusb.ui)
QT4_WRAP_UI(atvusb-creator_UIS_H ${atvusb-creator_UIS})

# Don't forget to include output directory, otherwise the UI files won't be found!
include_directories(${CMAKE_CURRENT_BINARY_DIR})

#moc the headers
SET(atvusb-creator_MOC_HDRS src/aucdialog.h)	
QT4_WRAP_CPP(atvusb-creator_MOC_SRCS ${atvusb-creator_MOC_HDRS})

QT4_ADD_RESOURCES(atvusb-creator_RES_SRCS data/resources.qrc)

IF(WIN32)
add_executable( atvusb-creator ${atvusb-creator_SRCS} ${atvusb-creator_MOC_SRCS} ${atvusb-creator_UIS_H} ${atvusb-creator_RES_SRCS})
ELSE(WIN32)
 IF(APPLE)
 	add_executable( atvusb-creator MACOSX_BUNDLE ${atvusb-creator_SRCS} ${atvusb-creator_MOC_SRCS} ${atvusb-creator_UIS_H} ${atvusb-creator_RES_SRCS})
 	set_target_properties(atvusb-creator PROPERTIES MACOSX_BUNDLE_INFO_PLIST "${PROJECT_SOURCE_DIR}/data/Info.plist")
 ELSE(APPLE)
 ENDIF(APPLE)
ENDIF(WIN32)
target_link_libraries(atvusb-creator ${QT_LIBRARIES})

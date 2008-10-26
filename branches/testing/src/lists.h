#ifndef LISTS_H
#define LISTS_H

#include <string>

typedef struct _DMG_INFO {
  std::string name;
  std::string url;
  std::string sha1;
} DMG_INFO;

typedef struct _USB_INFO {
  std::string name;
  std::string file;
  std::string sha1;
  int         size;
  std::string p1_fs;
  int         p1_bgn;
  int         p1_cnt;
  std::string p2_fs;
  int         p2_bgn;
  int         p2_cnt;
} USB_INFO;

typedef struct _HFS_INFO {
  std::string name;
  std::string file;
  std::string sha1;
  int         size;
  std::string p1_fs;
  int         efibgn;
  int         eficnt;
} HFS_INFO;

typedef struct _INSTALLER {
  std::string name;
  std::string pict;
  std::string url;
  std::string sha1;
  bool        enable;
  bool        install;
  std::string option1;
  std::string option2;
  std::string option3;
} INSTALLER;

typedef struct _BACKUP {
  std::string name;
} BACKUP;

typedef struct _RESTORE {
  std::string name;
} RESTORE;

typedef struct _PATCHSTICK {
  std::string name;
  bool        enable;
  std::string depends;
} PATCHSTICK;

typedef struct _PACKAGE {
  std::string name;
  bool        enable;
  std::string depends;
  bool        install;
  std::string url;
  std::string type;
  std::string pkgname;
  std::string loader;
} PACKAGE;

typedef struct _LINUX_VIDEO {
  std::string name;
} LINUX_VIDEO;

typedef struct _LINUX_IR {
  std::string name;
} LINUX_IR;

#endif







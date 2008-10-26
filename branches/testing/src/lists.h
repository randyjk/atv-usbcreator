#ifndef LISTS_H
#define LISTS_H

typedef struct _DMG_INFO {
  char    *name;
  char    *url;
  char    *sha1;
} DMG_INFO;

typedef struct _USB_INFO {
  char    *name;
  char    *file;
  char    *sha1;
  int     size;
  char    *p1_fs;
  int     p1_bgn;
  int     p1_cnt;
  char    *p2_fs;
  int     p2_bgn;
  int     p2_cnt;
} USB_INFO;

typedef struct _HFS_INFO {
  char    *name;
  char    *file;
  char    *sha1;
  int     size;
  char    *p1_fs;
  int     efibgn;
  int     eficnt;
} HFS_INFO;

typedef struc _INSTALLERS {
  char    *name;
  char    *pict;
  char    *url;
  char    *sha1;
  bool    enable;
  bool    install;
  char    *option1;
  char    *option2;
  char    *option3;
} INSTALLERS;

typedef struct _BACKUP {
  char    *name;
} BACKUP;

typedef struct _RESTORE {
  char    *name;
} RESTORE;

typedef struc _PATCHSTICKS {
  char    *name;
  bool    enable;
  char    *depends;
} PATCHSTICKS;

typedef struc _PACKAGES {
  char    *name;
  bool    enable;
  char    *depends;
  bool    install;
  char    *url;
  char    *type;
  char    *pkgname;
  char    *loader;
} PACKAGES;

#endif







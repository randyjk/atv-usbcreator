#include <lists.h>

// openssl dgst -sha1
DMG_INFO atv_dmg_info = {
    "AppleTV Update 2.1",
    "http://mesu.apple.com/data/OS/061-4632.2080414.gt5rW/2Z694-5428-3.dmg",
    "65151a796164f202f0e0aa3554c5e9cad74e149d"
};
/*
dmg_info atv_dmg_info = {
    "AppleTV Update 2.2",
    "http://mesu.apple.com/data/OS/061-5262.20081002.tvap9/2Z694-5499.dmg",
    "ed7256ee03b3a3fc5e0004089157f9b3ff3e6d4e"
};
*/

DMG_INFO osx_dmg_info = {
    "OSX Intel Combo Update 10.4.9",
    "http://supportdownload.apple.com/download.info.apple.com/Apple_Support_Area/Apple_Software_Updates/Mac_OS_X/downloads/061-3165.20070313.iU8y4/MacOSXUpdCombo10.4.9Intel.dmg",
    "0000000000000000000000000000000000000000",
};

USB_INFO usb_info = {
    "atv_512MB.img",
    "atv_512MB.7z",
    "0000000000000000000000000000000000000000",
    1000000 * 512,
    "fat32",
    40 * 512,
    948800 * 512,
    "hfsplus",
    948840 * 512,
    51000 * 512,
};

// http://www.osxbook.com/software/hfsdebug/
// mkdir tmp
// hdiutil attach -mountpoint tmp atvusb_boot.img
// hfsdebug tmp/boot.efi
// hdiutil detach tmp
HFS_INFO hfs_info = {
    "atv_recv.img",
    "atv_recv.img.zip",
    "0000000000000000000000000000000000000000",
    51000 * 512,
    "hfsplus",
    100 * 4096,
    298800,
};





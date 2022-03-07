#ifndef _FILEMENU_H_
#define _FILEMENU_H_

#include "common.h"

extern MenuPanel* filemenu_menus[4];

extern BSS s32 filemenu_iterFileIdx;
extern BSS s32 filemenu_pressedButtons;
extern BSS s32 filemenu_8024C088;
extern BSS s32 filemenu_heldButtons;
extern BSS s32 filemenu_8024C090;
extern BSS s32 filemenu_loadedFileIdx;
extern BSS s8 filemenu_8024C098;
extern BSS s32 filemenu_8024C09C;
extern BSS s32 filemenu_cursorHudElemID[1];
extern BSS s32 filemenu_8024C0A4[3];
extern BSS s32 filemenu_hudElemIDs[20];
extern BSS s32 filemenu_8024C100[8];

#endif

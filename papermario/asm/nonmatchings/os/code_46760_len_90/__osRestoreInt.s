.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel __osRestoreInt
/* 0467D0 8006B3D0 40086000 */  mfc0  $t0, $12
/* 0467D4 8006B3D4 01044025 */  or    $t0, $t0, $a0
/* 0467D8 8006B3D8 40886000 */  mtc0  $t0, $12
/* 0467DC 8006B3DC 00000000 */  nop   
/* 0467E0 8006B3E0 00000000 */  nop   
/* 0467E4 8006B3E4 03E00008 */  jr    $ra
/* 0467E8 8006B3E8 00000000 */   nop   

/* 0467EC 8006B3EC 00000000 */  nop   



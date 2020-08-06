.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osViSetYScale
/* 0423D0 80066FD0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0423D4 80066FD4 F7B40018 */  sdc1  $f20, 0x18($sp)
/* 0423D8 80066FD8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0423DC 80066FDC 0C01ACD8 */  jal   __osDisableInt
/* 0423E0 80066FE0 46006506 */   mov.s $f20, $f12
/* 0423E4 80066FE4 3C048009 */  lui   $a0, 0x8009
/* 0423E8 80066FE8 8C8459D4 */  lw    $a0, 0x59d4($a0)
/* 0423EC 80066FEC 94830000 */  lhu   $v1, ($a0)
/* 0423F0 80066FF0 E4940024 */  swc1  $f20, 0x24($a0)
/* 0423F4 80066FF4 34630004 */  ori   $v1, $v1, 4
/* 0423F8 80066FF8 A4830000 */  sh    $v1, ($a0)
/* 0423FC 80066FFC 0C01ACF4 */  jal   __osRestoreInt
/* 042400 80067000 00402021 */   addu  $a0, $v0, $zero
/* 042404 80067004 8FBF0010 */  lw    $ra, 0x10($sp)
/* 042408 80067008 D7B40018 */  ldc1  $f20, 0x18($sp)
/* 04240C 8006700C 03E00008 */  jr    $ra
/* 042410 80067010 27BD0020 */   addiu $sp, $sp, 0x20

/* 042414 80067014 00000000 */  nop   
/* 042418 80067018 00000000 */  nop   
/* 04241C 8006701C 00000000 */  nop   



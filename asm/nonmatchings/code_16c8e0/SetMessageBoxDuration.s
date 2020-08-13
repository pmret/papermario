.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetMessageBoxDuration
/* 17FCE8 80251408 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17FCEC 8025140C AFBF0010 */  sw    $ra, 0x10($sp)
/* 17FCF0 80251410 8C82000C */  lw    $v0, 0xc($a0)
/* 17FCF4 80251414 0C0B1EAF */  jal   get_variable
/* 17FCF8 80251418 8C450000 */   lw    $a1, ($v0)
/* 17FCFC 8025141C 0C093EB1 */  jal   set_popup_duration
/* 17FD00 80251420 0040202D */   daddu $a0, $v0, $zero
/* 17FD04 80251424 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17FD08 80251428 24020002 */  addiu $v0, $zero, 2
/* 17FD0C 8025142C 03E00008 */  jr    $ra
/* 17FD10 80251430 27BD0018 */   addiu $sp, $sp, 0x18

/* 17FD14 80251434 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17FD18 80251438 AFBF0010 */  sw    $ra, 0x10($sp)
/* 17FD1C 8025143C 0C093EBA */  jal   func_8024FAE8
/* 17FD20 80251440 00000000 */   nop   
/* 17FD24 80251444 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17FD28 80251448 24020002 */  addiu $v0, $zero, 2
/* 17FD2C 8025144C 03E00008 */  jr    $ra
/* 17FD30 80251450 27BD0018 */   addiu $sp, $sp, 0x18

/* 17FD34 80251454 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17FD38 80251458 AFBF0010 */  sw    $ra, 0x10($sp)
/* 17FD3C 8025145C 0C093EBF */  jal   func_8024FAFC
/* 17FD40 80251460 00000000 */   nop   
/* 17FD44 80251464 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17FD48 80251468 24020002 */  addiu $v0, $zero, 2
/* 17FD4C 8025146C 03E00008 */  jr    $ra
/* 17FD50 80251470 27BD0018 */   addiu $sp, $sp, 0x18


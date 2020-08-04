.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel nuGfxDisplayOff
/* 03A800 8005F400 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03A804 8005F404 AFBF0010 */  sw    $ra, 0x10($sp)
/* 03A808 8005F408 3C01800A */  lui   $at, 0x800a
/* 03A80C 8005F40C AC20A5F8 */  sw    $zero, -0x5a08($at)
/* 03A810 8005F410 0C019CE0 */  jal   osViBlack
/* 03A814 8005F414 24040001 */   addiu $a0, $zero, 1
/* 03A818 8005F418 8FBF0010 */  lw    $ra, 0x10($sp)
/* 03A81C 8005F41C 03E00008 */  jr    $ra
/* 03A820 8005F420 27BD0018 */   addiu $sp, $sp, 0x18

/* 03A824 8005F424 00000000 */  nop   
/* 03A828 8005F428 00000000 */  nop   
/* 03A82C 8005F42C 00000000 */  nop   

.set reorder

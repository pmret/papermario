.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80248D78
/* 177658 80248D78 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17765C 80248D7C 3C038028 */  lui       $v1, %hi(D_802809F6)
/* 177660 80248D80 846309F6 */  lh        $v1, %lo(D_802809F6)($v1)
/* 177664 80248D84 2402FFFF */  addiu     $v0, $zero, -1
/* 177668 80248D88 1462000C */  bne       $v1, $v0, .L80248DBC
/* 17766C 80248D8C AFBF0010 */   sw       $ra, 0x10($sp)
/* 177670 80248D90 0000202D */  daddu     $a0, $zero, $zero
/* 177674 80248D94 0080282D */  daddu     $a1, $a0, $zero
/* 177678 80248D98 0080302D */  daddu     $a2, $a0, $zero
/* 17767C 80248D9C 0C04DF84 */  jal       func_80137E10
/* 177680 80248DA0 0080382D */   daddu    $a3, $a0, $zero
/* 177684 80248DA4 3C018028 */  lui       $at, %hi(D_80280A30)
/* 177688 80248DA8 C4200A30 */  lwc1      $f0, %lo(D_80280A30)($at)
/* 17768C 80248DAC 46800020 */  cvt.s.w   $f0, $f0
/* 177690 80248DB0 44050000 */  mfc1      $a1, $f0
/* 177694 80248DB4 0C04DF62 */  jal       func_80137D88
/* 177698 80248DB8 0000202D */   daddu    $a0, $zero, $zero
.L80248DBC:
/* 17769C 80248DBC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1776A0 80248DC0 03E00008 */  jr        $ra
/* 1776A4 80248DC4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 1776A8 80248DC8 00000000 */  nop
/* 1776AC 80248DCC 00000000 */  nop

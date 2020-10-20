.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_950970
/* 950970 80240000 44800000 */  mtc1      $zero, $f0
/* 950974 80240004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 950978 80240008 44050000 */  mfc1      $a1, $f0
/* 95097C 8024000C 0000202D */  daddu     $a0, $zero, $zero
/* 950980 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 950984 80240014 AFA00014 */  sw        $zero, 0x14($sp)
/* 950988 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 95098C 8024001C 00A0302D */  daddu     $a2, $a1, $zero
/* 950990 80240020 0C01CA54 */  jal       func_80072950
/* 950994 80240024 00A0382D */   daddu    $a3, $a1, $zero
/* 950998 80240028 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95099C 8024002C 24020002 */  addiu     $v0, $zero, 2
/* 9509A0 80240030 03E00008 */  jr        $ra
/* 9509A4 80240034 27BD0020 */   addiu    $sp, $sp, 0x20
/* 9509A8 80240038 00000000 */  nop       
/* 9509AC 8024003C 00000000 */  nop       

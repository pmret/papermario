.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_930CF0
/* 930CF0 80240000 44800000 */  mtc1      $zero, $f0
/* 930CF4 80240004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 930CF8 80240008 44050000 */  mfc1      $a1, $f0
/* 930CFC 8024000C 0000202D */  daddu     $a0, $zero, $zero
/* 930D00 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 930D04 80240014 AFA00014 */  sw        $zero, 0x14($sp)
/* 930D08 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 930D0C 8024001C 00A0302D */  daddu     $a2, $a1, $zero
/* 930D10 80240020 0C01CA54 */  jal       func_80072950
/* 930D14 80240024 00A0382D */   daddu    $a3, $a1, $zero
/* 930D18 80240028 8FBF0018 */  lw        $ra, 0x18($sp)
/* 930D1C 8024002C 24020002 */  addiu     $v0, $zero, 2
/* 930D20 80240030 03E00008 */  jr        $ra
/* 930D24 80240034 27BD0020 */   addiu    $sp, $sp, 0x20
/* 930D28 80240038 00000000 */  nop       
/* 930D2C 8024003C 00000000 */  nop       

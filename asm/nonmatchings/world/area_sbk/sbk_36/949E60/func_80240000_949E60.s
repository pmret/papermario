.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_949E60
/* 949E60 80240000 44800000 */  mtc1      $zero, $f0
/* 949E64 80240004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 949E68 80240008 44050000 */  mfc1      $a1, $f0
/* 949E6C 8024000C 0000202D */  daddu     $a0, $zero, $zero
/* 949E70 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 949E74 80240014 AFA00014 */  sw        $zero, 0x14($sp)
/* 949E78 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 949E7C 8024001C 00A0302D */  daddu     $a2, $a1, $zero
/* 949E80 80240020 0C01CA54 */  jal       func_80072950
/* 949E84 80240024 00A0382D */   daddu    $a3, $a1, $zero
/* 949E88 80240028 8FBF0018 */  lw        $ra, 0x18($sp)
/* 949E8C 8024002C 24020002 */  addiu     $v0, $zero, 2
/* 949E90 80240030 03E00008 */  jr        $ra
/* 949E94 80240034 27BD0020 */   addiu    $sp, $sp, 0x20
/* 949E98 80240038 00000000 */  nop       
/* 949E9C 8024003C 00000000 */  nop       

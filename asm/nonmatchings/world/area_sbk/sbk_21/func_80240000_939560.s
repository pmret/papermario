.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_939560
/* 939560 80240000 44800000 */  mtc1      $zero, $f0
/* 939564 80240004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 939568 80240008 44050000 */  mfc1      $a1, $f0
/* 93956C 8024000C 0000202D */  daddu     $a0, $zero, $zero
/* 939570 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 939574 80240014 AFA00014 */  sw        $zero, 0x14($sp)
/* 939578 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 93957C 8024001C 00A0302D */  daddu     $a2, $a1, $zero
/* 939580 80240020 0C01CA54 */  jal       func_80072950
/* 939584 80240024 00A0382D */   daddu    $a3, $a1, $zero
/* 939588 80240028 8FBF0018 */  lw        $ra, 0x18($sp)
/* 93958C 8024002C 24020002 */  addiu     $v0, $zero, 2
/* 939590 80240030 03E00008 */  jr        $ra
/* 939594 80240034 27BD0020 */   addiu    $sp, $sp, 0x20
/* 939598 80240038 00000000 */  nop       
/* 93959C 8024003C 00000000 */  nop       

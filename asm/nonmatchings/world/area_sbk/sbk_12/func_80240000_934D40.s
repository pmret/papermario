.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_934D40
/* 934D40 80240000 44800000 */  mtc1      $zero, $f0
/* 934D44 80240004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 934D48 80240008 44050000 */  mfc1      $a1, $f0
/* 934D4C 8024000C 0000202D */  daddu     $a0, $zero, $zero
/* 934D50 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 934D54 80240014 AFA00014 */  sw        $zero, 0x14($sp)
/* 934D58 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 934D5C 8024001C 00A0302D */  daddu     $a2, $a1, $zero
/* 934D60 80240020 0C01CA54 */  jal       func_80072950
/* 934D64 80240024 00A0382D */   daddu    $a3, $a1, $zero
/* 934D68 80240028 8FBF0018 */  lw        $ra, 0x18($sp)
/* 934D6C 8024002C 24020002 */  addiu     $v0, $zero, 2
/* 934D70 80240030 03E00008 */  jr        $ra
/* 934D74 80240034 27BD0020 */   addiu    $sp, $sp, 0x20
/* 934D78 80240038 00000000 */  nop       
/* 934D7C 8024003C 00000000 */  nop       

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_934040
/* 934040 80240000 44800000 */  mtc1      $zero, $f0
/* 934044 80240004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 934048 80240008 44050000 */  mfc1      $a1, $f0
/* 93404C 8024000C 0000202D */  daddu     $a0, $zero, $zero
/* 934050 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 934054 80240014 AFA00014 */  sw        $zero, 0x14($sp)
/* 934058 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 93405C 8024001C 00A0302D */  daddu     $a2, $a1, $zero
/* 934060 80240020 0C01CA54 */  jal       func_80072950
/* 934064 80240024 00A0382D */   daddu    $a3, $a1, $zero
/* 934068 80240028 8FBF0018 */  lw        $ra, 0x18($sp)
/* 93406C 8024002C 24020002 */  addiu     $v0, $zero, 2
/* 934070 80240030 03E00008 */  jr        $ra
/* 934074 80240034 27BD0020 */   addiu    $sp, $sp, 0x20
/* 934078 80240038 00000000 */  nop       
/* 93407C 8024003C 00000000 */  nop       

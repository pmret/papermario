.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_93C280
/* 93C280 80240000 44800000 */  mtc1      $zero, $f0
/* 93C284 80240004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 93C288 80240008 44050000 */  mfc1      $a1, $f0
/* 93C28C 8024000C 0000202D */  daddu     $a0, $zero, $zero
/* 93C290 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 93C294 80240014 AFA00014 */  sw        $zero, 0x14($sp)
/* 93C298 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 93C29C 8024001C 00A0302D */  daddu     $a2, $a1, $zero
/* 93C2A0 80240020 0C01CA54 */  jal       func_80072950
/* 93C2A4 80240024 00A0382D */   daddu    $a3, $a1, $zero
/* 93C2A8 80240028 8FBF0018 */  lw        $ra, 0x18($sp)
/* 93C2AC 8024002C 24020002 */  addiu     $v0, $zero, 2
/* 93C2B0 80240030 03E00008 */  jr        $ra
/* 93C2B4 80240034 27BD0020 */   addiu    $sp, $sp, 0x20
/* 93C2B8 80240038 00000000 */  nop       
/* 93C2BC 8024003C 00000000 */  nop       

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_94E9A0
/* 94E9A0 80240000 44800000 */  mtc1      $zero, $f0
/* 94E9A4 80240004 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 94E9A8 80240008 44050000 */  mfc1      $a1, $f0
/* 94E9AC 8024000C 0000202D */  daddu     $a0, $zero, $zero
/* 94E9B0 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 94E9B4 80240014 AFA00014 */  sw        $zero, 0x14($sp)
/* 94E9B8 80240018 E7A00010 */  swc1      $f0, 0x10($sp)
/* 94E9BC 8024001C 00A0302D */  daddu     $a2, $a1, $zero
/* 94E9C0 80240020 0C01CA54 */  jal       func_80072950
/* 94E9C4 80240024 00A0382D */   daddu    $a3, $a1, $zero
/* 94E9C8 80240028 8FBF0018 */  lw        $ra, 0x18($sp)
/* 94E9CC 8024002C 24020002 */  addiu     $v0, $zero, 2
/* 94E9D0 80240030 03E00008 */  jr        $ra
/* 94E9D4 80240034 27BD0020 */   addiu    $sp, $sp, 0x20
/* 94E9D8 80240038 00000000 */  nop       
/* 94E9DC 8024003C 00000000 */  nop       

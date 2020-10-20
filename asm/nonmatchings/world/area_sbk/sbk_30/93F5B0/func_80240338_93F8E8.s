.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240338_93F8E8
/* 93F8E8 80240338 44800000 */  mtc1      $zero, $f0
/* 93F8EC 8024033C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 93F8F0 80240340 44050000 */  mfc1      $a1, $f0
/* 93F8F4 80240344 0000202D */  daddu     $a0, $zero, $zero
/* 93F8F8 80240348 AFBF0018 */  sw        $ra, 0x18($sp)
/* 93F8FC 8024034C AFA00014 */  sw        $zero, 0x14($sp)
/* 93F900 80240350 E7A00010 */  swc1      $f0, 0x10($sp)
/* 93F904 80240354 00A0302D */  daddu     $a2, $a1, $zero
/* 93F908 80240358 0C01CA54 */  jal       func_80072950
/* 93F90C 8024035C 00A0382D */   daddu    $a3, $a1, $zero
/* 93F910 80240360 8FBF0018 */  lw        $ra, 0x18($sp)
/* 93F914 80240364 24020002 */  addiu     $v0, $zero, 2
/* 93F918 80240368 03E00008 */  jr        $ra
/* 93F91C 8024036C 27BD0020 */   addiu    $sp, $sp, 0x20

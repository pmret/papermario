.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_AACB3C
/* AACB3C 8024030C 44800000 */  mtc1      $zero, $f0
/* AACB40 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AACB44 80240314 44050000 */  mfc1      $a1, $f0
/* AACB48 80240318 24040001 */  addiu     $a0, $zero, 1
/* AACB4C 8024031C AFBF0018 */  sw        $ra, 0x18($sp)
/* AACB50 80240320 AFA00014 */  sw        $zero, 0x14($sp)
/* AACB54 80240324 E7A00010 */  swc1      $f0, 0x10($sp)
/* AACB58 80240328 00A0302D */  daddu     $a2, $a1, $zero
/* AACB5C 8024032C 0C01CA54 */  jal       func_80072950
/* AACB60 80240330 00A0382D */   daddu    $a3, $a1, $zero
/* AACB64 80240334 8FBF0018 */  lw        $ra, 0x18($sp)
/* AACB68 80240338 24020002 */  addiu     $v0, $zero, 2
/* AACB6C 8024033C 03E00008 */  jr        $ra
/* AACB70 80240340 27BD0020 */   addiu    $sp, $sp, 0x20

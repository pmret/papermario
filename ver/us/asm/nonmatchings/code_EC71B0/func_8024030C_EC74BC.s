.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_EC74BC
/* EC74BC 8024030C 44800000 */  mtc1      $zero, $f0
/* EC74C0 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EC74C4 80240314 44050000 */  mfc1      $a1, $f0
/* EC74C8 80240318 0000202D */  daddu     $a0, $zero, $zero
/* EC74CC 8024031C AFBF0018 */  sw        $ra, 0x18($sp)
/* EC74D0 80240320 AFA00014 */  sw        $zero, 0x14($sp)
/* EC74D4 80240324 E7A00010 */  swc1      $f0, 0x10($sp)
/* EC74D8 80240328 00A0302D */  daddu     $a2, $a1, $zero
/* EC74DC 8024032C 0C01DEF4 */  jal       func_80077BD0
/* EC74E0 80240330 00A0382D */   daddu    $a3, $a1, $zero
/* EC74E4 80240334 8FBF0018 */  lw        $ra, 0x18($sp)
/* EC74E8 80240338 24020002 */  addiu     $v0, $zero, 2
/* EC74EC 8024033C 03E00008 */  jr        $ra
/* EC74F0 80240340 27BD0020 */   addiu    $sp, $sp, 0x20

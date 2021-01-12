.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_EFEE0C
/* EFEE0C 8024030C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EFEE10 80240310 24040001 */  addiu     $a0, $zero, 1
/* EFEE14 80240314 0000282D */  daddu     $a1, $zero, $zero
/* EFEE18 80240318 00A0302D */  daddu     $a2, $a1, $zero
/* EFEE1C 8024031C 00A0382D */  daddu     $a3, $a1, $zero
/* EFEE20 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* EFEE24 80240324 AFA00010 */  sw        $zero, 0x10($sp)
/* EFEE28 80240328 0C01DEF4 */  jal       func_80077BD0
/* EFEE2C 8024032C AFA00014 */   sw       $zero, 0x14($sp)
/* EFEE30 80240330 8FBF0018 */  lw        $ra, 0x18($sp)
/* EFEE34 80240334 24020002 */  addiu     $v0, $zero, 2
/* EFEE38 80240338 03E00008 */  jr        $ra
/* EFEE3C 8024033C 27BD0020 */   addiu    $sp, $sp, 0x20

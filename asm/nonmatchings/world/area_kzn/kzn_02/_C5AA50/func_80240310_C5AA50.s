.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_C5AA50
/* C5AA50 80240310 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C5AA54 80240314 AFB00038 */  sw        $s0, 0x38($sp)
/* C5AA58 80240318 0080802D */  daddu     $s0, $a0, $zero
/* C5AA5C 8024031C AFBF003C */  sw        $ra, 0x3c($sp)
/* C5AA60 80240320 8E02000C */  lw        $v0, 0xc($s0)
/* C5AA64 80240324 0C0B1EAF */  jal       get_variable
/* C5AA68 80240328 8C450000 */   lw       $a1, ($v0)
/* C5AA6C 8024032C 3044FFFF */  andi      $a0, $v0, 0xffff
/* C5AA70 80240330 27A50020 */  addiu     $a1, $sp, 0x20
/* C5AA74 80240334 27A2002C */  addiu     $v0, $sp, 0x2c
/* C5AA78 80240338 AFA20010 */  sw        $v0, 0x10($sp)
/* C5AA7C 8024033C 27A20030 */  addiu     $v0, $sp, 0x30
/* C5AA80 80240340 AFA20014 */  sw        $v0, 0x14($sp)
/* C5AA84 80240344 27A20034 */  addiu     $v0, $sp, 0x34
/* C5AA88 80240348 27A60024 */  addiu     $a2, $sp, 0x24
/* C5AA8C 8024034C 27A70028 */  addiu     $a3, $sp, 0x28
/* C5AA90 80240350 0C046C3B */  jal       get_model_center_and_size
/* C5AA94 80240354 AFA20018 */   sw       $v0, 0x18($sp)
/* C5AA98 80240358 C7A00020 */  lwc1      $f0, 0x20($sp)
/* C5AA9C 8024035C C7A20028 */  lwc1      $f2, 0x28($sp)
/* C5AAA0 80240360 4600010D */  trunc.w.s $f4, $f0
/* C5AAA4 80240364 E60400A0 */  swc1      $f4, 0xa0($s0)
/* C5AAA8 80240368 4600110D */  trunc.w.s $f4, $f2
/* C5AAAC 8024036C E60400A4 */  swc1      $f4, 0xa4($s0)
/* C5AAB0 80240370 8FBF003C */  lw        $ra, 0x3c($sp)
/* C5AAB4 80240374 8FB00038 */  lw        $s0, 0x38($sp)
/* C5AAB8 80240378 24020002 */  addiu     $v0, $zero, 2
/* C5AABC 8024037C 03E00008 */  jr        $ra
/* C5AAC0 80240380 27BD0040 */   addiu    $sp, $sp, 0x40

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240314
/* 8FF984 80240314 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8FF988 80240318 AFB10014 */  sw        $s1, 0x14($sp)
/* 8FF98C 8024031C 0080882D */  daddu     $s1, $a0, $zero
/* 8FF990 80240320 AFBF0024 */  sw        $ra, 0x24($sp)
/* 8FF994 80240324 AFB40020 */  sw        $s4, 0x20($sp)
/* 8FF998 80240328 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8FF99C 8024032C AFB20018 */  sw        $s2, 0x18($sp)
/* 8FF9A0 80240330 AFB00010 */  sw        $s0, 0x10($sp)
/* 8FF9A4 80240334 8E30000C */  lw        $s0, 0xc($s1)
/* 8FF9A8 80240338 8E050000 */  lw        $a1, ($s0)
/* 8FF9AC 8024033C 0C0B1EAF */  jal       get_variable
/* 8FF9B0 80240340 26100004 */   addiu    $s0, $s0, 4
/* 8FF9B4 80240344 8E050000 */  lw        $a1, ($s0)
/* 8FF9B8 80240348 26100004 */  addiu     $s0, $s0, 4
/* 8FF9BC 8024034C 0220202D */  daddu     $a0, $s1, $zero
/* 8FF9C0 80240350 0C0B1EAF */  jal       get_variable
/* 8FF9C4 80240354 0040982D */   daddu    $s3, $v0, $zero
/* 8FF9C8 80240358 8E050000 */  lw        $a1, ($s0)
/* 8FF9CC 8024035C 26100004 */  addiu     $s0, $s0, 4
/* 8FF9D0 80240360 0220202D */  daddu     $a0, $s1, $zero
/* 8FF9D4 80240364 0C0B1EAF */  jal       get_variable
/* 8FF9D8 80240368 0040902D */   daddu    $s2, $v0, $zero
/* 8FF9DC 8024036C 8E050000 */  lw        $a1, ($s0)
/* 8FF9E0 80240370 26100004 */  addiu     $s0, $s0, 4
/* 8FF9E4 80240374 0220202D */  daddu     $a0, $s1, $zero
/* 8FF9E8 80240378 0C0B1EAF */  jal       get_variable
/* 8FF9EC 8024037C 0040A02D */   daddu    $s4, $v0, $zero
/* 8FF9F0 80240380 0220202D */  daddu     $a0, $s1, $zero
/* 8FF9F4 80240384 8E050000 */  lw        $a1, ($s0)
/* 8FF9F8 80240388 0C0B1EAF */  jal       get_variable
/* 8FF9FC 8024038C 0040882D */   daddu    $s1, $v0, $zero
/* 8FFA00 80240390 0000202D */  daddu     $a0, $zero, $zero
/* 8FFA04 80240394 3C05FD05 */  lui       $a1, 0xfd05
/* 8FFA08 80240398 34A50F80 */  ori       $a1, $a1, 0xf80
/* 8FFA0C 8024039C 0C0B1EAF */  jal       get_variable
/* 8FFA10 802403A0 0040802D */   daddu    $s0, $v0, $zero
/* 8FFA14 802403A4 00131900 */  sll       $v1, $s3, 4
/* 8FFA18 802403A8 00731823 */  subu      $v1, $v1, $s3
/* 8FFA1C 802403AC 00031940 */  sll       $v1, $v1, 5
/* 8FFA20 802403B0 00432021 */  addu      $a0, $v0, $v1
/* 8FFA24 802403B4 24020002 */  addiu     $v0, $zero, 2
/* 8FFA28 802403B8 00121840 */  sll       $v1, $s2, 1
/* 8FFA2C 802403BC 00721821 */  addu      $v1, $v1, $s2
/* 8FFA30 802403C0 00431804 */  sllv      $v1, $v1, $v0
/* 8FFA34 802403C4 00832021 */  addu      $a0, $a0, $v1
/* 8FFA38 802403C8 44940000 */  mtc1      $s4, $f0
/* 8FFA3C 802403CC 00000000 */  nop       
/* 8FFA40 802403D0 46800020 */  cvt.s.w   $f0, $f0
/* 8FFA44 802403D4 E4800000 */  swc1      $f0, ($a0)
/* 8FFA48 802403D8 44910000 */  mtc1      $s1, $f0
/* 8FFA4C 802403DC 00000000 */  nop       
/* 8FFA50 802403E0 46800020 */  cvt.s.w   $f0, $f0
/* 8FFA54 802403E4 E4800004 */  swc1      $f0, 4($a0)
/* 8FFA58 802403E8 44900000 */  mtc1      $s0, $f0
/* 8FFA5C 802403EC 00000000 */  nop       
/* 8FFA60 802403F0 46800020 */  cvt.s.w   $f0, $f0
/* 8FFA64 802403F4 E4800008 */  swc1      $f0, 8($a0)
/* 8FFA68 802403F8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 8FFA6C 802403FC 8FB40020 */  lw        $s4, 0x20($sp)
/* 8FFA70 80240400 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8FFA74 80240404 8FB20018 */  lw        $s2, 0x18($sp)
/* 8FFA78 80240408 8FB10014 */  lw        $s1, 0x14($sp)
/* 8FFA7C 8024040C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8FFA80 80240410 03E00008 */  jr        $ra
/* 8FFA84 80240414 27BD0028 */   addiu    $sp, $sp, 0x28

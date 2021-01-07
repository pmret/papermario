.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240314_9EDF04
/* 9EDF04 80240314 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9EDF08 80240318 AFB10014 */  sw        $s1, 0x14($sp)
/* 9EDF0C 8024031C 0080882D */  daddu     $s1, $a0, $zero
/* 9EDF10 80240320 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9EDF14 80240324 AFB20018 */  sw        $s2, 0x18($sp)
/* 9EDF18 80240328 AFB00010 */  sw        $s0, 0x10($sp)
/* 9EDF1C 8024032C 8E30000C */  lw        $s0, 0xc($s1)
/* 9EDF20 80240330 8E050000 */  lw        $a1, ($s0)
/* 9EDF24 80240334 0C0B1EAF */  jal       get_variable
/* 9EDF28 80240338 26100004 */   addiu    $s0, $s0, 4
/* 9EDF2C 8024033C 8E050000 */  lw        $a1, ($s0)
/* 9EDF30 80240340 26100004 */  addiu     $s0, $s0, 4
/* 9EDF34 80240344 0220202D */  daddu     $a0, $s1, $zero
/* 9EDF38 80240348 0C0B1EAF */  jal       get_variable
/* 9EDF3C 8024034C 0040902D */   daddu    $s2, $v0, $zero
/* 9EDF40 80240350 0220202D */  daddu     $a0, $s1, $zero
/* 9EDF44 80240354 8E050000 */  lw        $a1, ($s0)
/* 9EDF48 80240358 0C0B1EAF */  jal       get_variable
/* 9EDF4C 8024035C 0040802D */   daddu    $s0, $v0, $zero
/* 9EDF50 80240360 44823000 */  mtc1      $v0, $f6
/* 9EDF54 80240364 00000000 */  nop       
/* 9EDF58 80240368 468031A0 */  cvt.s.w   $f6, $f6
/* 9EDF5C 8024036C 3C038024 */  lui       $v1, %hi(D_802413F8)
/* 9EDF60 80240370 246313F8 */  addiu     $v1, $v1, %lo(D_802413F8)
/* 9EDF64 80240374 44922000 */  mtc1      $s2, $f4
/* 9EDF68 80240378 00000000 */  nop       
/* 9EDF6C 8024037C 46802120 */  cvt.s.w   $f4, $f4
/* 9EDF70 80240380 3C014080 */  lui       $at, 0x4080
/* 9EDF74 80240384 44811000 */  mtc1      $at, $f2
/* 9EDF78 80240388 44900000 */  mtc1      $s0, $f0
/* 9EDF7C 8024038C 00000000 */  nop       
/* 9EDF80 80240390 46800020 */  cvt.s.w   $f0, $f0
/* 9EDF84 80240394 46020000 */  add.s     $f0, $f0, $f2
/* 9EDF88 80240398 E4640000 */  swc1      $f4, ($v1)
/* 9EDF8C 8024039C E4660008 */  swc1      $f6, 8($v1)
/* 9EDF90 802403A0 E4600004 */  swc1      $f0, 4($v1)
/* 9EDF94 802403A4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9EDF98 802403A8 8FB20018 */  lw        $s2, 0x18($sp)
/* 9EDF9C 802403AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9EDFA0 802403B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9EDFA4 802403B4 24020002 */  addiu     $v0, $zero, 2
/* 9EDFA8 802403B8 03E00008 */  jr        $ra
/* 9EDFAC 802403BC 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241310_D59BA0
/* D59BA0 80241310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D59BA4 80241314 AFB10014 */  sw        $s1, 0x14($sp)
/* D59BA8 80241318 0080882D */  daddu     $s1, $a0, $zero
/* D59BAC 8024131C AFBF001C */  sw        $ra, 0x1c($sp)
/* D59BB0 80241320 AFB20018 */  sw        $s2, 0x18($sp)
/* D59BB4 80241324 AFB00010 */  sw        $s0, 0x10($sp)
/* D59BB8 80241328 8E30000C */  lw        $s0, 0xc($s1)
/* D59BBC 8024132C 8E050000 */  lw        $a1, ($s0)
/* D59BC0 80241330 0C0B1EAF */  jal       evt_get_variable
/* D59BC4 80241334 26100004 */   addiu    $s0, $s0, 4
/* D59BC8 80241338 8E050000 */  lw        $a1, ($s0)
/* D59BCC 8024133C 26100004 */  addiu     $s0, $s0, 4
/* D59BD0 80241340 0220202D */  daddu     $a0, $s1, $zero
/* D59BD4 80241344 0C0B1EAF */  jal       evt_get_variable
/* D59BD8 80241348 0040902D */   daddu    $s2, $v0, $zero
/* D59BDC 8024134C 0220202D */  daddu     $a0, $s1, $zero
/* D59BE0 80241350 8E050000 */  lw        $a1, ($s0)
/* D59BE4 80241354 0C0B1EAF */  jal       evt_get_variable
/* D59BE8 80241358 0040802D */   daddu    $s0, $v0, $zero
/* D59BEC 8024135C 44926000 */  mtc1      $s2, $f12
/* D59BF0 80241360 00000000 */  nop
/* D59BF4 80241364 46806320 */  cvt.s.w   $f12, $f12
/* D59BF8 80241368 44820000 */  mtc1      $v0, $f0
/* D59BFC 8024136C 00000000 */  nop
/* D59C00 80241370 46800020 */  cvt.s.w   $f0, $f0
/* D59C04 80241374 44060000 */  mfc1      $a2, $f0
/* D59C08 80241378 44907000 */  mtc1      $s0, $f14
/* D59C0C 8024137C 00000000 */  nop
/* D59C10 80241380 0C01BE3C */  jal       playFX_01
/* D59C14 80241384 468073A0 */   cvt.s.w  $f14, $f14
/* D59C18 80241388 8FBF001C */  lw        $ra, 0x1c($sp)
/* D59C1C 8024138C 8FB20018 */  lw        $s2, 0x18($sp)
/* D59C20 80241390 8FB10014 */  lw        $s1, 0x14($sp)
/* D59C24 80241394 8FB00010 */  lw        $s0, 0x10($sp)
/* D59C28 80241398 24020002 */  addiu     $v0, $zero, 2
/* D59C2C 8024139C 03E00008 */  jr        $ra
/* D59C30 802413A0 27BD0020 */   addiu    $sp, $sp, 0x20

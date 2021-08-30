.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BD8_8333D8
/* 8333D8 80241BD8 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 8333DC 80241BDC AFB10014 */  sw        $s1, 0x14($sp)
/* 8333E0 80241BE0 0080882D */  daddu     $s1, $a0, $zero
/* 8333E4 80241BE4 3C05FD05 */  lui       $a1, 0xfd05
/* 8333E8 80241BE8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8333EC 80241BEC AFB3001C */  sw        $s3, 0x1c($sp)
/* 8333F0 80241BF0 AFB20018 */  sw        $s2, 0x18($sp)
/* 8333F4 80241BF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8333F8 80241BF8 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 8333FC 80241BFC F7B60030 */  sdc1      $f22, 0x30($sp)
/* 833400 80241C00 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 833404 80241C04 0C0B1EAF */  jal       evt_get_variable
/* 833408 80241C08 34A50F82 */   ori      $a1, $a1, 0xf82
/* 83340C 80241C0C 0220202D */  daddu     $a0, $s1, $zero
/* 833410 80241C10 8E30000C */  lw        $s0, 0xc($s1)
/* 833414 80241C14 0040982D */  daddu     $s3, $v0, $zero
/* 833418 80241C18 8E050000 */  lw        $a1, ($s0)
/* 83341C 80241C1C 0C0B1EAF */  jal       evt_get_variable
/* 833420 80241C20 26100004 */   addiu    $s0, $s0, 4
/* 833424 80241C24 8E050000 */  lw        $a1, ($s0)
/* 833428 80241C28 26100004 */  addiu     $s0, $s0, 4
/* 83342C 80241C2C 0220202D */  daddu     $a0, $s1, $zero
/* 833430 80241C30 0C0B1EAF */  jal       evt_get_variable
/* 833434 80241C34 0040902D */   daddu    $s2, $v0, $zero
/* 833438 80241C38 8E050000 */  lw        $a1, ($s0)
/* 83343C 80241C3C 26100004 */  addiu     $s0, $s0, 4
/* 833440 80241C40 4482C000 */  mtc1      $v0, $f24
/* 833444 80241C44 00000000 */  nop
/* 833448 80241C48 4680C620 */  cvt.s.w   $f24, $f24
/* 83344C 80241C4C 0C0B1EAF */  jal       evt_get_variable
/* 833450 80241C50 0220202D */   daddu    $a0, $s1, $zero
/* 833454 80241C54 8E050000 */  lw        $a1, ($s0)
/* 833458 80241C58 26100004 */  addiu     $s0, $s0, 4
/* 83345C 80241C5C 4482B000 */  mtc1      $v0, $f22
/* 833460 80241C60 00000000 */  nop
/* 833464 80241C64 4680B5A0 */  cvt.s.w   $f22, $f22
/* 833468 80241C68 0C0B1EAF */  jal       evt_get_variable
/* 83346C 80241C6C 0220202D */   daddu    $a0, $s1, $zero
/* 833470 80241C70 8E050000 */  lw        $a1, ($s0)
/* 833474 80241C74 4482A000 */  mtc1      $v0, $f20
/* 833478 80241C78 00000000 */  nop
/* 83347C 80241C7C 4680A520 */  cvt.s.w   $f20, $f20
/* 833480 80241C80 0C0B1EAF */  jal       evt_get_variable
/* 833484 80241C84 0220202D */   daddu    $a0, $s1, $zero
/* 833488 80241C88 8E63000C */  lw        $v1, 0xc($s3)
/* 83348C 80241C8C 00129080 */  sll       $s2, $s2, 2
/* 833490 80241C90 00721821 */  addu      $v1, $v1, $s2
/* 833494 80241C94 E4780034 */  swc1      $f24, 0x34($v1)
/* 833498 80241C98 8E63000C */  lw        $v1, 0xc($s3)
/* 83349C 80241C9C 00721821 */  addu      $v1, $v1, $s2
/* 8334A0 80241CA0 E4760060 */  swc1      $f22, 0x60($v1)
/* 8334A4 80241CA4 8E63000C */  lw        $v1, 0xc($s3)
/* 8334A8 80241CA8 00721821 */  addu      $v1, $v1, $s2
/* 8334AC 80241CAC E474008C */  swc1      $f20, 0x8c($v1)
/* 8334B0 80241CB0 8E63000C */  lw        $v1, 0xc($s3)
/* 8334B4 80241CB4 44820000 */  mtc1      $v0, $f0
/* 8334B8 80241CB8 00000000 */  nop
/* 8334BC 80241CBC 46800020 */  cvt.s.w   $f0, $f0
/* 8334C0 80241CC0 00721821 */  addu      $v1, $v1, $s2
/* 8334C4 80241CC4 E46000B8 */  swc1      $f0, 0xb8($v1)
/* 8334C8 80241CC8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8334CC 80241CCC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8334D0 80241CD0 8FB20018 */  lw        $s2, 0x18($sp)
/* 8334D4 80241CD4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8334D8 80241CD8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8334DC 80241CDC D7B80038 */  ldc1      $f24, 0x38($sp)
/* 8334E0 80241CE0 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 8334E4 80241CE4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 8334E8 80241CE8 24020002 */  addiu     $v0, $zero, 2
/* 8334EC 80241CEC 03E00008 */  jr        $ra
/* 8334F0 80241CF0 27BD0040 */   addiu    $sp, $sp, 0x40
/* 8334F4 80241CF4 00000000 */  nop
/* 8334F8 80241CF8 00000000 */  nop
/* 8334FC 80241CFC 00000000 */  nop

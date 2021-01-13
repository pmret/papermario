.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238A6C_70C77C
/* 70C77C 80238A6C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 70C780 80238A70 3C03800E */  lui       $v1, %hi(gBattleStatus+0xDC)
/* 70C784 80238A74 8C63C14C */  lw        $v1, %lo(gBattleStatus+0xDC)($v1)
/* 70C788 80238A78 3C0140A0 */  lui       $at, 0x40a0
/* 70C78C 80238A7C 44810000 */  mtc1      $at, $f0
/* 70C790 80238A80 2404008C */  addiu     $a0, $zero, 0x8c
/* 70C794 80238A84 AFBF0028 */  sw        $ra, 0x28($sp)
/* 70C798 80238A88 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 70C79C 80238A8C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 70C7A0 80238A90 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 70C7A4 80238A94 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 70C7A8 80238A98 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 70C7AC 80238A9C C4780144 */  lwc1      $f24, 0x144($v1)
/* 70C7B0 80238AA0 90620191 */  lbu       $v0, 0x191($v1)
/* 70C7B4 80238AA4 4600C600 */  add.s     $f24, $f24, $f0
/* 70C7B8 80238AA8 C4760148 */  lwc1      $f22, 0x148($v1)
/* 70C7BC 80238AAC 44820000 */  mtc1      $v0, $f0
/* 70C7C0 80238AB0 00000000 */  nop
/* 70C7C4 80238AB4 46800020 */  cvt.s.w   $f0, $f0
/* 70C7C8 80238AB8 4600B580 */  add.s     $f22, $f22, $f0
/* 70C7CC 80238ABC 3C0141A0 */  lui       $at, 0x41a0
/* 70C7D0 80238AC0 4481D000 */  mtc1      $at, $f26
/* 70C7D4 80238AC4 C47C014C */  lwc1      $f28, 0x14c($v1)
/* 70C7D8 80238AC8 0C00A67F */  jal       rand_int
/* 70C7DC 80238ACC 461AB580 */   add.s    $f22, $f22, $f26
/* 70C7E0 80238AD0 2442000A */  addiu     $v0, $v0, 0xa
/* 70C7E4 80238AD4 4482A000 */  mtc1      $v0, $f20
/* 70C7E8 80238AD8 00000000 */  nop
/* 70C7EC 80238ADC 4680A520 */  cvt.s.w   $f20, $f20
/* 70C7F0 80238AE0 0C00A67F */  jal       rand_int
/* 70C7F4 80238AE4 24040050 */   addiu    $a0, $zero, 0x50
/* 70C7F8 80238AE8 0000202D */  daddu     $a0, $zero, $zero
/* 70C7FC 80238AEC 2442000A */  addiu     $v0, $v0, 0xa
/* 70C800 80238AF0 44820000 */  mtc1      $v0, $f0
/* 70C804 80238AF4 00000000 */  nop
/* 70C808 80238AF8 46800020 */  cvt.s.w   $f0, $f0
/* 70C80C 80238AFC E7A00014 */  swc1      $f0, 0x14($sp)
/* 70C810 80238B00 3C013FC0 */  lui       $at, 0x3fc0
/* 70C814 80238B04 44810000 */  mtc1      $at, $f0
/* 70C818 80238B08 4405C000 */  mfc1      $a1, $f24
/* 70C81C 80238B0C 4407E000 */  mfc1      $a3, $f28
/* 70C820 80238B10 4406B000 */  mfc1      $a2, $f22
/* 70C824 80238B14 2402001E */  addiu     $v0, $zero, 0x1e
/* 70C828 80238B18 E7B40010 */  swc1      $f20, 0x10($sp)
/* 70C82C 80238B1C E7BA0018 */  swc1      $f26, 0x18($sp)
/* 70C830 80238B20 AFA20020 */  sw        $v0, 0x20($sp)
/* 70C834 80238B24 0C01C784 */  jal       func_80071E10
/* 70C838 80238B28 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 70C83C 80238B2C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 70C840 80238B30 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 70C844 80238B34 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 70C848 80238B38 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 70C84C 80238B3C D7B60038 */  ldc1      $f22, 0x38($sp)
/* 70C850 80238B40 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 70C854 80238B44 24020002 */  addiu     $v0, $zero, 2
/* 70C858 80238B48 03E00008 */  jr        $ra
/* 70C85C 80238B4C 27BD0058 */   addiu    $sp, $sp, 0x58

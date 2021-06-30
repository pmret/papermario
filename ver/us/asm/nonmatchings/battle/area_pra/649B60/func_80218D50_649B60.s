.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D50_649B60
/* 649B60 80218D50 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 649B64 80218D54 AFB10024 */  sw        $s1, 0x24($sp)
/* 649B68 80218D58 0080882D */  daddu     $s1, $a0, $zero
/* 649B6C 80218D5C AFBF0028 */  sw        $ra, 0x28($sp)
/* 649B70 80218D60 AFB00020 */  sw        $s0, 0x20($sp)
/* 649B74 80218D64 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 649B78 80218D68 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 649B7C 80218D6C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 649B80 80218D70 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 649B84 80218D74 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 649B88 80218D78 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 649B8C 80218D7C 8E30000C */  lw        $s0, 0xc($s1)
/* 649B90 80218D80 8E050000 */  lw        $a1, ($s0)
/* 649B94 80218D84 0C0B210B */  jal       get_float_variable
/* 649B98 80218D88 26100004 */   addiu    $s0, $s0, 4
/* 649B9C 80218D8C 8E050000 */  lw        $a1, ($s0)
/* 649BA0 80218D90 26100004 */  addiu     $s0, $s0, 4
/* 649BA4 80218D94 0220202D */  daddu     $a0, $s1, $zero
/* 649BA8 80218D98 0C0B210B */  jal       get_float_variable
/* 649BAC 80218D9C 46000786 */   mov.s    $f30, $f0
/* 649BB0 80218DA0 8E050000 */  lw        $a1, ($s0)
/* 649BB4 80218DA4 26100004 */  addiu     $s0, $s0, 4
/* 649BB8 80218DA8 0220202D */  daddu     $a0, $s1, $zero
/* 649BBC 80218DAC 0C0B210B */  jal       get_float_variable
/* 649BC0 80218DB0 46000506 */   mov.s    $f20, $f0
/* 649BC4 80218DB4 8E050000 */  lw        $a1, ($s0)
/* 649BC8 80218DB8 26100004 */  addiu     $s0, $s0, 4
/* 649BCC 80218DBC 0220202D */  daddu     $a0, $s1, $zero
/* 649BD0 80218DC0 0C0B210B */  jal       get_float_variable
/* 649BD4 80218DC4 46000706 */   mov.s    $f28, $f0
/* 649BD8 80218DC8 8E050000 */  lw        $a1, ($s0)
/* 649BDC 80218DCC 26100004 */  addiu     $s0, $s0, 4
/* 649BE0 80218DD0 0220202D */  daddu     $a0, $s1, $zero
/* 649BE4 80218DD4 0C0B210B */  jal       get_float_variable
/* 649BE8 80218DD8 46000686 */   mov.s    $f26, $f0
/* 649BEC 80218DDC 8E050000 */  lw        $a1, ($s0)
/* 649BF0 80218DE0 26100004 */  addiu     $s0, $s0, 4
/* 649BF4 80218DE4 0220202D */  daddu     $a0, $s1, $zero
/* 649BF8 80218DE8 0C0B210B */  jal       get_float_variable
/* 649BFC 80218DEC 46000606 */   mov.s    $f24, $f0
/* 649C00 80218DF0 0220202D */  daddu     $a0, $s1, $zero
/* 649C04 80218DF4 8E050000 */  lw        $a1, ($s0)
/* 649C08 80218DF8 0C0B1EAF */  jal       get_variable
/* 649C0C 80218DFC 46000586 */   mov.s    $f22, $f0
/* 649C10 80218E00 8E240148 */  lw        $a0, 0x148($s1)
/* 649C14 80218E04 0C09A75B */  jal       get_actor
/* 649C18 80218E08 0040802D */   daddu    $s0, $v0, $zero
/* 649C1C 80218E0C 4600A521 */  cvt.d.s   $f20, $f20
/* 649C20 80218E10 4405F000 */  mfc1      $a1, $f30
/* 649C24 80218E14 3C014014 */  lui       $at, 0x4014
/* 649C28 80218E18 44810800 */  mtc1      $at, $f1
/* 649C2C 80218E1C 44800000 */  mtc1      $zero, $f0
/* 649C30 80218E20 4407E000 */  mfc1      $a3, $f28
/* 649C34 80218E24 4620A500 */  add.d     $f20, $f20, $f0
/* 649C38 80218E28 0000202D */  daddu     $a0, $zero, $zero
/* 649C3C 80218E2C AFB0001C */  sw        $s0, 0x1c($sp)
/* 649C40 80218E30 4620A520 */  cvt.s.d   $f20, $f20
/* 649C44 80218E34 4406A000 */  mfc1      $a2, $f20
/* 649C48 80218E38 0040802D */  daddu     $s0, $v0, $zero
/* 649C4C 80218E3C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 649C50 80218E40 E7B80014 */  swc1      $f24, 0x14($sp)
/* 649C54 80218E44 0C01BFD4 */  jal       playFX_12
/* 649C58 80218E48 E7B60018 */   swc1     $f22, 0x18($sp)
/* 649C5C 80218E4C 0040202D */  daddu     $a0, $v0, $zero
/* 649C60 80218E50 82030210 */  lb        $v1, 0x210($s0)
/* 649C64 80218E54 2402000A */  addiu     $v0, $zero, 0xa
/* 649C68 80218E58 14620007 */  bne       $v1, $v0, .L80218E78
/* 649C6C 80218E5C 00000000 */   nop
/* 649C70 80218E60 8C82000C */  lw        $v0, 0xc($a0)
/* 649C74 80218E64 3C013ECC */  lui       $at, 0x3ecc
/* 649C78 80218E68 3421CCCD */  ori       $at, $at, 0xcccd
/* 649C7C 80218E6C 44810000 */  mtc1      $at, $f0
/* 649C80 80218E70 00000000 */  nop
/* 649C84 80218E74 E4400028 */  swc1      $f0, 0x28($v0)
.L80218E78:
/* 649C88 80218E78 8FBF0028 */  lw        $ra, 0x28($sp)
/* 649C8C 80218E7C 8FB10024 */  lw        $s1, 0x24($sp)
/* 649C90 80218E80 8FB00020 */  lw        $s0, 0x20($sp)
/* 649C94 80218E84 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 649C98 80218E88 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 649C9C 80218E8C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 649CA0 80218E90 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 649CA4 80218E94 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 649CA8 80218E98 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 649CAC 80218E9C 24020002 */  addiu     $v0, $zero, 2
/* 649CB0 80218EA0 03E00008 */  jr        $ra
/* 649CB4 80218EA4 27BD0060 */   addiu    $sp, $sp, 0x60

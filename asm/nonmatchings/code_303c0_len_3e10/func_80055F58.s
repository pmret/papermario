.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055F58
/* 31358 80055F58 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3135C 80055F5C AFB00018 */  sw        $s0, 0x18($sp)
/* 31360 80055F60 00A0802D */  daddu     $s0, $a1, $zero
/* 31364 80055F64 AFB1001C */  sw        $s1, 0x1c($sp)
/* 31368 80055F68 00C0882D */  daddu     $s1, $a2, $zero
/* 3136C 80055F6C 27A50010 */  addiu     $a1, $sp, 0x10
/* 31370 80055F70 27A60014 */  addiu     $a2, $sp, 0x14
/* 31374 80055F74 AFBF0024 */  sw        $ra, 0x24($sp)
/* 31378 80055F78 0C01573A */  jal       func_80055CE8
/* 3137C 80055F7C AFB20020 */   sw       $s2, 0x20($sp)
/* 31380 80055F80 0040902D */  daddu     $s2, $v0, $zero
/* 31384 80055F84 1640000D */  bnez      $s2, .L80055FBC
/* 31388 80055F88 0240102D */   daddu    $v0, $s2, $zero
/* 3138C 80055F8C 2E220080 */  sltiu     $v0, $s1, 0x80
/* 31390 80055F90 50400001 */  beql      $v0, $zero, .L80055F98
/* 31394 80055F94 2411007F */   addiu    $s1, $zero, 0x7f
.L80055F98:
/* 31398 80055F98 2E020010 */  sltiu     $v0, $s0, 0x10
/* 3139C 80055F9C 50400001 */  beql      $v0, $zero, .L80055FA4
/* 313A0 80055FA0 2410000F */   addiu    $s0, $zero, 0xf
.L80055FA4:
/* 313A4 80055FA4 8FA40014 */  lw        $a0, 0x14($sp)
/* 313A8 80055FA8 0200282D */  daddu     $a1, $s0, $zero
/* 313AC 80055FAC 24060060 */  addiu     $a2, $zero, 0x60
/* 313B0 80055FB0 0C01420F */  jal       func_8005083C
/* 313B4 80055FB4 322700FF */   andi     $a3, $s1, 0xff
/* 313B8 80055FB8 0240102D */  daddu     $v0, $s2, $zero
.L80055FBC:
/* 313BC 80055FBC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 313C0 80055FC0 8FB20020 */  lw        $s2, 0x20($sp)
/* 313C4 80055FC4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 313C8 80055FC8 8FB00018 */  lw        $s0, 0x18($sp)
/* 313CC 80055FCC 03E00008 */  jr        $ra
/* 313D0 80055FD0 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055C08
/* 31008 80055C08 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3100C 80055C0C AFB00018 */  sw        $s0, 0x18($sp)
/* 31010 80055C10 00A0802D */  daddu     $s0, $a1, $zero
/* 31014 80055C14 AFB1001C */  sw        $s1, 0x1c($sp)
/* 31018 80055C18 00C0882D */  daddu     $s1, $a2, $zero
/* 3101C 80055C1C 27A50010 */  addiu     $a1, $sp, 0x10
/* 31020 80055C20 27A60014 */  addiu     $a2, $sp, 0x14
/* 31024 80055C24 AFBF0024 */  sw        $ra, 0x24($sp)
/* 31028 80055C28 0C015666 */  jal       func_80055998
/* 3102C 80055C2C AFB20020 */   sw       $s2, 0x20($sp)
/* 31030 80055C30 0040902D */  daddu     $s2, $v0, $zero
/* 31034 80055C34 1640000D */  bnez      $s2, .L80055C6C
/* 31038 80055C38 0240102D */   daddu    $v0, $s2, $zero
/* 3103C 80055C3C 2E220080 */  sltiu     $v0, $s1, 0x80
/* 31040 80055C40 50400001 */  beql      $v0, $zero, .L80055C48
/* 31044 80055C44 2411007F */   addiu    $s1, $zero, 0x7f
.L80055C48:
/* 31048 80055C48 2E020010 */  sltiu     $v0, $s0, 0x10
/* 3104C 80055C4C 50400001 */  beql      $v0, $zero, .L80055C54
/* 31050 80055C50 2410000F */   addiu    $s0, $zero, 0xf
.L80055C54:
/* 31054 80055C54 8FA40014 */  lw        $a0, 0x14($sp)
/* 31058 80055C58 0200282D */  daddu     $a1, $s0, $zero
/* 3105C 80055C5C 24060060 */  addiu     $a2, $zero, 0x60
/* 31060 80055C60 0C01413B */  jal       func_800504EC
/* 31064 80055C64 322700FF */   andi     $a3, $s1, 0xff
/* 31068 80055C68 0240102D */  daddu     $v0, $s2, $zero
.L80055C6C:
/* 3106C 80055C6C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 31070 80055C70 8FB20020 */  lw        $s2, 0x20($sp)
/* 31074 80055C74 8FB1001C */  lw        $s1, 0x1c($sp)
/* 31078 80055C78 8FB00018 */  lw        $s0, 0x18($sp)
/* 3107C 80055C7C 03E00008 */  jr        $ra
/* 31080 80055C80 27BD0028 */   addiu    $sp, $sp, 0x28

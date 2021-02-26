.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055AF8
/* 30EF8 80055AF8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 30EFC 80055AFC AFB1001C */  sw        $s1, 0x1c($sp)
/* 30F00 80055B00 00A0882D */  daddu     $s1, $a1, $zero
/* 30F04 80055B04 27A50010 */  addiu     $a1, $sp, 0x10
/* 30F08 80055B08 27A60014 */  addiu     $a2, $sp, 0x14
/* 30F0C 80055B0C AFBF0020 */  sw        $ra, 0x20($sp)
/* 30F10 80055B10 0C015666 */  jal       func_80055998
/* 30F14 80055B14 AFB00018 */   sw       $s0, 0x18($sp)
/* 30F18 80055B18 0040802D */  daddu     $s0, $v0, $zero
/* 30F1C 80055B1C 1600000C */  bnez      $s0, .L80055B50
/* 30F20 80055B20 0200102D */   daddu    $v0, $s0, $zero
/* 30F24 80055B24 0C0156D9 */  jal       func_80055B64
/* 30F28 80055B28 0220202D */   daddu    $a0, $s1, $zero
/* 30F2C 80055B2C 10400006 */  beqz      $v0, .L80055B48
/* 30F30 80055B30 0040282D */   daddu    $a1, $v0, $zero
/* 30F34 80055B34 8FA40014 */  lw        $a0, 0x14($sp)
/* 30F38 80055B38 0C01414B */  jal       func_8005052C
/* 30F3C 80055B3C 0000302D */   daddu    $a2, $zero, $zero
/* 30F40 80055B40 080156D4 */  j         .L80055B50
/* 30F44 80055B44 0200102D */   daddu    $v0, $s0, $zero
.L80055B48:
/* 30F48 80055B48 2410000B */  addiu     $s0, $zero, 0xb
/* 30F4C 80055B4C 0200102D */  daddu     $v0, $s0, $zero
.L80055B50:
/* 30F50 80055B50 8FBF0020 */  lw        $ra, 0x20($sp)
/* 30F54 80055B54 8FB1001C */  lw        $s1, 0x1c($sp)
/* 30F58 80055B58 8FB00018 */  lw        $s0, 0x18($sp)
/* 30F5C 80055B5C 03E00008 */  jr        $ra
/* 30F60 80055B60 27BD0028 */   addiu    $sp, $sp, 0x28

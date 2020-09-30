.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055D8C
/* 3118C 80055D8C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 31190 80055D90 AFB1001C */  sw        $s1, 0x1c($sp)
/* 31194 80055D94 00A0882D */  daddu     $s1, $a1, $zero
/* 31198 80055D98 27A50010 */  addiu     $a1, $sp, 0x10
/* 3119C 80055D9C 27A60014 */  addiu     $a2, $sp, 0x14
/* 311A0 80055DA0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 311A4 80055DA4 0C01573A */  jal       func_80055CE8
/* 311A8 80055DA8 AFB00018 */   sw       $s0, 0x18($sp)
/* 311AC 80055DAC 0040802D */  daddu     $s0, $v0, $zero
/* 311B0 80055DB0 16000005 */  bnez      $s0, .L80055DC8
/* 311B4 80055DB4 0200102D */   daddu    $v0, $s0, $zero
/* 311B8 80055DB8 8FA40014 */  lw        $a0, 0x14($sp)
/* 311BC 80055DBC 0C014206 */  jal       func_80050818
/* 311C0 80055DC0 0220282D */   daddu    $a1, $s1, $zero
/* 311C4 80055DC4 0200102D */  daddu     $v0, $s0, $zero
.L80055DC8:
/* 311C8 80055DC8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 311CC 80055DCC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 311D0 80055DD0 8FB00018 */  lw        $s0, 0x18($sp)
/* 311D4 80055DD4 03E00008 */  jr        $ra
/* 311D8 80055DD8 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055A8C
/* 30E8C 80055A8C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 30E90 80055A90 AFB1001C */  sw        $s1, 0x1c($sp)
/* 30E94 80055A94 00A0882D */  daddu     $s1, $a1, $zero
/* 30E98 80055A98 27A50010 */  addiu     $a1, $sp, 0x10
/* 30E9C 80055A9C 27A60014 */  addiu     $a2, $sp, 0x14
/* 30EA0 80055AA0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 30EA4 80055AA4 0C015666 */  jal       func_80055998
/* 30EA8 80055AA8 AFB00018 */   sw       $s0, 0x18($sp)
/* 30EAC 80055AAC 0040802D */  daddu     $s0, $v0, $zero
/* 30EB0 80055AB0 1600000C */  bnez      $s0, .L80055AE4
/* 30EB4 80055AB4 0200102D */   daddu    $v0, $s0, $zero
/* 30EB8 80055AB8 0C0156D9 */  jal       func_80055B64
/* 30EBC 80055ABC 0220202D */   daddu    $a0, $s1, $zero
/* 30EC0 80055AC0 10400006 */  beqz      $v0, .L80055ADC
/* 30EC4 80055AC4 0040282D */   daddu    $a1, $v0, $zero
/* 30EC8 80055AC8 8FA40014 */  lw        $a0, 0x14($sp)
/* 30ECC 80055ACC 0C01414B */  jal       func_8005052C
/* 30ED0 80055AD0 24060001 */   addiu    $a2, $zero, 1
/* 30ED4 80055AD4 080156B9 */  j         .L80055AE4
/* 30ED8 80055AD8 0200102D */   daddu    $v0, $s0, $zero
.L80055ADC:
/* 30EDC 80055ADC 2410000B */  addiu     $s0, $zero, 0xb
/* 30EE0 80055AE0 0200102D */  daddu     $v0, $s0, $zero
.L80055AE4:
/* 30EE4 80055AE4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 30EE8 80055AE8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 30EEC 80055AEC 8FB00018 */  lw        $s0, 0x18($sp)
/* 30EF0 80055AF0 03E00008 */  jr        $ra
/* 30EF4 80055AF4 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050AC8
/* 2BEC8 80050AC8 00041100 */  sll       $v0, $a0, 4
/* 2BECC 80050ACC 00441023 */  subu      $v0, $v0, $a0
/* 2BED0 80050AD0 000210C0 */  sll       $v0, $v0, 3
/* 2BED4 80050AD4 00441021 */  addu      $v0, $v0, $a0
/* 2BED8 80050AD8 00021080 */  sll       $v0, $v0, 2
/* 2BEDC 80050ADC 3C03800A */  lui       $v1, %hi(D_8009A608)
/* 2BEE0 80050AE0 8C63A608 */  lw        $v1, %lo(D_8009A608)($v1)
/* 2BEE4 80050AE4 24420024 */  addiu     $v0, $v0, 0x24
/* 2BEE8 80050AE8 00621821 */  addu      $v1, $v1, $v0
/* 2BEEC 80050AEC 8C620004 */  lw        $v0, 4($v1)
/* 2BEF0 80050AF0 1040000E */  beqz      $v0, .L80050B2C
/* 2BEF4 80050AF4 00000000 */   nop
/* 2BEF8 80050AF8 8C620008 */  lw        $v0, 8($v1)
/* 2BEFC 80050AFC 1040000B */  beqz      $v0, .L80050B2C
/* 2BF00 80050B00 00000000 */   nop
/* 2BF04 80050B04 10A00008 */  beqz      $a1, .L80050B28
/* 2BF08 80050B08 24020003 */   addiu    $v0, $zero, 3
/* 2BF0C 80050B0C 240200FF */  addiu     $v0, $zero, 0xff
/* 2BF10 80050B10 A062002A */  sb        $v0, 0x2a($v1)
/* 2BF14 80050B14 24020002 */  addiu     $v0, $zero, 2
/* 2BF18 80050B18 A4650028 */  sh        $a1, 0x28($v1)
/* 2BF1C 80050B1C A060002B */  sb        $zero, 0x2b($v1)
/* 2BF20 80050B20 03E00008 */  jr        $ra
/* 2BF24 80050B24 A0620026 */   sb       $v0, 0x26($v1)
.L80050B28:
/* 2BF28 80050B28 A0620024 */  sb        $v0, 0x24($v1)
.L80050B2C:
/* 2BF2C 80050B2C 03E00008 */  jr        $ra
/* 2BF30 80050B30 00000000 */   nop

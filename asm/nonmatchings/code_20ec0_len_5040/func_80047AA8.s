.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80047AA8
/* 022EA8 80047AA8 00041040 */  sll   $v0, $a0, 1
/* 022EAC 80047AAC 00441021 */  addu  $v0, $v0, $a0
/* 022EB0 80047AB0 00021080 */  sll   $v0, $v0, 2
/* 022EB4 80047AB4 00441023 */  subu  $v0, $v0, $a0
/* 022EB8 80047AB8 3C03800A */  lui   $v1, 0x800a
/* 022EBC 80047ABC 8C630F44 */  lw    $v1, 0xf44($v1)
/* 022EC0 80047AC0 00021100 */  sll   $v0, $v0, 4
/* 022EC4 80047AC4 00622021 */  addu  $a0, $v1, $v0
/* 022EC8 80047AC8 80820058 */  lb    $v0, 0x58($a0)
/* 022ECC 80047ACC 1040000C */  beqz  $v0, .L80047B00
/* 022ED0 80047AD0 90830058 */   lbu   $v1, 0x58($a0)
/* 022ED4 80047AD4 80820059 */  lb    $v0, 0x59($a0)
/* 022ED8 80047AD8 14400009 */  bnez  $v0, .L80047B00
/* 022EDC 80047ADC 24020001 */   addiu $v0, $zero, 1
/* 022EE0 80047AE0 A0830059 */  sb    $v1, 0x59($a0)
/* 022EE4 80047AE4 8C830060 */  lw    $v1, 0x60($a0)
/* 022EE8 80047AE8 A082005B */  sb    $v0, 0x5b($a0)
/* 022EEC 80047AEC 2402000A */  addiu $v0, $zero, 0xa
/* 022EF0 80047AF0 A0800058 */  sb    $zero, 0x58($a0)
/* 022EF4 80047AF4 A080005A */  sb    $zero, 0x5a($a0)
/* 022EF8 80047AF8 A082005D */  sb    $v0, 0x5d($a0)
/* 022EFC 80047AFC AC830064 */  sw    $v1, 0x64($a0)
.L80047B00:
/* 022F00 80047B00 03E00008 */  jr    $ra
/* 022F04 80047B04 00000000 */   nop   


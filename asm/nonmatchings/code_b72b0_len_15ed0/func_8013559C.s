.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8013559C
/* 0CBC9C 8013559C 8083001A */  lb    $v1, 0x1a($a0)
/* 0CBCA0 801355A0 24020001 */  addiu $v0, $zero, 1
/* 0CBCA4 801355A4 1462002A */  bne   $v1, $v0, .L80135650
/* 0CBCA8 801355A8 3C020002 */   lui   $v0, 2
/* 0CBCAC 801355AC 8C860000 */  lw    $a2, ($a0)
/* 0CBCB0 801355B0 8083001B */  lb    $v1, 0x1b($a0)
/* 0CBCB4 801355B4 8C850014 */  lw    $a1, 0x14($a0)
/* 0CBCB8 801355B8 00C21024 */  and   $v0, $a2, $v0
/* 0CBCBC 801355BC 0002382B */  sltu  $a3, $zero, $v0
/* 0CBCC0 801355C0 24020014 */  addiu $v0, $zero, 0x14
/* 0CBCC4 801355C4 10620022 */  beq   $v1, $v0, .L80135650
/* 0CBCC8 801355C8 24020017 */   addiu $v0, $zero, 0x17
/* 0CBCCC 801355CC 10620015 */  beq   $v1, $v0, .L80135624
/* 0CBCD0 801355D0 00000000 */   nop   
/* 0CBCD4 801355D4 8CA2001C */  lw    $v0, 0x1c($a1)
/* 0CBCD8 801355D8 2842003C */  slti  $v0, $v0, 0x3c
/* 0CBCDC 801355DC 1040001C */  beqz  $v0, .L80135650
/* 0CBCE0 801355E0 3C020020 */   lui   $v0, 0x20
/* 0CBCE4 801355E4 00C21024 */  and   $v0, $a2, $v0
/* 0CBCE8 801355E8 14400008 */  bnez  $v0, .L8013560C
/* 0CBCEC 801355EC 2402FFBF */   addiu $v0, $zero, -0x41
/* 0CBCF0 801355F0 3C028007 */  lui   $v0, 0x8007
/* 0CBCF4 801355F4 8C42419C */  lw    $v0, 0x419c($v0)
/* 0CBCF8 801355F8 94420134 */  lhu   $v0, 0x134($v0)
/* 0CBCFC 801355FC 00471021 */  addu  $v0, $v0, $a3
/* 0CBD00 80135600 30420001 */  andi  $v0, $v0, 1
/* 0CBD04 80135604 10400004 */  beqz  $v0, .L80135618
/* 0CBD08 80135608 2402FFBF */   addiu $v0, $zero, -0x41
.L8013560C:
/* 0CBD0C 8013560C 00C21024 */  and   $v0, $a2, $v0
/* 0CBD10 80135610 03E00008 */  jr    $ra
/* 0CBD14 80135614 AC820000 */   sw    $v0, ($a0)

.L80135618:
/* 0CBD18 80135618 34C20040 */  ori   $v0, $a2, 0x40
/* 0CBD1C 8013561C 03E00008 */  jr    $ra
/* 0CBD20 80135620 AC820000 */   sw    $v0, ($a0)

.L80135624:
/* 0CBD24 80135624 8CA3001C */  lw    $v1, 0x1c($a1)
/* 0CBD28 80135628 2862000A */  slti  $v0, $v1, 0xa
/* 0CBD2C 8013562C 10400008 */  beqz  $v0, .L80135650
/* 0CBD30 80135630 000310C0 */   sll   $v0, $v1, 3
/* 0CBD34 80135634 00431023 */  subu  $v0, $v0, $v1
/* 0CBD38 80135638 00021080 */  sll   $v0, $v0, 2
/* 0CBD3C 8013563C A082002F */  sb    $v0, 0x2f($a0)
/* 0CBD40 80135640 8C820000 */  lw    $v0, ($a0)
/* 0CBD44 80135644 3C030008 */  lui   $v1, 8
/* 0CBD48 80135648 00431025 */  or    $v0, $v0, $v1
/* 0CBD4C 8013564C AC820000 */  sw    $v0, ($a0)
.L80135650:
/* 0CBD50 80135650 03E00008 */  jr    $ra
/* 0CBD54 80135654 00000000 */   nop   


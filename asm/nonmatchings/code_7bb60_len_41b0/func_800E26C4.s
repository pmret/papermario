.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E26C4
/* 07BB74 800E26C4 3C04800F */  lui   $a0, 0x800f
/* 07BB78 800E26C8 8C847B30 */  lw    $a0, 0x7b30($a0)
/* 07BB7C 800E26CC 808300B4 */  lb    $v1, 0xb4($a0)
/* 07BB80 800E26D0 3C058011 */  lui   $a1, 0x8011
/* 07BB84 800E26D4 24A5EBB0 */  addiu $a1, $a1, -0x1450
/* 07BB88 800E26D8 2C620003 */  sltiu $v0, $v1, 3
/* 07BB8C 800E26DC 14400005 */  bnez  $v0, .L800E26F4
/* 07BB90 800E26E0 2402001F */   addiu $v0, $zero, 0x1f
/* 07BB94 800E26E4 10620003 */  beq   $v1, $v0, .L800E26F4
/* 07BB98 800E26E8 2402001A */   addiu $v0, $zero, 0x1a
/* 07BB9C 800E26EC 14620003 */  bne   $v1, $v0, .L800E26FC
/* 07BBA0 800E26F0 24020021 */   addiu $v0, $zero, 0x21
.L800E26F4:
/* 07BBA4 800E26F4 03E00008 */  jr    $ra
/* 07BBA8 800E26F8 24020001 */   addiu $v0, $zero, 1

.L800E26FC:
/* 07BBAC 800E26FC 1462001C */  bne   $v1, $v0, .L800E2770
/* 07BBB0 800E2700 00000000 */   nop   
/* 07BBB4 800E2704 3C028011 */  lui   $v0, 0x8011
/* 07BBB8 800E2708 2442F290 */  addiu $v0, $v0, -0xd70
/* 07BBBC 800E270C 90420012 */  lbu   $v0, 0x12($v0)
/* 07BBC0 800E2710 2442FFF8 */  addiu $v0, $v0, -8
/* 07BBC4 800E2714 2C420002 */  sltiu $v0, $v0, 2
/* 07BBC8 800E2718 10400009 */  beqz  $v0, .L800E2740
/* 07BBCC 800E271C 00000000 */   nop   
/* 07BBD0 800E2720 80A20000 */  lb    $v0, ($a1)
/* 07BBD4 800E2724 1440FFF3 */  bnez  $v0, .L800E26F4
/* 07BBD8 800E2728 00000000 */   nop   
.L800E272C:
/* 07BBDC 800E272C 8C830004 */  lw    $v1, 4($a0)
/* 07BBE0 800E2730 0000102D */  daddu $v0, $zero, $zero
/* 07BBE4 800E2734 34630004 */  ori   $v1, $v1, 4
/* 07BBE8 800E2738 03E00008 */  jr    $ra
/* 07BBEC 800E273C AC830004 */   sw    $v1, 4($a0)

.L800E2740:
/* 07BBF0 800E2740 90A30003 */  lbu   $v1, 3($a1)
/* 07BBF4 800E2744 2462FFFA */  addiu $v0, $v1, -6
/* 07BBF8 800E2748 2C420002 */  sltiu $v0, $v0, 2
/* 07BBFC 800E274C 50400004 */  beql  $v0, $zero, .L800E2760
/* 07BC00 800E2750 00031600 */   sll   $v0, $v1, 0x18
/* 07BC04 800E2754 80A20000 */  lb    $v0, ($a1)
/* 07BC08 800E2758 03E00008 */  jr    $ra
/* 07BC0C 800E275C 0002102B */   sltu  $v0, $zero, $v0

.L800E2760:
/* 07BC10 800E2760 00021603 */  sra   $v0, $v0, 0x18
/* 07BC14 800E2764 24030004 */  addiu $v1, $zero, 4
/* 07BC18 800E2768 1043FFF0 */  beq   $v0, $v1, .L800E272C
/* 07BC1C 800E276C 00000000 */   nop   
.L800E2770:
/* 07BC20 800E2770 03E00008 */  jr    $ra
/* 07BC24 800E2774 0000102D */   daddu $v0, $zero, $zero


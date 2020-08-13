.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel suspend_group_script_index
/* 0E8EA8 802C44F8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E8EAC 802C44FC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E8EB0 802C4500 0080882D */  daddu $s1, $a0, $zero
/* 0E8EB4 802C4504 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E8EB8 802C4508 00A0902D */  daddu $s2, $a1, $zero
/* 0E8EBC 802C450C AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8EC0 802C4510 0000802D */  daddu $s0, $zero, $zero
/* 0E8EC4 802C4514 AFBF001C */  sw    $ra, 0x1c($sp)
.L802C4518:
/* 0E8EC8 802C4518 3C03802E */  lui   $v1, 0x802e
/* 0E8ECC 802C451C 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8ED0 802C4520 00101080 */  sll   $v0, $s0, 2
/* 0E8ED4 802C4524 00431021 */  addu  $v0, $v0, $v1
/* 0E8ED8 802C4528 8C440000 */  lw    $a0, ($v0)
/* 0E8EDC 802C452C 50800007 */  beql  $a0, $zero, .L802C454C
/* 0E8EE0 802C4530 26100001 */   addiu $s0, $s0, 1
/* 0E8EE4 802C4534 8C820144 */  lw    $v0, 0x144($a0)
/* 0E8EE8 802C4538 54510004 */  bnel  $v0, $s1, .L802C454C
/* 0E8EEC 802C453C 26100001 */   addiu $s0, $s0, 1
/* 0E8EF0 802C4540 0C0B10B6 */  jal   suspend_group_script
/* 0E8EF4 802C4544 0240282D */   daddu $a1, $s2, $zero
/* 0E8EF8 802C4548 26100001 */  addiu $s0, $s0, 1
.L802C454C:
/* 0E8EFC 802C454C 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8F00 802C4550 1440FFF1 */  bnez  $v0, .L802C4518
/* 0E8F04 802C4554 00000000 */   nop   
/* 0E8F08 802C4558 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E8F0C 802C455C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E8F10 802C4560 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E8F14 802C4564 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8F18 802C4568 03E00008 */  jr    $ra
/* 0E8F1C 802C456C 27BD0020 */   addiu $sp, $sp, 0x20


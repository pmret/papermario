.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel MakeEntity
/* 0A8438 80111D38 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0A843C 80111D3C AFB20030 */  sw    $s2, 0x30($sp)
/* 0A8440 80111D40 0080902D */  daddu $s2, $a0, $zero
/* 0A8444 80111D44 24020001 */  addiu $v0, $zero, 1
/* 0A8448 80111D48 AFBF004C */  sw    $ra, 0x4c($sp)
/* 0A844C 80111D4C AFBE0048 */  sw    $fp, 0x48($sp)
/* 0A8450 80111D50 AFB70044 */  sw    $s7, 0x44($sp)
/* 0A8454 80111D54 AFB60040 */  sw    $s6, 0x40($sp)
/* 0A8458 80111D58 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0A845C 80111D5C AFB40038 */  sw    $s4, 0x38($sp)
/* 0A8460 80111D60 AFB30034 */  sw    $s3, 0x34($sp)
/* 0A8464 80111D64 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0A8468 80111D68 AFB00028 */  sw    $s0, 0x28($sp)
/* 0A846C 80111D6C 8E50000C */  lw    $s0, 0xc($s2)
/* 0A8470 80111D70 14A2003E */  bne   $a1, $v0, .L80111E6C
/* 0A8474 80111D74 24020002 */   addiu $v0, $zero, 2
/* 0A8478 80111D78 8E050000 */  lw    $a1, ($s0)
/* 0A847C 80111D7C 26100004 */  addiu $s0, $s0, 4
/* 0A8480 80111D80 0240202D */  daddu $a0, $s2, $zero
/* 0A8484 80111D84 3C118016 */  lui   $s1, 0x8016
/* 0A8488 80111D88 2631C7D8 */  addiu $s1, $s1, -0x3828
/* 0A848C 80111D8C 0C0B1EAF */  jal   get_variable
/* 0A8490 80111D90 3C148000 */   lui   $s4, 0x8000
/* 0A8494 80111D94 8E050000 */  lw    $a1, ($s0)
/* 0A8498 80111D98 26100004 */  addiu $s0, $s0, 4
/* 0A849C 80111D9C 0240202D */  daddu $a0, $s2, $zero
/* 0A84A0 80111DA0 0C0B1EAF */  jal   get_variable
/* 0A84A4 80111DA4 0040F02D */   daddu $fp, $v0, $zero
/* 0A84A8 80111DA8 8E050000 */  lw    $a1, ($s0)
/* 0A84AC 80111DAC 26100004 */  addiu $s0, $s0, 4
/* 0A84B0 80111DB0 0240202D */  daddu $a0, $s2, $zero
/* 0A84B4 80111DB4 0C0B1EAF */  jal   get_variable
/* 0A84B8 80111DB8 0040B02D */   daddu $s6, $v0, $zero
/* 0A84BC 80111DBC 8E050000 */  lw    $a1, ($s0)
/* 0A84C0 80111DC0 26100004 */  addiu $s0, $s0, 4
/* 0A84C4 80111DC4 0240202D */  daddu $a0, $s2, $zero
/* 0A84C8 80111DC8 0C0B1EAF */  jal   get_variable
/* 0A84CC 80111DCC 0040B82D */   daddu $s7, $v0, $zero
/* 0A84D0 80111DD0 8E050000 */  lw    $a1, ($s0)
/* 0A84D4 80111DD4 26100004 */  addiu $s0, $s0, 4
/* 0A84D8 80111DD8 0240202D */  daddu $a0, $s2, $zero
/* 0A84DC 80111DDC 0C0B1EAF */  jal   get_variable
/* 0A84E0 80111DE0 0040A82D */   daddu $s5, $v0, $zero
/* 0A84E4 80111DE4 0040982D */  daddu $s3, $v0, $zero
/* 0A84E8 80111DE8 AE200000 */  sw    $zero, ($s1)
/* 0A84EC 80111DEC 2631FFFC */  addiu $s1, $s1, -4
/* 0A84F0 80111DF0 AE200000 */  sw    $zero, ($s1)
/* 0A84F4 80111DF4 2631FFFC */  addiu $s1, $s1, -4
/* 0A84F8 80111DF8 AE200000 */  sw    $zero, ($s1)
.L80111DFC:
/* 0A84FC 80111DFC 8E050000 */  lw    $a1, ($s0)
/* 0A8500 80111E00 26100004 */  addiu $s0, $s0, 4
/* 0A8504 80111E04 0C0B1EAF */  jal   get_variable
/* 0A8508 80111E08 0240202D */   daddu $a0, $s2, $zero
/* 0A850C 80111E0C 10540004 */  beq   $v0, $s4, .L80111E20
/* 0A8510 80111E10 03C0202D */   daddu $a0, $fp, $zero
/* 0A8514 80111E14 AE220000 */  sw    $v0, ($s1)
/* 0A8518 80111E18 0804477F */  j     .L80111DFC
/* 0A851C 80111E1C 26310004 */   addiu $s1, $s1, 4

.L80111E20:
/* 0A8520 80111E20 3C028016 */  lui   $v0, 0x8016
/* 0A8524 80111E24 2442C7D0 */  addiu $v0, $v0, -0x3830
/* 0A8528 80111E28 02C0282D */  daddu $a1, $s6, $zero
/* 0A852C 80111E2C 8C430000 */  lw    $v1, ($v0)
/* 0A8530 80111E30 8C460004 */  lw    $a2, 4($v0)
/* 0A8534 80111E34 8C420008 */  lw    $v0, 8($v0)
/* 0A8538 80111E38 02A0382D */  daddu $a3, $s5, $zero
/* 0A853C 80111E3C AFB30010 */  sw    $s3, 0x10($sp)
/* 0A8540 80111E40 AFB40020 */  sw    $s4, 0x20($sp)
/* 0A8544 80111E44 AFA60018 */  sw    $a2, 0x18($sp)
/* 0A8548 80111E48 02E0302D */  daddu $a2, $s7, $zero
/* 0A854C 80111E4C AFA30014 */  sw    $v1, 0x14($sp)
/* 0A8550 80111E50 0C044631 */  jal   create_entity
/* 0A8554 80111E54 AFA2001C */   sw    $v0, 0x1c($sp)
/* 0A8558 80111E58 0040182D */  daddu $v1, $v0, $zero
/* 0A855C 80111E5C 24020002 */  addiu $v0, $zero, 2
/* 0A8560 80111E60 3C018015 */  lui   $at, 0x8015
/* 0A8564 80111E64 AC2312EC */  sw    $v1, 0x12ec($at)
/* 0A8568 80111E68 AE430084 */  sw    $v1, 0x84($s2)
.L80111E6C:
/* 0A856C 80111E6C 8FBF004C */  lw    $ra, 0x4c($sp)
/* 0A8570 80111E70 8FBE0048 */  lw    $fp, 0x48($sp)
/* 0A8574 80111E74 8FB70044 */  lw    $s7, 0x44($sp)
/* 0A8578 80111E78 8FB60040 */  lw    $s6, 0x40($sp)
/* 0A857C 80111E7C 8FB5003C */  lw    $s5, 0x3c($sp)
/* 0A8580 80111E80 8FB40038 */  lw    $s4, 0x38($sp)
/* 0A8584 80111E84 8FB30034 */  lw    $s3, 0x34($sp)
/* 0A8588 80111E88 8FB20030 */  lw    $s2, 0x30($sp)
/* 0A858C 80111E8C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0A8590 80111E90 8FB00028 */  lw    $s0, 0x28($sp)
/* 0A8594 80111E94 03E00008 */  jr    $ra
/* 0A8598 80111E98 27BD0050 */   addiu $sp, $sp, 0x50

/* 0A859C 80111E9C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A85A0 80111EA0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0A85A4 80111EA4 0080802D */  daddu $s0, $a0, $zero
/* 0A85A8 80111EA8 3C048015 */  lui   $a0, 0x8015
/* 0A85AC 80111EAC 8C8412EC */  lw    $a0, 0x12ec($a0)
/* 0A85B0 80111EB0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A85B4 80111EB4 0C04417A */  jal   get_entity_by_index
/* 0A85B8 80111EB8 00000000 */   nop   
/* 0A85BC 80111EBC 8E03000C */  lw    $v1, 0xc($s0)
/* 0A85C0 80111EC0 0200202D */  daddu $a0, $s0, $zero
/* 0A85C4 80111EC4 8C650000 */  lw    $a1, ($v1)
/* 0A85C8 80111EC8 0C0B1EAF */  jal   get_variable
/* 0A85CC 80111ECC 0040802D */   daddu $s0, $v0, $zero
/* 0A85D0 80111ED0 0040182D */  daddu $v1, $v0, $zero
/* 0A85D4 80111ED4 54600004 */  bnel  $v1, $zero, .L80111EE8
/* 0A85D8 80111ED8 24020001 */   addiu $v0, $zero, 1
/* 0A85DC 80111EDC 8E020000 */  lw    $v0, ($s0)
/* 0A85E0 80111EE0 080447C5 */  j     .L80111F14
/* 0A85E4 80111EE4 34420002 */   ori   $v0, $v0, 2

.L80111EE8:
/* 0A85E8 80111EE8 14620004 */  bne   $v1, $v0, .L80111EFC
/* 0A85EC 80111EEC 24020002 */   addiu $v0, $zero, 2
/* 0A85F0 80111EF0 8E020000 */  lw    $v0, ($s0)
/* 0A85F4 80111EF4 080447C4 */  j     .L80111F10
/* 0A85F8 80111EF8 3C030004 */   lui   $v1, 4

.L80111EFC:
/* 0A85FC 80111EFC 14620002 */  bne   $v1, $v0, .L80111F08
/* 0A8600 80111F00 3C03000C */   lui   $v1, 0xc
/* 0A8604 80111F04 3C030004 */  lui   $v1, 4
.L80111F08:
/* 0A8608 80111F08 8E020000 */  lw    $v0, ($s0)
/* 0A860C 80111F0C 34630002 */  ori   $v1, $v1, 2
.L80111F10:
/* 0A8610 80111F10 00431025 */  or    $v0, $v0, $v1
.L80111F14:
/* 0A8614 80111F14 AE020000 */  sw    $v0, ($s0)
/* 0A8618 80111F18 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A861C 80111F1C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A8620 80111F20 24020002 */  addiu $v0, $zero, 2
/* 0A8624 80111F24 03E00008 */  jr    $ra
/* 0A8628 80111F28 27BD0018 */   addiu $sp, $sp, 0x18

/* 0A862C 80111F2C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0A8630 80111F30 AFB00010 */  sw    $s0, 0x10($sp)
/* 0A8634 80111F34 0080802D */  daddu $s0, $a0, $zero
/* 0A8638 80111F38 3C048015 */  lui   $a0, 0x8015
/* 0A863C 80111F3C 8C8412EC */  lw    $a0, 0x12ec($a0)
/* 0A8640 80111F40 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0A8644 80111F44 0C04417A */  jal   get_entity_by_index
/* 0A8648 80111F48 00000000 */   nop   
/* 0A864C 80111F4C 8E03000C */  lw    $v1, 0xc($s0)
/* 0A8650 80111F50 0200202D */  daddu $a0, $s0, $zero
/* 0A8654 80111F54 8C650000 */  lw    $a1, ($v1)
/* 0A8658 80111F58 0C0B1EAF */  jal   get_variable
/* 0A865C 80111F5C 0040802D */   daddu $s0, $v0, $zero
/* 0A8660 80111F60 1040000B */  beqz  $v0, .L80111F90
/* 0A8664 80111F64 2403FFFB */   addiu $v1, $zero, -5
/* 0A8668 80111F68 8E020000 */  lw    $v0, ($s0)
/* 0A866C 80111F6C 86040016 */  lh    $a0, 0x16($s0)
/* 0A8670 80111F70 34420004 */  ori   $v0, $v0, 4
/* 0A8674 80111F74 0C044181 */  jal   get_shadow_by_index
/* 0A8678 80111F78 AE020000 */   sw    $v0, ($s0)
/* 0A867C 80111F7C 8C430000 */  lw    $v1, ($v0)
/* 0A8680 80111F80 3C040040 */  lui   $a0, 0x40
/* 0A8684 80111F84 00641825 */  or    $v1, $v1, $a0
/* 0A8688 80111F88 080447E7 */  j     .L80111F9C
/* 0A868C 80111F8C AC430000 */   sw    $v1, ($v0)

.L80111F90:
/* 0A8690 80111F90 8E020000 */  lw    $v0, ($s0)
/* 0A8694 80111F94 00431024 */  and   $v0, $v0, $v1
/* 0A8698 80111F98 AE020000 */  sw    $v0, ($s0)
.L80111F9C:
/* 0A869C 80111F9C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0A86A0 80111FA0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A86A4 80111FA4 24020002 */  addiu $v0, $zero, 2
/* 0A86A8 80111FA8 03E00008 */  jr    $ra
/* 0A86AC 80111FAC 27BD0018 */   addiu $sp, $sp, 0x18


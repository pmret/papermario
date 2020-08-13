.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80126EAC
/* 0BD5AC 80126EAC 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0BD5B0 80126EB0 3C058015 */  lui   $a1, 0x8015
/* 0BD5B4 80126EB4 24A54C30 */  addiu $a1, $a1, 0x4c30
/* 0BD5B8 80126EB8 00041080 */  sll   $v0, $a0, 2
/* 0BD5BC 80126EBC 00441021 */  addu  $v0, $v0, $a0
/* 0BD5C0 80126EC0 00021080 */  sll   $v0, $v0, 2
/* 0BD5C4 80126EC4 00441023 */  subu  $v0, $v0, $a0
/* 0BD5C8 80126EC8 000218C0 */  sll   $v1, $v0, 3
/* 0BD5CC 80126ECC 00431021 */  addu  $v0, $v0, $v1
/* 0BD5D0 80126ED0 000210C0 */  sll   $v0, $v0, 3
/* 0BD5D4 80126ED4 AFB00038 */  sw    $s0, 0x38($sp)
/* 0BD5D8 80126ED8 00458021 */  addu  $s0, $v0, $a1
/* 0BD5DC 80126EDC AFBF003C */  sw    $ra, 0x3c($sp)
/* 0BD5E0 80126EE0 8602047E */  lh    $v0, 0x47e($s0)
/* 0BD5E4 80126EE4 28420006 */  slti  $v0, $v0, 6
/* 0BD5E8 80126EE8 10400017 */  beqz  $v0, .L80126F48
/* 0BD5EC 80126EEC 24050018 */   addiu $a1, $zero, 0x18
/* 0BD5F0 80126EF0 3C02802F */  lui   $v0, 0x802f
/* 0BD5F4 80126EF4 2442D670 */  addiu $v0, $v0, -0x2990
/* 0BD5F8 80126EF8 3C04802F */  lui   $a0, 0x802f
/* 0BD5FC 80126EFC 2484D550 */  addiu $a0, $a0, -0x2ab0
/* 0BD600 80126F00 00A0302D */  daddu $a2, $a1, $zero
/* 0BD604 80126F04 AFA00010 */  sw    $zero, 0x10($sp)
/* 0BD608 80126F08 AFA20014 */  sw    $v0, 0x14($sp)
/* 0BD60C 80126F0C 86020482 */  lh    $v0, 0x482($s0)
/* 0BD610 80126F10 24070002 */  addiu $a3, $zero, 2
/* 0BD614 80126F14 AFA20018 */  sw    $v0, 0x18($sp)
/* 0BD618 80126F18 86030484 */  lh    $v1, 0x484($s0)
/* 0BD61C 80126F1C 2402000A */  addiu $v0, $zero, 0xa
/* 0BD620 80126F20 AFA20020 */  sw    $v0, 0x20($sp)
/* 0BD624 80126F24 AFA20024 */  sw    $v0, 0x24($sp)
/* 0BD628 80126F28 2402012C */  addiu $v0, $zero, 0x12c
/* 0BD62C 80126F2C AFA20028 */  sw    $v0, 0x28($sp)
/* 0BD630 80126F30 240200DC */  addiu $v0, $zero, 0xdc
/* 0BD634 80126F34 AFA2002C */  sw    $v0, 0x2c($sp)
/* 0BD638 80126F38 240200FF */  addiu $v0, $zero, 0xff
/* 0BD63C 80126F3C AFA20030 */  sw    $v0, 0x30($sp)
/* 0BD640 80126F40 0C04BA68 */  jal   func_8012E9A0
/* 0BD644 80126F44 AFA3001C */   sw    $v1, 0x1c($sp)
.L80126F48:
/* 0BD648 80126F48 9602047E */  lhu   $v0, 0x47e($s0)
/* 0BD64C 80126F4C 24420001 */  addiu $v0, $v0, 1
/* 0BD650 80126F50 A602047E */  sh    $v0, 0x47e($s0)
/* 0BD654 80126F54 00021400 */  sll   $v0, $v0, 0x10
/* 0BD658 80126F58 00021403 */  sra   $v0, $v0, 0x10
/* 0BD65C 80126F5C 2842000C */  slti  $v0, $v0, 0xc
/* 0BD660 80126F60 50400001 */  beql  $v0, $zero, .L80126F68
/* 0BD664 80126F64 A600047E */   sh    $zero, 0x47e($s0)
.L80126F68:
/* 0BD668 80126F68 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0BD66C 80126F6C 8FB00038 */  lw    $s0, 0x38($sp)
/* 0BD670 80126F70 03E00008 */  jr    $ra
/* 0BD674 80126F74 27BD0040 */   addiu $sp, $sp, 0x40


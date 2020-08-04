.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel add_star_points
/* 0835D8 800EA128 3C038011 */  lui   $v1, 0x8011
/* 0835DC 800EA12C 2463F290 */  addiu $v1, $v1, -0xd70
/* 0835E0 800EA130 90620010 */  lbu   $v0, 0x10($v1)
/* 0835E4 800EA134 00441021 */  addu  $v0, $v0, $a0
/* 0835E8 800EA138 A0620010 */  sb    $v0, 0x10($v1)
/* 0835EC 800EA13C 00021600 */  sll   $v0, $v0, 0x18
/* 0835F0 800EA140 00021603 */  sra   $v0, $v0, 0x18
/* 0835F4 800EA144 28420065 */  slti  $v0, $v0, 0x65
/* 0835F8 800EA148 14400003 */  bnez  $v0, .L800EA158
/* 0835FC 800EA14C 0060202D */   daddu $a0, $v1, $zero
/* 083600 800EA150 24020064 */  addiu $v0, $zero, 0x64
/* 083604 800EA154 A0620010 */  sb    $v0, 0x10($v1)
.L800EA158:
/* 083608 800EA158 80620010 */  lb    $v0, 0x10($v1)
/* 08360C 800EA15C 04420001 */  bltzl $v0, .L800EA164
/* 083610 800EA160 A0600010 */   sb    $zero, 0x10($v1)
.L800EA164:
/* 083614 800EA164 80820010 */  lb    $v0, 0x10($a0)
/* 083618 800EA168 03E00008 */  jr    $ra
/* 08361C 800EA16C 00000000 */   nop   


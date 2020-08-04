.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80246168
/* 1394A8 80246168 0040902D */  daddu $s2, $v0, $zero
/* 1394AC 8024616C 00021400 */  sll   $v0, $v0, 0x10
/* 1394B0 80246170 04420001 */  bltzl $v0, .L80246178
/* 1394B4 80246174 0000902D */   daddu $s2, $zero, $zero
.L80246178:
/* 1394B8 80246178 00121400 */  sll   $v0, $s2, 0x10
/* 1394BC 8024617C 00021403 */  sra   $v0, $v0, 0x10
/* 1394C0 80246180 28420004 */  slti  $v0, $v0, 4
/* 1394C4 80246184 50400001 */  beql  $v0, $zero, .L8024618C
/* 1394C8 80246188 24120003 */   addiu $s2, $zero, 3
.L8024618C:
/* 1394CC 8024618C 26620001 */  addiu $v0, $s3, 1
/* 1394D0 80246190 0040982D */  daddu $s3, $v0, $zero
/* 1394D4 80246194 00021400 */  sll   $v0, $v0, 0x10
/* 1394D8 80246198 04420001 */  bltzl $v0, .L802461A0
/* 1394DC 8024619C 0000982D */   daddu $s3, $zero, $zero
.L802461A0:
/* 1394E0 802461A0 00131400 */  sll   $v0, $s3, 0x10
/* 1394E4 802461A4 00021403 */  sra   $v0, $v0, 0x10
/* 1394E8 802461A8 28420004 */  slti  $v0, $v0, 4
/* 1394EC 802461AC 50400001 */  beql  $v0, $zero, .L802461B4
/* 1394F0 802461B0 24130003 */   addiu $s3, $zero, 3
.L802461B4:
/* 1394F4 802461B4 24040003 */  addiu $a0, $zero, 3
/* 1394F8 802461B8 8FA80084 */  lw    $t0, 0x84($sp)
/* 1394FC 802461BC 27C6000A */  addiu $a2, $fp, 0xa

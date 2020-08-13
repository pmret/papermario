.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8010FBD8
/* 0A62D8 8010FBD8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A62DC 8010FBDC AFB10014 */  sw    $s1, 0x14($sp)
/* 0A62E0 8010FBE0 0080882D */  daddu $s1, $a0, $zero
/* 0A62E4 8010FBE4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0A62E8 8010FBE8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0A62EC 8010FBEC 8E300018 */  lw    $s0, 0x18($s1)
/* 0A62F0 8010FBF0 8E030000 */  lw    $v1, ($s0)
/* 0A62F4 8010FBF4 2C62000A */  sltiu $v0, $v1, 0xa
/* 0A62F8 8010FBF8 10400052 */  beqz  $v0, .L8010FD44
/* 0A62FC 8010FBFC 26100004 */   addiu $s0, $s0, 4
/* 0A6300 8010FC00 00031080 */  sll   $v0, $v1, 2
/* 0A6304 8010FC04 3C018015 */  lui   $at, 0x8015
/* 0A6308 8010FC08 00220821 */  addu  $at, $at, $v0
/* 0A630C 8010FC0C 8C22F740 */  lw    $v0, -0x8c0($at)
/* 0A6310 8010FC10 00400008 */  jr    $v0
/* 0A6314 8010FC14 00000000 */   nop   
/* 0A6318 8010FC18 0000202D */  daddu $a0, $zero, $zero
/* 0A631C 8010FC1C 240200FF */  addiu $v0, $zero, 0xff
/* 0A6320 8010FC20 A2220009 */  sb    $v0, 9($s1)
/* 0A6324 8010FC24 AE20001C */  sw    $zero, 0x1c($s1)
/* 0A6328 8010FC28 08043F54 */  j     .L8010FD50
/* 0A632C 8010FC2C AE200018 */   sw    $zero, 0x18($s1)

/* 0A6330 8010FC30 8E020000 */  lw    $v0, ($s0)
/* 0A6334 8010FC34 24040001 */  addiu $a0, $zero, 1
/* 0A6338 8010FC38 AE220018 */  sw    $v0, 0x18($s1)
/* 0A633C 8010FC3C 0040182D */  daddu $v1, $v0, $zero
/* 0A6340 8010FC40 0080102D */  daddu $v0, $a0, $zero
/* 0A6344 8010FC44 A2220009 */  sb    $v0, 9($s1)
/* 0A6348 8010FC48 08043F54 */  j     .L8010FD50
/* 0A634C 8010FC4C AE23002C */   sw    $v1, 0x2c($s1)

/* 0A6350 8010FC50 8E020000 */  lw    $v0, ($s0)
/* 0A6354 8010FC54 26100004 */  addiu $s0, $s0, 4
/* 0A6358 8010FC58 0220202D */  daddu $a0, $s1, $zero
/* 0A635C 8010FC5C 0040F809 */  jalr  $v0
/* 0A6360 8010FC60 AC900018 */  sw    $s0, 0x18($a0)
/* 0A6364 8010FC64 08043F54 */  j     .L8010FD50
/* 0A6368 8010FC68 24040001 */   addiu $a0, $zero, 1

/* 0A636C 8010FC6C 92020003 */  lbu   $v0, 3($s0)
/* 0A6370 8010FC70 26100004 */  addiu $s0, $s0, 4
/* 0A6374 8010FC74 0000202D */  daddu $a0, $zero, $zero
/* 0A6378 8010FC78 A2220009 */  sb    $v0, 9($s1)
/* 0A637C 8010FC7C 8E020000 */  lw    $v0, ($s0)
/* 0A6380 8010FC80 26100004 */  addiu $s0, $s0, 4
/* 0A6384 8010FC84 AE300018 */  sw    $s0, 0x18($s1)
/* 0A6388 8010FC88 08043F54 */  j     .L8010FD50
/* 0A638C 8010FC8C AE22001C */   sw    $v0, 0x1c($s1)

/* 0A6390 8010FC90 8E020000 */  lw    $v0, ($s0)
/* 0A6394 8010FC94 00021080 */  sll   $v0, $v0, 2
/* 0A6398 8010FC98 02221021 */  addu  $v0, $s1, $v0
/* 0A639C 8010FC9C 8C42002C */  lw    $v0, 0x2c($v0)
/* 0A63A0 8010FCA0 24040001 */  addiu $a0, $zero, 1
/* 0A63A4 8010FCA4 08043F54 */  j     .L8010FD50
/* 0A63A8 8010FCA8 AE220018 */   sw    $v0, 0x18($s1)

/* 0A63AC 8010FCAC 8E020000 */  lw    $v0, ($s0)
/* 0A63B0 8010FCB0 26100004 */  addiu $s0, $s0, 4
/* 0A63B4 8010FCB4 24040001 */  addiu $a0, $zero, 1
/* 0A63B8 8010FCB8 00021080 */  sll   $v0, $v0, 2
/* 0A63BC 8010FCBC 02221021 */  addu  $v0, $s1, $v0
/* 0A63C0 8010FCC0 AC50002C */  sw    $s0, 0x2c($v0)
/* 0A63C4 8010FCC4 08043F54 */  j     .L8010FD50
/* 0A63C8 8010FCC8 AE300018 */   sw    $s0, 0x18($s1)

/* 0A63CC 8010FCCC 8E220028 */  lw    $v0, 0x28($s1)
/* 0A63D0 8010FCD0 1040001D */  beqz  $v0, .L8010FD48
/* 0A63D4 8010FCD4 3C030100 */   lui   $v1, 0x100
/* 0A63D8 8010FCD8 8E220000 */  lw    $v0, ($s1)
/* 0A63DC 8010FCDC 00431025 */  or    $v0, $v0, $v1
/* 0A63E0 8010FCE0 08043F52 */  j     .L8010FD48
/* 0A63E4 8010FCE4 AE220000 */   sw    $v0, ($s1)

/* 0A63E8 8010FCE8 8E030000 */  lw    $v1, ($s0)
/* 0A63EC 8010FCEC 26100004 */  addiu $s0, $s0, 4
/* 0A63F0 8010FCF0 8E220000 */  lw    $v0, ($s1)
/* 0A63F4 8010FCF4 24040001 */  addiu $a0, $zero, 1
/* 0A63F8 8010FCF8 AE300018 */  sw    $s0, 0x18($s1)
/* 0A63FC 8010FCFC 00431025 */  or    $v0, $v0, $v1
/* 0A6400 8010FD00 08043F54 */  j     .L8010FD50
/* 0A6404 8010FD04 AE220000 */   sw    $v0, ($s1)

/* 0A6408 8010FD08 8E030000 */  lw    $v1, ($s0)
/* 0A640C 8010FD0C 26100004 */  addiu $s0, $s0, 4
/* 0A6410 8010FD10 8E220000 */  lw    $v0, ($s1)
/* 0A6414 8010FD14 24040001 */  addiu $a0, $zero, 1
/* 0A6418 8010FD18 AE300018 */  sw    $s0, 0x18($s1)
/* 0A641C 8010FD1C 00031827 */  nor   $v1, $zero, $v1
/* 0A6420 8010FD20 00431024 */  and   $v0, $v0, $v1
/* 0A6424 8010FD24 08043F54 */  j     .L8010FD50
/* 0A6428 8010FD28 AE220000 */   sw    $v0, ($s1)

/* 0A642C 8010FD2C 8E040000 */  lw    $a0, ($s0)
/* 0A6430 8010FD30 0C05272D */  jal   play_sound
/* 0A6434 8010FD34 26100004 */   addiu $s0, $s0, 4
/* 0A6438 8010FD38 24040001 */  addiu $a0, $zero, 1
/* 0A643C 8010FD3C 08043F54 */  j     .L8010FD50
/* 0A6440 8010FD40 AE300018 */   sw    $s0, 0x18($s1)

.L8010FD44:
/* 0A6444 8010FD44 26100004 */  addiu $s0, $s0, 4
.L8010FD48:
/* 0A6448 8010FD48 AE300018 */  sw    $s0, 0x18($s1)
/* 0A644C 8010FD4C 24040001 */  addiu $a0, $zero, 1
.L8010FD50:
/* 0A6450 8010FD50 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0A6454 8010FD54 8FB10014 */  lw    $s1, 0x14($sp)
/* 0A6458 8010FD58 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A645C 8010FD5C 0080102D */  daddu $v0, $a0, $zero
/* 0A6460 8010FD60 03E00008 */  jr    $ra
/* 0A6464 8010FD64 27BD0020 */   addiu $sp, $sp, 0x20


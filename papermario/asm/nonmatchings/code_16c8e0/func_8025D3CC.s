.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8025D3CC
/* 18BCAC 8025D3CC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 18BCB0 8025D3D0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 18BCB4 8025D3D4 AFB00020 */  sw    $s0, 0x20($sp)
/* 18BCB8 8025D3D8 8C8600C0 */  lw    $a2, 0xc0($a0)
/* 18BCBC 8025D3DC 00C58021 */  addu  $s0, $a2, $a1
/* 18BCC0 8025D3E0 820308BC */  lb    $v1, 0x8bc($s0)
/* 18BCC4 8025D3E4 10600005 */  beqz  $v1, .L8025D3FC
/* 18BCC8 8025D3E8 24020001 */   addiu $v0, $zero, 1
/* 18BCCC 8025D3EC 1062001A */  beq   $v1, $v0, .L8025D458
/* 18BCD0 8025D3F0 00051080 */   sll   $v0, $a1, 2
/* 18BCD4 8025D3F4 08097524 */  j     .L8025D490
/* 18BCD8 8025D3F8 00000000 */   nop   

.L8025D3FC:
/* 18BCDC 8025D3FC 90830073 */  lbu   $v1, 0x73($a0)
/* 18BCE0 8025D400 C482005C */  lwc1  $f2, 0x5c($a0)
/* 18BCE4 8025D404 24020003 */  addiu $v0, $zero, 3
/* 18BCE8 8025D408 AFA20014 */  sw    $v0, 0x14($sp)
/* 18BCEC 8025D40C 00051080 */  sll   $v0, $a1, 2
/* 18BCF0 8025D410 244208B0 */  addiu $v0, $v0, 0x8b0
/* 18BCF4 8025D414 3C0141A0 */  lui   $at, 0x41a0
/* 18BCF8 8025D418 44810000 */  mtc1  $at, $f0
/* 18BCFC 8025D41C 00C21021 */  addu  $v0, $a2, $v0
/* 18BD00 8025D420 AFA20018 */  sw    $v0, 0x18($sp)
/* 18BD04 8025D424 E7A00010 */  swc1  $f0, 0x10($sp)
/* 18BD08 8025D428 44830000 */  mtc1  $v1, $f0
/* 18BD0C 8025D42C 00000000 */  nop   
/* 18BD10 8025D430 46800020 */  cvt.s.w $f0, $f0
/* 18BD14 8025D434 46001080 */  add.s $f2, $f2, $f0
/* 18BD18 8025D438 8C850058 */  lw    $a1, 0x58($a0)
/* 18BD1C 8025D43C 8C870060 */  lw    $a3, 0x60($a0)
/* 18BD20 8025D440 44061000 */  mfc1  $a2, $f2
/* 18BD24 8025D444 0C01C28C */  jal   func_80070A30
/* 18BD28 8025D448 0000202D */   daddu $a0, $zero, $zero
/* 18BD2C 8025D44C 24020001 */  addiu $v0, $zero, 1
/* 18BD30 8025D450 08097524 */  j     .L8025D490
/* 18BD34 8025D454 A20208BC */   sb    $v0, 0x8bc($s0)

.L8025D458:
/* 18BD38 8025D458 00C21021 */  addu  $v0, $a2, $v0
/* 18BD3C 8025D45C 8C4208B0 */  lw    $v0, 0x8b0($v0)
/* 18BD40 8025D460 C4800058 */  lwc1  $f0, 0x58($a0)
/* 18BD44 8025D464 8C43000C */  lw    $v1, 0xc($v0)
/* 18BD48 8025D468 E4600004 */  swc1  $f0, 4($v1)
/* 18BD4C 8025D46C 90820073 */  lbu   $v0, 0x73($a0)
/* 18BD50 8025D470 C480005C */  lwc1  $f0, 0x5c($a0)
/* 18BD54 8025D474 44821000 */  mtc1  $v0, $f2
/* 18BD58 8025D478 00000000 */  nop   
/* 18BD5C 8025D47C 468010A0 */  cvt.s.w $f2, $f2
/* 18BD60 8025D480 46020000 */  add.s $f0, $f0, $f2
/* 18BD64 8025D484 E4600008 */  swc1  $f0, 8($v1)
/* 18BD68 8025D488 C4800060 */  lwc1  $f0, 0x60($a0)
/* 18BD6C 8025D48C E460000C */  swc1  $f0, 0xc($v1)
.L8025D490:
/* 18BD70 8025D490 8FBF0024 */  lw    $ra, 0x24($sp)
/* 18BD74 8025D494 8FB00020 */  lw    $s0, 0x20($sp)
/* 18BD78 8025D498 03E00008 */  jr    $ra
/* 18BD7C 8025D49C 27BD0028 */   addiu $sp, $sp, 0x28


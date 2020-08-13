.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel play_sound_at_position
/* 0E045C 80149D5C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0E0460 80149D60 AFB20028 */  sw    $s2, 0x28($sp)
/* 0E0464 80149D64 0080902D */  daddu $s2, $a0, $zero
/* 0E0468 80149D68 3C02F000 */  lui   $v0, 0xf000
/* 0E046C 80149D6C 02421024 */  and   $v0, $s2, $v0
/* 0E0470 80149D70 44866000 */  mtc1  $a2, $f12
/* 0E0474 80149D74 44877000 */  mtc1  $a3, $f14
/* 0E0478 80149D78 C7A00040 */  lwc1  $f0, 0x40($sp)
/* 0E047C 80149D7C 3C038000 */  lui   $v1, 0x8000
/* 0E0480 80149D80 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0E0484 80149D84 AFB10024 */  sw    $s1, 0x24($sp)
/* 0E0488 80149D88 1443000A */  bne   $v0, $v1, .L80149DB4
/* 0E048C 80149D8C AFB00020 */   sw    $s0, 0x20($sp)
/* 0E0490 80149D90 3242FFFF */  andi  $v0, $s2, 0xffff
/* 0E0494 80149D94 00021080 */  sll   $v0, $v0, 2
/* 0E0498 80149D98 3C048015 */  lui   $a0, 0x8015
/* 0E049C 80149D9C 00822021 */  addu  $a0, $a0, $v0
/* 0E04A0 80149DA0 8C84F2D0 */  lw    $a0, -0xd30($a0)
/* 0E04A4 80149DA4 0C05265D */  jal   func_80149974
/* 0E04A8 80149DA8 E7A00010 */   swc1  $f0, 0x10($sp)
/* 0E04AC 80149DAC 0805277B */  j     .L80149DEC
/* 0E04B0 80149DB0 00000000 */   nop   

.L80149DB4:
/* 0E04B4 80149DB4 27B10018 */  addiu $s1, $sp, 0x18
/* 0E04B8 80149DB8 0220382D */  daddu $a3, $s1, $zero
/* 0E04BC 80149DBC 44060000 */  mfc1  $a2, $f0
/* 0E04C0 80149DC0 27B0001A */  addiu $s0, $sp, 0x1a
/* 0E04C4 80149DC4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E04C8 80149DC8 0C052781 */  jal   func_80149E04
/* 0E04CC 80149DCC AFA50014 */   sw    $a1, 0x14($sp)
/* 0E04D0 80149DD0 87A20018 */  lh    $v0, 0x18($sp)
/* 0E04D4 80149DD4 04400005 */  bltz  $v0, .L80149DEC
/* 0E04D8 80149DD8 0240202D */   daddu $a0, $s2, $zero
/* 0E04DC 80149DDC 92250001 */  lbu   $a1, 1($s1)
/* 0E04E0 80149DE0 92060001 */  lbu   $a2, 1($s0)
/* 0E04E4 80149DE4 0C0526AE */  jal   _play_sound
/* 0E04E8 80149DE8 0000382D */   daddu $a3, $zero, $zero
.L80149DEC:
/* 0E04EC 80149DEC 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0E04F0 80149DF0 8FB20028 */  lw    $s2, 0x28($sp)
/* 0E04F4 80149DF4 8FB10024 */  lw    $s1, 0x24($sp)
/* 0E04F8 80149DF8 8FB00020 */  lw    $s0, 0x20($sp)
/* 0E04FC 80149DFC 03E00008 */  jr    $ra
/* 0E0500 80149E00 27BD0030 */   addiu $sp, $sp, 0x30


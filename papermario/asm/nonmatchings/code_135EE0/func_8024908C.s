.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024908C
/* 13C3CC 8024908C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 13C3D0 80249090 8FB3001C */  lw    $s3, 0x1c($sp)
/* 13C3D4 80249094 8FB20018 */  lw    $s2, 0x18($sp)
/* 13C3D8 80249098 8FB10014 */  lw    $s1, 0x14($sp)
/* 13C3DC 8024909C 8FB00010 */  lw    $s0, 0x10($sp)
/* 13C3E0 802490A0 03E00008 */  jr    $ra
/* 13C3E4 802490A4 27BD0028 */   addiu $sp, $sp, 0x28

/* 13C3E8 802490A8 3C038027 */  lui   $v1, 0x8027
/* 13C3EC 802490AC 8C630280 */  lw    $v1, 0x280($v1)
/* 13C3F0 802490B0 3C098027 */  lui   $t1, 0x8027
/* 13C3F4 802490B4 8D290378 */  lw    $t1, 0x378($t1)
/* 13C3F8 802490B8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 13C3FC 802490BC AFBF001C */  sw    $ra, 0x1c($sp)
/* 13C400 802490C0 AFB20018 */  sw    $s2, 0x18($sp)
/* 13C404 802490C4 AFB10014 */  sw    $s1, 0x14($sp)
/* 13C408 802490C8 AFB00010 */  sw    $s0, 0x10($sp)
/* 13C40C 802490CC 00031040 */  sll   $v0, $v1, 1
/* 13C410 802490D0 00431021 */  addu  $v0, $v0, $v1
/* 13C414 802490D4 00021080 */  sll   $v0, $v0, 2
/* 13C418 802490D8 3C018027 */  lui   $at, 0x8027
/* 13C41C 802490DC 00220821 */  addu  $at, $at, $v0
/* 13C420 802490E0 9022028A */  lbu   $v0, 0x28a($at)
/* 13C424 802490E4 3C038027 */  lui   $v1, 0x8027
/* 13C428 802490E8 8C6300C4 */  lw    $v1, 0xc4($v1)
/* 13C42C 802490EC 14400002 */  bnez  $v0, .L802490F8
/* 13C430 802490F0 0122001A */   div   $zero, $t1, $v0
/* 13C434 802490F4 0007000D */  break 7
.L802490F8:
/* 13C438 802490F8 2401FFFF */  addiu $at, $zero, -1
/* 13C43C 802490FC 14410004 */  bne   $v0, $at, .L80249110
/* 13C440 80249100 3C018000 */   lui   $at, 0x8000
/* 13C444 80249104 15210002 */  bne   $t1, $at, .L80249110
/* 13C448 80249108 00000000 */   nop   
/* 13C44C 8024910C 0006000D */  break 6

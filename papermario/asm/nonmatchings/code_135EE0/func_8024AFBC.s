.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024AFBC
/* 13E2FC 8024AFBC 27A40050 */  addiu $a0, $sp, 0x50
/* 13E300 8024AFC0 3C108007 */  lui   $s0, 0x8007
/* 13E304 8024AFC4 261041F0 */  addiu $s0, $s0, 0x41f0
/* 13E308 8024AFC8 3C12800A */  lui   $s2, 0x800a
/* 13E30C 8024AFCC 2652A674 */  addiu $s2, $s2, -0x598c
/* 13E310 8024AFD0 96050000 */  lhu   $a1, ($s0)
/* 13E314 8024AFD4 8E420000 */  lw    $v0, ($s2)
/* 13E318 8024AFD8 00052980 */  sll   $a1, $a1, 6
/* 13E31C 8024AFDC 00B32821 */  addu  $a1, $a1, $s3
/* 13E320 8024AFE0 0C019D40 */  jal   guMtxF2L
/* 13E324 8024AFE4 00452821 */   addu  $a1, $v0, $a1
/* 13E328 8024AFE8 3C09DA38 */  lui   $t1, 0xda38
/* 13E32C 8024AFEC 35290007 */  ori   $t1, $t1, 7
/* 13E330 8024AFF0 27A40050 */  addiu $a0, $sp, 0x50
/* 13E334 8024AFF4 8E230000 */  lw    $v1, ($s1)
/* 13E338 8024AFF8 4405A000 */  mfc1  $a1, $f20
/* 13E33C 8024AFFC 4406A000 */  mfc1  $a2, $f20
/* 13E340 8024B000 4407A000 */  mfc1  $a3, $f20
/* 13E344 8024B004 96020000 */  lhu   $v0, ($s0)
/* 13E348 8024B008 0060402D */  daddu $t0, $v1, $zero
/* 13E34C 8024B00C 24630008 */  addiu $v1, $v1, 8
/* 13E350 8024B010 AE230000 */  sw    $v1, ($s1)
/* 13E354 8024B014 24430001 */  addiu $v1, $v0, 1
/* 13E358 8024B018 3042FFFF */  andi  $v0, $v0, 0xffff
/* 13E35C 8024B01C 00021180 */  sll   $v0, $v0, 6
/* 13E360 8024B020 AD090000 */  sw    $t1, ($t0)
/* 13E364 8024B024 A6030000 */  sh    $v1, ($s0)
/* 13E368 8024B028 8E430000 */  lw    $v1, ($s2)
/* 13E36C 8024B02C 00531021 */  addu  $v0, $v0, $s3
/* 13E370 8024B030 00621821 */  addu  $v1, $v1, $v0
/* 13E374 8024B034 0C019E40 */  jal   guTranslateF
/* 13E378 8024B038 AD030004 */   sw    $v1, 4($t0)
/* 13E37C 8024B03C 27A40050 */  addiu $a0, $sp, 0x50
/* 13E380 8024B040 96050000 */  lhu   $a1, ($s0)
/* 13E384 8024B044 8E420000 */  lw    $v0, ($s2)
/* 13E388 8024B048 00052980 */  sll   $a1, $a1, 6
/* 13E38C 8024B04C 00B32821 */  addu  $a1, $a1, $s3
/* 13E390 8024B050 0C019D40 */  jal   guMtxF2L
/* 13E394 8024B054 00452821 */   addu  $a1, $v0, $a1
/* 13E398 8024B058 3C04DA38 */  lui   $a0, 0xda38
/* 13E39C 8024B05C 34840002 */  ori   $a0, $a0, 2
/* 13E3A0 8024B060 3C068027 */  lui   $a2, 0x8027
/* 13E3A4 8024B064 24C606B0 */  addiu $a2, $a2, 0x6b0
/* 13E3A8 8024B068 8E230000 */  lw    $v1, ($s1)
/* 13E3AC 8024B06C 96020000 */  lhu   $v0, ($s0)
/* 13E3B0 8024B070 0060282D */  daddu $a1, $v1, $zero
/* 13E3B4 8024B074 24630008 */  addiu $v1, $v1, 8
/* 13E3B8 8024B078 AE230000 */  sw    $v1, ($s1)
/* 13E3BC 8024B07C 24430001 */  addiu $v1, $v0, 1
/* 13E3C0 8024B080 3042FFFF */  andi  $v0, $v0, 0xffff
/* 13E3C4 8024B084 00021180 */  sll   $v0, $v0, 6
/* 13E3C8 8024B088 ACA40000 */  sw    $a0, ($a1)
/* 13E3CC 8024B08C A6030000 */  sh    $v1, ($s0)
/* 13E3D0 8024B090 8E430000 */  lw    $v1, ($s2)
/* 13E3D4 8024B094 00531021 */  addu  $v0, $v0, $s3
/* 13E3D8 8024B098 00621821 */  addu  $v1, $v1, $v0
/* 13E3DC 8024B09C ACA30004 */  sw    $v1, 4($a1)
/* 13E3E0 8024B0A0 8CC20000 */  lw    $v0, ($a2)
/* 13E3E4 8024B0A4 18400042 */  blez  $v0, .L8024B1B0
/* 13E3E8 8024B0A8 0000802D */   daddu $s0, $zero, $zero
/* 13E3EC 8024B0AC 3C0141A0 */  lui   $at, 0x41a0
/* 13E3F0 8024B0B0 4481B000 */  mtc1  $at, $f22
/* 13E3F4 8024B0B4 27B200D0 */  addiu $s2, $sp, 0xd0
/* 13E3F8 8024B0B8 0200982D */  daddu $s3, $s0, $zero
.L8024B0BC:
/* 13E3FC 8024B0BC 8CC20000 */  lw    $v0, ($a2)
/* 13E400 8024B0C0 14400002 */  bnez  $v0, .L8024B0CC
/* 13E404 8024B0C4 0262001A */   div   $zero, $s3, $v0
/* 13E408 8024B0C8 0007000D */  break 7
.L8024B0CC:
/* 13E40C 8024B0CC 2401FFFF */  addiu $at, $zero, -1
/* 13E410 8024B0D0 14410004 */  bne   $v0, $at, .L8024B0E4
/* 13E414 8024B0D4 3C018000 */   lui   $at, 0x8000
/* 13E418 8024B0D8 16610002 */  bne   $s3, $at, .L8024B0E4
/* 13E41C 8024B0DC 00000000 */   nop   

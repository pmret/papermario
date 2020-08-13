.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DE2AC
/* 10139C 802DE2AC 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 1013A0 802DE2B0 AFB5002C */  sw    $s5, 0x2c($sp)
/* 1013A4 802DE2B4 0080A82D */  daddu $s5, $a0, $zero
/* 1013A8 802DE2B8 AFB20020 */  sw    $s2, 0x20($sp)
/* 1013AC 802DE2BC 32B200FF */  andi  $s2, $s5, 0xff
/* 1013B0 802DE2C0 3C03802E */  lui   $v1, 0x802e
/* 1013B4 802DE2C4 2463FA48 */  addiu $v1, $v1, -0x5b8
/* 1013B8 802DE2C8 00121080 */  sll   $v0, $s2, 2
/* 1013BC 802DE2CC 00521021 */  addu  $v0, $v0, $s2
/* 1013C0 802DE2D0 00021080 */  sll   $v0, $v0, 2
/* 1013C4 802DE2D4 AFB00018 */  sw    $s0, 0x18($sp)
/* 1013C8 802DE2D8 00438021 */  addu  $s0, $v0, $v1
/* 1013CC 802DE2DC AFB1001C */  sw    $s1, 0x1c($sp)
/* 1013D0 802DE2E0 30B100FF */  andi  $s1, $a1, 0xff
/* 1013D4 802DE2E4 00111080 */  sll   $v0, $s1, 2
/* 1013D8 802DE2E8 24420010 */  addiu $v0, $v0, 0x10
/* 1013DC 802DE2EC 00052A03 */  sra   $a1, $a1, 8
/* 1013E0 802DE2F0 AFB40028 */  sw    $s4, 0x28($sp)
/* 1013E4 802DE2F4 AFBF0038 */  sw    $ra, 0x38($sp)
/* 1013E8 802DE2F8 AFB70034 */  sw    $s7, 0x34($sp)
/* 1013EC 802DE2FC AFB60030 */  sw    $s6, 0x30($sp)
/* 1013F0 802DE300 AFB30024 */  sw    $s3, 0x24($sp)
/* 1013F4 802DE304 8E030008 */  lw    $v1, 8($s0)
/* 1013F8 802DE308 8E130004 */  lw    $s3, 4($s0)
/* 1013FC 802DE30C 44866000 */  mtc1  $a2, $f12
/* 101400 802DE310 8C770000 */  lw    $s7, ($v1)
/* 101404 802DE314 00621821 */  addu  $v1, $v1, $v0
/* 101408 802DE318 8C760000 */  lw    $s6, ($v1)
/* 10140C 802DE31C 0C0B7623 */  jal   func_802DD88C
/* 101410 802DE320 30B400FF */   andi  $s4, $a1, 0xff
/* 101414 802DE324 06A00004 */  bltz  $s5, .L802DE338
/* 101418 802DE328 0260202D */   daddu $a0, $s3, $zero
/* 10141C 802DE32C 9202000F */  lbu   $v0, 0xf($s0)
/* 101420 802DE330 10510008 */  beq   $v0, $s1, .L802DE354
/* 101424 802DE334 3C024000 */   lui   $v0, 0x4000
.L802DE338:
/* 101428 802DE338 0C0B7608 */  jal   func_802DD820
/* 10142C 802DE33C 02C0282D */   daddu $a1, $s6, $zero
/* 101430 802DE340 00141200 */  sll   $v0, $s4, 8
/* 101434 802DE344 00511025 */  or    $v0, $v0, $s1
/* 101438 802DE348 AE02000C */  sw    $v0, 0xc($s0)
/* 10143C 802DE34C AE000010 */  sw    $zero, 0x10($s0)
/* 101440 802DE350 3C024000 */  lui   $v0, 0x4000
.L802DE354:
/* 101444 802DE354 02A21024 */  and   $v0, $s5, $v0
/* 101448 802DE358 1440000F */  bnez  $v0, .L802DE398
/* 10144C 802DE35C 00121080 */   sll   $v0, $s2, 2
/* 101450 802DE360 0260282D */  daddu $a1, $s3, $zero
/* 101454 802DE364 3C02802E */  lui   $v0, 0x802e
/* 101458 802DE368 2442FA48 */  addiu $v0, $v0, -0x5b8
/* 10145C 802DE36C 00128080 */  sll   $s0, $s2, 2
/* 101460 802DE370 02128021 */  addu  $s0, $s0, $s2
/* 101464 802DE374 00108080 */  sll   $s0, $s0, 2
/* 101468 802DE378 02028021 */  addu  $s0, $s0, $v0
/* 10146C 802DE37C 02C0302D */  daddu $a2, $s6, $zero
/* 101470 802DE380 AFB40010 */  sw    $s4, 0x10($sp)
/* 101474 802DE384 8E040010 */  lw    $a0, 0x10($s0)
/* 101478 802DE388 0C0B75B7 */  jal   func_802DD6DC
/* 10147C 802DE38C 02E0382D */   daddu $a3, $s7, $zero
/* 101480 802DE390 AE020010 */  sw    $v0, 0x10($s0)
/* 101484 802DE394 00121080 */  sll   $v0, $s2, 2
.L802DE398:
/* 101488 802DE398 00521021 */  addu  $v0, $v0, $s2
/* 10148C 802DE39C 00021080 */  sll   $v0, $v0, 2
/* 101490 802DE3A0 3C01802E */  lui   $at, 0x802e
/* 101494 802DE3A4 00220821 */  addu  $at, $at, $v0
/* 101498 802DE3A8 8C22FA58 */  lw    $v0, -0x5a8($at)
/* 10149C 802DE3AC 8FBF0038 */  lw    $ra, 0x38($sp)
/* 1014A0 802DE3B0 8FB70034 */  lw    $s7, 0x34($sp)
/* 1014A4 802DE3B4 8FB60030 */  lw    $s6, 0x30($sp)
/* 1014A8 802DE3B8 8FB5002C */  lw    $s5, 0x2c($sp)
/* 1014AC 802DE3BC 8FB40028 */  lw    $s4, 0x28($sp)
/* 1014B0 802DE3C0 8FB30024 */  lw    $s3, 0x24($sp)
/* 1014B4 802DE3C4 8FB20020 */  lw    $s2, 0x20($sp)
/* 1014B8 802DE3C8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1014BC 802DE3CC 8FB00018 */  lw    $s0, 0x18($sp)
/* 1014C0 802DE3D0 03E00008 */  jr    $ra
/* 1014C4 802DE3D4 27BD0040 */   addiu $sp, $sp, 0x40


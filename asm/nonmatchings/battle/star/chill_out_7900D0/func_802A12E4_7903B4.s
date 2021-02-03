.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12E4_7903B4
/* 7903B4 802A12E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7903B8 802A12E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 7903BC 802A12EC 0080802D */  daddu     $s0, $a0, $zero
/* 7903C0 802A12F0 10A0000E */  beqz      $a1, .L802A132C
/* 7903C4 802A12F4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 7903C8 802A12F8 0C04760B */  jal       func_8011D82C
/* 7903CC 802A12FC 24040001 */   addiu    $a0, $zero, 1
/* 7903D0 802A1300 0000202D */  daddu     $a0, $zero, $zero
/* 7903D4 802A1304 0080282D */  daddu     $a1, $a0, $zero
/* 7903D8 802A1308 0080302D */  daddu     $a2, $a0, $zero
/* 7903DC 802A130C 0080382D */  daddu     $a3, $a0, $zero
/* 7903E0 802A1310 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 7903E4 802A1314 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 7903E8 802A1318 24030001 */  addiu     $v1, $zero, 1
/* 7903EC 802A131C 0C046F97 */  jal       set_background_color_blend
/* 7903F0 802A1320 A0430000 */   sb       $v1, ($v0)
/* 7903F4 802A1324 24020014 */  addiu     $v0, $zero, 0x14
/* 7903F8 802A1328 AE020070 */  sw        $v0, 0x70($s0)
.L802A132C:
/* 7903FC 802A132C 0000202D */  daddu     $a0, $zero, $zero
/* 790400 802A1330 0080282D */  daddu     $a1, $a0, $zero
/* 790404 802A1334 0080302D */  daddu     $a2, $a0, $zero
/* 790408 802A1338 8E030070 */  lw        $v1, 0x70($s0)
/* 79040C 802A133C 24020014 */  addiu     $v0, $zero, 0x14
/* 790410 802A1340 00431023 */  subu      $v0, $v0, $v1
/* 790414 802A1344 00023880 */  sll       $a3, $v0, 2
/* 790418 802A1348 00E23821 */  addu      $a3, $a3, $v0
/* 79041C 802A134C 00073840 */  sll       $a3, $a3, 1
/* 790420 802A1350 0C046F97 */  jal       set_background_color_blend
/* 790424 802A1354 30E700FE */   andi     $a3, $a3, 0xfe
/* 790428 802A1358 8E020070 */  lw        $v0, 0x70($s0)
/* 79042C 802A135C 2442FFFF */  addiu     $v0, $v0, -1
/* 790430 802A1360 AE020070 */  sw        $v0, 0x70($s0)
/* 790434 802A1364 2C420001 */  sltiu     $v0, $v0, 1
/* 790438 802A1368 8FBF0014 */  lw        $ra, 0x14($sp)
/* 79043C 802A136C 8FB00010 */  lw        $s0, 0x10($sp)
/* 790440 802A1370 00021040 */  sll       $v0, $v0, 1
/* 790444 802A1374 03E00008 */  jr        $ra
/* 790448 802A1378 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12E4_78A144
/* 78A144 802A12E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 78A148 802A12E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 78A14C 802A12EC 0080802D */  daddu     $s0, $a0, $zero
/* 78A150 802A12F0 10A0000E */  beqz      $a1, .L802A132C
/* 78A154 802A12F4 AFBF0014 */   sw       $ra, 0x14($sp)
/* 78A158 802A12F8 0C04760B */  jal       func_8011D82C
/* 78A15C 802A12FC 24040001 */   addiu    $a0, $zero, 1
/* 78A160 802A1300 0000202D */  daddu     $a0, $zero, $zero
/* 78A164 802A1304 0080282D */  daddu     $a1, $a0, $zero
/* 78A168 802A1308 0080302D */  daddu     $a2, $a0, $zero
/* 78A16C 802A130C 0080382D */  daddu     $a3, $a0, $zero
/* 78A170 802A1310 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 78A174 802A1314 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 78A178 802A1318 24030001 */  addiu     $v1, $zero, 1
/* 78A17C 802A131C 0C046F97 */  jal       set_background_color_blend
/* 78A180 802A1320 A0430000 */   sb       $v1, ($v0)
/* 78A184 802A1324 24020014 */  addiu     $v0, $zero, 0x14
/* 78A188 802A1328 AE020070 */  sw        $v0, 0x70($s0)
.L802A132C:
/* 78A18C 802A132C 0000202D */  daddu     $a0, $zero, $zero
/* 78A190 802A1330 0080282D */  daddu     $a1, $a0, $zero
/* 78A194 802A1334 0080302D */  daddu     $a2, $a0, $zero
/* 78A198 802A1338 8E030070 */  lw        $v1, 0x70($s0)
/* 78A19C 802A133C 24020014 */  addiu     $v0, $zero, 0x14
/* 78A1A0 802A1340 00431023 */  subu      $v0, $v0, $v1
/* 78A1A4 802A1344 00023880 */  sll       $a3, $v0, 2
/* 78A1A8 802A1348 00E23821 */  addu      $a3, $a3, $v0
/* 78A1AC 802A134C 00073840 */  sll       $a3, $a3, 1
/* 78A1B0 802A1350 0C046F97 */  jal       set_background_color_blend
/* 78A1B4 802A1354 30E700FE */   andi     $a3, $a3, 0xfe
/* 78A1B8 802A1358 8E020070 */  lw        $v0, 0x70($s0)
/* 78A1BC 802A135C 2442FFFF */  addiu     $v0, $v0, -1
/* 78A1C0 802A1360 AE020070 */  sw        $v0, 0x70($s0)
/* 78A1C4 802A1364 2C420001 */  sltiu     $v0, $v0, 1
/* 78A1C8 802A1368 8FBF0014 */  lw        $ra, 0x14($sp)
/* 78A1CC 802A136C 8FB00010 */  lw        $s0, 0x10($sp)
/* 78A1D0 802A1370 00021040 */  sll       $v0, $v0, 1
/* 78A1D4 802A1374 03E00008 */  jr        $ra
/* 78A1D8 802A1378 27BD0018 */   addiu    $sp, $sp, 0x18

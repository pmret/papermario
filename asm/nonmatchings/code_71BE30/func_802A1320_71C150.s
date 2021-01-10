.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1320_71C150
/* 71C150 802A1320 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 71C154 802A1324 AFB00010 */  sw        $s0, 0x10($sp)
/* 71C158 802A1328 0080802D */  daddu     $s0, $a0, $zero
/* 71C15C 802A132C 10A0000E */  beqz      $a1, .L802A1368
/* 71C160 802A1330 AFBF0014 */   sw       $ra, 0x14($sp)
/* 71C164 802A1334 0C04760B */  jal       func_8011D82C
/* 71C168 802A1338 24040001 */   addiu    $a0, $zero, 1
/* 71C16C 802A133C 0000202D */  daddu     $a0, $zero, $zero
/* 71C170 802A1340 0080282D */  daddu     $a1, $a0, $zero
/* 71C174 802A1344 0080302D */  daddu     $a2, $a0, $zero
/* 71C178 802A1348 0080382D */  daddu     $a3, $a0, $zero
/* 71C17C 802A134C 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 71C180 802A1350 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 71C184 802A1354 24030001 */  addiu     $v1, $zero, 1
/* 71C188 802A1358 0C046F97 */  jal       set_background_color_blend
/* 71C18C 802A135C A0430000 */   sb       $v1, ($v0)
/* 71C190 802A1360 24020014 */  addiu     $v0, $zero, 0x14
/* 71C194 802A1364 AE020070 */  sw        $v0, 0x70($s0)
.L802A1368:
/* 71C198 802A1368 0000202D */  daddu     $a0, $zero, $zero
/* 71C19C 802A136C 0080282D */  daddu     $a1, $a0, $zero
/* 71C1A0 802A1370 0080302D */  daddu     $a2, $a0, $zero
/* 71C1A4 802A1374 8E030070 */  lw        $v1, 0x70($s0)
/* 71C1A8 802A1378 24020014 */  addiu     $v0, $zero, 0x14
/* 71C1AC 802A137C 00431023 */  subu      $v0, $v0, $v1
/* 71C1B0 802A1380 00023880 */  sll       $a3, $v0, 2
/* 71C1B4 802A1384 00E23821 */  addu      $a3, $a3, $v0
/* 71C1B8 802A1388 00073840 */  sll       $a3, $a3, 1
/* 71C1BC 802A138C 0C046F97 */  jal       set_background_color_blend
/* 71C1C0 802A1390 30E700FE */   andi     $a3, $a3, 0xfe
/* 71C1C4 802A1394 8E020070 */  lw        $v0, 0x70($s0)
/* 71C1C8 802A1398 2442FFFF */  addiu     $v0, $v0, -1
/* 71C1CC 802A139C AE020070 */  sw        $v0, 0x70($s0)
/* 71C1D0 802A13A0 2C420001 */  sltiu     $v0, $v0, 1
/* 71C1D4 802A13A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 71C1D8 802A13A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 71C1DC 802A13AC 00021040 */  sll       $v0, $v0, 1
/* 71C1E0 802A13B0 03E00008 */  jr        $ra
/* 71C1E4 802A13B4 27BD0018 */   addiu    $sp, $sp, 0x18

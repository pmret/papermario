.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1444_71DBB4
/* 71DBB4 802A1444 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 71DBB8 802A1448 AFB00010 */  sw        $s0, 0x10($sp)
/* 71DBBC 802A144C 0080802D */  daddu     $s0, $a0, $zero
/* 71DBC0 802A1450 10A0000E */  beqz      $a1, .L802A148C
/* 71DBC4 802A1454 AFBF0014 */   sw       $ra, 0x14($sp)
/* 71DBC8 802A1458 0C04760B */  jal       func_8011D82C
/* 71DBCC 802A145C 24040001 */   addiu    $a0, $zero, 1
/* 71DBD0 802A1460 0000202D */  daddu     $a0, $zero, $zero
/* 71DBD4 802A1464 0080282D */  daddu     $a1, $a0, $zero
/* 71DBD8 802A1468 0080302D */  daddu     $a2, $a0, $zero
/* 71DBDC 802A146C 0080382D */  daddu     $a3, $a0, $zero
/* 71DBE0 802A1470 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 71DBE4 802A1474 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 71DBE8 802A1478 24030001 */  addiu     $v1, $zero, 1
/* 71DBEC 802A147C 0C046F97 */  jal       set_background_color_blend
/* 71DBF0 802A1480 A0430000 */   sb       $v1, ($v0)
/* 71DBF4 802A1484 2402000A */  addiu     $v0, $zero, 0xa
/* 71DBF8 802A1488 AE020070 */  sw        $v0, 0x70($s0)
.L802A148C:
/* 71DBFC 802A148C 0000202D */  daddu     $a0, $zero, $zero
/* 71DC00 802A1490 0080282D */  daddu     $a1, $a0, $zero
/* 71DC04 802A1494 0080302D */  daddu     $a2, $a0, $zero
/* 71DC08 802A1498 8E020070 */  lw        $v0, 0x70($s0)
/* 71DC0C 802A149C 2407000A */  addiu     $a3, $zero, 0xa
/* 71DC10 802A14A0 00E23823 */  subu      $a3, $a3, $v0
/* 71DC14 802A14A4 00073900 */  sll       $a3, $a3, 4
/* 71DC18 802A14A8 0C046F97 */  jal       set_background_color_blend
/* 71DC1C 802A14AC 30E700F0 */   andi     $a3, $a3, 0xf0
/* 71DC20 802A14B0 8E020070 */  lw        $v0, 0x70($s0)
/* 71DC24 802A14B4 2442FFFF */  addiu     $v0, $v0, -1
/* 71DC28 802A14B8 AE020070 */  sw        $v0, 0x70($s0)
/* 71DC2C 802A14BC 2C420001 */  sltiu     $v0, $v0, 1
/* 71DC30 802A14C0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 71DC34 802A14C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 71DC38 802A14C8 00021040 */  sll       $v0, $v0, 1
/* 71DC3C 802A14CC 03E00008 */  jr        $ra
/* 71DC40 802A14D0 27BD0018 */   addiu    $sp, $sp, 0x18

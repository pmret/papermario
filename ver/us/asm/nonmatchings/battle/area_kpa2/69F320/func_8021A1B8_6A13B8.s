.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021A1B8_6A13B8
/* 6A13B8 8021A1B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A13BC 8021A1BC AFB20018 */  sw        $s2, 0x18($sp)
/* 6A13C0 8021A1C0 0080902D */  daddu     $s2, $a0, $zero
/* 6A13C4 8021A1C4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A13C8 8021A1C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A13CC 8021A1CC AFB00010 */  sw        $s0, 0x10($sp)
/* 6A13D0 8021A1D0 8E440148 */  lw        $a0, 0x148($s2)
/* 6A13D4 8021A1D4 0C09A75B */  jal       get_actor
/* 6A13D8 8021A1D8 8E50000C */   lw       $s0, 0xc($s2)
/* 6A13DC 8021A1DC 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 6A13E0 8021A1E0 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 6A13E4 8021A1E4 80430210 */  lb        $v1, 0x210($v0)
/* 6A13E8 8021A1E8 2402000A */  addiu     $v0, $zero, 0xa
/* 6A13EC 8021A1EC 1062000D */  beq       $v1, $v0, .L8021A224
/* 6A13F0 8021A1F0 2403FFFF */   addiu    $v1, $zero, -1
/* 6A13F4 8021A1F4 822200AE */  lb        $v0, 0xae($s1)
/* 6A13F8 8021A1F8 10430007 */  beq       $v0, $v1, .L8021A218
/* 6A13FC 8021A1FC 0240202D */   daddu    $a0, $s2, $zero
/* 6A1400 8021A200 822200AF */  lb        $v0, 0xaf($s1)
/* 6A1404 8021A204 10430004 */  beq       $v0, $v1, .L8021A218
/* 6A1408 8021A208 00000000 */   nop
/* 6A140C 8021A20C 822200B0 */  lb        $v0, 0xb0($s1)
/* 6A1410 8021A210 14430005 */  bne       $v0, $v1, .L8021A228
/* 6A1414 8021A214 00000000 */   nop
.L8021A218:
/* 6A1418 8021A218 8E050000 */  lw        $a1, ($s0)
/* 6A141C 8021A21C 0808688C */  j         .L8021A230
/* 6A1420 8021A220 0000302D */   daddu    $a2, $zero, $zero
.L8021A224:
/* 6A1424 8021A224 0240202D */  daddu     $a0, $s2, $zero
.L8021A228:
/* 6A1428 8021A228 8E050000 */  lw        $a1, ($s0)
/* 6A142C 8021A22C 2406FFFF */  addiu     $a2, $zero, -1
.L8021A230:
/* 6A1430 8021A230 0C0B2026 */  jal       set_variable
/* 6A1434 8021A234 00000000 */   nop
/* 6A1438 8021A238 24020002 */  addiu     $v0, $zero, 2
/* 6A143C 8021A23C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A1440 8021A240 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A1444 8021A244 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A1448 8021A248 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A144C 8021A24C 03E00008 */  jr        $ra
/* 6A1450 8021A250 27BD0020 */   addiu    $sp, $sp, 0x20

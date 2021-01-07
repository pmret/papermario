.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B570_6A2770
/* 6A2770 8021B570 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A2774 8021B574 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A2778 8021B578 0080902D */  daddu     $s2, $a0, $zero
/* 6A277C 8021B57C AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A2780 8021B580 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A2784 8021B584 AFB00010 */  sw        $s0, 0x10($sp)
/* 6A2788 8021B588 8E440148 */  lw        $a0, 0x148($s2)
/* 6A278C 8021B58C 0C09A75B */  jal       get_actor
/* 6A2790 8021B590 8E50000C */   lw       $s0, 0xc($s2)
/* 6A2794 8021B594 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 6A2798 8021B598 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 6A279C 8021B59C 80430210 */  lb        $v1, 0x210($v0)
/* 6A27A0 8021B5A0 2402000A */  addiu     $v0, $zero, 0xa
/* 6A27A4 8021B5A4 1062000D */  beq       $v1, $v0, .L8021B5DC
/* 6A27A8 8021B5A8 2403FFFF */   addiu    $v1, $zero, -1
/* 6A27AC 8021B5AC 822200AE */  lb        $v0, 0xae($s1)
/* 6A27B0 8021B5B0 10430007 */  beq       $v0, $v1, .L8021B5D0
/* 6A27B4 8021B5B4 0240202D */   daddu    $a0, $s2, $zero
/* 6A27B8 8021B5B8 822200AF */  lb        $v0, 0xaf($s1)
/* 6A27BC 8021B5BC 10430004 */  beq       $v0, $v1, .L8021B5D0
/* 6A27C0 8021B5C0 00000000 */   nop      
/* 6A27C4 8021B5C4 822200B0 */  lb        $v0, 0xb0($s1)
/* 6A27C8 8021B5C8 14430005 */  bne       $v0, $v1, .L8021B5E0
/* 6A27CC 8021B5CC 00000000 */   nop      
.L8021B5D0:
/* 6A27D0 8021B5D0 8E050000 */  lw        $a1, ($s0)
/* 6A27D4 8021B5D4 08086D7A */  j         .L8021B5E8
/* 6A27D8 8021B5D8 0000302D */   daddu    $a2, $zero, $zero
.L8021B5DC:
/* 6A27DC 8021B5DC 0240202D */  daddu     $a0, $s2, $zero
.L8021B5E0:
/* 6A27E0 8021B5E0 8E050000 */  lw        $a1, ($s0)
/* 6A27E4 8021B5E4 2406FFFF */  addiu     $a2, $zero, -1
.L8021B5E8:
/* 6A27E8 8021B5E8 0C0B2026 */  jal       set_variable
/* 6A27EC 8021B5EC 00000000 */   nop      
/* 6A27F0 8021B5F0 24020002 */  addiu     $v0, $zero, 2
/* 6A27F4 8021B5F4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A27F8 8021B5F8 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A27FC 8021B5FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A2800 8021B600 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A2804 8021B604 03E00008 */  jr        $ra
/* 6A2808 8021B608 27BD0020 */   addiu    $sp, $sp, 0x20

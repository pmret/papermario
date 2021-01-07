.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021CEB8_6A40B8
/* 6A40B8 8021CEB8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A40BC 8021CEBC AFB20018 */  sw        $s2, 0x18($sp)
/* 6A40C0 8021CEC0 0080902D */  daddu     $s2, $a0, $zero
/* 6A40C4 8021CEC4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A40C8 8021CEC8 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A40CC 8021CECC AFB00010 */  sw        $s0, 0x10($sp)
/* 6A40D0 8021CED0 8E440148 */  lw        $a0, 0x148($s2)
/* 6A40D4 8021CED4 0C09A75B */  jal       get_actor
/* 6A40D8 8021CED8 8E50000C */   lw       $s0, 0xc($s2)
/* 6A40DC 8021CEDC 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 6A40E0 8021CEE0 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 6A40E4 8021CEE4 80430210 */  lb        $v1, 0x210($v0)
/* 6A40E8 8021CEE8 2402000A */  addiu     $v0, $zero, 0xa
/* 6A40EC 8021CEEC 1062000D */  beq       $v1, $v0, .L8021CF24
/* 6A40F0 8021CEF0 2403FFFF */   addiu    $v1, $zero, -1
/* 6A40F4 8021CEF4 822200AE */  lb        $v0, 0xae($s1)
/* 6A40F8 8021CEF8 10430007 */  beq       $v0, $v1, .L8021CF18
/* 6A40FC 8021CEFC 0240202D */   daddu    $a0, $s2, $zero
/* 6A4100 8021CF00 822200AF */  lb        $v0, 0xaf($s1)
/* 6A4104 8021CF04 10430004 */  beq       $v0, $v1, .L8021CF18
/* 6A4108 8021CF08 00000000 */   nop      
/* 6A410C 8021CF0C 822200B0 */  lb        $v0, 0xb0($s1)
/* 6A4110 8021CF10 14430005 */  bne       $v0, $v1, .L8021CF28
/* 6A4114 8021CF14 00000000 */   nop      
.L8021CF18:
/* 6A4118 8021CF18 8E050000 */  lw        $a1, ($s0)
/* 6A411C 8021CF1C 080873CC */  j         .L8021CF30
/* 6A4120 8021CF20 0000302D */   daddu    $a2, $zero, $zero
.L8021CF24:
/* 6A4124 8021CF24 0240202D */  daddu     $a0, $s2, $zero
.L8021CF28:
/* 6A4128 8021CF28 8E050000 */  lw        $a1, ($s0)
/* 6A412C 8021CF2C 2406FFFF */  addiu     $a2, $zero, -1
.L8021CF30:
/* 6A4130 8021CF30 0C0B2026 */  jal       set_variable
/* 6A4134 8021CF34 00000000 */   nop      
/* 6A4138 8021CF38 24020002 */  addiu     $v0, $zero, 2
/* 6A413C 8021CF3C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6A4140 8021CF40 8FB20018 */  lw        $s2, 0x18($sp)
/* 6A4144 8021CF44 8FB10014 */  lw        $s1, 0x14($sp)
/* 6A4148 8021CF48 8FB00010 */  lw        $s0, 0x10($sp)
/* 6A414C 8021CF4C 03E00008 */  jr        $ra
/* 6A4150 8021CF50 27BD0020 */   addiu    $sp, $sp, 0x20

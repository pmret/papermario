.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_429D20
/* 429D20 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 429D24 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 429D28 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 429D2C 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 429D30 802A9010 24020005 */  addiu     $v0, $zero, 5
/* 429D34 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 429D38 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 429D3C 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 429D40 802A9020 3C028029 */  lui       $v0, %hi(D_80294380)
/* 429D44 802A9024 24424380 */  addiu     $v0, $v0, %lo(D_80294380)
/* 429D48 802A9028 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 429D4C 802A902C 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 429D50 802A9030 AE020434 */  sw        $v0, 0x434($s0)
/* 429D54 802A9034 82020083 */  lb        $v0, 0x83($s0)
/* 429D58 802A9038 10400031 */  beqz      $v0, .L802A9100
/* 429D5C 802A903C 0200182D */   daddu    $v1, $s0, $zero
/* 429D60 802A9040 0C09A216 */  jal       func_80268858
/* 429D64 802A9044 00000000 */   nop
/* 429D68 802A9048 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 429D6C 802A904C 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 429D70 802A9050 2402000F */  addiu     $v0, $zero, 0xf
/* 429D74 802A9054 A622004A */  sh        $v0, 0x4a($s1)
/* 429D78 802A9058 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 429D7C 802A905C A620004C */  sh        $zero, 0x4c($s1)
/* 429D80 802A9060 A2200060 */  sb        $zero, 0x60($s1)
/* 429D84 802A9064 A6200044 */  sh        $zero, 0x44($s1)
/* 429D88 802A9068 A6200048 */  sh        $zero, 0x48($s1)
/* 429D8C 802A906C A2000084 */  sb        $zero, 0x84($s0)
/* 429D90 802A9070 A6220056 */  sh        $v0, 0x56($s1)
/* 429D94 802A9074 24020050 */  addiu     $v0, $zero, 0x50
/* 429D98 802A9078 A220005C */  sb        $zero, 0x5c($s1)
/* 429D9C 802A907C 0C050529 */  jal       create_hud_element
/* 429DA0 802A9080 A6220058 */   sh       $v0, 0x58($s1)
/* 429DA4 802A9084 0040802D */  daddu     $s0, $v0, $zero
/* 429DA8 802A9088 0200202D */  daddu     $a0, $s0, $zero
/* 429DAC 802A908C 24050082 */  addiu     $a1, $zero, 0x82
/* 429DB0 802A9090 0C051280 */  jal       set_hud_element_flags
/* 429DB4 802A9094 AE300004 */   sw       $s0, 4($s1)
/* 429DB8 802A9098 86250056 */  lh        $a1, 0x56($s1)
/* 429DBC 802A909C 86260058 */  lh        $a2, 0x58($s1)
/* 429DC0 802A90A0 0C051261 */  jal       set_hud_element_render_pos
/* 429DC4 802A90A4 0200202D */   daddu    $a0, $s0, $zero
/* 429DC8 802A90A8 0200202D */  daddu     $a0, $s0, $zero
/* 429DCC 802A90AC 0C051277 */  jal       set_hud_element_render_depth
/* 429DD0 802A90B0 0000282D */   daddu    $a1, $zero, $zero
/* 429DD4 802A90B4 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 429DD8 802A90B8 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 429DDC 802A90BC 0C050529 */  jal       create_hud_element
/* 429DE0 802A90C0 00000000 */   nop
/* 429DE4 802A90C4 0040802D */  daddu     $s0, $v0, $zero
/* 429DE8 802A90C8 86250056 */  lh        $a1, 0x56($s1)
/* 429DEC 802A90CC 86260058 */  lh        $a2, 0x58($s1)
/* 429DF0 802A90D0 0200202D */  daddu     $a0, $s0, $zero
/* 429DF4 802A90D4 AE300008 */  sw        $s0, 8($s1)
/* 429DF8 802A90D8 0C051261 */  jal       set_hud_element_render_pos
/* 429DFC 802A90DC 24C6001C */   addiu    $a2, $a2, 0x1c
/* 429E00 802A90E0 0200202D */  daddu     $a0, $s0, $zero
/* 429E04 802A90E4 0C051277 */  jal       set_hud_element_render_depth
/* 429E08 802A90E8 0000282D */   daddu    $a1, $zero, $zero
/* 429E0C 802A90EC 0200202D */  daddu     $a0, $s0, $zero
/* 429E10 802A90F0 0C051280 */  jal       set_hud_element_flags
/* 429E14 802A90F4 24050082 */   addiu    $a1, $zero, 0x82
/* 429E18 802A90F8 080AA442 */  j         .L802A9108
/* 429E1C 802A90FC 24020002 */   addiu    $v0, $zero, 2
.L802A9100:
/* 429E20 802A9100 A0600081 */  sb        $zero, 0x81($v1)
/* 429E24 802A9104 24020002 */  addiu     $v0, $zero, 2
.L802A9108:
/* 429E28 802A9108 8FBF0018 */  lw        $ra, 0x18($sp)
/* 429E2C 802A910C 8FB10014 */  lw        $s1, 0x14($sp)
/* 429E30 802A9110 8FB00010 */  lw        $s0, 0x10($sp)
/* 429E34 802A9114 03E00008 */  jr        $ra
/* 429E38 802A9118 27BD0020 */   addiu    $sp, $sp, 0x20

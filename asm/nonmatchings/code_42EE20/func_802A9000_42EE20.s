.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_42EE20
/* 42EE20 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42EE24 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 42EE28 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 42EE2C 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 42EE30 802A9010 24020010 */  addiu     $v0, $zero, 0x10
/* 42EE34 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 42EE38 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 42EE3C 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 42EE40 802A9020 3C028029 */  lui       $v0, %hi(D_80294400)
/* 42EE44 802A9024 24424400 */  addiu     $v0, $v0, %lo(D_80294400)
/* 42EE48 802A9028 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42EE4C 802A902C 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42EE50 802A9030 AE020434 */  sw        $v0, 0x434($s0)
/* 42EE54 802A9034 82020083 */  lb        $v0, 0x83($s0)
/* 42EE58 802A9038 10400045 */  beqz      $v0, .L802A9150
/* 42EE5C 802A903C 0200182D */   daddu    $v1, $s0, $zero
/* 42EE60 802A9040 0C09A216 */  jal       func_80268858
/* 42EE64 802A9044 00000000 */   nop
/* 42EE68 802A9048 3C048011 */  lui       $a0, %hi(D_80108E1C)
/* 42EE6C 802A904C 24848E1C */  addiu     $a0, $a0, %lo(D_80108E1C)
/* 42EE70 802A9050 24020013 */  addiu     $v0, $zero, 0x13
/* 42EE74 802A9054 A622004A */  sh        $v0, 0x4a($s1)
/* 42EE78 802A9058 2402001E */  addiu     $v0, $zero, 0x1e
/* 42EE7C 802A905C A620004C */  sh        $zero, 0x4c($s1)
/* 42EE80 802A9060 A2200060 */  sb        $zero, 0x60($s1)
/* 42EE84 802A9064 A6200044 */  sh        $zero, 0x44($s1)
/* 42EE88 802A9068 A6200048 */  sh        $zero, 0x48($s1)
/* 42EE8C 802A906C A6200068 */  sh        $zero, 0x68($s1)
/* 42EE90 802A9070 A2000081 */  sb        $zero, 0x81($s0)
/* 42EE94 802A9074 A2000086 */  sb        $zero, 0x86($s0)
/* 42EE98 802A9078 A622006C */  sh        $v0, 0x6c($s1)
/* 42EE9C 802A907C 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42EEA0 802A9080 A6220056 */  sh        $v0, 0x56($s1)
/* 42EEA4 802A9084 24020050 */  addiu     $v0, $zero, 0x50
/* 42EEA8 802A9088 0C050529 */  jal       create_icon
/* 42EEAC 802A908C A6220058 */   sh       $v0, 0x58($s1)
/* 42EEB0 802A9090 0040802D */  daddu     $s0, $v0, $zero
/* 42EEB4 802A9094 86250056 */  lh        $a1, 0x56($s1)
/* 42EEB8 802A9098 86260058 */  lh        $a2, 0x58($s1)
/* 42EEBC 802A909C 0200202D */  daddu     $a0, $s0, $zero
/* 42EEC0 802A90A0 0C051261 */  jal       set_icon_render_pos
/* 42EEC4 802A90A4 AE300004 */   sw       $s0, 4($s1)
/* 42EEC8 802A90A8 0200202D */  daddu     $a0, $s0, $zero
/* 42EECC 802A90AC 0C051277 */  jal       func_801449DC
/* 42EED0 802A90B0 0000282D */   daddu    $a1, $zero, $zero
/* 42EED4 802A90B4 0200202D */  daddu     $a0, $s0, $zero
/* 42EED8 802A90B8 0C051280 */  jal       set_icon_flags
/* 42EEDC 802A90BC 24050082 */   addiu    $a1, $zero, 0x82
/* 42EEE0 802A90C0 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 42EEE4 802A90C4 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 42EEE8 802A90C8 0C050529 */  jal       create_icon
/* 42EEEC 802A90CC 00000000 */   nop
/* 42EEF0 802A90D0 0040802D */  daddu     $s0, $v0, $zero
/* 42EEF4 802A90D4 86250056 */  lh        $a1, 0x56($s1)
/* 42EEF8 802A90D8 86260058 */  lh        $a2, 0x58($s1)
/* 42EEFC 802A90DC 0200202D */  daddu     $a0, $s0, $zero
/* 42EF00 802A90E0 AE300008 */  sw        $s0, 8($s1)
/* 42EF04 802A90E4 0C051261 */  jal       set_icon_render_pos
/* 42EF08 802A90E8 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42EF0C 802A90EC 0200202D */  daddu     $a0, $s0, $zero
/* 42EF10 802A90F0 0C051277 */  jal       func_801449DC
/* 42EF14 802A90F4 0000282D */   daddu    $a1, $zero, $zero
/* 42EF18 802A90F8 0200202D */  daddu     $a0, $s0, $zero
/* 42EF1C 802A90FC 0C051280 */  jal       set_icon_flags
/* 42EF20 802A9100 24050082 */   addiu    $a1, $zero, 0x82
/* 42EF24 802A9104 3C048029 */  lui       $a0, %hi(D_80292974)
/* 42EF28 802A9108 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 42EF2C 802A910C 0C050529 */  jal       create_icon
/* 42EF30 802A9110 00000000 */   nop
/* 42EF34 802A9114 0040802D */  daddu     $s0, $v0, $zero
/* 42EF38 802A9118 86250056 */  lh        $a1, 0x56($s1)
/* 42EF3C 802A911C 86260058 */  lh        $a2, 0x58($s1)
/* 42EF40 802A9120 0200202D */  daddu     $a0, $s0, $zero
/* 42EF44 802A9124 AE30000C */  sw        $s0, 0xc($s1)
/* 42EF48 802A9128 0C051261 */  jal       set_icon_render_pos
/* 42EF4C 802A912C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42EF50 802A9130 0200202D */  daddu     $a0, $s0, $zero
/* 42EF54 802A9134 0C051277 */  jal       func_801449DC
/* 42EF58 802A9138 0000282D */   daddu    $a1, $zero, $zero
/* 42EF5C 802A913C 0200202D */  daddu     $a0, $s0, $zero
/* 42EF60 802A9140 0C051280 */  jal       set_icon_flags
/* 42EF64 802A9144 24050082 */   addiu    $a1, $zero, 0x82
/* 42EF68 802A9148 080AA456 */  j         .L802A9158
/* 42EF6C 802A914C 24020002 */   addiu    $v0, $zero, 2
.L802A9150:
/* 42EF70 802A9150 A0600081 */  sb        $zero, 0x81($v1)
/* 42EF74 802A9154 24020002 */  addiu     $v0, $zero, 2
.L802A9158:
/* 42EF78 802A9158 8FBF0018 */  lw        $ra, 0x18($sp)
/* 42EF7C 802A915C 8FB10014 */  lw        $s1, 0x14($sp)
/* 42EF80 802A9160 8FB00010 */  lw        $s0, 0x10($sp)
/* 42EF84 802A9164 03E00008 */  jr        $ra
/* 42EF88 802A9168 27BD0020 */   addiu    $sp, $sp, 0x20

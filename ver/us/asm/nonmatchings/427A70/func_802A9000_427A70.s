.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_427A70
/* 427A70 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 427A74 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 427A78 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 427A7C 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 427A80 802A9010 24020064 */  addiu     $v0, $zero, 0x64
/* 427A84 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 427A88 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 427A8C 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 427A90 802A9020 3C028029 */  lui       $v0, %hi(D_80294300)
/* 427A94 802A9024 24424300 */  addiu     $v0, $v0, %lo(D_80294300)
/* 427A98 802A9028 AE020434 */  sw        $v0, 0x434($s0)
/* 427A9C 802A902C 2402007F */  addiu     $v0, $zero, 0x7f
/* 427AA0 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 427AA4 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 427AA8 802A9038 A2020086 */  sb        $v0, 0x86($s0)
/* 427AAC 802A903C 82020083 */  lb        $v0, 0x83($s0)
/* 427AB0 802A9040 10400044 */  beqz      $v0, .L802A9154
/* 427AB4 802A9044 0200182D */   daddu    $v1, $s0, $zero
/* 427AB8 802A9048 0C09A216 */  jal       func_80268858
/* 427ABC 802A904C 00000000 */   nop
/* 427AC0 802A9050 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 427AC4 802A9054 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 427AC8 802A9058 2402000B */  addiu     $v0, $zero, 0xb
/* 427ACC 802A905C A622004A */  sh        $v0, 0x4a($s1)
/* 427AD0 802A9060 24020001 */  addiu     $v0, $zero, 1
/* 427AD4 802A9064 A2220061 */  sb        $v0, 0x61($s1)
/* 427AD8 802A9068 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 427ADC 802A906C A620004C */  sh        $zero, 0x4c($s1)
/* 427AE0 802A9070 A2200060 */  sb        $zero, 0x60($s1)
/* 427AE4 802A9074 A6200044 */  sh        $zero, 0x44($s1)
/* 427AE8 802A9078 A6200048 */  sh        $zero, 0x48($s1)
/* 427AEC 802A907C A6200068 */  sh        $zero, 0x68($s1)
/* 427AF0 802A9080 A2000081 */  sb        $zero, 0x81($s0)
/* 427AF4 802A9084 A6220056 */  sh        $v0, 0x56($s1)
/* 427AF8 802A9088 24020050 */  addiu     $v0, $zero, 0x50
/* 427AFC 802A908C 0C050529 */  jal       create_hud_element
/* 427B00 802A9090 A6220058 */   sh       $v0, 0x58($s1)
/* 427B04 802A9094 0040802D */  daddu     $s0, $v0, $zero
/* 427B08 802A9098 86250056 */  lh        $a1, 0x56($s1)
/* 427B0C 802A909C 86260058 */  lh        $a2, 0x58($s1)
/* 427B10 802A90A0 0200202D */  daddu     $a0, $s0, $zero
/* 427B14 802A90A4 0C051261 */  jal       set_hud_element_render_pos
/* 427B18 802A90A8 AE300004 */   sw       $s0, 4($s1)
/* 427B1C 802A90AC 0200202D */  daddu     $a0, $s0, $zero
/* 427B20 802A90B0 0C051277 */  jal       set_hud_element_render_depth
/* 427B24 802A90B4 0000282D */   daddu    $a1, $zero, $zero
/* 427B28 802A90B8 0200202D */  daddu     $a0, $s0, $zero
/* 427B2C 802A90BC 0C051280 */  jal       set_hud_element_flags
/* 427B30 802A90C0 24050082 */   addiu    $a1, $zero, 0x82
/* 427B34 802A90C4 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 427B38 802A90C8 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 427B3C 802A90CC 0C050529 */  jal       create_hud_element
/* 427B40 802A90D0 00000000 */   nop
/* 427B44 802A90D4 0040802D */  daddu     $s0, $v0, $zero
/* 427B48 802A90D8 86250056 */  lh        $a1, 0x56($s1)
/* 427B4C 802A90DC 86260058 */  lh        $a2, 0x58($s1)
/* 427B50 802A90E0 0200202D */  daddu     $a0, $s0, $zero
/* 427B54 802A90E4 AE300008 */  sw        $s0, 8($s1)
/* 427B58 802A90E8 0C051261 */  jal       set_hud_element_render_pos
/* 427B5C 802A90EC 24C6001C */   addiu    $a2, $a2, 0x1c
/* 427B60 802A90F0 0200202D */  daddu     $a0, $s0, $zero
/* 427B64 802A90F4 0C051277 */  jal       set_hud_element_render_depth
/* 427B68 802A90F8 0000282D */   daddu    $a1, $zero, $zero
/* 427B6C 802A90FC 0200202D */  daddu     $a0, $s0, $zero
/* 427B70 802A9100 0C051280 */  jal       set_hud_element_flags
/* 427B74 802A9104 24050082 */   addiu    $a1, $zero, 0x82
/* 427B78 802A9108 3C048029 */  lui       $a0, %hi(D_80292974)
/* 427B7C 802A910C 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 427B80 802A9110 0C050529 */  jal       create_hud_element
/* 427B84 802A9114 00000000 */   nop
/* 427B88 802A9118 0040802D */  daddu     $s0, $v0, $zero
/* 427B8C 802A911C 86250056 */  lh        $a1, 0x56($s1)
/* 427B90 802A9120 86260058 */  lh        $a2, 0x58($s1)
/* 427B94 802A9124 0200202D */  daddu     $a0, $s0, $zero
/* 427B98 802A9128 AE30000C */  sw        $s0, 0xc($s1)
/* 427B9C 802A912C 0C051261 */  jal       set_hud_element_render_pos
/* 427BA0 802A9130 24C6001C */   addiu    $a2, $a2, 0x1c
/* 427BA4 802A9134 0200202D */  daddu     $a0, $s0, $zero
/* 427BA8 802A9138 0C051277 */  jal       set_hud_element_render_depth
/* 427BAC 802A913C 0000282D */   daddu    $a1, $zero, $zero
/* 427BB0 802A9140 0200202D */  daddu     $a0, $s0, $zero
/* 427BB4 802A9144 0C051280 */  jal       set_hud_element_flags
/* 427BB8 802A9148 24050082 */   addiu    $a1, $zero, 0x82
/* 427BBC 802A914C 080AA457 */  j         .L802A915C
/* 427BC0 802A9150 24020002 */   addiu    $v0, $zero, 2
.L802A9154:
/* 427BC4 802A9154 A0600081 */  sb        $zero, 0x81($v1)
/* 427BC8 802A9158 24020002 */  addiu     $v0, $zero, 2
.L802A915C:
/* 427BCC 802A915C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 427BD0 802A9160 8FB10014 */  lw        $s1, 0x14($sp)
/* 427BD4 802A9164 8FB00010 */  lw        $s0, 0x10($sp)
/* 427BD8 802A9168 03E00008 */  jr        $ra
/* 427BDC 802A916C 27BD0020 */   addiu    $sp, $sp, 0x20

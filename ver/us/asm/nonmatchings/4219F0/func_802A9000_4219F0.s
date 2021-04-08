.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_4219F0
/* 4219F0 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4219F4 802A9004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 4219F8 802A9008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 4219FC 802A900C 24020001 */  addiu     $v0, $zero, 1
/* 421A00 802A9010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 421A04 802A9014 AFB10014 */  sw        $s1, 0x14($sp)
/* 421A08 802A9018 AFB00010 */  sw        $s0, 0x10($sp)
/* 421A0C 802A901C A0620082 */  sb        $v0, 0x82($v1)
/* 421A10 802A9020 3C028029 */  lui       $v0, %hi(D_802941C0)
/* 421A14 802A9024 244241C0 */  addiu     $v0, $v0, %lo(D_802941C0)
/* 421A18 802A9028 AC620434 */  sw        $v0, 0x434($v1)
/* 421A1C 802A902C 80620083 */  lb        $v0, 0x83($v1)
/* 421A20 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 421A24 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 421A28 802A9038 10400032 */  beqz      $v0, .L802A9104
/* 421A2C 802A903C A0600086 */   sb       $zero, 0x86($v1)
/* 421A30 802A9040 0C09A216 */  jal       func_80268858
/* 421A34 802A9044 00000000 */   nop
/* 421A38 802A9048 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 421A3C 802A904C 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 421A40 802A9050 24020001 */  addiu     $v0, $zero, 1
/* 421A44 802A9054 A622004A */  sh        $v0, 0x4a($s1)
/* 421A48 802A9058 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 421A4C 802A905C A6220056 */  sh        $v0, 0x56($s1)
/* 421A50 802A9060 24020050 */  addiu     $v0, $zero, 0x50
/* 421A54 802A9064 A620004C */  sh        $zero, 0x4c($s1)
/* 421A58 802A9068 A2200060 */  sb        $zero, 0x60($s1)
/* 421A5C 802A906C 0C050529 */  jal       create_icon
/* 421A60 802A9070 A6220058 */   sh       $v0, 0x58($s1)
/* 421A64 802A9074 0040802D */  daddu     $s0, $v0, $zero
/* 421A68 802A9078 0200202D */  daddu     $a0, $s0, $zero
/* 421A6C 802A907C 24050082 */  addiu     $a1, $zero, 0x82
/* 421A70 802A9080 0C051280 */  jal       set_icon_flags
/* 421A74 802A9084 AE300004 */   sw       $s0, 4($s1)
/* 421A78 802A9088 86250056 */  lh        $a1, 0x56($s1)
/* 421A7C 802A908C 86260058 */  lh        $a2, 0x58($s1)
/* 421A80 802A9090 0C051261 */  jal       set_icon_render_pos
/* 421A84 802A9094 0200202D */   daddu    $a0, $s0, $zero
/* 421A88 802A9098 0200202D */  daddu     $a0, $s0, $zero
/* 421A8C 802A909C 0C051277 */  jal       func_801449DC
/* 421A90 802A90A0 0000282D */   daddu    $a1, $zero, $zero
/* 421A94 802A90A4 0200202D */  daddu     $a0, $s0, $zero
/* 421A98 802A90A8 0C0513AC */  jal       icon_set_opacity
/* 421A9C 802A90AC 240500FF */   addiu    $a1, $zero, 0xff
/* 421AA0 802A90B0 3C048029 */  lui       $a0, %hi(D_80292A2C)
/* 421AA4 802A90B4 24842A2C */  addiu     $a0, $a0, %lo(D_80292A2C)
/* 421AA8 802A90B8 0C050529 */  jal       create_icon
/* 421AAC 802A90BC 00000000 */   nop
/* 421AB0 802A90C0 0040802D */  daddu     $s0, $v0, $zero
/* 421AB4 802A90C4 0200202D */  daddu     $a0, $s0, $zero
/* 421AB8 802A90C8 24050082 */  addiu     $a1, $zero, 0x82
/* 421ABC 802A90CC 0C051280 */  jal       set_icon_flags
/* 421AC0 802A90D0 AE300008 */   sw       $s0, 8($s1)
/* 421AC4 802A90D4 86250056 */  lh        $a1, 0x56($s1)
/* 421AC8 802A90D8 86260058 */  lh        $a2, 0x58($s1)
/* 421ACC 802A90DC 0C051261 */  jal       set_icon_render_pos
/* 421AD0 802A90E0 0200202D */   daddu    $a0, $s0, $zero
/* 421AD4 802A90E4 0200202D */  daddu     $a0, $s0, $zero
/* 421AD8 802A90E8 0C051277 */  jal       func_801449DC
/* 421ADC 802A90EC 0000282D */   daddu    $a1, $zero, $zero
/* 421AE0 802A90F0 0200202D */  daddu     $a0, $s0, $zero
/* 421AE4 802A90F4 0C0513AC */  jal       icon_set_opacity
/* 421AE8 802A90F8 240500FF */   addiu    $a1, $zero, 0xff
/* 421AEC 802A90FC 080AA443 */  j         .L802A910C
/* 421AF0 802A9100 24020002 */   addiu    $v0, $zero, 2
.L802A9104:
/* 421AF4 802A9104 A0600081 */  sb        $zero, 0x81($v1)
/* 421AF8 802A9108 24020002 */  addiu     $v0, $zero, 2
.L802A910C:
/* 421AFC 802A910C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 421B00 802A9110 8FB10014 */  lw        $s1, 0x14($sp)
/* 421B04 802A9114 8FB00010 */  lw        $s0, 0x10($sp)
/* 421B08 802A9118 03E00008 */  jr        $ra
/* 421B0C 802A911C 27BD0020 */   addiu    $sp, $sp, 0x20

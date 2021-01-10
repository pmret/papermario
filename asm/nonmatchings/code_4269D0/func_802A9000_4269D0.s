.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_4269D0
/* 4269D0 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4269D4 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 4269D8 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 4269DC 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 4269E0 802A9010 24020064 */  addiu     $v0, $zero, 0x64
/* 4269E4 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4269E8 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 4269EC 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 4269F0 802A9020 3C028029 */  lui       $v0, %hi(D_802942C0)
/* 4269F4 802A9024 244242C0 */  addiu     $v0, $v0, %lo(D_802942C0)
/* 4269F8 802A9028 AE020434 */  sw        $v0, 0x434($s0)
/* 4269FC 802A902C 2402007F */  addiu     $v0, $zero, 0x7f
/* 426A00 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 426A04 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 426A08 802A9038 A2020086 */  sb        $v0, 0x86($s0)
/* 426A0C 802A903C 82020083 */  lb        $v0, 0x83($s0)
/* 426A10 802A9040 10400046 */  beqz      $v0, .L802A915C
/* 426A14 802A9044 0200182D */   daddu    $v1, $s0, $zero
/* 426A18 802A9048 0C09A216 */  jal       func_80268858
/* 426A1C 802A904C 00000000 */   nop      
/* 426A20 802A9050 3C048011 */  lui       $a0, %hi(D_80108E1C)
/* 426A24 802A9054 24848E1C */  addiu     $a0, $a0, %lo(D_80108E1C)
/* 426A28 802A9058 24020009 */  addiu     $v0, $zero, 9
/* 426A2C 802A905C A622004A */  sh        $v0, 0x4a($s1)
/* 426A30 802A9060 24020001 */  addiu     $v0, $zero, 1
/* 426A34 802A9064 A2220061 */  sb        $v0, 0x61($s1)
/* 426A38 802A9068 2402001E */  addiu     $v0, $zero, 0x1e
/* 426A3C 802A906C A622006C */  sh        $v0, 0x6c($s1)
/* 426A40 802A9070 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 426A44 802A9074 A620004C */  sh        $zero, 0x4c($s1)
/* 426A48 802A9078 A2200060 */  sb        $zero, 0x60($s1)
/* 426A4C 802A907C A6200044 */  sh        $zero, 0x44($s1)
/* 426A50 802A9080 A6200048 */  sh        $zero, 0x48($s1)
/* 426A54 802A9084 A6200068 */  sh        $zero, 0x68($s1)
/* 426A58 802A9088 A2000081 */  sb        $zero, 0x81($s0)
/* 426A5C 802A908C A6220056 */  sh        $v0, 0x56($s1)
/* 426A60 802A9090 24020050 */  addiu     $v0, $zero, 0x50
/* 426A64 802A9094 0C050529 */  jal       create_icon
/* 426A68 802A9098 A6220058 */   sh       $v0, 0x58($s1)
/* 426A6C 802A909C 0040802D */  daddu     $s0, $v0, $zero
/* 426A70 802A90A0 86250056 */  lh        $a1, 0x56($s1)
/* 426A74 802A90A4 86260058 */  lh        $a2, 0x58($s1)
/* 426A78 802A90A8 0200202D */  daddu     $a0, $s0, $zero
/* 426A7C 802A90AC 0C051261 */  jal       set_icon_render_pos
/* 426A80 802A90B0 AE300004 */   sw       $s0, 4($s1)
/* 426A84 802A90B4 0200202D */  daddu     $a0, $s0, $zero
/* 426A88 802A90B8 0C051277 */  jal       func_801449DC
/* 426A8C 802A90BC 0000282D */   daddu    $a1, $zero, $zero
/* 426A90 802A90C0 0200202D */  daddu     $a0, $s0, $zero
/* 426A94 802A90C4 0C051280 */  jal       set_icon_flags
/* 426A98 802A90C8 24050082 */   addiu    $a1, $zero, 0x82
/* 426A9C 802A90CC 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 426AA0 802A90D0 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 426AA4 802A90D4 0C050529 */  jal       create_icon
/* 426AA8 802A90D8 00000000 */   nop      
/* 426AAC 802A90DC 0040802D */  daddu     $s0, $v0, $zero
/* 426AB0 802A90E0 86250056 */  lh        $a1, 0x56($s1)
/* 426AB4 802A90E4 86260058 */  lh        $a2, 0x58($s1)
/* 426AB8 802A90E8 0200202D */  daddu     $a0, $s0, $zero
/* 426ABC 802A90EC AE300008 */  sw        $s0, 8($s1)
/* 426AC0 802A90F0 0C051261 */  jal       set_icon_render_pos
/* 426AC4 802A90F4 24C6001C */   addiu    $a2, $a2, 0x1c
/* 426AC8 802A90F8 0200202D */  daddu     $a0, $s0, $zero
/* 426ACC 802A90FC 0C051277 */  jal       func_801449DC
/* 426AD0 802A9100 0000282D */   daddu    $a1, $zero, $zero
/* 426AD4 802A9104 0200202D */  daddu     $a0, $s0, $zero
/* 426AD8 802A9108 0C051280 */  jal       set_icon_flags
/* 426ADC 802A910C 24050082 */   addiu    $a1, $zero, 0x82
/* 426AE0 802A9110 3C048029 */  lui       $a0, %hi(D_80292974)
/* 426AE4 802A9114 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 426AE8 802A9118 0C050529 */  jal       create_icon
/* 426AEC 802A911C 00000000 */   nop      
/* 426AF0 802A9120 0040802D */  daddu     $s0, $v0, $zero
/* 426AF4 802A9124 86250056 */  lh        $a1, 0x56($s1)
/* 426AF8 802A9128 86260058 */  lh        $a2, 0x58($s1)
/* 426AFC 802A912C 0200202D */  daddu     $a0, $s0, $zero
/* 426B00 802A9130 AE30000C */  sw        $s0, 0xc($s1)
/* 426B04 802A9134 0C051261 */  jal       set_icon_render_pos
/* 426B08 802A9138 24C6001C */   addiu    $a2, $a2, 0x1c
/* 426B0C 802A913C 0200202D */  daddu     $a0, $s0, $zero
/* 426B10 802A9140 0C051277 */  jal       func_801449DC
/* 426B14 802A9144 0000282D */   daddu    $a1, $zero, $zero
/* 426B18 802A9148 0200202D */  daddu     $a0, $s0, $zero
/* 426B1C 802A914C 0C051280 */  jal       set_icon_flags
/* 426B20 802A9150 24050082 */   addiu    $a1, $zero, 0x82
/* 426B24 802A9154 080AA459 */  j         .L802A9164
/* 426B28 802A9158 24020002 */   addiu    $v0, $zero, 2
.L802A915C:
/* 426B2C 802A915C A0600081 */  sb        $zero, 0x81($v1)
/* 426B30 802A9160 24020002 */  addiu     $v0, $zero, 2
.L802A9164:
/* 426B34 802A9164 8FBF0018 */  lw        $ra, 0x18($sp)
/* 426B38 802A9168 8FB10014 */  lw        $s1, 0x14($sp)
/* 426B3C 802A916C 8FB00010 */  lw        $s0, 0x10($sp)
/* 426B40 802A9170 03E00008 */  jr        $ra
/* 426B44 802A9174 27BD0020 */   addiu    $sp, $sp, 0x20

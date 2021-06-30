.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_42E3A0
/* 42E3A0 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 42E3A4 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 42E3A8 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 42E3AC 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 42E3B0 802A9010 24020064 */  addiu     $v0, $zero, 0x64
/* 42E3B4 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 42E3B8 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 42E3BC 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 42E3C0 802A9020 3C028029 */  lui       $v0, %hi(D_802943E0)
/* 42E3C4 802A9024 244243E0 */  addiu     $v0, $v0, %lo(D_802943E0)
/* 42E3C8 802A9028 AE020434 */  sw        $v0, 0x434($s0)
/* 42E3CC 802A902C 2402007F */  addiu     $v0, $zero, 0x7f
/* 42E3D0 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42E3D4 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 42E3D8 802A9038 A2020086 */  sb        $v0, 0x86($s0)
/* 42E3DC 802A903C 82020083 */  lb        $v0, 0x83($s0)
/* 42E3E0 802A9040 10400047 */  beqz      $v0, .L802A9160
/* 42E3E4 802A9044 0200182D */   daddu    $v1, $s0, $zero
/* 42E3E8 802A9048 0C09A216 */  jal       func_80268858
/* 42E3EC 802A904C 00000000 */   nop
/* 42E3F0 802A9050 3C048011 */  lui       $a0, %hi(D_80108E1C)
/* 42E3F4 802A9054 24848E1C */  addiu     $a0, $a0, %lo(D_80108E1C)
/* 42E3F8 802A9058 24020012 */  addiu     $v0, $zero, 0x12
/* 42E3FC 802A905C A622004A */  sh        $v0, 0x4a($s1)
/* 42E400 802A9060 24020001 */  addiu     $v0, $zero, 1
/* 42E404 802A9064 A2220061 */  sb        $v0, 0x61($s1)
/* 42E408 802A9068 2402001E */  addiu     $v0, $zero, 0x1e
/* 42E40C 802A906C A622006C */  sh        $v0, 0x6c($s1)
/* 42E410 802A9070 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42E414 802A9074 A620004C */  sh        $zero, 0x4c($s1)
/* 42E418 802A9078 A2200060 */  sb        $zero, 0x60($s1)
/* 42E41C 802A907C A6200044 */  sh        $zero, 0x44($s1)
/* 42E420 802A9080 A6200048 */  sh        $zero, 0x48($s1)
/* 42E424 802A9084 A6200068 */  sh        $zero, 0x68($s1)
/* 42E428 802A9088 A2000081 */  sb        $zero, 0x81($s0)
/* 42E42C 802A908C A2000084 */  sb        $zero, 0x84($s0)
/* 42E430 802A9090 A6220056 */  sh        $v0, 0x56($s1)
/* 42E434 802A9094 24020050 */  addiu     $v0, $zero, 0x50
/* 42E438 802A9098 0C050529 */  jal       create_hud_element
/* 42E43C 802A909C A6220058 */   sh       $v0, 0x58($s1)
/* 42E440 802A90A0 0040802D */  daddu     $s0, $v0, $zero
/* 42E444 802A90A4 86250056 */  lh        $a1, 0x56($s1)
/* 42E448 802A90A8 86260058 */  lh        $a2, 0x58($s1)
/* 42E44C 802A90AC 0200202D */  daddu     $a0, $s0, $zero
/* 42E450 802A90B0 0C051261 */  jal       set_hud_element_render_pos
/* 42E454 802A90B4 AE300004 */   sw       $s0, 4($s1)
/* 42E458 802A90B8 0200202D */  daddu     $a0, $s0, $zero
/* 42E45C 802A90BC 0C051277 */  jal       set_hud_element_render_depth
/* 42E460 802A90C0 0000282D */   daddu    $a1, $zero, $zero
/* 42E464 802A90C4 0200202D */  daddu     $a0, $s0, $zero
/* 42E468 802A90C8 0C051280 */  jal       set_hud_element_flags
/* 42E46C 802A90CC 24050082 */   addiu    $a1, $zero, 0x82
/* 42E470 802A90D0 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 42E474 802A90D4 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 42E478 802A90D8 0C050529 */  jal       create_hud_element
/* 42E47C 802A90DC 00000000 */   nop
/* 42E480 802A90E0 0040802D */  daddu     $s0, $v0, $zero
/* 42E484 802A90E4 86250056 */  lh        $a1, 0x56($s1)
/* 42E488 802A90E8 86260058 */  lh        $a2, 0x58($s1)
/* 42E48C 802A90EC 0200202D */  daddu     $a0, $s0, $zero
/* 42E490 802A90F0 AE300008 */  sw        $s0, 8($s1)
/* 42E494 802A90F4 0C051261 */  jal       set_hud_element_render_pos
/* 42E498 802A90F8 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42E49C 802A90FC 0200202D */  daddu     $a0, $s0, $zero
/* 42E4A0 802A9100 0C051277 */  jal       set_hud_element_render_depth
/* 42E4A4 802A9104 0000282D */   daddu    $a1, $zero, $zero
/* 42E4A8 802A9108 0200202D */  daddu     $a0, $s0, $zero
/* 42E4AC 802A910C 0C051280 */  jal       set_hud_element_flags
/* 42E4B0 802A9110 24050082 */   addiu    $a1, $zero, 0x82
/* 42E4B4 802A9114 3C048029 */  lui       $a0, %hi(D_80292974)
/* 42E4B8 802A9118 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 42E4BC 802A911C 0C050529 */  jal       create_hud_element
/* 42E4C0 802A9120 00000000 */   nop
/* 42E4C4 802A9124 0040802D */  daddu     $s0, $v0, $zero
/* 42E4C8 802A9128 86250056 */  lh        $a1, 0x56($s1)
/* 42E4CC 802A912C 86260058 */  lh        $a2, 0x58($s1)
/* 42E4D0 802A9130 0200202D */  daddu     $a0, $s0, $zero
/* 42E4D4 802A9134 AE30000C */  sw        $s0, 0xc($s1)
/* 42E4D8 802A9138 0C051261 */  jal       set_hud_element_render_pos
/* 42E4DC 802A913C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42E4E0 802A9140 0200202D */  daddu     $a0, $s0, $zero
/* 42E4E4 802A9144 0C051277 */  jal       set_hud_element_render_depth
/* 42E4E8 802A9148 0000282D */   daddu    $a1, $zero, $zero
/* 42E4EC 802A914C 0200202D */  daddu     $a0, $s0, $zero
/* 42E4F0 802A9150 0C051280 */  jal       set_hud_element_flags
/* 42E4F4 802A9154 24050082 */   addiu    $a1, $zero, 0x82
/* 42E4F8 802A9158 080AA45A */  j         .L802A9168
/* 42E4FC 802A915C 24020002 */   addiu    $v0, $zero, 2
.L802A9160:
/* 42E500 802A9160 A0600081 */  sb        $zero, 0x81($v1)
/* 42E504 802A9164 24020002 */  addiu     $v0, $zero, 2
.L802A9168:
/* 42E508 802A9168 8FBF0018 */  lw        $ra, 0x18($sp)
/* 42E50C 802A916C 8FB10014 */  lw        $s1, 0x14($sp)
/* 42E510 802A9170 8FB00010 */  lw        $s0, 0x10($sp)
/* 42E514 802A9174 03E00008 */  jr        $ra
/* 42E518 802A9178 27BD0020 */   addiu    $sp, $sp, 0x20

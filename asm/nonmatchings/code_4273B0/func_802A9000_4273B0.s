.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_4273B0
/* 4273B0 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4273B4 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 4273B8 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 4273BC 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 4273C0 802A9010 24020064 */  addiu     $v0, $zero, 0x64
/* 4273C4 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4273C8 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 4273CC 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 4273D0 802A9020 3C028029 */  lui       $v0, %hi(D_802942E0)
/* 4273D4 802A9024 244242E0 */  addiu     $v0, $v0, %lo(D_802942E0)
/* 4273D8 802A9028 AE020434 */  sw        $v0, 0x434($s0)
/* 4273DC 802A902C 2402007F */  addiu     $v0, $zero, 0x7f
/* 4273E0 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 4273E4 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 4273E8 802A9038 A2020086 */  sb        $v0, 0x86($s0)
/* 4273EC 802A903C 82020083 */  lb        $v0, 0x83($s0)
/* 4273F0 802A9040 10400044 */  beqz      $v0, .L802A9154
/* 4273F4 802A9044 0200182D */   daddu    $v1, $s0, $zero
/* 4273F8 802A9048 0C09A216 */  jal       func_80268858
/* 4273FC 802A904C 00000000 */   nop
/* 427400 802A9050 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 427404 802A9054 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 427408 802A9058 2402000A */  addiu     $v0, $zero, 0xa
/* 42740C 802A905C A622004A */  sh        $v0, 0x4a($s1)
/* 427410 802A9060 24020001 */  addiu     $v0, $zero, 1
/* 427414 802A9064 A2220061 */  sb        $v0, 0x61($s1)
/* 427418 802A9068 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 42741C 802A906C A620004C */  sh        $zero, 0x4c($s1)
/* 427420 802A9070 A2200060 */  sb        $zero, 0x60($s1)
/* 427424 802A9074 A6200044 */  sh        $zero, 0x44($s1)
/* 427428 802A9078 A6200048 */  sh        $zero, 0x48($s1)
/* 42742C 802A907C A6200068 */  sh        $zero, 0x68($s1)
/* 427430 802A9080 A2000081 */  sb        $zero, 0x81($s0)
/* 427434 802A9084 A6220056 */  sh        $v0, 0x56($s1)
/* 427438 802A9088 24020050 */  addiu     $v0, $zero, 0x50
/* 42743C 802A908C 0C050529 */  jal       create_icon
/* 427440 802A9090 A6220058 */   sh       $v0, 0x58($s1)
/* 427444 802A9094 0040802D */  daddu     $s0, $v0, $zero
/* 427448 802A9098 86250056 */  lh        $a1, 0x56($s1)
/* 42744C 802A909C 86260058 */  lh        $a2, 0x58($s1)
/* 427450 802A90A0 0200202D */  daddu     $a0, $s0, $zero
/* 427454 802A90A4 0C051261 */  jal       set_icon_render_pos
/* 427458 802A90A8 AE300004 */   sw       $s0, 4($s1)
/* 42745C 802A90AC 0200202D */  daddu     $a0, $s0, $zero
/* 427460 802A90B0 0C051277 */  jal       func_801449DC
/* 427464 802A90B4 0000282D */   daddu    $a1, $zero, $zero
/* 427468 802A90B8 0200202D */  daddu     $a0, $s0, $zero
/* 42746C 802A90BC 0C051280 */  jal       set_icon_flags
/* 427470 802A90C0 24050082 */   addiu    $a1, $zero, 0x82
/* 427474 802A90C4 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 427478 802A90C8 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 42747C 802A90CC 0C050529 */  jal       create_icon
/* 427480 802A90D0 00000000 */   nop
/* 427484 802A90D4 0040802D */  daddu     $s0, $v0, $zero
/* 427488 802A90D8 86250056 */  lh        $a1, 0x56($s1)
/* 42748C 802A90DC 86260058 */  lh        $a2, 0x58($s1)
/* 427490 802A90E0 0200202D */  daddu     $a0, $s0, $zero
/* 427494 802A90E4 AE300008 */  sw        $s0, 8($s1)
/* 427498 802A90E8 0C051261 */  jal       set_icon_render_pos
/* 42749C 802A90EC 24C6001C */   addiu    $a2, $a2, 0x1c
/* 4274A0 802A90F0 0200202D */  daddu     $a0, $s0, $zero
/* 4274A4 802A90F4 0C051277 */  jal       func_801449DC
/* 4274A8 802A90F8 0000282D */   daddu    $a1, $zero, $zero
/* 4274AC 802A90FC 0200202D */  daddu     $a0, $s0, $zero
/* 4274B0 802A9100 0C051280 */  jal       set_icon_flags
/* 4274B4 802A9104 24050082 */   addiu    $a1, $zero, 0x82
/* 4274B8 802A9108 3C048029 */  lui       $a0, %hi(D_80292974)
/* 4274BC 802A910C 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 4274C0 802A9110 0C050529 */  jal       create_icon
/* 4274C4 802A9114 00000000 */   nop
/* 4274C8 802A9118 0040802D */  daddu     $s0, $v0, $zero
/* 4274CC 802A911C 86250056 */  lh        $a1, 0x56($s1)
/* 4274D0 802A9120 86260058 */  lh        $a2, 0x58($s1)
/* 4274D4 802A9124 0200202D */  daddu     $a0, $s0, $zero
/* 4274D8 802A9128 AE30000C */  sw        $s0, 0xc($s1)
/* 4274DC 802A912C 0C051261 */  jal       set_icon_render_pos
/* 4274E0 802A9130 24C6001C */   addiu    $a2, $a2, 0x1c
/* 4274E4 802A9134 0200202D */  daddu     $a0, $s0, $zero
/* 4274E8 802A9138 0C051277 */  jal       func_801449DC
/* 4274EC 802A913C 0000282D */   daddu    $a1, $zero, $zero
/* 4274F0 802A9140 0200202D */  daddu     $a0, $s0, $zero
/* 4274F4 802A9144 0C051280 */  jal       set_icon_flags
/* 4274F8 802A9148 24050082 */   addiu    $a1, $zero, 0x82
/* 4274FC 802A914C 080AA457 */  j         .L802A915C
/* 427500 802A9150 24020002 */   addiu    $v0, $zero, 2
.L802A9154:
/* 427504 802A9154 A0600081 */  sb        $zero, 0x81($v1)
/* 427508 802A9158 24020002 */  addiu     $v0, $zero, 2
.L802A915C:
/* 42750C 802A915C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 427510 802A9160 8FB10014 */  lw        $s1, 0x14($sp)
/* 427514 802A9164 8FB00010 */  lw        $s0, 0x10($sp)
/* 427518 802A9168 03E00008 */  jr        $ra
/* 42751C 802A916C 27BD0020 */   addiu    $sp, $sp, 0x20

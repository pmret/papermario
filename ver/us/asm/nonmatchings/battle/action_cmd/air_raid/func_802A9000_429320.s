.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_429320
/* 429320 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 429324 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 429328 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 42932C 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 429330 802A9010 24020064 */  addiu     $v0, $zero, 0x64
/* 429334 802A9014 AFBF0018 */  sw        $ra, 0x18($sp)
/* 429338 802A9018 AFB10014 */  sw        $s1, 0x14($sp)
/* 42933C 802A901C A2020082 */  sb        $v0, 0x82($s0)
/* 429340 802A9020 3C028029 */  lui       $v0, %hi(D_80294360)
/* 429344 802A9024 24424360 */  addiu     $v0, $v0, %lo(D_80294360)
/* 429348 802A9028 AE020434 */  sw        $v0, 0x434($s0)
/* 42934C 802A902C 2402007F */  addiu     $v0, $zero, 0x7f
/* 429350 802A9030 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 429354 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 429358 802A9038 A2020086 */  sb        $v0, 0x86($s0)
/* 42935C 802A903C 82020083 */  lb        $v0, 0x83($s0)
/* 429360 802A9040 10400046 */  beqz      $v0, .L802A915C
/* 429364 802A9044 0200182D */   daddu    $v1, $s0, $zero
/* 429368 802A9048 0C09A216 */  jal       func_80268858
/* 42936C 802A904C 00000000 */   nop
/* 429370 802A9050 3C048011 */  lui       $a0, %hi(D_80108E1C)
/* 429374 802A9054 24848E1C */  addiu     $a0, $a0, %lo(D_80108E1C)
/* 429378 802A9058 2402000E */  addiu     $v0, $zero, 0xe
/* 42937C 802A905C A622004A */  sh        $v0, 0x4a($s1)
/* 429380 802A9060 24020001 */  addiu     $v0, $zero, 1
/* 429384 802A9064 A2220061 */  sb        $v0, 0x61($s1)
/* 429388 802A9068 2402001E */  addiu     $v0, $zero, 0x1e
/* 42938C 802A906C A622006C */  sh        $v0, 0x6c($s1)
/* 429390 802A9070 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 429394 802A9074 A620004C */  sh        $zero, 0x4c($s1)
/* 429398 802A9078 A2200060 */  sb        $zero, 0x60($s1)
/* 42939C 802A907C A6200044 */  sh        $zero, 0x44($s1)
/* 4293A0 802A9080 A6200048 */  sh        $zero, 0x48($s1)
/* 4293A4 802A9084 A6200068 */  sh        $zero, 0x68($s1)
/* 4293A8 802A9088 A2000081 */  sb        $zero, 0x81($s0)
/* 4293AC 802A908C A6220056 */  sh        $v0, 0x56($s1)
/* 4293B0 802A9090 24020050 */  addiu     $v0, $zero, 0x50
/* 4293B4 802A9094 0C050529 */  jal       create_hud_element
/* 4293B8 802A9098 A6220058 */   sh       $v0, 0x58($s1)
/* 4293BC 802A909C 0040802D */  daddu     $s0, $v0, $zero
/* 4293C0 802A90A0 86250056 */  lh        $a1, 0x56($s1)
/* 4293C4 802A90A4 86260058 */  lh        $a2, 0x58($s1)
/* 4293C8 802A90A8 0200202D */  daddu     $a0, $s0, $zero
/* 4293CC 802A90AC 0C051261 */  jal       set_hud_element_render_pos
/* 4293D0 802A90B0 AE300004 */   sw       $s0, 4($s1)
/* 4293D4 802A90B4 0200202D */  daddu     $a0, $s0, $zero
/* 4293D8 802A90B8 0C051277 */  jal       set_hud_element_render_depth
/* 4293DC 802A90BC 0000282D */   daddu    $a1, $zero, $zero
/* 4293E0 802A90C0 0200202D */  daddu     $a0, $s0, $zero
/* 4293E4 802A90C4 0C051280 */  jal       set_hud_element_flags
/* 4293E8 802A90C8 24050082 */   addiu    $a1, $zero, 0x82
/* 4293EC 802A90CC 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 4293F0 802A90D0 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 4293F4 802A90D4 0C050529 */  jal       create_hud_element
/* 4293F8 802A90D8 00000000 */   nop
/* 4293FC 802A90DC 0040802D */  daddu     $s0, $v0, $zero
/* 429400 802A90E0 86250056 */  lh        $a1, 0x56($s1)
/* 429404 802A90E4 86260058 */  lh        $a2, 0x58($s1)
/* 429408 802A90E8 0200202D */  daddu     $a0, $s0, $zero
/* 42940C 802A90EC AE300008 */  sw        $s0, 8($s1)
/* 429410 802A90F0 0C051261 */  jal       set_hud_element_render_pos
/* 429414 802A90F4 24C6001C */   addiu    $a2, $a2, 0x1c
/* 429418 802A90F8 0200202D */  daddu     $a0, $s0, $zero
/* 42941C 802A90FC 0C051277 */  jal       set_hud_element_render_depth
/* 429420 802A9100 0000282D */   daddu    $a1, $zero, $zero
/* 429424 802A9104 0200202D */  daddu     $a0, $s0, $zero
/* 429428 802A9108 0C051280 */  jal       set_hud_element_flags
/* 42942C 802A910C 24050082 */   addiu    $a1, $zero, 0x82
/* 429430 802A9110 3C048029 */  lui       $a0, %hi(D_80292974)
/* 429434 802A9114 24842974 */  addiu     $a0, $a0, %lo(D_80292974)
/* 429438 802A9118 0C050529 */  jal       create_hud_element
/* 42943C 802A911C 00000000 */   nop
/* 429440 802A9120 0040802D */  daddu     $s0, $v0, $zero
/* 429444 802A9124 86250056 */  lh        $a1, 0x56($s1)
/* 429448 802A9128 86260058 */  lh        $a2, 0x58($s1)
/* 42944C 802A912C 0200202D */  daddu     $a0, $s0, $zero
/* 429450 802A9130 AE30000C */  sw        $s0, 0xc($s1)
/* 429454 802A9134 0C051261 */  jal       set_hud_element_render_pos
/* 429458 802A9138 24C6001C */   addiu    $a2, $a2, 0x1c
/* 42945C 802A913C 0200202D */  daddu     $a0, $s0, $zero
/* 429460 802A9140 0C051277 */  jal       set_hud_element_render_depth
/* 429464 802A9144 0000282D */   daddu    $a1, $zero, $zero
/* 429468 802A9148 0200202D */  daddu     $a0, $s0, $zero
/* 42946C 802A914C 0C051280 */  jal       set_hud_element_flags
/* 429470 802A9150 24050082 */   addiu    $a1, $zero, 0x82
/* 429474 802A9154 080AA459 */  j         .L802A9164
/* 429478 802A9158 24020002 */   addiu    $v0, $zero, 2
.L802A915C:
/* 42947C 802A915C A0600081 */  sb        $zero, 0x81($v1)
/* 429480 802A9160 24020002 */  addiu     $v0, $zero, 2
.L802A9164:
/* 429484 802A9164 8FBF0018 */  lw        $ra, 0x18($sp)
/* 429488 802A9168 8FB10014 */  lw        $s1, 0x14($sp)
/* 42948C 802A916C 8FB00010 */  lw        $s0, 0x10($sp)
/* 429490 802A9170 03E00008 */  jr        $ra
/* 429494 802A9174 27BD0020 */   addiu    $sp, $sp, 0x20

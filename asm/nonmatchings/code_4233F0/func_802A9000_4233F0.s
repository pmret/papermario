.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_4233F0
/* 4233F0 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4233F4 802A9004 AFB00010 */  sw        $s0, 0x10($sp)
/* 4233F8 802A9008 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 4233FC 802A900C 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 423400 802A9010 3C028029 */  lui       $v0, %hi(D_80294220)
/* 423404 802A9014 24424220 */  addiu     $v0, $v0, %lo(D_80294220)
/* 423408 802A9018 AFBF0018 */  sw        $ra, 0x18($sp)
/* 42340C 802A901C AFB10014 */  sw        $s1, 0x14($sp)
/* 423410 802A9020 AE020434 */  sw        $v0, 0x434($s0)
/* 423414 802A9024 2402007F */  addiu     $v0, $zero, 0x7f
/* 423418 802A9028 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 42341C 802A902C 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 423420 802A9030 A2020086 */  sb        $v0, 0x86($s0)
/* 423424 802A9034 82020083 */  lb        $v0, 0x83($s0)
/* 423428 802A9038 0200182D */  daddu     $v1, $s0, $zero
/* 42342C 802A903C 10400055 */  beqz      $v0, .L802A9194
/* 423430 802A9040 A2000082 */   sb       $zero, 0x82($s0)
/* 423434 802A9044 0C09A216 */  jal       func_80268858
/* 423438 802A9048 00000000 */   nop      
/* 42343C 802A904C 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 423440 802A9050 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 423444 802A9054 24020004 */  addiu     $v0, $zero, 4
/* 423448 802A9058 A622004A */  sh        $v0, 0x4a($s1)
/* 42344C 802A905C 24020001 */  addiu     $v0, $zero, 1
/* 423450 802A9060 A2220061 */  sb        $v0, 0x61($s1)
/* 423454 802A9064 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 423458 802A9068 A620004C */  sh        $zero, 0x4c($s1)
/* 42345C 802A906C A2200060 */  sb        $zero, 0x60($s1)
/* 423460 802A9070 A6200044 */  sh        $zero, 0x44($s1)
/* 423464 802A9074 A6200046 */  sh        $zero, 0x46($s1)
/* 423468 802A9078 A6200048 */  sh        $zero, 0x48($s1)
/* 42346C 802A907C A2000081 */  sb        $zero, 0x81($s0)
/* 423470 802A9080 A6220056 */  sh        $v0, 0x56($s1)
/* 423474 802A9084 24020050 */  addiu     $v0, $zero, 0x50
/* 423478 802A9088 0C050529 */  jal       create_icon
/* 42347C 802A908C A6220058 */   sh       $v0, 0x58($s1)
/* 423480 802A9090 0040802D */  daddu     $s0, $v0, $zero
/* 423484 802A9094 86250056 */  lh        $a1, 0x56($s1)
/* 423488 802A9098 86260058 */  lh        $a2, 0x58($s1)
/* 42348C 802A909C 0200202D */  daddu     $a0, $s0, $zero
/* 423490 802A90A0 0C051261 */  jal       set_icon_render_pos
/* 423494 802A90A4 AE300004 */   sw       $s0, 4($s1)
/* 423498 802A90A8 0200202D */  daddu     $a0, $s0, $zero
/* 42349C 802A90AC 0C051277 */  jal       func_801449DC
/* 4234A0 802A90B0 0000282D */   daddu    $a1, $zero, $zero
/* 4234A4 802A90B4 0200202D */  daddu     $a0, $s0, $zero
/* 4234A8 802A90B8 0C051280 */  jal       set_icon_flags
/* 4234AC 802A90BC 24050082 */   addiu    $a1, $zero, 0x82
/* 4234B0 802A90C0 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 4234B4 802A90C4 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 4234B8 802A90C8 0C050529 */  jal       create_icon
/* 4234BC 802A90CC 00000000 */   nop      
/* 4234C0 802A90D0 0040802D */  daddu     $s0, $v0, $zero
/* 4234C4 802A90D4 86250056 */  lh        $a1, 0x56($s1)
/* 4234C8 802A90D8 86260058 */  lh        $a2, 0x58($s1)
/* 4234CC 802A90DC 0200202D */  daddu     $a0, $s0, $zero
/* 4234D0 802A90E0 AE300008 */  sw        $s0, 8($s1)
/* 4234D4 802A90E4 0C051261 */  jal       set_icon_render_pos
/* 4234D8 802A90E8 24C6001C */   addiu    $a2, $a2, 0x1c
/* 4234DC 802A90EC 0200202D */  daddu     $a0, $s0, $zero
/* 4234E0 802A90F0 0C051277 */  jal       func_801449DC
/* 4234E4 802A90F4 0000282D */   daddu    $a1, $zero, $zero
/* 4234E8 802A90F8 0200202D */  daddu     $a0, $s0, $zero
/* 4234EC 802A90FC 0C051280 */  jal       set_icon_flags
/* 4234F0 802A9100 24050082 */   addiu    $a1, $zero, 0x82
/* 4234F4 802A9104 3C048029 */  lui       $a0, %hi(D_802928F8)
/* 4234F8 802A9108 248428F8 */  addiu     $a0, $a0, %lo(D_802928F8)
/* 4234FC 802A910C 0C050529 */  jal       create_icon
/* 423500 802A9110 00000000 */   nop      
/* 423504 802A9114 0040802D */  daddu     $s0, $v0, $zero
/* 423508 802A9118 86250056 */  lh        $a1, 0x56($s1)
/* 42350C 802A911C 86260058 */  lh        $a2, 0x58($s1)
/* 423510 802A9120 0200202D */  daddu     $a0, $s0, $zero
/* 423514 802A9124 AE30000C */  sw        $s0, 0xc($s1)
/* 423518 802A9128 0C051261 */  jal       set_icon_render_pos
/* 42351C 802A912C 24C6001C */   addiu    $a2, $a2, 0x1c
/* 423520 802A9130 0200202D */  daddu     $a0, $s0, $zero
/* 423524 802A9134 0C051277 */  jal       func_801449DC
/* 423528 802A9138 0000282D */   daddu    $a1, $zero, $zero
/* 42352C 802A913C 0200202D */  daddu     $a0, $s0, $zero
/* 423530 802A9140 0C051280 */  jal       set_icon_flags
/* 423534 802A9144 24050082 */   addiu    $a1, $zero, 0x82
/* 423538 802A9148 3C048011 */  lui       $a0, %hi(D_80109244)
/* 42353C 802A914C 24849244 */  addiu     $a0, $a0, %lo(D_80109244)
/* 423540 802A9150 0C050529 */  jal       create_icon
/* 423544 802A9154 00000000 */   nop      
/* 423548 802A9158 0040802D */  daddu     $s0, $v0, $zero
/* 42354C 802A915C 86250056 */  lh        $a1, 0x56($s1)
/* 423550 802A9160 86260058 */  lh        $a2, 0x58($s1)
/* 423554 802A9164 0200202D */  daddu     $a0, $s0, $zero
/* 423558 802A9168 AE300010 */  sw        $s0, 0x10($s1)
/* 42355C 802A916C 0C051261 */  jal       set_icon_render_pos
/* 423560 802A9170 24C6001C */   addiu    $a2, $a2, 0x1c
/* 423564 802A9174 0200202D */  daddu     $a0, $s0, $zero
/* 423568 802A9178 0C051277 */  jal       func_801449DC
/* 42356C 802A917C 0000282D */   daddu    $a1, $zero, $zero
/* 423570 802A9180 0200202D */  daddu     $a0, $s0, $zero
/* 423574 802A9184 0C051280 */  jal       set_icon_flags
/* 423578 802A9188 24050082 */   addiu    $a1, $zero, 0x82
/* 42357C 802A918C 080AA467 */  j         .L802A919C
/* 423580 802A9190 24020002 */   addiu    $v0, $zero, 2
.L802A9194:
/* 423584 802A9194 A0600081 */  sb        $zero, 0x81($v1)
/* 423588 802A9198 24020002 */  addiu     $v0, $zero, 2
.L802A919C:
/* 42358C 802A919C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 423590 802A91A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 423594 802A91A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 423598 802A91A8 03E00008 */  jr        $ra
/* 42359C 802A91AC 27BD0020 */   addiu    $sp, $sp, 0x20

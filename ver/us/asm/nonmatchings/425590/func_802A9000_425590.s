.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9000_425590
/* 425590 802A9000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 425594 802A9004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 425598 802A9008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 42559C 802A900C 24020005 */  addiu     $v0, $zero, 5
/* 4255A0 802A9010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4255A4 802A9014 AFB10014 */  sw        $s1, 0x14($sp)
/* 4255A8 802A9018 AFB00010 */  sw        $s0, 0x10($sp)
/* 4255AC 802A901C A0620082 */  sb        $v0, 0x82($v1)
/* 4255B0 802A9020 3C028029 */  lui       $v0, %hi(D_80294260)
/* 4255B4 802A9024 24424260 */  addiu     $v0, $v0, %lo(D_80294260)
/* 4255B8 802A9028 AC620434 */  sw        $v0, 0x434($v1)
/* 4255BC 802A902C 80620083 */  lb        $v0, 0x83($v1)
/* 4255C0 802A9030 3C11802A */  lui       $s1, %hi(D_8029FBE0)
/* 4255C4 802A9034 2631FBE0 */  addiu     $s1, $s1, %lo(D_8029FBE0)
/* 4255C8 802A9038 5040002F */  beql      $v0, $zero, .L802A90F8
/* 4255CC 802A903C A0600081 */   sb       $zero, 0x81($v1)
/* 4255D0 802A9040 0C09A216 */  jal       func_80268858
/* 4255D4 802A9044 00000000 */   nop
/* 4255D8 802A9048 3C048011 */  lui       $a0, %hi(D_80108B28)
/* 4255DC 802A904C 24848B28 */  addiu     $a0, $a0, %lo(D_80108B28)
/* 4255E0 802A9050 24020006 */  addiu     $v0, $zero, 6
/* 4255E4 802A9054 A622004A */  sh        $v0, 0x4a($s1)
/* 4255E8 802A9058 2402FFD0 */  addiu     $v0, $zero, -0x30
/* 4255EC 802A905C A6220056 */  sh        $v0, 0x56($s1)
/* 4255F0 802A9060 24020050 */  addiu     $v0, $zero, 0x50
/* 4255F4 802A9064 A620004C */  sh        $zero, 0x4c($s1)
/* 4255F8 802A9068 A2200060 */  sb        $zero, 0x60($s1)
/* 4255FC 802A906C A6200044 */  sh        $zero, 0x44($s1)
/* 425600 802A9070 A6200048 */  sh        $zero, 0x48($s1)
/* 425604 802A9074 0C050529 */  jal       create_hud_element
/* 425608 802A9078 A6220058 */   sh       $v0, 0x58($s1)
/* 42560C 802A907C 0040802D */  daddu     $s0, $v0, $zero
/* 425610 802A9080 0200202D */  daddu     $a0, $s0, $zero
/* 425614 802A9084 24050082 */  addiu     $a1, $zero, 0x82
/* 425618 802A9088 0C051280 */  jal       set_hud_element_flags
/* 42561C 802A908C AE300004 */   sw       $s0, 4($s1)
/* 425620 802A9090 86250056 */  lh        $a1, 0x56($s1)
/* 425624 802A9094 86260058 */  lh        $a2, 0x58($s1)
/* 425628 802A9098 0C051261 */  jal       set_hud_element_render_pos
/* 42562C 802A909C 0200202D */   daddu    $a0, $s0, $zero
/* 425630 802A90A0 0200202D */  daddu     $a0, $s0, $zero
/* 425634 802A90A4 0C051277 */  jal       set_hud_element_render_depth
/* 425638 802A90A8 0000282D */   daddu    $a1, $zero, $zero
/* 42563C 802A90AC 3C048011 */  lui       $a0, %hi(D_80108AFC)
/* 425640 802A90B0 24848AFC */  addiu     $a0, $a0, %lo(D_80108AFC)
/* 425644 802A90B4 0C050529 */  jal       create_hud_element
/* 425648 802A90B8 00000000 */   nop
/* 42564C 802A90BC 0040802D */  daddu     $s0, $v0, $zero
/* 425650 802A90C0 86250056 */  lh        $a1, 0x56($s1)
/* 425654 802A90C4 86260058 */  lh        $a2, 0x58($s1)
/* 425658 802A90C8 0200202D */  daddu     $a0, $s0, $zero
/* 42565C 802A90CC AE300008 */  sw        $s0, 8($s1)
/* 425660 802A90D0 0C051261 */  jal       set_hud_element_render_pos
/* 425664 802A90D4 24C6001C */   addiu    $a2, $a2, 0x1c
/* 425668 802A90D8 0200202D */  daddu     $a0, $s0, $zero
/* 42566C 802A90DC 0C051277 */  jal       set_hud_element_render_depth
/* 425670 802A90E0 0000282D */   daddu    $a1, $zero, $zero
/* 425674 802A90E4 0200202D */  daddu     $a0, $s0, $zero
/* 425678 802A90E8 0C051280 */  jal       set_hud_element_flags
/* 42567C 802A90EC 24050082 */   addiu    $a1, $zero, 0x82
/* 425680 802A90F0 080AA43F */  j         .L802A90FC
/* 425684 802A90F4 24020002 */   addiu    $v0, $zero, 2
.L802A90F8:
/* 425688 802A90F8 24020002 */  addiu     $v0, $zero, 2
.L802A90FC:
/* 42568C 802A90FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 425690 802A9100 8FB10014 */  lw        $s1, 0x14($sp)
/* 425694 802A9104 8FB00010 */  lw        $s0, 0x10($sp)
/* 425698 802A9108 03E00008 */  jr        $ra
/* 42569C 802A910C 27BD0020 */   addiu    $sp, $sp, 0x20

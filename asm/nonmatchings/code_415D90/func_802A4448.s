.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A4448
/* 4191D8 802A4448 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4191DC 802A444C 24A50010 */  addiu     $a1, $a1, 0x10
/* 4191E0 802A4450 AFB00010 */  sw        $s0, 0x10($sp)
/* 4191E4 802A4454 3C10802B */  lui       $s0, %hi(battle_menu_moveTitleIcon)
/* 4191E8 802A4458 8E10D188 */  lw        $s0, %lo(battle_menu_moveTitleIcon)($s0)
/* 4191EC 802A445C 24C6000F */  addiu     $a2, $a2, 0xf
/* 4191F0 802A4460 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4191F4 802A4464 0C051261 */  jal       set_icon_render_pos
/* 4191F8 802A4468 0200202D */   daddu    $a0, $s0, $zero
/* 4191FC 802A446C 3C05802B */  lui       $a1, %hi(battle_menu_moveTextOpacity)
/* 419200 802A4470 84A5D116 */  lh        $a1, %lo(battle_menu_moveTextOpacity)($a1)
/* 419204 802A4474 0C0513AC */  jal       icon_set_opacity
/* 419208 802A4478 0200202D */   daddu    $a0, $s0, $zero
/* 41920C 802A447C 0C0511EA */  jal       draw_icon_0
/* 419210 802A4480 0200202D */   daddu    $a0, $s0, $zero
/* 419214 802A4484 8FBF0014 */  lw        $ra, 0x14($sp)
/* 419218 802A4488 8FB00010 */  lw        $s0, 0x10($sp)
/* 41921C 802A448C 03E00008 */  jr        $ra
/* 419220 802A4490 27BD0018 */   addiu    $sp, $sp, 0x18

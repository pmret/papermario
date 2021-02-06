.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A43DC
/* 41916C 802A43DC 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 419170 802A43E0 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 419174 802A43E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 419178 802A43E8 14400009 */  bnez      $v0, .L802A4410
/* 41917C 802A43EC AFBF0018 */   sw       $ra, 0x18($sp)
/* 419180 802A43F0 3C04001D */  lui       $a0, 0x1d
/* 419184 802A43F4 34840045 */  ori       $a0, $a0, 0x45
/* 419188 802A43F8 24A50010 */  addiu     $a1, $a1, 0x10
/* 41918C 802A43FC 24C60002 */  addiu     $a2, $a2, 2
/* 419190 802A4400 3C07802B */  lui       $a3, %hi(battle_menu_moveTextOpacity)
/* 419194 802A4404 84E7D116 */  lh        $a3, %lo(battle_menu_moveTextOpacity)($a3)
/* 419198 802A4408 080A910B */  j         .L802A442C
/* 41919C 802A440C 24020030 */   addiu    $v0, $zero, 0x30
.L802A4410:
/* 4191A0 802A4410 3C04001D */  lui       $a0, 0x1d
/* 4191A4 802A4414 3484003A */  ori       $a0, $a0, 0x3a
/* 4191A8 802A4418 24A50006 */  addiu     $a1, $a1, 6
/* 4191AC 802A441C 24C60002 */  addiu     $a2, $a2, 2
/* 4191B0 802A4420 3C07802B */  lui       $a3, %hi(battle_menu_moveTextOpacity)
/* 4191B4 802A4424 84E7D116 */  lh        $a3, %lo(battle_menu_moveTextOpacity)($a3)
/* 4191B8 802A4428 24020031 */  addiu     $v0, $zero, 0x31
.L802A442C:
/* 4191BC 802A442C AFA20010 */  sw        $v0, 0x10($sp)
/* 4191C0 802A4430 24020001 */  addiu     $v0, $zero, 1
/* 4191C4 802A4434 0C04993B */  jal       draw_string
/* 4191C8 802A4438 AFA20014 */   sw       $v0, 0x14($sp)
/* 4191CC 802A443C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4191D0 802A4440 03E00008 */  jr        $ra
/* 4191D4 802A4444 27BD0020 */   addiu    $sp, $sp, 0x20

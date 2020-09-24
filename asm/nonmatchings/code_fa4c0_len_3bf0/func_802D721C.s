.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D721C
/* FBBCC 802D721C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* FBBD0 802D7220 AFB10014 */  sw        $s1, 0x14($sp)
/* FBBD4 802D7224 0080882D */  daddu     $s1, $a0, $zero
/* FBBD8 802D7228 AFBF0018 */  sw        $ra, 0x18($sp)
/* FBBDC 802D722C AFB00010 */  sw        $s0, 0x10($sp)
/* FBBE0 802D7230 8E30000C */  lw        $s0, 0xc($s1)
/* FBBE4 802D7234 8E050000 */  lw        $a1, ($s0)
/* FBBE8 802D7238 0C0B1EAF */  jal       get_variable
/* FBBEC 802D723C 26100004 */   addiu    $s0, $s0, 4
/* FBBF0 802D7240 0220202D */  daddu     $a0, $s1, $zero
/* FBBF4 802D7244 8E050000 */  lw        $a1, ($s0)
/* FBBF8 802D7248 0C0B1EAF */  jal       get_variable
/* FBBFC 802D724C 0040802D */   daddu    $s0, $v0, $zero
/* FBC00 802D7250 0200202D */  daddu     $a0, $s0, $zero
/* FBC04 802D7254 0C04C3D6 */  jal       get_item_entity
/* FBC08 802D7258 0040802D */   daddu    $s0, $v0, $zero
/* FBC0C 802D725C A050002F */  sb        $s0, 0x2f($v0)
/* FBC10 802D7260 8FBF0018 */  lw        $ra, 0x18($sp)
/* FBC14 802D7264 8FB10014 */  lw        $s1, 0x14($sp)
/* FBC18 802D7268 8FB00010 */  lw        $s0, 0x10($sp)
/* FBC1C 802D726C 24020002 */  addiu     $v0, $zero, 2
/* FBC20 802D7270 03E00008 */  jr        $ra
/* FBC24 802D7274 27BD0020 */   addiu    $sp, $sp, 0x20

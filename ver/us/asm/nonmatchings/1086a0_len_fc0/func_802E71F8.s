.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E71F8
/* 108A78 802E71F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 108A7C 802E71FC 2403000A */  addiu     $v1, $zero, 0xa
/* 108A80 802E7200 AFBF0010 */  sw        $ra, 0x10($sp)
/* 108A84 802E7204 8C820040 */  lw        $v0, 0x40($a0)
/* 108A88 802E7208 240401D3 */  addiu     $a0, $zero, 0x1d3
/* 108A8C 802E720C A0430006 */  sb        $v1, 6($v0)
/* 108A90 802E7210 24030028 */  addiu     $v1, $zero, 0x28
/* 108A94 802E7214 AC400008 */  sw        $zero, 8($v0)
/* 108A98 802E7218 A0400005 */  sb        $zero, 5($v0)
/* 108A9C 802E721C 0C05272D */  jal       sfx_play_sound
/* 108AA0 802E7220 A4430002 */   sh       $v1, 2($v0)
/* 108AA4 802E7224 8FBF0010 */  lw        $ra, 0x10($sp)
/* 108AA8 802E7228 03E00008 */  jr        $ra
/* 108AAC 802E722C 27BD0018 */   addiu    $sp, $sp, 0x18

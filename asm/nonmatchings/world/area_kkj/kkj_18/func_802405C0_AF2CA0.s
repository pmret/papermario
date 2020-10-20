.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405C0_AF3260
/* AF3260 802405C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF3264 802405C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF3268 802405C8 8C82000C */  lw        $v0, 0xc($a0)
/* AF326C 802405CC 0C0B1EAF */  jal       get_variable
/* AF3270 802405D0 8C450000 */   lw       $a1, ($v0)
/* AF3274 802405D4 3C018024 */  lui       $at, 0x8024
/* AF3278 802405D8 AC221F14 */  sw        $v0, 0x1f14($at)
/* AF327C 802405DC 24020002 */  addiu     $v0, $zero, 2
/* AF3280 802405E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF3284 802405E4 24030001 */  addiu     $v1, $zero, 1
/* AF3288 802405E8 3C018024 */  lui       $at, 0x8024
/* AF328C 802405EC AC231F10 */  sw        $v1, 0x1f10($at)
/* AF3290 802405F0 03E00008 */  jr        $ra
/* AF3294 802405F4 27BD0018 */   addiu    $sp, $sp, 0x18

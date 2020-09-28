.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2148
/* F6AF8 802D2148 3C04FBFF */  lui       $a0, 0xfbff
/* F6AFC 802D214C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* F6B00 802D2150 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* F6B04 802D2154 8C620000 */  lw        $v0, ($v1)
/* F6B08 802D2158 3484FFFF */  ori       $a0, $a0, 0xffff
/* F6B0C 802D215C 00441024 */  and       $v0, $v0, $a0
/* F6B10 802D2160 AC620000 */  sw        $v0, ($v1)
/* F6B14 802D2164 03E00008 */  jr        $ra
/* F6B18 802D2168 24020002 */   addiu    $v0, $zero, 2

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404FC
/* CD232C 802404FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CD2330 80240500 AFBF0010 */  sw        $ra, 0x10($sp)
/* CD2334 80240504 8C82000C */  lw        $v0, 0xc($a0)
/* CD2338 80240508 0C0B1EAF */  jal       get_variable
/* CD233C 8024050C 8C450000 */   lw       $a1, ($v0)
/* CD2340 80240510 0C03AC5A */  jal       func_800EB168
/* CD2344 80240514 0040202D */   daddu    $a0, $v0, $zero
/* CD2348 80240518 8FBF0010 */  lw        $ra, 0x10($sp)
/* CD234C 8024051C 24020002 */  addiu     $v0, $zero, 2
/* CD2350 80240520 03E00008 */  jr        $ra
/* CD2354 80240524 27BD0018 */   addiu    $sp, $sp, 0x18

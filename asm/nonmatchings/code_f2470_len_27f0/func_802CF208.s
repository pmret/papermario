.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CF208
/* F3BB8 802CF208 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F3BBC 802CF20C AFB00010 */  sw        $s0, 0x10($sp)
/* F3BC0 802CF210 0080802D */  daddu     $s0, $a0, $zero
/* F3BC4 802CF214 AFBF0018 */  sw        $ra, 0x18($sp)
/* F3BC8 802CF218 AFB10014 */  sw        $s1, 0x14($sp)
/* F3BCC 802CF21C 8E11000C */  lw        $s1, 0xc($s0)
/* F3BD0 802CF220 8E250000 */  lw        $a1, ($s1)
/* F3BD4 802CF224 0C0B1EAF */  jal       get_variable
/* F3BD8 802CF228 26310004 */   addiu    $s1, $s1, 4
/* F3BDC 802CF22C 0200202D */  daddu     $a0, $s0, $zero
/* F3BE0 802CF230 8E310000 */  lw        $s1, ($s1)
/* F3BE4 802CF234 0C0B36B0 */  jal       resolve_npc
/* F3BE8 802CF238 0040282D */   daddu    $a1, $v0, $zero
/* F3BEC 802CF23C 10400004 */  beqz      $v0, .L802CF250
/* F3BF0 802CF240 0040202D */   daddu    $a0, $v0, $zero
/* F3BF4 802CF244 0220282D */  daddu     $a1, $s1, $zero
/* F3BF8 802CF248 0C00EB17 */  jal       func_8003AC5C
/* F3BFC 802CF24C 0000302D */   daddu    $a2, $zero, $zero
.L802CF250:
/* F3C00 802CF250 24020002 */  addiu     $v0, $zero, 2
/* F3C04 802CF254 8FBF0018 */  lw        $ra, 0x18($sp)
/* F3C08 802CF258 8FB10014 */  lw        $s1, 0x14($sp)
/* F3C0C 802CF25C 8FB00010 */  lw        $s0, 0x10($sp)
/* F3C10 802CF260 03E00008 */  jr        $ra
/* F3C14 802CF264 27BD0020 */   addiu    $sp, $sp, 0x20

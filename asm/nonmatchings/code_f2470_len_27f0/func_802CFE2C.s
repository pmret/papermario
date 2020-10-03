.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CFE2C
/* F47DC 802CFE2C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F47E0 802CFE30 AFB00010 */  sw        $s0, 0x10($sp)
/* F47E4 802CFE34 0080802D */  daddu     $s0, $a0, $zero
/* F47E8 802CFE38 AFBF0018 */  sw        $ra, 0x18($sp)
/* F47EC 802CFE3C AFB10014 */  sw        $s1, 0x14($sp)
/* F47F0 802CFE40 8E11000C */  lw        $s1, 0xc($s0)
/* F47F4 802CFE44 8E250000 */  lw        $a1, ($s1)
/* F47F8 802CFE48 0C0B1EAF */  jal       get_variable
/* F47FC 802CFE4C 26310004 */   addiu    $s1, $s1, 4
/* F4800 802CFE50 0200202D */  daddu     $a0, $s0, $zero
/* F4804 802CFE54 8E310000 */  lw        $s1, ($s1)
/* F4808 802CFE58 0C0B36B0 */  jal       resolve_npc
/* F480C 802CFE5C 0040282D */   daddu    $a1, $v0, $zero
/* F4810 802CFE60 54400001 */  bnel      $v0, $zero, .L802CFE68
/* F4814 802CFE64 A45100A2 */   sh       $s1, 0xa2($v0)
.L802CFE68:
/* F4818 802CFE68 24020002 */  addiu     $v0, $zero, 2
/* F481C 802CFE6C 8FBF0018 */  lw        $ra, 0x18($sp)
/* F4820 802CFE70 8FB10014 */  lw        $s1, 0x14($sp)
/* F4824 802CFE74 8FB00010 */  lw        $s0, 0x10($sp)
/* F4828 802CFE78 03E00008 */  jr        $ra
/* F482C 802CFE7C 27BD0020 */   addiu    $sp, $sp, 0x20

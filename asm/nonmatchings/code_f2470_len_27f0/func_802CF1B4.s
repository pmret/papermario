.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CF1B4
/* F3B64 802CF1B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F3B68 802CF1B8 AFB00010 */  sw        $s0, 0x10($sp)
/* F3B6C 802CF1BC 0080802D */  daddu     $s0, $a0, $zero
/* F3B70 802CF1C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* F3B74 802CF1C4 AFB10014 */  sw        $s1, 0x14($sp)
/* F3B78 802CF1C8 8E11000C */  lw        $s1, 0xc($s0)
/* F3B7C 802CF1CC 8E250000 */  lw        $a1, ($s1)
/* F3B80 802CF1D0 0C0B1EAF */  jal       get_variable
/* F3B84 802CF1D4 26310004 */   addiu    $s1, $s1, 4
/* F3B88 802CF1D8 0200202D */  daddu     $a0, $s0, $zero
/* F3B8C 802CF1DC 8E310000 */  lw        $s1, ($s1)
/* F3B90 802CF1E0 0C0B36B0 */  jal       resolve_npc
/* F3B94 802CF1E4 0040282D */   daddu    $a1, $v0, $zero
/* F3B98 802CF1E8 54400001 */  bnel      $v0, $zero, .L802CF1F0
/* F3B9C 802CF1EC AC510080 */   sw       $s1, 0x80($v0)
.L802CF1F0:
/* F3BA0 802CF1F0 24020002 */  addiu     $v0, $zero, 2
/* F3BA4 802CF1F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* F3BA8 802CF1F8 8FB10014 */  lw        $s1, 0x14($sp)
/* F3BAC 802CF1FC 8FB00010 */  lw        $s0, 0x10($sp)
/* F3BB0 802CF200 03E00008 */  jr        $ra
/* F3BB4 802CF204 27BD0020 */   addiu    $sp, $sp, 0x20

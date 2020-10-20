.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400D4_BF4874
/* BF4874 802400D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BF4878 802400D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* BF487C 802400DC 0C03BCC0 */  jal       func_800EF300
/* BF4880 802400E0 00000000 */   nop      
/* BF4884 802400E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* BF4888 802400E8 24020002 */  addiu     $v0, $zero, 2
/* BF488C 802400EC 03E00008 */  jr        $ra
/* BF4890 802400F0 27BD0018 */   addiu    $sp, $sp, 0x18

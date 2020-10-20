.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412C8_BE8EA8
/* BE8EA8 802412C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BE8EAC 802412CC AFBF0010 */  sw        $ra, 0x10($sp)
/* BE8EB0 802412D0 8C82000C */  lw        $v0, 0xc($a0)
/* BE8EB4 802412D4 0C0B1EAF */  jal       get_variable
/* BE8EB8 802412D8 8C450000 */   lw       $a1, ($v0)
/* BE8EBC 802412DC 0C03AC5A */  jal       func_800EB168
/* BE8EC0 802412E0 0040202D */   daddu    $a0, $v0, $zero
/* BE8EC4 802412E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* BE8EC8 802412E8 24020002 */  addiu     $v0, $zero, 2
/* BE8ECC 802412EC 03E00008 */  jr        $ra
/* BE8ED0 802412F0 27BD0018 */   addiu    $sp, $sp, 0x18
/* BE8ED4 802412F4 00000000 */  nop       
/* BE8ED8 802412F8 00000000 */  nop       
/* BE8EDC 802412FC 00000000 */  nop       

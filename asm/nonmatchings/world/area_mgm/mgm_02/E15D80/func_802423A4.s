.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423A4
/* E18124 802423A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E18128 802423A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* E1812C 802423AC 0C03A5B2 */  jal       func_800E96C8
/* E18130 802423B0 00000000 */   nop      
/* E18134 802423B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* E18138 802423B8 24020002 */  addiu     $v0, $zero, 2
/* E1813C 802423BC 03E00008 */  jr        $ra
/* E18140 802423C0 27BD0018 */   addiu    $sp, $sp, 0x18
/* E18144 802423C4 00000000 */  nop       
/* E18148 802423C8 00000000 */  nop       
/* E1814C 802423CC 00000000 */  nop       

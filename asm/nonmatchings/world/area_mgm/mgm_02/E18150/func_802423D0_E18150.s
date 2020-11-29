.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423D0_E18150
/* E18150 802423D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E18154 802423D4 3C048025 */  lui       $a0, %hi(D_802484C0)
/* E18158 802423D8 248484C0 */  addiu     $a0, $a0, %lo(D_802484C0)
/* E1815C 802423DC AFBF0010 */  sw        $ra, 0x10($sp)
/* E18160 802423E0 0C0496CB */  jal       set_message_images
/* E18164 802423E4 00000000 */   nop      
/* E18168 802423E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* E1816C 802423EC 24020002 */  addiu     $v0, $zero, 2
/* E18170 802423F0 03E00008 */  jr        $ra
/* E18174 802423F4 27BD0018 */   addiu    $sp, $sp, 0x18
/* E18178 802423F8 00000000 */  nop       
/* E1817C 802423FC 00000000 */  nop       

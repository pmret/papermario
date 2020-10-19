.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241780_E13EE0
/* E13EE0 80241780 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E13EE4 80241784 3C048024 */  lui       $a0, 0x8024
/* E13EE8 80241788 24843560 */  addiu     $a0, $a0, 0x3560
/* E13EEC 8024178C AFBF0010 */  sw        $ra, 0x10($sp)
/* E13EF0 80241790 0C0496CB */  jal       set_message_images
/* E13EF4 80241794 00000000 */   nop      
/* E13EF8 80241798 8FBF0010 */  lw        $ra, 0x10($sp)
/* E13EFC 8024179C 24020002 */  addiu     $v0, $zero, 2
/* E13F00 802417A0 03E00008 */  jr        $ra
/* E13F04 802417A4 27BD0018 */   addiu    $sp, $sp, 0x18
/* E13F08 802417A8 00000000 */  nop       
/* E13F0C 802417AC 00000000 */  nop       

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel reset_partner_blur
/* 182F6C 8025468C 3C04800E */  lui       $a0, %hi(gBattleStatus+0xDC)
/* 182F70 80254690 8C84C14C */  lw        $a0, %lo(gBattleStatus+0xDC)($a0)
/* 182F74 80254694 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 182F78 80254698 AFBF0010 */  sw        $ra, 0x10($sp)
/* 182F7C 8025469C 0C09516B */  jal       reset_actor_blur
/* 182F80 802546A0 00000000 */   nop      
/* 182F84 802546A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 182F88 802546A8 03E00008 */  jr        $ra
/* 182F8C 802546AC 27BD0018 */   addiu    $sp, $sp, 0x18

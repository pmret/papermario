.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802186A0_69F8A0
/* 69F8A0 802186A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 69F8A4 802186A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 69F8A8 802186A8 0C09A75B */  jal       get_actor
/* 69F8AC 802186AC 8C840148 */   lw       $a0, 0x148($a0)
/* 69F8B0 802186B0 84440436 */  lh        $a0, 0x436($v0)
/* 69F8B4 802186B4 A0400224 */  sb        $zero, 0x224($v0)
/* 69F8B8 802186B8 0C011EE1 */  jal       remove_status_icon_chillout
/* 69F8BC 802186BC A0400223 */   sb       $zero, 0x223($v0)
/* 69F8C0 802186C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 69F8C4 802186C4 24020002 */  addiu     $v0, $zero, 2
/* 69F8C8 802186C8 03E00008 */  jr        $ra
/* 69F8CC 802186CC 27BD0018 */   addiu    $sp, $sp, 0x18

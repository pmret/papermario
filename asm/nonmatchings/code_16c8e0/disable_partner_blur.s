.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel disable_partner_blur
/* 182F48 80254668 3C04800E */  lui       $a0, 0x800e
/* 182F4C 8025466C 8C84C14C */  lw        $a0, -0x3eb4($a0)
/* 182F50 80254670 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 182F54 80254674 AFBF0010 */  sw        $ra, 0x10($sp)
/* 182F58 80254678 0C095157 */  jal       disable_actor_blur
/* 182F5C 8025467C 00000000 */   nop      
/* 182F60 80254680 8FBF0010 */  lw        $ra, 0x10($sp)
/* 182F64 80254684 03E00008 */  jr        $ra
/* 182F68 80254688 27BD0018 */   addiu    $sp, $sp, 0x18

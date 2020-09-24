.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_partner_blur
/* 182F24 80254644 3C04800E */  lui       $a0, 0x800e
/* 182F28 80254648 8C84C14C */  lw        $a0, -0x3eb4($a0)
/* 182F2C 8025464C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 182F30 80254650 AFBF0010 */  sw        $ra, 0x10($sp)
/* 182F34 80254654 0C0950B3 */  jal       enable_actor_blur
/* 182F38 80254658 00000000 */   nop      
/* 182F3C 8025465C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 182F40 80254660 03E00008 */  jr        $ra
/* 182F44 80254664 27BD0018 */   addiu    $sp, $sp, 0x18

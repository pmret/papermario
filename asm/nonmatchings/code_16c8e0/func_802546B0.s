.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802546B0
/* 182F90 802546B0 3C04800E */  lui       $a0, 0x800e
/* 182F94 802546B4 8C84C14C */  lw        $a0, -0x3eb4($a0)
/* 182F98 802546B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 182F9C 802546BC AFBF0010 */  sw        $ra, 0x10($sp)
/* 182FA0 802546C0 0C095184 */  jal       func_80254610
/* 182FA4 802546C4 00000000 */   nop      
/* 182FA8 802546C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 182FAC 802546CC 03E00008 */  jr        $ra
/* 182FB0 802546D0 27BD0018 */   addiu    $sp, $sp, 0x18

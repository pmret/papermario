.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel disable_partner_blur
/* 182F48 80254668 3C04800E */  lui   $a0, 0x800e
/* 182F4C 8025466C 8C84C14C */  lw    $a0, -0x3eb4($a0)
/* 182F50 80254670 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 182F54 80254674 AFBF0010 */  sw    $ra, 0x10($sp)
/* 182F58 80254678 0C095157 */  jal   disable_actor_blur
/* 182F5C 8025467C 00000000 */   nop   
/* 182F60 80254680 8FBF0010 */  lw    $ra, 0x10($sp)
/* 182F64 80254684 03E00008 */  jr    $ra
/* 182F68 80254688 27BD0018 */   addiu $sp, $sp, 0x18

/* 182F6C 8025468C 3C04800E */  lui   $a0, 0x800e
/* 182F70 80254690 8C84C14C */  lw    $a0, -0x3eb4($a0)
/* 182F74 80254694 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 182F78 80254698 AFBF0010 */  sw    $ra, 0x10($sp)
/* 182F7C 8025469C 0C09516B */  jal   func_802545AC
/* 182F80 802546A0 00000000 */   nop   
/* 182F84 802546A4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 182F88 802546A8 03E00008 */  jr    $ra
/* 182F8C 802546AC 27BD0018 */   addiu $sp, $sp, 0x18

/* 182F90 802546B0 3C04800E */  lui   $a0, 0x800e
/* 182F94 802546B4 8C84C14C */  lw    $a0, -0x3eb4($a0)
/* 182F98 802546B8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 182F9C 802546BC AFBF0010 */  sw    $ra, 0x10($sp)
/* 182FA0 802546C0 0C095184 */  jal   func_80254610
/* 182FA4 802546C4 00000000 */   nop   
/* 182FA8 802546C8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 182FAC 802546CC 03E00008 */  jr    $ra
/* 182FB0 802546D0 27BD0018 */   addiu $sp, $sp, 0x18


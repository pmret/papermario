.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242678_B2EAE8
/* B2EAE8 80242678 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2EAEC 8024267C 3C058024 */  lui       $a1, %hi(func_8024260C_B2EA7C)
/* B2EAF0 80242680 24A5260C */  addiu     $a1, $a1, %lo(func_8024260C_B2EA7C)
/* B2EAF4 80242684 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2EAF8 80242688 0C048C8F */  jal       create_generic_entity_frontUI
/* B2EAFC 8024268C 0000202D */   daddu    $a0, $zero, $zero
/* B2EB00 80242690 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2EB04 80242694 3C018025 */  lui       $at, %hi(D_80248924)
/* B2EB08 80242698 AC228924 */  sw        $v0, %lo(D_80248924)($at)
/* B2EB0C 8024269C 24020002 */  addiu     $v0, $zero, 2
/* B2EB10 802426A0 03E00008 */  jr        $ra
/* B2EB14 802426A4 27BD0018 */   addiu    $sp, $sp, 0x18

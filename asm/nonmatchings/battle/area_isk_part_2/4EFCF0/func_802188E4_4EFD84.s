.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188E4_4EFD84
/* 4EFD84 802188E4 3C048022 */  lui       $a0, %hi(D_80220740)
/* 4EFD88 802188E8 8C840740 */  lw        $a0, %lo(D_80220740)($a0)
/* 4EFD8C 802188EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFD90 802188F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFD94 802188F4 0C016914 */  jal       remove_effect
/* 4EFD98 802188F8 00000000 */   nop
/* 4EFD9C 802188FC 3C048022 */  lui       $a0, %hi(D_80220744)
/* 4EFDA0 80218900 8C840744 */  lw        $a0, %lo(D_80220744)($a0)
/* 4EFDA4 80218904 0C016914 */  jal       remove_effect
/* 4EFDA8 80218908 00000000 */   nop
/* 4EFDAC 8021890C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFDB0 80218910 24020002 */  addiu     $v0, $zero, 2
/* 4EFDB4 80218914 03E00008 */  jr        $ra
/* 4EFDB8 80218918 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4EFDBC 8021891C 00000000 */  nop

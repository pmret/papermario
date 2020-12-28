.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802188FC_59EFDC
/* 59EFDC 802188FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 59EFE0 80218900 2402FFFF */  addiu     $v0, $zero, -1
/* 59EFE4 80218904 3C058022 */  lui       $a1, %hi(D_802188B0)
/* 59EFE8 80218908 24A588B0 */  addiu     $a1, $a1, %lo(D_802188B0)
/* 59EFEC 8021890C AFBF0010 */  sw        $ra, 0x10($sp)
/* 59EFF0 80218910 3C018023 */  lui       $at, %hi(D_8022B550)
/* 59EFF4 80218914 AC22B550 */  sw        $v0, %lo(D_8022B550)($at)
/* 59EFF8 80218918 0C048C56 */  jal       bind_dynamic_entity_3
/* 59EFFC 8021891C 0000202D */   daddu    $a0, $zero, $zero
/* 59F000 80218920 8FBF0010 */  lw        $ra, 0x10($sp)
/* 59F004 80218924 24020002 */  addiu     $v0, $zero, 2
/* 59F008 80218928 03E00008 */  jr        $ra
/* 59F00C 8021892C 27BD0018 */   addiu    $sp, $sp, 0x18

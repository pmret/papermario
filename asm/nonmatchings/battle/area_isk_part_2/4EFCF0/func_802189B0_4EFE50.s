.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802189B0_4EFE50
/* 4EFE50 802189B0 3C048022 */  lui       $a0, %hi(D_80220750)
/* 4EFE54 802189B4 8C840750 */  lw        $a0, %lo(D_80220750)($a0)
/* 4EFE58 802189B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4EFE5C 802189BC AFBF0010 */  sw        $ra, 0x10($sp)
/* 4EFE60 802189C0 0C016914 */  jal       remove_effect
/* 4EFE64 802189C4 00000000 */   nop      
/* 4EFE68 802189C8 3C048022 */  lui       $a0, %hi(D_80220754)
/* 4EFE6C 802189CC 8C840754 */  lw        $a0, %lo(D_80220754)($a0)
/* 4EFE70 802189D0 0C016914 */  jal       remove_effect
/* 4EFE74 802189D4 00000000 */   nop      
/* 4EFE78 802189D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4EFE7C 802189DC 24020002 */  addiu     $v0, $zero, 2
/* 4EFE80 802189E0 03E00008 */  jr        $ra
/* 4EFE84 802189E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4EFE88 802189E8 00000000 */  nop       
/* 4EFE8C 802189EC 00000000 */  nop       

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B78_4E32B8
/* 4E32B8 80218B78 3C048022 */  lui       $a0, %hi(D_80224DA0)
/* 4E32BC 80218B7C 8C844DA0 */  lw        $a0, %lo(D_80224DA0)($a0)
/* 4E32C0 80218B80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4E32C4 80218B84 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4E32C8 80218B88 0C016914 */  jal       remove_effect
/* 4E32CC 80218B8C 00000000 */   nop
/* 4E32D0 80218B90 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4E32D4 80218B94 24020002 */  addiu     $v0, $zero, 2
/* 4E32D8 80218B98 03E00008 */  jr        $ra
/* 4E32DC 80218B9C 27BD0018 */   addiu    $sp, $sp, 0x18

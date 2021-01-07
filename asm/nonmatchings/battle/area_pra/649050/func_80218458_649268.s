.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218458_649268
/* 649268 80218458 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 64926C 8021845C AFBF0010 */  sw        $ra, 0x10($sp)
/* 649270 80218460 8C82000C */  lw        $v0, 0xc($a0)
/* 649274 80218464 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 649278 80218468 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 64927C 8021846C 0C0B2026 */  jal       set_variable
/* 649280 80218470 8C450000 */   lw       $a1, ($v0)
/* 649284 80218474 8FBF0010 */  lw        $ra, 0x10($sp)
/* 649288 80218478 24020002 */  addiu     $v0, $zero, 2
/* 64928C 8021847C 03E00008 */  jr        $ra
/* 649290 80218480 27BD0018 */   addiu    $sp, $sp, 0x18

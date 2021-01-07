.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802182A8_47F358
/* 47F358 802182A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 47F35C 802182AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 47F360 802182B0 8C82000C */  lw        $v0, 0xc($a0)
/* 47F364 802182B4 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 47F368 802182B8 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 47F36C 802182BC 0C0B2026 */  jal       set_variable
/* 47F370 802182C0 8C450000 */   lw       $a1, ($v0)
/* 47F374 802182C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 47F378 802182C8 24020002 */  addiu     $v0, $zero, 2
/* 47F37C 802182CC 03E00008 */  jr        $ra
/* 47F380 802182D0 27BD0018 */   addiu    $sp, $sp, 0x18

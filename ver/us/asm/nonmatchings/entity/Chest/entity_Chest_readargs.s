.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_Chest_readargs
/* 1095B8 802E7D38 8C820040 */  lw        $v0, 0x40($a0)
/* 1095BC 802E7D3C 3C038016 */  lui       $v1, %hi(D_8015C7D0)
/* 1095C0 802E7D40 8C63C7D0 */  lw        $v1, %lo(D_8015C7D0)($v1)
/* 1095C4 802E7D44 AC430010 */  sw        $v1, 0x10($v0)
/* 1095C8 802E7D48 3403FFFF */  ori       $v1, $zero, 0xffff
/* 1095CC 802E7D4C 03E00008 */  jr        $ra
/* 1095D0 802E7D50 A4430000 */   sh       $v1, ($v0)

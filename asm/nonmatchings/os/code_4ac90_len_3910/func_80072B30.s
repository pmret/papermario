.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072B30
/* 4DF30 80072B30 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 4DF34 80072B34 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 4DF38 80072B38 A04000AA */  sb        $zero, 0xaa($v0)
/* 4DF3C 80072B3C 24020001 */  addiu     $v0, $zero, 1
/* 4DF40 80072B40 3C01800E */  lui       $at, %hi(gBattleState)
/* 4DF44 80072B44 AC20C068 */  sw        $zero, %lo(gBattleState)($at)
/* 4DF48 80072B48 3C01800E */  lui       $at, 0x800e
/* 4DF4C 80072B4C AC22C4E0 */  sw        $v0, -0x3b20($at)
/* 4DF50 80072B50 3C01800E */  lui       $at, 0x800e
/* 4DF54 80072B54 AC20C4DC */  sw        $zero, -0x3b24($at)
/* 4DF58 80072B58 3C01800E */  lui       $at, 0x800e
/* 4DF5C 80072B5C AC20C4D0 */  sw        $zero, -0x3b30($at)
/* 4DF60 80072B60 3C01800E */  lui       $at, 0x800e
/* 4DF64 80072B64 AC20C4F0 */  sw        $zero, -0x3b10($at)
/* 4DF68 80072B68 3C01800E */  lui       $at, 0x800e
/* 4DF6C 80072B6C AC20C4D4 */  sw        $zero, -0x3b2c($at)
/* 4DF70 80072B70 3C01800E */  lui       $at, 0x800e
/* 4DF74 80072B74 AC20C4FC */  sw        $zero, -0x3b04($at)
/* 4DF78 80072B78 3C01800E */  lui       $at, 0x800e
/* 4DF7C 80072B7C AC20C4F8 */  sw        $zero, -0x3b08($at)
/* 4DF80 80072B80 3C01800E */  lui       $at, 0x800e
/* 4DF84 80072B84 AC20C4E8 */  sw        $zero, -0x3b18($at)
/* 4DF88 80072B88 3C01800E */  lui       $at, 0x800e
/* 4DF8C 80072B8C AC20C064 */  sw        $zero, -0x3f9c($at)
/* 4DF90 80072B90 3C01800E */  lui       $at, 0x800e
/* 4DF94 80072B94 AC20C060 */  sw        $zero, -0x3fa0($at)
/* 4DF98 80072B98 3C01800E */  lui       $at, 0x800e
/* 4DF9C 80072B9C AC20C4EC */  sw        $zero, -0x3b14($at)
/* 4DFA0 80072BA0 3C01800E */  lui       $at, 0x800e
/* 4DFA4 80072BA4 AC20C4F4 */  sw        $zero, -0x3b0c($at)
/* 4DFA8 80072BA8 03E00008 */  jr        $ra
/* 4DFAC 80072BAC 00000000 */   nop      

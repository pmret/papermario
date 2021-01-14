.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219208_5B26B8
/* 5B26B8 80219208 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5B26BC 8021920C AFBF0010 */  sw        $ra, 0x10($sp)
/* 5B26C0 80219210 8C82000C */  lw        $v0, 0xc($a0)
/* 5B26C4 80219214 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 5B26C8 80219218 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 5B26CC 8021921C 0C0B2026 */  jal       set_variable
/* 5B26D0 80219220 8C450000 */   lw       $a1, ($v0)
/* 5B26D4 80219224 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5B26D8 80219228 24020002 */  addiu     $v0, $zero, 2
/* 5B26DC 8021922C 03E00008 */  jr        $ra
/* 5B26E0 80219230 27BD0018 */   addiu    $sp, $sp, 0x18

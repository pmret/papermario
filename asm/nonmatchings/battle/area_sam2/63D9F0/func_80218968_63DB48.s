.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218968_63DB48
/* 63DB48 80218968 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 63DB4C 8021896C AFBF0010 */  sw        $ra, 0x10($sp)
/* 63DB50 80218970 8C82000C */  lw        $v0, 0xc($a0)
/* 63DB54 80218974 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 63DB58 80218978 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 63DB5C 8021897C 0C0B2026 */  jal       set_variable
/* 63DB60 80218980 8C450000 */   lw       $a1, ($v0)
/* 63DB64 80218984 8FBF0010 */  lw        $ra, 0x10($sp)
/* 63DB68 80218988 24020002 */  addiu     $v0, $zero, 2
/* 63DB6C 8021898C 03E00008 */  jr        $ra
/* 63DB70 80218990 27BD0018 */   addiu    $sp, $sp, 0x18

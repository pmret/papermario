.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240970
/* 92AC20 80240970 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 92AC24 80240974 AFBF0010 */  sw        $ra, 0x10($sp)
/* 92AC28 80240978 8C82000C */  lw        $v0, 0xc($a0)
/* 92AC2C 8024097C 0C0B1EAF */  jal       get_variable
/* 92AC30 80240980 8C450000 */   lw       $a1, ($v0)
/* 92AC34 80240984 3C018024 */  lui       $at, 0x8024
/* 92AC38 80240988 AC224050 */  sw        $v0, 0x4050($at)
/* 92AC3C 8024098C 24020002 */  addiu     $v0, $zero, 2
/* 92AC40 80240990 8FBF0010 */  lw        $ra, 0x10($sp)
/* 92AC44 80240994 24030001 */  addiu     $v1, $zero, 1
/* 92AC48 80240998 3C018024 */  lui       $at, 0x8024
/* 92AC4C 8024099C AC23404C */  sw        $v1, 0x404c($at)
/* 92AC50 802409A0 03E00008 */  jr        $ra
/* 92AC54 802409A4 27BD0018 */   addiu    $sp, $sp, 0x18

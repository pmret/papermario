.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240344_8DA444
/* 8DA444 80240344 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8DA448 80240348 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8DA44C 8024034C 8C82000C */  lw        $v0, 0xc($a0)
/* 8DA450 80240350 0C0B210B */  jal       get_float_variable
/* 8DA454 80240354 8C450000 */   lw       $a1, ($v0)
/* 8DA458 80240358 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8DA45C 8024035C 24020002 */  addiu     $v0, $zero, 2
/* 8DA460 80240360 3C01800B */  lui       $at, %hi(D_800B1D98)
/* 8DA464 80240364 E4201D98 */  swc1      $f0, %lo(D_800B1D98)($at)
/* 8DA468 80240368 03E00008 */  jr        $ra
/* 8DA46C 8024036C 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800298C0
/* 4CC0 800298C0 3C035D58 */  lui       $v1, 0x5d58
/* 4CC4 800298C4 3C048007 */  lui       $a0, %hi(gRandSeed)
/* 4CC8 800298C8 248443F0 */  addiu     $a0, $a0, %lo(gRandSeed)
/* 4CCC 800298CC 8C820000 */  lw        $v0, ($a0)
/* 4CD0 800298D0 34638B65 */  ori       $v1, $v1, 0x8b65
/* 4CD4 800298D4 00430018 */  mult      $v0, $v1
/* 4CD8 800298D8 3C038007 */  lui       $v1, %hi(D_8007417C)
/* 4CDC 800298DC 8C63417C */  lw        $v1, %lo(D_8007417C)($v1)
/* 4CE0 800298E0 00002812 */  mflo      $a1
/* 4CE4 800298E4 24A20001 */  addiu     $v0, $a1, 1
/* 4CE8 800298E8 AC820000 */  sw        $v0, ($a0)
/* 4CEC 800298EC 03E00008 */  jr        $ra
/* 4CF0 800298F0 AC620138 */   sw       $v0, 0x138($v1)

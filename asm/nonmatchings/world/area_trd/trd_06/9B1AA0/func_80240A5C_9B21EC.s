.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A5C_9B21EC
/* 9B21EC 80240A5C 24020001 */  addiu     $v0, $zero, 1
/* 9B21F0 80240A60 3C018024 */  lui       $at, %hi(D_802451F0)
/* 9B21F4 80240A64 AC2251F0 */  sw        $v0, %lo(D_802451F0)($at)
/* 9B21F8 80240A68 03E00008 */  jr        $ra
/* 9B21FC 80240A6C 24020002 */   addiu    $v0, $zero, 2

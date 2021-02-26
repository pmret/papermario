.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045458
/* 20858 80045458 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2085C 8004545C AFBF0010 */  sw        $ra, 0x10($sp)
/* 20860 80045460 8C82000C */  lw        $v0, 0xc($a0)
/* 20864 80045464 0C0B1EAF */  jal       func_802C7ABC
/* 20868 80045468 8C450000 */   lw       $a1, ($v0)
/* 2086C 8004546C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 20870 80045470 3C018011 */  lui       $at, %hi(D_8010F0C8)
/* 20874 80045474 AC22F0C8 */  sw        $v0, %lo(D_8010F0C8)($at)
/* 20878 80045478 24020002 */  addiu     $v0, $zero, 2
/* 2087C 8004547C 03E00008 */  jr        $ra
/* 20880 80045480 27BD0018 */   addiu    $sp, $sp, 0x18

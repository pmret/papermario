.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EF3C0
/* 88870 800EF3C0 3C018010 */  lui       $at, %hi(D_800F8024)
/* 88874 800EF3C4 AC248024 */  sw        $a0, %lo(D_800F8024)($at)
/* 88878 800EF3C8 3C018010 */  lui       $at, %hi(D_800F8028)
/* 8887C 800EF3CC 03E00008 */  jr        $ra
/* 88880 800EF3D0 AC258028 */   sw       $a1, %lo(D_800F8028)($at)

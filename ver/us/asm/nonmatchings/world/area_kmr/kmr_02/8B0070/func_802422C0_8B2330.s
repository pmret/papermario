.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422C0_8B2330
/* 8B2330 802422C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B2334 802422C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B2338 802422C8 8C82000C */  lw        $v0, 0xc($a0)
/* 8B233C 802422CC 0C0B1EAF */  jal       evt_get_variable
/* 8B2340 802422D0 8C450000 */   lw       $a1, ($v0)
/* 8B2344 802422D4 3C018024 */  lui       $at, %hi(D_80247E34_8B7EA4)
/* 8B2348 802422D8 AC227E34 */  sw        $v0, %lo(D_80247E34_8B7EA4)($at)
/* 8B234C 802422DC 24020002 */  addiu     $v0, $zero, 2
/* 8B2350 802422E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B2354 802422E4 24030001 */  addiu     $v1, $zero, 1
/* 8B2358 802422E8 3C018024 */  lui       $at, %hi(D_80247E30_8B7EA0)
/* 8B235C 802422EC AC237E30 */  sw        $v1, %lo(D_80247E30_8B7EA0)($at)
/* 8B2360 802422F0 03E00008 */  jr        $ra
/* 8B2364 802422F4 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A14_EA3314
/* EA3314 80242A14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA3318 80242A18 AFBF0010 */  sw        $ra, 0x10($sp)
/* EA331C 80242A1C 8C82000C */  lw        $v0, 0xc($a0)
/* EA3320 80242A20 0C0B53A3 */  jal       func_802D4E8C
/* EA3324 80242A24 8C450000 */   lw       $a1, ($v0)
/* EA3328 80242A28 3C018024 */  lui       $at, %hi(D_802441BC)
/* EA332C 80242A2C AC2241BC */  sw        $v0, %lo(D_802441BC)($at)
/* EA3330 80242A30 24020002 */  addiu     $v0, $zero, 2
/* EA3334 80242A34 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA3338 80242A38 24030001 */  addiu     $v1, $zero, 1
/* EA333C 80242A3C 3C018024 */  lui       $at, %hi(D_802441B8)
/* EA3340 80242A40 AC2341B8 */  sw        $v1, %lo(D_802441B8)($at)
/* EA3344 80242A44 03E00008 */  jr        $ra
/* EA3348 80242A48 27BD0018 */   addiu    $sp, $sp, 0x18

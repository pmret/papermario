.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243300_8B3370
/* 8B3370 80243300 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B3374 80243304 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B3378 80243308 8C82000C */  lw        $v0, 0xc($a0)
/* 8B337C 8024330C 3C068011 */  lui       $a2, 0x8011
/* 8B3380 80243310 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* 8B3384 80243314 0C0B2026 */  jal       set_variable
/* 8B3388 80243318 8C450000 */   lw       $a1, ($v0)
/* 8B338C 8024331C 0C03AC5A */  jal       func_800EB168
/* 8B3390 80243320 0000202D */   daddu    $a0, $zero, $zero
/* 8B3394 80243324 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B3398 80243328 24020002 */  addiu     $v0, $zero, 2
/* 8B339C 8024332C 03E00008 */  jr        $ra
/* 8B33A0 80243330 27BD0018 */   addiu    $sp, $sp, 0x18

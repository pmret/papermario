.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218280_48D420
/* 48D420 80218280 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 48D424 80218284 AFB10014 */  sw        $s1, 0x14($sp)
/* 48D428 80218288 0080882D */  daddu     $s1, $a0, $zero
/* 48D42C 8021828C AFBF0018 */  sw        $ra, 0x18($sp)
/* 48D430 80218290 AFB00010 */  sw        $s0, 0x10($sp)
/* 48D434 80218294 8E30000C */  lw        $s0, 0xc($s1)
/* 48D438 80218298 8E050000 */  lw        $a1, ($s0)
/* 48D43C 8021829C 0C0B1EAF */  jal       get_variable
/* 48D440 802182A0 26100004 */   addiu    $s0, $s0, 4
/* 48D444 802182A4 0220202D */  daddu     $a0, $s1, $zero
/* 48D448 802182A8 8E050000 */  lw        $a1, ($s0)
/* 48D44C 802182AC 0C0B1EAF */  jal       get_variable
/* 48D450 802182B0 0040802D */   daddu    $s0, $v0, $zero
/* 48D454 802182B4 0200202D */  daddu     $a0, $s0, $zero
/* 48D458 802182B8 0C00A3C2 */  jal       start_rumble
/* 48D45C 802182BC 0040282D */   daddu    $a1, $v0, $zero
/* 48D460 802182C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 48D464 802182C4 8FB10014 */  lw        $s1, 0x14($sp)
/* 48D468 802182C8 8FB00010 */  lw        $s0, 0x10($sp)
/* 48D46C 802182CC 24020002 */  addiu     $v0, $zero, 2
/* 48D470 802182D0 03E00008 */  jr        $ra
/* 48D474 802182D4 27BD0020 */   addiu    $sp, $sp, 0x20

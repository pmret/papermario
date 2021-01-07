.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021942C_64A23C
/* 64A23C 8021942C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 64A240 80219430 AFB10014 */  sw        $s1, 0x14($sp)
/* 64A244 80219434 0080882D */  daddu     $s1, $a0, $zero
/* 64A248 80219438 AFB20018 */  sw        $s2, 0x18($sp)
/* 64A24C 8021943C 3C128011 */  lui       $s2, %hi(gPlayerData)
/* 64A250 80219440 2652F290 */  addiu     $s2, $s2, %lo(gPlayerData)
/* 64A254 80219444 AFBF001C */  sw        $ra, 0x1c($sp)
/* 64A258 80219448 AFB00010 */  sw        $s0, 0x10($sp)
/* 64A25C 8021944C 8E30000C */  lw        $s0, 0xc($s1)
/* 64A260 80219450 82460000 */  lb        $a2, ($s2)
/* 64A264 80219454 8E050000 */  lw        $a1, ($s0)
/* 64A268 80219458 0C0B2026 */  jal       set_variable
/* 64A26C 8021945C 26100004 */   addiu    $s0, $s0, 4
/* 64A270 80219460 8E050000 */  lw        $a1, ($s0)
/* 64A274 80219464 82460001 */  lb        $a2, 1($s2)
/* 64A278 80219468 0C0B2026 */  jal       set_variable
/* 64A27C 8021946C 0220202D */   daddu    $a0, $s1, $zero
/* 64A280 80219470 8FBF001C */  lw        $ra, 0x1c($sp)
/* 64A284 80219474 8FB20018 */  lw        $s2, 0x18($sp)
/* 64A288 80219478 8FB10014 */  lw        $s1, 0x14($sp)
/* 64A28C 8021947C 8FB00010 */  lw        $s0, 0x10($sp)
/* 64A290 80219480 24020002 */  addiu     $v0, $zero, 2
/* 64A294 80219484 03E00008 */  jr        $ra
/* 64A298 80219488 27BD0020 */   addiu    $sp, $sp, 0x20

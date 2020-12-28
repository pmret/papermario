.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218550_649360
/* 649360 80218550 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 649364 80218554 AFB10014 */  sw        $s1, 0x14($sp)
/* 649368 80218558 0080882D */  daddu     $s1, $a0, $zero
/* 64936C 8021855C AFBF0018 */  sw        $ra, 0x18($sp)
/* 649370 80218560 AFB00010 */  sw        $s0, 0x10($sp)
/* 649374 80218564 8E30000C */  lw        $s0, 0xc($s1)
/* 649378 80218568 8E050000 */  lw        $a1, ($s0)
/* 64937C 8021856C 0C0B1EAF */  jal       get_variable
/* 649380 80218570 26100004 */   addiu    $s0, $s0, 4
/* 649384 80218574 0220202D */  daddu     $a0, $s1, $zero
/* 649388 80218578 8E050000 */  lw        $a1, ($s0)
/* 64938C 8021857C 0C0B1EAF */  jal       get_variable
/* 649390 80218580 0040802D */   daddu    $s0, $v0, $zero
/* 649394 80218584 0200202D */  daddu     $a0, $s0, $zero
/* 649398 80218588 0C00A3C2 */  jal       start_rumble
/* 64939C 8021858C 0040282D */   daddu    $a1, $v0, $zero
/* 6493A0 80218590 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6493A4 80218594 8FB10014 */  lw        $s1, 0x14($sp)
/* 6493A8 80218598 8FB00010 */  lw        $s0, 0x10($sp)
/* 6493AC 8021859C 24020002 */  addiu     $v0, $zero, 2
/* 6493B0 802185A0 03E00008 */  jr        $ra
/* 6493B4 802185A4 27BD0020 */   addiu    $sp, $sp, 0x20

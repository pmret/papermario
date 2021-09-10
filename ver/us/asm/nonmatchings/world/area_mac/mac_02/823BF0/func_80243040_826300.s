.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243040_826300
/* 826300 80243040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 826304 80243044 AFB00010 */  sw        $s0, 0x10($sp)
/* 826308 80243048 0080802D */  daddu     $s0, $a0, $zero
/* 82630C 8024304C AFBF0018 */  sw        $ra, 0x18($sp)
/* 826310 80243050 AFB10014 */  sw        $s1, 0x14($sp)
/* 826314 80243054 8E02000C */  lw        $v0, 0xc($s0)
/* 826318 80243058 0C039D7B */  jal       get_item_count
/* 82631C 8024305C 8C510000 */   lw       $s1, ($v0)
/* 826320 80243060 0200202D */  daddu     $a0, $s0, $zero
/* 826324 80243064 0040302D */  daddu     $a2, $v0, $zero
/* 826328 80243068 0C0B2026 */  jal       evt_set_variable
/* 82632C 8024306C 0220282D */   daddu    $a1, $s1, $zero
/* 826330 80243070 8FBF0018 */  lw        $ra, 0x18($sp)
/* 826334 80243074 8FB10014 */  lw        $s1, 0x14($sp)
/* 826338 80243078 8FB00010 */  lw        $s0, 0x10($sp)
/* 82633C 8024307C 24020002 */  addiu     $v0, $zero, 2
/* 826340 80243080 03E00008 */  jr        $ra
/* 826344 80243084 27BD0020 */   addiu    $sp, $sp, 0x20

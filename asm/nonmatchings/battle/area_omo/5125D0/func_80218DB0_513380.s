.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218DB0_513380
/* 513380 80218DB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 513384 80218DB4 AFB10014 */  sw        $s1, 0x14($sp)
/* 513388 80218DB8 0080882D */  daddu     $s1, $a0, $zero
/* 51338C 80218DBC AFBF0018 */  sw        $ra, 0x18($sp)
/* 513390 80218DC0 AFB00010 */  sw        $s0, 0x10($sp)
/* 513394 80218DC4 8E30000C */  lw        $s0, 0xc($s1)
/* 513398 80218DC8 8E050000 */  lw        $a1, ($s0)
/* 51339C 80218DCC 0C0B1EAF */  jal       get_variable
/* 5133A0 80218DD0 26100004 */   addiu    $s0, $s0, 4
/* 5133A4 80218DD4 0220202D */  daddu     $a0, $s1, $zero
/* 5133A8 80218DD8 8E050000 */  lw        $a1, ($s0)
/* 5133AC 80218DDC 0C0B1EAF */  jal       get_variable
/* 5133B0 80218DE0 0040802D */   daddu    $s0, $v0, $zero
/* 5133B4 80218DE4 0200202D */  daddu     $a0, $s0, $zero
/* 5133B8 80218DE8 0C00A3C2 */  jal       start_rumble
/* 5133BC 80218DEC 0040282D */   daddu    $a1, $v0, $zero
/* 5133C0 80218DF0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5133C4 80218DF4 8FB10014 */  lw        $s1, 0x14($sp)
/* 5133C8 80218DF8 8FB00010 */  lw        $s0, 0x10($sp)
/* 5133CC 80218DFC 24020002 */  addiu     $v0, $zero, 2
/* 5133D0 80218E00 03E00008 */  jr        $ra
/* 5133D4 80218E04 27BD0020 */   addiu    $sp, $sp, 0x20

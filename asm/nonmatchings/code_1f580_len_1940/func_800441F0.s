.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800441F0
/* 1F5F0 800441F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1F5F4 800441F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1F5F8 800441F8 0080802D */  daddu     $s0, $a0, $zero
/* 1F5FC 800441FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 1F600 80044200 AFB10014 */  sw        $s1, 0x14($sp)
/* 1F604 80044204 8E02000C */  lw        $v0, 0xc($s0)
/* 1F608 80044208 0C011052 */  jal       func_80044148
/* 1F60C 8004420C 8C510000 */   lw       $s1, ($v0)
/* 1F610 80044210 0200202D */  daddu     $a0, $s0, $zero
/* 1F614 80044214 0040302D */  daddu     $a2, $v0, $zero
/* 1F618 80044218 0C0B2026 */  jal       set_variable
/* 1F61C 8004421C 0220282D */   daddu    $a1, $s1, $zero
/* 1F620 80044220 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1F624 80044224 8FB10014 */  lw        $s1, 0x14($sp)
/* 1F628 80044228 8FB00010 */  lw        $s0, 0x10($sp)
/* 1F62C 8004422C 24020002 */  addiu     $v0, $zero, 2
/* 1F630 80044230 03E00008 */  jr        $ra
/* 1F634 80044234 27BD0020 */   addiu    $sp, $sp, 0x20

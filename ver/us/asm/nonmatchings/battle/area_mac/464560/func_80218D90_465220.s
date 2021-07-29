.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D90_465220
/* 465220 80218D90 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 465224 80218D94 AFB00018 */  sw        $s0, 0x18($sp)
/* 465228 80218D98 0080802D */  daddu     $s0, $a0, $zero
/* 46522C 80218D9C 3C0542D4 */  lui       $a1, 0x42d4
/* 465230 80218DA0 3C064310 */  lui       $a2, 0x4310
/* 465234 80218DA4 0000202D */  daddu     $a0, $zero, $zero
/* 465238 80218DA8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 46523C 80218DAC AFB1001C */  sw        $s1, 0x1c($sp)
/* 465240 80218DB0 8E11000C */  lw        $s1, 0xc($s0)
/* 465244 80218DB4 3C013F80 */  lui       $at, 0x3f80
/* 465248 80218DB8 44810000 */  mtc1      $at, $f0
/* 46524C 80218DBC 0000382D */  daddu     $a3, $zero, $zero
/* 465250 80218DC0 AFA00014 */  sw        $zero, 0x14($sp)
/* 465254 80218DC4 0C01C844 */  jal       playFX_6C
/* 465258 80218DC8 E7A00010 */   swc1     $f0, 0x10($sp)
/* 46525C 80218DCC 0200202D */  daddu     $a0, $s0, $zero
/* 465260 80218DD0 8E250000 */  lw        $a1, ($s1)
/* 465264 80218DD4 0C0B2026 */  jal       set_variable
/* 465268 80218DD8 0040302D */   daddu    $a2, $v0, $zero
/* 46526C 80218DDC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 465270 80218DE0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 465274 80218DE4 8FB00018 */  lw        $s0, 0x18($sp)
/* 465278 80218DE8 24020002 */  addiu     $v0, $zero, 2
/* 46527C 80218DEC 03E00008 */  jr        $ra
/* 465280 80218DF0 27BD0028 */   addiu    $sp, $sp, 0x28

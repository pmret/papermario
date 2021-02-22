.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_BCF0F0
/* BCF0F0 80240500 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BCF0F4 80240504 AFB00010 */  sw        $s0, 0x10($sp)
/* BCF0F8 80240508 0080802D */  daddu     $s0, $a0, $zero
/* BCF0FC 8024050C AFBF0014 */  sw        $ra, 0x14($sp)
/* BCF100 80240510 0C00AB39 */  jal       heap_malloc
/* BCF104 80240514 240401E0 */   addiu    $a0, $zero, 0x1e0
/* BCF108 80240518 0200202D */  daddu     $a0, $s0, $zero
/* BCF10C 8024051C 3C05FD05 */  lui       $a1, 0xfd05
/* BCF110 80240520 34A50F86 */  ori       $a1, $a1, 0xf86
/* BCF114 80240524 0C0B2026 */  jal       set_variable
/* BCF118 80240528 0040302D */   daddu    $a2, $v0, $zero
/* BCF11C 8024052C 8FBF0014 */  lw        $ra, 0x14($sp)
/* BCF120 80240530 8FB00010 */  lw        $s0, 0x10($sp)
/* BCF124 80240534 24020002 */  addiu     $v0, $zero, 2
/* BCF128 80240538 03E00008 */  jr        $ra
/* BCF12C 8024053C 27BD0018 */   addiu    $sp, $sp, 0x18

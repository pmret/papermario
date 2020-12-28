.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_5CE690
/* 5CE690 80218000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5CE694 80218004 AFB10014 */  sw        $s1, 0x14($sp)
/* 5CE698 80218008 0080882D */  daddu     $s1, $a0, $zero
/* 5CE69C 8021800C AFBF0018 */  sw        $ra, 0x18($sp)
/* 5CE6A0 80218010 AFB00010 */  sw        $s0, 0x10($sp)
/* 5CE6A4 80218014 8E30000C */  lw        $s0, 0xc($s1)
/* 5CE6A8 80218018 8E050000 */  lw        $a1, ($s0)
/* 5CE6AC 8021801C 0C0B1EAF */  jal       get_variable
/* 5CE6B0 80218020 26100004 */   addiu    $s0, $s0, 4
/* 5CE6B4 80218024 0220202D */  daddu     $a0, $s1, $zero
/* 5CE6B8 80218028 8E050000 */  lw        $a1, ($s0)
/* 5CE6BC 8021802C 0C0B1EAF */  jal       get_variable
/* 5CE6C0 80218030 0040802D */   daddu    $s0, $v0, $zero
/* 5CE6C4 80218034 0200202D */  daddu     $a0, $s0, $zero
/* 5CE6C8 80218038 0C00A3C2 */  jal       start_rumble
/* 5CE6CC 8021803C 0040282D */   daddu    $a1, $v0, $zero
/* 5CE6D0 80218040 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5CE6D4 80218044 8FB10014 */  lw        $s1, 0x14($sp)
/* 5CE6D8 80218048 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CE6DC 8021804C 24020002 */  addiu     $v0, $zero, 2
/* 5CE6E0 80218050 03E00008 */  jr        $ra
/* 5CE6E4 80218054 27BD0020 */   addiu    $sp, $sp, 0x20

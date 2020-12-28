.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_4FEA50
/* 4FEA50 80218000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4FEA54 80218004 AFB10014 */  sw        $s1, 0x14($sp)
/* 4FEA58 80218008 0080882D */  daddu     $s1, $a0, $zero
/* 4FEA5C 8021800C AFBF0018 */  sw        $ra, 0x18($sp)
/* 4FEA60 80218010 AFB00010 */  sw        $s0, 0x10($sp)
/* 4FEA64 80218014 8E30000C */  lw        $s0, 0xc($s1)
/* 4FEA68 80218018 8E050000 */  lw        $a1, ($s0)
/* 4FEA6C 8021801C 0C0B1EAF */  jal       get_variable
/* 4FEA70 80218020 26100004 */   addiu    $s0, $s0, 4
/* 4FEA74 80218024 0220202D */  daddu     $a0, $s1, $zero
/* 4FEA78 80218028 8E050000 */  lw        $a1, ($s0)
/* 4FEA7C 8021802C 0C0B1EAF */  jal       get_variable
/* 4FEA80 80218030 0040802D */   daddu    $s0, $v0, $zero
/* 4FEA84 80218034 0200202D */  daddu     $a0, $s0, $zero
/* 4FEA88 80218038 0C00A3C2 */  jal       start_rumble
/* 4FEA8C 8021803C 0040282D */   daddu    $a1, $v0, $zero
/* 4FEA90 80218040 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4FEA94 80218044 8FB10014 */  lw        $s1, 0x14($sp)
/* 4FEA98 80218048 8FB00010 */  lw        $s0, 0x10($sp)
/* 4FEA9C 8021804C 24020002 */  addiu     $v0, $zero, 2
/* 4FEAA0 80218050 03E00008 */  jr        $ra
/* 4FEAA4 80218054 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel WasStatusInflicted
/* 1AC548 8027DC68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AC54C 8027DC6C AFB10014 */  sw        $s1, 0x14($sp)
/* 1AC550 8027DC70 0080882D */  daddu     $s1, $a0, $zero
/* 1AC554 8027DC74 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1AC558 8027DC78 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AC55C 8027DC7C 8E30000C */  lw        $s0, 0xc($s1)
/* 1AC560 8027DC80 8E050000 */  lw        $a1, ($s0)
/* 1AC564 8027DC84 0C0B1EAF */  jal       get_variable
/* 1AC568 8027DC88 26100004 */   addiu    $s0, $s0, 4
/* 1AC56C 8027DC8C 3C02800E */  lui       $v0, 0x800e
/* 1AC570 8027DC90 2442C070 */  addiu     $v0, $v0, -0x3f90
/* 1AC574 8027DC94 8E050000 */  lw        $a1, ($s0)
/* 1AC578 8027DC98 80460199 */  lb        $a2, 0x199($v0)
/* 1AC57C 8027DC9C 0C0B2026 */  jal       set_variable
/* 1AC580 8027DCA0 0220202D */   daddu    $a0, $s1, $zero
/* 1AC584 8027DCA4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1AC588 8027DCA8 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AC58C 8027DCAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AC590 8027DCB0 24020002 */  addiu     $v0, $zero, 2
/* 1AC594 8027DCB4 03E00008 */  jr        $ra
/* 1AC598 8027DCB8 27BD0020 */   addiu    $sp, $sp, 0x20

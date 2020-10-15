.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetLastDamage
/* 1AC41C 8027DB3C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AC420 8027DB40 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AC424 8027DB44 0080882D */  daddu     $s1, $a0, $zero
/* 1AC428 8027DB48 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1AC42C 8027DB4C AFB00010 */  sw        $s0, 0x10($sp)
/* 1AC430 8027DB50 8E30000C */  lw        $s0, 0xc($s1)
/* 1AC434 8027DB54 8E050000 */  lw        $a1, ($s0)
/* 1AC438 8027DB58 0C0B1EAF */  jal       get_variable
/* 1AC43C 8027DB5C 26100004 */   addiu    $s0, $s0, 4
/* 1AC440 8027DB60 0040202D */  daddu     $a0, $v0, $zero
/* 1AC444 8027DB64 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AC448 8027DB68 14820002 */  bne       $a0, $v0, .L8027DB74
/* 1AC44C 8027DB6C 00000000 */   nop      
/* 1AC450 8027DB70 8E240148 */  lw        $a0, 0x148($s1)
.L8027DB74:
/* 1AC454 8027DB74 0C09A75B */  jal       get_actor
/* 1AC458 8027DB78 8E100000 */   lw       $s0, ($s0)
/* 1AC45C 8027DB7C 0220202D */  daddu     $a0, $s1, $zero
/* 1AC460 8027DB80 844601F8 */  lh        $a2, 0x1f8($v0)
/* 1AC464 8027DB84 0C0B2026 */  jal       set_variable
/* 1AC468 8027DB88 0200282D */   daddu    $a1, $s0, $zero
/* 1AC46C 8027DB8C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1AC470 8027DB90 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AC474 8027DB94 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AC478 8027DB98 24020002 */  addiu     $v0, $zero, 2
/* 1AC47C 8027DB9C 03E00008 */  jr        $ra
/* 1AC480 8027DBA0 27BD0020 */   addiu    $sp, $sp, 0x20

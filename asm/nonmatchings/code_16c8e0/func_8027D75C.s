.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8027D75C
/* 1AC03C 8027D75C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AC040 8027D760 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AC044 8027D764 0080882D */  daddu     $s1, $a0, $zero
/* 1AC048 8027D768 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1AC04C 8027D76C AFB00010 */  sw        $s0, 0x10($sp)
/* 1AC050 8027D770 8E30000C */  lw        $s0, 0xc($s1)
/* 1AC054 8027D774 8E050000 */  lw        $a1, ($s0)
/* 1AC058 8027D778 0C0B1EAF */  jal       get_variable
/* 1AC05C 8027D77C 26100004 */   addiu    $s0, $s0, 4
/* 1AC060 8027D780 0040202D */  daddu     $a0, $v0, $zero
/* 1AC064 8027D784 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AC068 8027D788 14820002 */  bne       $a0, $v0, .L8027D794
/* 1AC06C 8027D78C 8E100000 */   lw       $s0, ($s0)
/* 1AC070 8027D790 8E240148 */  lw        $a0, 0x148($s1)
.L8027D794:
/* 1AC074 8027D794 0C09A75B */  jal       get_actor
/* 1AC078 8027D798 00000000 */   nop      
/* 1AC07C 8027D79C 0220202D */  daddu     $a0, $s1, $zero
/* 1AC080 8027D7A0 80460208 */  lb        $a2, 0x208($v0)
/* 1AC084 8027D7A4 0C0B2026 */  jal       set_variable
/* 1AC088 8027D7A8 0200282D */   daddu    $a1, $s0, $zero
/* 1AC08C 8027D7AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1AC090 8027D7B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AC094 8027D7B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AC098 8027D7B8 24020002 */  addiu     $v0, $zero, 2
/* 1AC09C 8027D7BC 03E00008 */  jr        $ra
/* 1AC0A0 8027D7C0 27BD0020 */   addiu    $sp, $sp, 0x20

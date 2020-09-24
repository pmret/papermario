.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartTargetFlags
/* 19B9B0 8026D0D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19B9B4 8026D0D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 19B9B8 8026D0D8 0080902D */  daddu     $s2, $a0, $zero
/* 19B9BC 8026D0DC AFBF001C */  sw        $ra, 0x1c($sp)
/* 19B9C0 8026D0E0 AFB10014 */  sw        $s1, 0x14($sp)
/* 19B9C4 8026D0E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 19B9C8 8026D0E8 8E51000C */  lw        $s1, 0xc($s2)
/* 19B9CC 8026D0EC 8E250000 */  lw        $a1, ($s1)
/* 19B9D0 8026D0F0 0C0B1EAF */  jal       get_variable
/* 19B9D4 8026D0F4 26310004 */   addiu    $s1, $s1, 4
/* 19B9D8 8026D0F8 0040802D */  daddu     $s0, $v0, $zero
/* 19B9DC 8026D0FC 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19B9E0 8026D100 16020002 */  bne       $s0, $v0, .L8026D10C
/* 19B9E4 8026D104 00000000 */   nop      
/* 19B9E8 8026D108 8E500148 */  lw        $s0, 0x148($s2)
.L8026D10C:
/* 19B9EC 8026D10C 8E250000 */  lw        $a1, ($s1)
/* 19B9F0 8026D110 26310004 */  addiu     $s1, $s1, 4
/* 19B9F4 8026D114 0C0B1EAF */  jal       get_variable
/* 19B9F8 8026D118 0240202D */   daddu    $a0, $s2, $zero
/* 19B9FC 8026D11C 0200202D */  daddu     $a0, $s0, $zero
/* 19BA00 8026D120 8E310000 */  lw        $s1, ($s1)
/* 19BA04 8026D124 0C09A75B */  jal       get_actor
/* 19BA08 8026D128 0040802D */   daddu    $s0, $v0, $zero
/* 19BA0C 8026D12C 0040202D */  daddu     $a0, $v0, $zero
/* 19BA10 8026D130 0C099117 */  jal       get_actor_part
/* 19BA14 8026D134 0200282D */   daddu    $a1, $s0, $zero
/* 19BA18 8026D138 AC510004 */  sw        $s1, 4($v0)
/* 19BA1C 8026D13C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19BA20 8026D140 8FB20018 */  lw        $s2, 0x18($sp)
/* 19BA24 8026D144 8FB10014 */  lw        $s1, 0x14($sp)
/* 19BA28 8026D148 8FB00010 */  lw        $s0, 0x10($sp)
/* 19BA2C 8026D14C 24020002 */  addiu     $v0, $zero, 2
/* 19BA30 8026D150 03E00008 */  jr        $ra
/* 19BA34 8026D154 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartMoveSpeed
/* 19A0CC 8026B7EC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19A0D0 8026B7F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 19A0D4 8026B7F4 0080902D */  daddu     $s2, $a0, $zero
/* 19A0D8 8026B7F8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19A0DC 8026B7FC AFB10014 */  sw        $s1, 0x14($sp)
/* 19A0E0 8026B800 AFB00010 */  sw        $s0, 0x10($sp)
/* 19A0E4 8026B804 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 19A0E8 8026B808 8E50000C */  lw        $s0, 0xc($s2)
/* 19A0EC 8026B80C 8E050000 */  lw        $a1, ($s0)
/* 19A0F0 8026B810 0C0B1EAF */  jal       get_variable
/* 19A0F4 8026B814 26100004 */   addiu    $s0, $s0, 4
/* 19A0F8 8026B818 0040882D */  daddu     $s1, $v0, $zero
/* 19A0FC 8026B81C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19A100 8026B820 16220002 */  bne       $s1, $v0, .L8026B82C
/* 19A104 8026B824 00000000 */   nop      
/* 19A108 8026B828 8E510148 */  lw        $s1, 0x148($s2)
.L8026B82C:
/* 19A10C 8026B82C 8E050000 */  lw        $a1, ($s0)
/* 19A110 8026B830 26100004 */  addiu     $s0, $s0, 4
/* 19A114 8026B834 0C0B1EAF */  jal       get_variable
/* 19A118 8026B838 0240202D */   daddu    $a0, $s2, $zero
/* 19A11C 8026B83C 0240202D */  daddu     $a0, $s2, $zero
/* 19A120 8026B840 8E050000 */  lw        $a1, ($s0)
/* 19A124 8026B844 0C0B210B */  jal       get_float_variable
/* 19A128 8026B848 0040802D */   daddu    $s0, $v0, $zero
/* 19A12C 8026B84C 0220202D */  daddu     $a0, $s1, $zero
/* 19A130 8026B850 0C09A75B */  jal       get_actor
/* 19A134 8026B854 46000506 */   mov.s    $f20, $f0
/* 19A138 8026B858 0040202D */  daddu     $a0, $v0, $zero
/* 19A13C 8026B85C 0C099117 */  jal       get_actor_part
/* 19A140 8026B860 0200282D */   daddu    $a1, $s0, $zero
/* 19A144 8026B864 8C430010 */  lw        $v1, 0x10($v0)
/* 19A148 8026B868 E4740028 */  swc1      $f20, 0x28($v1)
/* 19A14C 8026B86C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19A150 8026B870 8FB20018 */  lw        $s2, 0x18($sp)
/* 19A154 8026B874 8FB10014 */  lw        $s1, 0x14($sp)
/* 19A158 8026B878 8FB00010 */  lw        $s0, 0x10($sp)
/* 19A15C 8026B87C D7B40020 */  ldc1      $f20, 0x20($sp)
/* 19A160 8026B880 24020002 */  addiu     $v0, $zero, 2
/* 19A164 8026B884 03E00008 */  jr        $ra
/* 19A168 8026B888 27BD0028 */   addiu    $sp, $sp, 0x28

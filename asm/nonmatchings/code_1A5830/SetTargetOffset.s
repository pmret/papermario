.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetTargetOffset
/* 1ABC60 8027D380 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1ABC64 8027D384 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1ABC68 8027D388 0080982D */  daddu     $s3, $a0, $zero
/* 1ABC6C 8027D38C AFBF0020 */  sw        $ra, 0x20($sp)
/* 1ABC70 8027D390 AFB20018 */  sw        $s2, 0x18($sp)
/* 1ABC74 8027D394 AFB10014 */  sw        $s1, 0x14($sp)
/* 1ABC78 8027D398 AFB00010 */  sw        $s0, 0x10($sp)
/* 1ABC7C 8027D39C 8E72000C */  lw        $s2, 0xc($s3)
/* 1ABC80 8027D3A0 8E450000 */  lw        $a1, ($s2)
/* 1ABC84 8027D3A4 0C0B1EAF */  jal       get_variable
/* 1ABC88 8027D3A8 26520004 */   addiu    $s2, $s2, 4
/* 1ABC8C 8027D3AC 0040802D */  daddu     $s0, $v0, $zero
/* 1ABC90 8027D3B0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1ABC94 8027D3B4 16020002 */  bne       $s0, $v0, .L8027D3C0
/* 1ABC98 8027D3B8 00000000 */   nop      
/* 1ABC9C 8027D3BC 8E700148 */  lw        $s0, 0x148($s3)
.L8027D3C0:
/* 1ABCA0 8027D3C0 8E450000 */  lw        $a1, ($s2)
/* 1ABCA4 8027D3C4 26520004 */  addiu     $s2, $s2, 4
/* 1ABCA8 8027D3C8 0C0B1EAF */  jal       get_variable
/* 1ABCAC 8027D3CC 0260202D */   daddu    $a0, $s3, $zero
/* 1ABCB0 8027D3D0 0200202D */  daddu     $a0, $s0, $zero
/* 1ABCB4 8027D3D4 0C09A75B */  jal       get_actor
/* 1ABCB8 8027D3D8 0040802D */   daddu    $s0, $v0, $zero
/* 1ABCBC 8027D3DC 0040202D */  daddu     $a0, $v0, $zero
/* 1ABCC0 8027D3E0 0C099117 */  jal       get_actor_part
/* 1ABCC4 8027D3E4 0200282D */   daddu    $a1, $s0, $zero
/* 1ABCC8 8027D3E8 8E450000 */  lw        $a1, ($s2)
/* 1ABCCC 8027D3EC 26520004 */  addiu     $s2, $s2, 4
/* 1ABCD0 8027D3F0 0260202D */  daddu     $a0, $s3, $zero
/* 1ABCD4 8027D3F4 0C0B1EAF */  jal       get_variable
/* 1ABCD8 8027D3F8 0040882D */   daddu    $s1, $v0, $zero
/* 1ABCDC 8027D3FC 0260202D */  daddu     $a0, $s3, $zero
/* 1ABCE0 8027D400 8E450000 */  lw        $a1, ($s2)
/* 1ABCE4 8027D404 0C0B1EAF */  jal       get_variable
/* 1ABCE8 8027D408 0040802D */   daddu    $s0, $v0, $zero
/* 1ABCEC 8027D40C A622006E */  sh        $v0, 0x6e($s1)
/* 1ABCF0 8027D410 A630006C */  sh        $s0, 0x6c($s1)
/* 1ABCF4 8027D414 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1ABCF8 8027D418 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1ABCFC 8027D41C 8FB20018 */  lw        $s2, 0x18($sp)
/* 1ABD00 8027D420 8FB10014 */  lw        $s1, 0x14($sp)
/* 1ABD04 8027D424 8FB00010 */  lw        $s0, 0x10($sp)
/* 1ABD08 8027D428 24020002 */  addiu     $v0, $zero, 2
/* 1ABD0C 8027D42C 03E00008 */  jr        $ra
/* 1ABD10 8027D430 27BD0028 */   addiu    $sp, $sp, 0x28

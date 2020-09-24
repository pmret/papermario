.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartEventFlags
/* 19BC20 8026D340 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19BC24 8026D344 AFB20018 */  sw        $s2, 0x18($sp)
/* 19BC28 8026D348 0080902D */  daddu     $s2, $a0, $zero
/* 19BC2C 8026D34C AFBF001C */  sw        $ra, 0x1c($sp)
/* 19BC30 8026D350 AFB10014 */  sw        $s1, 0x14($sp)
/* 19BC34 8026D354 AFB00010 */  sw        $s0, 0x10($sp)
/* 19BC38 8026D358 8E51000C */  lw        $s1, 0xc($s2)
/* 19BC3C 8026D35C 8E250000 */  lw        $a1, ($s1)
/* 19BC40 8026D360 0C0B1EAF */  jal       get_variable
/* 19BC44 8026D364 26310004 */   addiu    $s1, $s1, 4
/* 19BC48 8026D368 0040802D */  daddu     $s0, $v0, $zero
/* 19BC4C 8026D36C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19BC50 8026D370 16020002 */  bne       $s0, $v0, .L8026D37C
/* 19BC54 8026D374 00000000 */   nop      
/* 19BC58 8026D378 8E500148 */  lw        $s0, 0x148($s2)
.L8026D37C:
/* 19BC5C 8026D37C 8E250000 */  lw        $a1, ($s1)
/* 19BC60 8026D380 26310004 */  addiu     $s1, $s1, 4
/* 19BC64 8026D384 0C0B1EAF */  jal       get_variable
/* 19BC68 8026D388 0240202D */   daddu    $a0, $s2, $zero
/* 19BC6C 8026D38C 0200202D */  daddu     $a0, $s0, $zero
/* 19BC70 8026D390 8E310000 */  lw        $s1, ($s1)
/* 19BC74 8026D394 0C09A75B */  jal       get_actor
/* 19BC78 8026D398 0040802D */   daddu    $s0, $v0, $zero
/* 19BC7C 8026D39C 0040202D */  daddu     $a0, $v0, $zero
/* 19BC80 8026D3A0 0C099117 */  jal       get_actor_part
/* 19BC84 8026D3A4 0200282D */   daddu    $a1, $s0, $zero
/* 19BC88 8026D3A8 AC51007C */  sw        $s1, 0x7c($v0)
/* 19BC8C 8026D3AC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19BC90 8026D3B0 8FB20018 */  lw        $s2, 0x18($sp)
/* 19BC94 8026D3B4 8FB10014 */  lw        $s1, 0x14($sp)
/* 19BC98 8026D3B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 19BC9C 8026D3BC 24020002 */  addiu     $v0, $zero, 2
/* 19BCA0 8026D3C0 03E00008 */  jr        $ra
/* 19BCA4 8026D3C4 27BD0020 */   addiu    $sp, $sp, 0x20

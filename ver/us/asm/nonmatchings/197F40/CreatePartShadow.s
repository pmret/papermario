.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel CreatePartShadow
/* 19DE0C 8026F52C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19DE10 8026F530 AFB20018 */  sw        $s2, 0x18($sp)
/* 19DE14 8026F534 0080902D */  daddu     $s2, $a0, $zero
/* 19DE18 8026F538 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19DE1C 8026F53C AFB10014 */  sw        $s1, 0x14($sp)
/* 19DE20 8026F540 AFB00010 */  sw        $s0, 0x10($sp)
/* 19DE24 8026F544 8E50000C */  lw        $s0, 0xc($s2)
/* 19DE28 8026F548 8E050000 */  lw        $a1, ($s0)
/* 19DE2C 8026F54C 0C0B1EAF */  jal       evt_get_variable
/* 19DE30 8026F550 26100004 */   addiu    $s0, $s0, 4
/* 19DE34 8026F554 0040882D */  daddu     $s1, $v0, $zero
/* 19DE38 8026F558 8E050000 */  lw        $a1, ($s0)
/* 19DE3C 8026F55C 0C0B1EAF */  jal       evt_get_variable
/* 19DE40 8026F560 0240202D */   daddu    $a0, $s2, $zero
/* 19DE44 8026F564 0040282D */  daddu     $a1, $v0, $zero
/* 19DE48 8026F568 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19DE4C 8026F56C 16220002 */  bne       $s1, $v0, .L8026F578
/* 19DE50 8026F570 00000000 */   nop
/* 19DE54 8026F574 8E510148 */  lw        $s1, 0x148($s2)
.L8026F578:
/* 19DE58 8026F578 0C099CC7 */  jal       create_part_shadow
/* 19DE5C 8026F57C 0220202D */   daddu    $a0, $s1, $zero
/* 19DE60 8026F580 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19DE64 8026F584 8FB20018 */  lw        $s2, 0x18($sp)
/* 19DE68 8026F588 8FB10014 */  lw        $s1, 0x14($sp)
/* 19DE6C 8026F58C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19DE70 8026F590 24020002 */  addiu     $v0, $zero, 2
/* 19DE74 8026F594 03E00008 */  jr        $ra
/* 19DE78 8026F598 27BD0020 */   addiu    $sp, $sp, 0x20

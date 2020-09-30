.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026D51C
/* 19BDFC 8026D51C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19BE00 8026D520 AFB20018 */  sw        $s2, 0x18($sp)
/* 19BE04 8026D524 0080902D */  daddu     $s2, $a0, $zero
/* 19BE08 8026D528 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19BE0C 8026D52C AFB10014 */  sw        $s1, 0x14($sp)
/* 19BE10 8026D530 AFB00010 */  sw        $s0, 0x10($sp)
/* 19BE14 8026D534 8E51000C */  lw        $s1, 0xc($s2)
/* 19BE18 8026D538 8E250000 */  lw        $a1, ($s1)
/* 19BE1C 8026D53C 0C0B1EAF */  jal       get_variable
/* 19BE20 8026D540 26310004 */   addiu    $s1, $s1, 4
/* 19BE24 8026D544 0040802D */  daddu     $s0, $v0, $zero
/* 19BE28 8026D548 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19BE2C 8026D54C 16020002 */  bne       $s0, $v0, .L8026D558
/* 19BE30 8026D550 00000000 */   nop      
/* 19BE34 8026D554 8E500148 */  lw        $s0, 0x148($s2)
.L8026D558:
/* 19BE38 8026D558 8E250000 */  lw        $a1, ($s1)
/* 19BE3C 8026D55C 26310004 */  addiu     $s1, $s1, 4
/* 19BE40 8026D560 0C0B1EAF */  jal       get_variable
/* 19BE44 8026D564 0240202D */   daddu    $a0, $s2, $zero
/* 19BE48 8026D568 0200202D */  daddu     $a0, $s0, $zero
/* 19BE4C 8026D56C 8E310000 */  lw        $s1, ($s1)
/* 19BE50 8026D570 0C09A75B */  jal       get_actor
/* 19BE54 8026D574 0040802D */   daddu    $s0, $v0, $zero
/* 19BE58 8026D578 0040202D */  daddu     $a0, $v0, $zero
/* 19BE5C 8026D57C 0C099117 */  jal       get_actor_part
/* 19BE60 8026D580 0200282D */   daddu    $a1, $s0, $zero
/* 19BE64 8026D584 AC510080 */  sw        $s1, 0x80($v0)
/* 19BE68 8026D588 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19BE6C 8026D58C 8FB20018 */  lw        $s2, 0x18($sp)
/* 19BE70 8026D590 8FB10014 */  lw        $s1, 0x14($sp)
/* 19BE74 8026D594 8FB00010 */  lw        $s0, 0x10($sp)
/* 19BE78 8026D598 24020002 */  addiu     $v0, $zero, 2
/* 19BE7C 8026D59C 03E00008 */  jr        $ra
/* 19BE80 8026D5A0 27BD0020 */   addiu    $sp, $sp, 0x20

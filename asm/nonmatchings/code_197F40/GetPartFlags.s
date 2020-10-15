.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetPartFlags
/* 19BAF8 8026D218 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19BAFC 8026D21C AFB20018 */  sw        $s2, 0x18($sp)
/* 19BB00 8026D220 0080902D */  daddu     $s2, $a0, $zero
/* 19BB04 8026D224 AFBF001C */  sw        $ra, 0x1c($sp)
/* 19BB08 8026D228 AFB10014 */  sw        $s1, 0x14($sp)
/* 19BB0C 8026D22C AFB00010 */  sw        $s0, 0x10($sp)
/* 19BB10 8026D230 8E51000C */  lw        $s1, 0xc($s2)
/* 19BB14 8026D234 8E250000 */  lw        $a1, ($s1)
/* 19BB18 8026D238 0C0B1EAF */  jal       get_variable
/* 19BB1C 8026D23C 26310004 */   addiu    $s1, $s1, 4
/* 19BB20 8026D240 0040802D */  daddu     $s0, $v0, $zero
/* 19BB24 8026D244 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19BB28 8026D248 16020002 */  bne       $s0, $v0, .L8026D254
/* 19BB2C 8026D24C 00000000 */   nop      
/* 19BB30 8026D250 8E500148 */  lw        $s0, 0x148($s2)
.L8026D254:
/* 19BB34 8026D254 8E250000 */  lw        $a1, ($s1)
/* 19BB38 8026D258 26310004 */  addiu     $s1, $s1, 4
/* 19BB3C 8026D25C 0C0B1EAF */  jal       get_variable
/* 19BB40 8026D260 0240202D */   daddu    $a0, $s2, $zero
/* 19BB44 8026D264 0200202D */  daddu     $a0, $s0, $zero
/* 19BB48 8026D268 8E310000 */  lw        $s1, ($s1)
/* 19BB4C 8026D26C 0C09A75B */  jal       get_actor
/* 19BB50 8026D270 0040802D */   daddu    $s0, $v0, $zero
/* 19BB54 8026D274 0040202D */  daddu     $a0, $v0, $zero
/* 19BB58 8026D278 0C099117 */  jal       get_actor_part
/* 19BB5C 8026D27C 0200282D */   daddu    $a1, $s0, $zero
/* 19BB60 8026D280 0240202D */  daddu     $a0, $s2, $zero
/* 19BB64 8026D284 8C460000 */  lw        $a2, ($v0)
/* 19BB68 8026D288 0C0B2026 */  jal       set_variable
/* 19BB6C 8026D28C 0220282D */   daddu    $a1, $s1, $zero
/* 19BB70 8026D290 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19BB74 8026D294 8FB20018 */  lw        $s2, 0x18($sp)
/* 19BB78 8026D298 8FB10014 */  lw        $s1, 0x14($sp)
/* 19BB7C 8026D29C 8FB00010 */  lw        $s0, 0x10($sp)
/* 19BB80 8026D2A0 24020002 */  addiu     $v0, $zero, 2
/* 19BB84 8026D2A4 03E00008 */  jr        $ra
/* 19BB88 8026D2A8 27BD0020 */   addiu    $sp, $sp, 0x20

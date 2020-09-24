.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel StopLoopingSoundAtActor
/* 1822F8 80253A18 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1822FC 80253A1C AFB20018 */  sw        $s2, 0x18($sp)
/* 182300 80253A20 0080902D */  daddu     $s2, $a0, $zero
/* 182304 80253A24 AFBF001C */  sw        $ra, 0x1c($sp)
/* 182308 80253A28 AFB10014 */  sw        $s1, 0x14($sp)
/* 18230C 80253A2C AFB00010 */  sw        $s0, 0x10($sp)
/* 182310 80253A30 8E50000C */  lw        $s0, 0xc($s2)
/* 182314 80253A34 8E050000 */  lw        $a1, ($s0)
/* 182318 80253A38 0C0B1EAF */  jal       get_variable
/* 18231C 80253A3C 26100004 */   addiu    $s0, $s0, 4
/* 182320 80253A40 0040882D */  daddu     $s1, $v0, $zero
/* 182324 80253A44 8E050000 */  lw        $a1, ($s0)
/* 182328 80253A48 0C0B1EAF */  jal       get_variable
/* 18232C 80253A4C 0240202D */   daddu    $a0, $s2, $zero
/* 182330 80253A50 0040802D */  daddu     $s0, $v0, $zero
/* 182334 80253A54 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 182338 80253A58 16220002 */  bne       $s1, $v0, .L80253A64
/* 18233C 80253A5C 00000000 */   nop      
/* 182340 80253A60 8E510148 */  lw        $s1, 0x148($s2)
.L80253A64:
/* 182344 80253A64 0C09A75B */  jal       get_actor
/* 182348 80253A68 0220202D */   daddu    $a0, $s1, $zero
/* 18234C 80253A6C 00101880 */  sll       $v1, $s0, 2
/* 182350 80253A70 00438021 */  addu      $s0, $v0, $v1
/* 182354 80253A74 8E040438 */  lw        $a0, 0x438($s0)
/* 182358 80253A78 10800005 */  beqz      $a0, .L80253A90
/* 18235C 80253A7C 24020002 */   addiu    $v0, $zero, 2
/* 182360 80253A80 0C05271B */  jal       stop_sound
/* 182364 80253A84 00000000 */   nop      
/* 182368 80253A88 AE000438 */  sw        $zero, 0x438($s0)
/* 18236C 80253A8C 24020002 */  addiu     $v0, $zero, 2
.L80253A90:
/* 182370 80253A90 8FBF001C */  lw        $ra, 0x1c($sp)
/* 182374 80253A94 8FB20018 */  lw        $s2, 0x18($sp)
/* 182378 80253A98 8FB10014 */  lw        $s1, 0x14($sp)
/* 18237C 80253A9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 182380 80253AA0 03E00008 */  jr        $ra
/* 182384 80253AA4 27BD0020 */   addiu    $sp, $sp, 0x20

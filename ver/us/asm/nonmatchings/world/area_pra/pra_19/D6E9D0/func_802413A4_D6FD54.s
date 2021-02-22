.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413A4_D6FD54
/* D6FD54 802413A4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D6FD58 802413A8 AFB20018 */  sw        $s2, 0x18($sp)
/* D6FD5C 802413AC 0080902D */  daddu     $s2, $a0, $zero
/* D6FD60 802413B0 AFBF0024 */  sw        $ra, 0x24($sp)
/* D6FD64 802413B4 AFB40020 */  sw        $s4, 0x20($sp)
/* D6FD68 802413B8 AFB3001C */  sw        $s3, 0x1c($sp)
/* D6FD6C 802413BC AFB10014 */  sw        $s1, 0x14($sp)
/* D6FD70 802413C0 AFB00010 */  sw        $s0, 0x10($sp)
/* D6FD74 802413C4 8E50000C */  lw        $s0, 0xc($s2)
/* D6FD78 802413C8 8E530148 */  lw        $s3, 0x148($s2)
/* D6FD7C 802413CC 8E050000 */  lw        $a1, ($s0)
/* D6FD80 802413D0 0C0B1EAF */  jal       get_variable
/* D6FD84 802413D4 26100004 */   addiu    $s0, $s0, 4
/* D6FD88 802413D8 2C510001 */  sltiu     $s1, $v0, 1
/* D6FD8C 802413DC 8E050000 */  lw        $a1, ($s0)
/* D6FD90 802413E0 26100004 */  addiu     $s0, $s0, 4
/* D6FD94 802413E4 3C14800B */  lui       $s4, %hi(gCurrentEncounter)
/* D6FD98 802413E8 26940F10 */  addiu     $s4, $s4, %lo(gCurrentEncounter)
/* D6FD9C 802413EC 0C0B1EAF */  jal       get_variable
/* D6FDA0 802413F0 0240202D */   daddu    $a0, $s2, $zero
/* D6FDA4 802413F4 50400001 */  beql      $v0, $zero, .L802413FC
/* D6FDA8 802413F8 26310001 */   addiu    $s1, $s1, 1
.L802413FC:
/* D6FDAC 802413FC 8E050000 */  lw        $a1, ($s0)
/* D6FDB0 80241400 26100004 */  addiu     $s0, $s0, 4
/* D6FDB4 80241404 0C0B1EAF */  jal       get_variable
/* D6FDB8 80241408 0240202D */   daddu    $a0, $s2, $zero
/* D6FDBC 8024140C 50400001 */  beql      $v0, $zero, .L80241414
/* D6FDC0 80241410 26310001 */   addiu    $s1, $s1, 1
.L80241414:
/* D6FDC4 80241414 8E050000 */  lw        $a1, ($s0)
/* D6FDC8 80241418 0C0B1EAF */  jal       get_variable
/* D6FDCC 8024141C 0240202D */   daddu    $a0, $s2, $zero
/* D6FDD0 80241420 50400001 */  beql      $v0, $zero, .L80241428
/* D6FDD4 80241424 26310001 */   addiu    $s1, $s1, 1
.L80241428:
/* D6FDD8 80241428 24020002 */  addiu     $v0, $zero, 2
/* D6FDDC 8024142C 12220016 */  beq       $s1, $v0, .L80241488
/* D6FDE0 80241430 00000000 */   nop
/* D6FDE4 80241434 2A220003 */  slti      $v0, $s1, 3
/* D6FDE8 80241438 10400005 */  beqz      $v0, .L80241450
/* D6FDEC 8024143C 24020001 */   addiu    $v0, $zero, 1
/* D6FDF0 80241440 1222000B */  beq       $s1, $v0, .L80241470
/* D6FDF4 80241444 00000000 */   nop
/* D6FDF8 80241448 08090534 */  j         .L802414D0
/* D6FDFC 8024144C 00000000 */   nop
.L80241450:
/* D6FE00 80241450 24020003 */  addiu     $v0, $zero, 3
/* D6FE04 80241454 12220012 */  beq       $s1, $v0, .L802414A0
/* D6FE08 80241458 00000000 */   nop
/* D6FE0C 8024145C 24020004 */  addiu     $v0, $zero, 4
/* D6FE10 80241460 12220015 */  beq       $s1, $v0, .L802414B8
/* D6FE14 80241464 00000000 */   nop
/* D6FE18 80241468 08090534 */  j         .L802414D0
/* D6FE1C 8024146C 00000000 */   nop
.L80241470:
/* D6FE20 80241470 82620004 */  lb        $v0, 4($s3)
/* D6FE24 80241474 00021080 */  sll       $v0, $v0, 2
/* D6FE28 80241478 00541021 */  addu      $v0, $v0, $s4
/* D6FE2C 8024147C 8C430028 */  lw        $v1, 0x28($v0)
/* D6FE30 80241480 08090533 */  j         .L802414CC
/* D6FE34 80241484 24022101 */   addiu    $v0, $zero, 0x2101
.L80241488:
/* D6FE38 80241488 82620004 */  lb        $v0, 4($s3)
/* D6FE3C 8024148C 00021080 */  sll       $v0, $v0, 2
/* D6FE40 80241490 00541021 */  addu      $v0, $v0, $s4
/* D6FE44 80241494 8C430028 */  lw        $v1, 0x28($v0)
/* D6FE48 80241498 08090533 */  j         .L802414CC
/* D6FE4C 8024149C 24022102 */   addiu    $v0, $zero, 0x2102
.L802414A0:
/* D6FE50 802414A0 82620004 */  lb        $v0, 4($s3)
/* D6FE54 802414A4 00021080 */  sll       $v0, $v0, 2
/* D6FE58 802414A8 00541021 */  addu      $v0, $v0, $s4
/* D6FE5C 802414AC 8C430028 */  lw        $v1, 0x28($v0)
/* D6FE60 802414B0 08090533 */  j         .L802414CC
/* D6FE64 802414B4 24022103 */   addiu    $v0, $zero, 0x2103
.L802414B8:
/* D6FE68 802414B8 82620004 */  lb        $v0, 4($s3)
/* D6FE6C 802414BC 00021080 */  sll       $v0, $v0, 2
/* D6FE70 802414C0 00541021 */  addu      $v0, $v0, $s4
/* D6FE74 802414C4 8C430028 */  lw        $v1, 0x28($v0)
/* D6FE78 802414C8 24022104 */  addiu     $v0, $zero, 0x2104
.L802414CC:
/* D6FE7C 802414CC A4620044 */  sh        $v0, 0x44($v1)
.L802414D0:
/* D6FE80 802414D0 8FBF0024 */  lw        $ra, 0x24($sp)
/* D6FE84 802414D4 8FB40020 */  lw        $s4, 0x20($sp)
/* D6FE88 802414D8 8FB3001C */  lw        $s3, 0x1c($sp)
/* D6FE8C 802414DC 8FB20018 */  lw        $s2, 0x18($sp)
/* D6FE90 802414E0 8FB10014 */  lw        $s1, 0x14($sp)
/* D6FE94 802414E4 8FB00010 */  lw        $s0, 0x10($sp)
/* D6FE98 802414E8 24020002 */  addiu     $v0, $zero, 2
/* D6FE9C 802414EC 03E00008 */  jr        $ra
/* D6FEA0 802414F0 27BD0028 */   addiu    $sp, $sp, 0x28

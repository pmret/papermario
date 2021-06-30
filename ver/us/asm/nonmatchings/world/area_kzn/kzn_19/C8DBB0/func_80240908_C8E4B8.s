.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240908_C8E4B8
/* C8E4B8 80240908 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C8E4BC 8024090C AFB20020 */  sw        $s2, 0x20($sp)
/* C8E4C0 80240910 0080902D */  daddu     $s2, $a0, $zero
/* C8E4C4 80240914 AFBF0024 */  sw        $ra, 0x24($sp)
/* C8E4C8 80240918 AFB1001C */  sw        $s1, 0x1c($sp)
/* C8E4CC 8024091C AFB00018 */  sw        $s0, 0x18($sp)
/* C8E4D0 80240920 10A00035 */  beqz      $a1, .L802409F8
/* C8E4D4 80240924 8E51000C */   lw       $s1, 0xc($s2)
/* C8E4D8 80240928 0C00AB39 */  jal       heap_malloc
/* C8E4DC 8024092C 24040058 */   addiu    $a0, $zero, 0x58
/* C8E4E0 80240930 0040802D */  daddu     $s0, $v0, $zero
/* C8E4E4 80240934 AE500084 */  sw        $s0, 0x84($s2)
/* C8E4E8 80240938 8E250000 */  lw        $a1, ($s1)
/* C8E4EC 8024093C 26310004 */  addiu     $s1, $s1, 4
/* C8E4F0 80240940 0C0B1EAF */  jal       get_variable
/* C8E4F4 80240944 0240202D */   daddu    $a0, $s2, $zero
/* C8E4F8 80240948 AE020038 */  sw        $v0, 0x38($s0)
/* C8E4FC 8024094C 8E250000 */  lw        $a1, ($s1)
/* C8E500 80240950 26310004 */  addiu     $s1, $s1, 4
/* C8E504 80240954 0C0B210B */  jal       get_float_variable
/* C8E508 80240958 0240202D */   daddu    $a0, $s2, $zero
/* C8E50C 8024095C E6000018 */  swc1      $f0, 0x18($s0)
/* C8E510 80240960 8E250000 */  lw        $a1, ($s1)
/* C8E514 80240964 26310004 */  addiu     $s1, $s1, 4
/* C8E518 80240968 0C0B210B */  jal       get_float_variable
/* C8E51C 8024096C 0240202D */   daddu    $a0, $s2, $zero
/* C8E520 80240970 E6000024 */  swc1      $f0, 0x24($s0)
/* C8E524 80240974 8E250000 */  lw        $a1, ($s1)
/* C8E528 80240978 26310004 */  addiu     $s1, $s1, 4
/* C8E52C 8024097C 0C0B210B */  jal       get_float_variable
/* C8E530 80240980 0240202D */   daddu    $a0, $s2, $zero
/* C8E534 80240984 E6000020 */  swc1      $f0, 0x20($s0)
/* C8E538 80240988 8E250000 */  lw        $a1, ($s1)
/* C8E53C 8024098C 0C0B210B */  jal       get_float_variable
/* C8E540 80240990 0240202D */   daddu    $a0, $s2, $zero
/* C8E544 80240994 3C013F80 */  lui       $at, 0x3f80
/* C8E548 80240998 44811000 */  mtc1      $at, $f2
/* C8E54C 8024099C E6000028 */  swc1      $f0, 0x28($s0)
/* C8E550 802409A0 AFA00014 */  sw        $zero, 0x14($sp)
/* C8E554 802409A4 E7A20010 */  swc1      $f2, 0x10($sp)
/* C8E558 802409A8 8E050018 */  lw        $a1, 0x18($s0)
/* C8E55C 802409AC 8E060024 */  lw        $a2, 0x24($s0)
/* C8E560 802409B0 8E070020 */  lw        $a3, 0x20($s0)
/* C8E564 802409B4 0C01C9AC */  jal       playFX_7B
/* C8E568 802409B8 24040001 */   addiu    $a0, $zero, 1
/* C8E56C 802409BC AE020054 */  sw        $v0, 0x54($s0)
/* C8E570 802409C0 8C43000C */  lw        $v1, 0xc($v0)
/* C8E574 802409C4 9202003B */  lbu       $v0, 0x3b($s0)
/* C8E578 802409C8 A0620034 */  sb        $v0, 0x34($v1)
/* C8E57C 802409CC 8E020054 */  lw        $v0, 0x54($s0)
/* C8E580 802409D0 8C42000C */  lw        $v0, 0xc($v0)
/* C8E584 802409D4 AC400020 */  sw        $zero, 0x20($v0)
/* C8E588 802409D8 8E050018 */  lw        $a1, 0x18($s0)
/* C8E58C 802409DC 8E060028 */  lw        $a2, 0x28($s0)
/* C8E590 802409E0 8E070020 */  lw        $a3, 0x20($s0)
/* C8E594 802409E4 0C044898 */  jal       create_shadow_type
/* C8E598 802409E8 0000202D */   daddu    $a0, $zero, $zero
/* C8E59C 802409EC AE020040 */  sw        $v0, 0x40($s0)
/* C8E5A0 802409F0 2402010E */  addiu     $v0, $zero, 0x10e
/* C8E5A4 802409F4 A602004C */  sh        $v0, 0x4c($s0)
.L802409F8:
/* C8E5A8 802409F8 8FBF0024 */  lw        $ra, 0x24($sp)
/* C8E5AC 802409FC 8FB20020 */  lw        $s2, 0x20($sp)
/* C8E5B0 80240A00 8FB1001C */  lw        $s1, 0x1c($sp)
/* C8E5B4 80240A04 8FB00018 */  lw        $s0, 0x18($sp)
/* C8E5B8 80240A08 24020002 */  addiu     $v0, $zero, 2
/* C8E5BC 80240A0C 03E00008 */  jr        $ra
/* C8E5C0 80240A10 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240908_EA93E8
/* EA93E8 80240908 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EA93EC 8024090C AFB20020 */  sw        $s2, 0x20($sp)
/* EA93F0 80240910 0080902D */  daddu     $s2, $a0, $zero
/* EA93F4 80240914 AFBF0024 */  sw        $ra, 0x24($sp)
/* EA93F8 80240918 AFB1001C */  sw        $s1, 0x1c($sp)
/* EA93FC 8024091C AFB00018 */  sw        $s0, 0x18($sp)
/* EA9400 80240920 10A00035 */  beqz      $a1, .L802409F8
/* EA9404 80240924 8E51000C */   lw       $s1, 0xc($s2)
/* EA9408 80240928 0C00AFF5 */  jal       func_8002BFD4
/* EA940C 8024092C 24040058 */   addiu    $a0, $zero, 0x58
/* EA9410 80240930 0040802D */  daddu     $s0, $v0, $zero
/* EA9414 80240934 AE500084 */  sw        $s0, 0x84($s2)
/* EA9418 80240938 8E250000 */  lw        $a1, ($s1)
/* EA941C 8024093C 26310004 */  addiu     $s1, $s1, 4
/* EA9420 80240940 0C0B53A3 */  jal       dead_get_variable
/* EA9424 80240944 0240202D */   daddu    $a0, $s2, $zero
/* EA9428 80240948 AE020038 */  sw        $v0, 0x38($s0)
/* EA942C 8024094C 8E250000 */  lw        $a1, ($s1)
/* EA9430 80240950 26310004 */  addiu     $s1, $s1, 4
/* EA9434 80240954 0C0B55FF */  jal       dead_get_float_variable
/* EA9438 80240958 0240202D */   daddu    $a0, $s2, $zero
/* EA943C 8024095C E6000018 */  swc1      $f0, 0x18($s0)
/* EA9440 80240960 8E250000 */  lw        $a1, ($s1)
/* EA9444 80240964 26310004 */  addiu     $s1, $s1, 4
/* EA9448 80240968 0C0B55FF */  jal       dead_get_float_variable
/* EA944C 8024096C 0240202D */   daddu    $a0, $s2, $zero
/* EA9450 80240970 E6000024 */  swc1      $f0, 0x24($s0)
/* EA9454 80240974 8E250000 */  lw        $a1, ($s1)
/* EA9458 80240978 26310004 */  addiu     $s1, $s1, 4
/* EA945C 8024097C 0C0B55FF */  jal       dead_get_float_variable
/* EA9460 80240980 0240202D */   daddu    $a0, $s2, $zero
/* EA9464 80240984 E6000020 */  swc1      $f0, 0x20($s0)
/* EA9468 80240988 8E250000 */  lw        $a1, ($s1)
/* EA946C 8024098C 0C0B55FF */  jal       dead_get_float_variable
/* EA9470 80240990 0240202D */   daddu    $a0, $s2, $zero
/* EA9474 80240994 3C013F80 */  lui       $at, 0x3f80
/* EA9478 80240998 44811000 */  mtc1      $at, $f2
/* EA947C 8024099C E6000028 */  swc1      $f0, 0x28($s0)
/* EA9480 802409A0 AFA00014 */  sw        $zero, 0x14($sp)
/* EA9484 802409A4 E7A20010 */  swc1      $f2, 0x10($sp)
/* EA9488 802409A8 8E050018 */  lw        $a1, 0x18($s0)
/* EA948C 802409AC 8E060024 */  lw        $a2, 0x24($s0)
/* EA9490 802409B0 8E070020 */  lw        $a3, 0x20($s0)
/* EA9494 802409B4 0C01DE4C */  jal       func_80077930
/* EA9498 802409B8 24040001 */   addiu    $a0, $zero, 1
/* EA949C 802409BC AE020054 */  sw        $v0, 0x54($s0)
/* EA94A0 802409C0 8C43000C */  lw        $v1, 0xc($v0)
/* EA94A4 802409C4 9202003B */  lbu       $v0, 0x3b($s0)
/* EA94A8 802409C8 A0620034 */  sb        $v0, 0x34($v1)
/* EA94AC 802409CC 8E020054 */  lw        $v0, 0x54($s0)
/* EA94B0 802409D0 8C42000C */  lw        $v0, 0xc($v0)
/* EA94B4 802409D4 AC400020 */  sw        $zero, 0x20($v0)
/* EA94B8 802409D8 8E050018 */  lw        $a1, 0x18($s0)
/* EA94BC 802409DC 8E060028 */  lw        $a2, 0x28($s0)
/* EA94C0 802409E0 8E070020 */  lw        $a3, 0x20($s0)
/* EA94C4 802409E4 0C046AAD */  jal       func_8011AAB4
/* EA94C8 802409E8 0000202D */   daddu    $a0, $zero, $zero
/* EA94CC 802409EC AE020040 */  sw        $v0, 0x40($s0)
/* EA94D0 802409F0 2402010E */  addiu     $v0, $zero, 0x10e
/* EA94D4 802409F4 A602004C */  sh        $v0, 0x4c($s0)
.L802409F8:
/* EA94D8 802409F8 8FBF0024 */  lw        $ra, 0x24($sp)
/* EA94DC 802409FC 8FB20020 */  lw        $s2, 0x20($sp)
/* EA94E0 80240A00 8FB1001C */  lw        $s1, 0x1c($sp)
/* EA94E4 80240A04 8FB00018 */  lw        $s0, 0x18($sp)
/* EA94E8 80240A08 24020002 */  addiu     $v0, $zero, 2
/* EA94EC 80240A0C 03E00008 */  jr        $ra
/* EA94F0 80240A10 27BD0028 */   addiu    $sp, $sp, 0x28

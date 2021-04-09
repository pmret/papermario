.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkFunc27
/* 95B4E0 802402E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95B4E4 802402E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 95B4E8 802402E8 0080882D */  daddu     $s1, $a0, $zero
/* 95B4EC 802402EC AFBF001C */  sw        $ra, 0x1c($sp)
/* 95B4F0 802402F0 AFB20018 */  sw        $s2, 0x18($sp)
/* 95B4F4 802402F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 95B4F8 802402F8 8E30000C */  lw        $s0, 0xc($s1)
/* 95B4FC 802402FC 8E050000 */  lw        $a1, ($s0)
/* 95B500 80240300 0C0B1EAF */  jal       get_variable
/* 95B504 80240304 26100004 */   addiu    $s0, $s0, 4
/* 95B508 80240308 8E050000 */  lw        $a1, ($s0)
/* 95B50C 8024030C 26100004 */  addiu     $s0, $s0, 4
/* 95B510 80240310 0220202D */  daddu     $a0, $s1, $zero
/* 95B514 80240314 0C0B1EAF */  jal       get_variable
/* 95B518 80240318 0040902D */   daddu    $s2, $v0, $zero
/* 95B51C 8024031C 0220202D */  daddu     $a0, $s1, $zero
/* 95B520 80240320 8E050000 */  lw        $a1, ($s0)
/* 95B524 80240324 0C0B1EAF */  jal       get_variable
/* 95B528 80240328 0040802D */   daddu    $s0, $v0, $zero
/* 95B52C 8024032C 0040882D */  daddu     $s1, $v0, $zero
/* 95B530 80240330 2402FFFF */  addiu     $v0, $zero, -1
/* 95B534 80240334 16020005 */  bne       $s0, $v0, .L8024034C
/* 95B538 80240338 24020001 */   addiu    $v0, $zero, 1
/* 95B53C 8024033C 0C04760B */  jal       func_8011D82C
/* 95B540 80240340 0220202D */   daddu    $a0, $s1, $zero
/* 95B544 80240344 080900FB */  j         .L802403EC
/* 95B548 80240348 24020002 */   addiu    $v0, $zero, 2
.L8024034C:
/* 95B54C 8024034C 12420018 */  beq       $s2, $v0, .L802403B0
/* 95B550 80240350 2A420002 */   slti     $v0, $s2, 2
/* 95B554 80240354 10400005 */  beqz      $v0, .L8024036C
/* 95B558 80240358 24020002 */   addiu    $v0, $zero, 2
/* 95B55C 8024035C 12400007 */  beqz      $s2, .L8024037C
/* 95B560 80240360 3412FFFF */   ori      $s2, $zero, 0xffff
/* 95B564 80240364 080900FB */  j         .L802403EC
/* 95B568 80240368 00000000 */   nop
.L8024036C:
/* 95B56C 8024036C 1242001B */  beq       $s2, $v0, .L802403DC
/* 95B570 80240370 24020002 */   addiu    $v0, $zero, 2
/* 95B574 80240374 080900FB */  j         .L802403EC
/* 95B578 80240378 00000000 */   nop
.L8024037C:
/* 95B57C 8024037C 8E040000 */  lw        $a0, ($s0)
/* 95B580 80240380 1092001A */  beq       $a0, $s2, .L802403EC
/* 95B584 80240384 24020002 */   addiu    $v0, $zero, 2
/* 95B588 80240388 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 95B58C 8024038C 26100004 */   addiu    $s0, $s0, 4
/* 95B590 80240390 0C046B4C */  jal       get_model_from_list_index
/* 95B594 80240394 0040202D */   daddu    $a0, $v0, $zero
/* 95B598 80240398 0040202D */  daddu     $a0, $v0, $zero
/* 95B59C 8024039C 2405FFFF */  addiu     $a1, $zero, -1
/* 95B5A0 802403A0 0C046F1F */  jal       func_8011BC7C
/* 95B5A4 802403A4 0220302D */   daddu    $a2, $s1, $zero
/* 95B5A8 802403A8 080900DF */  j         .L8024037C
/* 95B5AC 802403AC 00000000 */   nop
.L802403B0:
/* 95B5B0 802403B0 3412FFFF */  ori       $s2, $zero, 0xffff
.L802403B4:
/* 95B5B4 802403B4 8E020000 */  lw        $v0, ($s0)
/* 95B5B8 802403B8 1052000B */  beq       $v0, $s2, .L802403E8
/* 95B5BC 802403BC 2405FFFF */   addiu    $a1, $zero, -1
/* 95B5C0 802403C0 96040002 */  lhu       $a0, 2($s0)
/* 95B5C4 802403C4 0220302D */  daddu     $a2, $s1, $zero
/* 95B5C8 802403C8 26100004 */  addiu     $s0, $s0, 4
/* 95B5CC 802403CC 0C046E54 */  jal       func_8011B950
/* 95B5D0 802403D0 0000382D */   daddu    $a3, $zero, $zero
/* 95B5D4 802403D4 080900ED */  j         .L802403B4
/* 95B5D8 802403D8 00000000 */   nop
.L802403DC:
/* 95B5DC 802403DC 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 95B5E0 802403E0 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 95B5E4 802403E4 A0510000 */  sb        $s1, ($v0)
.L802403E8:
/* 95B5E8 802403E8 24020002 */  addiu     $v0, $zero, 2
.L802403EC:
/* 95B5EC 802403EC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 95B5F0 802403F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 95B5F4 802403F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 95B5F8 802403F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 95B5FC 802403FC 03E00008 */  jr        $ra
/* 95B600 80240400 27BD0020 */   addiu    $sp, $sp, 0x20

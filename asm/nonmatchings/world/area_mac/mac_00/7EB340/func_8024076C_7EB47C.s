.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024076C_7EB47C
/* 7EB47C 8024076C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7EB480 80240770 AFB10024 */  sw        $s1, 0x24($sp)
/* 7EB484 80240774 0080882D */  daddu     $s1, $a0, $zero
/* 7EB488 80240778 3C05F840 */  lui       $a1, 0xf840
/* 7EB48C 8024077C AFBF0044 */  sw        $ra, 0x44($sp)
/* 7EB490 80240780 AFBE0040 */  sw        $fp, 0x40($sp)
/* 7EB494 80240784 AFB7003C */  sw        $s7, 0x3c($sp)
/* 7EB498 80240788 AFB60038 */  sw        $s6, 0x38($sp)
/* 7EB49C 8024078C AFB50034 */  sw        $s5, 0x34($sp)
/* 7EB4A0 80240790 AFB40030 */  sw        $s4, 0x30($sp)
/* 7EB4A4 80240794 AFB3002C */  sw        $s3, 0x2c($sp)
/* 7EB4A8 80240798 AFB20028 */  sw        $s2, 0x28($sp)
/* 7EB4AC 8024079C AFB00020 */  sw        $s0, 0x20($sp)
/* 7EB4B0 802407A0 8E3E0148 */  lw        $fp, 0x148($s1)
/* 7EB4B4 802407A4 0C0B1EAF */  jal       get_variable
/* 7EB4B8 802407A8 34A56268 */   ori      $a1, $a1, 0x6268
/* 7EB4BC 802407AC 0040802D */  daddu     $s0, $v0, $zero
/* 7EB4C0 802407B0 0220202D */  daddu     $a0, $s1, $zero
/* 7EB4C4 802407B4 3C05F840 */  lui       $a1, 0xf840
/* 7EB4C8 802407B8 0C0B1EAF */  jal       get_variable
/* 7EB4CC 802407BC 34A56269 */   ori      $a1, $a1, 0x6269
/* 7EB4D0 802407C0 0040B82D */  daddu     $s7, $v0, $zero
/* 7EB4D4 802407C4 0220202D */  daddu     $a0, $s1, $zero
/* 7EB4D8 802407C8 3C05F5DE */  lui       $a1, 0xf5de
/* 7EB4DC 802407CC 0C0B1EAF */  jal       get_variable
/* 7EB4E0 802407D0 34A502DE */   ori      $a1, $a1, 0x2de
/* 7EB4E4 802407D4 0040B02D */  daddu     $s6, $v0, $zero
/* 7EB4E8 802407D8 0220202D */  daddu     $a0, $s1, $zero
/* 7EB4EC 802407DC 3C05F5DE */  lui       $a1, 0xf5de
/* 7EB4F0 802407E0 0C0B1EAF */  jal       get_variable
/* 7EB4F4 802407E4 34A502DF */   ori      $a1, $a1, 0x2df
/* 7EB4F8 802407E8 0040A82D */  daddu     $s5, $v0, $zero
/* 7EB4FC 802407EC 93D3006D */  lbu       $s3, 0x6d($fp)
/* 7EB500 802407F0 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 7EB504 802407F4 A7B30010 */  sh        $s3, 0x10($sp)
/* 7EB508 802407F8 93D2006E */  lbu       $s2, 0x6e($fp)
/* 7EB50C 802407FC 93C7006F */  lbu       $a3, 0x6f($fp)
/* 7EB510 80240800 3274FFFF */  andi      $s4, $s3, 0xffff
/* 7EB514 80240804 12820003 */  beq       $s4, $v0, .L80240814
/* 7EB518 80240808 A7A7001E */   sh       $a3, 0x1e($sp)
/* 7EB51C 8024080C 0000B82D */  daddu     $s7, $zero, $zero
/* 7EB520 80240810 02E0802D */  daddu     $s0, $s7, $zero
.L80240814:
/* 7EB524 80240814 3202FFFF */  andi      $v0, $s0, 0xffff
/* 7EB528 80240818 14400016 */  bnez      $v0, .L80240874
/* 7EB52C 8024081C 0220202D */   daddu    $a0, $s1, $zero
/* 7EB530 80240820 0C00A67F */  jal       rand_int
/* 7EB534 80240824 24040064 */   addiu    $a0, $zero, 0x64
/* 7EB538 80240828 2842001E */  slti      $v0, $v0, 0x1e
/* 7EB53C 8024082C 10400011 */  beqz      $v0, .L80240874
/* 7EB540 80240830 0220202D */   daddu    $a0, $s1, $zero
/* 7EB544 80240834 0C00A67F */  jal       rand_int
/* 7EB548 80240838 2644FFFF */   addiu    $a0, $s2, -1
/* 7EB54C 8024083C 0040A82D */  daddu     $s5, $v0, $zero
/* 7EB550 80240840 0260B02D */  daddu     $s6, $s3, $zero
/* 7EB554 80240844 0220202D */  daddu     $a0, $s1, $zero
/* 7EB558 80240848 3C05F5DE */  lui       $a1, 0xf5de
/* 7EB55C 8024084C 34A502DE */  ori       $a1, $a1, 0x2de
/* 7EB560 80240850 0C0B2026 */  jal       set_variable
/* 7EB564 80240854 0280302D */   daddu    $a2, $s4, $zero
/* 7EB568 80240858 0220202D */  daddu     $a0, $s1, $zero
/* 7EB56C 8024085C 3C05F5DE */  lui       $a1, 0xf5de
/* 7EB570 80240860 34A502DF */  ori       $a1, $a1, 0x2df
/* 7EB574 80240864 0C0B2026 */  jal       set_variable
/* 7EB578 80240868 32A6FFFF */   andi     $a2, $s5, 0xffff
/* 7EB57C 8024086C 24100001 */  addiu     $s0, $zero, 1
/* 7EB580 80240870 0220202D */  daddu     $a0, $s1, $zero
.L80240874:
/* 7EB584 80240874 3C05F840 */  lui       $a1, 0xf840
/* 7EB588 80240878 34A56268 */  ori       $a1, $a1, 0x6268
/* 7EB58C 8024087C 0C0B2026 */  jal       set_variable
/* 7EB590 80240880 3206FFFF */   andi     $a2, $s0, 0xffff
/* 7EB594 80240884 0220202D */  daddu     $a0, $s1, $zero
/* 7EB598 80240888 3C05F840 */  lui       $a1, 0xf840
/* 7EB59C 8024088C 34A56269 */  ori       $a1, $a1, 0x6269
/* 7EB5A0 80240890 0C0B2026 */  jal       set_variable
/* 7EB5A4 80240894 32E6FFFF */   andi     $a2, $s7, 0xffff
/* 7EB5A8 80240898 0000202D */  daddu     $a0, $zero, $zero
/* 7EB5AC 8024089C 3C05F5DE */  lui       $a1, 0xf5de
/* 7EB5B0 802408A0 0C0B1EAF */  jal       get_variable
/* 7EB5B4 802408A4 34A502E0 */   ori      $a1, $a1, 0x2e0
/* 7EB5B8 802408A8 0000202D */  daddu     $a0, $zero, $zero
/* 7EB5BC 802408AC 3C05F5DE */  lui       $a1, 0xf5de
/* 7EB5C0 802408B0 34A50180 */  ori       $a1, $a1, 0x180
/* 7EB5C4 802408B4 0C0B1EAF */  jal       get_variable
/* 7EB5C8 802408B8 0040802D */   daddu    $s0, $v0, $zero
/* 7EB5CC 802408BC 0040282D */  daddu     $a1, $v0, $zero
/* 7EB5D0 802408C0 0000182D */  daddu     $v1, $zero, $zero
/* 7EB5D4 802408C4 3C068024 */  lui       $a2, %hi(D_80245E64)
/* 7EB5D8 802408C8 24C65E64 */  addiu     $a2, $a2, %lo(D_80245E64)
/* 7EB5DC 802408CC 00C0202D */  daddu     $a0, $a2, $zero
.L802408D0:
/* 7EB5E0 802408D0 8C820000 */  lw        $v0, ($a0)
/* 7EB5E4 802408D4 00A2102A */  slt       $v0, $a1, $v0
/* 7EB5E8 802408D8 14400006 */  bnez      $v0, .L802408F4
/* 7EB5EC 802408DC 000310C0 */   sll      $v0, $v1, 3
/* 7EB5F0 802408E0 24630001 */  addiu     $v1, $v1, 1
/* 7EB5F4 802408E4 28620008 */  slti      $v0, $v1, 8
/* 7EB5F8 802408E8 1440FFF9 */  bnez      $v0, .L802408D0
/* 7EB5FC 802408EC 24840008 */   addiu    $a0, $a0, 8
/* 7EB600 802408F0 000310C0 */  sll       $v0, $v1, 3
.L802408F4:
/* 7EB604 802408F4 00461021 */  addu      $v0, $v0, $a2
/* 7EB608 802408F8 8C420004 */  lw        $v0, 4($v0)
/* 7EB60C 802408FC 97A30010 */  lhu       $v1, 0x10($sp)
/* 7EB610 80240900 0202202A */  slt       $a0, $s0, $v0
/* 7EB614 80240904 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 7EB618 80240908 14620008 */  bne       $v1, $v0, .L8024092C
/* 7EB61C 8024090C 32A2FFFF */   andi     $v0, $s5, 0xffff
/* 7EB620 80240910 97A7001E */  lhu       $a3, 0x1e($sp)
/* 7EB624 80240914 14E20005 */  bne       $a3, $v0, .L8024092C
/* 7EB628 80240918 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 7EB62C 8024091C 14400003 */  bnez      $v0, .L8024092C
/* 7EB630 80240920 00000000 */   nop      
/* 7EB634 80240924 14800008 */  bnez      $a0, .L80240948
/* 7EB638 80240928 24020001 */   addiu    $v0, $zero, 1
.L8024092C:
/* 7EB63C 8024092C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7EB640 80240930 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7EB644 80240934 80420075 */  lb        $v0, 0x75($v0)
/* 7EB648 80240938 10400005 */  beqz      $v0, .L80240950
/* 7EB64C 8024093C 00000000 */   nop      
/* 7EB650 80240940 10800003 */  beqz      $a0, .L80240950
/* 7EB654 80240944 24020001 */   addiu    $v0, $zero, 1
.L80240948:
/* 7EB658 80240948 08090257 */  j         .L8024095C
/* 7EB65C 8024094C AE220084 */   sw       $v0, 0x84($s1)
.L80240950:
/* 7EB660 80240950 0C00F9EB */  jal       kill_enemy
/* 7EB664 80240954 03C0202D */   daddu    $a0, $fp, $zero
/* 7EB668 80240958 AE200084 */  sw        $zero, 0x84($s1)
.L8024095C:
/* 7EB66C 8024095C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 7EB670 80240960 8FBE0040 */  lw        $fp, 0x40($sp)
/* 7EB674 80240964 8FB7003C */  lw        $s7, 0x3c($sp)
/* 7EB678 80240968 8FB60038 */  lw        $s6, 0x38($sp)
/* 7EB67C 8024096C 8FB50034 */  lw        $s5, 0x34($sp)
/* 7EB680 80240970 8FB40030 */  lw        $s4, 0x30($sp)
/* 7EB684 80240974 8FB3002C */  lw        $s3, 0x2c($sp)
/* 7EB688 80240978 8FB20028 */  lw        $s2, 0x28($sp)
/* 7EB68C 8024097C 8FB10024 */  lw        $s1, 0x24($sp)
/* 7EB690 80240980 8FB00020 */  lw        $s0, 0x20($sp)
/* 7EB694 80240984 24020002 */  addiu     $v0, $zero, 2
/* 7EB698 80240988 03E00008 */  jr        $ra
/* 7EB69C 8024098C 27BD0048 */   addiu    $sp, $sp, 0x48

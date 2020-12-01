.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406C4_9EE2B4
/* 9EE2B4 802406C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9EE2B8 802406C8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9EE2BC 802406CC 0080982D */  daddu     $s3, $a0, $zero
/* 9EE2C0 802406D0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9EE2C4 802406D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 9EE2C8 802406D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9EE2CC 802406DC AFB00010 */  sw        $s0, 0x10($sp)
/* 9EE2D0 802406E0 8E70000C */  lw        $s0, 0xc($s3)
/* 9EE2D4 802406E4 8E050000 */  lw        $a1, ($s0)
/* 9EE2D8 802406E8 0C0B1EAF */  jal       get_variable
/* 9EE2DC 802406EC 26100004 */   addiu    $s0, $s0, 4
/* 9EE2E0 802406F0 0040882D */  daddu     $s1, $v0, $zero
/* 9EE2E4 802406F4 8E050000 */  lw        $a1, ($s0)
/* 9EE2E8 802406F8 0C0B1EAF */  jal       get_variable
/* 9EE2EC 802406FC 0260202D */   daddu    $a0, $s3, $zero
/* 9EE2F0 80240700 3C032AAA */  lui       $v1, 0x2aaa
/* 9EE2F4 80240704 3463AAAB */  ori       $v1, $v1, 0xaaab
/* 9EE2F8 80240708 02230018 */  mult      $s1, $v1
/* 9EE2FC 8024070C 001127C3 */  sra       $a0, $s1, 0x1f
/* 9EE300 80240710 0040902D */  daddu     $s2, $v0, $zero
/* 9EE304 80240714 00003810 */  mfhi      $a3
/* 9EE308 80240718 00E42023 */  subu      $a0, $a3, $a0
/* 9EE30C 8024071C 00041840 */  sll       $v1, $a0, 1
/* 9EE310 80240720 00641821 */  addu      $v1, $v1, $a0
/* 9EE314 80240724 00031840 */  sll       $v1, $v1, 1
/* 9EE318 80240728 02238823 */  subu      $s1, $s1, $v1
/* 9EE31C 8024072C 2A220004 */  slti      $v0, $s1, 4
/* 9EE320 80240730 14400004 */  bnez      $v0, .L80240744
/* 9EE324 80240734 26220006 */   addiu    $v0, $s1, 6
/* 9EE328 80240738 24020006 */  addiu     $v0, $zero, 6
/* 9EE32C 8024073C 00518823 */  subu      $s1, $v0, $s1
/* 9EE330 80240740 26220006 */  addiu     $v0, $s1, 6
.L80240744:
/* 9EE334 80240744 00021080 */  sll       $v0, $v0, 2
/* 9EE338 80240748 02628021 */  addu      $s0, $s3, $v0
/* 9EE33C 8024074C 0C0B1059 */  jal       does_script_exist
/* 9EE340 80240750 8E040084 */   lw       $a0, 0x84($s0)
/* 9EE344 80240754 10400003 */  beqz      $v0, .L80240764
/* 9EE348 80240758 00000000 */   nop      
/* 9EE34C 8024075C 0C0B102B */  jal       kill_script_by_ID
/* 9EE350 80240760 8E040084 */   lw       $a0, 0x84($s0)
.L80240764:
/* 9EE354 80240764 3C048024 */  lui       $a0, %hi(D_80241470)
/* 9EE358 80240768 24841470 */  addiu     $a0, $a0, %lo(D_80241470)
/* 9EE35C 8024076C 12400005 */  beqz      $s2, .L80240784
/* 9EE360 80240770 24020001 */   addiu    $v0, $zero, 1
/* 9EE364 80240774 16420004 */  bne       $s2, $v0, .L80240788
/* 9EE368 80240778 24050001 */   addiu    $a1, $zero, 1
/* 9EE36C 8024077C 3C048024 */  lui       $a0, %hi(D_8024161C)
/* 9EE370 80240780 2484161C */  addiu     $a0, $a0, %lo(D_8024161C)
.L80240784:
/* 9EE374 80240784 24050001 */  addiu     $a1, $zero, 1
.L80240788:
/* 9EE378 80240788 0C0B0CF8 */  jal       start_script
/* 9EE37C 8024078C 0000302D */   daddu    $a2, $zero, $zero
/* 9EE380 80240790 0040202D */  daddu     $a0, $v0, $zero
/* 9EE384 80240794 26220006 */  addiu     $v0, $s1, 6
/* 9EE388 80240798 00021080 */  sll       $v0, $v0, 2
/* 9EE38C 8024079C 8C830144 */  lw        $v1, 0x144($a0)
/* 9EE390 802407A0 02621021 */  addu      $v0, $s3, $v0
/* 9EE394 802407A4 AC430084 */  sw        $v1, 0x84($v0)
/* 9EE398 802407A8 24020001 */  addiu     $v0, $zero, 1
/* 9EE39C 802407AC 1222000D */  beq       $s1, $v0, .L802407E4
/* 9EE3A0 802407B0 2A220002 */   slti     $v0, $s1, 2
/* 9EE3A4 802407B4 10400005 */  beqz      $v0, .L802407CC
/* 9EE3A8 802407B8 24020002 */   addiu    $v0, $zero, 2
/* 9EE3AC 802407BC 1220000C */  beqz      $s1, .L802407F0
/* 9EE3B0 802407C0 2402004C */   addiu    $v0, $zero, 0x4c
/* 9EE3B4 802407C4 080901FD */  j         .L802407F4
/* 9EE3B8 802407C8 00000000 */   nop      
.L802407CC:
/* 9EE3BC 802407CC 12220007 */  beq       $s1, $v0, .L802407EC
/* 9EE3C0 802407D0 24020003 */   addiu    $v0, $zero, 3
/* 9EE3C4 802407D4 12220006 */  beq       $s1, $v0, .L802407F0
/* 9EE3C8 802407D8 2402004F */   addiu    $v0, $zero, 0x4f
/* 9EE3CC 802407DC 080901FD */  j         .L802407F4
/* 9EE3D0 802407E0 00000000 */   nop      
.L802407E4:
/* 9EE3D4 802407E4 080901FC */  j         .L802407F0
/* 9EE3D8 802407E8 2402004D */   addiu    $v0, $zero, 0x4d
.L802407EC:
/* 9EE3DC 802407EC 2402004E */  addiu     $v0, $zero, 0x4e
.L802407F0:
/* 9EE3E0 802407F0 AC820084 */  sw        $v0, 0x84($a0)
.L802407F4:
/* 9EE3E4 802407F4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9EE3E8 802407F8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9EE3EC 802407FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 9EE3F0 80240800 8FB10014 */  lw        $s1, 0x14($sp)
/* 9EE3F4 80240804 8FB00010 */  lw        $s0, 0x10($sp)
/* 9EE3F8 80240808 24020002 */  addiu     $v0, $zero, 2
/* 9EE3FC 8024080C 03E00008 */  jr        $ra
/* 9EE400 80240810 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404CC_8B053C
/* 8B053C 802404CC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8B0540 802404D0 AFB10024 */  sw        $s1, 0x24($sp)
/* 8B0544 802404D4 0080882D */  daddu     $s1, $a0, $zero
/* 8B0548 802404D8 3C05F840 */  lui       $a1, 0xf840
/* 8B054C 802404DC AFBF0044 */  sw        $ra, 0x44($sp)
/* 8B0550 802404E0 AFBE0040 */  sw        $fp, 0x40($sp)
/* 8B0554 802404E4 AFB7003C */  sw        $s7, 0x3c($sp)
/* 8B0558 802404E8 AFB60038 */  sw        $s6, 0x38($sp)
/* 8B055C 802404EC AFB50034 */  sw        $s5, 0x34($sp)
/* 8B0560 802404F0 AFB40030 */  sw        $s4, 0x30($sp)
/* 8B0564 802404F4 AFB3002C */  sw        $s3, 0x2c($sp)
/* 8B0568 802404F8 AFB20028 */  sw        $s2, 0x28($sp)
/* 8B056C 802404FC AFB00020 */  sw        $s0, 0x20($sp)
/* 8B0570 80240500 8E3E0148 */  lw        $fp, 0x148($s1)
/* 8B0574 80240504 0C0B1EAF */  jal       get_variable
/* 8B0578 80240508 34A56268 */   ori      $a1, $a1, 0x6268
/* 8B057C 8024050C 0040802D */  daddu     $s0, $v0, $zero
/* 8B0580 80240510 0220202D */  daddu     $a0, $s1, $zero
/* 8B0584 80240514 3C05F840 */  lui       $a1, 0xf840
/* 8B0588 80240518 0C0B1EAF */  jal       get_variable
/* 8B058C 8024051C 34A56269 */   ori      $a1, $a1, 0x6269
/* 8B0590 80240520 0040B82D */  daddu     $s7, $v0, $zero
/* 8B0594 80240524 0220202D */  daddu     $a0, $s1, $zero
/* 8B0598 80240528 3C05F5DE */  lui       $a1, 0xf5de
/* 8B059C 8024052C 0C0B1EAF */  jal       get_variable
/* 8B05A0 80240530 34A502DE */   ori      $a1, $a1, 0x2de
/* 8B05A4 80240534 0040B02D */  daddu     $s6, $v0, $zero
/* 8B05A8 80240538 0220202D */  daddu     $a0, $s1, $zero
/* 8B05AC 8024053C 3C05F5DE */  lui       $a1, 0xf5de
/* 8B05B0 80240540 0C0B1EAF */  jal       get_variable
/* 8B05B4 80240544 34A502DF */   ori      $a1, $a1, 0x2df
/* 8B05B8 80240548 0040A82D */  daddu     $s5, $v0, $zero
/* 8B05BC 8024054C 93D3006D */  lbu       $s3, 0x6d($fp)
/* 8B05C0 80240550 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 8B05C4 80240554 A7B30010 */  sh        $s3, 0x10($sp)
/* 8B05C8 80240558 93D2006E */  lbu       $s2, 0x6e($fp)
/* 8B05CC 8024055C 93C7006F */  lbu       $a3, 0x6f($fp)
/* 8B05D0 80240560 3274FFFF */  andi      $s4, $s3, 0xffff
/* 8B05D4 80240564 12820003 */  beq       $s4, $v0, .L80240574
/* 8B05D8 80240568 A7A7001E */   sh       $a3, 0x1e($sp)
/* 8B05DC 8024056C 0000B82D */  daddu     $s7, $zero, $zero
/* 8B05E0 80240570 02E0802D */  daddu     $s0, $s7, $zero
.L80240574:
/* 8B05E4 80240574 3202FFFF */  andi      $v0, $s0, 0xffff
/* 8B05E8 80240578 14400016 */  bnez      $v0, .L802405D4
/* 8B05EC 8024057C 0220202D */   daddu    $a0, $s1, $zero
/* 8B05F0 80240580 0C00A67F */  jal       rand_int
/* 8B05F4 80240584 24040064 */   addiu    $a0, $zero, 0x64
/* 8B05F8 80240588 2842001E */  slti      $v0, $v0, 0x1e
/* 8B05FC 8024058C 10400011 */  beqz      $v0, .L802405D4
/* 8B0600 80240590 0220202D */   daddu    $a0, $s1, $zero
/* 8B0604 80240594 0C00A67F */  jal       rand_int
/* 8B0608 80240598 2644FFFF */   addiu    $a0, $s2, -1
/* 8B060C 8024059C 0040A82D */  daddu     $s5, $v0, $zero
/* 8B0610 802405A0 0260B02D */  daddu     $s6, $s3, $zero
/* 8B0614 802405A4 0220202D */  daddu     $a0, $s1, $zero
/* 8B0618 802405A8 3C05F5DE */  lui       $a1, 0xf5de
/* 8B061C 802405AC 34A502DE */  ori       $a1, $a1, 0x2de
/* 8B0620 802405B0 0C0B2026 */  jal       set_variable
/* 8B0624 802405B4 0280302D */   daddu    $a2, $s4, $zero
/* 8B0628 802405B8 0220202D */  daddu     $a0, $s1, $zero
/* 8B062C 802405BC 3C05F5DE */  lui       $a1, 0xf5de
/* 8B0630 802405C0 34A502DF */  ori       $a1, $a1, 0x2df
/* 8B0634 802405C4 0C0B2026 */  jal       set_variable
/* 8B0638 802405C8 32A6FFFF */   andi     $a2, $s5, 0xffff
/* 8B063C 802405CC 24100001 */  addiu     $s0, $zero, 1
/* 8B0640 802405D0 0220202D */  daddu     $a0, $s1, $zero
.L802405D4:
/* 8B0644 802405D4 3C05F840 */  lui       $a1, 0xf840
/* 8B0648 802405D8 34A56268 */  ori       $a1, $a1, 0x6268
/* 8B064C 802405DC 0C0B2026 */  jal       set_variable
/* 8B0650 802405E0 3206FFFF */   andi     $a2, $s0, 0xffff
/* 8B0654 802405E4 0220202D */  daddu     $a0, $s1, $zero
/* 8B0658 802405E8 3C05F840 */  lui       $a1, 0xf840
/* 8B065C 802405EC 34A56269 */  ori       $a1, $a1, 0x6269
/* 8B0660 802405F0 0C0B2026 */  jal       set_variable
/* 8B0664 802405F4 32E6FFFF */   andi     $a2, $s7, 0xffff
/* 8B0668 802405F8 0000202D */  daddu     $a0, $zero, $zero
/* 8B066C 802405FC 3C05F5DE */  lui       $a1, 0xf5de
/* 8B0670 80240600 0C0B1EAF */  jal       get_variable
/* 8B0674 80240604 34A502E0 */   ori      $a1, $a1, 0x2e0
/* 8B0678 80240608 0000202D */  daddu     $a0, $zero, $zero
/* 8B067C 8024060C 3C05F5DE */  lui       $a1, 0xf5de
/* 8B0680 80240610 34A50180 */  ori       $a1, $a1, 0x180
/* 8B0684 80240614 0C0B1EAF */  jal       get_variable
/* 8B0688 80240618 0040802D */   daddu    $s0, $v0, $zero
/* 8B068C 8024061C 0040282D */  daddu     $a1, $v0, $zero
/* 8B0690 80240620 0000182D */  daddu     $v1, $zero, $zero
/* 8B0694 80240624 3C068024 */  lui       $a2, %hi(D_80245674)
/* 8B0698 80240628 24C65674 */  addiu     $a2, $a2, %lo(D_80245674)
/* 8B069C 8024062C 00C0202D */  daddu     $a0, $a2, $zero
.L80240630:
/* 8B06A0 80240630 8C820000 */  lw        $v0, ($a0)
/* 8B06A4 80240634 00A2102A */  slt       $v0, $a1, $v0
/* 8B06A8 80240638 14400006 */  bnez      $v0, .L80240654
/* 8B06AC 8024063C 000310C0 */   sll      $v0, $v1, 3
/* 8B06B0 80240640 24630001 */  addiu     $v1, $v1, 1
/* 8B06B4 80240644 28620008 */  slti      $v0, $v1, 8
/* 8B06B8 80240648 1440FFF9 */  bnez      $v0, .L80240630
/* 8B06BC 8024064C 24840008 */   addiu    $a0, $a0, 8
/* 8B06C0 80240650 000310C0 */  sll       $v0, $v1, 3
.L80240654:
/* 8B06C4 80240654 00461021 */  addu      $v0, $v0, $a2
/* 8B06C8 80240658 8C420004 */  lw        $v0, 4($v0)
/* 8B06CC 8024065C 97A30010 */  lhu       $v1, 0x10($sp)
/* 8B06D0 80240660 0202202A */  slt       $a0, $s0, $v0
/* 8B06D4 80240664 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 8B06D8 80240668 14620008 */  bne       $v1, $v0, .L8024068C
/* 8B06DC 8024066C 32A2FFFF */   andi     $v0, $s5, 0xffff
/* 8B06E0 80240670 97A7001E */  lhu       $a3, 0x1e($sp)
/* 8B06E4 80240674 14E20005 */  bne       $a3, $v0, .L8024068C
/* 8B06E8 80240678 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 8B06EC 8024067C 14400003 */  bnez      $v0, .L8024068C
/* 8B06F0 80240680 00000000 */   nop      
/* 8B06F4 80240684 14800008 */  bnez      $a0, .L802406A8
/* 8B06F8 80240688 24020001 */   addiu    $v0, $zero, 1
.L8024068C:
/* 8B06FC 8024068C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8B0700 80240690 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8B0704 80240694 80420075 */  lb        $v0, 0x75($v0)
/* 8B0708 80240698 10400005 */  beqz      $v0, .L802406B0
/* 8B070C 8024069C 00000000 */   nop      
/* 8B0710 802406A0 10800003 */  beqz      $a0, .L802406B0
/* 8B0714 802406A4 24020001 */   addiu    $v0, $zero, 1
.L802406A8:
/* 8B0718 802406A8 080901AF */  j         .L802406BC
/* 8B071C 802406AC AE220084 */   sw       $v0, 0x84($s1)
.L802406B0:
/* 8B0720 802406B0 0C00F9EB */  jal       kill_enemy
/* 8B0724 802406B4 03C0202D */   daddu    $a0, $fp, $zero
/* 8B0728 802406B8 AE200084 */  sw        $zero, 0x84($s1)
.L802406BC:
/* 8B072C 802406BC 8FBF0044 */  lw        $ra, 0x44($sp)
/* 8B0730 802406C0 8FBE0040 */  lw        $fp, 0x40($sp)
/* 8B0734 802406C4 8FB7003C */  lw        $s7, 0x3c($sp)
/* 8B0738 802406C8 8FB60038 */  lw        $s6, 0x38($sp)
/* 8B073C 802406CC 8FB50034 */  lw        $s5, 0x34($sp)
/* 8B0740 802406D0 8FB40030 */  lw        $s4, 0x30($sp)
/* 8B0744 802406D4 8FB3002C */  lw        $s3, 0x2c($sp)
/* 8B0748 802406D8 8FB20028 */  lw        $s2, 0x28($sp)
/* 8B074C 802406DC 8FB10024 */  lw        $s1, 0x24($sp)
/* 8B0750 802406E0 8FB00020 */  lw        $s0, 0x20($sp)
/* 8B0754 802406E4 24020002 */  addiu     $v0, $zero, 2
/* 8B0758 802406E8 03E00008 */  jr        $ra
/* 8B075C 802406EC 27BD0048 */   addiu    $sp, $sp, 0x48

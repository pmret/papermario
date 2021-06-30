.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel spr_free_sprite
/* 1016D8 802DE5E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1016DC 802DE5EC AFB20018 */  sw        $s2, 0x18($sp)
/* 1016E0 802DE5F0 0080902D */  daddu     $s2, $a0, $zero
/* 1016E4 802DE5F4 3C03802E */  lui       $v1, %hi(D_802DFA48)
/* 1016E8 802DE5F8 2463FA48 */  addiu     $v1, $v1, %lo(D_802DFA48)
/* 1016EC 802DE5FC 00121080 */  sll       $v0, $s2, 2
/* 1016F0 802DE600 00521021 */  addu      $v0, $v0, $s2
/* 1016F4 802DE604 00021080 */  sll       $v0, $v0, 2
/* 1016F8 802DE608 00432821 */  addu      $a1, $v0, $v1
/* 1016FC 802DE60C AFBF0024 */  sw        $ra, 0x24($sp)
/* 101700 802DE610 AFB40020 */  sw        $s4, 0x20($sp)
/* 101704 802DE614 AFB3001C */  sw        $s3, 0x1c($sp)
/* 101708 802DE618 AFB10014 */  sw        $s1, 0x14($sp)
/* 10170C 802DE61C AFB00010 */  sw        $s0, 0x10($sp)
/* 101710 802DE620 8CB10000 */  lw        $s1, ($a1)
/* 101714 802DE624 12200003 */  beqz      $s1, .L802DE634
/* 101718 802DE628 2A2200EA */   slti     $v0, $s1, 0xea
/* 10171C 802DE62C 14400003 */  bnez      $v0, .L802DE63C
/* 101720 802DE630 00000000 */   nop
.L802DE634:
/* 101724 802DE634 080B79CA */  j         .L802DE728
/* 101728 802DE638 0240102D */   daddu    $v0, $s2, $zero
.L802DE63C:
/* 10172C 802DE63C 3C03802E */  lui       $v1, %hi(spr_npcSpriteInstanceCount)
/* 101730 802DE640 2463F958 */  addiu     $v1, $v1, %lo(spr_npcSpriteInstanceCount)
/* 101734 802DE644 02231821 */  addu      $v1, $s1, $v1
/* 101738 802DE648 90620000 */  lbu       $v0, ($v1)
/* 10173C 802DE64C 2442FFFF */  addiu     $v0, $v0, -1
/* 101740 802DE650 A0620000 */  sb        $v0, ($v1)
/* 101744 802DE654 8CB00004 */  lw        $s0, 4($a1)
/* 101748 802DE658 2403FFFF */  addiu     $v1, $zero, -1
/* 10174C 802DE65C 8E020000 */  lw        $v0, ($s0)
/* 101750 802DE660 8CB40008 */  lw        $s4, 8($a1)
/* 101754 802DE664 10430009 */  beq       $v0, $v1, .L802DE68C
/* 101758 802DE668 00121080 */   sll      $v0, $s2, 2
/* 10175C 802DE66C 0060982D */  daddu     $s3, $v1, $zero
.L802DE670:
/* 101760 802DE670 8E020000 */  lw        $v0, ($s0)
/* 101764 802DE674 9044004F */  lbu       $a0, 0x4f($v0)
/* 101768 802DE678 0C04EA15 */  jal       func_8013A854
/* 10176C 802DE67C 26100004 */   addiu    $s0, $s0, 4
/* 101770 802DE680 8E020000 */  lw        $v0, ($s0)
/* 101774 802DE684 1453FFFA */  bne       $v0, $s3, .L802DE670
/* 101778 802DE688 00121080 */   sll      $v0, $s2, 2
.L802DE68C:
/* 10177C 802DE68C 00521021 */  addu      $v0, $v0, $s2
/* 101780 802DE690 00021080 */  sll       $v0, $v0, 2
/* 101784 802DE694 3C03802E */  lui       $v1, %hi(spr_npcSpriteInstanceCount)
/* 101788 802DE698 00711821 */  addu      $v1, $v1, $s1
/* 10178C 802DE69C 9063F958 */  lbu       $v1, %lo(spr_npcSpriteInstanceCount)($v1)
/* 101790 802DE6A0 3C10802E */  lui       $s0, %hi(D_802DFA4C)
/* 101794 802DE6A4 02028021 */  addu      $s0, $s0, $v0
/* 101798 802DE6A8 8E10FA4C */  lw        $s0, %lo(D_802DFA4C)($s0)
/* 10179C 802DE6AC 14600008 */  bnez      $v1, .L802DE6D0
/* 1017A0 802DE6B0 00111080 */   sll      $v0, $s1, 2
/* 1017A4 802DE6B4 3C01802E */  lui       $at, %hi(spr_npcSprites)
/* 1017A8 802DE6B8 00220821 */  addu      $at, $at, $v0
/* 1017AC 802DE6BC AC20F5B0 */  sw        $zero, %lo(spr_npcSprites)($at)
/* 1017B0 802DE6C0 3C048035 */  lui       $a0, %hi(gSpriteHeapPtr)
/* 1017B4 802DE6C4 2484F800 */  addiu     $a0, $a0, %lo(gSpriteHeapPtr)
/* 1017B8 802DE6C8 0C00A487 */  jal       _heap_free
/* 1017BC 802DE6CC 0280282D */   daddu    $a1, $s4, $zero
.L802DE6D0:
/* 1017C0 802DE6D0 3C02802E */  lui       $v0, %hi(spr_allocateBtlComponentsOnWorldHeap)
/* 1017C4 802DE6D4 8C42F524 */  lw        $v0, %lo(spr_allocateBtlComponentsOnWorldHeap)($v0)
/* 1017C8 802DE6D8 3C048035 */  lui       $a0, %hi(gSpriteHeapPtr)
/* 1017CC 802DE6DC 2484F800 */  addiu     $a0, $a0, %lo(gSpriteHeapPtr)
/* 1017D0 802DE6E0 10400003 */  beqz      $v0, .L802DE6F0
/* 1017D4 802DE6E4 00000000 */   nop
/* 1017D8 802DE6E8 3C048030 */  lui       $a0, %hi(D_802FB800)
/* 1017DC 802DE6EC 2484B800 */  addiu     $a0, $a0, %lo(D_802FB800)
.L802DE6F0:
/* 1017E0 802DE6F0 0C00A487 */  jal       _heap_free
/* 1017E4 802DE6F4 0200282D */   daddu    $a1, $s0, $zero
/* 1017E8 802DE6F8 0000102D */  daddu     $v0, $zero, $zero
/* 1017EC 802DE6FC 3C03802E */  lui       $v1, %hi(D_802DFA48)
/* 1017F0 802DE700 2463FA48 */  addiu     $v1, $v1, %lo(D_802DFA48)
/* 1017F4 802DE704 00122080 */  sll       $a0, $s2, 2
/* 1017F8 802DE708 00922021 */  addu      $a0, $a0, $s2
/* 1017FC 802DE70C 00042080 */  sll       $a0, $a0, 2
/* 101800 802DE710 00832021 */  addu      $a0, $a0, $v1
/* 101804 802DE714 2403FFFF */  addiu     $v1, $zero, -1
/* 101808 802DE718 AC800000 */  sw        $zero, ($a0)
/* 10180C 802DE71C AC800004 */  sw        $zero, 4($a0)
/* 101810 802DE720 AC800008 */  sw        $zero, 8($a0)
/* 101814 802DE724 AC83000C */  sw        $v1, 0xc($a0)
.L802DE728:
/* 101818 802DE728 8FBF0024 */  lw        $ra, 0x24($sp)
/* 10181C 802DE72C 8FB40020 */  lw        $s4, 0x20($sp)
/* 101820 802DE730 8FB3001C */  lw        $s3, 0x1c($sp)
/* 101824 802DE734 8FB20018 */  lw        $s2, 0x18($sp)
/* 101828 802DE738 8FB10014 */  lw        $s1, 0x14($sp)
/* 10182C 802DE73C 8FB00010 */  lw        $s0, 0x10($sp)
/* 101830 802DE740 03E00008 */  jr        $ra
/* 101834 802DE744 27BD0028 */   addiu    $sp, $sp, 0x28

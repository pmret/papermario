.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_cleanup
/* 137A48 80244708 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 137A4C 8024470C AFB00010 */  sw        $s0, 0x10($sp)
/* 137A50 80244710 0000802D */  daddu     $s0, $zero, $zero
/* 137A54 80244714 AFB10014 */  sw        $s1, 0x14($sp)
/* 137A58 80244718 3C118027 */  lui       $s1, %hi(gPauseMenuCommonIconIDs)
/* 137A5C 8024471C 263100E8 */  addiu     $s1, $s1, %lo(gPauseMenuCommonIconIDs)
/* 137A60 80244720 AFBF0018 */  sw        $ra, 0x18($sp)
.L80244724:
/* 137A64 80244724 8E240000 */  lw        $a0, ($s1)
/* 137A68 80244728 26310004 */  addiu     $s1, $s1, 4
/* 137A6C 8024472C 0C05123D */  jal       free_icon
/* 137A70 80244730 26100001 */   addiu    $s0, $s0, 1
/* 137A74 80244734 2A020008 */  slti      $v0, $s0, 8
/* 137A78 80244738 1440FFFA */  bnez      $v0, .L80244724
/* 137A7C 8024473C 0000202D */   daddu    $a0, $zero, $zero
/* 137A80 80244740 3C05F840 */  lui       $a1, 0xf840
/* 137A84 80244744 0C0B1EAF */  jal       get_variable
/* 137A88 80244748 34A55BDE */   ori      $a1, $a1, 0x5bde
/* 137A8C 8024474C 1040000A */  beqz      $v0, .L80244778
/* 137A90 80244750 0000802D */   daddu    $s0, $zero, $zero
/* 137A94 80244754 3C118027 */  lui       $s1, %hi(D_8027011C)
/* 137A98 80244758 2631011C */  addiu     $s1, $s1, %lo(D_8027011C)
.L8024475C:
/* 137A9C 8024475C 8E240000 */  lw        $a0, ($s1)
/* 137AA0 80244760 26310004 */  addiu     $s1, $s1, 4
/* 137AA4 80244764 0C0B797A */  jal       func_802DE5E8
/* 137AA8 80244768 26100001 */   addiu    $s0, $s0, 1
/* 137AAC 8024476C 2A020003 */  slti      $v0, $s0, 3
/* 137AB0 80244770 1440FFFA */  bnez      $v0, .L8024475C
/* 137AB4 80244774 00000000 */   nop
.L80244778:
/* 137AB8 80244778 3C118025 */  lui       $s1, %hi(D_8024EF80)
/* 137ABC 8024477C 2631EF80 */  addiu     $s1, $s1, %lo(D_8024EF80)
/* 137AC0 80244780 0000802D */  daddu     $s0, $zero, $zero
.L80244784:
/* 137AC4 80244784 8E240000 */  lw        $a0, ($s1)
/* 137AC8 80244788 90820000 */  lbu       $v0, ($a0)
/* 137ACC 8024478C 10400006 */  beqz      $v0, .L802447A8
/* 137AD0 80244790 26100001 */   addiu    $s0, $s0, 1
/* 137AD4 80244794 8C820018 */  lw        $v0, 0x18($a0)
/* 137AD8 80244798 10400003 */  beqz      $v0, .L802447A8
/* 137ADC 8024479C 00000000 */   nop
/* 137AE0 802447A0 0040F809 */  jalr      $v0
/* 137AE4 802447A4 00000000 */   nop
.L802447A8:
/* 137AE8 802447A8 2A020007 */  slti      $v0, $s0, 7
/* 137AEC 802447AC 1440FFF5 */  bnez      $v0, .L80244784
/* 137AF0 802447B0 26310004 */   addiu    $s1, $s1, 4
/* 137AF4 802447B4 24100016 */  addiu     $s0, $zero, 0x16
/* 137AF8 802447B8 0200202D */  daddu     $a0, $s0, $zero
.L802447BC:
/* 137AFC 802447BC 0C051F9F */  jal       set_window_update
/* 137B00 802447C0 24050002 */   addiu    $a1, $zero, 2
/* 137B04 802447C4 26100001 */  addiu     $s0, $s0, 1
/* 137B08 802447C8 2A02002C */  slti      $v0, $s0, 0x2c
/* 137B0C 802447CC 1440FFFB */  bnez      $v0, .L802447BC
/* 137B10 802447D0 0200202D */   daddu    $a0, $s0, $zero
/* 137B14 802447D4 2404002C */  addiu     $a0, $zero, 0x2c
/* 137B18 802447D8 0C051F9F */  jal       set_window_update
/* 137B1C 802447DC 24050002 */   addiu    $a1, $zero, 2
/* 137B20 802447E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 137B24 802447E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 137B28 802447E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 137B2C 802447EC 03E00008 */  jr        $ra
/* 137B30 802447F0 27BD0020 */   addiu    $sp, $sp, 0x20

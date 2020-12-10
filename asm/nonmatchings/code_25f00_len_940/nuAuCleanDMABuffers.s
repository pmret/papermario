.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuAuCleanDMABuffers
/* 26668 8004B268 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2666C 8004B26C 3C02800A */  lui       $v0, %hi(nuAuDmaState)
/* 26670 8004B270 24423BD0 */  addiu     $v0, $v0, %lo(nuAuDmaState)
/* 26674 8004B274 AFBF001C */  sw        $ra, 0x1c($sp)
/* 26678 8004B278 AFB20018 */  sw        $s2, 0x18($sp)
/* 2667C 8004B27C AFB10014 */  sw        $s1, 0x14($sp)
/* 26680 8004B280 AFB00010 */  sw        $s0, 0x10($sp)
/* 26684 8004B284 8C500004 */  lw        $s0, 4($v0)
/* 26688 8004B288 1200001A */  beqz      $s0, .L8004B2F4
/* 2668C 8004B28C 0040902D */   daddu    $s2, $v0, $zero
.L8004B290:
/* 26690 8004B290 8E02000C */  lw        $v0, 0xc($s0)
/* 26694 8004B294 3C038008 */  lui       $v1, %hi(D_8007817C)
/* 26698 8004B298 8C63817C */  lw        $v1, %lo(D_8007817C)($v1)
/* 2669C 8004B29C 8E110000 */  lw        $s1, ($s0)
/* 266A0 8004B2A0 24420001 */  addiu     $v0, $v0, 1
/* 266A4 8004B2A4 0043102B */  sltu      $v0, $v0, $v1
/* 266A8 8004B2A8 50400010 */  beql      $v0, $zero, .L8004B2EC
/* 266AC 8004B2AC 0220802D */   daddu    $s0, $s1, $zero
/* 266B0 8004B2B0 8E420004 */  lw        $v0, 4($s2)
/* 266B4 8004B2B4 50500001 */  beql      $v0, $s0, .L8004B2BC
/* 266B8 8004B2B8 AE510004 */   sw       $s1, 4($s2)
.L8004B2BC:
/* 266BC 8004B2BC 0C012D03 */  jal       alUnlink
/* 266C0 8004B2C0 0200202D */   daddu    $a0, $s0, $zero
/* 266C4 8004B2C4 8E450008 */  lw        $a1, 8($s2)
/* 266C8 8004B2C8 50A00005 */  beql      $a1, $zero, .L8004B2E0
/* 266CC 8004B2CC AE500008 */   sw       $s0, 8($s2)
/* 266D0 8004B2D0 0C012CFB */  jal       alLink
/* 266D4 8004B2D4 0200202D */   daddu    $a0, $s0, $zero
/* 266D8 8004B2D8 08012CBB */  j         .L8004B2EC
/* 266DC 8004B2DC 0220802D */   daddu    $s0, $s1, $zero
.L8004B2E0:
/* 266E0 8004B2E0 AE000000 */  sw        $zero, ($s0)
/* 266E4 8004B2E4 AE000004 */  sw        $zero, 4($s0)
/* 266E8 8004B2E8 0220802D */  daddu     $s0, $s1, $zero
.L8004B2EC:
/* 266EC 8004B2EC 1600FFE8 */  bnez      $s0, .L8004B290
/* 266F0 8004B2F0 00000000 */   nop
.L8004B2F4:
/* 266F4 8004B2F4 3C038008 */  lui       $v1, %hi(D_8007817C)
/* 266F8 8004B2F8 2463817C */  addiu     $v1, $v1, %lo(D_8007817C)
/* 266FC 8004B2FC 8C620000 */  lw        $v0, ($v1)
/* 26700 8004B300 3C018008 */  lui       $at, %hi(nuAuDmaNext)
/* 26704 8004B304 AC208178 */  sw        $zero, %lo(nuAuDmaNext)($at)
/* 26708 8004B308 24420001 */  addiu     $v0, $v0, 1
/* 2670C 8004B30C AC620000 */  sw        $v0, ($v1)
/* 26710 8004B310 8FBF001C */  lw        $ra, 0x1c($sp)
/* 26714 8004B314 8FB20018 */  lw        $s2, 0x18($sp)
/* 26718 8004B318 8FB10014 */  lw        $s1, 0x14($sp)
/* 2671C 8004B31C 8FB00010 */  lw        $s0, 0x10($sp)
/* 26720 8004B320 03E00008 */  jr        $ra
/* 26724 8004B324 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_944AA0
/* 944AA0 80240040 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 944AA4 80240044 AFB3001C */  sw        $s3, 0x1c($sp)
/* 944AA8 80240048 0080982D */  daddu     $s3, $a0, $zero
/* 944AAC 8024004C AFBF0024 */  sw        $ra, 0x24($sp)
/* 944AB0 80240050 AFB40020 */  sw        $s4, 0x20($sp)
/* 944AB4 80240054 AFB20018 */  sw        $s2, 0x18($sp)
/* 944AB8 80240058 AFB10014 */  sw        $s1, 0x14($sp)
/* 944ABC 8024005C AFB00010 */  sw        $s0, 0x10($sp)
/* 944AC0 80240060 8E70000C */  lw        $s0, 0xc($s3)
/* 944AC4 80240064 50A0001D */  beql      $a1, $zero, .L802400DC
/* 944AC8 80240068 0260202D */   daddu    $a0, $s3, $zero
/* 944ACC 8024006C 8E050000 */  lw        $a1, ($s0)
/* 944AD0 80240070 0C0B1EAF */  jal       get_variable
/* 944AD4 80240074 26100004 */   addiu    $s0, $s0, 4
/* 944AD8 80240078 8E050000 */  lw        $a1, ($s0)
/* 944ADC 8024007C 26100004 */  addiu     $s0, $s0, 4
/* 944AE0 80240080 0260202D */  daddu     $a0, $s3, $zero
/* 944AE4 80240084 0C0B1EAF */  jal       get_variable
/* 944AE8 80240088 0040882D */   daddu    $s1, $v0, $zero
/* 944AEC 8024008C 0040A02D */  daddu     $s4, $v0, $zero
/* 944AF0 80240090 2402FFFF */  addiu     $v0, $zero, -1
/* 944AF4 80240094 8E120000 */  lw        $s2, ($s0)
/* 944AF8 80240098 16220004 */  bne       $s1, $v0, .L802400AC
/* 944AFC 8024009C 3C02EFE8 */   lui      $v0, 0xefe8
/* 944B00 802400A0 8E64014C */  lw        $a0, 0x14c($s3)
/* 944B04 802400A4 08090030 */  j         .L802400C0
/* 944B08 802400A8 00000000 */   nop      
.L802400AC:
/* 944B0C 802400AC 34422080 */  ori       $v0, $v0, 0x2080
/* 944B10 802400B0 0222102A */  slt       $v0, $s1, $v0
/* 944B14 802400B4 14400005 */  bnez      $v0, .L802400CC
/* 944B18 802400B8 0220802D */   daddu    $s0, $s1, $zero
/* 944B1C 802400BC 0220202D */  daddu     $a0, $s1, $zero
.L802400C0:
/* 944B20 802400C0 0C00EABB */  jal       get_npc_unsafe
/* 944B24 802400C4 00000000 */   nop      
/* 944B28 802400C8 0040802D */  daddu     $s0, $v0, $zero
.L802400CC:
/* 944B2C 802400CC AE700070 */  sw        $s0, 0x70($s3)
/* 944B30 802400D0 AE740074 */  sw        $s4, 0x74($s3)
/* 944B34 802400D4 AE720078 */  sw        $s2, 0x78($s3)
/* 944B38 802400D8 0260202D */  daddu     $a0, $s3, $zero
.L802400DC:
/* 944B3C 802400DC 8C900070 */  lw        $s0, 0x70($a0)
/* 944B40 802400E0 8C850078 */  lw        $a1, 0x78($a0)
/* 944B44 802400E4 0C0B1EAF */  jal       get_variable
/* 944B48 802400E8 8C940074 */   lw       $s4, 0x74($a0)
/* 944B4C 802400EC 1040000C */  beqz      $v0, .L80240120
/* 944B50 802400F0 24020002 */   addiu    $v0, $zero, 2
/* 944B54 802400F4 C602003C */  lwc1      $f2, 0x3c($s0)
/* 944B58 802400F8 3C0141F0 */  lui       $at, 0x41f0
/* 944B5C 802400FC 44810000 */  mtc1      $at, $f0
/* 944B60 80240100 00000000 */  nop       
/* 944B64 80240104 46001080 */  add.s     $f2, $f2, $f0
/* 944B68 80240108 8E050038 */  lw        $a1, 0x38($s0)
/* 944B6C 8024010C 8E070040 */  lw        $a3, 0x40($s0)
/* 944B70 80240110 44061000 */  mfc1      $a2, $f2
/* 944B74 80240114 0C04D083 */  jal       set_item_entity_position
/* 944B78 80240118 0280202D */   daddu    $a0, $s4, $zero
/* 944B7C 8024011C 0000102D */  daddu     $v0, $zero, $zero
.L80240120:
/* 944B80 80240120 8FBF0024 */  lw        $ra, 0x24($sp)
/* 944B84 80240124 8FB40020 */  lw        $s4, 0x20($sp)
/* 944B88 80240128 8FB3001C */  lw        $s3, 0x1c($sp)
/* 944B8C 8024012C 8FB20018 */  lw        $s2, 0x18($sp)
/* 944B90 80240130 8FB10014 */  lw        $s1, 0x14($sp)
/* 944B94 80240134 8FB00010 */  lw        $s0, 0x10($sp)
/* 944B98 80240138 03E00008 */  jr        $ra
/* 944B9C 8024013C 27BD0028 */   addiu    $sp, $sp, 0x28

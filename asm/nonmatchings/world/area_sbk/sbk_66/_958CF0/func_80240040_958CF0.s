.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_958CF0
/* 958CF0 80240040 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 958CF4 80240044 AFB3001C */  sw        $s3, 0x1c($sp)
/* 958CF8 80240048 0080982D */  daddu     $s3, $a0, $zero
/* 958CFC 8024004C AFBF0024 */  sw        $ra, 0x24($sp)
/* 958D00 80240050 AFB40020 */  sw        $s4, 0x20($sp)
/* 958D04 80240054 AFB20018 */  sw        $s2, 0x18($sp)
/* 958D08 80240058 AFB10014 */  sw        $s1, 0x14($sp)
/* 958D0C 8024005C AFB00010 */  sw        $s0, 0x10($sp)
/* 958D10 80240060 8E70000C */  lw        $s0, 0xc($s3)
/* 958D14 80240064 50A0001D */  beql      $a1, $zero, .L802400DC
/* 958D18 80240068 0260202D */   daddu    $a0, $s3, $zero
/* 958D1C 8024006C 8E050000 */  lw        $a1, ($s0)
/* 958D20 80240070 0C0B1EAF */  jal       get_variable
/* 958D24 80240074 26100004 */   addiu    $s0, $s0, 4
/* 958D28 80240078 8E050000 */  lw        $a1, ($s0)
/* 958D2C 8024007C 26100004 */  addiu     $s0, $s0, 4
/* 958D30 80240080 0260202D */  daddu     $a0, $s3, $zero
/* 958D34 80240084 0C0B1EAF */  jal       get_variable
/* 958D38 80240088 0040882D */   daddu    $s1, $v0, $zero
/* 958D3C 8024008C 0040A02D */  daddu     $s4, $v0, $zero
/* 958D40 80240090 2402FFFF */  addiu     $v0, $zero, -1
/* 958D44 80240094 8E120000 */  lw        $s2, ($s0)
/* 958D48 80240098 16220004 */  bne       $s1, $v0, .L802400AC
/* 958D4C 8024009C 3C02EFE8 */   lui      $v0, 0xefe8
/* 958D50 802400A0 8E64014C */  lw        $a0, 0x14c($s3)
/* 958D54 802400A4 08090030 */  j         .L802400C0
/* 958D58 802400A8 00000000 */   nop      
.L802400AC:
/* 958D5C 802400AC 34422080 */  ori       $v0, $v0, 0x2080
/* 958D60 802400B0 0222102A */  slt       $v0, $s1, $v0
/* 958D64 802400B4 14400005 */  bnez      $v0, .L802400CC
/* 958D68 802400B8 0220802D */   daddu    $s0, $s1, $zero
/* 958D6C 802400BC 0220202D */  daddu     $a0, $s1, $zero
.L802400C0:
/* 958D70 802400C0 0C00EABB */  jal       get_npc_unsafe
/* 958D74 802400C4 00000000 */   nop      
/* 958D78 802400C8 0040802D */  daddu     $s0, $v0, $zero
.L802400CC:
/* 958D7C 802400CC AE700070 */  sw        $s0, 0x70($s3)
/* 958D80 802400D0 AE740074 */  sw        $s4, 0x74($s3)
/* 958D84 802400D4 AE720078 */  sw        $s2, 0x78($s3)
/* 958D88 802400D8 0260202D */  daddu     $a0, $s3, $zero
.L802400DC:
/* 958D8C 802400DC 8C900070 */  lw        $s0, 0x70($a0)
/* 958D90 802400E0 8C850078 */  lw        $a1, 0x78($a0)
/* 958D94 802400E4 0C0B1EAF */  jal       get_variable
/* 958D98 802400E8 8C940074 */   lw       $s4, 0x74($a0)
/* 958D9C 802400EC 1040000C */  beqz      $v0, .L80240120
/* 958DA0 802400F0 24020002 */   addiu    $v0, $zero, 2
/* 958DA4 802400F4 C602003C */  lwc1      $f2, 0x3c($s0)
/* 958DA8 802400F8 3C0141F0 */  lui       $at, 0x41f0
/* 958DAC 802400FC 44810000 */  mtc1      $at, $f0
/* 958DB0 80240100 00000000 */  nop       
/* 958DB4 80240104 46001080 */  add.s     $f2, $f2, $f0
/* 958DB8 80240108 8E050038 */  lw        $a1, 0x38($s0)
/* 958DBC 8024010C 8E070040 */  lw        $a3, 0x40($s0)
/* 958DC0 80240110 44061000 */  mfc1      $a2, $f2
/* 958DC4 80240114 0C04D083 */  jal       set_item_entity_position
/* 958DC8 80240118 0280202D */   daddu    $a0, $s4, $zero
/* 958DCC 8024011C 0000102D */  daddu     $v0, $zero, $zero
.L80240120:
/* 958DD0 80240120 8FBF0024 */  lw        $ra, 0x24($sp)
/* 958DD4 80240124 8FB40020 */  lw        $s4, 0x20($sp)
/* 958DD8 80240128 8FB3001C */  lw        $s3, 0x1c($sp)
/* 958DDC 8024012C 8FB20018 */  lw        $s2, 0x18($sp)
/* 958DE0 80240130 8FB10014 */  lw        $s1, 0x14($sp)
/* 958DE4 80240134 8FB00010 */  lw        $s0, 0x10($sp)
/* 958DE8 80240138 03E00008 */  jr        $ra
/* 958DEC 8024013C 27BD0028 */   addiu    $sp, $sp, 0x28

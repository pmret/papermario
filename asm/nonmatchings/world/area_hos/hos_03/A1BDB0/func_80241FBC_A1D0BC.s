.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FBC_A1D0BC
/* A1D0BC 80241FBC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A1D0C0 80241FC0 AFB40040 */  sw        $s4, 0x40($sp)
/* A1D0C4 80241FC4 0080A02D */  daddu     $s4, $a0, $zero
/* A1D0C8 80241FC8 AFBF0048 */  sw        $ra, 0x48($sp)
/* A1D0CC 80241FCC AFB50044 */  sw        $s5, 0x44($sp)
/* A1D0D0 80241FD0 AFB3003C */  sw        $s3, 0x3c($sp)
/* A1D0D4 80241FD4 AFB20038 */  sw        $s2, 0x38($sp)
/* A1D0D8 80241FD8 AFB10034 */  sw        $s1, 0x34($sp)
/* A1D0DC 80241FDC AFB00030 */  sw        $s0, 0x30($sp)
/* A1D0E0 80241FE0 8E920148 */  lw        $s2, 0x148($s4)
/* A1D0E4 80241FE4 86440008 */  lh        $a0, 8($s2)
/* A1D0E8 80241FE8 8E90000C */  lw        $s0, 0xc($s4)
/* A1D0EC 80241FEC 0C00EABB */  jal       get_npc_unsafe
/* A1D0F0 80241FF0 00A0882D */   daddu    $s1, $a1, $zero
/* A1D0F4 80241FF4 0280202D */  daddu     $a0, $s4, $zero
/* A1D0F8 80241FF8 8E050000 */  lw        $a1, ($s0)
/* A1D0FC 80241FFC 0C0B1EAF */  jal       get_variable
/* A1D100 80242000 0040A82D */   daddu    $s5, $v0, $zero
/* A1D104 80242004 AFA00010 */  sw        $zero, 0x10($sp)
/* A1D108 80242008 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A1D10C 8024200C 8C630030 */  lw        $v1, 0x30($v1)
/* A1D110 80242010 AFA30014 */  sw        $v1, 0x14($sp)
/* A1D114 80242014 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A1D118 80242018 8C63001C */  lw        $v1, 0x1c($v1)
/* A1D11C 8024201C AFA30018 */  sw        $v1, 0x18($sp)
/* A1D120 80242020 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A1D124 80242024 8C630024 */  lw        $v1, 0x24($v1)
/* A1D128 80242028 AFA3001C */  sw        $v1, 0x1c($sp)
/* A1D12C 8024202C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A1D130 80242030 8C630028 */  lw        $v1, 0x28($v1)
/* A1D134 80242034 27B30010 */  addiu     $s3, $sp, 0x10
/* A1D138 80242038 AFA30020 */  sw        $v1, 0x20($sp)
/* A1D13C 8024203C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A1D140 80242040 3C0142F0 */  lui       $at, 0x42f0
/* A1D144 80242044 44810000 */  mtc1      $at, $f0
/* A1D148 80242048 8C63002C */  lw        $v1, 0x2c($v1)
/* A1D14C 8024204C 0040802D */  daddu     $s0, $v0, $zero
/* A1D150 80242050 E7A00028 */  swc1      $f0, 0x28($sp)
/* A1D154 80242054 A7A0002C */  sh        $zero, 0x2c($sp)
/* A1D158 80242058 12200006 */  beqz      $s1, .L80242074
/* A1D15C 8024205C AFA30024 */   sw       $v1, 0x24($sp)
/* A1D160 80242060 02A0202D */  daddu     $a0, $s5, $zero
/* A1D164 80242064 0240282D */  daddu     $a1, $s2, $zero
/* A1D168 80242068 0280302D */  daddu     $a2, $s4, $zero
/* A1D16C 8024206C 0C0907A6 */  jal       func_80241E98_A1CF98
/* A1D170 80242070 0200382D */   daddu    $a3, $s0, $zero
.L80242074:
/* A1D174 80242074 2402FFFE */  addiu     $v0, $zero, -2
/* A1D178 80242078 A2A200AB */  sb        $v0, 0xab($s5)
/* A1D17C 8024207C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A1D180 80242080 30620004 */  andi      $v0, $v1, 4
/* A1D184 80242084 10400007 */  beqz      $v0, .L802420A4
/* A1D188 80242088 00000000 */   nop      
/* A1D18C 8024208C 824200B4 */  lb        $v0, 0xb4($s2)
/* A1D190 80242090 1440003C */  bnez      $v0, .L80242184
/* A1D194 80242094 0000102D */   daddu    $v0, $zero, $zero
/* A1D198 80242098 2402FFFB */  addiu     $v0, $zero, -5
/* A1D19C 8024209C 00621024 */  and       $v0, $v1, $v0
/* A1D1A0 802420A0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802420A4:
/* A1D1A4 802420A4 8E830070 */  lw        $v1, 0x70($s4)
/* A1D1A8 802420A8 2C62000F */  sltiu     $v0, $v1, 0xf
/* A1D1AC 802420AC 10400034 */  beqz      $v0, .L80242180
/* A1D1B0 802420B0 00031080 */   sll      $v0, $v1, 2
/* A1D1B4 802420B4 3C018025 */  lui       $at, 0x8025
/* A1D1B8 802420B8 00220821 */  addu      $at, $at, $v0
/* A1D1BC 802420BC 8C22BD88 */  lw        $v0, -0x4278($at)
/* A1D1C0 802420C0 00400008 */  jr        $v0
/* A1D1C4 802420C4 00000000 */   nop      
/* A1D1C8 802420C8 0280202D */  daddu     $a0, $s4, $zero
/* A1D1CC 802420CC 0200282D */  daddu     $a1, $s0, $zero
/* A1D1D0 802420D0 0C09032C */  jal       func_80240CB0_A1BDB0
/* A1D1D4 802420D4 0260302D */   daddu    $a2, $s3, $zero
/* A1D1D8 802420D8 0280202D */  daddu     $a0, $s4, $zero
/* A1D1DC 802420DC 0200282D */  daddu     $a1, $s0, $zero
/* A1D1E0 802420E0 0C090398 */  jal       func_80240E60_A1BF60
/* A1D1E4 802420E4 0260302D */   daddu    $a2, $s3, $zero
/* A1D1E8 802420E8 08090861 */  j         .L80242184
/* A1D1EC 802420EC 0000102D */   daddu    $v0, $zero, $zero
/* A1D1F0 802420F0 0280202D */  daddu     $a0, $s4, $zero
/* A1D1F4 802420F4 0200282D */  daddu     $a1, $s0, $zero
/* A1D1F8 802420F8 0C090522 */  jal       func_80241488_A1C588
/* A1D1FC 802420FC 0260302D */   daddu    $a2, $s3, $zero
/* A1D200 80242100 0280202D */  daddu     $a0, $s4, $zero
/* A1D204 80242104 0200282D */  daddu     $a1, $s0, $zero
/* A1D208 80242108 0C090552 */  jal       func_80241548_A1C648
/* A1D20C 8024210C 0260302D */   daddu    $a2, $s3, $zero
/* A1D210 80242110 08090861 */  j         .L80242184
/* A1D214 80242114 0000102D */   daddu    $v0, $zero, $zero
/* A1D218 80242118 0280202D */  daddu     $a0, $s4, $zero
/* A1D21C 8024211C 0200282D */  daddu     $a1, $s0, $zero
/* A1D220 80242120 0C090623 */  jal       func_8024188C_A1C98C
/* A1D224 80242124 0260302D */   daddu    $a2, $s3, $zero
/* A1D228 80242128 0280202D */  daddu     $a0, $s4, $zero
/* A1D22C 8024212C 0200282D */  daddu     $a1, $s0, $zero
/* A1D230 80242130 0C090641 */  jal       func_80241904_A1CA04
/* A1D234 80242134 0260302D */   daddu    $a2, $s3, $zero
/* A1D238 80242138 08090861 */  j         .L80242184
/* A1D23C 8024213C 0000102D */   daddu    $v0, $zero, $zero
/* A1D240 80242140 0280202D */  daddu     $a0, $s4, $zero
/* A1D244 80242144 0200282D */  daddu     $a1, $s0, $zero
/* A1D248 80242148 0C09065C */  jal       func_80241970_A1CA70
/* A1D24C 8024214C 0260302D */   daddu    $a2, $s3, $zero
/* A1D250 80242150 08090861 */  j         .L80242184
/* A1D254 80242154 0000102D */   daddu    $v0, $zero, $zero
/* A1D258 80242158 0280202D */  daddu     $a0, $s4, $zero
/* A1D25C 8024215C 0200282D */  daddu     $a1, $s0, $zero
/* A1D260 80242160 0C0906A9 */  jal       func_80241AA4_A1CBA4
/* A1D264 80242164 0260302D */   daddu    $a2, $s3, $zero
/* A1D268 80242168 08090861 */  j         .L80242184
/* A1D26C 8024216C 0000102D */   daddu    $v0, $zero, $zero
/* A1D270 80242170 0280202D */  daddu     $a0, $s4, $zero
/* A1D274 80242174 0200282D */  daddu     $a1, $s0, $zero
/* A1D278 80242178 0C0906C2 */  jal       func_80241B08_A1CC08
/* A1D27C 8024217C 0260302D */   daddu    $a2, $s3, $zero
.L80242180:
/* A1D280 80242180 0000102D */  daddu     $v0, $zero, $zero
.L80242184:
/* A1D284 80242184 8FBF0048 */  lw        $ra, 0x48($sp)
/* A1D288 80242188 8FB50044 */  lw        $s5, 0x44($sp)
/* A1D28C 8024218C 8FB40040 */  lw        $s4, 0x40($sp)
/* A1D290 80242190 8FB3003C */  lw        $s3, 0x3c($sp)
/* A1D294 80242194 8FB20038 */  lw        $s2, 0x38($sp)
/* A1D298 80242198 8FB10034 */  lw        $s1, 0x34($sp)
/* A1D29C 8024219C 8FB00030 */  lw        $s0, 0x30($sp)
/* A1D2A0 802421A0 03E00008 */  jr        $ra
/* A1D2A4 802421A4 27BD0050 */   addiu    $sp, $sp, 0x50

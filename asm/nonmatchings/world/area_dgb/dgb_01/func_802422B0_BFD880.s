.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422B0_BFFB30
/* BFFB30 802422B0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* BFFB34 802422B4 AFB40050 */  sw        $s4, 0x50($sp)
/* BFFB38 802422B8 0080A02D */  daddu     $s4, $a0, $zero
/* BFFB3C 802422BC AFBF0058 */  sw        $ra, 0x58($sp)
/* BFFB40 802422C0 AFB50054 */  sw        $s5, 0x54($sp)
/* BFFB44 802422C4 AFB3004C */  sw        $s3, 0x4c($sp)
/* BFFB48 802422C8 AFB20048 */  sw        $s2, 0x48($sp)
/* BFFB4C 802422CC AFB10044 */  sw        $s1, 0x44($sp)
/* BFFB50 802422D0 AFB00040 */  sw        $s0, 0x40($sp)
/* BFFB54 802422D4 8E920148 */  lw        $s2, 0x148($s4)
/* BFFB58 802422D8 86440008 */  lh        $a0, 8($s2)
/* BFFB5C 802422DC 0C00EABB */  jal       get_npc_unsafe
/* BFFB60 802422E0 00A0802D */   daddu    $s0, $a1, $zero
/* BFFB64 802422E4 8E83000C */  lw        $v1, 0xc($s4)
/* BFFB68 802422E8 0280202D */  daddu     $a0, $s4, $zero
/* BFFB6C 802422EC 8C650000 */  lw        $a1, ($v1)
/* BFFB70 802422F0 0C0B1EAF */  jal       get_variable
/* BFFB74 802422F4 0040A82D */   daddu    $s5, $v0, $zero
/* BFFB78 802422F8 AFA00020 */  sw        $zero, 0x20($sp)
/* BFFB7C 802422FC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFFB80 80242300 8C630030 */  lw        $v1, 0x30($v1)
/* BFFB84 80242304 AFA30024 */  sw        $v1, 0x24($sp)
/* BFFB88 80242308 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFFB8C 8024230C 8C63001C */  lw        $v1, 0x1c($v1)
/* BFFB90 80242310 AFA30028 */  sw        $v1, 0x28($sp)
/* BFFB94 80242314 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFFB98 80242318 8C630024 */  lw        $v1, 0x24($v1)
/* BFFB9C 8024231C AFA3002C */  sw        $v1, 0x2c($sp)
/* BFFBA0 80242320 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFFBA4 80242324 8C630028 */  lw        $v1, 0x28($v1)
/* BFFBA8 80242328 27B30020 */  addiu     $s3, $sp, 0x20
/* BFFBAC 8024232C AFA30030 */  sw        $v1, 0x30($sp)
/* BFFBB0 80242330 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFFBB4 80242334 3C0142FA */  lui       $at, 0x42fa
/* BFFBB8 80242338 44810000 */  mtc1      $at, $f0
/* BFFBBC 8024233C 8C63002C */  lw        $v1, 0x2c($v1)
/* BFFBC0 80242340 0040882D */  daddu     $s1, $v0, $zero
/* BFFBC4 80242344 E7A00038 */  swc1      $f0, 0x38($sp)
/* BFFBC8 80242348 A7A0003C */  sh        $zero, 0x3c($sp)
/* BFFBCC 8024234C 12000007 */  beqz      $s0, .L8024236C
/* BFFBD0 80242350 AFA30034 */   sw       $v1, 0x34($sp)
/* BFFBD4 80242354 AE800070 */  sw        $zero, 0x70($s4)
/* BFFBD8 80242358 02A0202D */  daddu     $a0, $s5, $zero
/* BFFBDC 8024235C 0240282D */  daddu     $a1, $s2, $zero
/* BFFBE0 80242360 0280302D */  daddu     $a2, $s4, $zero
/* BFFBE4 80242364 0C0904C2 */  jal       func_80241308
/* BFFBE8 80242368 0220382D */   daddu    $a3, $s1, $zero
.L8024236C:
/* BFFBEC 8024236C 8E830070 */  lw        $v1, 0x70($s4)
/* BFFBF0 80242370 2C620020 */  sltiu     $v0, $v1, 0x20
/* BFFBF4 80242374 10400060 */  beqz      $v0, .L802424F8
/* BFFBF8 80242378 00031080 */   sll      $v0, $v1, 2
/* BFFBFC 8024237C 3C018026 */  lui       $at, 0x8026
/* BFFC00 80242380 00220821 */  addu      $at, $at, $v0
/* BFFC04 80242384 8C223488 */  lw        $v0, 0x3488($at)
/* BFFC08 80242388 00400008 */  jr        $v0
/* BFFC0C 8024238C 00000000 */   nop      
/* BFFC10 80242390 0280202D */  daddu     $a0, $s4, $zero
/* BFFC14 80242394 0220282D */  daddu     $a1, $s1, $zero
/* BFFC18 80242398 0C090048 */  jal       func_80240120
/* BFFC1C 8024239C 0260302D */   daddu    $a2, $s3, $zero
/* BFFC20 802423A0 0000282D */  daddu     $a1, $zero, $zero
/* BFFC24 802423A4 00A0302D */  daddu     $a2, $a1, $zero
/* BFFC28 802423A8 AFA00010 */  sw        $zero, 0x10($sp)
/* BFFC2C 802423AC AFA00014 */  sw        $zero, 0x14($sp)
/* BFFC30 802423B0 AFA00018 */  sw        $zero, 0x18($sp)
/* BFFC34 802423B4 8EA40024 */  lw        $a0, 0x24($s5)
/* BFFC38 802423B8 0C0B7A25 */  jal       func_802DE894
/* BFFC3C 802423BC 00A0382D */   daddu    $a3, $a1, $zero
/* BFFC40 802423C0 0280202D */  daddu     $a0, $s4, $zero
/* BFFC44 802423C4 0220282D */  daddu     $a1, $s1, $zero
/* BFFC48 802423C8 0C0900B4 */  jal       func_802402D0
/* BFFC4C 802423CC 0260302D */   daddu    $a2, $s3, $zero
/* BFFC50 802423D0 080908FE */  j         .L802423F8
/* BFFC54 802423D4 00000000 */   nop      
/* BFFC58 802423D8 0280202D */  daddu     $a0, $s4, $zero
/* BFFC5C 802423DC 0220282D */  daddu     $a1, $s1, $zero
/* BFFC60 802423E0 0C09023E */  jal       func_802408F8
/* BFFC64 802423E4 0260302D */   daddu    $a2, $s3, $zero
/* BFFC68 802423E8 0280202D */  daddu     $a0, $s4, $zero
/* BFFC6C 802423EC 0220282D */  daddu     $a1, $s1, $zero
/* BFFC70 802423F0 0C09026E */  jal       func_802409B8
/* BFFC74 802423F4 0260302D */   daddu    $a2, $s3, $zero
.L802423F8:
/* BFFC78 802423F8 8E830070 */  lw        $v1, 0x70($s4)
/* BFFC7C 802423FC 2402000C */  addiu     $v0, $zero, 0xc
/* BFFC80 80242400 1462003D */  bne       $v1, $v0, .L802424F8
/* BFFC84 80242404 24020006 */   addiu    $v0, $zero, 6
/* BFFC88 80242408 0809093E */  j         .L802424F8
/* BFFC8C 8024240C A6A2008E */   sh       $v0, 0x8e($s5)
/* BFFC90 80242410 0280202D */  daddu     $a0, $s4, $zero
/* BFFC94 80242414 0220282D */  daddu     $a1, $s1, $zero
/* BFFC98 80242418 0C090586 */  jal       func_80241618
/* BFFC9C 8024241C 0260302D */   daddu    $a2, $s3, $zero
/* BFFCA0 80242420 8E830070 */  lw        $v1, 0x70($s4)
/* BFFCA4 80242424 2402000D */  addiu     $v0, $zero, 0xd
/* BFFCA8 80242428 14620033 */  bne       $v1, $v0, .L802424F8
/* BFFCAC 8024242C 00000000 */   nop      
/* BFFCB0 80242430 0280202D */  daddu     $a0, $s4, $zero
/* BFFCB4 80242434 0220282D */  daddu     $a1, $s1, $zero
/* BFFCB8 80242438 0C0905DC */  jal       func_80241770
/* BFFCBC 8024243C 0260302D */   daddu    $a2, $s3, $zero
/* BFFCC0 80242440 0809093E */  j         .L802424F8
/* BFFCC4 80242444 00000000 */   nop      
/* BFFCC8 80242448 0280202D */  daddu     $a0, $s4, $zero
/* BFFCCC 8024244C 0220282D */  daddu     $a1, $s1, $zero
/* BFFCD0 80242450 0C09061D */  jal       func_80241874
/* BFFCD4 80242454 0260302D */   daddu    $a2, $s3, $zero
/* BFFCD8 80242458 8E830070 */  lw        $v1, 0x70($s4)
/* BFFCDC 8024245C 2402000F */  addiu     $v0, $zero, 0xf
/* BFFCE0 80242460 14620025 */  bne       $v1, $v0, .L802424F8
/* BFFCE4 80242464 00000000 */   nop      
/* BFFCE8 80242468 0280202D */  daddu     $a0, $s4, $zero
/* BFFCEC 8024246C 0220282D */  daddu     $a1, $s1, $zero
/* BFFCF0 80242470 0C090655 */  jal       func_80241954
/* BFFCF4 80242474 0260302D */   daddu    $a2, $s3, $zero
/* BFFCF8 80242478 0809093E */  j         .L802424F8
/* BFFCFC 8024247C 00000000 */   nop      
/* BFFD00 80242480 0280202D */  daddu     $a0, $s4, $zero
/* BFFD04 80242484 0220282D */  daddu     $a1, $s1, $zero
/* BFFD08 80242488 0C0906FC */  jal       func_80241BF0
/* BFFD0C 8024248C 0260302D */   daddu    $a2, $s3, $zero
/* BFFD10 80242490 0280202D */  daddu     $a0, $s4, $zero
/* BFFD14 80242494 0220282D */  daddu     $a1, $s1, $zero
/* BFFD18 80242498 0C09072A */  jal       func_80241CA8
/* BFFD1C 8024249C 0260302D */   daddu    $a2, $s3, $zero
/* BFFD20 802424A0 0809093E */  j         .L802424F8
/* BFFD24 802424A4 00000000 */   nop      
/* BFFD28 802424A8 0280202D */  daddu     $a0, $s4, $zero
/* BFFD2C 802424AC 0220282D */  daddu     $a1, $s1, $zero
/* BFFD30 802424B0 0C09078A */  jal       func_80241E28
/* BFFD34 802424B4 0260302D */   daddu    $a2, $s3, $zero
/* BFFD38 802424B8 0809093E */  j         .L802424F8
/* BFFD3C 802424BC 00000000 */   nop      
/* BFFD40 802424C0 0280202D */  daddu     $a0, $s4, $zero
/* BFFD44 802424C4 0220282D */  daddu     $a1, $s1, $zero
/* BFFD48 802424C8 0C09079C */  jal       func_80241E70
/* BFFD4C 802424CC 0260302D */   daddu    $a2, $s3, $zero
/* BFFD50 802424D0 0809093E */  j         .L802424F8
/* BFFD54 802424D4 00000000 */   nop      
/* BFFD58 802424D8 0280202D */  daddu     $a0, $s4, $zero
/* BFFD5C 802424DC 0220282D */  daddu     $a1, $s1, $zero
/* BFFD60 802424E0 0C0907BC */  jal       func_80241EF0
/* BFFD64 802424E4 0260302D */   daddu    $a2, $s3, $zero
/* BFFD68 802424E8 0280202D */  daddu     $a0, $s4, $zero
/* BFFD6C 802424EC 0220282D */  daddu     $a1, $s1, $zero
/* BFFD70 802424F0 0C0907E6 */  jal       func_80241F98
/* BFFD74 802424F4 0260302D */   daddu    $a2, $s3, $zero
.L802424F8:
/* BFFD78 802424F8 8E820070 */  lw        $v0, 0x70($s4)
/* BFFD7C 802424FC 8FBF0058 */  lw        $ra, 0x58($sp)
/* BFFD80 80242500 8FB50054 */  lw        $s5, 0x54($sp)
/* BFFD84 80242504 8FB40050 */  lw        $s4, 0x50($sp)
/* BFFD88 80242508 8FB3004C */  lw        $s3, 0x4c($sp)
/* BFFD8C 8024250C 8FB20048 */  lw        $s2, 0x48($sp)
/* BFFD90 80242510 8FB10044 */  lw        $s1, 0x44($sp)
/* BFFD94 80242514 8FB00040 */  lw        $s0, 0x40($sp)
/* BFFD98 80242518 38420064 */  xori      $v0, $v0, 0x64
/* BFFD9C 8024251C 2C420001 */  sltiu     $v0, $v0, 1
/* BFFDA0 80242520 00021040 */  sll       $v0, $v0, 1
/* BFFDA4 80242524 03E00008 */  jr        $ra
/* BFFDA8 80242528 27BD0060 */   addiu    $sp, $sp, 0x60

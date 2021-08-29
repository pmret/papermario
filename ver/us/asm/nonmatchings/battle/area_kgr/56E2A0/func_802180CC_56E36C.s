.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180CC_56E36C
/* 56E36C 802180CC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 56E370 802180D0 AFB20018 */  sw        $s2, 0x18($sp)
/* 56E374 802180D4 0080902D */  daddu     $s2, $a0, $zero
/* 56E378 802180D8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 56E37C 802180DC AFB10014 */  sw        $s1, 0x14($sp)
/* 56E380 802180E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 56E384 802180E4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 56E388 802180E8 10A00044 */  beqz      $a1, .L802181FC
/* 56E38C 802180EC 8E50000C */   lw       $s0, 0xc($s2)
/* 56E390 802180F0 0C00AB39 */  jal       heap_malloc
/* 56E394 802180F4 24040024 */   addiu    $a0, $zero, 0x24
/* 56E398 802180F8 0040882D */  daddu     $s1, $v0, $zero
/* 56E39C 802180FC AE510070 */  sw        $s1, 0x70($s2)
/* 56E3A0 80218100 8E050000 */  lw        $a1, ($s0)
/* 56E3A4 80218104 26100004 */  addiu     $s0, $s0, 4
/* 56E3A8 80218108 0C0B1EAF */  jal       get_variable
/* 56E3AC 8021810C 0240202D */   daddu    $a0, $s2, $zero
/* 56E3B0 80218110 AE220020 */  sw        $v0, 0x20($s1)
/* 56E3B4 80218114 8E050000 */  lw        $a1, ($s0)
/* 56E3B8 80218118 26100004 */  addiu     $s0, $s0, 4
/* 56E3BC 8021811C 0C0B210B */  jal       evt_get_float_variable
/* 56E3C0 80218120 0240202D */   daddu    $a0, $s2, $zero
/* 56E3C4 80218124 E6200000 */  swc1      $f0, ($s1)
/* 56E3C8 80218128 8E050000 */  lw        $a1, ($s0)
/* 56E3CC 8021812C 26100004 */  addiu     $s0, $s0, 4
/* 56E3D0 80218130 0C0B210B */  jal       evt_get_float_variable
/* 56E3D4 80218134 0240202D */   daddu    $a0, $s2, $zero
/* 56E3D8 80218138 E6200004 */  swc1      $f0, 4($s1)
/* 56E3DC 8021813C 8E050000 */  lw        $a1, ($s0)
/* 56E3E0 80218140 26100004 */  addiu     $s0, $s0, 4
/* 56E3E4 80218144 0C0B210B */  jal       evt_get_float_variable
/* 56E3E8 80218148 0240202D */   daddu    $a0, $s2, $zero
/* 56E3EC 8021814C E6200008 */  swc1      $f0, 8($s1)
/* 56E3F0 80218150 8E050000 */  lw        $a1, ($s0)
/* 56E3F4 80218154 26100004 */  addiu     $s0, $s0, 4
/* 56E3F8 80218158 0C0B1EAF */  jal       get_variable
/* 56E3FC 8021815C 0240202D */   daddu    $a0, $s2, $zero
/* 56E400 80218160 AE22001C */  sw        $v0, 0x1c($s1)
/* 56E404 80218164 8E050000 */  lw        $a1, ($s0)
/* 56E408 80218168 0C0B210B */  jal       evt_get_float_variable
/* 56E40C 8021816C 0240202D */   daddu    $a0, $s2, $zero
/* 56E410 80218170 8E240020 */  lw        $a0, 0x20($s1)
/* 56E414 80218174 0C04C3D6 */  jal       get_item_entity
/* 56E418 80218178 E6200010 */   swc1     $f0, 0x10($s1)
/* 56E41C 8021817C 0040802D */  daddu     $s0, $v0, $zero
/* 56E420 80218180 C60C0008 */  lwc1      $f12, 8($s0)
/* 56E424 80218184 C60E0010 */  lwc1      $f14, 0x10($s0)
/* 56E428 80218188 8E260000 */  lw        $a2, ($s1)
/* 56E42C 8021818C 0C00A7B5 */  jal       dist2D
/* 56E430 80218190 8E270008 */   lw       $a3, 8($s1)
/* 56E434 80218194 C60C0008 */  lwc1      $f12, 8($s0)
/* 56E438 80218198 C60E0010 */  lwc1      $f14, 0x10($s0)
/* 56E43C 8021819C 8E260000 */  lw        $a2, ($s1)
/* 56E440 802181A0 8E270008 */  lw        $a3, 8($s1)
/* 56E444 802181A4 0C00A720 */  jal       atan2
/* 56E448 802181A8 46000506 */   mov.s    $f20, $f0
/* 56E44C 802181AC C6240010 */  lwc1      $f4, 0x10($s1)
/* 56E450 802181B0 C626001C */  lwc1      $f6, 0x1c($s1)
/* 56E454 802181B4 468031A0 */  cvt.s.w   $f6, $f6
/* 56E458 802181B8 46062102 */  mul.s     $f4, $f4, $f6
/* 56E45C 802181BC 00000000 */  nop
/* 56E460 802181C0 3C013F00 */  lui       $at, 0x3f00
/* 56E464 802181C4 44811000 */  mtc1      $at, $f2
/* 56E468 802181C8 00000000 */  nop
/* 56E46C 802181CC 46022102 */  mul.s     $f4, $f4, $f2
/* 56E470 802181D0 00000000 */  nop
/* 56E474 802181D4 E620000C */  swc1      $f0, 0xc($s1)
/* 56E478 802181D8 C6200004 */  lwc1      $f0, 4($s1)
/* 56E47C 802181DC C602000C */  lwc1      $f2, 0xc($s0)
/* 56E480 802181E0 46020001 */  sub.s     $f0, $f0, $f2
/* 56E484 802181E4 46003086 */  mov.s     $f2, $f6
/* 56E488 802181E8 46060003 */  div.s     $f0, $f0, $f6
/* 56E48C 802181EC 46002100 */  add.s     $f4, $f4, $f0
/* 56E490 802181F0 4602A503 */  div.s     $f20, $f20, $f2
/* 56E494 802181F4 E6340014 */  swc1      $f20, 0x14($s1)
/* 56E498 802181F8 E6240018 */  swc1      $f4, 0x18($s1)
.L802181FC:
/* 56E49C 802181FC 8E510070 */  lw        $s1, 0x70($s2)
/* 56E4A0 80218200 0C04C3D6 */  jal       get_item_entity
/* 56E4A4 80218204 8E240020 */   lw       $a0, 0x20($s1)
/* 56E4A8 80218208 0040802D */  daddu     $s0, $v0, $zero
/* 56E4AC 8021820C 16000005 */  bnez      $s0, .L80218224
/* 56E4B0 80218210 00000000 */   nop
/* 56E4B4 80218214 0C00AB4B */  jal       heap_free
/* 56E4B8 80218218 8E440070 */   lw       $a0, 0x70($s2)
/* 56E4BC 8021821C 080860B2 */  j         .L802182C8
/* 56E4C0 80218220 24020002 */   addiu    $v0, $zero, 2
.L80218224:
/* 56E4C4 80218224 C62C000C */  lwc1      $f12, 0xc($s1)
/* 56E4C8 80218228 0C00A8BB */  jal       sin_deg
/* 56E4CC 8021822C 00000000 */   nop
/* 56E4D0 80218230 C6220014 */  lwc1      $f2, 0x14($s1)
/* 56E4D4 80218234 46001082 */  mul.s     $f2, $f2, $f0
/* 56E4D8 80218238 00000000 */  nop
/* 56E4DC 8021823C C6000008 */  lwc1      $f0, 8($s0)
/* 56E4E0 80218240 46020000 */  add.s     $f0, $f0, $f2
/* 56E4E4 80218244 E6000008 */  swc1      $f0, 8($s0)
/* 56E4E8 80218248 0C00A8D4 */  jal       cos_deg
/* 56E4EC 8021824C C62C000C */   lwc1     $f12, 0xc($s1)
/* 56E4F0 80218250 C6220014 */  lwc1      $f2, 0x14($s1)
/* 56E4F4 80218254 46001082 */  mul.s     $f2, $f2, $f0
/* 56E4F8 80218258 00000000 */  nop
/* 56E4FC 8021825C C6000010 */  lwc1      $f0, 0x10($s0)
/* 56E500 80218260 46020001 */  sub.s     $f0, $f0, $f2
/* 56E504 80218264 E6000010 */  swc1      $f0, 0x10($s0)
/* 56E508 80218268 C600000C */  lwc1      $f0, 0xc($s0)
/* 56E50C 8021826C C6220018 */  lwc1      $f2, 0x18($s1)
/* 56E510 80218270 46020000 */  add.s     $f0, $f0, $f2
/* 56E514 80218274 E600000C */  swc1      $f0, 0xc($s0)
/* 56E518 80218278 C6200018 */  lwc1      $f0, 0x18($s1)
/* 56E51C 8021827C C6220010 */  lwc1      $f2, 0x10($s1)
/* 56E520 80218280 8E22001C */  lw        $v0, 0x1c($s1)
/* 56E524 80218284 46020001 */  sub.s     $f0, $f0, $f2
/* 56E528 80218288 2442FFFF */  addiu     $v0, $v0, -1
/* 56E52C 8021828C AE22001C */  sw        $v0, 0x1c($s1)
/* 56E530 80218290 04400003 */  bltz      $v0, .L802182A0
/* 56E534 80218294 E6200018 */   swc1     $f0, 0x18($s1)
/* 56E538 80218298 080860B2 */  j         .L802182C8
/* 56E53C 8021829C 0000102D */   daddu    $v0, $zero, $zero
.L802182A0:
/* 56E540 802182A0 C6200000 */  lwc1      $f0, ($s1)
/* 56E544 802182A4 E6000008 */  swc1      $f0, 8($s0)
/* 56E548 802182A8 C6200004 */  lwc1      $f0, 4($s1)
/* 56E54C 802182AC E600000C */  swc1      $f0, 0xc($s0)
/* 56E550 802182B0 C6200008 */  lwc1      $f0, 8($s1)
/* 56E554 802182B4 E6000010 */  swc1      $f0, 0x10($s0)
/* 56E558 802182B8 AE200018 */  sw        $zero, 0x18($s1)
/* 56E55C 802182BC 0C00AB4B */  jal       heap_free
/* 56E560 802182C0 8E440070 */   lw       $a0, 0x70($s2)
/* 56E564 802182C4 24020001 */  addiu     $v0, $zero, 1
.L802182C8:
/* 56E568 802182C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 56E56C 802182CC 8FB20018 */  lw        $s2, 0x18($sp)
/* 56E570 802182D0 8FB10014 */  lw        $s1, 0x14($sp)
/* 56E574 802182D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 56E578 802182D8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 56E57C 802182DC 03E00008 */  jr        $ra
/* 56E580 802182E0 27BD0028 */   addiu    $sp, $sp, 0x28

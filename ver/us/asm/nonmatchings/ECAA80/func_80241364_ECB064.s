.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241364_ECB064
/* ECB064 80241364 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* ECB068 80241368 AFB3003C */  sw        $s3, 0x3c($sp)
/* ECB06C 8024136C 0080982D */  daddu     $s3, $a0, $zero
/* ECB070 80241370 AFBF0040 */  sw        $ra, 0x40($sp)
/* ECB074 80241374 AFB20038 */  sw        $s2, 0x38($sp)
/* ECB078 80241378 AFB10034 */  sw        $s1, 0x34($sp)
/* ECB07C 8024137C AFB00030 */  sw        $s0, 0x30($sp)
/* ECB080 80241380 8E720148 */  lw        $s2, 0x148($s3)
/* ECB084 80241384 00A0882D */  daddu     $s1, $a1, $zero
/* ECB088 80241388 86440008 */  lh        $a0, 8($s2)
/* ECB08C 8024138C 0C00F92F */  jal       dead_get_npc_unsafe
/* ECB090 80241390 00C0802D */   daddu    $s0, $a2, $zero
/* ECB094 80241394 0200202D */  daddu     $a0, $s0, $zero
/* ECB098 80241398 0240282D */  daddu     $a1, $s2, $zero
/* ECB09C 8024139C 24030001 */  addiu     $v1, $zero, 1
/* ECB0A0 802413A0 AFA30010 */  sw        $v1, 0x10($sp)
/* ECB0A4 802413A4 8E260024 */  lw        $a2, 0x24($s1)
/* ECB0A8 802413A8 8E270028 */  lw        $a3, 0x28($s1)
/* ECB0AC 802413AC 0C013469 */  jal       func_8004D1A4
/* ECB0B0 802413B0 0040802D */   daddu    $s0, $v0, $zero
/* ECB0B4 802413B4 1440001D */  bnez      $v0, .L8024142C
/* ECB0B8 802413B8 24040002 */   addiu    $a0, $zero, 2
/* ECB0BC 802413BC 0200282D */  daddu     $a1, $s0, $zero
/* ECB0C0 802413C0 0000302D */  daddu     $a2, $zero, $zero
/* ECB0C4 802413C4 860300A8 */  lh        $v1, 0xa8($s0)
/* ECB0C8 802413C8 3C013F80 */  lui       $at, 0x3f80
/* ECB0CC 802413CC 44810000 */  mtc1      $at, $f0
/* ECB0D0 802413D0 3C014000 */  lui       $at, 0x4000
/* ECB0D4 802413D4 44811000 */  mtc1      $at, $f2
/* ECB0D8 802413D8 3C01C1A0 */  lui       $at, 0xc1a0
/* ECB0DC 802413DC 44812000 */  mtc1      $at, $f4
/* ECB0E0 802413E0 2402000F */  addiu     $v0, $zero, 0xf
/* ECB0E4 802413E4 AFA2001C */  sw        $v0, 0x1c($sp)
/* ECB0E8 802413E8 44833000 */  mtc1      $v1, $f6
/* ECB0EC 802413EC 00000000 */  nop
/* ECB0F0 802413F0 468031A0 */  cvt.s.w   $f6, $f6
/* ECB0F4 802413F4 44073000 */  mfc1      $a3, $f6
/* ECB0F8 802413F8 27A20028 */  addiu     $v0, $sp, 0x28
/* ECB0FC 802413FC AFA20020 */  sw        $v0, 0x20($sp)
/* ECB100 80241400 E7A00010 */  swc1      $f0, 0x10($sp)
/* ECB104 80241404 E7A20014 */  swc1      $f2, 0x14($sp)
/* ECB108 80241408 0C01D444 */  jal       dead_fx_emote
/* ECB10C 8024140C E7A40018 */   swc1     $f4, 0x18($sp)
/* ECB110 80241410 8E4200CC */  lw        $v0, 0xcc($s2)
/* ECB114 80241414 8C430000 */  lw        $v1, ($v0)
/* ECB118 80241418 24020019 */  addiu     $v0, $zero, 0x19
/* ECB11C 8024141C A602008E */  sh        $v0, 0x8e($s0)
/* ECB120 80241420 2402000E */  addiu     $v0, $zero, 0xe
/* ECB124 80241424 0809052A */  j         .L802414A8
/* ECB128 80241428 AE030028 */   sw       $v1, 0x28($s0)
.L8024142C:
/* ECB12C 8024142C 8E4200CC */  lw        $v0, 0xcc($s2)
/* ECB130 80241430 8E030028 */  lw        $v1, 0x28($s0)
/* ECB134 80241434 8C420020 */  lw        $v0, 0x20($v0)
/* ECB138 80241438 10620014 */  beq       $v1, $v0, .L8024148C
/* ECB13C 8024143C 00000000 */   nop
/* ECB140 80241440 C6000018 */  lwc1      $f0, 0x18($s0)
/* ECB144 80241444 3C014010 */  lui       $at, 0x4010
/* ECB148 80241448 44811800 */  mtc1      $at, $f3
/* ECB14C 8024144C 44801000 */  mtc1      $zero, $f2
/* ECB150 80241450 46000021 */  cvt.d.s   $f0, $f0
/* ECB154 80241454 4622003C */  c.lt.d    $f0, $f2
/* ECB158 80241458 00000000 */  nop
/* ECB15C 8024145C 45000003 */  bc1f      .L8024146C
/* ECB160 80241460 0000282D */   daddu    $a1, $zero, $zero
/* ECB164 80241464 0809051D */  j         .L80241474
/* ECB168 80241468 0200202D */   daddu    $a0, $s0, $zero
.L8024146C:
/* ECB16C 8024146C 0200202D */  daddu     $a0, $s0, $zero
/* ECB170 80241470 24050001 */  addiu     $a1, $zero, 1
.L80241474:
/* ECB174 80241474 0C010420 */  jal       func_80041080
/* ECB178 80241478 00000000 */   nop
/* ECB17C 8024147C 8E050018 */  lw        $a1, 0x18($s0)
/* ECB180 80241480 8E06000C */  lw        $a2, 0xc($s0)
/* ECB184 80241484 0C00F909 */  jal       dead_npc_move_heading
/* ECB188 80241488 0200202D */   daddu    $a0, $s0, $zero
.L8024148C:
/* ECB18C 8024148C 8602008E */  lh        $v0, 0x8e($s0)
/* ECB190 80241490 9603008E */  lhu       $v1, 0x8e($s0)
/* ECB194 80241494 18400003 */  blez      $v0, .L802414A4
/* ECB198 80241498 2462FFFF */   addiu    $v0, $v1, -1
/* ECB19C 8024149C 0809052B */  j         .L802414AC
/* ECB1A0 802414A0 A602008E */   sh       $v0, 0x8e($s0)
.L802414A4:
/* ECB1A4 802414A4 2402000C */  addiu     $v0, $zero, 0xc
.L802414A8:
/* ECB1A8 802414A8 AE620070 */  sw        $v0, 0x70($s3)
.L802414AC:
/* ECB1AC 802414AC 8FBF0040 */  lw        $ra, 0x40($sp)
/* ECB1B0 802414B0 8FB3003C */  lw        $s3, 0x3c($sp)
/* ECB1B4 802414B4 8FB20038 */  lw        $s2, 0x38($sp)
/* ECB1B8 802414B8 8FB10034 */  lw        $s1, 0x34($sp)
/* ECB1BC 802414BC 8FB00030 */  lw        $s0, 0x30($sp)
/* ECB1C0 802414C0 03E00008 */  jr        $ra
/* ECB1C4 802414C4 27BD0048 */   addiu    $sp, $sp, 0x48

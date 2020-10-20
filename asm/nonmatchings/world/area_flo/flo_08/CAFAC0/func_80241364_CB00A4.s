.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241364_CB00A4
/* CB00A4 80241364 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CB00A8 80241368 AFB3003C */  sw        $s3, 0x3c($sp)
/* CB00AC 8024136C 0080982D */  daddu     $s3, $a0, $zero
/* CB00B0 80241370 AFBF0040 */  sw        $ra, 0x40($sp)
/* CB00B4 80241374 AFB20038 */  sw        $s2, 0x38($sp)
/* CB00B8 80241378 AFB10034 */  sw        $s1, 0x34($sp)
/* CB00BC 8024137C AFB00030 */  sw        $s0, 0x30($sp)
/* CB00C0 80241380 8E720148 */  lw        $s2, 0x148($s3)
/* CB00C4 80241384 00A0882D */  daddu     $s1, $a1, $zero
/* CB00C8 80241388 86440008 */  lh        $a0, 8($s2)
/* CB00CC 8024138C 0C00EABB */  jal       get_npc_unsafe
/* CB00D0 80241390 00C0802D */   daddu    $s0, $a2, $zero
/* CB00D4 80241394 0200202D */  daddu     $a0, $s0, $zero
/* CB00D8 80241398 0240282D */  daddu     $a1, $s2, $zero
/* CB00DC 8024139C 24030001 */  addiu     $v1, $zero, 1
/* CB00E0 802413A0 AFA30010 */  sw        $v1, 0x10($sp)
/* CB00E4 802413A4 8E260024 */  lw        $a2, 0x24($s1)
/* CB00E8 802413A8 8E270028 */  lw        $a3, 0x28($s1)
/* CB00EC 802413AC 0C01242D */  jal       func_800490B4
/* CB00F0 802413B0 0040802D */   daddu    $s0, $v0, $zero
/* CB00F4 802413B4 1440001D */  bnez      $v0, .L8024142C
/* CB00F8 802413B8 24040002 */   addiu    $a0, $zero, 2
/* CB00FC 802413BC 0200282D */  daddu     $a1, $s0, $zero
/* CB0100 802413C0 0000302D */  daddu     $a2, $zero, $zero
/* CB0104 802413C4 860300A8 */  lh        $v1, 0xa8($s0)
/* CB0108 802413C8 3C013F80 */  lui       $at, 0x3f80
/* CB010C 802413CC 44810000 */  mtc1      $at, $f0
/* CB0110 802413D0 3C014000 */  lui       $at, 0x4000
/* CB0114 802413D4 44811000 */  mtc1      $at, $f2
/* CB0118 802413D8 3C01C1A0 */  lui       $at, 0xc1a0
/* CB011C 802413DC 44812000 */  mtc1      $at, $f4
/* CB0120 802413E0 2402000F */  addiu     $v0, $zero, 0xf
/* CB0124 802413E4 AFA2001C */  sw        $v0, 0x1c($sp)
/* CB0128 802413E8 44833000 */  mtc1      $v1, $f6
/* CB012C 802413EC 00000000 */  nop       
/* CB0130 802413F0 468031A0 */  cvt.s.w   $f6, $f6
/* CB0134 802413F4 44073000 */  mfc1      $a3, $f6
/* CB0138 802413F8 27A20028 */  addiu     $v0, $sp, 0x28
/* CB013C 802413FC AFA20020 */  sw        $v0, 0x20($sp)
/* CB0140 80241400 E7A00010 */  swc1      $f0, 0x10($sp)
/* CB0144 80241404 E7A20014 */  swc1      $f2, 0x14($sp)
/* CB0148 80241408 0C01BFA4 */  jal       fx_emote
/* CB014C 8024140C E7A40018 */   swc1     $f4, 0x18($sp)
/* CB0150 80241410 8E4200CC */  lw        $v0, 0xcc($s2)
/* CB0154 80241414 8C430000 */  lw        $v1, ($v0)
/* CB0158 80241418 24020019 */  addiu     $v0, $zero, 0x19
/* CB015C 8024141C A602008E */  sh        $v0, 0x8e($s0)
/* CB0160 80241420 2402000E */  addiu     $v0, $zero, 0xe
/* CB0164 80241424 0809052A */  j         .L802414A8
/* CB0168 80241428 AE030028 */   sw       $v1, 0x28($s0)
.L8024142C:
/* CB016C 8024142C 8E4200CC */  lw        $v0, 0xcc($s2)
/* CB0170 80241430 8E030028 */  lw        $v1, 0x28($s0)
/* CB0174 80241434 8C420020 */  lw        $v0, 0x20($v0)
/* CB0178 80241438 10620014 */  beq       $v1, $v0, .L8024148C
/* CB017C 8024143C 00000000 */   nop      
/* CB0180 80241440 C6000018 */  lwc1      $f0, 0x18($s0)
/* CB0184 80241444 3C014010 */  lui       $at, 0x4010
/* CB0188 80241448 44811800 */  mtc1      $at, $f3
/* CB018C 8024144C 44801000 */  mtc1      $zero, $f2
/* CB0190 80241450 46000021 */  cvt.d.s   $f0, $f0
/* CB0194 80241454 4622003C */  c.lt.d    $f0, $f2
/* CB0198 80241458 00000000 */  nop       
/* CB019C 8024145C 45000003 */  bc1f      .L8024146C
/* CB01A0 80241460 0000282D */   daddu    $a1, $zero, $zero
/* CB01A4 80241464 0809051D */  j         .L80241474
/* CB01A8 80241468 0200202D */   daddu    $a0, $s0, $zero
.L8024146C:
/* CB01AC 8024146C 0200202D */  daddu     $a0, $s0, $zero
/* CB01B0 80241470 24050001 */  addiu     $a1, $zero, 1
.L80241474:
/* CB01B4 80241474 0C00F598 */  jal       func_8003D660
/* CB01B8 80241478 00000000 */   nop      
/* CB01BC 8024147C 8E050018 */  lw        $a1, 0x18($s0)
/* CB01C0 80241480 8E06000C */  lw        $a2, 0xc($s0)
/* CB01C4 80241484 0C00EA95 */  jal       npc_move_heading
/* CB01C8 80241488 0200202D */   daddu    $a0, $s0, $zero
.L8024148C:
/* CB01CC 8024148C 8602008E */  lh        $v0, 0x8e($s0)
/* CB01D0 80241490 9603008E */  lhu       $v1, 0x8e($s0)
/* CB01D4 80241494 18400003 */  blez      $v0, .L802414A4
/* CB01D8 80241498 2462FFFF */   addiu    $v0, $v1, -1
/* CB01DC 8024149C 0809052B */  j         .L802414AC
/* CB01E0 802414A0 A602008E */   sh       $v0, 0x8e($s0)
.L802414A4:
/* CB01E4 802414A4 2402000C */  addiu     $v0, $zero, 0xc
.L802414A8:
/* CB01E8 802414A8 AE620070 */  sw        $v0, 0x70($s3)
.L802414AC:
/* CB01EC 802414AC 8FBF0040 */  lw        $ra, 0x40($sp)
/* CB01F0 802414B0 8FB3003C */  lw        $s3, 0x3c($sp)
/* CB01F4 802414B4 8FB20038 */  lw        $s2, 0x38($sp)
/* CB01F8 802414B8 8FB10034 */  lw        $s1, 0x34($sp)
/* CB01FC 802414BC 8FB00030 */  lw        $s0, 0x30($sp)
/* CB0200 802414C0 03E00008 */  jr        $ra
/* CB0204 802414C4 27BD0048 */   addiu    $sp, $sp, 0x48

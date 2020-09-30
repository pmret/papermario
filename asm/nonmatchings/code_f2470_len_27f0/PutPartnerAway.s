.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PutPartnerAway
/* F4338 802CF988 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* F433C 802CF98C AFB00010 */  sw        $s0, 0x10($sp)
/* F4340 802CF990 00A0802D */  daddu     $s0, $a1, $zero
/* F4344 802CF994 AFBF0018 */  sw        $ra, 0x18($sp)
/* F4348 802CF998 AFB10014 */  sw        $s1, 0x14($sp)
/* F434C 802CF99C F7BE0048 */  sdc1      $f30, 0x48($sp)
/* F4350 802CF9A0 F7BC0040 */  sdc1      $f28, 0x40($sp)
/* F4354 802CF9A4 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* F4358 802CF9A8 F7B80030 */  sdc1      $f24, 0x30($sp)
/* F435C 802CF9AC F7B60028 */  sdc1      $f22, 0x28($sp)
/* F4360 802CF9B0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* F4364 802CF9B4 0C00EABB */  jal       get_npc_unsafe
/* F4368 802CF9B8 2404FFFC */   addiu    $a0, $zero, -4
/* F436C 802CF9BC 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* F4370 802CF9C0 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* F4374 802CF9C4 1200005F */  beqz      $s0, .L802CFB44
/* F4378 802CF9C8 0040882D */   daddu    $s1, $v0, $zero
/* F437C 802CF9CC 3C10802E */  lui       $s0, 0x802e
/* F4380 802CF9D0 2610AE40 */  addiu     $s0, $s0, -0x51c0
/* F4384 802CF9D4 8E020000 */  lw        $v0, ($s0)
/* F4388 802CF9D8 1040009A */  beqz      $v0, .L802CFC44
/* F438C 802CF9DC 2403FDFF */   addiu    $v1, $zero, -0x201
/* F4390 802CF9E0 8E220000 */  lw        $v0, ($s1)
/* F4394 802CF9E4 C63A0038 */  lwc1      $f26, 0x38($s1)
/* F4398 802CF9E8 C63C003C */  lwc1      $f28, 0x3c($s1)
/* F439C 802CF9EC C6380040 */  lwc1      $f24, 0x40($s1)
/* F43A0 802CF9F0 00431024 */  and       $v0, $v0, $v1
/* F43A4 802CF9F4 2403FFF7 */  addiu     $v1, $zero, -9
/* F43A8 802CF9F8 00431024 */  and       $v0, $v0, $v1
/* F43AC 802CF9FC AE220000 */  sw        $v0, ($s1)
/* F43B0 802CFA00 C4960028 */  lwc1      $f22, 0x28($a0)
/* F43B4 802CFA04 E6360060 */  swc1      $f22, 0x60($s1)
/* F43B8 802CFA08 948200B0 */  lhu       $v0, 0xb0($a0)
/* F43BC 802CFA0C C482002C */  lwc1      $f2, 0x2c($a0)
/* F43C0 802CFA10 4406B000 */  mfc1      $a2, $f22
/* F43C4 802CFA14 00021400 */  sll       $v0, $v0, 0x10
/* F43C8 802CFA18 00021C03 */  sra       $v1, $v0, 0x10
/* F43CC 802CFA1C 000217C2 */  srl       $v0, $v0, 0x1f
/* F43D0 802CFA20 00621821 */  addu      $v1, $v1, $v0
/* F43D4 802CFA24 00031843 */  sra       $v1, $v1, 1
/* F43D8 802CFA28 44830000 */  mtc1      $v1, $f0
/* F43DC 802CFA2C 00000000 */  nop       
/* F43E0 802CFA30 46800020 */  cvt.s.w   $f0, $f0
/* F43E4 802CFA34 46001780 */  add.s     $f30, $f2, $f0
/* F43E8 802CFA38 3C014080 */  lui       $at, 0x4080
/* F43EC 802CFA3C 44810000 */  mtc1      $at, $f0
/* F43F0 802CFA40 4600D306 */  mov.s     $f12, $f26
/* F43F4 802CFA44 E63E0064 */  swc1      $f30, 0x64($s1)
/* F43F8 802CFA48 C4940030 */  lwc1      $f20, 0x30($a0)
/* F43FC 802CFA4C 3C014026 */  lui       $at, 0x4026
/* F4400 802CFA50 34216666 */  ori       $at, $at, 0x6666
/* F4404 802CFA54 44811000 */  mtc1      $at, $f2
/* F4408 802CFA58 4407A000 */  mfc1      $a3, $f20
/* F440C 802CFA5C 4600C386 */  mov.s     $f14, $f24
/* F4410 802CFA60 E6200018 */  swc1      $f0, 0x18($s1)
/* F4414 802CFA64 E6220014 */  swc1      $f2, 0x14($s1)
/* F4418 802CFA68 0C00A7B5 */  jal       dist2D
/* F441C 802CFA6C E6340068 */   swc1     $f20, 0x68($s1)
/* F4420 802CFA70 4600D306 */  mov.s     $f12, $f26
/* F4424 802CFA74 4406B000 */  mfc1      $a2, $f22
/* F4428 802CFA78 4407A000 */  mfc1      $a3, $f20
/* F442C 802CFA7C 4600C386 */  mov.s     $f14, $f24
/* F4430 802CFA80 0C00A720 */  jal       atan2
/* F4434 802CFA84 E6200010 */   swc1     $f0, 0x10($s1)
/* F4438 802CFA88 C6220010 */  lwc1      $f2, 0x10($s1)
/* F443C 802CFA8C C6240018 */  lwc1      $f4, 0x18($s1)
/* F4440 802CFA90 E620000C */  swc1      $f0, 0xc($s1)
/* F4444 802CFA94 46041083 */  div.s     $f2, $f2, $f4
/* F4448 802CFA98 4600118D */  trunc.w.s $f6, $f2
/* F444C 802CFA9C 44023000 */  mfc1      $v0, $f6
/* F4450 802CFAA0 00000000 */  nop       
/* F4454 802CFAA4 A622008E */  sh        $v0, 0x8e($s1)
/* F4458 802CFAA8 00021400 */  sll       $v0, $v0, 0x10
/* F445C 802CFAAC 00021403 */  sra       $v0, $v0, 0x10
/* F4460 802CFAB0 2842000A */  slti      $v0, $v0, 0xa
/* F4464 802CFAB4 10400007 */  beqz      $v0, .L802CFAD4
/* F4468 802CFAB8 2402000A */   addiu    $v0, $zero, 0xa
/* F446C 802CFABC 3C014120 */  lui       $at, 0x4120
/* F4470 802CFAC0 44810000 */  mtc1      $at, $f0
/* F4474 802CFAC4 C6220010 */  lwc1      $f2, 0x10($s1)
/* F4478 802CFAC8 A622008E */  sh        $v0, 0x8e($s1)
/* F447C 802CFACC 46001083 */  div.s     $f2, $f2, $f0
/* F4480 802CFAD0 E6220018 */  swc1      $f2, 0x18($s1)
.L802CFAD4:
/* F4484 802CFAD4 8622008E */  lh        $v0, 0x8e($s1)
/* F4488 802CFAD8 C6200014 */  lwc1      $f0, 0x14($s1)
/* F448C 802CFADC 44822000 */  mtc1      $v0, $f4
/* F4490 802CFAE0 00000000 */  nop       
/* F4494 802CFAE4 46802120 */  cvt.s.w   $f4, $f4
/* F4498 802CFAE8 46040002 */  mul.s     $f0, $f0, $f4
/* F449C 802CFAEC 00000000 */  nop       
/* F44A0 802CFAF0 46040002 */  mul.s     $f0, $f0, $f4
/* F44A4 802CFAF4 00000000 */  nop       
/* F44A8 802CFAF8 3C013F00 */  lui       $at, 0x3f00
/* F44AC 802CFAFC 44811000 */  mtc1      $at, $f2
/* F44B0 802CFB00 00000000 */  nop       
/* F44B4 802CFB04 46020002 */  mul.s     $f0, $f0, $f2
/* F44B8 802CFB08 00000000 */  nop       
/* F44BC 802CFB0C 8E030000 */  lw        $v1, ($s0)
/* F44C0 802CFB10 461CF701 */  sub.s     $f28, $f30, $f28
/* F44C4 802CFB14 000310C0 */  sll       $v0, $v1, 3
/* F44C8 802CFB18 4600E000 */  add.s     $f0, $f28, $f0
/* F44CC 802CFB1C 00431021 */  addu      $v0, $v0, $v1
/* F44D0 802CFB20 00021080 */  sll       $v0, $v0, 2
/* F44D4 802CFB24 46040003 */  div.s     $f0, $f0, $f4
/* F44D8 802CFB28 E620001C */  swc1      $f0, 0x1c($s1)
/* F44DC 802CFB2C 3C038010 */  lui       $v1, 0x8010
/* F44E0 802CFB30 00621821 */  addu      $v1, $v1, $v0
/* F44E4 802CFB34 8C63834C */  lw        $v1, -0x7cb4($v1)
/* F44E8 802CFB38 0000102D */  daddu     $v0, $zero, $zero
/* F44EC 802CFB3C 080B3F12 */  j         .L802CFC48
/* F44F0 802CFB40 AE230028 */   sw       $v1, 0x28($s1)
.L802CFB44:
/* F44F4 802CFB44 C620001C */  lwc1      $f0, 0x1c($s1)
/* F44F8 802CFB48 C6220014 */  lwc1      $f2, 0x14($s1)
/* F44FC 802CFB4C 46020001 */  sub.s     $f0, $f0, $f2
/* F4500 802CFB50 C622003C */  lwc1      $f2, 0x3c($s1)
/* F4504 802CFB54 46001080 */  add.s     $f2, $f2, $f0
/* F4508 802CFB58 4480A000 */  mtc1      $zero, $f20
/* F450C 802CFB5C 00000000 */  nop       
/* F4510 802CFB60 4614003E */  c.le.s    $f0, $f20
/* F4514 802CFB64 E620001C */  swc1      $f0, 0x1c($s1)
/* F4518 802CFB68 4500000A */  bc1f      .L802CFB94
/* F451C 802CFB6C E622003C */   swc1     $f2, 0x3c($s1)
/* F4520 802CFB70 3C02802E */  lui       $v0, 0x802e
/* F4524 802CFB74 8C42AE40 */  lw        $v0, -0x51c0($v0)
/* F4528 802CFB78 000218C0 */  sll       $v1, $v0, 3
/* F452C 802CFB7C 00621821 */  addu      $v1, $v1, $v0
/* F4530 802CFB80 00031880 */  sll       $v1, $v1, 2
/* F4534 802CFB84 3C028010 */  lui       $v0, 0x8010
/* F4538 802CFB88 00431021 */  addu      $v0, $v0, $v1
/* F453C 802CFB8C 8C428350 */  lw        $v0, -0x7cb0($v0)
/* F4540 802CFB90 AE220028 */  sw        $v0, 0x28($s1)
.L802CFB94:
/* F4544 802CFB94 8E26000C */  lw        $a2, 0xc($s1)
/* F4548 802CFB98 8E250018 */  lw        $a1, 0x18($s1)
/* F454C 802CFB9C 0C00EA95 */  jal       npc_move_heading
/* F4550 802CFBA0 0220202D */   daddu    $a0, $s1, $zero
/* F4554 802CFBA4 8622008E */  lh        $v0, 0x8e($s1)
/* F4558 802CFBA8 3C014120 */  lui       $at, 0x4120
/* F455C 802CFBAC 44811000 */  mtc1      $at, $f2
/* F4560 802CFBB0 44820000 */  mtc1      $v0, $f0
/* F4564 802CFBB4 00000000 */  nop       
/* F4568 802CFBB8 46800020 */  cvt.s.w   $f0, $f0
/* F456C 802CFBBC 4600103C */  c.lt.s    $f2, $f0
/* F4570 802CFBC0 00000000 */  nop       
/* F4574 802CFBC4 45030001 */  bc1tl     .L802CFBCC
/* F4578 802CFBC8 46001006 */   mov.s    $f0, $f2
.L802CFBCC:
/* F457C 802CFBCC 9622008E */  lhu       $v0, 0x8e($s1)
/* F4580 802CFBD0 46020003 */  div.s     $f0, $f0, $f2
/* F4584 802CFBD4 E6200054 */  swc1      $f0, 0x54($s1)
/* F4588 802CFBD8 46000086 */  mov.s     $f2, $f0
/* F458C 802CFBDC E6200058 */  swc1      $f0, 0x58($s1)
/* F4590 802CFBE0 E622005C */  swc1      $f2, 0x5c($s1)
/* F4594 802CFBE4 2442FFFF */  addiu     $v0, $v0, -1
/* F4598 802CFBE8 A622008E */  sh        $v0, 0x8e($s1)
/* F459C 802CFBEC 00021400 */  sll       $v0, $v0, 0x10
/* F45A0 802CFBF0 04410015 */  bgez      $v0, .L802CFC48
/* F45A4 802CFBF4 0000102D */   daddu    $v0, $zero, $zero
/* F45A8 802CFBF8 3C03802E */  lui       $v1, 0x802e
/* F45AC 802CFBFC 8C63AE40 */  lw        $v1, -0x51c0($v1)
/* F45B0 802CFC00 3C04802E */  lui       $a0, 0x802e
/* F45B4 802CFC04 8C84AE44 */  lw        $a0, -0x51bc($a0)
/* F45B8 802CFC08 C6200064 */  lwc1      $f0, 0x64($s1)
/* F45BC 802CFC0C 000310C0 */  sll       $v0, $v1, 3
/* F45C0 802CFC10 00431021 */  addu      $v0, $v0, $v1
/* F45C4 802CFC14 00021080 */  sll       $v0, $v0, 2
/* F45C8 802CFC18 3C018010 */  lui       $at, 0x8010
/* F45CC 802CFC1C 00220821 */  addu      $at, $at, $v0
/* F45D0 802CFC20 8C228354 */  lw        $v0, -0x7cac($at)
/* F45D4 802CFC24 E634001C */  swc1      $f20, 0x1c($s1)
/* F45D8 802CFC28 E620003C */  swc1      $f0, 0x3c($s1)
/* F45DC 802CFC2C 0C00E228 */  jal       free_npc_by_index
/* F45E0 802CFC30 AE220028 */   sw       $v0, 0x28($s1)
/* F45E4 802CFC34 0C00EABB */  jal       get_npc_unsafe
/* F45E8 802CFC38 2404FFFB */   addiu    $a0, $zero, -5
/* F45EC 802CFC3C 2403FFFC */  addiu     $v1, $zero, -4
/* F45F0 802CFC40 A04300A4 */  sb        $v1, 0xa4($v0)
.L802CFC44:
/* F45F4 802CFC44 24020002 */  addiu     $v0, $zero, 2
.L802CFC48:
/* F45F8 802CFC48 8FBF0018 */  lw        $ra, 0x18($sp)
/* F45FC 802CFC4C 8FB10014 */  lw        $s1, 0x14($sp)
/* F4600 802CFC50 8FB00010 */  lw        $s0, 0x10($sp)
/* F4604 802CFC54 D7BE0048 */  ldc1      $f30, 0x48($sp)
/* F4608 802CFC58 D7BC0040 */  ldc1      $f28, 0x40($sp)
/* F460C 802CFC5C D7BA0038 */  ldc1      $f26, 0x38($sp)
/* F4610 802CFC60 D7B80030 */  ldc1      $f24, 0x30($sp)
/* F4614 802CFC64 D7B60028 */  ldc1      $f22, 0x28($sp)
/* F4618 802CFC68 D7B40020 */  ldc1      $f20, 0x20($sp)
/* F461C 802CFC6C 03E00008 */  jr        $ra
/* F4620 802CFC70 27BD0050 */   addiu    $sp, $sp, 0x50

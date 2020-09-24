.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetNextPathPos
/* F9ED4 802D5524 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* F9ED8 802D5528 AFB1002C */  sw        $s1, 0x2c($sp)
/* F9EDC 802D552C 0080882D */  daddu     $s1, $a0, $zero
/* F9EE0 802D5530 AFBF0030 */  sw        $ra, 0x30($sp)
/* F9EE4 802D5534 AFB00028 */  sw        $s0, 0x28($sp)
/* F9EE8 802D5538 8E3000C0 */  lw        $s0, 0xc0($s1)
/* F9EEC 802D553C 8E030018 */  lw        $v1, 0x18($s0)
/* F9EF0 802D5540 24020001 */  addiu     $v0, $zero, 1
/* F9EF4 802D5544 10620017 */  beq       $v1, $v0, .L802D55A4
/* F9EF8 802D5548 28620002 */   slti     $v0, $v1, 2
/* F9EFC 802D554C 10400005 */  beqz      $v0, .L802D5564
/* F9F00 802D5550 24020004 */   addiu    $v0, $zero, 4
/* F9F04 802D5554 10600009 */  beqz      $v1, .L802D557C
/* F9F08 802D5558 00000000 */   nop      
/* F9F0C 802D555C 080B55A3 */  j         .L802D568C
/* F9F10 802D5560 00000000 */   nop      
.L802D5564:
/* F9F14 802D5564 10620022 */  beq       $v1, $v0, .L802D55F0
/* F9F18 802D5568 2402000A */   addiu    $v0, $zero, 0xa
/* F9F1C 802D556C 10620032 */  beq       $v1, $v0, .L802D5638
/* F9F20 802D5570 00000000 */   nop      
/* F9F24 802D5574 080B55A3 */  j         .L802D568C
/* F9F28 802D5578 00000000 */   nop      
.L802D557C:
/* F9F2C 802D557C 3C013F80 */  lui       $at, 0x3f80
/* F9F30 802D5580 44810000 */  mtc1      $at, $f0
/* F9F34 802D5584 C6020014 */  lwc1      $f2, 0x14($s0)
/* F9F38 802D5588 468010A0 */  cvt.s.w   $f2, $f2
/* F9F3C 802D558C 46020003 */  div.s     $f0, $f0, $f2
/* F9F40 802D5590 C6020010 */  lwc1      $f2, 0x10($s0)
/* F9F44 802D5594 468010A0 */  cvt.s.w   $f2, $f2
/* F9F48 802D5598 46020302 */  mul.s     $f12, $f0, $f2
/* F9F4C 802D559C 080B55A4 */  j         .L802D5690
/* F9F50 802D55A0 00000000 */   nop      
.L802D55A4:
/* F9F54 802D55A4 8E020014 */  lw        $v0, 0x14($s0)
/* F9F58 802D55A8 00420018 */  mult      $v0, $v0
/* F9F5C 802D55AC 00001812 */  mflo      $v1
/* F9F60 802D55B0 8E020010 */  lw        $v0, 0x10($s0)
/* F9F64 802D55B4 00000000 */  nop       
/* F9F68 802D55B8 00420018 */  mult      $v0, $v0
/* F9F6C 802D55BC 3C013F80 */  lui       $at, 0x3f80
/* F9F70 802D55C0 44810000 */  mtc1      $at, $f0
/* F9F74 802D55C4 44831000 */  mtc1      $v1, $f2
/* F9F78 802D55C8 00000000 */  nop       
/* F9F7C 802D55CC 468010A0 */  cvt.s.w   $f2, $f2
/* F9F80 802D55D0 00001012 */  mflo      $v0
/* F9F84 802D55D4 46020003 */  div.s     $f0, $f0, $f2
/* F9F88 802D55D8 44821000 */  mtc1      $v0, $f2
/* F9F8C 802D55DC 00000000 */  nop       
/* F9F90 802D55E0 468010A0 */  cvt.s.w   $f2, $f2
/* F9F94 802D55E4 46020302 */  mul.s     $f12, $f0, $f2
/* F9F98 802D55E8 080B55A4 */  j         .L802D5690
/* F9F9C 802D55EC 00000000 */   nop      
.L802D55F0:
/* F9FA0 802D55F0 8E020014 */  lw        $v0, 0x14($s0)
/* F9FA4 802D55F4 00420018 */  mult      $v0, $v0
/* F9FA8 802D55F8 8E030010 */  lw        $v1, 0x10($s0)
/* F9FAC 802D55FC 00431023 */  subu      $v0, $v0, $v1
/* F9FB0 802D5600 44820000 */  mtc1      $v0, $f0
/* F9FB4 802D5604 00000000 */  nop       
/* F9FB8 802D5608 46800020 */  cvt.s.w   $f0, $f0
/* F9FBC 802D560C 46000002 */  mul.s     $f0, $f0, $f0
/* F9FC0 802D5610 00000000 */  nop       
/* F9FC4 802D5614 3C013F80 */  lui       $at, 0x3f80
/* F9FC8 802D5618 44812000 */  mtc1      $at, $f4
/* F9FCC 802D561C 00004012 */  mflo      $t0
/* F9FD0 802D5620 44881000 */  mtc1      $t0, $f2
/* F9FD4 802D5624 00000000 */  nop       
/* F9FD8 802D5628 468010A0 */  cvt.s.w   $f2, $f2
/* F9FDC 802D562C 46020003 */  div.s     $f0, $f0, $f2
/* F9FE0 802D5630 080B55A4 */  j         .L802D5690
/* F9FE4 802D5634 46002301 */   sub.s    $f12, $f4, $f0
.L802D5638:
/* F9FE8 802D5638 3C014049 */  lui       $at, 0x4049
/* F9FEC 802D563C 34210FD8 */  ori       $at, $at, 0xfd8
/* F9FF0 802D5640 44816000 */  mtc1      $at, $f12
/* F9FF4 802D5644 C6000014 */  lwc1      $f0, 0x14($s0)
/* F9FF8 802D5648 46800020 */  cvt.s.w   $f0, $f0
/* F9FFC 802D564C 46006303 */  div.s     $f12, $f12, $f0
/* FA000 802D5650 C6000010 */  lwc1      $f0, 0x10($s0)
/* FA004 802D5654 46800020 */  cvt.s.w   $f0, $f0
/* FA008 802D5658 46006302 */  mul.s     $f12, $f12, $f0
/* FA00C 802D565C 0C00A874 */  jal       cos_rad
/* FA010 802D5660 00000000 */   nop      
/* FA014 802D5664 3C013F80 */  lui       $at, 0x3f80
/* FA018 802D5668 44811000 */  mtc1      $at, $f2
/* FA01C 802D566C 00000000 */  nop       
/* FA020 802D5670 46001081 */  sub.s     $f2, $f2, $f0
/* FA024 802D5674 3C013F00 */  lui       $at, 0x3f00
/* FA028 802D5678 44810000 */  mtc1      $at, $f0
/* FA02C 802D567C 00000000 */  nop       
/* FA030 802D5680 46001302 */  mul.s     $f12, $f2, $f0
/* FA034 802D5684 080B55A4 */  j         .L802D5690
/* FA038 802D5688 00000000 */   nop      
.L802D568C:
/* FA03C 802D568C 44806000 */  mtc1      $zero, $f12
.L802D5690:
/* FA040 802D5690 8E020008 */  lw        $v0, 8($s0)
/* FA044 802D5694 AFA20010 */  sw        $v0, 0x10($sp)
/* FA048 802D5698 8E02000C */  lw        $v0, 0xc($s0)
/* FA04C 802D569C AFA20014 */  sw        $v0, 0x14($sp)
/* FA050 802D56A0 8E060000 */  lw        $a2, ($s0)
/* FA054 802D56A4 8E070004 */  lw        $a3, 4($s0)
/* FA058 802D56A8 0C0B549C */  jal       func_802D5270
/* FA05C 802D56AC 27A50018 */   addiu    $a1, $sp, 0x18
/* FA060 802D56B0 C7A00018 */  lwc1      $f0, 0x18($sp)
/* FA064 802D56B4 3C014480 */  lui       $at, 0x4480
/* FA068 802D56B8 44812000 */  mtc1      $at, $f4
/* FA06C 802D56BC 00000000 */  nop       
/* FA070 802D56C0 46040002 */  mul.s     $f0, $f0, $f4
/* FA074 802D56C4 00000000 */  nop       
/* FA078 802D56C8 3C01CD5B */  lui       $at, 0xcd5b
/* FA07C 802D56CC 34215858 */  ori       $at, $at, 0x5858
/* FA080 802D56D0 44811000 */  mtc1      $at, $f2
/* FA084 802D56D4 00000000 */  nop       
/* FA088 802D56D8 46020000 */  add.s     $f0, $f0, $f2
/* FA08C 802D56DC 4600018D */  trunc.w.s $f6, $f0
/* FA090 802D56E0 E6260088 */  swc1      $f6, 0x88($s1)
/* FA094 802D56E4 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* FA098 802D56E8 46040002 */  mul.s     $f0, $f0, $f4
/* FA09C 802D56EC 00000000 */  nop       
/* FA0A0 802D56F0 46020000 */  add.s     $f0, $f0, $f2
/* FA0A4 802D56F4 4600018D */  trunc.w.s $f6, $f0
/* FA0A8 802D56F8 E626008C */  swc1      $f6, 0x8c($s1)
/* FA0AC 802D56FC C7A00020 */  lwc1      $f0, 0x20($sp)
/* FA0B0 802D5700 46040002 */  mul.s     $f0, $f0, $f4
/* FA0B4 802D5704 00000000 */  nop       
/* FA0B8 802D5708 46020000 */  add.s     $f0, $f0, $f2
/* FA0BC 802D570C 4600018D */  trunc.w.s $f6, $f0
/* FA0C0 802D5710 E6260090 */  swc1      $f6, 0x90($s1)
/* FA0C4 802D5714 8E030010 */  lw        $v1, 0x10($s0)
/* FA0C8 802D5718 8E020014 */  lw        $v0, 0x14($s0)
/* FA0CC 802D571C 0062102A */  slt       $v0, $v1, $v0
/* FA0D0 802D5720 10400005 */  beqz      $v0, .L802D5738
/* FA0D4 802D5724 24620001 */   addiu    $v0, $v1, 1
/* FA0D8 802D5728 AE020010 */  sw        $v0, 0x10($s0)
/* FA0DC 802D572C 24020001 */  addiu     $v0, $zero, 1
/* FA0E0 802D5730 080B55D6 */  j         .L802D5758
/* FA0E4 802D5734 AE220084 */   sw       $v0, 0x84($s1)
.L802D5738:
/* FA0E8 802D5738 8E040004 */  lw        $a0, 4($s0)
/* FA0EC 802D573C 0C00AB4B */  jal       heap_free
/* FA0F0 802D5740 00000000 */   nop      
/* FA0F4 802D5744 0C00AB4B */  jal       heap_free
/* FA0F8 802D5748 8E04000C */   lw       $a0, 0xc($s0)
/* FA0FC 802D574C 0C00AB4B */  jal       heap_free
/* FA100 802D5750 8E2400C0 */   lw       $a0, 0xc0($s1)
/* FA104 802D5754 AE200084 */  sw        $zero, 0x84($s1)
.L802D5758:
/* FA108 802D5758 8FBF0030 */  lw        $ra, 0x30($sp)
/* FA10C 802D575C 8FB1002C */  lw        $s1, 0x2c($sp)
/* FA110 802D5760 8FB00028 */  lw        $s0, 0x28($sp)
/* FA114 802D5764 24020002 */  addiu     $v0, $zero, 2
/* FA118 802D5768 03E00008 */  jr        $ra
/* FA11C 802D576C 27BD0038 */   addiu    $sp, $sp, 0x38

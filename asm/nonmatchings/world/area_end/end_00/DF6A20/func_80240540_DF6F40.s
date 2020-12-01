.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240540_DF6F40
/* DF6F40 80240540 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* DF6F44 80240544 AFB200D0 */  sw        $s2, 0xd0($sp)
/* DF6F48 80240548 0080902D */  daddu     $s2, $a0, $zero
/* DF6F4C 8024054C AFB000C8 */  sw        $s0, 0xc8($sp)
/* DF6F50 80240550 00A0802D */  daddu     $s0, $a1, $zero
/* DF6F54 80240554 AFBF00E0 */  sw        $ra, 0xe0($sp)
/* DF6F58 80240558 AFB500DC */  sw        $s5, 0xdc($sp)
/* DF6F5C 8024055C AFB400D8 */  sw        $s4, 0xd8($sp)
/* DF6F60 80240560 AFB300D4 */  sw        $s3, 0xd4($sp)
/* DF6F64 80240564 AFB100CC */  sw        $s1, 0xcc($sp)
/* DF6F68 80240568 F7BC0108 */  sdc1      $f28, 0x108($sp)
/* DF6F6C 8024056C F7BA0100 */  sdc1      $f26, 0x100($sp)
/* DF6F70 80240570 F7B800F8 */  sdc1      $f24, 0xf8($sp)
/* DF6F74 80240574 F7B600F0 */  sdc1      $f22, 0xf0($sp)
/* DF6F78 80240578 F7B400E8 */  sdc1      $f20, 0xe8($sp)
/* DF6F7C 8024057C C6160010 */  lwc1      $f22, 0x10($s0)
/* DF6F80 80240580 4680B5A0 */  cvt.s.w   $f22, $f22
/* DF6F84 80240584 3C054180 */  lui       $a1, 0x4180
/* DF6F88 80240588 3C064396 */  lui       $a2, 0x4396
/* DF6F8C 8024058C 8E42001C */  lw        $v0, 0x1c($s2)
/* DF6F90 80240590 C61C0014 */  lwc1      $f28, 0x14($s0)
/* DF6F94 80240594 4680E720 */  cvt.s.w   $f28, $f28
/* DF6F98 80240598 AFA20010 */  sw        $v0, 0x10($sp)
/* DF6F9C 8024059C 8E070018 */  lw        $a3, 0x18($s0)
/* DF6FA0 802405A0 0C00A8ED */  jal       update_lerp
/* DF6FA4 802405A4 2404000C */   addiu    $a0, $zero, 0xc
/* DF6FA8 802405A8 3C01437F */  lui       $at, 0x437f
/* DF6FAC 802405AC 44811000 */  mtc1      $at, $f2
/* DF6FB0 802405B0 00000000 */  nop       
/* DF6FB4 802405B4 4600103C */  c.lt.s    $f2, $f0
/* DF6FB8 802405B8 00000000 */  nop       
/* DF6FBC 802405BC 45000002 */  bc1f      .L802405C8
/* DF6FC0 802405C0 27B10038 */   addiu    $s1, $sp, 0x38
/* DF6FC4 802405C4 46001006 */  mov.s     $f0, $f2
.L802405C8:
/* DF6FC8 802405C8 4600010D */  trunc.w.s $f4, $f0
/* DF6FCC 802405CC E7A40014 */  swc1      $f4, 0x14($sp)
/* DF6FD0 802405D0 0000202D */  daddu     $a0, $zero, $zero
/* DF6FD4 802405D4 24050007 */  addiu     $a1, $zero, 7
/* DF6FD8 802405D8 240600FF */  addiu     $a2, $zero, 0xff
/* DF6FDC 802405DC 00C0382D */  daddu     $a3, $a2, $zero
/* DF6FE0 802405E0 00C0A82D */  daddu     $s5, $a2, $zero
/* DF6FE4 802405E4 AFB50010 */  sw        $s5, 0x10($sp)
/* DF6FE8 802405E8 0C04EAA7 */  jal       func_8013AA9C
/* DF6FEC 802405EC AFA00018 */   sw       $zero, 0x18($sp)
/* DF6FF0 802405F0 8E42001C */  lw        $v0, 0x1c($s2)
/* DF6FF4 802405F4 3C053E4C */  lui       $a1, 0x3e4c
/* DF6FF8 802405F8 34A5CCCD */  ori       $a1, $a1, 0xcccd
/* DF6FFC 802405FC 3C064000 */  lui       $a2, 0x4000
/* DF7000 80240600 AFA20010 */  sw        $v0, 0x10($sp)
/* DF7004 80240604 8E070018 */  lw        $a3, 0x18($s0)
/* DF7008 80240608 0C00A8ED */  jal       update_lerp
/* DF700C 8024060C 0000202D */   daddu    $a0, $zero, $zero
/* DF7010 80240610 46000506 */  mov.s     $f20, $f0
/* DF7014 80240614 3C013FF0 */  lui       $at, 0x3ff0
/* DF7018 80240618 4481C800 */  mtc1      $at, $f25
/* DF701C 8024061C 4480C000 */  mtc1      $zero, $f24
/* DF7020 80240620 4600A021 */  cvt.d.s   $f0, $f20
/* DF7024 80240624 4620C03C */  c.lt.d    $f24, $f0
/* DF7028 80240628 00000000 */  nop       
/* DF702C 8024062C 45000003 */  bc1f      .L8024063C
/* DF7030 80240630 AFB10010 */   sw       $s1, 0x10($sp)
/* DF7034 80240634 3C013F80 */  lui       $at, 0x3f80
/* DF7038 80240638 4481A000 */  mtc1      $at, $f20
.L8024063C:
/* DF703C 8024063C 8E040004 */  lw        $a0, 4($s0)
/* DF7040 80240640 8E050008 */  lw        $a1, 8($s0)
/* DF7044 80240644 8E060000 */  lw        $a2, ($s0)
/* DF7048 80240648 0C04BA38 */  jal       func_8012E8E0
/* DF704C 8024064C 8E07000C */   lw       $a3, 0xc($s0)
/* DF7050 80240650 93A20042 */  lbu       $v0, 0x42($sp)
/* DF7054 80240654 3C013FE0 */  lui       $at, 0x3fe0
/* DF7058 80240658 4481D800 */  mtc1      $at, $f27
/* DF705C 8024065C 4480D000 */  mtc1      $zero, $f26
/* DF7060 80240660 44820000 */  mtc1      $v0, $f0
/* DF7064 80240664 00000000 */  nop       
/* DF7068 80240668 46800021 */  cvt.d.w   $f0, $f0
/* DF706C 8024066C 463A0002 */  mul.d     $f0, $f0, $f26
/* DF7070 80240670 00000000 */  nop       
/* DF7074 80240674 4600B0A1 */  cvt.d.s   $f2, $f22
/* DF7078 80240678 46201080 */  add.d     $f2, $f2, $f0
/* DF707C 8024067C 27B40048 */  addiu     $s4, $sp, 0x48
/* DF7080 80240680 0280202D */  daddu     $a0, $s4, $zero
/* DF7084 80240684 4600E707 */  neg.s     $f28, $f28
/* DF7088 80240688 4406E000 */  mfc1      $a2, $f28
/* DF708C 8024068C 462010A0 */  cvt.s.d   $f2, $f2
/* DF7090 80240690 44051000 */  mfc1      $a1, $f2
/* DF7094 80240694 0C019E40 */  jal       guTranslateF
/* DF7098 80240698 0000382D */   daddu    $a3, $zero, $zero
/* DF709C 8024069C 4600A021 */  cvt.d.s   $f0, $f20
/* DF70A0 802406A0 46380032 */  c.eq.d    $f0, $f24
/* DF70A4 802406A4 00000000 */  nop       
/* DF70A8 802406A8 4501000C */  bc1t      .L802406DC
/* DF70AC 802406AC 3C130001 */   lui      $s3, 1
/* DF70B0 802406B0 27B00088 */  addiu     $s0, $sp, 0x88
/* DF70B4 802406B4 0200202D */  daddu     $a0, $s0, $zero
/* DF70B8 802406B8 4405A000 */  mfc1      $a1, $f20
/* DF70BC 802406BC 3C073F80 */  lui       $a3, 0x3f80
/* DF70C0 802406C0 0C019DF0 */  jal       guScaleF
/* DF70C4 802406C4 00A0302D */   daddu    $a2, $a1, $zero
/* DF70C8 802406C8 0200202D */  daddu     $a0, $s0, $zero
/* DF70CC 802406CC 0280282D */  daddu     $a1, $s4, $zero
/* DF70D0 802406D0 0C019D80 */  jal       guMtxCatF
/* DF70D4 802406D4 0280302D */   daddu    $a2, $s4, $zero
/* DF70D8 802406D8 3C130001 */  lui       $s3, 1
.L802406DC:
/* DF70DC 802406DC 36731630 */  ori       $s3, $s3, 0x1630
/* DF70E0 802406E0 0280202D */  daddu     $a0, $s4, $zero
/* DF70E4 802406E4 3C118007 */  lui       $s1, %hi(D_800741F0)
/* DF70E8 802406E8 263141F0 */  addiu     $s1, $s1, %lo(D_800741F0)
/* DF70EC 802406EC 3C12800A */  lui       $s2, %hi(D_8009A674)
/* DF70F0 802406F0 2652A674 */  addiu     $s2, $s2, %lo(D_8009A674)
/* DF70F4 802406F4 96250000 */  lhu       $a1, ($s1)
/* DF70F8 802406F8 8E420000 */  lw        $v0, ($s2)
/* DF70FC 802406FC 00052980 */  sll       $a1, $a1, 6
/* DF7100 80240700 00B32821 */  addu      $a1, $a1, $s3
/* DF7104 80240704 0C019D40 */  jal       guMtxF2L
/* DF7108 80240708 00452821 */   addu     $a1, $v0, $a1
/* DF710C 8024070C 3C03DA38 */  lui       $v1, 0xda38
/* DF7110 80240710 34630002 */  ori       $v1, $v1, 2
/* DF7114 80240714 0000202D */  daddu     $a0, $zero, $zero
/* DF7118 80240718 27A50020 */  addiu     $a1, $sp, 0x20
/* DF711C 8024071C 24060040 */  addiu     $a2, $zero, 0x40
/* DF7120 80240720 3C10800A */  lui       $s0, %hi(D_8009A66C)
/* DF7124 80240724 2610A66C */  addiu     $s0, $s0, %lo(D_8009A66C)
/* DF7128 80240728 0280382D */  daddu     $a3, $s4, $zero
/* DF712C 8024072C 8E020000 */  lw        $v0, ($s0)
/* DF7130 80240730 96280000 */  lhu       $t0, ($s1)
/* DF7134 80240734 0040482D */  daddu     $t1, $v0, $zero
/* DF7138 80240738 24420008 */  addiu     $v0, $v0, 8
/* DF713C 8024073C AE020000 */  sw        $v0, ($s0)
/* DF7140 80240740 3102FFFF */  andi      $v0, $t0, 0xffff
/* DF7144 80240744 00021180 */  sll       $v0, $v0, 6
/* DF7148 80240748 00531021 */  addu      $v0, $v0, $s3
/* DF714C 8024074C AD230000 */  sw        $v1, ($t1)
/* DF7150 80240750 8E430000 */  lw        $v1, ($s2)
/* DF7154 80240754 25080001 */  addiu     $t0, $t0, 1
/* DF7158 80240758 00621821 */  addu      $v1, $v1, $v0
/* DF715C 8024075C 3C028000 */  lui       $v0, 0x8000
/* DF7160 80240760 00621821 */  addu      $v1, $v1, $v0
/* DF7164 80240764 AD230004 */  sw        $v1, 4($t1)
/* DF7168 80240768 93A20042 */  lbu       $v0, 0x42($sp)
/* DF716C 8024076C 8FA3003C */  lw        $v1, 0x3c($sp)
/* DF7170 80240770 93A90040 */  lbu       $t1, 0x40($sp)
/* DF7174 80240774 93AA0041 */  lbu       $t2, 0x41($sp)
/* DF7178 80240778 44820000 */  mtc1      $v0, $f0
/* DF717C 8024077C 00000000 */  nop       
/* DF7180 80240780 46800021 */  cvt.d.w   $f0, $f0
/* DF7184 80240784 8FA20038 */  lw        $v0, 0x38($sp)
/* DF7188 80240788 463A0002 */  mul.d     $f0, $f0, $f26
/* DF718C 8024078C 00000000 */  nop       
/* DF7190 80240790 A6280000 */  sh        $t0, ($s1)
/* DF7194 80240794 A7A0002E */  sh        $zero, 0x2e($sp)
/* DF7198 80240798 A3B50030 */  sb        $s5, 0x30($sp)
/* DF719C 8024079C AFA30024 */  sw        $v1, 0x24($sp)
/* DF71A0 802407A0 A7A90028 */  sh        $t1, 0x28($sp)
/* DF71A4 802407A4 A7AA002A */  sh        $t2, 0x2a($sp)
/* DF71A8 802407A8 AFA20020 */  sw        $v0, 0x20($sp)
/* DF71AC 802407AC 46200007 */  neg.d     $f0, $f0
/* DF71B0 802407B0 4620010D */  trunc.w.d $f4, $f0
/* DF71B4 802407B4 44022000 */  mfc1      $v0, $f4
/* DF71B8 802407B8 0C04EBDC */  jal       func_8013AF70
/* DF71BC 802407BC A7A2002C */   sh       $v0, 0x2c($sp)
/* DF71C0 802407C0 3C04D838 */  lui       $a0, 0xd838
/* DF71C4 802407C4 8E020000 */  lw        $v0, ($s0)
/* DF71C8 802407C8 34840002 */  ori       $a0, $a0, 2
/* DF71CC 802407CC 0040182D */  daddu     $v1, $v0, $zero
/* DF71D0 802407D0 24420008 */  addiu     $v0, $v0, 8
/* DF71D4 802407D4 AE020000 */  sw        $v0, ($s0)
/* DF71D8 802407D8 24020040 */  addiu     $v0, $zero, 0x40
/* DF71DC 802407DC AC640000 */  sw        $a0, ($v1)
/* DF71E0 802407E0 AC620004 */  sw        $v0, 4($v1)
/* DF71E4 802407E4 8FBF00E0 */  lw        $ra, 0xe0($sp)
/* DF71E8 802407E8 8FB500DC */  lw        $s5, 0xdc($sp)
/* DF71EC 802407EC 8FB400D8 */  lw        $s4, 0xd8($sp)
/* DF71F0 802407F0 8FB300D4 */  lw        $s3, 0xd4($sp)
/* DF71F4 802407F4 8FB200D0 */  lw        $s2, 0xd0($sp)
/* DF71F8 802407F8 8FB100CC */  lw        $s1, 0xcc($sp)
/* DF71FC 802407FC 8FB000C8 */  lw        $s0, 0xc8($sp)
/* DF7200 80240800 D7BC0108 */  ldc1      $f28, 0x108($sp)
/* DF7204 80240804 D7BA0100 */  ldc1      $f26, 0x100($sp)
/* DF7208 80240808 D7B800F8 */  ldc1      $f24, 0xf8($sp)
/* DF720C 8024080C D7B600F0 */  ldc1      $f22, 0xf0($sp)
/* DF7210 80240810 D7B400E8 */  ldc1      $f20, 0xe8($sp)
/* DF7214 80240814 03E00008 */  jr        $ra
/* DF7218 80240818 27BD0110 */   addiu    $sp, $sp, 0x110

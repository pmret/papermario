.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405F0_8AC580
/* 8AC580 802405F0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 8AC584 802405F4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 8AC588 802405F8 0080882D */  daddu     $s1, $a0, $zero
/* 8AC58C 802405FC AFB30024 */  sw        $s3, 0x24($sp)
/* 8AC590 80240600 AFBF0028 */  sw        $ra, 0x28($sp)
/* 8AC594 80240604 AFB20020 */  sw        $s2, 0x20($sp)
/* 8AC598 80240608 AFB00018 */  sw        $s0, 0x18($sp)
/* 8AC59C 8024060C F7B60038 */  sdc1      $f22, 0x38($sp)
/* 8AC5A0 80240610 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 8AC5A4 80240614 8E30000C */  lw        $s0, 0xc($s1)
/* 8AC5A8 80240618 10A00010 */  beqz      $a1, .L8024065C
/* 8AC5AC 8024061C 0000982D */   daddu    $s3, $zero, $zero
/* 8AC5B0 80240620 8E050000 */  lw        $a1, ($s0)
/* 8AC5B4 80240624 0C0B1EAF */  jal       evt_get_variable
/* 8AC5B8 80240628 26100004 */   addiu    $s0, $s0, 4
/* 8AC5BC 8024062C AE220074 */  sw        $v0, 0x74($s1)
/* 8AC5C0 80240630 8E050000 */  lw        $a1, ($s0)
/* 8AC5C4 80240634 26100004 */  addiu     $s0, $s0, 4
/* 8AC5C8 80240638 0C0B1EAF */  jal       evt_get_variable
/* 8AC5CC 8024063C 0220202D */   daddu    $a0, $s1, $zero
/* 8AC5D0 80240640 AE220078 */  sw        $v0, 0x78($s1)
/* 8AC5D4 80240644 8E050000 */  lw        $a1, ($s0)
/* 8AC5D8 80240648 0C0B1EAF */  jal       evt_get_variable
/* 8AC5DC 8024064C 0220202D */   daddu    $a0, $s1, $zero
/* 8AC5E0 80240650 AE2200C0 */  sw        $v0, 0xc0($s1)
/* 8AC5E4 80240654 AE200070 */  sw        $zero, 0x70($s1)
/* 8AC5E8 80240658 AE20007C */  sw        $zero, 0x7c($s1)
.L8024065C:
/* 8AC5EC 8024065C 8E240074 */  lw        $a0, 0x74($s1)
/* 8AC5F0 80240660 0C00EABB */  jal       get_npc_unsafe
/* 8AC5F4 80240664 24120001 */   addiu    $s2, $zero, 1
/* 8AC5F8 80240668 8E230070 */  lw        $v1, 0x70($s1)
/* 8AC5FC 8024066C 1072005D */  beq       $v1, $s2, .L802407E4
/* 8AC600 80240670 0040802D */   daddu    $s0, $v0, $zero
/* 8AC604 80240674 28620002 */  slti      $v0, $v1, 2
/* 8AC608 80240678 10400005 */  beqz      $v0, .L80240690
/* 8AC60C 8024067C 24020002 */   addiu    $v0, $zero, 2
/* 8AC610 80240680 10600009 */  beqz      $v1, .L802406A8
/* 8AC614 80240684 26040038 */   addiu    $a0, $s0, 0x38
/* 8AC618 80240688 080902E5 */  j         .L80240B94
/* 8AC61C 8024068C 00000000 */   nop
.L80240690:
/* 8AC620 80240690 1062009C */  beq       $v1, $v0, .L80240904
/* 8AC624 80240694 24020003 */   addiu    $v0, $zero, 3
/* 8AC628 80240698 106200EF */  beq       $v1, $v0, .L80240A58
/* 8AC62C 8024069C 26040038 */   addiu    $a0, $s0, 0x38
/* 8AC630 802406A0 080902E5 */  j         .L80240B94
/* 8AC634 802406A4 00000000 */   nop
.L802406A8:
/* 8AC638 802406A8 3C01C47A */  lui       $at, 0xc47a
/* 8AC63C 802406AC 44810000 */  mtc1      $at, $f0
/* 8AC640 802406B0 3C01C248 */  lui       $at, 0xc248
/* 8AC644 802406B4 4481B000 */  mtc1      $at, $f22
/* 8AC648 802406B8 AE000038 */  sw        $zero, 0x38($s0)
/* 8AC64C 802406BC E600003C */  swc1      $f0, 0x3c($s0)
/* 8AC650 802406C0 E6160040 */  swc1      $f22, 0x40($s0)
/* 8AC654 802406C4 8E23007C */  lw        $v1, 0x7c($s1)
/* 8AC658 802406C8 3C014040 */  lui       $at, 0x4040
/* 8AC65C 802406CC 44810000 */  mtc1      $at, $f0
/* 8AC660 802406D0 00031040 */  sll       $v0, $v1, 1
/* 8AC664 802406D4 00431021 */  addu      $v0, $v0, $v1
/* 8AC668 802406D8 E6000064 */  swc1      $f0, 0x64($s0)
/* 8AC66C 802406DC 44820000 */  mtc1      $v0, $f0
/* 8AC670 802406E0 00000000 */  nop
/* 8AC674 802406E4 46800020 */  cvt.s.w   $f0, $f0
/* 8AC678 802406E8 E6000060 */  swc1      $f0, 0x60($s0)
/* 8AC67C 802406EC 8E22007C */  lw        $v0, 0x7c($s1)
/* 8AC680 802406F0 8E2300C0 */  lw        $v1, 0xc0($s1)
/* 8AC684 802406F4 0043102A */  slt       $v0, $v0, $v1
/* 8AC688 802406F8 14400126 */  bnez      $v0, .L80240B94
/* 8AC68C 802406FC 26050040 */   addiu    $a1, $s0, 0x40
/* 8AC690 80240700 3C0142C8 */  lui       $at, 0x42c8
/* 8AC694 80240704 44810000 */  mtc1      $at, $f0
/* 8AC698 80240708 00000000 */  nop
/* 8AC69C 8024070C E600003C */  swc1      $f0, 0x3c($s0)
/* 8AC6A0 80240710 8E230078 */  lw        $v1, 0x78($s1)
/* 8AC6A4 80240714 C6020060 */  lwc1      $f2, 0x60($s0)
/* 8AC6A8 80240718 00031040 */  sll       $v0, $v1, 1
/* 8AC6AC 8024071C 00431021 */  addu      $v0, $v0, $v1
/* 8AC6B0 80240720 00021900 */  sll       $v1, $v0, 4
/* 8AC6B4 80240724 00431021 */  addu      $v0, $v0, $v1
/* 8AC6B8 80240728 44820000 */  mtc1      $v0, $f0
/* 8AC6BC 8024072C 00000000 */  nop
/* 8AC6C0 80240730 46800020 */  cvt.s.w   $f0, $f0
/* 8AC6C4 80240734 46001080 */  add.s     $f2, $f2, $f0
/* 8AC6C8 80240738 3C014319 */  lui       $at, 0x4319
/* 8AC6CC 8024073C 44810000 */  mtc1      $at, $f0
/* 8AC6D0 80240740 3C01428C */  lui       $at, 0x428c
/* 8AC6D4 80240744 4481A000 */  mtc1      $at, $f20
/* 8AC6D8 80240748 46001080 */  add.s     $f2, $f2, $f0
/* 8AC6DC 8024074C 4406A000 */  mfc1      $a2, $f20
/* 8AC6E0 80240750 44071000 */  mfc1      $a3, $f2
/* 8AC6E4 80240754 0C00A7E7 */  jal       add_vec2D_polar
/* 8AC6E8 80240758 00000000 */   nop
/* 8AC6EC 8024075C C6000040 */  lwc1      $f0, 0x40($s0)
/* 8AC6F0 80240760 46000007 */  neg.s     $f0, $f0
/* 8AC6F4 80240764 46160000 */  add.s     $f0, $f0, $f22
/* 8AC6F8 80240768 46140000 */  add.s     $f0, $f0, $f20
/* 8AC6FC 8024076C 3C013E19 */  lui       $at, 0x3e19
/* 8AC700 80240770 3421999A */  ori       $at, $at, 0x999a
/* 8AC704 80240774 44811000 */  mtc1      $at, $f2
/* 8AC708 80240778 00000000 */  nop
/* 8AC70C 8024077C 46020002 */  mul.s     $f0, $f0, $f2
/* 8AC710 80240780 00000000 */  nop
/* 8AC714 80240784 C602003C */  lwc1      $f2, 0x3c($s0)
/* 8AC718 80240788 3C04B000 */  lui       $a0, 0xb000
/* 8AC71C 8024078C 46001080 */  add.s     $f2, $f2, $f0
/* 8AC720 80240790 C6000040 */  lwc1      $f0, 0x40($s0)
/* 8AC724 80240794 3484001E */  ori       $a0, $a0, 0x1e
/* 8AC728 80240798 E602003C */  swc1      $f2, 0x3c($s0)
/* 8AC72C 8024079C E7A00010 */  swc1      $f0, 0x10($sp)
/* 8AC730 802407A0 8E060038 */  lw        $a2, 0x38($s0)
/* 8AC734 802407A4 8E07003C */  lw        $a3, 0x3c($s0)
/* 8AC738 802407A8 0C052757 */  jal       sfx_play_sound_at_position
/* 8AC73C 802407AC 0000282D */   daddu    $a1, $zero, $zero
/* 8AC740 802407B0 C602003C */  lwc1      $f2, 0x3c($s0)
/* 8AC744 802407B4 3C0141A0 */  lui       $at, 0x41a0
/* 8AC748 802407B8 44810000 */  mtc1      $at, $f0
/* 8AC74C 802407BC 00000000 */  nop
/* 8AC750 802407C0 46001080 */  add.s     $f2, $f2, $f0
/* 8AC754 802407C4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8AC758 802407C8 8E050038 */  lw        $a1, 0x38($s0)
/* 8AC75C 802407CC 8E070040 */  lw        $a3, 0x40($s0)
/* 8AC760 802407D0 44061000 */  mfc1      $a2, $f2
/* 8AC764 802407D4 0C01BFBC */  jal       fx_sparkles
/* 8AC768 802407D8 0000202D */   daddu    $a0, $zero, $zero
/* 8AC76C 802407DC 080902E5 */  j         .L80240B94
/* 8AC770 802407E0 AE320070 */   sw       $s2, 0x70($s1)
.L802407E4:
/* 8AC774 802407E4 3C01C248 */  lui       $at, 0xc248
/* 8AC778 802407E8 4481B000 */  mtc1      $at, $f22
/* 8AC77C 802407EC 3C0142C8 */  lui       $at, 0x42c8
/* 8AC780 802407F0 44810000 */  mtc1      $at, $f0
/* 8AC784 802407F4 AE000038 */  sw        $zero, 0x38($s0)
/* 8AC788 802407F8 E6160040 */  swc1      $f22, 0x40($s0)
/* 8AC78C 802407FC E600003C */  swc1      $f0, 0x3c($s0)
/* 8AC790 80240800 8E230078 */  lw        $v1, 0x78($s1)
/* 8AC794 80240804 C6020060 */  lwc1      $f2, 0x60($s0)
/* 8AC798 80240808 00031040 */  sll       $v0, $v1, 1
/* 8AC79C 8024080C 00431021 */  addu      $v0, $v0, $v1
/* 8AC7A0 80240810 00021900 */  sll       $v1, $v0, 4
/* 8AC7A4 80240814 00431021 */  addu      $v0, $v0, $v1
/* 8AC7A8 80240818 44820000 */  mtc1      $v0, $f0
/* 8AC7AC 8024081C 00000000 */  nop
/* 8AC7B0 80240820 46800020 */  cvt.s.w   $f0, $f0
/* 8AC7B4 80240824 46001080 */  add.s     $f2, $f2, $f0
/* 8AC7B8 80240828 3C014319 */  lui       $at, 0x4319
/* 8AC7BC 8024082C 44810000 */  mtc1      $at, $f0
/* 8AC7C0 80240830 3C01428C */  lui       $at, 0x428c
/* 8AC7C4 80240834 4481A000 */  mtc1      $at, $f20
/* 8AC7C8 80240838 46001080 */  add.s     $f2, $f2, $f0
/* 8AC7CC 8024083C 26040038 */  addiu     $a0, $s0, 0x38
/* 8AC7D0 80240840 4406A000 */  mfc1      $a2, $f20
/* 8AC7D4 80240844 44071000 */  mfc1      $a3, $f2
/* 8AC7D8 80240848 0C00A7E7 */  jal       add_vec2D_polar
/* 8AC7DC 8024084C 26050040 */   addiu    $a1, $s0, 0x40
/* 8AC7E0 80240850 C6000040 */  lwc1      $f0, 0x40($s0)
/* 8AC7E4 80240854 46000007 */  neg.s     $f0, $f0
/* 8AC7E8 80240858 46160000 */  add.s     $f0, $f0, $f22
/* 8AC7EC 8024085C 46140000 */  add.s     $f0, $f0, $f20
/* 8AC7F0 80240860 3C013E19 */  lui       $at, 0x3e19
/* 8AC7F4 80240864 3421999A */  ori       $at, $at, 0x999a
/* 8AC7F8 80240868 44811000 */  mtc1      $at, $f2
/* 8AC7FC 8024086C 00000000 */  nop
/* 8AC800 80240870 46020002 */  mul.s     $f0, $f0, $f2
/* 8AC804 80240874 00000000 */  nop
/* 8AC808 80240878 C602003C */  lwc1      $f2, 0x3c($s0)
/* 8AC80C 8024087C 46001080 */  add.s     $f2, $f2, $f0
/* 8AC810 80240880 3C034EC4 */  lui       $v1, 0x4ec4
/* 8AC814 80240884 E602003C */  swc1      $f2, 0x3c($s0)
/* 8AC818 80240888 8E24007C */  lw        $a0, 0x7c($s1)
/* 8AC81C 8024088C 8E220078 */  lw        $v0, 0x78($s1)
/* 8AC820 80240890 3463EC4F */  ori       $v1, $v1, 0xec4f
/* 8AC824 80240894 00822021 */  addu      $a0, $a0, $v0
/* 8AC828 80240898 00830018 */  mult      $a0, $v1
/* 8AC82C 8024089C 000417C3 */  sra       $v0, $a0, 0x1f
/* 8AC830 802408A0 00004010 */  mfhi      $t0
/* 8AC834 802408A4 00081883 */  sra       $v1, $t0, 2
/* 8AC838 802408A8 00621823 */  subu      $v1, $v1, $v0
/* 8AC83C 802408AC 00031040 */  sll       $v0, $v1, 1
/* 8AC840 802408B0 00431021 */  addu      $v0, $v0, $v1
/* 8AC844 802408B4 00021080 */  sll       $v0, $v0, 2
/* 8AC848 802408B8 00431021 */  addu      $v0, $v0, $v1
/* 8AC84C 802408BC 1482000B */  bne       $a0, $v0, .L802408EC
/* 8AC850 802408C0 00000000 */   nop
/* 8AC854 802408C4 3C014120 */  lui       $at, 0x4120
/* 8AC858 802408C8 44810000 */  mtc1      $at, $f0
/* 8AC85C 802408CC 00000000 */  nop
/* 8AC860 802408D0 46001080 */  add.s     $f2, $f2, $f0
/* 8AC864 802408D4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8AC868 802408D8 8E050038 */  lw        $a1, 0x38($s0)
/* 8AC86C 802408DC 8E070040 */  lw        $a3, 0x40($s0)
/* 8AC870 802408E0 44061000 */  mfc1      $a2, $f2
/* 8AC874 802408E4 0C01BFBC */  jal       fx_sparkles
/* 8AC878 802408E8 24040003 */   addiu    $a0, $zero, 3
.L802408EC:
/* 8AC87C 802408EC 8E22007C */  lw        $v0, 0x7c($s1)
/* 8AC880 802408F0 28420101 */  slti      $v0, $v0, 0x101
/* 8AC884 802408F4 144000A7 */  bnez      $v0, .L80240B94
/* 8AC888 802408F8 24020002 */   addiu    $v0, $zero, 2
/* 8AC88C 802408FC 08090294 */  j         .L80240A50
/* 8AC890 80240900 AE220070 */   sw       $v0, 0x70($s1)
.L80240904:
/* 8AC894 80240904 3C01C248 */  lui       $at, 0xc248
/* 8AC898 80240908 4481B000 */  mtc1      $at, $f22
/* 8AC89C 8024090C 3C013E99 */  lui       $at, 0x3e99
/* 8AC8A0 80240910 3421999A */  ori       $at, $at, 0x999a
/* 8AC8A4 80240914 44810000 */  mtc1      $at, $f0
/* 8AC8A8 80240918 AE000038 */  sw        $zero, 0x38($s0)
/* 8AC8AC 8024091C E6160040 */  swc1      $f22, 0x40($s0)
/* 8AC8B0 80240920 C62200BC */  lwc1      $f2, 0xbc($s1)
/* 8AC8B4 80240924 468010A0 */  cvt.s.w   $f2, $f2
/* 8AC8B8 80240928 46001082 */  mul.s     $f2, $f2, $f0
/* 8AC8BC 8024092C 00000000 */  nop
/* 8AC8C0 80240930 3C0142C8 */  lui       $at, 0x42c8
/* 8AC8C4 80240934 44810000 */  mtc1      $at, $f0
/* 8AC8C8 80240938 00000000 */  nop
/* 8AC8CC 8024093C 46020001 */  sub.s     $f0, $f0, $f2
/* 8AC8D0 80240940 E600003C */  swc1      $f0, 0x3c($s0)
/* 8AC8D4 80240944 8E230078 */  lw        $v1, 0x78($s1)
/* 8AC8D8 80240948 C6020060 */  lwc1      $f2, 0x60($s0)
/* 8AC8DC 8024094C 00031040 */  sll       $v0, $v1, 1
/* 8AC8E0 80240950 00431021 */  addu      $v0, $v0, $v1
/* 8AC8E4 80240954 00021900 */  sll       $v1, $v0, 4
/* 8AC8E8 80240958 00431021 */  addu      $v0, $v0, $v1
/* 8AC8EC 8024095C 44820000 */  mtc1      $v0, $f0
/* 8AC8F0 80240960 00000000 */  nop
/* 8AC8F4 80240964 46800020 */  cvt.s.w   $f0, $f0
/* 8AC8F8 80240968 46001080 */  add.s     $f2, $f2, $f0
/* 8AC8FC 8024096C 3C014319 */  lui       $at, 0x4319
/* 8AC900 80240970 44810000 */  mtc1      $at, $f0
/* 8AC904 80240974 3C01428C */  lui       $at, 0x428c
/* 8AC908 80240978 4481A000 */  mtc1      $at, $f20
/* 8AC90C 8024097C 46001080 */  add.s     $f2, $f2, $f0
/* 8AC910 80240980 26040038 */  addiu     $a0, $s0, 0x38
/* 8AC914 80240984 4406A000 */  mfc1      $a2, $f20
/* 8AC918 80240988 44071000 */  mfc1      $a3, $f2
/* 8AC91C 8024098C 0C00A7E7 */  jal       add_vec2D_polar
/* 8AC920 80240990 26050040 */   addiu    $a1, $s0, 0x40
/* 8AC924 80240994 C6000040 */  lwc1      $f0, 0x40($s0)
/* 8AC928 80240998 46000007 */  neg.s     $f0, $f0
/* 8AC92C 8024099C 46160000 */  add.s     $f0, $f0, $f22
/* 8AC930 802409A0 46140000 */  add.s     $f0, $f0, $f20
/* 8AC934 802409A4 3C013E19 */  lui       $at, 0x3e19
/* 8AC938 802409A8 3421999A */  ori       $at, $at, 0x999a
/* 8AC93C 802409AC 44811000 */  mtc1      $at, $f2
/* 8AC940 802409B0 00000000 */  nop
/* 8AC944 802409B4 46020002 */  mul.s     $f0, $f0, $f2
/* 8AC948 802409B8 00000000 */  nop
/* 8AC94C 802409BC C602003C */  lwc1      $f2, 0x3c($s0)
/* 8AC950 802409C0 46001080 */  add.s     $f2, $f2, $f0
/* 8AC954 802409C4 3C034EC4 */  lui       $v1, 0x4ec4
/* 8AC958 802409C8 E602003C */  swc1      $f2, 0x3c($s0)
/* 8AC95C 802409CC 8E24007C */  lw        $a0, 0x7c($s1)
/* 8AC960 802409D0 8E220078 */  lw        $v0, 0x78($s1)
/* 8AC964 802409D4 3463EC4F */  ori       $v1, $v1, 0xec4f
/* 8AC968 802409D8 00822021 */  addu      $a0, $a0, $v0
/* 8AC96C 802409DC 00830018 */  mult      $a0, $v1
/* 8AC970 802409E0 000417C3 */  sra       $v0, $a0, 0x1f
/* 8AC974 802409E4 00004010 */  mfhi      $t0
/* 8AC978 802409E8 00081883 */  sra       $v1, $t0, 2
/* 8AC97C 802409EC 00621823 */  subu      $v1, $v1, $v0
/* 8AC980 802409F0 00031040 */  sll       $v0, $v1, 1
/* 8AC984 802409F4 00431021 */  addu      $v0, $v0, $v1
/* 8AC988 802409F8 00021080 */  sll       $v0, $v0, 2
/* 8AC98C 802409FC 00431021 */  addu      $v0, $v0, $v1
/* 8AC990 80240A00 1482000B */  bne       $a0, $v0, .L80240A30
/* 8AC994 80240A04 00000000 */   nop
/* 8AC998 80240A08 3C014120 */  lui       $at, 0x4120
/* 8AC99C 80240A0C 44810000 */  mtc1      $at, $f0
/* 8AC9A0 80240A10 00000000 */  nop
/* 8AC9A4 80240A14 46001080 */  add.s     $f2, $f2, $f0
/* 8AC9A8 80240A18 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8AC9AC 80240A1C 8E050038 */  lw        $a1, 0x38($s0)
/* 8AC9B0 80240A20 8E070040 */  lw        $a3, 0x40($s0)
/* 8AC9B4 80240A24 44061000 */  mfc1      $a2, $f2
/* 8AC9B8 80240A28 0C01BFBC */  jal       fx_sparkles
/* 8AC9BC 80240A2C 24040003 */   addiu    $a0, $zero, 3
.L80240A30:
/* 8AC9C0 80240A30 8E2200BC */  lw        $v0, 0xbc($s1)
/* 8AC9C4 80240A34 0040182D */  daddu     $v1, $v0, $zero
/* 8AC9C8 80240A38 24420001 */  addiu     $v0, $v0, 1
/* 8AC9CC 80240A3C 286300B5 */  slti      $v1, $v1, 0xb5
/* 8AC9D0 80240A40 14600054 */  bnez      $v1, .L80240B94
/* 8AC9D4 80240A44 AE2200BC */   sw       $v0, 0xbc($s1)
/* 8AC9D8 80240A48 24020003 */  addiu     $v0, $zero, 3
/* 8AC9DC 80240A4C AE220070 */  sw        $v0, 0x70($s1)
.L80240A50:
/* 8AC9E0 80240A50 080902E5 */  j         .L80240B94
/* 8AC9E4 80240A54 AE2000BC */   sw       $zero, 0xbc($s1)
.L80240A58:
/* 8AC9E8 80240A58 C6000064 */  lwc1      $f0, 0x64($s0)
/* 8AC9EC 80240A5C 3C013CF5 */  lui       $at, 0x3cf5
/* 8AC9F0 80240A60 3421C28F */  ori       $at, $at, 0xc28f
/* 8AC9F4 80240A64 44811000 */  mtc1      $at, $f2
/* 8AC9F8 80240A68 3C01C248 */  lui       $at, 0xc248
/* 8AC9FC 80240A6C 4481B000 */  mtc1      $at, $f22
/* 8ACA00 80240A70 3C014237 */  lui       $at, 0x4237
/* 8ACA04 80240A74 3421FFFF */  ori       $at, $at, 0xffff
/* 8ACA08 80240A78 44812000 */  mtc1      $at, $f4
/* 8ACA0C 80240A7C AE000038 */  sw        $zero, 0x38($s0)
/* 8ACA10 80240A80 46020001 */  sub.s     $f0, $f0, $f2
/* 8ACA14 80240A84 E6160040 */  swc1      $f22, 0x40($s0)
/* 8ACA18 80240A88 E604003C */  swc1      $f4, 0x3c($s0)
/* 8ACA1C 80240A8C E6000064 */  swc1      $f0, 0x64($s0)
/* 8ACA20 80240A90 8E230078 */  lw        $v1, 0x78($s1)
/* 8ACA24 80240A94 C6020060 */  lwc1      $f2, 0x60($s0)
/* 8ACA28 80240A98 00031040 */  sll       $v0, $v1, 1
/* 8ACA2C 80240A9C 00431021 */  addu      $v0, $v0, $v1
/* 8ACA30 80240AA0 00021900 */  sll       $v1, $v0, 4
/* 8ACA34 80240AA4 00431021 */  addu      $v0, $v0, $v1
/* 8ACA38 80240AA8 44820000 */  mtc1      $v0, $f0
/* 8ACA3C 80240AAC 00000000 */  nop
/* 8ACA40 80240AB0 46800020 */  cvt.s.w   $f0, $f0
/* 8ACA44 80240AB4 46001080 */  add.s     $f2, $f2, $f0
/* 8ACA48 80240AB8 3C014319 */  lui       $at, 0x4319
/* 8ACA4C 80240ABC 44810000 */  mtc1      $at, $f0
/* 8ACA50 80240AC0 3C01428C */  lui       $at, 0x428c
/* 8ACA54 80240AC4 4481A000 */  mtc1      $at, $f20
/* 8ACA58 80240AC8 46001080 */  add.s     $f2, $f2, $f0
/* 8ACA5C 80240ACC 4406A000 */  mfc1      $a2, $f20
/* 8ACA60 80240AD0 44071000 */  mfc1      $a3, $f2
/* 8ACA64 80240AD4 0C00A7E7 */  jal       add_vec2D_polar
/* 8ACA68 80240AD8 26050040 */   addiu    $a1, $s0, 0x40
/* 8ACA6C 80240ADC C6000040 */  lwc1      $f0, 0x40($s0)
/* 8ACA70 80240AE0 46000007 */  neg.s     $f0, $f0
/* 8ACA74 80240AE4 46160000 */  add.s     $f0, $f0, $f22
/* 8ACA78 80240AE8 46140000 */  add.s     $f0, $f0, $f20
/* 8ACA7C 80240AEC 3C013E19 */  lui       $at, 0x3e19
/* 8ACA80 80240AF0 3421999A */  ori       $at, $at, 0x999a
/* 8ACA84 80240AF4 44811000 */  mtc1      $at, $f2
/* 8ACA88 80240AF8 00000000 */  nop
/* 8ACA8C 80240AFC 46020002 */  mul.s     $f0, $f0, $f2
/* 8ACA90 80240B00 00000000 */  nop
/* 8ACA94 80240B04 C602003C */  lwc1      $f2, 0x3c($s0)
/* 8ACA98 80240B08 46001080 */  add.s     $f2, $f2, $f0
/* 8ACA9C 80240B0C 3C034EC4 */  lui       $v1, 0x4ec4
/* 8ACAA0 80240B10 E602003C */  swc1      $f2, 0x3c($s0)
/* 8ACAA4 80240B14 8E24007C */  lw        $a0, 0x7c($s1)
/* 8ACAA8 80240B18 8E220078 */  lw        $v0, 0x78($s1)
/* 8ACAAC 80240B1C 3463EC4F */  ori       $v1, $v1, 0xec4f
/* 8ACAB0 80240B20 00822021 */  addu      $a0, $a0, $v0
/* 8ACAB4 80240B24 00830018 */  mult      $a0, $v1
/* 8ACAB8 80240B28 000417C3 */  sra       $v0, $a0, 0x1f
/* 8ACABC 80240B2C 00004010 */  mfhi      $t0
/* 8ACAC0 80240B30 00081883 */  sra       $v1, $t0, 2
/* 8ACAC4 80240B34 00621823 */  subu      $v1, $v1, $v0
/* 8ACAC8 80240B38 00031040 */  sll       $v0, $v1, 1
/* 8ACACC 80240B3C 00431021 */  addu      $v0, $v0, $v1
/* 8ACAD0 80240B40 00021080 */  sll       $v0, $v0, 2
/* 8ACAD4 80240B44 00431021 */  addu      $v0, $v0, $v1
/* 8ACAD8 80240B48 1482000B */  bne       $a0, $v0, .L80240B78
/* 8ACADC 80240B4C 00000000 */   nop
/* 8ACAE0 80240B50 3C014120 */  lui       $at, 0x4120
/* 8ACAE4 80240B54 44810000 */  mtc1      $at, $f0
/* 8ACAE8 80240B58 00000000 */  nop
/* 8ACAEC 80240B5C 46001080 */  add.s     $f2, $f2, $f0
/* 8ACAF0 80240B60 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8ACAF4 80240B64 8E050038 */  lw        $a1, 0x38($s0)
/* 8ACAF8 80240B68 8E070040 */  lw        $a3, 0x40($s0)
/* 8ACAFC 80240B6C 44061000 */  mfc1      $a2, $f2
/* 8ACB00 80240B70 0C01BFBC */  jal       fx_sparkles
/* 8ACB04 80240B74 24040003 */   addiu    $a0, $zero, 3
.L80240B78:
/* 8ACB08 80240B78 C6020064 */  lwc1      $f2, 0x64($s0)
/* 8ACB0C 80240B7C 44800000 */  mtc1      $zero, $f0
/* 8ACB10 80240B80 00000000 */  nop
/* 8ACB14 80240B84 4600103C */  c.lt.s    $f2, $f0
/* 8ACB18 80240B88 00000000 */  nop
/* 8ACB1C 80240B8C 45030001 */  bc1tl     .L80240B94
/* 8ACB20 80240B90 24130002 */   addiu    $s3, $zero, 2
.L80240B94:
/* 8ACB24 80240B94 8E22007C */  lw        $v0, 0x7c($s1)
/* 8ACB28 80240B98 24420001 */  addiu     $v0, $v0, 1
/* 8ACB2C 80240B9C AE22007C */  sw        $v0, 0x7c($s1)
/* 8ACB30 80240BA0 C6000060 */  lwc1      $f0, 0x60($s0)
/* 8ACB34 80240BA4 C6020064 */  lwc1      $f2, 0x64($s0)
/* 8ACB38 80240BA8 46020000 */  add.s     $f0, $f0, $f2
/* 8ACB3C 80240BAC 0260102D */  daddu     $v0, $s3, $zero
/* 8ACB40 80240BB0 E6000060 */  swc1      $f0, 0x60($s0)
/* 8ACB44 80240BB4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 8ACB48 80240BB8 8FB30024 */  lw        $s3, 0x24($sp)
/* 8ACB4C 80240BBC 8FB20020 */  lw        $s2, 0x20($sp)
/* 8ACB50 80240BC0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8ACB54 80240BC4 8FB00018 */  lw        $s0, 0x18($sp)
/* 8ACB58 80240BC8 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 8ACB5C 80240BCC D7B40030 */  ldc1      $f20, 0x30($sp)
/* 8ACB60 80240BD0 03E00008 */  jr        $ra
/* 8ACB64 80240BD4 27BD0040 */   addiu    $sp, $sp, 0x40

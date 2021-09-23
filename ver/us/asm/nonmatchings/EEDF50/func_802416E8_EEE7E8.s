.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416E8_EEE7E8
/* EEE7E8 802416E8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* EEE7EC 802416EC AFB3004C */  sw        $s3, 0x4c($sp)
/* EEE7F0 802416F0 0080982D */  daddu     $s3, $a0, $zero
/* EEE7F4 802416F4 AFBF0054 */  sw        $ra, 0x54($sp)
/* EEE7F8 802416F8 AFB40050 */  sw        $s4, 0x50($sp)
/* EEE7FC 802416FC AFB20048 */  sw        $s2, 0x48($sp)
/* EEE800 80241700 AFB10044 */  sw        $s1, 0x44($sp)
/* EEE804 80241704 AFB00040 */  sw        $s0, 0x40($sp)
/* EEE808 80241708 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* EEE80C 8024170C F7B80068 */  sdc1      $f24, 0x68($sp)
/* EEE810 80241710 F7B60060 */  sdc1      $f22, 0x60($sp)
/* EEE814 80241714 F7B40058 */  sdc1      $f20, 0x58($sp)
/* EEE818 80241718 8E710148 */  lw        $s1, 0x148($s3)
/* EEE81C 8024171C 00A0902D */  daddu     $s2, $a1, $zero
/* EEE820 80241720 86240008 */  lh        $a0, 8($s1)
/* EEE824 80241724 0C00F92F */  jal       dead_get_npc_unsafe
/* EEE828 80241728 00C0A02D */   daddu    $s4, $a2, $zero
/* EEE82C 8024172C 0040802D */  daddu     $s0, $v0, $zero
/* EEE830 80241730 C6200078 */  lwc1      $f0, 0x78($s1)
/* EEE834 80241734 46800020 */  cvt.s.w   $f0, $f0
/* EEE838 80241738 46000021 */  cvt.d.s   $f0, $f0
/* EEE83C 8024173C 3C014059 */  lui       $at, 0x4059
/* EEE840 80241740 44811800 */  mtc1      $at, $f3
/* EEE844 80241744 44801000 */  mtc1      $zero, $f2
/* EEE848 80241748 8602008E */  lh        $v0, 0x8e($s0)
/* EEE84C 8024174C 9603008E */  lhu       $v1, 0x8e($s0)
/* EEE850 80241750 46220003 */  div.d     $f0, $f0, $f2
/* EEE854 80241754 46200620 */  cvt.s.d   $f24, $f0
/* EEE858 80241758 C6200088 */  lwc1      $f0, 0x88($s1)
/* EEE85C 8024175C 46800020 */  cvt.s.w   $f0, $f0
/* EEE860 80241760 46000021 */  cvt.d.s   $f0, $f0
/* EEE864 80241764 46220003 */  div.d     $f0, $f0, $f2
/* EEE868 80241768 46200020 */  cvt.s.d   $f0, $f0
/* EEE86C 8024176C 18400003 */  blez      $v0, .L8024177C
/* EEE870 80241770 4600C680 */   add.s    $f26, $f24, $f0
/* EEE874 80241774 2462FFFF */  addiu     $v0, $v1, -1
/* EEE878 80241778 A602008E */  sh        $v0, 0x8e($s0)
.L8024177C:
/* EEE87C 8024177C 8E220070 */  lw        $v0, 0x70($s1)
/* EEE880 80241780 18400034 */  blez      $v0, .L80241854
/* EEE884 80241784 00000000 */   nop
/* EEE888 80241788 C62C0074 */  lwc1      $f12, 0x74($s1)
/* EEE88C 8024178C 46806320 */  cvt.s.w   $f12, $f12
/* EEE890 80241790 44820000 */  mtc1      $v0, $f0
/* EEE894 80241794 00000000 */  nop
/* EEE898 80241798 46800020 */  cvt.s.w   $f0, $f0
/* EEE89C 8024179C 46000021 */  cvt.d.s   $f0, $f0
/* EEE8A0 802417A0 46220003 */  div.d     $f0, $f0, $f2
/* EEE8A4 802417A4 0C00AD77 */  jal       dead_sin_deg
/* EEE8A8 802417A8 462005A0 */   cvt.s.d  $f22, $f0
/* EEE8AC 802417AC 8E020000 */  lw        $v0, ($s0)
/* EEE8B0 802417B0 30420008 */  andi      $v0, $v0, 8
/* EEE8B4 802417B4 10400003 */  beqz      $v0, .L802417C4
/* EEE8B8 802417B8 46000506 */   mov.s    $f20, $f0
/* EEE8BC 802417BC 08090601 */  j         .L80241804
/* EEE8C0 802417C0 0000102D */   daddu    $v0, $zero, $zero
.L802417C4:
/* EEE8C4 802417C4 27A50028 */  addiu     $a1, $sp, 0x28
/* EEE8C8 802417C8 27A6002C */  addiu     $a2, $sp, 0x2c
/* EEE8CC 802417CC C6000038 */  lwc1      $f0, 0x38($s0)
/* EEE8D0 802417D0 C602003C */  lwc1      $f2, 0x3c($s0)
/* EEE8D4 802417D4 C6040040 */  lwc1      $f4, 0x40($s0)
/* EEE8D8 802417D8 3C01447A */  lui       $at, 0x447a
/* EEE8DC 802417DC 44813000 */  mtc1      $at, $f6
/* EEE8E0 802417E0 27A20034 */  addiu     $v0, $sp, 0x34
/* EEE8E4 802417E4 E7A00028 */  swc1      $f0, 0x28($sp)
/* EEE8E8 802417E8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* EEE8EC 802417EC E7A40030 */  swc1      $f4, 0x30($sp)
/* EEE8F0 802417F0 E7A60034 */  swc1      $f6, 0x34($sp)
/* EEE8F4 802417F4 AFA20010 */  sw        $v0, 0x10($sp)
/* EEE8F8 802417F8 8E040080 */  lw        $a0, 0x80($s0)
/* EEE8FC 802417FC 0C03908F */  jal       dead_npc_raycast_down_sides
/* EEE900 80241800 27A70030 */   addiu    $a3, $sp, 0x30
.L80241804:
/* EEE904 80241804 10400007 */  beqz      $v0, .L80241824
/* EEE908 80241808 00000000 */   nop
/* EEE90C 8024180C 4616A082 */  mul.s     $f2, $f20, $f22
/* EEE910 80241810 00000000 */  nop
/* EEE914 80241814 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* EEE918 80241818 46180000 */  add.s     $f0, $f0, $f24
/* EEE91C 8024181C 0809060C */  j         .L80241830
/* EEE920 80241820 46020000 */   add.s    $f0, $f0, $f2
.L80241824:
/* EEE924 80241824 4616A002 */  mul.s     $f0, $f20, $f22
/* EEE928 80241828 00000000 */  nop
/* EEE92C 8024182C 4600D000 */  add.s     $f0, $f26, $f0
.L80241830:
/* EEE930 80241830 E600003C */  swc1      $f0, 0x3c($s0)
/* EEE934 80241834 8E220074 */  lw        $v0, 0x74($s1)
/* EEE938 80241838 2442000A */  addiu     $v0, $v0, 0xa
/* EEE93C 8024183C 44826000 */  mtc1      $v0, $f12
/* EEE940 80241840 00000000 */  nop
/* EEE944 80241844 0C00AB85 */  jal       dead_clamp_angle
/* EEE948 80241848 46806320 */   cvt.s.w  $f12, $f12
/* EEE94C 8024184C 4600020D */  trunc.w.s $f8, $f0
/* EEE950 80241850 E6280074 */  swc1      $f8, 0x74($s1)
.L80241854:
/* EEE954 80241854 8E220090 */  lw        $v0, 0x90($s1)
/* EEE958 80241858 1C400040 */  bgtz      $v0, .L8024195C
/* EEE95C 8024185C 2442FFFF */   addiu    $v0, $v0, -1
/* EEE960 80241860 860200A8 */  lh        $v0, 0xa8($s0)
/* EEE964 80241864 C600003C */  lwc1      $f0, 0x3c($s0)
/* EEE968 80241868 44821000 */  mtc1      $v0, $f2
/* EEE96C 8024186C 00000000 */  nop
/* EEE970 80241870 468010A0 */  cvt.s.w   $f2, $f2
/* EEE974 80241874 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EEE978 80241878 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EEE97C 8024187C 46020000 */  add.s     $f0, $f0, $f2
/* EEE980 80241880 3C014024 */  lui       $at, 0x4024
/* EEE984 80241884 44812800 */  mtc1      $at, $f5
/* EEE988 80241888 44802000 */  mtc1      $zero, $f4
/* EEE98C 8024188C C442002C */  lwc1      $f2, 0x2c($v0)
/* EEE990 80241890 46000021 */  cvt.d.s   $f0, $f0
/* EEE994 80241894 46240000 */  add.d     $f0, $f0, $f4
/* EEE998 80241898 460010A1 */  cvt.d.s   $f2, $f2
/* EEE99C 8024189C 4620103C */  c.lt.d    $f2, $f0
/* EEE9A0 802418A0 00000000 */  nop
/* EEE9A4 802418A4 4500002E */  bc1f      .L80241960
/* EEE9A8 802418A8 0280202D */   daddu    $a0, $s4, $zero
/* EEE9AC 802418AC 24020001 */  addiu     $v0, $zero, 1
/* EEE9B0 802418B0 AFA20010 */  sw        $v0, 0x10($sp)
/* EEE9B4 802418B4 8E460024 */  lw        $a2, 0x24($s2)
/* EEE9B8 802418B8 8E470028 */  lw        $a3, 0x28($s2)
/* EEE9BC 802418BC 0C013469 */  jal       func_8004D1A4
/* EEE9C0 802418C0 0220282D */   daddu    $a1, $s1, $zero
/* EEE9C4 802418C4 10400026 */  beqz      $v0, .L80241960
/* EEE9C8 802418C8 0000202D */   daddu    $a0, $zero, $zero
/* EEE9CC 802418CC 0200282D */  daddu     $a1, $s0, $zero
/* EEE9D0 802418D0 0000302D */  daddu     $a2, $zero, $zero
/* EEE9D4 802418D4 2412000C */  addiu     $s2, $zero, 0xc
/* EEE9D8 802418D8 860300A8 */  lh        $v1, 0xa8($s0)
/* EEE9DC 802418DC 3C013F80 */  lui       $at, 0x3f80
/* EEE9E0 802418E0 44810000 */  mtc1      $at, $f0
/* EEE9E4 802418E4 3C014000 */  lui       $at, 0x4000
/* EEE9E8 802418E8 44811000 */  mtc1      $at, $f2
/* EEE9EC 802418EC 3C01C1A0 */  lui       $at, 0xc1a0
/* EEE9F0 802418F0 44812000 */  mtc1      $at, $f4
/* EEE9F4 802418F4 44834000 */  mtc1      $v1, $f8
/* EEE9F8 802418F8 00000000 */  nop
/* EEE9FC 802418FC 46804220 */  cvt.s.w   $f8, $f8
/* EEEA00 80241900 44074000 */  mfc1      $a3, $f8
/* EEEA04 80241904 27A20038 */  addiu     $v0, $sp, 0x38
/* EEEA08 80241908 AFB2001C */  sw        $s2, 0x1c($sp)
/* EEEA0C 8024190C AFA20020 */  sw        $v0, 0x20($sp)
/* EEEA10 80241910 E7A00010 */  swc1      $f0, 0x10($sp)
/* EEEA14 80241914 E7A20014 */  swc1      $f2, 0x14($sp)
/* EEEA18 80241918 0C01D444 */  jal       dead_fx_emote
/* EEEA1C 8024191C E7A40018 */   swc1     $f4, 0x18($sp)
/* EEEA20 80241920 0200202D */  daddu     $a0, $s0, $zero
/* EEEA24 80241924 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EEEA28 80241928 C480003C */  lwc1      $f0, 0x3c($a0)
/* EEEA2C 8024192C 3C060020 */  lui       $a2, 0x20
/* EEEA30 80241930 0C013600 */  jal       dead_ai_enemy_play_sound
/* EEEA34 80241934 E4800064 */   swc1     $f0, 0x64($a0)
/* EEEA38 80241938 8E220018 */  lw        $v0, 0x18($s1)
/* EEEA3C 8024193C 9442002A */  lhu       $v0, 0x2a($v0)
/* EEEA40 80241940 30420001 */  andi      $v0, $v0, 1
/* EEEA44 80241944 10400003 */  beqz      $v0, .L80241954
/* EEEA48 80241948 2402000A */   addiu    $v0, $zero, 0xa
/* EEEA4C 8024194C 0809067F */  j         .L802419FC
/* EEEA50 80241950 AE620070 */   sw       $v0, 0x70($s3)
.L80241954:
/* EEEA54 80241954 0809067F */  j         .L802419FC
/* EEEA58 80241958 AE720070 */   sw       $s2, 0x70($s3)
.L8024195C:
/* EEEA5C 8024195C AE220090 */  sw        $v0, 0x90($s1)
.L80241960:
/* EEEA60 80241960 8602008C */  lh        $v0, 0x8c($s0)
/* EEEA64 80241964 14400025 */  bnez      $v0, .L802419FC
/* EEEA68 80241968 00000000 */   nop
/* EEEA6C 8024196C 8602008E */  lh        $v0, 0x8e($s0)
/* EEEA70 80241970 1C400022 */  bgtz      $v0, .L802419FC
/* EEEA74 80241974 00000000 */   nop
/* EEEA78 80241978 8E620074 */  lw        $v0, 0x74($s3)
/* EEEA7C 8024197C 2442FFFF */  addiu     $v0, $v0, -1
/* EEEA80 80241980 1840001D */  blez      $v0, .L802419F8
/* EEEA84 80241984 AE620074 */   sw       $v0, 0x74($s3)
/* EEEA88 80241988 8E220018 */  lw        $v0, 0x18($s1)
/* EEEA8C 8024198C 9442002A */  lhu       $v0, 0x2a($v0)
/* EEEA90 80241990 30420010 */  andi      $v0, $v0, 0x10
/* EEEA94 80241994 14400007 */  bnez      $v0, .L802419B4
/* EEEA98 80241998 00000000 */   nop
/* EEEA9C 8024199C C600000C */  lwc1      $f0, 0xc($s0)
/* EEEAA0 802419A0 3C014334 */  lui       $at, 0x4334
/* EEEAA4 802419A4 44816000 */  mtc1      $at, $f12
/* EEEAA8 802419A8 0C00AB85 */  jal       dead_clamp_angle
/* EEEAAC 802419AC 460C0300 */   add.s    $f12, $f0, $f12
/* EEEAB0 802419B0 E600000C */  swc1      $f0, 0xc($s0)
.L802419B4:
/* EEEAB4 802419B4 0C00AB3B */  jal       dead_rand_int
/* EEEAB8 802419B8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* EEEABC 802419BC 3C032E8B */  lui       $v1, 0x2e8b
/* EEEAC0 802419C0 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* EEEAC4 802419C4 00430018 */  mult      $v0, $v1
/* EEEAC8 802419C8 00021FC3 */  sra       $v1, $v0, 0x1f
/* EEEACC 802419CC 00004010 */  mfhi      $t0
/* EEEAD0 802419D0 00082043 */  sra       $a0, $t0, 1
/* EEEAD4 802419D4 00832023 */  subu      $a0, $a0, $v1
/* EEEAD8 802419D8 00041840 */  sll       $v1, $a0, 1
/* EEEADC 802419DC 00641821 */  addu      $v1, $v1, $a0
/* EEEAE0 802419E0 00031880 */  sll       $v1, $v1, 2
/* EEEAE4 802419E4 00641823 */  subu      $v1, $v1, $a0
/* EEEAE8 802419E8 00431023 */  subu      $v0, $v0, $v1
/* EEEAEC 802419EC 24420005 */  addiu     $v0, $v0, 5
/* EEEAF0 802419F0 0809067F */  j         .L802419FC
/* EEEAF4 802419F4 A602008E */   sh       $v0, 0x8e($s0)
.L802419F8:
/* EEEAF8 802419F8 AE600070 */  sw        $zero, 0x70($s3)
.L802419FC:
/* EEEAFC 802419FC 8FBF0054 */  lw        $ra, 0x54($sp)
/* EEEB00 80241A00 8FB40050 */  lw        $s4, 0x50($sp)
/* EEEB04 80241A04 8FB3004C */  lw        $s3, 0x4c($sp)
/* EEEB08 80241A08 8FB20048 */  lw        $s2, 0x48($sp)
/* EEEB0C 80241A0C 8FB10044 */  lw        $s1, 0x44($sp)
/* EEEB10 80241A10 8FB00040 */  lw        $s0, 0x40($sp)
/* EEEB14 80241A14 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* EEEB18 80241A18 D7B80068 */  ldc1      $f24, 0x68($sp)
/* EEEB1C 80241A1C D7B60060 */  ldc1      $f22, 0x60($sp)
/* EEEB20 80241A20 D7B40058 */  ldc1      $f20, 0x58($sp)
/* EEEB24 80241A24 03E00008 */  jr        $ra
/* EEEB28 80241A28 27BD0078 */   addiu    $sp, $sp, 0x78

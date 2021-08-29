.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E0_EED7E0
/* EED7E0 802406E0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* EED7E4 802406E4 AFB60040 */  sw        $s6, 0x40($sp)
/* EED7E8 802406E8 0080B02D */  daddu     $s6, $a0, $zero
/* EED7EC 802406EC AFB00028 */  sw        $s0, 0x28($sp)
/* EED7F0 802406F0 00A0802D */  daddu     $s0, $a1, $zero
/* EED7F4 802406F4 AFBF0044 */  sw        $ra, 0x44($sp)
/* EED7F8 802406F8 AFB5003C */  sw        $s5, 0x3c($sp)
/* EED7FC 802406FC AFB40038 */  sw        $s4, 0x38($sp)
/* EED800 80240700 AFB30034 */  sw        $s3, 0x34($sp)
/* EED804 80240704 AFB20030 */  sw        $s2, 0x30($sp)
/* EED808 80240708 AFB1002C */  sw        $s1, 0x2c($sp)
/* EED80C 8024070C F7B80058 */  sdc1      $f24, 0x58($sp)
/* EED810 80240710 F7B60050 */  sdc1      $f22, 0x50($sp)
/* EED814 80240714 F7B40048 */  sdc1      $f20, 0x48($sp)
/* EED818 80240718 8ED3000C */  lw        $s3, 0xc($s6)
/* EED81C 8024071C 0C00F94D */  jal       func_8003E534
/* EED820 80240720 2404FFFC */   addiu    $a0, $zero, -4
/* EED824 80240724 27A50018 */  addiu     $a1, $sp, 0x18
/* EED828 80240728 3C048008 */  lui       $a0, %hi(D_8007C760)
/* EED82C 8024072C 8C84C760 */  lw        $a0, %lo(D_8007C760)($a0)
/* EED830 80240730 27A6001C */  addiu     $a2, $sp, 0x1c
/* EED834 80240734 00041880 */  sll       $v1, $a0, 2
/* EED838 80240738 00641821 */  addu      $v1, $v1, $a0
/* EED83C 8024073C 00031880 */  sll       $v1, $v1, 2
/* EED840 80240740 00641823 */  subu      $v1, $v1, $a0
/* EED844 80240744 000320C0 */  sll       $a0, $v1, 3
/* EED848 80240748 00641821 */  addu      $v1, $v1, $a0
/* EED84C 8024074C 000318C0 */  sll       $v1, $v1, 3
/* EED850 80240750 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EED854 80240754 00230821 */  addu      $at, $at, $v1
/* EED858 80240758 C42C8DEC */  lwc1      $f12, %lo(D_800B8DEC)($at)
/* EED85C 8024075C 0C00AD49 */  jal       func_8002B524
/* EED860 80240760 0040A82D */   daddu    $s5, $v0, $zero
/* EED864 80240764 1200005D */  beqz      $s0, .L802408DC
/* EED868 80240768 00000000 */   nop
/* EED86C 8024076C 0C00AFC6 */  jal       func_8002BF18
/* EED870 80240770 24040068 */   addiu    $a0, $zero, 0x68
/* EED874 80240774 0040902D */  daddu     $s2, $v0, $zero
/* EED878 80240778 02C0202D */  daddu     $a0, $s6, $zero
/* EED87C 8024077C 0000882D */  daddu     $s1, $zero, $zero
/* EED880 80240780 2414FFFF */  addiu     $s4, $zero, -1
/* EED884 80240784 AED20060 */  sw        $s2, 0x60($s6)
/* EED888 80240788 8E650000 */  lw        $a1, ($s3)
/* EED88C 8024078C 3C014148 */  lui       $at, 0x4148
/* EED890 80240790 4481C000 */  mtc1      $at, $f24
/* EED894 80240794 3C013F80 */  lui       $at, 0x3f80
/* EED898 80240798 4481B000 */  mtc1      $at, $f22
/* EED89C 8024079C 4480A000 */  mtc1      $zero, $f20
/* EED8A0 802407A0 0C0B53A3 */  jal       dead_evt_get_variable
/* EED8A4 802407A4 0240802D */   daddu    $s0, $s2, $zero
/* EED8A8 802407A8 0C0462EC */  jal       func_80118BB0
/* EED8AC 802407AC 0040202D */   daddu    $a0, $v0, $zero
/* EED8B0 802407B0 AE42005C */  sw        $v0, 0x5c($s2)
.L802407B4:
/* EED8B4 802407B4 8E42005C */  lw        $v0, 0x5c($s2)
/* EED8B8 802407B8 C440004C */  lwc1      $f0, 0x4c($v0)
/* EED8BC 802407BC 0000202D */  daddu     $a0, $zero, $zero
/* EED8C0 802407C0 E7B60010 */  swc1      $f22, 0x10($sp)
/* EED8C4 802407C4 AFB40014 */  sw        $s4, 0x14($sp)
/* EED8C8 802407C8 46180000 */  add.s     $f0, $f0, $f24
/* EED8CC 802407CC 8C450048 */  lw        $a1, 0x48($v0)
/* EED8D0 802407D0 8C470050 */  lw        $a3, 0x50($v0)
/* EED8D4 802407D4 44060000 */  mfc1      $a2, $f0
/* EED8D8 802407D8 0C01DA5C */  jal       func_80076970
/* EED8DC 802407DC 26310001 */   addiu    $s1, $s1, 1
/* EED8E0 802407E0 AE020008 */  sw        $v0, 8($s0)
/* EED8E4 802407E4 E614002C */  swc1      $f20, 0x2c($s0)
/* EED8E8 802407E8 E6140020 */  swc1      $f20, 0x20($s0)
/* EED8EC 802407EC E6140014 */  swc1      $f20, 0x14($s0)
/* EED8F0 802407F0 E6140050 */  swc1      $f20, 0x50($s0)
/* EED8F4 802407F4 E6140044 */  swc1      $f20, 0x44($s0)
/* EED8F8 802407F8 E6140038 */  swc1      $f20, 0x38($s0)
/* EED8FC 802407FC 2A220003 */  slti      $v0, $s1, 3
/* EED900 80240800 1440FFEC */  bnez      $v0, .L802407B4
/* EED904 80240804 26100004 */   addiu    $s0, $s0, 4
/* EED908 80240808 0000882D */  daddu     $s1, $zero, $zero
/* EED90C 8024080C 0240802D */  daddu     $s0, $s2, $zero
/* EED910 80240810 3C148024 */  lui       $s4, %hi(D_802437B8_EF08B8)
/* EED914 80240814 269437B8 */  addiu     $s4, $s4, %lo(D_802437B8_EF08B8)
/* EED918 80240818 3C014248 */  lui       $at, 0x4248
/* EED91C 8024081C 4481A000 */  mtc1      $at, $f20
/* EED920 80240820 24130044 */  addiu     $s3, $zero, 0x44
/* EED924 80240824 AE400000 */  sw        $zero, ($s2)
/* EED928 80240828 AE400004 */  sw        $zero, 4($s2)
/* EED92C 8024082C AE400060 */  sw        $zero, 0x60($s2)
/* EED930 80240830 AE400064 */  sw        $zero, 0x64($s2)
.L80240834:
/* EED934 80240834 27A40020 */  addiu     $a0, $sp, 0x20
/* EED938 80240838 4406A000 */  mfc1      $a2, $f20
/* EED93C 8024083C 8E870000 */  lw        $a3, ($s4)
/* EED940 80240840 02532821 */  addu      $a1, $s2, $s3
/* EED944 80240844 0C00ACA3 */  jal       func_8002B28C
/* EED948 80240848 AFA00020 */   sw       $zero, 0x20($sp)
/* EED94C 8024084C C7A2001C */  lwc1      $f2, 0x1c($sp)
/* EED950 80240850 C7A40020 */  lwc1      $f4, 0x20($sp)
/* EED954 80240854 46041082 */  mul.s     $f2, $f2, $f4
/* EED958 80240858 00000000 */  nop
/* EED95C 8024085C C7A00018 */  lwc1      $f0, 0x18($sp)
/* EED960 80240860 46040002 */  mul.s     $f0, $f0, $f4
/* EED964 80240864 00000000 */  nop
/* EED968 80240868 E6020038 */  swc1      $f2, 0x38($s0)
/* EED96C 8024086C E6000050 */  swc1      $f0, 0x50($s0)
/* EED970 80240870 8E42005C */  lw        $v0, 0x5c($s2)
/* EED974 80240874 C6000038 */  lwc1      $f0, 0x38($s0)
/* EED978 80240878 C4420048 */  lwc1      $f2, 0x48($v0)
/* EED97C 8024087C 46001080 */  add.s     $f2, $f2, $f0
/* EED980 80240880 C6A00038 */  lwc1      $f0, 0x38($s5)
/* EED984 80240884 46020001 */  sub.s     $f0, $f0, $f2
/* EED988 80240888 E6000038 */  swc1      $f0, 0x38($s0)
/* EED98C 8024088C 8E42005C */  lw        $v0, 0x5c($s2)
/* EED990 80240890 C6000044 */  lwc1      $f0, 0x44($s0)
/* EED994 80240894 C442004C */  lwc1      $f2, 0x4c($v0)
/* EED998 80240898 46001080 */  add.s     $f2, $f2, $f0
/* EED99C 8024089C C6A0003C */  lwc1      $f0, 0x3c($s5)
/* EED9A0 802408A0 46020001 */  sub.s     $f0, $f0, $f2
/* EED9A4 802408A4 E6000044 */  swc1      $f0, 0x44($s0)
/* EED9A8 802408A8 8E42005C */  lw        $v0, 0x5c($s2)
/* EED9AC 802408AC C6000050 */  lwc1      $f0, 0x50($s0)
/* EED9B0 802408B0 C4420050 */  lwc1      $f2, 0x50($v0)
/* EED9B4 802408B4 26940004 */  addiu     $s4, $s4, 4
/* EED9B8 802408B8 46001080 */  add.s     $f2, $f2, $f0
/* EED9BC 802408BC C6A00040 */  lwc1      $f0, 0x40($s5)
/* EED9C0 802408C0 26730004 */  addiu     $s3, $s3, 4
/* EED9C4 802408C4 46020001 */  sub.s     $f0, $f0, $f2
/* EED9C8 802408C8 26310001 */  addiu     $s1, $s1, 1
/* EED9CC 802408CC 2A220003 */  slti      $v0, $s1, 3
/* EED9D0 802408D0 E6000050 */  swc1      $f0, 0x50($s0)
/* EED9D4 802408D4 1440FFD7 */  bnez      $v0, .L80240834
/* EED9D8 802408D8 26100004 */   addiu    $s0, $s0, 4
.L802408DC:
/* EED9DC 802408DC 8ED20060 */  lw        $s2, 0x60($s6)
/* EED9E0 802408E0 8E430000 */  lw        $v1, ($s2)
/* EED9E4 802408E4 24020001 */  addiu     $v0, $zero, 1
/* EED9E8 802408E8 10620038 */  beq       $v1, $v0, .L802409CC
/* EED9EC 802408EC 28620002 */   slti     $v0, $v1, 2
/* EED9F0 802408F0 50400005 */  beql      $v0, $zero, .L80240908
/* EED9F4 802408F4 24020002 */   addiu    $v0, $zero, 2
/* EED9F8 802408F8 10600007 */  beqz      $v1, .L80240918
/* EED9FC 802408FC 24040005 */   addiu    $a0, $zero, 5
/* EEDA00 80240900 080902AC */  j         .L80240AB0
/* EEDA04 80240904 00000000 */   nop
.L80240908:
/* EEDA08 80240908 10620058 */  beq       $v1, $v0, .L80240A6C
/* EEDA0C 8024090C 00000000 */   nop
/* EEDA10 80240910 080902AC */  j         .L80240AB0
/* EEDA14 80240914 00000000 */   nop
.L80240918:
/* EEDA18 80240918 0000882D */  daddu     $s1, $zero, $zero
/* EEDA1C 8024091C 3C148024 */  lui       $s4, %hi(D_802437B8_EF08B8)
/* EEDA20 80240920 269437B8 */  addiu     $s4, $s4, %lo(D_802437B8_EF08B8)
/* EEDA24 80240924 24130020 */  addiu     $s3, $zero, 0x20
/* EEDA28 80240928 3C064248 */  lui       $a2, 0x4248
/* EEDA2C 8024092C 44800000 */  mtc1      $zero, $f0
/* EEDA30 80240930 24020014 */  addiu     $v0, $zero, 0x14
/* EEDA34 80240934 AFA20010 */  sw        $v0, 0x10($sp)
/* EEDA38 80240938 44050000 */  mfc1      $a1, $f0
/* EEDA3C 8024093C 8E470060 */  lw        $a3, 0x60($s2)
/* EEDA40 80240940 4485B000 */  mtc1      $a1, $f22
/* EEDA44 80240944 0C00ADA9 */  jal       func_8002B6A4
/* EEDA48 80240948 0240802D */   daddu    $s0, $s2, $zero
/* EEDA4C 8024094C 46000506 */  mov.s     $f20, $f0
.L80240950:
/* EEDA50 80240950 4406A000 */  mfc1      $a2, $f20
/* EEDA54 80240954 27A40020 */  addiu     $a0, $sp, 0x20
/* EEDA58 80240958 E6160020 */  swc1      $f22, 0x20($s0)
/* EEDA5C 8024095C 8E870000 */  lw        $a3, ($s4)
/* EEDA60 80240960 02532821 */  addu      $a1, $s2, $s3
/* EEDA64 80240964 0C00ACA3 */  jal       func_8002B28C
/* EEDA68 80240968 E7B60020 */   swc1     $f22, 0x20($sp)
/* EEDA6C 8024096C C7A4001C */  lwc1      $f4, 0x1c($sp)
/* EEDA70 80240970 C7A00020 */  lwc1      $f0, 0x20($sp)
/* EEDA74 80240974 46002102 */  mul.s     $f4, $f4, $f0
/* EEDA78 80240978 00000000 */  nop
/* EEDA7C 8024097C C7A20018 */  lwc1      $f2, 0x18($sp)
/* EEDA80 80240980 26940004 */  addiu     $s4, $s4, 4
/* EEDA84 80240984 46001082 */  mul.s     $f2, $f2, $f0
/* EEDA88 80240988 00000000 */  nop
/* EEDA8C 8024098C 26730004 */  addiu     $s3, $s3, 4
/* EEDA90 80240990 26310001 */  addiu     $s1, $s1, 1
/* EEDA94 80240994 2A220003 */  slti      $v0, $s1, 3
/* EEDA98 80240998 E6040014 */  swc1      $f4, 0x14($s0)
/* EEDA9C 8024099C E602002C */  swc1      $f2, 0x2c($s0)
/* EEDAA0 802409A0 1440FFEB */  bnez      $v0, .L80240950
/* EEDAA4 802409A4 26100004 */   addiu    $s0, $s0, 4
/* EEDAA8 802409A8 8E420060 */  lw        $v0, 0x60($s2)
/* EEDAAC 802409AC 24420001 */  addiu     $v0, $v0, 1
/* EEDAB0 802409B0 AE420060 */  sw        $v0, 0x60($s2)
/* EEDAB4 802409B4 28420015 */  slti      $v0, $v0, 0x15
/* EEDAB8 802409B8 1440003D */  bnez      $v0, .L80240AB0
/* EEDABC 802409BC 24020001 */   addiu    $v0, $zero, 1
/* EEDAC0 802409C0 AE420000 */  sw        $v0, ($s2)
/* EEDAC4 802409C4 080902AC */  j         .L80240AB0
/* EEDAC8 802409C8 AE400060 */   sw       $zero, 0x60($s2)
.L802409CC:
/* EEDACC 802409CC 0000882D */  daddu     $s1, $zero, $zero
/* EEDAD0 802409D0 3C148024 */  lui       $s4, %hi(D_802437B8_EF08B8)
/* EEDAD4 802409D4 269437B8 */  addiu     $s4, $s4, %lo(D_802437B8_EF08B8)
/* EEDAD8 802409D8 24130020 */  addiu     $s3, $zero, 0x20
/* EEDADC 802409DC 0240802D */  daddu     $s0, $s2, $zero
/* EEDAE0 802409E0 3C014248 */  lui       $at, 0x4248
/* EEDAE4 802409E4 4481A000 */  mtc1      $at, $f20
/* EEDAE8 802409E8 4480B000 */  mtc1      $zero, $f22
.L802409EC:
/* EEDAEC 802409EC 4406A000 */  mfc1      $a2, $f20
/* EEDAF0 802409F0 27A40020 */  addiu     $a0, $sp, 0x20
/* EEDAF4 802409F4 E6160020 */  swc1      $f22, 0x20($s0)
/* EEDAF8 802409F8 8E870000 */  lw        $a3, ($s4)
/* EEDAFC 802409FC 02532821 */  addu      $a1, $s2, $s3
/* EEDB00 80240A00 0C00ACA3 */  jal       func_8002B28C
/* EEDB04 80240A04 E7B60020 */   swc1     $f22, 0x20($sp)
/* EEDB08 80240A08 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* EEDB0C 80240A0C C7A00020 */  lwc1      $f0, 0x20($sp)
/* EEDB10 80240A10 46002102 */  mul.s     $f4, $f4, $f0
/* EEDB14 80240A14 00000000 */  nop
/* EEDB18 80240A18 C7A20018 */  lwc1      $f2, 0x18($sp)
/* EEDB1C 80240A1C 26940004 */  addiu     $s4, $s4, 4
/* EEDB20 80240A20 46001082 */  mul.s     $f2, $f2, $f0
/* EEDB24 80240A24 00000000 */  nop
/* EEDB28 80240A28 26730004 */  addiu     $s3, $s3, 4
/* EEDB2C 80240A2C 26310001 */  addiu     $s1, $s1, 1
/* EEDB30 80240A30 2A220003 */  slti      $v0, $s1, 3
/* EEDB34 80240A34 E6040014 */  swc1      $f4, 0x14($s0)
/* EEDB38 80240A38 E602002C */  swc1      $f2, 0x2c($s0)
/* EEDB3C 80240A3C 1440FFEB */  bnez      $v0, .L802409EC
/* EEDB40 80240A40 26100004 */   addiu    $s0, $s0, 4
/* EEDB44 80240A44 8E420060 */  lw        $v0, 0x60($s2)
/* EEDB48 80240A48 24420001 */  addiu     $v0, $v0, 1
/* EEDB4C 80240A4C AE420060 */  sw        $v0, 0x60($s2)
/* EEDB50 80240A50 28420010 */  slti      $v0, $v0, 0x10
/* EEDB54 80240A54 14400016 */  bnez      $v0, .L80240AB0
/* EEDB58 80240A58 2402000F */   addiu    $v0, $zero, 0xf
/* EEDB5C 80240A5C AE420060 */  sw        $v0, 0x60($s2)
/* EEDB60 80240A60 24020002 */  addiu     $v0, $zero, 2
/* EEDB64 80240A64 080902AC */  j         .L80240AB0
/* EEDB68 80240A68 AE420000 */   sw       $v0, ($s2)
.L80240A6C:
/* EEDB6C 80240A6C 8E420060 */  lw        $v0, 0x60($s2)
/* EEDB70 80240A70 24420001 */  addiu     $v0, $v0, 1
/* EEDB74 80240A74 AE420060 */  sw        $v0, 0x60($s2)
/* EEDB78 80240A78 2842001F */  slti      $v0, $v0, 0x1f
/* EEDB7C 80240A7C 1440000C */  bnez      $v0, .L80240AB0
/* EEDB80 80240A80 0000882D */   daddu    $s1, $zero, $zero
/* EEDB84 80240A84 0240282D */  daddu     $a1, $s2, $zero
.L80240A88:
/* EEDB88 80240A88 8CA20008 */  lw        $v0, 8($a1)
/* EEDB8C 80240A8C 8C430000 */  lw        $v1, ($v0)
/* EEDB90 80240A90 26310001 */  addiu     $s1, $s1, 1
/* EEDB94 80240A94 34630010 */  ori       $v1, $v1, 0x10
/* EEDB98 80240A98 AC430000 */  sw        $v1, ($v0)
/* EEDB9C 80240A9C 2A220003 */  slti      $v0, $s1, 3
/* EEDBA0 80240AA0 1440FFF9 */  bnez      $v0, .L80240A88
/* EEDBA4 80240AA4 24A50004 */   addiu    $a1, $a1, 4
/* EEDBA8 80240AA8 080902F9 */  j         .L80240BE4
/* EEDBAC 80240AAC 24020002 */   addiu    $v0, $zero, 2
.L80240AB0:
/* EEDBB0 80240AB0 8E430004 */  lw        $v1, 4($s2)
/* EEDBB4 80240AB4 10600005 */  beqz      $v1, .L80240ACC
/* EEDBB8 80240AB8 24020001 */   addiu    $v0, $zero, 1
/* EEDBBC 80240ABC 1062000B */  beq       $v1, $v0, .L80240AEC
/* EEDBC0 80240AC0 0000882D */   daddu    $s1, $zero, $zero
/* EEDBC4 80240AC4 080902E8 */  j         .L80240BA0
/* EEDBC8 80240AC8 0240282D */   daddu    $a1, $s2, $zero
.L80240ACC:
/* EEDBCC 80240ACC 8E420064 */  lw        $v0, 0x64($s2)
/* EEDBD0 80240AD0 24420001 */  addiu     $v0, $v0, 1
/* EEDBD4 80240AD4 AE420064 */  sw        $v0, 0x64($s2)
/* EEDBD8 80240AD8 28420010 */  slti      $v0, $v0, 0x10
/* EEDBDC 80240ADC 1440002F */  bnez      $v0, .L80240B9C
/* EEDBE0 80240AE0 0000882D */   daddu    $s1, $zero, $zero
/* EEDBE4 80240AE4 080902E4 */  j         .L80240B90
/* EEDBE8 80240AE8 24020001 */   addiu    $v0, $zero, 1
.L80240AEC:
/* EEDBEC 80240AEC 4480A000 */  mtc1      $zero, $f20
/* EEDBF0 80240AF0 24130014 */  addiu     $s3, $zero, 0x14
/* EEDBF4 80240AF4 0240802D */  daddu     $s0, $s2, $zero
.L80240AF8:
/* EEDBF8 80240AF8 4405A000 */  mfc1      $a1, $f20
/* EEDBFC 80240AFC AFB30010 */  sw        $s3, 0x10($sp)
/* EEDC00 80240B00 8E060038 */  lw        $a2, 0x38($s0)
/* EEDC04 80240B04 8E470064 */  lw        $a3, 0x64($s2)
/* EEDC08 80240B08 0C00ADA9 */  jal       func_8002B6A4
/* EEDC0C 80240B0C 24040001 */   addiu    $a0, $zero, 1
/* EEDC10 80240B10 C6020014 */  lwc1      $f2, 0x14($s0)
/* EEDC14 80240B14 46001080 */  add.s     $f2, $f2, $f0
/* EEDC18 80240B18 4405A000 */  mfc1      $a1, $f20
/* EEDC1C 80240B1C E6020014 */  swc1      $f2, 0x14($s0)
/* EEDC20 80240B20 AFB30010 */  sw        $s3, 0x10($sp)
/* EEDC24 80240B24 8E060044 */  lw        $a2, 0x44($s0)
/* EEDC28 80240B28 8E470064 */  lw        $a3, 0x64($s2)
/* EEDC2C 80240B2C 0C00ADA9 */  jal       func_8002B6A4
/* EEDC30 80240B30 24040001 */   addiu    $a0, $zero, 1
/* EEDC34 80240B34 C6020020 */  lwc1      $f2, 0x20($s0)
/* EEDC38 80240B38 46001080 */  add.s     $f2, $f2, $f0
/* EEDC3C 80240B3C 4405A000 */  mfc1      $a1, $f20
/* EEDC40 80240B40 E6020020 */  swc1      $f2, 0x20($s0)
/* EEDC44 80240B44 AFB30010 */  sw        $s3, 0x10($sp)
/* EEDC48 80240B48 8E060050 */  lw        $a2, 0x50($s0)
/* EEDC4C 80240B4C 8E470064 */  lw        $a3, 0x64($s2)
/* EEDC50 80240B50 0C00ADA9 */  jal       func_8002B6A4
/* EEDC54 80240B54 24040001 */   addiu    $a0, $zero, 1
/* EEDC58 80240B58 C602002C */  lwc1      $f2, 0x2c($s0)
/* EEDC5C 80240B5C 46001080 */  add.s     $f2, $f2, $f0
/* EEDC60 80240B60 26310001 */  addiu     $s1, $s1, 1
/* EEDC64 80240B64 2A220003 */  slti      $v0, $s1, 3
/* EEDC68 80240B68 E602002C */  swc1      $f2, 0x2c($s0)
/* EEDC6C 80240B6C 1440FFE2 */  bnez      $v0, .L80240AF8
/* EEDC70 80240B70 26100004 */   addiu    $s0, $s0, 4
/* EEDC74 80240B74 8E420064 */  lw        $v0, 0x64($s2)
/* EEDC78 80240B78 24420001 */  addiu     $v0, $v0, 1
/* EEDC7C 80240B7C AE420064 */  sw        $v0, 0x64($s2)
/* EEDC80 80240B80 28420015 */  slti      $v0, $v0, 0x15
/* EEDC84 80240B84 14400005 */  bnez      $v0, .L80240B9C
/* EEDC88 80240B88 0000882D */   daddu    $s1, $zero, $zero
/* EEDC8C 80240B8C 24020002 */  addiu     $v0, $zero, 2
.L80240B90:
/* EEDC90 80240B90 AE420004 */  sw        $v0, 4($s2)
/* EEDC94 80240B94 AE400064 */  sw        $zero, 0x64($s2)
/* EEDC98 80240B98 0000882D */  daddu     $s1, $zero, $zero
.L80240B9C:
/* EEDC9C 80240B9C 0240282D */  daddu     $a1, $s2, $zero
.L80240BA0:
/* EEDCA0 80240BA0 8CA20008 */  lw        $v0, 8($a1)
/* EEDCA4 80240BA4 C4A00014 */  lwc1      $f0, 0x14($a1)
/* EEDCA8 80240BA8 8C42000C */  lw        $v0, 0xc($v0)
/* EEDCAC 80240BAC E4400010 */  swc1      $f0, 0x10($v0)
/* EEDCB0 80240BB0 8CA20008 */  lw        $v0, 8($a1)
/* EEDCB4 80240BB4 C4A00020 */  lwc1      $f0, 0x20($a1)
/* EEDCB8 80240BB8 8C42000C */  lw        $v0, 0xc($v0)
/* EEDCBC 80240BBC 26310001 */  addiu     $s1, $s1, 1
/* EEDCC0 80240BC0 E4400014 */  swc1      $f0, 0x14($v0)
/* EEDCC4 80240BC4 8CA20008 */  lw        $v0, 8($a1)
/* EEDCC8 80240BC8 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* EEDCCC 80240BCC 8C42000C */  lw        $v0, 0xc($v0)
/* EEDCD0 80240BD0 E4400018 */  swc1      $f0, 0x18($v0)
/* EEDCD4 80240BD4 2A220003 */  slti      $v0, $s1, 3
/* EEDCD8 80240BD8 1440FFF1 */  bnez      $v0, .L80240BA0
/* EEDCDC 80240BDC 24A50004 */   addiu    $a1, $a1, 4
/* EEDCE0 80240BE0 0000102D */  daddu     $v0, $zero, $zero
.L80240BE4:
/* EEDCE4 80240BE4 8FBF0044 */  lw        $ra, 0x44($sp)
/* EEDCE8 80240BE8 8FB60040 */  lw        $s6, 0x40($sp)
/* EEDCEC 80240BEC 8FB5003C */  lw        $s5, 0x3c($sp)
/* EEDCF0 80240BF0 8FB40038 */  lw        $s4, 0x38($sp)
/* EEDCF4 80240BF4 8FB30034 */  lw        $s3, 0x34($sp)
/* EEDCF8 80240BF8 8FB20030 */  lw        $s2, 0x30($sp)
/* EEDCFC 80240BFC 8FB1002C */  lw        $s1, 0x2c($sp)
/* EEDD00 80240C00 8FB00028 */  lw        $s0, 0x28($sp)
/* EEDD04 80240C04 D7B80058 */  ldc1      $f24, 0x58($sp)
/* EEDD08 80240C08 D7B60050 */  ldc1      $f22, 0x50($sp)
/* EEDD0C 80240C0C D7B40048 */  ldc1      $f20, 0x48($sp)
/* EEDD10 80240C10 03E00008 */  jr        $ra
/* EEDD14 80240C14 27BD0060 */   addiu    $sp, $sp, 0x60

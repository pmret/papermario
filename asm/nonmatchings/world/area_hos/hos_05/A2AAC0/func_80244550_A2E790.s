.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244550_A2E790
/* A2E790 80244550 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A2E794 80244554 AFB60028 */  sw        $s6, 0x28($sp)
/* A2E798 80244558 0080B02D */  daddu     $s6, $a0, $zero
/* A2E79C 8024455C AFB00010 */  sw        $s0, 0x10($sp)
/* A2E7A0 80244560 00A0802D */  daddu     $s0, $a1, $zero
/* A2E7A4 80244564 AFBF002C */  sw        $ra, 0x2c($sp)
/* A2E7A8 80244568 AFB50024 */  sw        $s5, 0x24($sp)
/* A2E7AC 8024456C AFB40020 */  sw        $s4, 0x20($sp)
/* A2E7B0 80244570 AFB3001C */  sw        $s3, 0x1c($sp)
/* A2E7B4 80244574 AFB20018 */  sw        $s2, 0x18($sp)
/* A2E7B8 80244578 AFB10014 */  sw        $s1, 0x14($sp)
/* A2E7BC 8024457C F7B80040 */  sdc1      $f24, 0x40($sp)
/* A2E7C0 80244580 F7B60038 */  sdc1      $f22, 0x38($sp)
/* A2E7C4 80244584 F7B40030 */  sdc1      $f20, 0x30($sp)
/* A2E7C8 80244588 0C0B36B0 */  jal       resolve_npc
/* A2E7CC 8024458C 24050009 */   addiu    $a1, $zero, 9
/* A2E7D0 80244590 02C0202D */  daddu     $a0, $s6, $zero
/* A2E7D4 80244594 3C05F4AC */  lui       $a1, 0xf4ac
/* A2E7D8 80244598 34A5D480 */  ori       $a1, $a1, 0xd480
/* A2E7DC 8024459C 0C0B1EAF */  jal       get_variable
/* A2E7E0 802445A0 0040A02D */   daddu    $s4, $v0, $zero
/* A2E7E4 802445A4 1200002B */  beqz      $s0, .L80244654
/* A2E7E8 802445A8 0040A82D */   daddu    $s5, $v0, $zero
/* A2E7EC 802445AC 0000802D */  daddu     $s0, $zero, $zero
/* A2E7F0 802445B0 3C138025 */  lui       $s3, 0x8025
/* A2E7F4 802445B4 2673F358 */  addiu     $s3, $s3, -0xca8
/* A2E7F8 802445B8 3C128025 */  lui       $s2, 0x8025
/* A2E7FC 802445BC 2652F338 */  addiu     $s2, $s2, -0xcc8
/* A2E800 802445C0 C6800038 */  lwc1      $f0, 0x38($s4)
/* A2E804 802445C4 C682003C */  lwc1      $f2, 0x3c($s4)
/* A2E808 802445C8 C6840040 */  lwc1      $f4, 0x40($s4)
/* A2E80C 802445CC 3C118025 */  lui       $s1, 0x8025
/* A2E810 802445D0 2631F318 */  addiu     $s1, $s1, -0xce8
/* A2E814 802445D4 3C018025 */  lui       $at, 0x8025
/* A2E818 802445D8 E420F2FC */  swc1      $f0, -0xd04($at)
/* A2E81C 802445DC 3C018025 */  lui       $at, 0x8025
/* A2E820 802445E0 E422F300 */  swc1      $f2, -0xd00($at)
/* A2E824 802445E4 3C018025 */  lui       $at, 0x8025
/* A2E828 802445E8 E424F304 */  swc1      $f4, -0xcfc($at)
.L802445EC:
/* A2E82C 802445EC 02C0202D */  daddu     $a0, $s6, $zero
/* A2E830 802445F0 0C0B36B0 */  jal       resolve_npc
/* A2E834 802445F4 0200282D */   daddu    $a1, $s0, $zero
/* A2E838 802445F8 C4400038 */  lwc1      $f0, 0x38($v0)
/* A2E83C 802445FC 26100001 */  addiu     $s0, $s0, 1
/* A2E840 80244600 E6200000 */  swc1      $f0, ($s1)
/* A2E844 80244604 C440003C */  lwc1      $f0, 0x3c($v0)
/* A2E848 80244608 26310004 */  addiu     $s1, $s1, 4
/* A2E84C 8024460C E6400000 */  swc1      $f0, ($s2)
/* A2E850 80244610 26520004 */  addiu     $s2, $s2, 4
/* A2E854 80244614 C4400040 */  lwc1      $f0, 0x40($v0)
/* A2E858 80244618 2A020007 */  slti      $v0, $s0, 7
/* A2E85C 8024461C E6600000 */  swc1      $f0, ($s3)
/* A2E860 80244620 1440FFF2 */  bnez      $v0, .L802445EC
/* A2E864 80244624 26730004 */   addiu    $s3, $s3, 4
/* A2E868 80244628 8EA2000C */  lw        $v0, 0xc($s5)
/* A2E86C 8024462C 0040182D */  daddu     $v1, $v0, $zero
/* A2E870 80244630 C4440004 */  lwc1      $f4, 4($v0)
/* A2E874 80244634 C4400008 */  lwc1      $f0, 8($v0)
/* A2E878 80244638 C462000C */  lwc1      $f2, 0xc($v1)
/* A2E87C 8024463C 3C018025 */  lui       $at, 0x8025
/* A2E880 80244640 E424F308 */  swc1      $f4, -0xcf8($at)
/* A2E884 80244644 3C018025 */  lui       $at, 0x8025
/* A2E888 80244648 E420F30C */  swc1      $f0, -0xcf4($at)
/* A2E88C 8024464C 3C018025 */  lui       $at, 0x8025
/* A2E890 80244650 E422F310 */  swc1      $f2, -0xcf0($at)
.L80244654:
/* A2E894 80244654 0000802D */  daddu     $s0, $zero, $zero
/* A2E898 80244658 C6820038 */  lwc1      $f2, 0x38($s4)
/* A2E89C 8024465C 3C018025 */  lui       $at, 0x8025
/* A2E8A0 80244660 C420F2FC */  lwc1      $f0, -0xd04($at)
/* A2E8A4 80244664 3C138025 */  lui       $s3, 0x8025
/* A2E8A8 80244668 2673F358 */  addiu     $s3, $s3, -0xca8
/* A2E8AC 8024466C 46001501 */  sub.s     $f20, $f2, $f0
/* A2E8B0 80244670 C682003C */  lwc1      $f2, 0x3c($s4)
/* A2E8B4 80244674 3C018025 */  lui       $at, 0x8025
/* A2E8B8 80244678 C420F300 */  lwc1      $f0, -0xd00($at)
/* A2E8BC 8024467C 3C128025 */  lui       $s2, 0x8025
/* A2E8C0 80244680 2652F338 */  addiu     $s2, $s2, -0xcc8
/* A2E8C4 80244684 46001581 */  sub.s     $f22, $f2, $f0
/* A2E8C8 80244688 C6820040 */  lwc1      $f2, 0x40($s4)
/* A2E8CC 8024468C 3C018025 */  lui       $at, 0x8025
/* A2E8D0 80244690 C420F304 */  lwc1      $f0, -0xcfc($at)
/* A2E8D4 80244694 3C118025 */  lui       $s1, 0x8025
/* A2E8D8 80244698 2631F318 */  addiu     $s1, $s1, -0xce8
/* A2E8DC 8024469C 46001601 */  sub.s     $f24, $f2, $f0
.L802446A0:
/* A2E8E0 802446A0 02C0202D */  daddu     $a0, $s6, $zero
/* A2E8E4 802446A4 0C0B36B0 */  jal       resolve_npc
/* A2E8E8 802446A8 0200282D */   daddu    $a1, $s0, $zero
/* A2E8EC 802446AC C6200000 */  lwc1      $f0, ($s1)
/* A2E8F0 802446B0 46140000 */  add.s     $f0, $f0, $f20
/* A2E8F4 802446B4 E4400038 */  swc1      $f0, 0x38($v0)
/* A2E8F8 802446B8 C6400000 */  lwc1      $f0, ($s2)
/* A2E8FC 802446BC 46160000 */  add.s     $f0, $f0, $f22
/* A2E900 802446C0 26100001 */  addiu     $s0, $s0, 1
/* A2E904 802446C4 E440003C */  swc1      $f0, 0x3c($v0)
/* A2E908 802446C8 C6600000 */  lwc1      $f0, ($s3)
/* A2E90C 802446CC 26310004 */  addiu     $s1, $s1, 4
/* A2E910 802446D0 46180000 */  add.s     $f0, $f0, $f24
/* A2E914 802446D4 C442003C */  lwc1      $f2, 0x3c($v0)
/* A2E918 802446D8 26520004 */  addiu     $s2, $s2, 4
/* A2E91C 802446DC E4400040 */  swc1      $f0, 0x40($v0)
/* A2E920 802446E0 C4400038 */  lwc1      $f0, 0x38($v0)
/* A2E924 802446E4 C4440040 */  lwc1      $f4, 0x40($v0)
/* A2E928 802446E8 E4420070 */  swc1      $f2, 0x70($v0)
/* A2E92C 802446EC E440006C */  swc1      $f0, 0x6c($v0)
/* A2E930 802446F0 E4440074 */  swc1      $f4, 0x74($v0)
/* A2E934 802446F4 2A020007 */  slti      $v0, $s0, 7
/* A2E938 802446F8 1440FFE9 */  bnez      $v0, .L802446A0
/* A2E93C 802446FC 26730004 */   addiu    $s3, $s3, 4
/* A2E940 80244700 3C018025 */  lui       $at, 0x8025
/* A2E944 80244704 C420F308 */  lwc1      $f0, -0xcf8($at)
/* A2E948 80244708 46140000 */  add.s     $f0, $f0, $f20
/* A2E94C 8024470C 3C018025 */  lui       $at, 0x8025
/* A2E950 80244710 C422F30C */  lwc1      $f2, -0xcf4($at)
/* A2E954 80244714 8EA2000C */  lw        $v0, 0xc($s5)
/* A2E958 80244718 46161080 */  add.s     $f2, $f2, $f22
/* A2E95C 8024471C E4400004 */  swc1      $f0, 4($v0)
/* A2E960 80244720 3C018025 */  lui       $at, 0x8025
/* A2E964 80244724 C420F310 */  lwc1      $f0, -0xcf0($at)
/* A2E968 80244728 8EA2000C */  lw        $v0, 0xc($s5)
/* A2E96C 8024472C 46180000 */  add.s     $f0, $f0, $f24
/* A2E970 80244730 E4420008 */  swc1      $f2, 8($v0)
/* A2E974 80244734 8EA3000C */  lw        $v1, 0xc($s5)
/* A2E978 80244738 E460000C */  swc1      $f0, 0xc($v1)
/* A2E97C 8024473C 8FBF002C */  lw        $ra, 0x2c($sp)
/* A2E980 80244740 8FB60028 */  lw        $s6, 0x28($sp)
/* A2E984 80244744 8FB50024 */  lw        $s5, 0x24($sp)
/* A2E988 80244748 8FB40020 */  lw        $s4, 0x20($sp)
/* A2E98C 8024474C 8FB3001C */  lw        $s3, 0x1c($sp)
/* A2E990 80244750 8FB20018 */  lw        $s2, 0x18($sp)
/* A2E994 80244754 8FB10014 */  lw        $s1, 0x14($sp)
/* A2E998 80244758 8FB00010 */  lw        $s0, 0x10($sp)
/* A2E99C 8024475C D7B80040 */  ldc1      $f24, 0x40($sp)
/* A2E9A0 80244760 D7B60038 */  ldc1      $f22, 0x38($sp)
/* A2E9A4 80244764 D7B40030 */  ldc1      $f20, 0x30($sp)
/* A2E9A8 80244768 0000102D */  daddu     $v0, $zero, $zero
/* A2E9AC 8024476C 03E00008 */  jr        $ra
/* A2E9B0 80244770 27BD0048 */   addiu    $sp, $sp, 0x48

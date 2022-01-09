.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802185B0_4B17A0
/* 4B17A0 802185B0 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 4B17A4 802185B4 AFB20058 */  sw        $s2, 0x58($sp)
/* 4B17A8 802185B8 0080902D */  daddu     $s2, $a0, $zero
/* 4B17AC 802185BC AFBF005C */  sw        $ra, 0x5c($sp)
/* 4B17B0 802185C0 AFB10054 */  sw        $s1, 0x54($sp)
/* 4B17B4 802185C4 AFB00050 */  sw        $s0, 0x50($sp)
/* 4B17B8 802185C8 8E50000C */  lw        $s0, 0xc($s2)
/* 4B17BC 802185CC 0C09A75B */  jal       get_actor
/* 4B17C0 802185D0 24040204 */   addiu    $a0, $zero, 0x204
/* 4B17C4 802185D4 8C510094 */  lw        $s1, 0x94($v0)
/* 4B17C8 802185D8 24020003 */  addiu     $v0, $zero, 3
/* 4B17CC 802185DC 1222001D */  beq       $s1, $v0, .L80218654
/* 4B17D0 802185E0 2A220004 */   slti     $v0, $s1, 4
/* 4B17D4 802185E4 10400005 */  beqz      $v0, .L802185FC
/* 4B17D8 802185E8 24020002 */   addiu    $v0, $zero, 2
/* 4B17DC 802185EC 12220008 */  beq       $s1, $v0, .L80218610
/* 4B17E0 802185F0 0000202D */   daddu    $a0, $zero, $zero
/* 4B17E4 802185F4 080861D0 */  j         .L80218740
/* 4B17E8 802185F8 2622FFFF */   addiu    $v0, $s1, -1
.L802185FC:
/* 4B17EC 802185FC 24020004 */  addiu     $v0, $zero, 4
/* 4B17F0 80218600 1222002D */  beq       $s1, $v0, .L802186B8
/* 4B17F4 80218604 0000202D */   daddu    $a0, $zero, $zero
/* 4B17F8 80218608 080861D0 */  j         .L80218740
/* 4B17FC 8021860C 2622FFFF */   addiu    $v0, $s1, -1
.L80218610:
/* 4B1800 80218610 0C086144 */  jal       b_area_trd_part_2_green_ninja_koopa_UnkEnemyFunc
/* 4B1804 80218614 24040003 */   addiu    $a0, $zero, 3
/* 4B1808 80218618 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B180C 8021861C E7A00020 */  swc1      $f0, 0x20($sp)
/* 4B1810 80218620 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B1814 80218624 E7A00024 */  swc1      $f0, 0x24($sp)
/* 4B1818 80218628 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B181C 8021862C 24040006 */  addiu     $a0, $zero, 6
/* 4B1820 80218630 0C086144 */  jal       b_area_trd_part_2_green_ninja_koopa_UnkEnemyFunc
/* 4B1824 80218634 E7A00028 */   swc1     $f0, 0x28($sp)
/* 4B1828 80218638 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B182C 8021863C E7A0002C */  swc1      $f0, 0x2c($sp)
/* 4B1830 80218640 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B1834 80218644 E7A00030 */  swc1      $f0, 0x30($sp)
/* 4B1838 80218648 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B183C 8021864C 080861CE */  j         .L80218738
/* 4B1840 80218650 E7A00034 */   swc1     $f0, 0x34($sp)
.L80218654:
/* 4B1844 80218654 0C086144 */  jal       b_area_trd_part_2_green_ninja_koopa_UnkEnemyFunc
/* 4B1848 80218658 24040003 */   addiu    $a0, $zero, 3
/* 4B184C 8021865C C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B1850 80218660 E7A00020 */  swc1      $f0, 0x20($sp)
/* 4B1854 80218664 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B1858 80218668 E7A00024 */  swc1      $f0, 0x24($sp)
/* 4B185C 8021866C C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B1860 80218670 24040005 */  addiu     $a0, $zero, 5
/* 4B1864 80218674 0C086144 */  jal       b_area_trd_part_2_green_ninja_koopa_UnkEnemyFunc
/* 4B1868 80218678 E7A00028 */   swc1     $f0, 0x28($sp)
/* 4B186C 8021867C C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B1870 80218680 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 4B1874 80218684 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B1878 80218688 E7A00030 */  swc1      $f0, 0x30($sp)
/* 4B187C 8021868C C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B1880 80218690 24040006 */  addiu     $a0, $zero, 6
/* 4B1884 80218694 0C086144 */  jal       b_area_trd_part_2_green_ninja_koopa_UnkEnemyFunc
/* 4B1888 80218698 E7A00034 */   swc1     $f0, 0x34($sp)
/* 4B188C 8021869C C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B1890 802186A0 E7A00038 */  swc1      $f0, 0x38($sp)
/* 4B1894 802186A4 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B1898 802186A8 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 4B189C 802186AC C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B18A0 802186B0 080861CE */  j         .L80218738
/* 4B18A4 802186B4 E7A00040 */   swc1     $f0, 0x40($sp)
.L802186B8:
/* 4B18A8 802186B8 0C086144 */  jal       b_area_trd_part_2_green_ninja_koopa_UnkEnemyFunc
/* 4B18AC 802186BC 24040003 */   addiu    $a0, $zero, 3
/* 4B18B0 802186C0 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B18B4 802186C4 E7A00020 */  swc1      $f0, 0x20($sp)
/* 4B18B8 802186C8 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B18BC 802186CC E7A00024 */  swc1      $f0, 0x24($sp)
/* 4B18C0 802186D0 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B18C4 802186D4 24040004 */  addiu     $a0, $zero, 4
/* 4B18C8 802186D8 0C086144 */  jal       b_area_trd_part_2_green_ninja_koopa_UnkEnemyFunc
/* 4B18CC 802186DC E7A00028 */   swc1     $f0, 0x28($sp)
/* 4B18D0 802186E0 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B18D4 802186E4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 4B18D8 802186E8 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B18DC 802186EC E7A00030 */  swc1      $f0, 0x30($sp)
/* 4B18E0 802186F0 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B18E4 802186F4 24040005 */  addiu     $a0, $zero, 5
/* 4B18E8 802186F8 0C086144 */  jal       b_area_trd_part_2_green_ninja_koopa_UnkEnemyFunc
/* 4B18EC 802186FC E7A00034 */   swc1     $f0, 0x34($sp)
/* 4B18F0 80218700 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B18F4 80218704 E7A00038 */  swc1      $f0, 0x38($sp)
/* 4B18F8 80218708 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B18FC 8021870C E7A0003C */  swc1      $f0, 0x3c($sp)
/* 4B1900 80218710 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B1904 80218714 24040006 */  addiu     $a0, $zero, 6
/* 4B1908 80218718 0C086144 */  jal       b_area_trd_part_2_green_ninja_koopa_UnkEnemyFunc
/* 4B190C 8021871C E7A00040 */   swc1     $f0, 0x40($sp)
/* 4B1910 80218720 C4400138 */  lwc1      $f0, 0x138($v0)
/* 4B1914 80218724 E7A00044 */  swc1      $f0, 0x44($sp)
/* 4B1918 80218728 C440013C */  lwc1      $f0, 0x13c($v0)
/* 4B191C 8021872C E7A00048 */  swc1      $f0, 0x48($sp)
/* 4B1920 80218730 C4400140 */  lwc1      $f0, 0x140($v0)
/* 4B1924 80218734 E7A0004C */  swc1      $f0, 0x4c($sp)
.L80218738:
/* 4B1928 80218738 0000202D */  daddu     $a0, $zero, $zero
/* 4B192C 8021873C 2622FFFF */  addiu     $v0, $s1, -1
.L80218740:
/* 4B1930 80218740 1840002A */  blez      $v0, .L802187EC
/* 4B1934 80218744 0040482D */   daddu    $t1, $v0, $zero
/* 4B1938 80218748 27A80020 */  addiu     $t0, $sp, 0x20
/* 4B193C 8021874C 0100382D */  daddu     $a3, $t0, $zero
.L80218750:
/* 4B1940 80218750 0091102A */  slt       $v0, $a0, $s1
/* 4B1944 80218754 10400021 */  beqz      $v0, .L802187DC
/* 4B1948 80218758 0080302D */   daddu    $a2, $a0, $zero
/* 4B194C 8021875C 00E0282D */  daddu     $a1, $a3, $zero
/* 4B1950 80218760 00041040 */  sll       $v0, $a0, 1
/* 4B1954 80218764 00441021 */  addu      $v0, $v0, $a0
/* 4B1958 80218768 00021080 */  sll       $v0, $v0, 2
/* 4B195C 8021876C 00481821 */  addu      $v1, $v0, $t0
.L80218770:
/* 4B1960 80218770 C4A20000 */  lwc1      $f2, ($a1)
/* 4B1964 80218774 C4600000 */  lwc1      $f0, ($v1)
/* 4B1968 80218778 4600103C */  c.lt.s    $f2, $f0
/* 4B196C 8021877C 00000000 */  nop
/* 4B1970 80218780 45000013 */  bc1f      .L802187D0
/* 4B1974 80218784 24C60001 */   addiu    $a2, $a2, 1
/* 4B1978 80218788 8CAA0000 */  lw        $t2, ($a1)
/* 4B197C 8021878C 8CAB0004 */  lw        $t3, 4($a1)
/* 4B1980 80218790 8CAC0008 */  lw        $t4, 8($a1)
/* 4B1984 80218794 AFAA0010 */  sw        $t2, 0x10($sp)
/* 4B1988 80218798 AFAB0014 */  sw        $t3, 0x14($sp)
/* 4B198C 8021879C AFAC0018 */  sw        $t4, 0x18($sp)
/* 4B1990 802187A0 8C6A0000 */  lw        $t2, ($v1)
/* 4B1994 802187A4 8C6B0004 */  lw        $t3, 4($v1)
/* 4B1998 802187A8 8C6C0008 */  lw        $t4, 8($v1)
/* 4B199C 802187AC ACAA0000 */  sw        $t2, ($a1)
/* 4B19A0 802187B0 ACAB0004 */  sw        $t3, 4($a1)
/* 4B19A4 802187B4 ACAC0008 */  sw        $t4, 8($a1)
/* 4B19A8 802187B8 8FAA0010 */  lw        $t2, 0x10($sp)
/* 4B19AC 802187BC 8FAB0014 */  lw        $t3, 0x14($sp)
/* 4B19B0 802187C0 8FAC0018 */  lw        $t4, 0x18($sp)
/* 4B19B4 802187C4 AC6A0000 */  sw        $t2, ($v1)
/* 4B19B8 802187C8 AC6B0004 */  sw        $t3, 4($v1)
/* 4B19BC 802187CC AC6C0008 */  sw        $t4, 8($v1)
.L802187D0:
/* 4B19C0 802187D0 00D1102A */  slt       $v0, $a2, $s1
/* 4B19C4 802187D4 1440FFE6 */  bnez      $v0, .L80218770
/* 4B19C8 802187D8 2463000C */   addiu    $v1, $v1, 0xc
.L802187DC:
/* 4B19CC 802187DC 24840001 */  addiu     $a0, $a0, 1
/* 4B19D0 802187E0 0089102A */  slt       $v0, $a0, $t1
/* 4B19D4 802187E4 1440FFDA */  bnez      $v0, .L80218750
/* 4B19D8 802187E8 24E7000C */   addiu    $a3, $a3, 0xc
.L802187EC:
/* 4B19DC 802187EC 8E440148 */  lw        $a0, 0x148($s2)
/* 4B19E0 802187F0 0C09A75B */  jal       get_actor
/* 4B19E4 802187F4 00000000 */   nop
/* 4B19E8 802187F8 24040003 */  addiu     $a0, $zero, 3
/* 4B19EC 802187FC 8C43008C */  lw        $v1, 0x8c($v0)
/* 4B19F0 80218800 12240034 */  beq       $s1, $a0, .L802188D4
/* 4B19F4 80218804 2A220004 */   slti     $v0, $s1, 4
/* 4B19F8 80218808 10400005 */  beqz      $v0, .L80218820
/* 4B19FC 8021880C 24020002 */   addiu    $v0, $zero, 2
/* 4B1A00 80218810 12220008 */  beq       $s1, $v0, .L80218834
/* 4B1A04 80218814 00000000 */   nop
/* 4B1A08 80218818 080862CB */  j         .L80218B2C
/* 4B1A0C 8021881C 00000000 */   nop
.L80218820:
/* 4B1A10 80218820 24020004 */  addiu     $v0, $zero, 4
/* 4B1A14 80218824 1222006B */  beq       $s1, $v0, .L802189D4
/* 4B1A18 80218828 00000000 */   nop
/* 4B1A1C 8021882C 080862CB */  j         .L80218B2C
/* 4B1A20 80218830 00000000 */   nop
.L80218834:
/* 4B1A24 80218834 10640005 */  beq       $v1, $a0, .L8021884C
/* 4B1A28 80218838 24020006 */   addiu    $v0, $zero, 6
/* 4B1A2C 8021883C 10620014 */  beq       $v1, $v0, .L80218890
/* 4B1A30 80218840 00000000 */   nop
/* 4B1A34 80218844 080862CB */  j         .L80218B2C
/* 4B1A38 80218848 00000000 */   nop
.L8021884C:
/* 4B1A3C 8021884C 8E050000 */  lw        $a1, ($s0)
/* 4B1A40 80218850 26100004 */  addiu     $s0, $s0, 4
/* 4B1A44 80218854 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 4B1A48 80218858 4600010D */  trunc.w.s $f4, $f0
/* 4B1A4C 8021885C 44062000 */  mfc1      $a2, $f4
/* 4B1A50 80218860 0C0B2026 */  jal       evt_set_variable
/* 4B1A54 80218864 0240202D */   daddu    $a0, $s2, $zero
/* 4B1A58 80218868 8E050000 */  lw        $a1, ($s0)
/* 4B1A5C 8021886C 26100004 */  addiu     $s0, $s0, 4
/* 4B1A60 80218870 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 4B1A64 80218874 4600010D */  trunc.w.s $f4, $f0
/* 4B1A68 80218878 44062000 */  mfc1      $a2, $f4
/* 4B1A6C 8021887C 0C0B2026 */  jal       evt_set_variable
/* 4B1A70 80218880 0240202D */   daddu    $a0, $s2, $zero
/* 4B1A74 80218884 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 4B1A78 80218888 080862C6 */  j         .L80218B18
/* 4B1A7C 8021888C 0240202D */   daddu    $a0, $s2, $zero
.L80218890:
/* 4B1A80 80218890 8E050000 */  lw        $a1, ($s0)
/* 4B1A84 80218894 26100004 */  addiu     $s0, $s0, 4
/* 4B1A88 80218898 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 4B1A8C 8021889C 4600010D */  trunc.w.s $f4, $f0
/* 4B1A90 802188A0 44062000 */  mfc1      $a2, $f4
/* 4B1A94 802188A4 0C0B2026 */  jal       evt_set_variable
/* 4B1A98 802188A8 0240202D */   daddu    $a0, $s2, $zero
/* 4B1A9C 802188AC 8E050000 */  lw        $a1, ($s0)
/* 4B1AA0 802188B0 26100004 */  addiu     $s0, $s0, 4
/* 4B1AA4 802188B4 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 4B1AA8 802188B8 4600010D */  trunc.w.s $f4, $f0
/* 4B1AAC 802188BC 44062000 */  mfc1      $a2, $f4
/* 4B1AB0 802188C0 0C0B2026 */  jal       evt_set_variable
/* 4B1AB4 802188C4 0240202D */   daddu    $a0, $s2, $zero
/* 4B1AB8 802188C8 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 4B1ABC 802188CC 080862C6 */  j         .L80218B18
/* 4B1AC0 802188D0 0240202D */   daddu    $a0, $s2, $zero
.L802188D4:
/* 4B1AC4 802188D4 24020005 */  addiu     $v0, $zero, 5
/* 4B1AC8 802188D8 1062001C */  beq       $v1, $v0, .L8021894C
/* 4B1ACC 802188DC 28620006 */   slti     $v0, $v1, 6
/* 4B1AD0 802188E0 10400005 */  beqz      $v0, .L802188F8
/* 4B1AD4 802188E4 24020006 */   addiu    $v0, $zero, 6
/* 4B1AD8 802188E8 10640007 */  beq       $v1, $a0, .L80218908
/* 4B1ADC 802188EC 00000000 */   nop
/* 4B1AE0 802188F0 080862CB */  j         .L80218B2C
/* 4B1AE4 802188F4 00000000 */   nop
.L802188F8:
/* 4B1AE8 802188F8 10620025 */  beq       $v1, $v0, .L80218990
/* 4B1AEC 802188FC 00000000 */   nop
/* 4B1AF0 80218900 080862CB */  j         .L80218B2C
/* 4B1AF4 80218904 00000000 */   nop
.L80218908:
/* 4B1AF8 80218908 8E050000 */  lw        $a1, ($s0)
/* 4B1AFC 8021890C 26100004 */  addiu     $s0, $s0, 4
/* 4B1B00 80218910 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 4B1B04 80218914 4600010D */  trunc.w.s $f4, $f0
/* 4B1B08 80218918 44062000 */  mfc1      $a2, $f4
/* 4B1B0C 8021891C 0C0B2026 */  jal       evt_set_variable
/* 4B1B10 80218920 0240202D */   daddu    $a0, $s2, $zero
/* 4B1B14 80218924 8E050000 */  lw        $a1, ($s0)
/* 4B1B18 80218928 26100004 */  addiu     $s0, $s0, 4
/* 4B1B1C 8021892C C7A00024 */  lwc1      $f0, 0x24($sp)
/* 4B1B20 80218930 4600010D */  trunc.w.s $f4, $f0
/* 4B1B24 80218934 44062000 */  mfc1      $a2, $f4
/* 4B1B28 80218938 0C0B2026 */  jal       evt_set_variable
/* 4B1B2C 8021893C 0240202D */   daddu    $a0, $s2, $zero
/* 4B1B30 80218940 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 4B1B34 80218944 080862C6 */  j         .L80218B18
/* 4B1B38 80218948 0240202D */   daddu    $a0, $s2, $zero
.L8021894C:
/* 4B1B3C 8021894C 8E050000 */  lw        $a1, ($s0)
/* 4B1B40 80218950 26100004 */  addiu     $s0, $s0, 4
/* 4B1B44 80218954 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 4B1B48 80218958 4600010D */  trunc.w.s $f4, $f0
/* 4B1B4C 8021895C 44062000 */  mfc1      $a2, $f4
/* 4B1B50 80218960 0C0B2026 */  jal       evt_set_variable
/* 4B1B54 80218964 0240202D */   daddu    $a0, $s2, $zero
/* 4B1B58 80218968 8E050000 */  lw        $a1, ($s0)
/* 4B1B5C 8021896C 26100004 */  addiu     $s0, $s0, 4
/* 4B1B60 80218970 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 4B1B64 80218974 4600010D */  trunc.w.s $f4, $f0
/* 4B1B68 80218978 44062000 */  mfc1      $a2, $f4
/* 4B1B6C 8021897C 0C0B2026 */  jal       evt_set_variable
/* 4B1B70 80218980 0240202D */   daddu    $a0, $s2, $zero
/* 4B1B74 80218984 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 4B1B78 80218988 080862C6 */  j         .L80218B18
/* 4B1B7C 8021898C 0240202D */   daddu    $a0, $s2, $zero
.L80218990:
/* 4B1B80 80218990 8E050000 */  lw        $a1, ($s0)
/* 4B1B84 80218994 26100004 */  addiu     $s0, $s0, 4
/* 4B1B88 80218998 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 4B1B8C 8021899C 4600010D */  trunc.w.s $f4, $f0
/* 4B1B90 802189A0 44062000 */  mfc1      $a2, $f4
/* 4B1B94 802189A4 0C0B2026 */  jal       evt_set_variable
/* 4B1B98 802189A8 0240202D */   daddu    $a0, $s2, $zero
/* 4B1B9C 802189AC 8E050000 */  lw        $a1, ($s0)
/* 4B1BA0 802189B0 26100004 */  addiu     $s0, $s0, 4
/* 4B1BA4 802189B4 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 4B1BA8 802189B8 4600010D */  trunc.w.s $f4, $f0
/* 4B1BAC 802189BC 44062000 */  mfc1      $a2, $f4
/* 4B1BB0 802189C0 0C0B2026 */  jal       evt_set_variable
/* 4B1BB4 802189C4 0240202D */   daddu    $a0, $s2, $zero
/* 4B1BB8 802189C8 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 4B1BBC 802189CC 080862C6 */  j         .L80218B18
/* 4B1BC0 802189D0 0240202D */   daddu    $a0, $s2, $zero
.L802189D4:
/* 4B1BC4 802189D4 1071001E */  beq       $v1, $s1, .L80218A50
/* 4B1BC8 802189D8 28620005 */   slti     $v0, $v1, 5
/* 4B1BCC 802189DC 10400005 */  beqz      $v0, .L802189F4
/* 4B1BD0 802189E0 24020005 */   addiu    $v0, $zero, 5
/* 4B1BD4 802189E4 10640009 */  beq       $v1, $a0, .L80218A0C
/* 4B1BD8 802189E8 00000000 */   nop
/* 4B1BDC 802189EC 080862CB */  j         .L80218B2C
/* 4B1BE0 802189F0 00000000 */   nop
.L802189F4:
/* 4B1BE4 802189F4 10620027 */  beq       $v1, $v0, .L80218A94
/* 4B1BE8 802189F8 24020006 */   addiu    $v0, $zero, 6
/* 4B1BEC 802189FC 10620036 */  beq       $v1, $v0, .L80218AD8
/* 4B1BF0 80218A00 00000000 */   nop
/* 4B1BF4 80218A04 080862CB */  j         .L80218B2C
/* 4B1BF8 80218A08 00000000 */   nop
.L80218A0C:
/* 4B1BFC 80218A0C 8E050000 */  lw        $a1, ($s0)
/* 4B1C00 80218A10 26100004 */  addiu     $s0, $s0, 4
/* 4B1C04 80218A14 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 4B1C08 80218A18 4600010D */  trunc.w.s $f4, $f0
/* 4B1C0C 80218A1C 44062000 */  mfc1      $a2, $f4
/* 4B1C10 80218A20 0C0B2026 */  jal       evt_set_variable
/* 4B1C14 80218A24 0240202D */   daddu    $a0, $s2, $zero
/* 4B1C18 80218A28 8E050000 */  lw        $a1, ($s0)
/* 4B1C1C 80218A2C 26100004 */  addiu     $s0, $s0, 4
/* 4B1C20 80218A30 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 4B1C24 80218A34 4600010D */  trunc.w.s $f4, $f0
/* 4B1C28 80218A38 44062000 */  mfc1      $a2, $f4
/* 4B1C2C 80218A3C 0C0B2026 */  jal       evt_set_variable
/* 4B1C30 80218A40 0240202D */   daddu    $a0, $s2, $zero
/* 4B1C34 80218A44 C7A00028 */  lwc1      $f0, 0x28($sp)
/* 4B1C38 80218A48 080862C6 */  j         .L80218B18
/* 4B1C3C 80218A4C 0240202D */   daddu    $a0, $s2, $zero
.L80218A50:
/* 4B1C40 80218A50 8E050000 */  lw        $a1, ($s0)
/* 4B1C44 80218A54 26100004 */  addiu     $s0, $s0, 4
/* 4B1C48 80218A58 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 4B1C4C 80218A5C 4600010D */  trunc.w.s $f4, $f0
/* 4B1C50 80218A60 44062000 */  mfc1      $a2, $f4
/* 4B1C54 80218A64 0C0B2026 */  jal       evt_set_variable
/* 4B1C58 80218A68 0240202D */   daddu    $a0, $s2, $zero
/* 4B1C5C 80218A6C 8E050000 */  lw        $a1, ($s0)
/* 4B1C60 80218A70 26100004 */  addiu     $s0, $s0, 4
/* 4B1C64 80218A74 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 4B1C68 80218A78 4600010D */  trunc.w.s $f4, $f0
/* 4B1C6C 80218A7C 44062000 */  mfc1      $a2, $f4
/* 4B1C70 80218A80 0C0B2026 */  jal       evt_set_variable
/* 4B1C74 80218A84 0240202D */   daddu    $a0, $s2, $zero
/* 4B1C78 80218A88 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 4B1C7C 80218A8C 080862C6 */  j         .L80218B18
/* 4B1C80 80218A90 0240202D */   daddu    $a0, $s2, $zero
.L80218A94:
/* 4B1C84 80218A94 8E050000 */  lw        $a1, ($s0)
/* 4B1C88 80218A98 26100004 */  addiu     $s0, $s0, 4
/* 4B1C8C 80218A9C C7A00038 */  lwc1      $f0, 0x38($sp)
/* 4B1C90 80218AA0 4600010D */  trunc.w.s $f4, $f0
/* 4B1C94 80218AA4 44062000 */  mfc1      $a2, $f4
/* 4B1C98 80218AA8 0C0B2026 */  jal       evt_set_variable
/* 4B1C9C 80218AAC 0240202D */   daddu    $a0, $s2, $zero
/* 4B1CA0 80218AB0 8E050000 */  lw        $a1, ($s0)
/* 4B1CA4 80218AB4 26100004 */  addiu     $s0, $s0, 4
/* 4B1CA8 80218AB8 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 4B1CAC 80218ABC 4600010D */  trunc.w.s $f4, $f0
/* 4B1CB0 80218AC0 44062000 */  mfc1      $a2, $f4
/* 4B1CB4 80218AC4 0C0B2026 */  jal       evt_set_variable
/* 4B1CB8 80218AC8 0240202D */   daddu    $a0, $s2, $zero
/* 4B1CBC 80218ACC C7A00040 */  lwc1      $f0, 0x40($sp)
/* 4B1CC0 80218AD0 080862C6 */  j         .L80218B18
/* 4B1CC4 80218AD4 0240202D */   daddu    $a0, $s2, $zero
.L80218AD8:
/* 4B1CC8 80218AD8 8E050000 */  lw        $a1, ($s0)
/* 4B1CCC 80218ADC 26100004 */  addiu     $s0, $s0, 4
/* 4B1CD0 80218AE0 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 4B1CD4 80218AE4 4600010D */  trunc.w.s $f4, $f0
/* 4B1CD8 80218AE8 44062000 */  mfc1      $a2, $f4
/* 4B1CDC 80218AEC 0C0B2026 */  jal       evt_set_variable
/* 4B1CE0 80218AF0 0240202D */   daddu    $a0, $s2, $zero
/* 4B1CE4 80218AF4 8E050000 */  lw        $a1, ($s0)
/* 4B1CE8 80218AF8 26100004 */  addiu     $s0, $s0, 4
/* 4B1CEC 80218AFC C7A00048 */  lwc1      $f0, 0x48($sp)
/* 4B1CF0 80218B00 4600010D */  trunc.w.s $f4, $f0
/* 4B1CF4 80218B04 44062000 */  mfc1      $a2, $f4
/* 4B1CF8 80218B08 0C0B2026 */  jal       evt_set_variable
/* 4B1CFC 80218B0C 0240202D */   daddu    $a0, $s2, $zero
/* 4B1D00 80218B10 0240202D */  daddu     $a0, $s2, $zero
/* 4B1D04 80218B14 C7A0004C */  lwc1      $f0, 0x4c($sp)
.L80218B18:
/* 4B1D08 80218B18 8E050000 */  lw        $a1, ($s0)
/* 4B1D0C 80218B1C 4600010D */  trunc.w.s $f4, $f0
/* 4B1D10 80218B20 44062000 */  mfc1      $a2, $f4
/* 4B1D14 80218B24 0C0B2026 */  jal       evt_set_variable
/* 4B1D18 80218B28 00000000 */   nop
.L80218B2C:
/* 4B1D1C 80218B2C 8FBF005C */  lw        $ra, 0x5c($sp)
/* 4B1D20 80218B30 8FB20058 */  lw        $s2, 0x58($sp)
/* 4B1D24 80218B34 8FB10054 */  lw        $s1, 0x54($sp)
/* 4B1D28 80218B38 8FB00050 */  lw        $s0, 0x50($sp)
/* 4B1D2C 80218B3C 24020002 */  addiu     $v0, $zero, 2
/* 4B1D30 80218B40 03E00008 */  jr        $ra
/* 4B1D34 80218B44 27BD0060 */   addiu    $sp, $sp, 0x60

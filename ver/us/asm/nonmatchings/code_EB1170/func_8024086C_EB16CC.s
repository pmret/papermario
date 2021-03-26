.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024086C_EB16CC
/* EB16CC 8024086C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* EB16D0 80240870 AFB1001C */  sw        $s1, 0x1c($sp)
/* EB16D4 80240874 0080882D */  daddu     $s1, $a0, $zero
/* EB16D8 80240878 AFBF0034 */  sw        $ra, 0x34($sp)
/* EB16DC 8024087C AFB60030 */  sw        $s6, 0x30($sp)
/* EB16E0 80240880 AFB5002C */  sw        $s5, 0x2c($sp)
/* EB16E4 80240884 AFB40028 */  sw        $s4, 0x28($sp)
/* EB16E8 80240888 AFB30024 */  sw        $s3, 0x24($sp)
/* EB16EC 8024088C AFB20020 */  sw        $s2, 0x20($sp)
/* EB16F0 80240890 AFB00018 */  sw        $s0, 0x18($sp)
/* EB16F4 80240894 F7B60040 */  sdc1      $f22, 0x40($sp)
/* EB16F8 80240898 F7B40038 */  sdc1      $f20, 0x38($sp)
/* EB16FC 8024089C 8E30000C */  lw        $s0, 0xc($s1)
/* EB1700 802408A0 8E160000 */  lw        $s6, ($s0)
/* EB1704 802408A4 26100004 */  addiu     $s0, $s0, 4
/* EB1708 802408A8 0C0B53A3 */  jal       dead_get_variable
/* EB170C 802408AC 02C0282D */   daddu    $a1, $s6, $zero
/* EB1710 802408B0 44820000 */  mtc1      $v0, $f0
/* EB1714 802408B4 00000000 */  nop
/* EB1718 802408B8 46800020 */  cvt.s.w   $f0, $f0
/* EB171C 802408BC E7A00010 */  swc1      $f0, 0x10($sp)
/* EB1720 802408C0 8E140000 */  lw        $s4, ($s0)
/* EB1724 802408C4 26100004 */  addiu     $s0, $s0, 4
/* EB1728 802408C8 0220202D */  daddu     $a0, $s1, $zero
/* EB172C 802408CC 0C0B53A3 */  jal       dead_get_variable
/* EB1730 802408D0 0280282D */   daddu    $a1, $s4, $zero
/* EB1734 802408D4 0220202D */  daddu     $a0, $s1, $zero
/* EB1738 802408D8 8E150000 */  lw        $s5, ($s0)
/* EB173C 802408DC 4482B000 */  mtc1      $v0, $f22
/* EB1740 802408E0 00000000 */  nop
/* EB1744 802408E4 4680B5A0 */  cvt.s.w   $f22, $f22
/* EB1748 802408E8 0C0B53A3 */  jal       dead_get_variable
/* EB174C 802408EC 02A0282D */   daddu    $a1, $s5, $zero
/* EB1750 802408F0 2404FFFC */  addiu     $a0, $zero, -4
/* EB1754 802408F4 44820000 */  mtc1      $v0, $f0
/* EB1758 802408F8 00000000 */  nop
/* EB175C 802408FC 46800020 */  cvt.s.w   $f0, $f0
/* EB1760 80240900 0C00F92F */  jal       func_8003E4BC
/* EB1764 80240904 E7A00014 */   swc1     $f0, 0x14($sp)
/* EB1768 80240908 3C048008 */  lui       $a0, %hi(D_8007C760)
/* EB176C 8024090C 8C84C760 */  lw        $a0, %lo(D_8007C760)($a0)
/* EB1770 80240910 3C014334 */  lui       $at, 0x4334
/* EB1774 80240914 44816000 */  mtc1      $at, $f12
/* EB1778 80240918 00041880 */  sll       $v1, $a0, 2
/* EB177C 8024091C 00641821 */  addu      $v1, $v1, $a0
/* EB1780 80240920 00031880 */  sll       $v1, $v1, 2
/* EB1784 80240924 00641823 */  subu      $v1, $v1, $a0
/* EB1788 80240928 000320C0 */  sll       $a0, $v1, 3
/* EB178C 8024092C 00641821 */  addu      $v1, $v1, $a0
/* EB1790 80240930 000318C0 */  sll       $v1, $v1, 3
/* EB1794 80240934 3C01800C */  lui       $at, %hi(D_800B8DEC)
/* EB1798 80240938 00230821 */  addu      $at, $at, $v1
/* EB179C 8024093C C4208DEC */  lwc1      $f0, %lo(D_800B8DEC)($at)
/* EB17A0 80240940 460C0300 */  add.s     $f12, $f0, $f12
/* EB17A4 80240944 0C00AB85 */  jal       func_8002AE14
/* EB17A8 80240948 0040982D */   daddu    $s3, $v0, $zero
/* EB17AC 8024094C 27B00010 */  addiu     $s0, $sp, 0x10
/* EB17B0 80240950 0200202D */  daddu     $a0, $s0, $zero
/* EB17B4 80240954 27B20014 */  addiu     $s2, $sp, 0x14
/* EB17B8 80240958 0240282D */  daddu     $a1, $s2, $zero
/* EB17BC 8024095C 3C064170 */  lui       $a2, 0x4170
/* EB17C0 80240960 8E67000C */  lw        $a3, 0xc($s3)
/* EB17C4 80240964 0C00ACA3 */  jal       func_8002B28C
/* EB17C8 80240968 46000506 */   mov.s    $f20, $f0
/* EB17CC 8024096C 0200202D */  daddu     $a0, $s0, $zero
/* EB17D0 80240970 3C064120 */  lui       $a2, 0x4120
/* EB17D4 80240974 4407A000 */  mfc1      $a3, $f20
/* EB17D8 80240978 0C00ACA3 */  jal       func_8002B28C
/* EB17DC 8024097C 0240282D */   daddu    $a1, $s2, $zero
/* EB17E0 80240980 0220202D */  daddu     $a0, $s1, $zero
/* EB17E4 80240984 C7A00010 */  lwc1      $f0, 0x10($sp)
/* EB17E8 80240988 4600008D */  trunc.w.s $f2, $f0
/* EB17EC 8024098C 44061000 */  mfc1      $a2, $f2
/* EB17F0 80240990 0C0B551A */  jal       dead_set_variable
/* EB17F4 80240994 02C0282D */   daddu    $a1, $s6, $zero
/* EB17F8 80240998 0220202D */  daddu     $a0, $s1, $zero
/* EB17FC 8024099C 4600B08D */  trunc.w.s $f2, $f22
/* EB1800 802409A0 44061000 */  mfc1      $a2, $f2
/* EB1804 802409A4 0C0B551A */  jal       dead_set_variable
/* EB1808 802409A8 0280282D */   daddu    $a1, $s4, $zero
/* EB180C 802409AC 0220202D */  daddu     $a0, $s1, $zero
/* EB1810 802409B0 C7A00014 */  lwc1      $f0, 0x14($sp)
/* EB1814 802409B4 4600008D */  trunc.w.s $f2, $f0
/* EB1818 802409B8 44061000 */  mfc1      $a2, $f2
/* EB181C 802409BC 0C0B551A */  jal       dead_set_variable
/* EB1820 802409C0 02A0282D */   daddu    $a1, $s5, $zero
/* EB1824 802409C4 8FBF0034 */  lw        $ra, 0x34($sp)
/* EB1828 802409C8 8FB60030 */  lw        $s6, 0x30($sp)
/* EB182C 802409CC 8FB5002C */  lw        $s5, 0x2c($sp)
/* EB1830 802409D0 8FB40028 */  lw        $s4, 0x28($sp)
/* EB1834 802409D4 8FB30024 */  lw        $s3, 0x24($sp)
/* EB1838 802409D8 8FB20020 */  lw        $s2, 0x20($sp)
/* EB183C 802409DC 8FB1001C */  lw        $s1, 0x1c($sp)
/* EB1840 802409E0 8FB00018 */  lw        $s0, 0x18($sp)
/* EB1844 802409E4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* EB1848 802409E8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* EB184C 802409EC 24020002 */  addiu     $v0, $zero, 2
/* EB1850 802409F0 03E00008 */  jr        $ra
/* EB1854 802409F4 27BD0048 */   addiu    $sp, $sp, 0x48

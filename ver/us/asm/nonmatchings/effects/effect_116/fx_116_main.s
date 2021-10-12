.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_116_main
/* 3E1690 E00E8000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 3E1694 E00E8004 AFB20030 */  sw        $s2, 0x30($sp)
/* 3E1698 E00E8008 0080902D */  daddu     $s2, $a0, $zero
/* 3E169C E00E800C F7BE0060 */  sdc1      $f30, 0x60($sp)
/* 3E16A0 E00E8010 4485F000 */  mtc1      $a1, $f30
/* 3E16A4 E00E8014 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E16A8 E00E8018 F7BC0058 */  sdc1      $f28, 0x58($sp)
/* 3E16AC E00E801C C7BC0084 */  lwc1      $f28, 0x84($sp)
/* 3E16B0 E00E8020 3C02E00F */  lui       $v0, %hi(fx_116_init)
/* 3E16B4 E00E8024 2442825C */  addiu     $v0, $v0, %lo(fx_116_init)
/* 3E16B8 E00E8028 AFA20018 */  sw        $v0, 0x18($sp)
/* 3E16BC E00E802C 3C02E00F */  lui       $v0, %hi(fx_116_update)
/* 3E16C0 E00E8030 24428264 */  addiu     $v0, $v0, %lo(fx_116_update)
/* 3E16C4 E00E8034 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E16C8 E00E8038 3C02E00F */  lui       $v0, %hi(fx_116_render)
/* 3E16CC E00E803C 24428374 */  addiu     $v0, $v0, %lo(fx_116_render)
/* 3E16D0 E00E8040 AFA20020 */  sw        $v0, 0x20($sp)
/* 3E16D4 E00E8044 24020074 */  addiu     $v0, $zero, 0x74
/* 3E16D8 E00E8048 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3E16DC E00E804C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3E16E0 E00E8050 AFB00028 */  sw        $s0, 0x28($sp)
/* 3E16E4 E00E8054 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 3E16E8 E00E8058 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3E16EC E00E805C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3E16F0 E00E8060 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3E16F4 E00E8064 AFA60070 */  sw        $a2, 0x70($sp)
/* 3E16F8 E00E8068 AFA70074 */  sw        $a3, 0x74($sp)
/* 3E16FC E00E806C AFA00010 */  sw        $zero, 0x10($sp)
/* 3E1700 E00E8070 AFA00024 */  sw        $zero, 0x24($sp)
/* 3E1704 E00E8074 0C080124 */  jal       shim_create_effect_instance
/* 3E1708 E00E8078 AFA20014 */   sw       $v0, 0x14($sp)
/* 3E170C E00E807C 24040048 */  addiu     $a0, $zero, 0x48
/* 3E1710 E00E8080 24030001 */  addiu     $v1, $zero, 1
/* 3E1714 E00E8084 0040882D */  daddu     $s1, $v0, $zero
/* 3E1718 E00E8088 0C08012C */  jal       shim_general_heap_malloc
/* 3E171C E00E808C AE230008 */   sw       $v1, 8($s1)
/* 3E1720 E00E8090 0040802D */  daddu     $s0, $v0, $zero
/* 3E1724 E00E8094 16000003 */  bnez      $s0, .LE00E80A4
/* 3E1728 E00E8098 AE22000C */   sw       $v0, 0xc($s1)
.LE00E809C:
/* 3E172C E00E809C 0803A027 */  j         .LE00E809C
/* 3E1730 E00E80A0 00000000 */   nop
.LE00E80A4:
/* 3E1734 E00E80A4 C7A00078 */  lwc1      $f0, 0x78($sp)
/* 3E1738 E00E80A8 461E0601 */  sub.s     $f24, $f0, $f30
/* 3E173C E00E80AC 4618C082 */  mul.s     $f2, $f24, $f24
/* 3E1740 E00E80B0 00000000 */  nop
/* 3E1744 E00E80B4 C7A60070 */  lwc1      $f6, 0x70($sp)
/* 3E1748 E00E80B8 C7A0007C */  lwc1      $f0, 0x7c($sp)
/* 3E174C E00E80BC 46060581 */  sub.s     $f22, $f0, $f6
/* 3E1750 E00E80C0 4616B102 */  mul.s     $f4, $f22, $f22
/* 3E1754 E00E80C4 00000000 */  nop
/* 3E1758 E00E80C8 C7A00080 */  lwc1      $f0, 0x80($sp)
/* 3E175C E00E80CC C7A60074 */  lwc1      $f6, 0x74($sp)
/* 3E1760 E00E80D0 46060501 */  sub.s     $f20, $f0, $f6
/* 3E1764 E00E80D4 4614A002 */  mul.s     $f0, $f20, $f20
/* 3E1768 E00E80D8 00000000 */  nop
/* 3E176C E00E80DC 46041080 */  add.s     $f2, $f2, $f4
/* 3E1770 E00E80E0 4480D000 */  mtc1      $zero, $f26
/* 3E1774 E00E80E4 46001300 */  add.s     $f12, $f2, $f0
/* 3E1778 E00E80E8 AE120000 */  sw        $s2, ($s0)
/* 3E177C E00E80EC 461A6032 */  c.eq.s    $f12, $f26
/* 3E1780 E00E80F0 00000000 */  nop
/* 3E1784 E00E80F4 45010004 */  bc1t      .LE00E8108
/* 3E1788 E00E80F8 AE000020 */   sw       $zero, 0x20($s0)
/* 3E178C E00E80FC 0C080154 */  jal       shim_sqrtf
/* 3E1790 E00E8100 00000000 */   nop
/* 3E1794 E00E8104 46000306 */  mov.s     $f12, $f0
.LE00E8108:
/* 3E1798 E00E8108 461CD03C */  c.lt.s    $f26, $f28
/* 3E179C E00E810C 00000000 */  nop
/* 3E17A0 E00E8110 45000005 */  bc1f      .LE00E8128
/* 3E17A4 E00E8114 0000102D */   daddu    $v0, $zero, $zero
/* 3E17A8 E00E8118 461C6003 */  div.s     $f0, $f12, $f28
/* 3E17AC E00E811C 4600018D */  trunc.w.s $f6, $f0
/* 3E17B0 E00E8120 44023000 */  mfc1      $v0, $f6
/* 3E17B4 E00E8124 00000000 */  nop
.LE00E8128:
/* 3E17B8 E00E8128 50400011 */  beql      $v0, $zero, .LE00E8170
/* 3E17BC E00E812C AE000010 */   sw       $zero, 0x10($s0)
/* 3E17C0 E00E8130 3C013F80 */  lui       $at, 0x3f80
/* 3E17C4 E00E8134 44811000 */  mtc1      $at, $f2
/* 3E17C8 E00E8138 44820000 */  mtc1      $v0, $f0
/* 3E17CC E00E813C 00000000 */  nop
/* 3E17D0 E00E8140 46800020 */  cvt.s.w   $f0, $f0
/* 3E17D4 E00E8144 46001303 */  div.s     $f12, $f2, $f0
/* 3E17D8 E00E8148 460CC002 */  mul.s     $f0, $f24, $f12
/* 3E17DC E00E814C 00000000 */  nop
/* 3E17E0 E00E8150 460CB082 */  mul.s     $f2, $f22, $f12
/* 3E17E4 E00E8154 00000000 */  nop
/* 3E17E8 E00E8158 460CA102 */  mul.s     $f4, $f20, $f12
/* 3E17EC E00E815C 00000000 */  nop
/* 3E17F0 E00E8160 E6000010 */  swc1      $f0, 0x10($s0)
/* 3E17F4 E00E8164 E6020014 */  swc1      $f2, 0x14($s0)
/* 3E17F8 E00E8168 0803A05E */  j         .LE00E8178
/* 3E17FC E00E816C E6040018 */   swc1     $f4, 0x18($s0)
.LE00E8170:
/* 3E1800 E00E8170 AE000014 */  sw        $zero, 0x14($s0)
/* 3E1804 E00E8174 AE000018 */  sw        $zero, 0x18($s0)
.LE00E8178:
/* 3E1808 E00E8178 04420001 */  bltzl     $v0, .LE00E8180
/* 3E180C E00E817C 240203E8 */   addiu    $v0, $zero, 0x3e8
.LE00E8180:
/* 3E1810 E00E8180 AE02001C */  sw        $v0, 0x1c($s0)
/* 3E1814 E00E8184 AE000030 */  sw        $zero, 0x30($s0)
/* 3E1818 E00E8188 E61E0004 */  swc1      $f30, 4($s0)
/* 3E181C E00E818C C7A60070 */  lwc1      $f6, 0x70($sp)
/* 3E1820 E00E8190 E6060008 */  swc1      $f6, 8($s0)
/* 3E1824 E00E8194 C7A60074 */  lwc1      $f6, 0x74($sp)
/* 3E1828 E00E8198 E606000C */  swc1      $f6, 0xc($s0)
/* 3E182C E00E819C C7A00088 */  lwc1      $f0, 0x88($sp)
/* 3E1830 E00E81A0 24020001 */  addiu     $v0, $zero, 1
/* 3E1834 E00E81A4 12420016 */  beq       $s2, $v0, .LE00E8200
/* 3E1838 E00E81A8 E6000044 */   swc1     $f0, 0x44($s0)
/* 3E183C E00E81AC 2A420002 */  slti      $v0, $s2, 2
/* 3E1840 E00E81B0 10400005 */  beqz      $v0, .LE00E81C8
/* 3E1844 E00E81B4 24020002 */   addiu    $v0, $zero, 2
/* 3E1848 E00E81B8 12400005 */  beqz      $s2, .LE00E81D0
/* 3E184C E00E81BC 240200FF */   addiu    $v0, $zero, 0xff
/* 3E1850 E00E81C0 0803A082 */  j         .LE00E8208
/* 3E1854 E00E81C4 240300DC */   addiu    $v1, $zero, 0xdc
.LE00E81C8:
/* 3E1858 E00E81C8 1642000E */  bne       $s2, $v0, .LE00E8204
/* 3E185C E00E81CC 240200FF */   addiu    $v0, $zero, 0xff
.LE00E81D0:
/* 3E1860 E00E81D0 240300D7 */  addiu     $v1, $zero, 0xd7
/* 3E1864 E00E81D4 240200B9 */  addiu     $v0, $zero, 0xb9
/* 3E1868 E00E81D8 AE02002C */  sw        $v0, 0x2c($s0)
/* 3E186C E00E81DC 240200C8 */  addiu     $v0, $zero, 0xc8
/* 3E1870 E00E81E0 AE020038 */  sw        $v0, 0x38($s0)
/* 3E1874 E00E81E4 24020064 */  addiu     $v0, $zero, 0x64
/* 3E1878 E00E81E8 AE02003C */  sw        $v0, 0x3c($s0)
/* 3E187C E00E81EC 240200FF */  addiu     $v0, $zero, 0xff
/* 3E1880 E00E81F0 AE030024 */  sw        $v1, 0x24($s0)
/* 3E1884 E00E81F4 AE030028 */  sw        $v1, 0x28($s0)
/* 3E1888 E00E81F8 0803A089 */  j         .LE00E8224
/* 3E188C E00E81FC AE030034 */   sw       $v1, 0x34($s0)
.LE00E8200:
/* 3E1890 E00E8200 240200FF */  addiu     $v0, $zero, 0xff
.LE00E8204:
/* 3E1894 E00E8204 240300DC */  addiu     $v1, $zero, 0xdc
.LE00E8208:
/* 3E1898 E00E8208 AE030034 */  sw        $v1, 0x34($s0)
/* 3E189C E00E820C 240300F5 */  addiu     $v1, $zero, 0xf5
/* 3E18A0 E00E8210 AE020024 */  sw        $v0, 0x24($s0)
/* 3E18A4 E00E8214 AE020028 */  sw        $v0, 0x28($s0)
/* 3E18A8 E00E8218 AE02002C */  sw        $v0, 0x2c($s0)
/* 3E18AC E00E821C AE030038 */  sw        $v1, 0x38($s0)
/* 3E18B0 E00E8220 AE02003C */  sw        $v0, 0x3c($s0)
.LE00E8224:
/* 3E18B4 E00E8224 AE020040 */  sw        $v0, 0x40($s0)
/* 3E18B8 E00E8228 0220102D */  daddu     $v0, $s1, $zero
/* 3E18BC E00E822C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3E18C0 E00E8230 8FB20030 */  lw        $s2, 0x30($sp)
/* 3E18C4 E00E8234 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3E18C8 E00E8238 8FB00028 */  lw        $s0, 0x28($sp)
/* 3E18CC E00E823C D7BE0060 */  ldc1      $f30, 0x60($sp)
/* 3E18D0 E00E8240 D7BC0058 */  ldc1      $f28, 0x58($sp)
/* 3E18D4 E00E8244 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 3E18D8 E00E8248 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3E18DC E00E824C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3E18E0 E00E8250 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3E18E4 E00E8254 03E00008 */  jr        $ra
/* 3E18E8 E00E8258 27BD0068 */   addiu    $sp, $sp, 0x68

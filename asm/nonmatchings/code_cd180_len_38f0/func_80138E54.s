.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80138E54
/* CF554 80138E54 27BDFF78 */  addiu     $sp, $sp, -0x88
/* CF558 80138E58 F7B80068 */  sdc1      $f24, 0x68($sp)
/* CF55C 80138E5C 4487C000 */  mtc1      $a3, $f24
/* CF560 80138E60 44800000 */  mtc1      $zero, $f0
/* CF564 80138E64 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CF568 80138E68 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CF56C 80138E6C F7BE0080 */  sdc1      $f30, 0x80($sp)
/* CF570 80138E70 C7BE0098 */  lwc1      $f30, 0x98($sp)
/* CF574 80138E74 AFA40088 */  sw        $a0, 0x88($sp)
/* CF578 80138E78 3C04800B */  lui       $a0, %hi(gCameras)
/* CF57C 80138E7C 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* CF580 80138E80 AFBF0054 */  sw        $ra, 0x54($sp)
/* CF584 80138E84 AFBE0050 */  sw        $fp, 0x50($sp)
/* CF588 80138E88 AFB7004C */  sw        $s7, 0x4c($sp)
/* CF58C 80138E8C AFB60048 */  sw        $s6, 0x48($sp)
/* CF590 80138E90 AFB50044 */  sw        $s5, 0x44($sp)
/* CF594 80138E94 AFB40040 */  sw        $s4, 0x40($sp)
/* CF598 80138E98 AFB3003C */  sw        $s3, 0x3c($sp)
/* CF59C 80138E9C AFB20038 */  sw        $s2, 0x38($sp)
/* CF5A0 80138EA0 AFB10034 */  sw        $s1, 0x34($sp)
/* CF5A4 80138EA4 AFB00030 */  sw        $s0, 0x30($sp)
/* CF5A8 80138EA8 F7BC0078 */  sdc1      $f28, 0x78($sp)
/* CF5AC 80138EAC F7BA0070 */  sdc1      $f26, 0x70($sp)
/* CF5B0 80138EB0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* CF5B4 80138EB4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* CF5B8 80138EB8 AFA5008C */  sw        $a1, 0x8c($sp)
/* CF5BC 80138EBC AFA60090 */  sw        $a2, 0x90($sp)
/* CF5C0 80138EC0 00031080 */  sll       $v0, $v1, 2
/* CF5C4 80138EC4 00431021 */  addu      $v0, $v0, $v1
/* CF5C8 80138EC8 00021080 */  sll       $v0, $v0, 2
/* CF5CC 80138ECC 00431023 */  subu      $v0, $v0, $v1
/* CF5D0 80138ED0 000218C0 */  sll       $v1, $v0, 3
/* CF5D4 80138ED4 00431021 */  addu      $v0, $v0, $v1
/* CF5D8 80138ED8 000210C0 */  sll       $v0, $v0, 3
/* CF5DC 80138EDC 4600C032 */  c.eq.s    $f24, $f0
/* CF5E0 80138EE0 00000000 */  nop       
/* CF5E4 80138EE4 450103F8 */  bc1t      .L80139EC8
/* CF5E8 80138EE8 0044F021 */   addu     $fp, $v0, $a0
/* CF5EC 80138EEC 8FAD0088 */  lw        $t5, 0x88($sp)
/* CF5F0 80138EF0 15A00011 */  bnez      $t5, .L80138F38
/* CF5F4 80138EF4 00000000 */   nop      
/* CF5F8 80138EF8 3C01437F */  lui       $at, 0x437f
/* CF5FC 80138EFC 44812000 */  mtc1      $at, $f4
/* CF600 80138F00 00000000 */  nop       
/* CF604 80138F04 46182001 */  sub.s     $f0, $f4, $f24
/* CF608 80138F08 3C014120 */  lui       $at, 0x4120
/* CF60C 80138F0C 44811000 */  mtc1      $at, $f2
/* CF610 80138F10 00000000 */  nop       
/* CF614 80138F14 46020002 */  mul.s     $f0, $f0, $f2
/* CF618 80138F18 00000000 */  nop       
/* CF61C 80138F1C 3C018015 */  lui       $at, 0x8015
/* CF620 80138F20 D4220F80 */  ldc1      $f2, 0xf80($at)
/* CF624 80138F24 46040003 */  div.s     $f0, $f0, $f4
/* CF628 80138F28 46000021 */  cvt.d.s   $f0, $f0
/* CF62C 80138F2C 46220000 */  add.d     $f0, $f0, $f2
/* CF630 80138F30 0804E400 */  j         .L80139000
/* CF634 80138F34 462005A0 */   cvt.s.d  $f22, $f0
.L80138F38:
/* CF638 80138F38 97C2000A */  lhu       $v0, 0xa($fp)
/* CF63C 80138F3C 3C01437F */  lui       $at, 0x437f
/* CF640 80138F40 44814000 */  mtc1      $at, $f8
/* CF644 80138F44 8FAD008C */  lw        $t5, 0x8c($sp)
/* CF648 80138F48 3C014118 */  lui       $at, 0x4118
/* CF64C 80138F4C 44813000 */  mtc1      $at, $f6
/* CF650 80138F50 97C4000C */  lhu       $a0, 0xc($fp)
/* CF654 80138F54 00021400 */  sll       $v0, $v0, 0x10
/* CF658 80138F58 00021C03 */  sra       $v1, $v0, 0x10
/* CF65C 80138F5C 000217C2 */  srl       $v0, $v0, 0x1f
/* CF660 80138F60 00621821 */  addu      $v1, $v1, $v0
/* CF664 80138F64 00031843 */  sra       $v1, $v1, 1
/* CF668 80138F68 46184101 */  sub.s     $f4, $f8, $f24
/* CF66C 80138F6C 006D1823 */  subu      $v1, $v1, $t5
/* CF670 80138F70 44831000 */  mtc1      $v1, $f2
/* CF674 80138F74 00000000 */  nop       
/* CF678 80138F78 468010A0 */  cvt.s.w   $f2, $f2
/* CF67C 80138F7C 46062182 */  mul.s     $f6, $f4, $f6
/* CF680 80138F80 00000000 */  nop       
/* CF684 80138F84 00042400 */  sll       $a0, $a0, 0x10
/* CF688 80138F88 00041403 */  sra       $v0, $a0, 0x10
/* CF68C 80138F8C 000427C2 */  srl       $a0, $a0, 0x1f
/* CF690 80138F90 00441021 */  addu      $v0, $v0, $a0
/* CF694 80138F94 46041082 */  mul.s     $f2, $f2, $f4
/* CF698 80138F98 00000000 */  nop       
/* CF69C 80138F9C 8FAD0090 */  lw        $t5, 0x90($sp)
/* CF6A0 80138FA0 00021043 */  sra       $v0, $v0, 1
/* CF6A4 80138FA4 004D1023 */  subu      $v0, $v0, $t5
/* CF6A8 80138FA8 44820000 */  mtc1      $v0, $f0
/* CF6AC 80138FAC 00000000 */  nop       
/* CF6B0 80138FB0 46800020 */  cvt.s.w   $f0, $f0
/* CF6B4 80138FB4 46040002 */  mul.s     $f0, $f0, $f4
/* CF6B8 80138FB8 00000000 */  nop       
/* CF6BC 80138FBC C7A4008C */  lwc1      $f4, 0x8c($sp)
/* CF6C0 80138FC0 46802120 */  cvt.s.w   $f4, $f4
/* CF6C4 80138FC4 46081083 */  div.s     $f2, $f2, $f8
/* CF6C8 80138FC8 46022100 */  add.s     $f4, $f4, $f2
/* CF6CC 80138FCC 448D1000 */  mtc1      $t5, $f2
/* CF6D0 80138FD0 00000000 */  nop       
/* CF6D4 80138FD4 468010A0 */  cvt.s.w   $f2, $f2
/* CF6D8 80138FD8 46080003 */  div.s     $f0, $f0, $f8
/* CF6DC 80138FDC 46001080 */  add.s     $f2, $f2, $f0
/* CF6E0 80138FE0 3C013F00 */  lui       $at, 0x3f00
/* CF6E4 80138FE4 4481B000 */  mtc1      $at, $f22
/* CF6E8 80138FE8 46083183 */  div.s     $f6, $f6, $f8
/* CF6EC 80138FEC 46163580 */  add.s     $f22, $f6, $f22
/* CF6F0 80138FF0 4600228D */  trunc.w.s $f10, $f4
/* CF6F4 80138FF4 E7AA008C */  swc1      $f10, 0x8c($sp)
/* CF6F8 80138FF8 4600128D */  trunc.w.s $f10, $f2
/* CF6FC 80138FFC E7AA0090 */  swc1      $f10, 0x90($sp)
.L80139000:
/* CF700 80139000 3C110001 */  lui       $s1, 1
/* CF704 80139004 36311630 */  ori       $s1, $s1, 0x1630
/* CF708 80139008 0000982D */  daddu     $s3, $zero, $zero
/* CF70C 8013900C 3C02800A */  lui       $v0, 0x800a
/* CF710 80139010 2442A66C */  addiu     $v0, $v0, -0x5994
/* CF714 80139014 0040902D */  daddu     $s2, $v0, $zero
/* CF718 80139018 3C02800A */  lui       $v0, 0x800a
/* CF71C 8013901C 2442A674 */  addiu     $v0, $v0, -0x598c
/* CF720 80139020 0040B02D */  daddu     $s6, $v0, $zero
/* CF724 80139024 3C028007 */  lui       $v0, 0x8007
/* CF728 80139028 244241F0 */  addiu     $v0, $v0, 0x41f0
/* CF72C 8013902C 0040A02D */  daddu     $s4, $v0, $zero
/* CF730 80139030 3C150001 */  lui       $s5, 1
/* CF734 80139034 36B51630 */  ori       $s5, $s5, 0x1630
/* CF738 80139038 3C05C180 */  lui       $a1, 0xc180
/* CF73C 8013903C 0260B82D */  daddu     $s7, $s3, $zero
/* CF740 80139040 AFA00020 */  sw        $zero, 0x20($sp)
/* CF744 80139044 96840000 */  lhu       $a0, ($s4)
/* CF748 80139048 3C018015 */  lui       $at, 0x8015
/* CF74C 8013904C D43A0F88 */  ldc1      $f26, 0xf88($at)
/* CF750 80139050 8EC20000 */  lw        $v0, ($s6)
/* CF754 80139054 4480A000 */  mtc1      $zero, $f20
/* CF758 80139058 3C014180 */  lui       $at, 0x4180
/* CF75C 8013905C 44812000 */  mtc1      $at, $f4
/* CF760 80139060 3C01C47A */  lui       $at, 0xc47a
/* CF764 80139064 44813000 */  mtc1      $at, $f6
/* CF768 80139068 3C013F80 */  lui       $at, 0x3f80
/* CF76C 8013906C 44810000 */  mtc1      $at, $f0
/* CF770 80139070 3C01447A */  lui       $at, 0x447a
/* CF774 80139074 44811000 */  mtc1      $at, $f2
/* CF778 80139078 00042180 */  sll       $a0, $a0, 6
/* CF77C 8013907C 00912021 */  addu      $a0, $a0, $s1
/* CF780 80139080 00442021 */  addu      $a0, $v0, $a0
/* CF784 80139084 4406A000 */  mfc1      $a2, $f20
/* CF788 80139088 4407A000 */  mfc1      $a3, $f20
/* CF78C 8013908C 46000706 */  mov.s     $f28, $f0
/* CF790 80139090 E7A40010 */  swc1      $f4, 0x10($sp)
/* CF794 80139094 E7A60014 */  swc1      $f6, 0x14($sp)
/* CF798 80139098 E7A20018 */  swc1      $f2, 0x18($sp)
/* CF79C 8013909C 0C018E90 */  jal       guOrtho
/* CF7A0 801390A0 E7BC001C */   swc1     $f28, 0x1c($sp)
/* CF7A4 801390A4 3C03DA38 */  lui       $v1, 0xda38
/* CF7A8 801390A8 34630007 */  ori       $v1, $v1, 7
/* CF7AC 801390AC 3C06E300 */  lui       $a2, 0xe300
/* CF7B0 801390B0 34C61A01 */  ori       $a2, $a2, 0x1a01
/* CF7B4 801390B4 3C07E300 */  lui       $a3, 0xe300
/* CF7B8 801390B8 34E71201 */  ori       $a3, $a3, 0x1201
/* CF7BC 801390BC 3C08E300 */  lui       $t0, 0xe300
/* CF7C0 801390C0 35080C00 */  ori       $t0, $t0, 0xc00
/* CF7C4 801390C4 3C09FF18 */  lui       $t1, 0xff18
/* CF7C8 801390C8 3529003F */  ori       $t1, $t1, 0x3f
/* CF7CC 801390CC 8E500000 */  lw        $s0, ($s2)
/* CF7D0 801390D0 3C04800A */  lui       $a0, %hi(nuGfxZBuffer)
/* CF7D4 801390D4 8C84A5DC */  lw        $a0, %lo(nuGfxZBuffer)($a0)
/* CF7D8 801390D8 96820000 */  lhu       $v0, ($s4)
/* CF7DC 801390DC 0200282D */  daddu     $a1, $s0, $zero
/* CF7E0 801390E0 26100008 */  addiu     $s0, $s0, 8
/* CF7E4 801390E4 AE500000 */  sw        $s0, ($s2)
/* CF7E8 801390E8 ACA30000 */  sw        $v1, ($a1)
/* CF7EC 801390EC 24430001 */  addiu     $v1, $v0, 1
/* CF7F0 801390F0 3042FFFF */  andi      $v0, $v0, 0xffff
/* CF7F4 801390F4 00021180 */  sll       $v0, $v0, 6
/* CF7F8 801390F8 A6830000 */  sh        $v1, ($s4)
/* CF7FC 801390FC 8EC30000 */  lw        $v1, ($s6)
/* CF800 80139100 00511021 */  addu      $v0, $v0, $s1
/* CF804 80139104 00621821 */  addu      $v1, $v1, $v0
/* CF808 80139108 26020008 */  addiu     $v0, $s0, 8
/* CF80C 8013910C ACA30004 */  sw        $v1, 4($a1)
/* CF810 80139110 AE420000 */  sw        $v0, ($s2)
/* CF814 80139114 26020010 */  addiu     $v0, $s0, 0x10
/* CF818 80139118 AE060000 */  sw        $a2, ($s0)
/* CF81C 8013911C AE000004 */  sw        $zero, 4($s0)
/* CF820 80139120 AE420000 */  sw        $v0, ($s2)
/* CF824 80139124 26020018 */  addiu     $v0, $s0, 0x18
/* CF828 80139128 AE070008 */  sw        $a3, 8($s0)
/* CF82C 8013912C AE00000C */  sw        $zero, 0xc($s0)
/* CF830 80139130 AE420000 */  sw        $v0, ($s2)
/* CF834 80139134 3C020008 */  lui       $v0, 8
/* CF838 80139138 AE020014 */  sw        $v0, 0x14($s0)
/* CF83C 8013913C 26020020 */  addiu     $v0, $s0, 0x20
/* CF840 80139140 AE080010 */  sw        $t0, 0x10($s0)
/* CF844 80139144 AE420000 */  sw        $v0, ($s2)
/* CF848 80139148 0C0187A4 */  jal       osVirtualToPhysical
/* CF84C 8013914C AE090018 */   sw       $t1, 0x18($s0)
/* CF850 80139150 3C090010 */  lui       $t1, 0x10
/* CF854 80139154 35290100 */  ori       $t1, $t1, 0x100
/* CF858 80139158 3C0ADC08 */  lui       $t2, 0xdc08
/* CF85C 8013915C 354A0008 */  ori       $t2, $t2, 8
/* CF860 80139160 3C0CFCFF */  lui       $t4, 0xfcff
/* CF864 80139164 358CFFFF */  ori       $t4, $t4, 0xffff
/* CF868 80139168 3C0BFFFF */  lui       $t3, 0xffff
/* CF86C 8013916C 8E430000 */  lw        $v1, ($s2)
/* CF870 80139170 4405A000 */  mfc1      $a1, $f20
/* CF874 80139174 356B7DBE */  ori       $t3, $t3, 0x7dbe
/* CF878 80139178 AE02001C */  sw        $v0, 0x1c($s0)
/* CF87C 8013917C 96840000 */  lhu       $a0, ($s4)
/* CF880 80139180 8EC20000 */  lw        $v0, ($s6)
/* CF884 80139184 00A0302D */  daddu     $a2, $a1, $zero
/* CF888 80139188 00A0382D */  daddu     $a3, $a1, $zero
/* CF88C 8013918C 0060402D */  daddu     $t0, $v1, $zero
/* CF890 80139190 24630008 */  addiu     $v1, $v1, 8
/* CF894 80139194 00042180 */  sll       $a0, $a0, 6
/* CF898 80139198 00912021 */  addu      $a0, $a0, $s1
/* CF89C 8013919C 00442021 */  addu      $a0, $v0, $a0
/* CF8A0 801391A0 3C02ED00 */  lui       $v0, 0xed00
/* CF8A4 801391A4 AE430000 */  sw        $v1, ($s2)
/* CF8A8 801391A8 AD020000 */  sw        $v0, ($t0)
/* CF8AC 801391AC 24620008 */  addiu     $v0, $v1, 8
/* CF8B0 801391B0 AD090004 */  sw        $t1, 4($t0)
/* CF8B4 801391B4 AE420000 */  sw        $v0, ($s2)
/* CF8B8 801391B8 3C028015 */  lui       $v0, 0x8015
/* CF8BC 801391BC 2442ED98 */  addiu     $v0, $v0, -0x1268
/* CF8C0 801391C0 AC620004 */  sw        $v0, 4($v1)
/* CF8C4 801391C4 24620010 */  addiu     $v0, $v1, 0x10
/* CF8C8 801391C8 AC6A0000 */  sw        $t2, ($v1)
/* CF8CC 801391CC AE420000 */  sw        $v0, ($s2)
/* CF8D0 801391D0 AC6C0008 */  sw        $t4, 8($v1)
/* CF8D4 801391D4 AC6B000C */  sw        $t3, 0xc($v1)
/* CF8D8 801391D8 0C019F20 */  jal       guRotate
/* CF8DC 801391DC E7BC0010 */   swc1     $f28, 0x10($sp)
/* CF8E0 801391E0 3C03DA38 */  lui       $v1, 0xda38
/* CF8E4 801391E4 34630002 */  ori       $v1, $v1, 2
/* CF8E8 801391E8 3C06D838 */  lui       $a2, 0xd838
/* CF8EC 801391EC 34C60002 */  ori       $a2, $a2, 2
/* CF8F0 801391F0 3C08FCFF */  lui       $t0, 0xfcff
/* CF8F4 801391F4 3508B7FF */  ori       $t0, $t0, 0xb7ff
/* CF8F8 801391F8 3C07FF6F */  lui       $a3, 0xff6f
/* CF8FC 801391FC 34E79FCF */  ori       $a3, $a3, 0x9fcf
/* CF900 80139200 8E440000 */  lw        $a0, ($s2)
/* CF904 80139204 96820000 */  lhu       $v0, ($s4)
/* CF908 80139208 0080282D */  daddu     $a1, $a0, $zero
/* CF90C 8013920C 24840008 */  addiu     $a0, $a0, 8
/* CF910 80139210 AE440000 */  sw        $a0, ($s2)
/* CF914 80139214 ACA30000 */  sw        $v1, ($a1)
/* CF918 80139218 24430001 */  addiu     $v1, $v0, 1
/* CF91C 8013921C 3042FFFF */  andi      $v0, $v0, 0xffff
/* CF920 80139220 00021180 */  sll       $v0, $v0, 6
/* CF924 80139224 A6830000 */  sh        $v1, ($s4)
/* CF928 80139228 8EC30000 */  lw        $v1, ($s6)
/* CF92C 8013922C 00511021 */  addu      $v0, $v0, $s1
/* CF930 80139230 00621821 */  addu      $v1, $v1, $v0
/* CF934 80139234 24820008 */  addiu     $v0, $a0, 8
/* CF938 80139238 ACA30004 */  sw        $v1, 4($a1)
/* CF93C 8013923C AE420000 */  sw        $v0, ($s2)
/* CF940 80139240 3C02DE00 */  lui       $v0, 0xde00
/* CF944 80139244 AC820000 */  sw        $v0, ($a0)
/* CF948 80139248 3C028015 */  lui       $v0, 0x8015
/* CF94C 8013924C 2442EDE8 */  addiu     $v0, $v0, -0x1218
/* CF950 80139250 AC820004 */  sw        $v0, 4($a0)
/* CF954 80139254 24820010 */  addiu     $v0, $a0, 0x10
/* CF958 80139258 AE420000 */  sw        $v0, ($s2)
/* CF95C 8013925C 24020040 */  addiu     $v0, $zero, 0x40
/* CF960 80139260 AC82000C */  sw        $v0, 0xc($a0)
/* CF964 80139264 24820018 */  addiu     $v0, $a0, 0x18
/* CF968 80139268 AC860008 */  sw        $a2, 8($a0)
/* CF96C 8013926C AE420000 */  sw        $v0, ($s2)
/* CF970 80139270 3C02E700 */  lui       $v0, 0xe700
/* CF974 80139274 AC820010 */  sw        $v0, 0x10($a0)
/* CF978 80139278 24820020 */  addiu     $v0, $a0, 0x20
/* CF97C 8013927C AC800014 */  sw        $zero, 0x14($a0)
/* CF980 80139280 AE420000 */  sw        $v0, ($s2)
/* CF984 80139284 AC880018 */  sw        $t0, 0x18($a0)
/* CF988 80139288 AC87001C */  sw        $a3, 0x1c($a0)
.L8013928C:
/* CF98C 8013928C 1660000C */  bnez      $s3, .L801392C0
/* CF990 80139290 241000FF */   addiu    $s0, $zero, 0xff
/* CF994 80139294 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* CF998 80139298 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* CF99C 8013929C 94420134 */  lhu       $v0, 0x134($v0)
/* CF9A0 801392A0 44826000 */  mtc1      $v0, $f12
/* CF9A4 801392A4 00000000 */  nop       
/* CF9A8 801392A8 0C00A8BB */  jal       sin_deg
/* CF9AC 801392AC 46806320 */   cvt.s.w  $f12, $f12
/* CF9B0 801392B0 3C018015 */  lui       $at, 0x8015
/* CF9B4 801392B4 D4220F90 */  ldc1      $f2, 0xf90($at)
/* CF9B8 801392B8 0804E4BC */  j         .L801392F0
/* CF9BC 801392BC 46000021 */   cvt.d.s  $f0, $f0
.L801392C0:
/* CF9C0 801392C0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* CF9C4 801392C4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* CF9C8 801392C8 94420134 */  lhu       $v0, 0x134($v0)
/* CF9CC 801392CC 00021040 */  sll       $v0, $v0, 1
/* CF9D0 801392D0 00571021 */  addu      $v0, $v0, $s7
/* CF9D4 801392D4 44826000 */  mtc1      $v0, $f12
/* CF9D8 801392D8 00000000 */  nop       
/* CF9DC 801392DC 0C00A8BB */  jal       sin_deg
/* CF9E0 801392E0 46806320 */   cvt.s.w  $f12, $f12
/* CF9E4 801392E4 3C018015 */  lui       $at, 0x8015
/* CF9E8 801392E8 D4220F98 */  ldc1      $f2, 0xf98($at)
/* CF9EC 801392EC 46000021 */  cvt.d.s   $f0, $f0
.L801392F0:
/* CF9F0 801392F0 46220002 */  mul.d     $f0, $f0, $f2
/* CF9F4 801392F4 00000000 */  nop       
/* CF9F8 801392F8 4620D001 */  sub.d     $f0, $f26, $f0
/* CF9FC 801392FC 44801000 */  mtc1      $zero, $f2
/* CFA00 80139300 2A020100 */  slti      $v0, $s0, 0x100
/* CFA04 80139304 14400002 */  bnez      $v0, .L80139310
/* CFA08 80139308 46200520 */   cvt.s.d  $f20, $f0
/* CFA0C 8013930C 241000FF */  addiu     $s0, $zero, 0xff
.L80139310:
/* CFA10 80139310 C7A00020 */  lwc1      $f0, 0x20($sp)
/* CFA14 80139314 46800020 */  cvt.s.w   $f0, $f0
/* CFA18 80139318 26F70028 */  addiu     $s7, $s7, 0x28
/* CFA1C 8013931C 26730001 */  addiu     $s3, $s3, 1
/* CFA20 80139320 46020000 */  add.s     $f0, $f0, $f2
/* CFA24 80139324 8FAD0020 */  lw        $t5, 0x20($sp)
/* CFA28 80139328 44061000 */  mfc1      $a2, $f2
/* CFA2C 8013932C 25AD0046 */  addiu     $t5, $t5, 0x46
/* CFA30 80139330 00C0382D */  daddu     $a3, $a2, $zero
/* CFA34 80139334 AFAD0020 */  sw        $t5, 0x20($sp)
/* CFA38 80139338 8E430000 */  lw        $v1, ($s2)
/* CFA3C 8013933C 96840000 */  lhu       $a0, ($s4)
/* CFA40 80139340 8EC20000 */  lw        $v0, ($s6)
/* CFA44 80139344 0060402D */  daddu     $t0, $v1, $zero
/* CFA48 80139348 24630008 */  addiu     $v1, $v1, 8
/* CFA4C 8013934C 00042180 */  sll       $a0, $a0, 6
/* CFA50 80139350 00952021 */  addu      $a0, $a0, $s5
/* CFA54 80139354 00442021 */  addu      $a0, $v0, $a0
/* CFA58 80139358 3C02FA00 */  lui       $v0, 0xfa00
/* CFA5C 8013935C AE430000 */  sw        $v1, ($s2)
/* CFA60 80139360 AD020000 */  sw        $v0, ($t0)
/* CFA64 80139364 2402FF00 */  addiu     $v0, $zero, -0x100
/* CFA68 80139368 44050000 */  mfc1      $a1, $f0
/* CFA6C 8013936C 02021025 */  or        $v0, $s0, $v0
/* CFA70 80139370 AD020004 */  sw        $v0, 4($t0)
/* CFA74 80139374 0C019F20 */  jal       guRotate
/* CFA78 80139378 E7BC0010 */   swc1     $f28, 0x10($sp)
/* CFA7C 8013937C 3C04DA38 */  lui       $a0, 0xda38
/* CFA80 80139380 34840002 */  ori       $a0, $a0, 2
/* CFA84 80139384 8E420000 */  lw        $v0, ($s2)
/* CFA88 80139388 4405A000 */  mfc1      $a1, $f20
/* CFA8C 8013938C 4407E000 */  mfc1      $a3, $f28
/* CFA90 80139390 96830000 */  lhu       $v1, ($s4)
/* CFA94 80139394 00A0302D */  daddu     $a2, $a1, $zero
/* CFA98 80139398 0040402D */  daddu     $t0, $v0, $zero
/* CFA9C 8013939C 24420008 */  addiu     $v0, $v0, 8
/* CFAA0 801393A0 AE420000 */  sw        $v0, ($s2)
/* CFAA4 801393A4 24620001 */  addiu     $v0, $v1, 1
/* CFAA8 801393A8 3063FFFF */  andi      $v1, $v1, 0xffff
/* CFAAC 801393AC 00031980 */  sll       $v1, $v1, 6
/* CFAB0 801393B0 00751821 */  addu      $v1, $v1, $s5
/* CFAB4 801393B4 AD040000 */  sw        $a0, ($t0)
/* CFAB8 801393B8 A6820000 */  sh        $v0, ($s4)
/* CFABC 801393BC 8EC20000 */  lw        $v0, ($s6)
/* CFAC0 801393C0 96840000 */  lhu       $a0, ($s4)
/* CFAC4 801393C4 00431821 */  addu      $v1, $v0, $v1
/* CFAC8 801393C8 00042180 */  sll       $a0, $a0, 6
/* CFACC 801393CC 00952021 */  addu      $a0, $a0, $s5
/* CFAD0 801393D0 00442021 */  addu      $a0, $v0, $a0
/* CFAD4 801393D4 0C019DC0 */  jal       guScale
/* CFAD8 801393D8 AD030004 */   sw       $v1, 4($t0)
/* CFADC 801393DC 3C02DA38 */  lui       $v0, 0xda38
/* CFAE0 801393E0 34420001 */  ori       $v0, $v0, 1
/* CFAE4 801393E4 3C06D838 */  lui       $a2, 0xd838
/* CFAE8 801393E8 34C60002 */  ori       $a2, $a2, 2
/* CFAEC 801393EC 8E440000 */  lw        $a0, ($s2)
/* CFAF0 801393F0 96830000 */  lhu       $v1, ($s4)
/* CFAF4 801393F4 0080282D */  daddu     $a1, $a0, $zero
/* CFAF8 801393F8 24840008 */  addiu     $a0, $a0, 8
/* CFAFC 801393FC AE440000 */  sw        $a0, ($s2)
/* CFB00 80139400 ACA20000 */  sw        $v0, ($a1)
/* CFB04 80139404 24620001 */  addiu     $v0, $v1, 1
/* CFB08 80139408 3063FFFF */  andi      $v1, $v1, 0xffff
/* CFB0C 8013940C 00031980 */  sll       $v1, $v1, 6
/* CFB10 80139410 A6820000 */  sh        $v0, ($s4)
/* CFB14 80139414 8EC20000 */  lw        $v0, ($s6)
/* CFB18 80139418 00751821 */  addu      $v1, $v1, $s5
/* CFB1C 8013941C 00431021 */  addu      $v0, $v0, $v1
/* CFB20 80139420 ACA20004 */  sw        $v0, 4($a1)
/* CFB24 80139424 24820008 */  addiu     $v0, $a0, 8
/* CFB28 80139428 AE420000 */  sw        $v0, ($s2)
/* CFB2C 8013942C 3C02DE00 */  lui       $v0, 0xde00
/* CFB30 80139430 AC820000 */  sw        $v0, ($a0)
/* CFB34 80139434 3C028015 */  lui       $v0, 0x8015
/* CFB38 80139438 2442EDE8 */  addiu     $v0, $v0, -0x1218
/* CFB3C 8013943C AC820004 */  sw        $v0, 4($a0)
/* CFB40 80139440 24820010 */  addiu     $v0, $a0, 0x10
/* CFB44 80139444 AE420000 */  sw        $v0, ($s2)
/* CFB48 80139448 24020040 */  addiu     $v0, $zero, 0x40
/* CFB4C 8013944C AC82000C */  sw        $v0, 0xc($a0)
/* CFB50 80139450 2A620002 */  slti      $v0, $s3, 2
/* CFB54 80139454 1440FF8D */  bnez      $v0, .L8013928C
/* CFB58 80139458 AC860008 */   sw       $a2, 8($a0)
/* CFB5C 8013945C 3C05E300 */  lui       $a1, 0xe300
/* CFB60 80139460 34A50C00 */  ori       $a1, $a1, 0xc00
/* CFB64 80139464 3C06FF88 */  lui       $a2, 0xff88
/* CFB68 80139468 34C6003F */  ori       $a2, $a2, 0x3f
/* CFB6C 8013946C 0000982D */  daddu     $s3, $zero, $zero
/* CFB70 80139470 3C02800A */  lui       $v0, 0x800a
/* CFB74 80139474 2442A66C */  addiu     $v0, $v0, -0x5994
/* CFB78 80139478 0040882D */  daddu     $s1, $v0, $zero
/* CFB7C 8013947C 3C14F518 */  lui       $s4, 0xf518
/* CFB80 80139480 36942000 */  ori       $s4, $s4, 0x2000
/* CFB84 80139484 3C15E700 */  lui       $s5, 0xe700
/* CFB88 80139488 24120040 */  addiu     $s2, $zero, 0x40
/* CFB8C 8013948C 02A0102D */  daddu     $v0, $s5, $zero
/* CFB90 80139490 8E300000 */  lw        $s0, ($s1)
/* CFB94 80139494 3C04800A */  lui       $a0, %hi(nuGfxZBuffer)
/* CFB98 80139498 8C84A5DC */  lw        $a0, %lo(nuGfxZBuffer)($a0)
/* CFB9C 8013949C 0200182D */  daddu     $v1, $s0, $zero
/* CFBA0 801394A0 26100008 */  addiu     $s0, $s0, 8
/* CFBA4 801394A4 AE300000 */  sw        $s0, ($s1)
/* CFBA8 801394A8 AC620000 */  sw        $v0, ($v1)
/* CFBAC 801394AC 26020008 */  addiu     $v0, $s0, 8
/* CFBB0 801394B0 AC600004 */  sw        $zero, 4($v1)
/* CFBB4 801394B4 AE220000 */  sw        $v0, ($s1)
/* CFBB8 801394B8 26020010 */  addiu     $v0, $s0, 0x10
/* CFBBC 801394BC AE050000 */  sw        $a1, ($s0)
/* CFBC0 801394C0 AE000004 */  sw        $zero, 4($s0)
/* CFBC4 801394C4 AE220000 */  sw        $v0, ($s1)
/* CFBC8 801394C8 0C0187A4 */  jal       osVirtualToPhysical
/* CFBCC 801394CC AE060008 */   sw       $a2, 8($s0)
/* CFBD0 801394D0 3C050010 */  lui       $a1, 0x10
/* CFBD4 801394D4 34A50100 */  ori       $a1, $a1, 0x100
/* CFBD8 801394D8 3C07FCFF */  lui       $a3, 0xfcff
/* CFBDC 801394DC 34E7FFFF */  ori       $a3, $a3, 0xffff
/* CFBE0 801394E0 3C06FFFC */  lui       $a2, 0xfffc
/* CFBE4 801394E4 8E230000 */  lw        $v1, ($s1)
/* CFBE8 801394E8 34C6FC7E */  ori       $a2, $a2, 0xfc7e
/* CFBEC 801394EC AE02000C */  sw        $v0, 0xc($s0)
/* CFBF0 801394F0 3C02ED00 */  lui       $v0, 0xed00
/* CFBF4 801394F4 0060202D */  daddu     $a0, $v1, $zero
/* CFBF8 801394F8 24630008 */  addiu     $v1, $v1, 8
/* CFBFC 801394FC AE230000 */  sw        $v1, ($s1)
/* CFC00 80139500 AC820000 */  sw        $v0, ($a0)
/* CFC04 80139504 24620008 */  addiu     $v0, $v1, 8
/* CFC08 80139508 AC850004 */  sw        $a1, 4($a0)
/* CFC0C 8013950C AE220000 */  sw        $v0, ($s1)
/* CFC10 80139510 AC670000 */  sw        $a3, ($v1)
/* CFC14 80139514 AC660004 */  sw        $a2, 4($v1)
.L80139518:
/* CFC18 80139518 3C05FD18 */  lui       $a1, 0xfd18
/* CFC1C 8013951C 34A5003F */  ori       $a1, $a1, 0x3f
/* CFC20 80139520 00132300 */  sll       $a0, $s3, 0xc
/* CFC24 80139524 8E220000 */  lw        $v0, ($s1)
/* CFC28 80139528 3C03800A */  lui       $v1, %hi(nuGfxZBuffer)
/* CFC2C 8013952C 8C63A5DC */  lw        $v1, %lo(nuGfxZBuffer)($v1)
/* CFC30 80139530 0040802D */  daddu     $s0, $v0, $zero
/* CFC34 80139534 24420008 */  addiu     $v0, $v0, 8
/* CFC38 80139538 00642021 */  addu      $a0, $v1, $a0
/* CFC3C 8013953C AE220000 */  sw        $v0, ($s1)
/* CFC40 80139540 0C0187A4 */  jal       osVirtualToPhysical
/* CFC44 80139544 AE050000 */   sw       $a1, ($s0)
/* CFC48 80139548 3C07070F */  lui       $a3, 0x70f
/* CFC4C 8013954C 34E7C03C */  ori       $a3, $a3, 0xc03c
/* CFC50 80139550 3C08000F */  lui       $t0, 0xf
/* CFC54 80139554 3508C03C */  ori       $t0, $t0, 0xc03c
/* CFC58 80139558 3C090400 */  lui       $t1, 0x400
/* CFC5C 8013955C 35290400 */  ori       $t1, $t1, 0x400
/* CFC60 80139560 32460FFF */  andi      $a2, $s2, 0xfff
/* CFC64 80139564 26520040 */  addiu     $s2, $s2, 0x40
/* CFC68 80139568 00132980 */  sll       $a1, $s3, 6
/* CFC6C 8013956C 8E230000 */  lw        $v1, ($s1)
/* CFC70 80139570 26730001 */  addiu     $s3, $s3, 1
/* CFC74 80139574 AE020004 */  sw        $v0, 4($s0)
/* CFC78 80139578 3C020700 */  lui       $v0, 0x700
/* CFC7C 8013957C 3C0BE600 */  lui       $t3, 0xe600
/* CFC80 80139580 3C0AF400 */  lui       $t2, 0xf400
/* CFC84 80139584 3C17F200 */  lui       $s7, 0xf200
/* CFC88 80139588 30A50FFF */  andi      $a1, $a1, 0xfff
/* CFC8C 8013958C 0060202D */  daddu     $a0, $v1, $zero
/* CFC90 80139590 24630008 */  addiu     $v1, $v1, 8
/* CFC94 80139594 AE230000 */  sw        $v1, ($s1)
/* CFC98 80139598 AC820004 */  sw        $v0, 4($a0)
/* CFC9C 8013959C 24620008 */  addiu     $v0, $v1, 8
/* CFCA0 801395A0 AC940000 */  sw        $s4, ($a0)
/* CFCA4 801395A4 AE220000 */  sw        $v0, ($s1)
/* CFCA8 801395A8 24620010 */  addiu     $v0, $v1, 0x10
/* CFCAC 801395AC AC6B0000 */  sw        $t3, ($v1)
/* CFCB0 801395B0 AC600004 */  sw        $zero, 4($v1)
/* CFCB4 801395B4 AE220000 */  sw        $v0, ($s1)
/* CFCB8 801395B8 24620018 */  addiu     $v0, $v1, 0x18
/* CFCBC 801395BC AC6A0008 */  sw        $t2, 8($v1)
/* CFCC0 801395C0 AC67000C */  sw        $a3, 0xc($v1)
/* CFCC4 801395C4 AE220000 */  sw        $v0, ($s1)
/* CFCC8 801395C8 24620020 */  addiu     $v0, $v1, 0x20
/* CFCCC 801395CC AC750010 */  sw        $s5, 0x10($v1)
/* CFCD0 801395D0 AC600014 */  sw        $zero, 0x14($v1)
/* CFCD4 801395D4 AE220000 */  sw        $v0, ($s1)
/* CFCD8 801395D8 24620028 */  addiu     $v0, $v1, 0x28
/* CFCDC 801395DC AC740018 */  sw        $s4, 0x18($v1)
/* CFCE0 801395E0 AC60001C */  sw        $zero, 0x1c($v1)
/* CFCE4 801395E4 AE220000 */  sw        $v0, ($s1)
/* CFCE8 801395E8 24620030 */  addiu     $v0, $v1, 0x30
/* CFCEC 801395EC AC770020 */  sw        $s7, 0x20($v1)
/* CFCF0 801395F0 AC680024 */  sw        $t0, 0x24($v1)
/* CFCF4 801395F4 AE220000 */  sw        $v0, ($s1)
/* CFCF8 801395F8 24620038 */  addiu     $v0, $v1, 0x38
/* CFCFC 801395FC AC750028 */  sw        $s5, 0x28($v1)
/* CFD00 80139600 AC60002C */  sw        $zero, 0x2c($v1)
/* CFD04 80139604 AE220000 */  sw        $v0, ($s1)
/* CFD08 80139608 3C02E410 */  lui       $v0, 0xe410
/* CFD0C 8013960C 00C23025 */  or        $a2, $a2, $v0
/* CFD10 80139610 24620040 */  addiu     $v0, $v1, 0x40
/* CFD14 80139614 AC660030 */  sw        $a2, 0x30($v1)
/* CFD18 80139618 AC650034 */  sw        $a1, 0x34($v1)
/* CFD1C 8013961C AE220000 */  sw        $v0, ($s1)
/* CFD20 80139620 3C02E100 */  lui       $v0, 0xe100
/* CFD24 80139624 AC620038 */  sw        $v0, 0x38($v1)
/* CFD28 80139628 24620048 */  addiu     $v0, $v1, 0x48
/* CFD2C 8013962C AC60003C */  sw        $zero, 0x3c($v1)
/* CFD30 80139630 AE220000 */  sw        $v0, ($s1)
/* CFD34 80139634 3C02F100 */  lui       $v0, 0xf100
/* CFD38 80139638 AC620040 */  sw        $v0, 0x40($v1)
/* CFD3C 8013963C 24620050 */  addiu     $v0, $v1, 0x50
/* CFD40 80139640 AC690044 */  sw        $t1, 0x44($v1)
/* CFD44 80139644 AE220000 */  sw        $v0, ($s1)
/* CFD48 80139648 2A620004 */  slti      $v0, $s3, 4
/* CFD4C 8013964C AC750048 */  sw        $s5, 0x48($v1)
/* CFD50 80139650 1440FFB1 */  bnez      $v0, .L80139518
/* CFD54 80139654 AC60004C */   sw       $zero, 0x4c($v1)
/* CFD58 80139658 3C03FD88 */  lui       $v1, 0xfd88
/* CFD5C 8013965C 3463003F */  ori       $v1, $v1, 0x3f
/* CFD60 80139660 3C14E300 */  lui       $s4, 0xe300
/* CFD64 80139664 36940A01 */  ori       $s4, $s4, 0xa01
/* CFD68 80139668 3C15E200 */  lui       $s5, 0xe200
/* CFD6C 8013966C 36B5001C */  ori       $s5, $s5, 0x1c
/* CFD70 80139670 3C16800A */  lui       $s6, 0x800a
/* CFD74 80139674 26D6A66C */  addiu     $s6, $s6, -0x5994
/* CFD78 80139678 3C13800A */  lui       $s3, %hi(nuGfxZBuffer)
/* CFD7C 8013967C 2673A5DC */  addiu     $s3, $s3, %lo(nuGfxZBuffer)
/* CFD80 80139680 8EC20000 */  lw        $v0, ($s6)
/* CFD84 80139684 8E640000 */  lw        $a0, ($s3)
/* CFD88 80139688 0040882D */  daddu     $s1, $v0, $zero
/* CFD8C 8013968C 24420008 */  addiu     $v0, $v0, 8
/* CFD90 80139690 AEC20000 */  sw        $v0, ($s6)
/* CFD94 80139694 AE230000 */  sw        $v1, ($s1)
/* CFD98 80139698 AFAA0028 */  sw        $t2, 0x28($sp)
/* CFD9C 8013969C 0C0187A4 */  jal       osVirtualToPhysical
/* CFDA0 801396A0 AFAB002C */   sw       $t3, 0x2c($sp)
/* CFDA4 801396A4 3C04F588 */  lui       $a0, 0xf588
/* CFDA8 801396A8 34841000 */  ori       $a0, $a0, 0x1000
/* CFDAC 801396AC 3C03070D */  lui       $v1, 0x70d
/* CFDB0 801396B0 3463BF6F */  ori       $v1, $v1, 0xbf6f
/* CFDB4 801396B4 3C05070F */  lui       $a1, 0x70f
/* CFDB8 801396B8 34A5C0FC */  ori       $a1, $a1, 0xc0fc
/* CFDBC 801396BC 3C06000D */  lui       $a2, 0xd
/* CFDC0 801396C0 34C6BF6F */  ori       $a2, $a2, 0xbf6f
/* CFDC4 801396C4 3C07000F */  lui       $a3, 0xf
/* CFDC8 801396C8 34E7C0FC */  ori       $a3, $a3, 0xc0fc
/* CFDCC 801396CC 3C08001F */  lui       $t0, 0x1f
/* CFDD0 801396D0 3508C1FC */  ori       $t0, $t0, 0xc1fc
/* CFDD4 801396D4 3C09FF18 */  lui       $t1, 0xff18
/* CFDD8 801396D8 3529003F */  ori       $t1, $t1, 0x3f
/* CFDDC 801396DC 8ED00000 */  lw        $s0, ($s6)
/* CFDE0 801396E0 3C12E700 */  lui       $s2, 0xe700
/* CFDE4 801396E4 AE220004 */  sw        $v0, 4($s1)
/* CFDE8 801396E8 0200102D */  daddu     $v0, $s0, $zero
/* CFDEC 801396EC 26100008 */  addiu     $s0, $s0, 8
/* CFDF0 801396F0 AED00000 */  sw        $s0, ($s6)
/* CFDF4 801396F4 AC440000 */  sw        $a0, ($v0)
/* CFDF8 801396F8 AC430004 */  sw        $v1, 4($v0)
/* CFDFC 801396FC 26020008 */  addiu     $v0, $s0, 8
/* CFE00 80139700 AEC20000 */  sw        $v0, ($s6)
/* CFE04 80139704 8FAB002C */  lw        $t3, 0x2c($sp)
/* CFE08 80139708 26020010 */  addiu     $v0, $s0, 0x10
/* CFE0C 8013970C AE000004 */  sw        $zero, 4($s0)
/* CFE10 80139710 AE0B0000 */  sw        $t3, ($s0)
/* CFE14 80139714 AEC20000 */  sw        $v0, ($s6)
/* CFE18 80139718 8FAA0028 */  lw        $t2, 0x28($sp)
/* CFE1C 8013971C 26020018 */  addiu     $v0, $s0, 0x18
/* CFE20 80139720 AE05000C */  sw        $a1, 0xc($s0)
/* CFE24 80139724 AE0A0008 */  sw        $t2, 8($s0)
/* CFE28 80139728 AEC20000 */  sw        $v0, ($s6)
/* CFE2C 8013972C 26020020 */  addiu     $v0, $s0, 0x20
/* CFE30 80139730 AE120010 */  sw        $s2, 0x10($s0)
/* CFE34 80139734 AE000014 */  sw        $zero, 0x14($s0)
/* CFE38 80139738 AEC20000 */  sw        $v0, ($s6)
/* CFE3C 8013973C 26020028 */  addiu     $v0, $s0, 0x28
/* CFE40 80139740 AE040018 */  sw        $a0, 0x18($s0)
/* CFE44 80139744 AE06001C */  sw        $a2, 0x1c($s0)
/* CFE48 80139748 AEC20000 */  sw        $v0, ($s6)
/* CFE4C 8013974C 26020030 */  addiu     $v0, $s0, 0x30
/* CFE50 80139750 AE170020 */  sw        $s7, 0x20($s0)
/* CFE54 80139754 AE070024 */  sw        $a3, 0x24($s0)
/* CFE58 80139758 AEC20000 */  sw        $v0, ($s6)
/* CFE5C 8013975C 26020038 */  addiu     $v0, $s0, 0x38
/* CFE60 80139760 AE170028 */  sw        $s7, 0x28($s0)
/* CFE64 80139764 AE08002C */  sw        $t0, 0x2c($s0)
/* CFE68 80139768 AEC20000 */  sw        $v0, ($s6)
/* CFE6C 8013976C 26020040 */  addiu     $v0, $s0, 0x40
/* CFE70 80139770 AE120030 */  sw        $s2, 0x30($s0)
/* CFE74 80139774 AE000034 */  sw        $zero, 0x34($s0)
/* CFE78 80139778 AEC20000 */  sw        $v0, ($s6)
/* CFE7C 8013977C 3C020030 */  lui       $v0, 0x30
/* CFE80 80139780 AE02003C */  sw        $v0, 0x3c($s0)
/* CFE84 80139784 26020048 */  addiu     $v0, $s0, 0x48
/* CFE88 80139788 AE140038 */  sw        $s4, 0x38($s0)
/* CFE8C 8013978C AEC20000 */  sw        $v0, ($s6)
/* CFE90 80139790 26020050 */  addiu     $v0, $s0, 0x50
/* CFE94 80139794 AE150040 */  sw        $s5, 0x40($s0)
/* CFE98 80139798 AE000044 */  sw        $zero, 0x44($s0)
/* CFE9C 8013979C AEC20000 */  sw        $v0, ($s6)
/* CFEA0 801397A0 AE090048 */  sw        $t1, 0x48($s0)
/* CFEA4 801397A4 0C0187A4 */  jal       osVirtualToPhysical
/* CFEA8 801397A8 8E640000 */   lw       $a0, ($s3)
/* CFEAC 801397AC 3C05FFFC */  lui       $a1, 0xfffc
/* CFEB0 801397B0 34A5FFFC */  ori       $a1, $a1, 0xfffc
/* CFEB4 801397B4 3C06F60F */  lui       $a2, 0xf60f
/* CFEB8 801397B8 34C6C0FC */  ori       $a2, $a2, 0xc0fc
/* CFEBC 801397BC 3C07FF10 */  lui       $a3, 0xff10
/* CFEC0 801397C0 8ED10000 */  lw        $s1, ($s6)
/* CFEC4 801397C4 34E7013F */  ori       $a3, $a3, 0x13f
/* CFEC8 801397C8 AE02004C */  sw        $v0, 0x4c($s0)
/* CFECC 801397CC 3C02F700 */  lui       $v0, 0xf700
/* CFED0 801397D0 3C04800A */  lui       $a0, 0x800a
/* CFED4 801397D4 8C84A64C */  lw        $a0, -0x59b4($a0)
/* CFED8 801397D8 0220182D */  daddu     $v1, $s1, $zero
/* CFEDC 801397DC 26310008 */  addiu     $s1, $s1, 8
/* CFEE0 801397E0 AED10000 */  sw        $s1, ($s6)
/* CFEE4 801397E4 AC620000 */  sw        $v0, ($v1)
/* CFEE8 801397E8 26220008 */  addiu     $v0, $s1, 8
/* CFEEC 801397EC AC650004 */  sw        $a1, 4($v1)
/* CFEF0 801397F0 AEC20000 */  sw        $v0, ($s6)
/* CFEF4 801397F4 26220010 */  addiu     $v0, $s1, 0x10
/* CFEF8 801397F8 AE260000 */  sw        $a2, ($s1)
/* CFEFC 801397FC AE200004 */  sw        $zero, 4($s1)
/* CFF00 80139800 AEC20000 */  sw        $v0, ($s6)
/* CFF04 80139804 26220018 */  addiu     $v0, $s1, 0x18
/* CFF08 80139808 AE320008 */  sw        $s2, 8($s1)
/* CFF0C 8013980C AE20000C */  sw        $zero, 0xc($s1)
/* CFF10 80139810 AEC20000 */  sw        $v0, ($s6)
/* CFF14 80139814 0C0187A4 */  jal       osVirtualToPhysical
/* CFF18 80139818 AE270010 */   sw       $a3, 0x10($s1)
/* CFF1C 8013981C 3C040050 */  lui       $a0, 0x50
/* CFF20 80139820 348403C0 */  ori       $a0, $a0, 0x3c0
/* CFF24 80139824 3C05E300 */  lui       $a1, 0xe300
/* CFF28 80139828 34A51801 */  ori       $a1, $a1, 0x1801
/* CFF2C 8013982C 3C06E300 */  lui       $a2, 0xe300
/* CFF30 80139830 34C61A01 */  ori       $a2, $a2, 0x1a01
/* CFF34 80139834 3C07E300 */  lui       $a3, 0xe300
/* CFF38 80139838 34E71201 */  ori       $a3, $a3, 0x1201
/* CFF3C 8013983C 3C080050 */  lui       $t0, 0x50
/* CFF40 80139840 8EC90000 */  lw        $t1, ($s6)
/* CFF44 80139844 35084340 */  ori       $t0, $t0, 0x4340
/* CFF48 80139848 AE220014 */  sw        $v0, 0x14($s1)
/* CFF4C 8013984C 3C02ED00 */  lui       $v0, 0xed00
/* CFF50 80139850 3C01437F */  lui       $at, 0x437f
/* CFF54 80139854 44810000 */  mtc1      $at, $f0
/* CFF58 80139858 0120182D */  daddu     $v1, $t1, $zero
/* CFF5C 8013985C 25290008 */  addiu     $t1, $t1, 8
/* CFF60 80139860 AEC90000 */  sw        $t1, ($s6)
/* CFF64 80139864 AC620000 */  sw        $v0, ($v1)
/* CFF68 80139868 25220008 */  addiu     $v0, $t1, 8
/* CFF6C 8013986C AC640004 */  sw        $a0, 4($v1)
/* CFF70 80139870 AEC20000 */  sw        $v0, ($s6)
/* CFF74 80139874 25220010 */  addiu     $v0, $t1, 0x10
/* CFF78 80139878 AD340000 */  sw        $s4, ($t1)
/* CFF7C 8013987C AD200004 */  sw        $zero, 4($t1)
/* CFF80 80139880 AEC20000 */  sw        $v0, ($s6)
/* CFF84 80139884 25220018 */  addiu     $v0, $t1, 0x18
/* CFF88 80139888 AD250008 */  sw        $a1, 8($t1)
/* CFF8C 8013988C AD20000C */  sw        $zero, 0xc($t1)
/* CFF90 80139890 AEC20000 */  sw        $v0, ($s6)
/* CFF94 80139894 25220020 */  addiu     $v0, $t1, 0x20
/* CFF98 80139898 AD260010 */  sw        $a2, 0x10($t1)
/* CFF9C 8013989C AD200014 */  sw        $zero, 0x14($t1)
/* CFFA0 801398A0 AEC20000 */  sw        $v0, ($s6)
/* CFFA4 801398A4 24023000 */  addiu     $v0, $zero, 0x3000
/* CFFA8 801398A8 AD22001C */  sw        $v0, 0x1c($t1)
/* CFFAC 801398AC 25220028 */  addiu     $v0, $t1, 0x28
/* CFFB0 801398B0 4600C032 */  c.eq.s    $f24, $f0
/* CFFB4 801398B4 AD270018 */  sw        $a3, 0x18($t1)
/* CFFB8 801398B8 AEC20000 */  sw        $v0, ($s6)
/* CFFBC 801398BC AD350020 */  sw        $s5, 0x20($t1)
/* CFFC0 801398C0 45000005 */  bc1f      .L801398D8
/* CFFC4 801398C4 AD280024 */   sw       $t0, 0x24($t1)
/* CFFC8 801398C8 8FAD0088 */  lw        $t5, 0x88($sp)
/* CFFCC 801398CC 24020001 */  addiu     $v0, $zero, 1
/* CFFD0 801398D0 55A20005 */  bnel      $t5, $v0, .L801398E8
/* CFFD4 801398D4 3C04FCFF */   lui      $a0, 0xfcff
.L801398D8:
/* CFFD8 801398D8 3C04FC61 */  lui       $a0, 0xfc61
/* CFFDC 801398DC 34849AC3 */  ori       $a0, $a0, 0x9ac3
/* CFFE0 801398E0 0804E63C */  j         .L801398F0
/* CFFE4 801398E4 3C031137 */   lui      $v1, 0x1137
.L801398E8:
/* CFFE8 801398E8 3484EBFF */  ori       $a0, $a0, 0xebff
/* CFFEC 801398EC 3C03FFD7 */  lui       $v1, 0xffd7
.L801398F0:
/* CFFF0 801398F0 3463F7FB */  ori       $v1, $v1, 0xf7fb
/* CFFF4 801398F4 25220030 */  addiu     $v0, $t1, 0x30
/* CFFF8 801398F8 AEC20000 */  sw        $v0, ($s6)
/* CFFFC 801398FC AD240028 */  sw        $a0, 0x28($t1)
/* D0000 80139900 AD23002C */  sw        $v1, 0x2c($t1)
/* D0004 80139904 3C013F00 */  lui       $at, 0x3f00
/* D0008 80139908 44810000 */  mtc1      $at, $f0
/* D000C 8013990C 00000000 */  nop       
/* D0010 80139910 4600C602 */  mul.s     $f24, $f24, $f0
/* D0014 80139914 00000000 */  nop       
/* D0018 80139918 3C03800A */  lui       $v1, 0x800a
/* D001C 8013991C 2463A66C */  addiu     $v1, $v1, -0x5994
/* D0020 80139920 8C620000 */  lw        $v0, ($v1)
/* D0024 80139924 4600C002 */  mul.s     $f0, $f24, $f0
/* D0028 80139928 00000000 */  nop       
/* D002C 8013992C 3C01437F */  lui       $at, 0x437f
/* D0030 80139930 44811000 */  mtc1      $at, $f2
/* D0034 80139934 3C014F00 */  lui       $at, 0x4f00
/* D0038 80139938 44812000 */  mtc1      $at, $f4
/* D003C 8013993C 0040202D */  daddu     $a0, $v0, $zero
/* D0040 80139940 24420008 */  addiu     $v0, $v0, 8
/* D0044 80139944 461E0002 */  mul.s     $f0, $f0, $f30
/* D0048 80139948 00000000 */  nop       
/* D004C 8013994C AC620000 */  sw        $v0, ($v1)
/* D0050 80139950 3C02FA00 */  lui       $v0, 0xfa00
/* D0054 80139954 AC820000 */  sw        $v0, ($a0)
/* D0058 80139958 46020003 */  div.s     $f0, $f0, $f2
/* D005C 8013995C 4600203E */  c.le.s    $f4, $f0
/* D0060 80139960 00000000 */  nop       
/* D0064 80139964 45010005 */  bc1t      .L8013997C
/* D0068 80139968 24840004 */   addiu    $a0, $a0, 4
/* D006C 8013996C 4600028D */  trunc.w.s $f10, $f0
/* D0070 80139970 44065000 */  mfc1      $a2, $f10
/* D0074 80139974 0804E665 */  j         .L80139994
/* D0078 80139978 00000000 */   nop      
.L8013997C:
/* D007C 8013997C 46040001 */  sub.s     $f0, $f0, $f4
/* D0080 80139980 3C028000 */  lui       $v0, 0x8000
/* D0084 80139984 4600028D */  trunc.w.s $f10, $f0
/* D0088 80139988 44065000 */  mfc1      $a2, $f10
/* D008C 8013998C 00000000 */  nop       
/* D0090 80139990 00C23025 */  or        $a2, $a2, $v0
.L80139994:
/* D0094 80139994 3C05800A */  lui       $a1, 0x800a
/* D0098 80139998 24A5A66C */  addiu     $a1, $a1, -0x5994
/* D009C 8013999C 3C013F00 */  lui       $at, 0x3f00
/* D00A0 801399A0 44810000 */  mtc1      $at, $f0
/* D00A4 801399A4 8CA30000 */  lw        $v1, ($a1)
/* D00A8 801399A8 4600C002 */  mul.s     $f0, $f24, $f0
/* D00AC 801399AC 00000000 */  nop       
/* D00B0 801399B0 3C01437F */  lui       $at, 0x437f
/* D00B4 801399B4 44811000 */  mtc1      $at, $f2
/* D00B8 801399B8 30C200FF */  andi      $v0, $a2, 0xff
/* D00BC 801399BC AC820000 */  sw        $v0, ($a0)
/* D00C0 801399C0 3C02FB00 */  lui       $v0, 0xfb00
/* D00C4 801399C4 46001001 */  sub.s     $f0, $f2, $f0
/* D00C8 801399C8 3C014F00 */  lui       $at, 0x4f00
/* D00CC 801399CC 44812000 */  mtc1      $at, $f4
/* D00D0 801399D0 0060202D */  daddu     $a0, $v1, $zero
/* D00D4 801399D4 461E0002 */  mul.s     $f0, $f0, $f30
/* D00D8 801399D8 00000000 */  nop       
/* D00DC 801399DC 24630008 */  addiu     $v1, $v1, 8
/* D00E0 801399E0 ACA30000 */  sw        $v1, ($a1)
/* D00E4 801399E4 AC820000 */  sw        $v0, ($a0)
/* D00E8 801399E8 46020003 */  div.s     $f0, $f0, $f2
/* D00EC 801399EC 4600203E */  c.le.s    $f4, $f0
/* D00F0 801399F0 00000000 */  nop       
/* D00F4 801399F4 45010005 */  bc1t      .L80139A0C
/* D00F8 801399F8 24840004 */   addiu    $a0, $a0, 4
/* D00FC 801399FC 4600028D */  trunc.w.s $f10, $f0
/* D0100 80139A00 44035000 */  mfc1      $v1, $f10
/* D0104 80139A04 0804E68A */  j         .L80139A28
/* D0108 80139A08 2402FF00 */   addiu    $v0, $zero, -0x100
.L80139A0C:
/* D010C 80139A0C 46040001 */  sub.s     $f0, $f0, $f4
/* D0110 80139A10 3C028000 */  lui       $v0, 0x8000
/* D0114 80139A14 4600028D */  trunc.w.s $f10, $f0
/* D0118 80139A18 44035000 */  mfc1      $v1, $f10
/* D011C 80139A1C 00000000 */  nop       
/* D0120 80139A20 00621825 */  or        $v1, $v1, $v0
/* D0124 80139A24 2402FF00 */  addiu     $v0, $zero, -0x100
.L80139A28:
/* D0128 80139A28 00621025 */  or        $v0, $v1, $v0
/* D012C 80139A2C AC820000 */  sw        $v0, ($a0)
/* D0130 80139A30 8FAD0088 */  lw        $t5, 0x88($sp)
/* D0134 80139A34 15A00091 */  bnez      $t5, .L80139C7C
/* D0138 80139A38 00000000 */   nop      
/* D013C 80139A3C 3C06800A */  lui       $a2, 0x800a
/* D0140 80139A40 24C6A66C */  addiu     $a2, $a2, -0x5994
/* D0144 80139A44 8CC50000 */  lw        $a1, ($a2)
/* D0148 80139A48 87C3000E */  lh        $v1, 0xe($fp)
/* D014C 80139A4C 87C2000A */  lh        $v0, 0xa($fp)
/* D0150 80139A50 3C014200 */  lui       $at, 0x4200
/* D0154 80139A54 44811000 */  mtc1      $at, $f2
/* D0158 80139A58 00A0382D */  daddu     $a3, $a1, $zero
/* D015C 80139A5C 24A50008 */  addiu     $a1, $a1, 8
/* D0160 80139A60 00621821 */  addu      $v1, $v1, $v0
/* D0164 80139A64 00031880 */  sll       $v1, $v1, 2
/* D0168 80139A68 30630FFF */  andi      $v1, $v1, 0xfff
/* D016C 80139A6C ACC50000 */  sw        $a1, ($a2)
/* D0170 80139A70 87C20010 */  lh        $v0, 0x10($fp)
/* D0174 80139A74 87C4000C */  lh        $a0, 0xc($fp)
/* D0178 80139A78 00031B00 */  sll       $v1, $v1, 0xc
/* D017C 80139A7C 00441021 */  addu      $v0, $v0, $a0
/* D0180 80139A80 00021080 */  sll       $v0, $v0, 2
/* D0184 80139A84 30420FFF */  andi      $v0, $v0, 0xfff
/* D0188 80139A88 3C04E400 */  lui       $a0, 0xe400
/* D018C 80139A8C 00441025 */  or        $v0, $v0, $a0
/* D0190 80139A90 00621825 */  or        $v1, $v1, $v0
/* D0194 80139A94 ACE30000 */  sw        $v1, ($a3)
/* D0198 80139A98 87C3000E */  lh        $v1, 0xe($fp)
/* D019C 80139A9C 24A20008 */  addiu     $v0, $a1, 8
/* D01A0 80139AA0 ACC20000 */  sw        $v0, ($a2)
/* D01A4 80139AA4 2402000C */  addiu     $v0, $zero, 0xc
/* D01A8 80139AA8 8FAD008C */  lw        $t5, 0x8c($sp)
/* D01AC 80139AAC 00031880 */  sll       $v1, $v1, 2
/* D01B0 80139AB0 30630FFF */  andi      $v1, $v1, 0xfff
/* D01B4 80139AB4 004D1023 */  subu      $v0, $v0, $t5
/* D01B8 80139AB8 44820000 */  mtc1      $v0, $f0
/* D01BC 80139ABC 00000000 */  nop       
/* D01C0 80139AC0 46800020 */  cvt.s.w   $f0, $f0
/* D01C4 80139AC4 00031B00 */  sll       $v1, $v1, 0xc
/* D01C8 80139AC8 46020002 */  mul.s     $f0, $f0, $f2
/* D01CC 80139ACC 00000000 */  nop       
/* D01D0 80139AD0 87C20010 */  lh        $v0, 0x10($fp)
/* D01D4 80139AD4 3C014180 */  lui       $at, 0x4180
/* D01D8 80139AD8 44811000 */  mtc1      $at, $f2
/* D01DC 80139ADC 00021080 */  sll       $v0, $v0, 2
/* D01E0 80139AE0 30420FFF */  andi      $v0, $v0, 0xfff
/* D01E4 80139AE4 00621825 */  or        $v1, $v1, $v0
/* D01E8 80139AE8 46160003 */  div.s     $f0, $f0, $f22
/* D01EC 80139AEC 46020000 */  add.s     $f0, $f0, $f2
/* D01F0 80139AF0 3C014480 */  lui       $at, 0x4480
/* D01F4 80139AF4 44811000 */  mtc1      $at, $f2
/* D01F8 80139AF8 3C02E100 */  lui       $v0, 0xe100
/* D01FC 80139AFC ACE30004 */  sw        $v1, 4($a3)
/* D0200 80139B00 46020000 */  add.s     $f0, $f0, $f2
/* D0204 80139B04 3C014F00 */  lui       $at, 0x4f00
/* D0208 80139B08 44811000 */  mtc1      $at, $f2
/* D020C 80139B0C 24A70004 */  addiu     $a3, $a1, 4
/* D0210 80139B10 4600103E */  c.le.s    $f2, $f0
/* D0214 80139B14 00000000 */  nop       
/* D0218 80139B18 45010005 */  bc1t      .L80139B30
/* D021C 80139B1C ACA20000 */   sw       $v0, ($a1)
/* D0220 80139B20 4600028D */  trunc.w.s $f10, $f0
/* D0224 80139B24 44035000 */  mfc1      $v1, $f10
/* D0228 80139B28 0804E6D3 */  j         .L80139B4C
/* D022C 80139B2C 24020013 */   addiu    $v0, $zero, 0x13
.L80139B30:
/* D0230 80139B30 46020001 */  sub.s     $f0, $f0, $f2
/* D0234 80139B34 3C028000 */  lui       $v0, 0x8000
/* D0238 80139B38 4600028D */  trunc.w.s $f10, $f0
/* D023C 80139B3C 44035000 */  mfc1      $v1, $f10
/* D0240 80139B40 00000000 */  nop       
/* D0244 80139B44 00621825 */  or        $v1, $v1, $v0
/* D0248 80139B48 24020013 */  addiu     $v0, $zero, 0x13
.L80139B4C:
/* D024C 80139B4C 8FAD0090 */  lw        $t5, 0x90($sp)
/* D0250 80139B50 3C014200 */  lui       $at, 0x4200
/* D0254 80139B54 44811000 */  mtc1      $at, $f2
/* D0258 80139B58 004D1023 */  subu      $v0, $v0, $t5
/* D025C 80139B5C 44820000 */  mtc1      $v0, $f0
/* D0260 80139B60 00000000 */  nop       
/* D0264 80139B64 46800020 */  cvt.s.w   $f0, $f0
/* D0268 80139B68 46020002 */  mul.s     $f0, $f0, $f2
/* D026C 80139B6C 00000000 */  nop       
/* D0270 80139B70 3C014180 */  lui       $at, 0x4180
/* D0274 80139B74 44811000 */  mtc1      $at, $f2
/* D0278 80139B78 46160003 */  div.s     $f0, $f0, $f22
/* D027C 80139B7C 46020000 */  add.s     $f0, $f0, $f2
/* D0280 80139B80 3C014480 */  lui       $at, 0x4480
/* D0284 80139B84 44811000 */  mtc1      $at, $f2
/* D0288 80139B88 00000000 */  nop       
/* D028C 80139B8C 46020000 */  add.s     $f0, $f0, $f2
/* D0290 80139B90 3C014F00 */  lui       $at, 0x4f00
/* D0294 80139B94 44811000 */  mtc1      $at, $f2
/* D0298 80139B98 00000000 */  nop       
/* D029C 80139B9C 4600103E */  c.le.s    $f2, $f0
/* D02A0 80139BA0 00000000 */  nop       
/* D02A4 80139BA4 45010005 */  bc1t      .L80139BBC
/* D02A8 80139BA8 00033400 */   sll      $a2, $v1, 0x10
/* D02AC 80139BAC 4600028D */  trunc.w.s $f10, $f0
/* D02B0 80139BB0 44045000 */  mfc1      $a0, $f10
/* D02B4 80139BB4 0804E6F5 */  j         .L80139BD4
/* D02B8 80139BB8 00000000 */   nop      
.L80139BBC:
/* D02BC 80139BBC 46020001 */  sub.s     $f0, $f0, $f2
/* D02C0 80139BC0 3C028000 */  lui       $v0, 0x8000
/* D02C4 80139BC4 4600028D */  trunc.w.s $f10, $f0
/* D02C8 80139BC8 44045000 */  mfc1      $a0, $f10
/* D02CC 80139BCC 00000000 */  nop       
/* D02D0 80139BD0 00822025 */  or        $a0, $a0, $v0
.L80139BD4:
/* D02D4 80139BD4 3C05800A */  lui       $a1, 0x800a
/* D02D8 80139BD8 24A5A66C */  addiu     $a1, $a1, -0x5994
/* D02DC 80139BDC 3082FFFF */  andi      $v0, $a0, 0xffff
/* D02E0 80139BE0 8CA30000 */  lw        $v1, ($a1)
/* D02E4 80139BE4 00C21025 */  or        $v0, $a2, $v0
/* D02E8 80139BE8 ACE20000 */  sw        $v0, ($a3)
/* D02EC 80139BEC 3C02F100 */  lui       $v0, 0xf100
/* D02F0 80139BF0 3C014480 */  lui       $at, 0x4480
/* D02F4 80139BF4 44810000 */  mtc1      $at, $f0
/* D02F8 80139BF8 3C014F00 */  lui       $at, 0x4f00
/* D02FC 80139BFC 44811000 */  mtc1      $at, $f2
/* D0300 80139C00 0060202D */  daddu     $a0, $v1, $zero
/* D0304 80139C04 24630008 */  addiu     $v1, $v1, 8
/* D0308 80139C08 46160003 */  div.s     $f0, $f0, $f22
/* D030C 80139C0C ACA30000 */  sw        $v1, ($a1)
/* D0310 80139C10 AC820000 */  sw        $v0, ($a0)
/* D0314 80139C14 4600103E */  c.le.s    $f2, $f0
/* D0318 80139C18 00000000 */  nop       
/* D031C 80139C1C 45010005 */  bc1t      .L80139C34
/* D0320 80139C20 24840004 */   addiu    $a0, $a0, 4
/* D0324 80139C24 4600028D */  trunc.w.s $f10, $f0
/* D0328 80139C28 44035000 */  mfc1      $v1, $f10
/* D032C 80139C2C 0804E714 */  j         .L80139C50
/* D0330 80139C30 00032C00 */   sll      $a1, $v1, 0x10
.L80139C34:
/* D0334 80139C34 46020001 */  sub.s     $f0, $f0, $f2
/* D0338 80139C38 3C028000 */  lui       $v0, 0x8000
/* D033C 80139C3C 4600028D */  trunc.w.s $f10, $f0
/* D0340 80139C40 44035000 */  mfc1      $v1, $f10
/* D0344 80139C44 00000000 */  nop       
/* D0348 80139C48 00621825 */  or        $v1, $v1, $v0
/* D034C 80139C4C 00032C00 */  sll       $a1, $v1, 0x10
.L80139C50:
/* D0350 80139C50 3C014480 */  lui       $at, 0x4480
/* D0354 80139C54 44810000 */  mtc1      $at, $f0
/* D0358 80139C58 3C014F00 */  lui       $at, 0x4f00
/* D035C 80139C5C 44811000 */  mtc1      $at, $f2
/* D0360 80139C60 46160003 */  div.s     $f0, $f0, $f22
/* D0364 80139C64 4600103E */  c.le.s    $f2, $f0
/* D0368 80139C68 00000000 */  nop       
/* D036C 80139C6C 4500008A */  bc1f      .L80139E98
/* D0370 80139C70 00000000 */   nop      
/* D0374 80139C74 0804E7AA */  j         .L80139EA8
/* D0378 80139C78 46020001 */   sub.s    $f0, $f0, $f2
.L80139C7C:
/* D037C 80139C7C 3C06800A */  lui       $a2, 0x800a
/* D0380 80139C80 24C6A66C */  addiu     $a2, $a2, -0x5994
/* D0384 80139C84 8CC50000 */  lw        $a1, ($a2)
/* D0388 80139C88 87C3000E */  lh        $v1, 0xe($fp)
/* D038C 80139C8C 87C2000A */  lh        $v0, 0xa($fp)
/* D0390 80139C90 3C014200 */  lui       $at, 0x4200
/* D0394 80139C94 44811000 */  mtc1      $at, $f2
/* D0398 80139C98 00A0382D */  daddu     $a3, $a1, $zero
/* D039C 80139C9C 24A50008 */  addiu     $a1, $a1, 8
/* D03A0 80139CA0 00621821 */  addu      $v1, $v1, $v0
/* D03A4 80139CA4 00031880 */  sll       $v1, $v1, 2
/* D03A8 80139CA8 30630FFF */  andi      $v1, $v1, 0xfff
/* D03AC 80139CAC ACC50000 */  sw        $a1, ($a2)
/* D03B0 80139CB0 87C20010 */  lh        $v0, 0x10($fp)
/* D03B4 80139CB4 87C4000C */  lh        $a0, 0xc($fp)
/* D03B8 80139CB8 00031B00 */  sll       $v1, $v1, 0xc
/* D03BC 80139CBC 00441021 */  addu      $v0, $v0, $a0
/* D03C0 80139CC0 00021080 */  sll       $v0, $v0, 2
/* D03C4 80139CC4 30420FFF */  andi      $v0, $v0, 0xfff
/* D03C8 80139CC8 3C04E400 */  lui       $a0, 0xe400
/* D03CC 80139CCC 00441025 */  or        $v0, $v0, $a0
/* D03D0 80139CD0 00621825 */  or        $v1, $v1, $v0
/* D03D4 80139CD4 ACE30000 */  sw        $v1, ($a3)
/* D03D8 80139CD8 87C3000E */  lh        $v1, 0xe($fp)
/* D03DC 80139CDC 24A20008 */  addiu     $v0, $a1, 8
/* D03E0 80139CE0 ACC20000 */  sw        $v0, ($a2)
/* D03E4 80139CE4 24020009 */  addiu     $v0, $zero, 9
/* D03E8 80139CE8 87C40010 */  lh        $a0, 0x10($fp)
/* D03EC 80139CEC 8FAD008C */  lw        $t5, 0x8c($sp)
/* D03F0 80139CF0 00031880 */  sll       $v1, $v1, 2
/* D03F4 80139CF4 30630FFF */  andi      $v1, $v1, 0xfff
/* D03F8 80139CF8 00031B00 */  sll       $v1, $v1, 0xc
/* D03FC 80139CFC 00042080 */  sll       $a0, $a0, 2
/* D0400 80139D00 004D1023 */  subu      $v0, $v0, $t5
/* D0404 80139D04 44820000 */  mtc1      $v0, $f0
/* D0408 80139D08 00000000 */  nop       
/* D040C 80139D0C 46800020 */  cvt.s.w   $f0, $f0
/* D0410 80139D10 30840FFF */  andi      $a0, $a0, 0xfff
/* D0414 80139D14 46020002 */  mul.s     $f0, $f0, $f2
/* D0418 80139D18 00000000 */  nop       
/* D041C 80139D1C 00641825 */  or        $v1, $v1, $a0
/* D0420 80139D20 3C014480 */  lui       $at, 0x4480
/* D0424 80139D24 44811000 */  mtc1      $at, $f2
/* D0428 80139D28 3C02E100 */  lui       $v0, 0xe100
/* D042C 80139D2C ACE30004 */  sw        $v1, 4($a3)
/* D0430 80139D30 46160003 */  div.s     $f0, $f0, $f22
/* D0434 80139D34 46020000 */  add.s     $f0, $f0, $f2
/* D0438 80139D38 3C014F00 */  lui       $at, 0x4f00
/* D043C 80139D3C 44811000 */  mtc1      $at, $f2
/* D0440 80139D40 24A70004 */  addiu     $a3, $a1, 4
/* D0444 80139D44 4600103E */  c.le.s    $f2, $f0
/* D0448 80139D48 00000000 */  nop       
/* D044C 80139D4C 45010005 */  bc1t      .L80139D64
/* D0450 80139D50 ACA20000 */   sw       $v0, ($a1)
/* D0454 80139D54 4600028D */  trunc.w.s $f10, $f0
/* D0458 80139D58 44035000 */  mfc1      $v1, $f10
/* D045C 80139D5C 0804E760 */  j         .L80139D80
/* D0460 80139D60 24020020 */   addiu    $v0, $zero, 0x20
.L80139D64:
/* D0464 80139D64 46020001 */  sub.s     $f0, $f0, $f2
/* D0468 80139D68 3C028000 */  lui       $v0, 0x8000
/* D046C 80139D6C 4600028D */  trunc.w.s $f10, $f0
/* D0470 80139D70 44035000 */  mfc1      $v1, $f10
/* D0474 80139D74 00000000 */  nop       
/* D0478 80139D78 00621825 */  or        $v1, $v1, $v0
/* D047C 80139D7C 24020020 */  addiu     $v0, $zero, 0x20
.L80139D80:
/* D0480 80139D80 8FAD0090 */  lw        $t5, 0x90($sp)
/* D0484 80139D84 3C014200 */  lui       $at, 0x4200
/* D0488 80139D88 44811000 */  mtc1      $at, $f2
/* D048C 80139D8C 004D1023 */  subu      $v0, $v0, $t5
/* D0490 80139D90 44820000 */  mtc1      $v0, $f0
/* D0494 80139D94 00000000 */  nop       
/* D0498 80139D98 46800020 */  cvt.s.w   $f0, $f0
/* D049C 80139D9C 46020002 */  mul.s     $f0, $f0, $f2
/* D04A0 80139DA0 00000000 */  nop       
/* D04A4 80139DA4 3C014480 */  lui       $at, 0x4480
/* D04A8 80139DA8 44811000 */  mtc1      $at, $f2
/* D04AC 80139DAC 46160003 */  div.s     $f0, $f0, $f22
/* D04B0 80139DB0 46020000 */  add.s     $f0, $f0, $f2
/* D04B4 80139DB4 3C014F00 */  lui       $at, 0x4f00
/* D04B8 80139DB8 44811000 */  mtc1      $at, $f2
/* D04BC 80139DBC 00000000 */  nop       
/* D04C0 80139DC0 4600103E */  c.le.s    $f2, $f0
/* D04C4 80139DC4 00000000 */  nop       
/* D04C8 80139DC8 45010005 */  bc1t      .L80139DE0
/* D04CC 80139DCC 00033400 */   sll      $a2, $v1, 0x10
/* D04D0 80139DD0 4600028D */  trunc.w.s $f10, $f0
/* D04D4 80139DD4 44045000 */  mfc1      $a0, $f10
/* D04D8 80139DD8 0804E77E */  j         .L80139DF8
/* D04DC 80139DDC 00000000 */   nop      
.L80139DE0:
/* D04E0 80139DE0 46020001 */  sub.s     $f0, $f0, $f2
/* D04E4 80139DE4 3C028000 */  lui       $v0, 0x8000
/* D04E8 80139DE8 4600028D */  trunc.w.s $f10, $f0
/* D04EC 80139DEC 44045000 */  mfc1      $a0, $f10
/* D04F0 80139DF0 00000000 */  nop       
/* D04F4 80139DF4 00822025 */  or        $a0, $a0, $v0
.L80139DF8:
/* D04F8 80139DF8 3C05800A */  lui       $a1, 0x800a
/* D04FC 80139DFC 24A5A66C */  addiu     $a1, $a1, -0x5994
/* D0500 80139E00 3082FFFF */  andi      $v0, $a0, 0xffff
/* D0504 80139E04 8CA30000 */  lw        $v1, ($a1)
/* D0508 80139E08 00C21025 */  or        $v0, $a2, $v0
/* D050C 80139E0C ACE20000 */  sw        $v0, ($a3)
/* D0510 80139E10 3C02F100 */  lui       $v0, 0xf100
/* D0514 80139E14 3C014480 */  lui       $at, 0x4480
/* D0518 80139E18 44810000 */  mtc1      $at, $f0
/* D051C 80139E1C 3C014F00 */  lui       $at, 0x4f00
/* D0520 80139E20 44811000 */  mtc1      $at, $f2
/* D0524 80139E24 0060202D */  daddu     $a0, $v1, $zero
/* D0528 80139E28 24630008 */  addiu     $v1, $v1, 8
/* D052C 80139E2C 46160003 */  div.s     $f0, $f0, $f22
/* D0530 80139E30 ACA30000 */  sw        $v1, ($a1)
/* D0534 80139E34 AC820000 */  sw        $v0, ($a0)
/* D0538 80139E38 4600103E */  c.le.s    $f2, $f0
/* D053C 80139E3C 00000000 */  nop       
/* D0540 80139E40 45010005 */  bc1t      .L80139E58
/* D0544 80139E44 24840004 */   addiu    $a0, $a0, 4
/* D0548 80139E48 4600028D */  trunc.w.s $f10, $f0
/* D054C 80139E4C 44035000 */  mfc1      $v1, $f10
/* D0550 80139E50 0804E79D */  j         .L80139E74
/* D0554 80139E54 00032C00 */   sll      $a1, $v1, 0x10
.L80139E58:
/* D0558 80139E58 46020001 */  sub.s     $f0, $f0, $f2
/* D055C 80139E5C 3C028000 */  lui       $v0, 0x8000
/* D0560 80139E60 4600028D */  trunc.w.s $f10, $f0
/* D0564 80139E64 44035000 */  mfc1      $v1, $f10
/* D0568 80139E68 00000000 */  nop       
/* D056C 80139E6C 00621825 */  or        $v1, $v1, $v0
/* D0570 80139E70 00032C00 */  sll       $a1, $v1, 0x10
.L80139E74:
/* D0574 80139E74 3C014480 */  lui       $at, 0x4480
/* D0578 80139E78 44810000 */  mtc1      $at, $f0
/* D057C 80139E7C 3C014F00 */  lui       $at, 0x4f00
/* D0580 80139E80 44811000 */  mtc1      $at, $f2
/* D0584 80139E84 46160003 */  div.s     $f0, $f0, $f22
/* D0588 80139E88 4600103E */  c.le.s    $f2, $f0
/* D058C 80139E8C 00000000 */  nop       
/* D0590 80139E90 45030005 */  bc1tl     .L80139EA8
/* D0594 80139E94 46020001 */   sub.s    $f0, $f0, $f2
.L80139E98:
/* D0598 80139E98 4600028D */  trunc.w.s $f10, $f0
/* D059C 80139E9C 44035000 */  mfc1      $v1, $f10
/* D05A0 80139EA0 0804E7B0 */  j         .L80139EC0
/* D05A4 80139EA4 3062FFFF */   andi     $v0, $v1, 0xffff
.L80139EA8:
/* D05A8 80139EA8 3C028000 */  lui       $v0, 0x8000
/* D05AC 80139EAC 4600028D */  trunc.w.s $f10, $f0
/* D05B0 80139EB0 44035000 */  mfc1      $v1, $f10
/* D05B4 80139EB4 00000000 */  nop       
/* D05B8 80139EB8 00621825 */  or        $v1, $v1, $v0
/* D05BC 80139EBC 3062FFFF */  andi      $v0, $v1, 0xffff
.L80139EC0:
/* D05C0 80139EC0 00A21025 */  or        $v0, $a1, $v0
/* D05C4 80139EC4 AC820000 */  sw        $v0, ($a0)
.L80139EC8:
/* D05C8 80139EC8 8FBF0054 */  lw        $ra, 0x54($sp)
/* D05CC 80139ECC 8FBE0050 */  lw        $fp, 0x50($sp)
/* D05D0 80139ED0 8FB7004C */  lw        $s7, 0x4c($sp)
/* D05D4 80139ED4 8FB60048 */  lw        $s6, 0x48($sp)
/* D05D8 80139ED8 8FB50044 */  lw        $s5, 0x44($sp)
/* D05DC 80139EDC 8FB40040 */  lw        $s4, 0x40($sp)
/* D05E0 80139EE0 8FB3003C */  lw        $s3, 0x3c($sp)
/* D05E4 80139EE4 8FB20038 */  lw        $s2, 0x38($sp)
/* D05E8 80139EE8 8FB10034 */  lw        $s1, 0x34($sp)
/* D05EC 80139EEC 8FB00030 */  lw        $s0, 0x30($sp)
/* D05F0 80139EF0 D7BE0080 */  ldc1      $f30, 0x80($sp)
/* D05F4 80139EF4 D7BC0078 */  ldc1      $f28, 0x78($sp)
/* D05F8 80139EF8 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* D05FC 80139EFC D7B80068 */  ldc1      $f24, 0x68($sp)
/* D0600 80139F00 D7B60060 */  ldc1      $f22, 0x60($sp)
/* D0604 80139F04 D7B40058 */  ldc1      $f20, 0x58($sp)
/* D0608 80139F08 03E00008 */  jr        $ra
/* D060C 80139F0C 27BD0088 */   addiu    $sp, $sp, 0x88

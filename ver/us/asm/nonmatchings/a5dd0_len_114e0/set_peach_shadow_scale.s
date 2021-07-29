.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8014F980
.double 0.01

glabel D_8014F988
.double 0.01

.section .text

glabel set_peach_shadow_scale
/* A90D4 801129D4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A90D8 801129D8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A90DC 801129DC 44852000 */  mtc1      $a1, $f4
/* A90E0 801129E0 80420070 */  lb        $v0, 0x70($v0)
/* A90E4 801129E4 3C013DF5 */  lui       $at, 0x3df5
/* A90E8 801129E8 3421C28F */  ori       $at, $at, 0xc28f
/* A90EC 801129EC 44811000 */  mtc1      $at, $f2
/* A90F0 801129F0 14400036 */  bnez      $v0, .L80112ACC
/* A90F4 801129F4 3C03000C */   lui      $v1, 0xc
/* A90F8 801129F8 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* A90FC 801129FC 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* A9100 80112A00 8C4500B8 */  lw        $a1, 0xb8($v0)
/* A9104 80112A04 34630018 */  ori       $v1, $v1, 0x18
/* A9108 80112A08 00A3182B */  sltu      $v1, $a1, $v1
/* A910C 80112A0C 1460002C */  bnez      $v1, .L80112AC0
/* A9110 80112A10 3C02000C */   lui      $v0, 0xc
/* A9114 80112A14 3442001A */  ori       $v0, $v0, 0x1a
/* A9118 80112A18 0045102B */  sltu      $v0, $v0, $a1
/* A911C 80112A1C 10400004 */  beqz      $v0, .L80112A30
/* A9120 80112A20 3C02000D */   lui      $v0, 0xd
/* A9124 80112A24 34420008 */  ori       $v0, $v0, 8
/* A9128 80112A28 14A20025 */  bne       $a1, $v0, .L80112AC0
/* A912C 80112A2C 00000000 */   nop
.L80112A30:
/* A9130 80112A30 3C014522 */  lui       $at, 0x4522
/* A9134 80112A34 34218000 */  ori       $at, $at, 0x8000
/* A9138 80112A38 44810000 */  mtc1      $at, $f0
/* A913C 80112A3C 3C013E85 */  lui       $at, 0x3e85
/* A9140 80112A40 34211EB8 */  ori       $at, $at, 0x1eb8
/* A9144 80112A44 44811000 */  mtc1      $at, $f2
/* A9148 80112A48 46002103 */  div.s     $f4, $f4, $f0
/* A914C 80112A4C 46041081 */  sub.s     $f2, $f2, $f4
/* A9150 80112A50 3C018015 */  lui       $at, %hi(D_8014F980)
/* A9154 80112A54 D426F980 */  ldc1      $f6, %lo(D_8014F980)($at)
/* A9158 80112A58 46001021 */  cvt.d.s   $f0, $f2
/* A915C 80112A5C 4626003C */  c.lt.d    $f0, $f6
/* A9160 80112A60 00000000 */  nop
/* A9164 80112A64 45000006 */  bc1f      .L80112A80
/* A9168 80112A68 E482001C */   swc1     $f2, 0x1c($a0)
/* A916C 80112A6C 3C013C23 */  lui       $at, 0x3c23
/* A9170 80112A70 3421D70A */  ori       $at, $at, 0xd70a
/* A9174 80112A74 44810000 */  mtc1      $at, $f0
/* A9178 80112A78 00000000 */  nop
/* A917C 80112A7C E480001C */  swc1      $f0, 0x1c($a0)
.L80112A80:
/* A9180 80112A80 3C013E05 */  lui       $at, 0x3e05
/* A9184 80112A84 34211EB8 */  ori       $at, $at, 0x1eb8
/* A9188 80112A88 44810000 */  mtc1      $at, $f0
/* A918C 80112A8C 00000000 */  nop
/* A9190 80112A90 46040001 */  sub.s     $f0, $f0, $f4
/* A9194 80112A94 E4800024 */  swc1      $f0, 0x24($a0)
/* A9198 80112A98 46000021 */  cvt.d.s   $f0, $f0
/* A919C 80112A9C 4626003C */  c.lt.d    $f0, $f6
/* A91A0 80112AA0 00000000 */  nop
/* A91A4 80112AA4 4500001C */  bc1f      .L80112B18
/* A91A8 80112AA8 00000000 */   nop
/* A91AC 80112AAC 3C013C23 */  lui       $at, 0x3c23
/* A91B0 80112AB0 3421D70A */  ori       $at, $at, 0xd70a
/* A91B4 80112AB4 44810000 */  mtc1      $at, $f0
/* A91B8 80112AB8 03E00008 */  jr        $ra
/* A91BC 80112ABC E4800024 */   swc1     $f0, 0x24($a0)
.L80112AC0:
/* A91C0 80112AC0 3C013E23 */  lui       $at, 0x3e23
/* A91C4 80112AC4 3421D70A */  ori       $at, $at, 0xd70a
/* A91C8 80112AC8 44811000 */  mtc1      $at, $f2
.L80112ACC:
/* A91CC 80112ACC 3C014561 */  lui       $at, 0x4561
/* A91D0 80112AD0 44810000 */  mtc1      $at, $f0
/* A91D4 80112AD4 00000000 */  nop
/* A91D8 80112AD8 46002003 */  div.s     $f0, $f4, $f0
/* A91DC 80112ADC 46001001 */  sub.s     $f0, $f2, $f0
/* A91E0 80112AE0 3C018015 */  lui       $at, %hi(D_8014F988)
/* A91E4 80112AE4 D424F988 */  ldc1      $f4, %lo(D_8014F988)($at)
/* A91E8 80112AE8 460000A1 */  cvt.d.s   $f2, $f0
/* A91EC 80112AEC 4624103C */  c.lt.d    $f2, $f4
/* A91F0 80112AF0 00000000 */  nop
/* A91F4 80112AF4 45000006 */  bc1f      .L80112B10
/* A91F8 80112AF8 E480001C */   swc1     $f0, 0x1c($a0)
/* A91FC 80112AFC 3C013C23 */  lui       $at, 0x3c23
/* A9200 80112B00 3421D70A */  ori       $at, $at, 0xd70a
/* A9204 80112B04 44810000 */  mtc1      $at, $f0
/* A9208 80112B08 00000000 */  nop
/* A920C 80112B0C E480001C */  swc1      $f0, 0x1c($a0)
.L80112B10:
/* A9210 80112B10 C480001C */  lwc1      $f0, 0x1c($a0)
/* A9214 80112B14 E4800024 */  swc1      $f0, 0x24($a0)
.L80112B18:
/* A9218 80112B18 03E00008 */  jr        $ra
/* A921C 80112B1C 00000000 */   nop

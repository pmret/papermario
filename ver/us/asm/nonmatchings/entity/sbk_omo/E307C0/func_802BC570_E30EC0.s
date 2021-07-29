.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802BCBA0_E314F0
.word L802BC5BC_E30F0C, L802BC5FC_E30F4C, L802BC6DC_E3102C, L802BC7D0_E31120, L802BC908_E31258, L802BC928_E31278, L802BC968_E312B8, 0

glabel D_802BCBC0_E31510
.double 0.08

glabel D_802BCBC8_E31518
.double 2.8

glabel D_802BCBD0_E31520
.double 0.1

glabel D_802BCBD8_E31528
.double 0.08

.section .text

glabel func_802BC570_E30EC0
/* E30EC0 802BC570 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* E30EC4 802BC574 AFB10014 */  sw        $s1, 0x14($sp)
/* E30EC8 802BC578 0080882D */  daddu     $s1, $a0, $zero
/* E30ECC 802BC57C AFBF0018 */  sw        $ra, 0x18($sp)
/* E30ED0 802BC580 AFB00010 */  sw        $s0, 0x10($sp)
/* E30ED4 802BC584 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* E30ED8 802BC588 F7B80030 */  sdc1      $f24, 0x30($sp)
/* E30EDC 802BC58C F7B60028 */  sdc1      $f22, 0x28($sp)
/* E30EE0 802BC590 F7B40020 */  sdc1      $f20, 0x20($sp)
/* E30EE4 802BC594 8E300040 */  lw        $s0, 0x40($s1)
/* E30EE8 802BC598 82030000 */  lb        $v1, ($s0)
/* E30EEC 802BC59C 2C620007 */  sltiu     $v0, $v1, 7
/* E30EF0 802BC5A0 104000F5 */  beqz      $v0, .L802BC978
/* E30EF4 802BC5A4 00031080 */   sll      $v0, $v1, 2
/* E30EF8 802BC5A8 3C01802C */  lui       $at, %hi(jtbl_802BCBA0_E314F0)
/* E30EFC 802BC5AC 00220821 */  addu      $at, $at, $v0
/* E30F00 802BC5B0 8C22CBA0 */  lw        $v0, %lo(jtbl_802BCBA0_E314F0)($at)
/* E30F04 802BC5B4 00400008 */  jr        $v0
/* E30F08 802BC5B8 00000000 */   nop
glabel L802BC5BC_E30F0C
/* E30F0C 802BC5BC 92020000 */  lbu       $v0, ($s0)
/* E30F10 802BC5C0 3C0142B4 */  lui       $at, 0x42b4
/* E30F14 802BC5C4 44810000 */  mtc1      $at, $f0
/* E30F18 802BC5C8 3C03802C */  lui       $v1, %hi(D_802BCAA0_E313F0)
/* E30F1C 802BC5CC 2463CAA0 */  addiu     $v1, $v1, %lo(D_802BCAA0_E313F0)
/* E30F20 802BC5D0 A2000004 */  sb        $zero, 4($s0)
/* E30F24 802BC5D4 A2000003 */  sb        $zero, 3($s0)
/* E30F28 802BC5D8 24420001 */  addiu     $v0, $v0, 1
/* E30F2C 802BC5DC A2020000 */  sb        $v0, ($s0)
/* E30F30 802BC5E0 E6000014 */  swc1      $f0, 0x14($s0)
/* E30F34 802BC5E4 90620000 */  lbu       $v0, ($v1)
/* E30F38 802BC5E8 A2020005 */  sb        $v0, 5($s0)
/* E30F3C 802BC5EC 90620001 */  lbu       $v0, 1($v1)
/* E30F40 802BC5F0 24042085 */  addiu     $a0, $zero, 0x2085
/* E30F44 802BC5F4 0C05272D */  jal       sfx_play_sound
/* E30F48 802BC5F8 A2020004 */   sb       $v0, 4($s0)
glabel L802BC5FC_E30F4C
/* E30F4C 802BC5FC C60C0014 */  lwc1      $f12, 0x14($s0)
/* E30F50 802BC600 3C0140C9 */  lui       $at, 0x40c9
/* E30F54 802BC604 34210FD0 */  ori       $at, $at, 0xfd0
/* E30F58 802BC608 44810000 */  mtc1      $at, $f0
/* E30F5C 802BC60C 00000000 */  nop
/* E30F60 802BC610 46006302 */  mul.s     $f12, $f12, $f0
/* E30F64 802BC614 00000000 */  nop
/* E30F68 802BC618 C634004C */  lwc1      $f20, 0x4c($s1)
/* E30F6C 802BC61C 3C0143B4 */  lui       $at, 0x43b4
/* E30F70 802BC620 44810000 */  mtc1      $at, $f0
/* E30F74 802BC624 4600A521 */  cvt.d.s   $f20, $f20
/* E30F78 802BC628 0C00A85B */  jal       sin_rad
/* E30F7C 802BC62C 46006303 */   div.s    $f12, $f12, $f0
/* E30F80 802BC630 3C014020 */  lui       $at, 0x4020
/* E30F84 802BC634 44811800 */  mtc1      $at, $f3
/* E30F88 802BC638 44801000 */  mtc1      $zero, $f2
/* E30F8C 802BC63C 46000021 */  cvt.d.s   $f0, $f0
/* E30F90 802BC640 46220002 */  mul.d     $f0, $f0, $f2
/* E30F94 802BC644 00000000 */  nop
/* E30F98 802BC648 4620A500 */  add.d     $f20, $f20, $f0
/* E30F9C 802BC64C 3C014000 */  lui       $at, 0x4000
/* E30FA0 802BC650 44812000 */  mtc1      $at, $f4
/* E30FA4 802BC654 4620A520 */  cvt.s.d   $f20, $f20
/* E30FA8 802BC658 E634004C */  swc1      $f20, 0x4c($s1)
/* E30FAC 802BC65C C6000014 */  lwc1      $f0, 0x14($s0)
/* E30FB0 802BC660 46040000 */  add.s     $f0, $f0, $f4
/* E30FB4 802BC664 3C014334 */  lui       $at, 0x4334
/* E30FB8 802BC668 44811000 */  mtc1      $at, $f2
/* E30FBC 802BC66C 00000000 */  nop
/* E30FC0 802BC670 4600103E */  c.le.s    $f2, $f0
/* E30FC4 802BC674 00000000 */  nop
/* E30FC8 802BC678 45000002 */  bc1f      .L802BC684
/* E30FCC 802BC67C E6000014 */   swc1     $f0, 0x14($s0)
/* E30FD0 802BC680 E6020014 */  swc1      $f2, 0x14($s0)
.L802BC684:
/* E30FD4 802BC684 C6000010 */  lwc1      $f0, 0x10($s0)
/* E30FD8 802BC688 3C014248 */  lui       $at, 0x4248
/* E30FDC 802BC68C 44811000 */  mtc1      $at, $f2
/* E30FE0 802BC690 00000000 */  nop
/* E30FE4 802BC694 46020080 */  add.s     $f2, $f0, $f2
/* E30FE8 802BC698 C620004C */  lwc1      $f0, 0x4c($s1)
/* E30FEC 802BC69C 4600103C */  c.lt.s    $f2, $f0
/* E30FF0 802BC6A0 00000000 */  nop
/* E30FF4 802BC6A4 450000B4 */  bc1f      .L802BC978
/* E30FF8 802BC6A8 00000000 */   nop
/* E30FFC 802BC6AC E622004C */  swc1      $f2, 0x4c($s1)
/* E31000 802BC6B0 92020000 */  lbu       $v0, ($s0)
/* E31004 802BC6B4 3C014040 */  lui       $at, 0x4040
/* E31008 802BC6B8 44810000 */  mtc1      $at, $f0
/* E3100C 802BC6BC 3C0142B4 */  lui       $at, 0x42b4
/* E31010 802BC6C0 44811000 */  mtc1      $at, $f2
/* E31014 802BC6C4 E6040020 */  swc1      $f4, 0x20($s0)
/* E31018 802BC6C8 24420001 */  addiu     $v0, $v0, 1
/* E3101C 802BC6CC A2020000 */  sb        $v0, ($s0)
/* E31020 802BC6D0 E6000018 */  swc1      $f0, 0x18($s0)
/* E31024 802BC6D4 080AF25E */  j         .L802BC978
/* E31028 802BC6D8 E602001C */   swc1     $f2, 0x1c($s0)
glabel L802BC6DC_E3102C
/* E3102C 802BC6DC C60C001C */  lwc1      $f12, 0x1c($s0)
/* E31030 802BC6E0 3C0140C9 */  lui       $at, 0x40c9
/* E31034 802BC6E4 34210FD0 */  ori       $at, $at, 0xfd0
/* E31038 802BC6E8 4481C000 */  mtc1      $at, $f24
/* E3103C 802BC6EC 00000000 */  nop
/* E31040 802BC6F0 46186302 */  mul.s     $f12, $f12, $f24
/* E31044 802BC6F4 00000000 */  nop
/* E31048 802BC6F8 3C0143B4 */  lui       $at, 0x43b4
/* E3104C 802BC6FC 4481A000 */  mtc1      $at, $f20
/* E31050 802BC700 0C00A85B */  jal       sin_rad
/* E31054 802BC704 46146303 */   div.s    $f12, $f12, $f20
/* E31058 802BC708 C60C0020 */  lwc1      $f12, 0x20($s0)
/* E3105C 802BC70C 46006302 */  mul.s     $f12, $f12, $f0
/* E31060 802BC710 00000000 */  nop
/* E31064 802BC714 0C00A6C9 */  jal       clamp_angle
/* E31068 802BC718 E62C0068 */   swc1     $f12, 0x68($s1)
/* E3106C 802BC71C C600001C */  lwc1      $f0, 0x1c($s0)
/* E31070 802BC720 3C0141F0 */  lui       $at, 0x41f0
/* E31074 802BC724 4481B000 */  mtc1      $at, $f22
/* E31078 802BC728 00000000 */  nop
/* E3107C 802BC72C 46160000 */  add.s     $f0, $f0, $f22
/* E31080 802BC730 4600A03E */  c.le.s    $f20, $f0
/* E31084 802BC734 00000000 */  nop
/* E31088 802BC738 45000003 */  bc1f      .L802BC748
/* E3108C 802BC73C E600001C */   swc1     $f0, 0x1c($s0)
/* E31090 802BC740 46140001 */  sub.s     $f0, $f0, $f20
/* E31094 802BC744 E600001C */  swc1      $f0, 0x1c($s0)
.L802BC748:
/* E31098 802BC748 C60C0014 */  lwc1      $f12, 0x14($s0)
/* E3109C 802BC74C 46186302 */  mul.s     $f12, $f12, $f24
/* E310A0 802BC750 00000000 */  nop
/* E310A4 802BC754 0C00A874 */  jal       cos_rad
/* E310A8 802BC758 46146303 */   div.s    $f12, $f12, $f20
/* E310AC 802BC75C C6020018 */  lwc1      $f2, 0x18($s0)
/* E310B0 802BC760 46001082 */  mul.s     $f2, $f2, $f0
/* E310B4 802BC764 00000000 */  nop
/* E310B8 802BC768 C620004C */  lwc1      $f0, 0x4c($s1)
/* E310BC 802BC76C 46020000 */  add.s     $f0, $f0, $f2
/* E310C0 802BC770 E620004C */  swc1      $f0, 0x4c($s1)
/* E310C4 802BC774 C6000014 */  lwc1      $f0, 0x14($s0)
/* E310C8 802BC778 46160000 */  add.s     $f0, $f0, $f22
/* E310CC 802BC77C 4600A03E */  c.le.s    $f20, $f0
/* E310D0 802BC780 00000000 */  nop
/* E310D4 802BC784 45000003 */  bc1f      .L802BC794
/* E310D8 802BC788 E6000014 */   swc1     $f0, 0x14($s0)
/* E310DC 802BC78C 46140001 */  sub.s     $f0, $f0, $f20
/* E310E0 802BC790 E6000014 */  swc1      $f0, 0x14($s0)
.L802BC794:
/* E310E4 802BC794 C6000018 */  lwc1      $f0, 0x18($s0)
/* E310E8 802BC798 3C01802C */  lui       $at, %hi(D_802BCBC0_E31510)
/* E310EC 802BC79C D422CBC0 */  ldc1      $f2, %lo(D_802BCBC0_E31510)($at)
/* E310F0 802BC7A0 46000021 */  cvt.d.s   $f0, $f0
/* E310F4 802BC7A4 46220001 */  sub.d     $f0, $f0, $f2
/* E310F8 802BC7A8 3C01802C */  lui       $at, %hi(D_802BCBC8_E31518)
/* E310FC 802BC7AC D424CBC8 */  ldc1      $f4, %lo(D_802BCBC8_E31518)($at)
/* E31100 802BC7B0 46200020 */  cvt.s.d   $f0, $f0
/* E31104 802BC7B4 460000A1 */  cvt.d.s   $f2, $f0
/* E31108 802BC7B8 4624103C */  c.lt.d    $f2, $f4
/* E3110C 802BC7BC 00000000 */  nop
/* E31110 802BC7C0 4500006D */  bc1f      .L802BC978
/* E31114 802BC7C4 E6000018 */   swc1     $f0, 0x18($s0)
/* E31118 802BC7C8 080AF256 */  j         .L802BC958
/* E3111C 802BC7CC 00000000 */   nop
glabel L802BC7D0_E31120
/* E31120 802BC7D0 C6000020 */  lwc1      $f0, 0x20($s0)
/* E31124 802BC7D4 3C01802C */  lui       $at, %hi(D_802BCBD0_E31520)
/* E31128 802BC7D8 D422CBD0 */  ldc1      $f2, %lo(D_802BCBD0_E31520)($at)
/* E3112C 802BC7DC 46000021 */  cvt.d.s   $f0, $f0
/* E31130 802BC7E0 46220001 */  sub.d     $f0, $f0, $f2
/* E31134 802BC7E4 4480B000 */  mtc1      $zero, $f22
/* E31138 802BC7E8 46200020 */  cvt.s.d   $f0, $f0
/* E3113C 802BC7EC 4616003E */  c.le.s    $f0, $f22
/* E31140 802BC7F0 00000000 */  nop
/* E31144 802BC7F4 45000002 */  bc1f      .L802BC800
/* E31148 802BC7F8 E6000020 */   swc1     $f0, 0x20($s0)
/* E3114C 802BC7FC E6160020 */  swc1      $f22, 0x20($s0)
.L802BC800:
/* E31150 802BC800 C60C001C */  lwc1      $f12, 0x1c($s0)
/* E31154 802BC804 3C0140C9 */  lui       $at, 0x40c9
/* E31158 802BC808 34210FD0 */  ori       $at, $at, 0xfd0
/* E3115C 802BC80C 4481D000 */  mtc1      $at, $f26
/* E31160 802BC810 00000000 */  nop
/* E31164 802BC814 461A6302 */  mul.s     $f12, $f12, $f26
/* E31168 802BC818 00000000 */  nop
/* E3116C 802BC81C 3C0143B4 */  lui       $at, 0x43b4
/* E31170 802BC820 4481A000 */  mtc1      $at, $f20
/* E31174 802BC824 0C00A85B */  jal       sin_rad
/* E31178 802BC828 46146303 */   div.s    $f12, $f12, $f20
/* E3117C 802BC82C C60C0020 */  lwc1      $f12, 0x20($s0)
/* E31180 802BC830 46006302 */  mul.s     $f12, $f12, $f0
/* E31184 802BC834 00000000 */  nop
/* E31188 802BC838 0C00A6C9 */  jal       clamp_angle
/* E3118C 802BC83C E62C0068 */   swc1     $f12, 0x68($s1)
/* E31190 802BC840 C600001C */  lwc1      $f0, 0x1c($s0)
/* E31194 802BC844 3C0141F0 */  lui       $at, 0x41f0
/* E31198 802BC848 4481C000 */  mtc1      $at, $f24
/* E3119C 802BC84C 00000000 */  nop
/* E311A0 802BC850 46180000 */  add.s     $f0, $f0, $f24
/* E311A4 802BC854 4600A03E */  c.le.s    $f20, $f0
/* E311A8 802BC858 00000000 */  nop
/* E311AC 802BC85C 45000003 */  bc1f      .L802BC86C
/* E311B0 802BC860 E600001C */   swc1     $f0, 0x1c($s0)
/* E311B4 802BC864 46140001 */  sub.s     $f0, $f0, $f20
/* E311B8 802BC868 E600001C */  swc1      $f0, 0x1c($s0)
.L802BC86C:
/* E311BC 802BC86C 0C0AF12E */  jal       func_802BC4B8_E30E08
/* E311C0 802BC870 0220202D */   daddu    $a0, $s1, $zero
/* E311C4 802BC874 C60C0014 */  lwc1      $f12, 0x14($s0)
/* E311C8 802BC878 461A6302 */  mul.s     $f12, $f12, $f26
/* E311CC 802BC87C 00000000 */  nop
/* E311D0 802BC880 0C00A874 */  jal       cos_rad
/* E311D4 802BC884 46146303 */   div.s    $f12, $f12, $f20
/* E311D8 802BC888 C6020018 */  lwc1      $f2, 0x18($s0)
/* E311DC 802BC88C 46001082 */  mul.s     $f2, $f2, $f0
/* E311E0 802BC890 00000000 */  nop
/* E311E4 802BC894 C620004C */  lwc1      $f0, 0x4c($s1)
/* E311E8 802BC898 46020000 */  add.s     $f0, $f0, $f2
/* E311EC 802BC89C E620004C */  swc1      $f0, 0x4c($s1)
/* E311F0 802BC8A0 C6000014 */  lwc1      $f0, 0x14($s0)
/* E311F4 802BC8A4 46180000 */  add.s     $f0, $f0, $f24
/* E311F8 802BC8A8 4600A03E */  c.le.s    $f20, $f0
/* E311FC 802BC8AC 00000000 */  nop
/* E31200 802BC8B0 45000003 */  bc1f      .L802BC8C0
/* E31204 802BC8B4 E6000014 */   swc1     $f0, 0x14($s0)
/* E31208 802BC8B8 46140001 */  sub.s     $f0, $f0, $f20
/* E3120C 802BC8BC E6000014 */  swc1      $f0, 0x14($s0)
.L802BC8C0:
/* E31210 802BC8C0 C6000018 */  lwc1      $f0, 0x18($s0)
/* E31214 802BC8C4 3C01802C */  lui       $at, %hi(D_802BCBD8_E31528)
/* E31218 802BC8C8 D422CBD8 */  ldc1      $f2, %lo(D_802BCBD8_E31528)($at)
/* E3121C 802BC8CC 46000021 */  cvt.d.s   $f0, $f0
/* E31220 802BC8D0 46220001 */  sub.d     $f0, $f0, $f2
/* E31224 802BC8D4 46200020 */  cvt.s.d   $f0, $f0
/* E31228 802BC8D8 4616003E */  c.le.s    $f0, $f22
/* E3122C 802BC8DC 00000000 */  nop
/* E31230 802BC8E0 45000025 */  bc1f      .L802BC978
/* E31234 802BC8E4 E6000018 */   swc1     $f0, 0x18($s0)
/* E31238 802BC8E8 92020000 */  lbu       $v0, ($s0)
/* E3123C 802BC8EC 24030008 */  addiu     $v1, $zero, 8
/* E31240 802BC8F0 E6160018 */  swc1      $f22, 0x18($s0)
/* E31244 802BC8F4 A2030001 */  sb        $v1, 1($s0)
/* E31248 802BC8F8 24420001 */  addiu     $v0, $v0, 1
/* E3124C 802BC8FC A2020000 */  sb        $v0, ($s0)
/* E31250 802BC900 080AF25E */  j         .L802BC978
/* E31254 802BC904 E6360068 */   swc1     $f22, 0x68($s1)
glabel L802BC908_E31258
/* E31258 802BC908 92020001 */  lbu       $v0, 1($s0)
/* E3125C 802BC90C 2442FFFF */  addiu     $v0, $v0, -1
/* E31260 802BC910 A2020001 */  sb        $v0, 1($s0)
/* E31264 802BC914 00021600 */  sll       $v0, $v0, 0x18
/* E31268 802BC918 1040000F */  beqz      $v0, .L802BC958
/* E3126C 802BC91C 00000000 */   nop
/* E31270 802BC920 080AF25E */  j         .L802BC978
/* E31274 802BC924 00000000 */   nop
glabel L802BC928_E31278
/* E31278 802BC928 C620004C */  lwc1      $f0, 0x4c($s1)
/* E3127C 802BC92C 3C014100 */  lui       $at, 0x4100
/* E31280 802BC930 44811000 */  mtc1      $at, $f2
/* E31284 802BC934 00000000 */  nop
/* E31288 802BC938 46020001 */  sub.s     $f0, $f0, $f2
/* E3128C 802BC93C E620004C */  swc1      $f0, 0x4c($s1)
/* E31290 802BC940 C6020010 */  lwc1      $f2, 0x10($s0)
/* E31294 802BC944 4602003E */  c.le.s    $f0, $f2
/* E31298 802BC948 00000000 */  nop
/* E3129C 802BC94C 4500000A */  bc1f      .L802BC978
/* E312A0 802BC950 00000000 */   nop
/* E312A4 802BC954 E622004C */  swc1      $f2, 0x4c($s1)
.L802BC958:
/* E312A8 802BC958 92020000 */  lbu       $v0, ($s0)
/* E312AC 802BC95C 24420001 */  addiu     $v0, $v0, 1
/* E312B0 802BC960 080AF25E */  j         .L802BC978
/* E312B4 802BC964 A2020000 */   sb       $v0, ($s0)
glabel L802BC968_E312B8
/* E312B8 802BC968 0C043F5A */  jal       exec_entity_commandlist
/* E312BC 802BC96C 0220202D */   daddu    $a0, $s1, $zero
/* E312C0 802BC970 0C038050 */  jal       enable_player_static_collisions
/* E312C4 802BC974 A2000000 */   sb       $zero, ($s0)
.L802BC978:
/* E312C8 802BC978 8FBF0018 */  lw        $ra, 0x18($sp)
/* E312CC 802BC97C 8FB10014 */  lw        $s1, 0x14($sp)
/* E312D0 802BC980 8FB00010 */  lw        $s0, 0x10($sp)
/* E312D4 802BC984 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* E312D8 802BC988 D7B80030 */  ldc1      $f24, 0x30($sp)
/* E312DC 802BC98C D7B60028 */  ldc1      $f22, 0x28($sp)
/* E312E0 802BC990 D7B40020 */  ldc1      $f20, 0x20($sp)
/* E312E4 802BC994 03E00008 */  jr        $ra
/* E312E8 802BC998 27BD0040 */   addiu    $sp, $sp, 0x40

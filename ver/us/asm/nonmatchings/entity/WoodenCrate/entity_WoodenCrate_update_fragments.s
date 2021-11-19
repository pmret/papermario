.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802EB350
.double 0.4

dlabel D_802EB358
.double 1.6

dlabel D_802EB360
.double 0.8

dlabel D_802EB368
.double -10.2

.section .text

glabel entity_WoodenCrate_update_fragments
/* 109820 802E7FA0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 109824 802E7FA4 F7B80068 */  sdc1      $f24, 0x68($sp)
/* 109828 802E7FA8 4480C000 */  mtc1      $zero, $f24
/* 10982C 802E7FAC F7BC0078 */  sdc1      $f28, 0x78($sp)
/* 109830 802E7FB0 3C014100 */  lui       $at, 0x4100
/* 109834 802E7FB4 4481E000 */  mtc1      $at, $f28
/* 109838 802E7FB8 AFBE0050 */  sw        $fp, 0x50($sp)
/* 10983C 802E7FBC 0080F02D */  daddu     $fp, $a0, $zero
/* 109840 802E7FC0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 109844 802E7FC4 0000982D */  daddu     $s3, $zero, $zero
/* 109848 802E7FC8 AFB60048 */  sw        $s6, 0x48($sp)
/* 10984C 802E7FCC 27B60020 */  addiu     $s6, $sp, 0x20
/* 109850 802E7FD0 AFB50044 */  sw        $s5, 0x44($sp)
/* 109854 802E7FD4 27B50024 */  addiu     $s5, $sp, 0x24
/* 109858 802E7FD8 AFB40040 */  sw        $s4, 0x40($sp)
/* 10985C 802E7FDC 27B40028 */  addiu     $s4, $sp, 0x28
/* 109860 802E7FE0 AFB7004C */  sw        $s7, 0x4c($sp)
/* 109864 802E7FE4 3C178000 */  lui       $s7, 0x8000
/* 109868 802E7FE8 AFBF0054 */  sw        $ra, 0x54($sp)
/* 10986C 802E7FEC AFB20038 */  sw        $s2, 0x38($sp)
/* 109870 802E7FF0 AFB10034 */  sw        $s1, 0x34($sp)
/* 109874 802E7FF4 AFB00030 */  sw        $s0, 0x30($sp)
/* 109878 802E7FF8 F7BE0080 */  sdc1      $f30, 0x80($sp)
/* 10987C 802E7FFC F7BA0070 */  sdc1      $f26, 0x70($sp)
/* 109880 802E8000 F7B60060 */  sdc1      $f22, 0x60($sp)
/* 109884 802E8004 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 109888 802E8008 8FD20040 */  lw        $s2, 0x40($fp)
/* 10988C 802E800C 4600C786 */  mov.s     $f30, $f24
/* 109890 802E8010 4600C686 */  mov.s     $f26, $f24
/* 109894 802E8014 0240882D */  daddu     $s1, $s2, $zero
/* 109898 802E8018 0240802D */  daddu     $s0, $s2, $zero
.L802E801C:
/* 10989C 802E801C 82230010 */  lb        $v1, 0x10($s1)
/* 1098A0 802E8020 24020001 */  addiu     $v0, $zero, 1
/* 1098A4 802E8024 10620028 */  beq       $v1, $v0, .L802E80C8
/* 1098A8 802E8028 28620002 */   slti     $v0, $v1, 2
/* 1098AC 802E802C 10400005 */  beqz      $v0, .L802E8044
/* 1098B0 802E8030 24020002 */   addiu    $v0, $zero, 2
/* 1098B4 802E8034 10600009 */  beqz      $v1, .L802E805C
/* 1098B8 802E8038 00000000 */   nop
/* 1098BC 802E803C 080BA05A */  j         .L802E8168
/* 1098C0 802E8040 00000000 */   nop
.L802E8044:
/* 1098C4 802E8044 10620029 */  beq       $v1, $v0, .L802E80EC
/* 1098C8 802E8048 24020003 */   addiu    $v0, $zero, 3
/* 1098CC 802E804C 50620046 */  beql      $v1, $v0, .L802E8168
/* 1098D0 802E8050 26730001 */   addiu    $s3, $s3, 1
/* 1098D4 802E8054 080BA05A */  j         .L802E8168
/* 1098D8 802E8058 00000000 */   nop
.L802E805C:
/* 1098DC 802E805C 3C014000 */  lui       $at, 0x4000
/* 1098E0 802E8060 4481F000 */  mtc1      $at, $f30
/* 1098E4 802E8064 922200A0 */  lbu       $v0, 0xa0($s1)
/* 1098E8 802E8068 C61800C4 */  lwc1      $f24, 0xc4($s0)
/* 1098EC 802E806C 3C014120 */  lui       $at, 0x4120
/* 1098F0 802E8070 44810000 */  mtc1      $at, $f0
/* 1098F4 802E8074 44801000 */  mtc1      $zero, $f2
/* 1098F8 802E8078 44822000 */  mtc1      $v0, $f4
/* 1098FC 802E807C 00000000 */  nop
/* 109900 802E8080 46802120 */  cvt.s.w   $f4, $f4
/* 109904 802E8084 4618103E */  c.le.s    $f2, $f24
/* 109908 802E8088 00000000 */  nop
/* 10990C 802E808C 45000006 */  bc1f      .L802E80A8
/* 109910 802E8090 46002683 */   div.s    $f26, $f4, $f0
/* 109914 802E8094 3C01802F */  lui       $at, %hi(D_802EB350)
/* 109918 802E8098 D422B350 */  ldc1      $f2, %lo(D_802EB350)($at)
/* 10991C 802E809C 4600C021 */  cvt.d.s   $f0, $f24
/* 109920 802E80A0 080BA02F */  j         .L802E80BC
/* 109924 802E80A4 46220001 */   sub.d    $f0, $f0, $f2
.L802E80A8:
/* 109928 802E80A8 3C013FE0 */  lui       $at, 0x3fe0
/* 10992C 802E80AC 44811800 */  mtc1      $at, $f3
/* 109930 802E80B0 44801000 */  mtc1      $zero, $f2
/* 109934 802E80B4 4600C021 */  cvt.d.s   $f0, $f24
/* 109938 802E80B8 46220000 */  add.d     $f0, $f0, $f2
.L802E80BC:
/* 10993C 802E80BC 46200020 */  cvt.s.d   $f0, $f0
/* 109940 802E80C0 080BA05A */  j         .L802E8168
/* 109944 802E80C4 E60000C4 */   swc1     $f0, 0xc4($s0)
.L802E80C8:
/* 109948 802E80C8 3C013F80 */  lui       $at, 0x3f80
/* 10994C 802E80CC 4481D000 */  mtc1      $at, $f26
/* 109950 802E80D0 C60200C4 */  lwc1      $f2, 0xc4($s0)
/* 109954 802E80D4 3C013E80 */  lui       $at, 0x3e80
/* 109958 802E80D8 44810000 */  mtc1      $at, $f0
/* 10995C 802E80DC 4480F000 */  mtc1      $zero, $f30
/* 109960 802E80E0 46001602 */  mul.s     $f24, $f2, $f0
/* 109964 802E80E4 080BA05A */  j         .L802E8168
/* 109968 802E80E8 00000000 */   nop
.L802E80EC:
/* 10996C 802E80EC C60200C4 */  lwc1      $f2, 0xc4($s0)
/* 109970 802E80F0 3C013F80 */  lui       $at, 0x3f80
/* 109974 802E80F4 44810000 */  mtc1      $at, $f0
/* 109978 802E80F8 00000000 */  nop
/* 10997C 802E80FC 46001080 */  add.s     $f2, $f2, $f0
/* 109980 802E8100 3C0141A0 */  lui       $at, 0x41a0
/* 109984 802E8104 44810000 */  mtc1      $at, $f0
/* 109988 802E8108 00000000 */  nop
/* 10998C 802E810C 4602003C */  c.lt.s    $f0, $f2
/* 109990 802E8110 00000000 */  nop
/* 109994 802E8114 45000002 */  bc1f      .L802E8120
/* 109998 802E8118 E60200C4 */   swc1     $f2, 0xc4($s0)
/* 10999C 802E811C E60000C4 */  swc1      $f0, 0xc4($s0)
.L802E8120:
/* 1099A0 802E8120 C60200C4 */  lwc1      $f2, 0xc4($s0)
/* 1099A4 802E8124 3C01428C */  lui       $at, 0x428c
/* 1099A8 802E8128 44812000 */  mtc1      $at, $f4
/* 1099AC 802E812C C60001E4 */  lwc1      $f0, 0x1e4($s0)
/* 1099B0 802E8130 46041083 */  div.s     $f2, $f2, $f4
/* 1099B4 802E8134 46020001 */  sub.s     $f0, $f0, $f2
/* 1099B8 802E8138 E60001E4 */  swc1      $f0, 0x1e4($s0)
/* 1099BC 802E813C 92220034 */  lbu       $v0, 0x34($s1)
/* 1099C0 802E8140 2442FFFB */  addiu     $v0, $v0, -5
/* 1099C4 802E8144 A2220034 */  sb        $v0, 0x34($s1)
/* 1099C8 802E8148 304200FF */  andi      $v0, $v0, 0xff
/* 1099CC 802E814C 2C420006 */  sltiu     $v0, $v0, 6
/* 1099D0 802E8150 10400005 */  beqz      $v0, .L802E8168
/* 1099D4 802E8154 00000000 */   nop
/* 1099D8 802E8158 92220010 */  lbu       $v0, 0x10($s1)
/* 1099DC 802E815C A2200034 */  sb        $zero, 0x34($s1)
/* 1099E0 802E8160 24420001 */  addiu     $v0, $v0, 1
/* 1099E4 802E8164 A2220010 */  sb        $v0, 0x10($s1)
.L802E8168:
/* 1099E8 802E8168 82220010 */  lb        $v0, 0x10($s1)
/* 1099EC 802E816C 28420002 */  slti      $v0, $v0, 2
/* 1099F0 802E8170 504000DB */  beql      $v0, $zero, .L802E84E0
/* 1099F4 802E8174 26310001 */   addiu    $s1, $s1, 1
/* 1099F8 802E8178 C6020304 */  lwc1      $f2, 0x304($s0)
/* 1099FC 802E817C 44800000 */  mtc1      $zero, $f0
/* 109A00 802E8180 00000000 */  nop
/* 109A04 802E8184 4602003E */  c.le.s    $f0, $f2
/* 109A08 802E8188 3C01802F */  lui       $at, %hi(D_802EB358)
/* 109A0C 802E818C D420B358 */  ldc1      $f0, %lo(D_802EB358)($at)
/* 109A10 802E8190 45000003 */  bc1f      .L802E81A0
/* 109A14 802E8194 460010A1 */   cvt.d.s  $f2, $f2
/* 109A18 802E8198 3C01802F */  lui       $at, %hi(D_802EB360)
/* 109A1C 802E819C D420B360 */  ldc1      $f0, %lo(D_802EB360)($at)
.L802E81A0:
/* 109A20 802E81A0 46201081 */  sub.d     $f2, $f2, $f0
/* 109A24 802E81A4 3C01802F */  lui       $at, %hi(D_802EB368)
/* 109A28 802E81A8 D424B368 */  ldc1      $f4, %lo(D_802EB368)($at)
/* 109A2C 802E81AC 462010A0 */  cvt.s.d   $f2, $f2
/* 109A30 802E81B0 46001021 */  cvt.d.s   $f0, $f2
/* 109A34 802E81B4 4624003C */  c.lt.d    $f0, $f4
/* 109A38 802E81B8 00000000 */  nop
/* 109A3C 802E81BC 45000006 */  bc1f      .L802E81D8
/* 109A40 802E81C0 E6020304 */   swc1     $f2, 0x304($s0)
/* 109A44 802E81C4 3C01C123 */  lui       $at, 0xc123
/* 109A48 802E81C8 34213333 */  ori       $at, $at, 0x3333
/* 109A4C 802E81CC 44810000 */  mtc1      $at, $f0
/* 109A50 802E81D0 00000000 */  nop
/* 109A54 802E81D4 E6000304 */  swc1      $f0, 0x304($s0)
.L802E81D8:
/* 109A58 802E81D8 C60001E4 */  lwc1      $f0, 0x1e4($s0)
/* 109A5C 802E81DC C6020304 */  lwc1      $f2, 0x304($s0)
/* 109A60 802E81E0 46020000 */  add.s     $f0, $f0, $f2
/* 109A64 802E81E4 E60001E4 */  swc1      $f0, 0x1e4($s0)
/* 109A68 802E81E8 92220034 */  lbu       $v0, 0x34($s1)
/* 109A6C 802E81EC 3C0143B4 */  lui       $at, 0x43b4
/* 109A70 802E81F0 44814000 */  mtc1      $at, $f8
/* 109A74 802E81F4 4482A000 */  mtc1      $v0, $f20
/* 109A78 802E81F8 00000000 */  nop
/* 109A7C 802E81FC 4680A520 */  cvt.s.w   $f20, $f20
/* 109A80 802E8200 4608A502 */  mul.s     $f20, $f20, $f8
/* 109A84 802E8204 00000000 */  nop
/* 109A88 802E8208 3C013B80 */  lui       $at, 0x3b80
/* 109A8C 802E820C 44814000 */  mtc1      $at, $f8
/* 109A90 802E8210 00000000 */  nop
/* 109A94 802E8214 4608A502 */  mul.s     $f20, $f20, $f8
/* 109A98 802E8218 00000000 */  nop
/* 109A9C 802E821C 3C0140C9 */  lui       $at, 0x40c9
/* 109AA0 802E8220 34210FD0 */  ori       $at, $at, 0xfd0
/* 109AA4 802E8224 44814000 */  mtc1      $at, $f8
/* 109AA8 802E8228 00000000 */  nop
/* 109AAC 802E822C 4608A002 */  mul.s     $f0, $f20, $f8
/* 109AB0 802E8230 00000000 */  nop
/* 109AB4 802E8234 3C0143B4 */  lui       $at, 0x43b4
/* 109AB8 802E8238 44814000 */  mtc1      $at, $f8
/* 109ABC 802E823C 00000000 */  nop
/* 109AC0 802E8240 46080583 */  div.s     $f22, $f0, $f8
/* 109AC4 802E8244 0C00A85B */  jal       sin_rad
/* 109AC8 802E8248 4600B306 */   mov.s    $f12, $f22
/* 109ACC 802E824C 4600D002 */  mul.s     $f0, $f26, $f0
/* 109AD0 802E8250 00000000 */  nop
/* 109AD4 802E8254 C6020154 */  lwc1      $f2, 0x154($s0)
/* 109AD8 802E8258 46001080 */  add.s     $f2, $f2, $f0
/* 109ADC 802E825C 4600B306 */  mov.s     $f12, $f22
/* 109AE0 802E8260 0C00A874 */  jal       cos_rad
/* 109AE4 802E8264 E6020154 */   swc1     $f2, 0x154($s0)
/* 109AE8 802E8268 4600D002 */  mul.s     $f0, $f26, $f0
/* 109AEC 802E826C 00000000 */  nop
/* 109AF0 802E8270 3C040004 */  lui       $a0, 4
/* 109AF4 802E8274 C6020274 */  lwc1      $f2, 0x274($s0)
/* 109AF8 802E8278 02C0282D */  daddu     $a1, $s6, $zero
/* 109AFC 802E827C 46001080 */  add.s     $f2, $f2, $f0
/* 109B00 802E8280 C6000154 */  lwc1      $f0, 0x154($s0)
/* 109B04 802E8284 02A0302D */  daddu     $a2, $s5, $zero
/* 109B08 802E8288 E6020274 */  swc1      $f2, 0x274($s0)
/* 109B0C 802E828C C60201E4 */  lwc1      $f2, 0x1e4($s0)
/* 109B10 802E8290 C6040274 */  lwc1      $f4, 0x274($s0)
/* 109B14 802E8294 0280382D */  daddu     $a3, $s4, $zero
/* 109B18 802E8298 E7A00020 */  swc1      $f0, 0x20($sp)
/* 109B1C 802E829C E7A20024 */  swc1      $f2, 0x24($sp)
/* 109B20 802E82A0 E7A40028 */  swc1      $f4, 0x28($sp)
/* 109B24 802E82A4 E7BA0010 */  swc1      $f26, 0x10($sp)
/* 109B28 802E82A8 E7B40014 */  swc1      $f20, 0x14($sp)
/* 109B2C 802E82AC E7BC0018 */  swc1      $f28, 0x18($sp)
/* 109B30 802E82B0 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* 109B34 802E82B4 E7BC001C */   swc1     $f28, 0x1c($sp)
/* 109B38 802E82B8 10400031 */  beqz      $v0, .L802E8380
/* 109B3C 802E82BC 3C040004 */   lui      $a0, 4
/* 109B40 802E82C0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 109B44 802E82C4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 109B48 802E82C8 C7A40028 */  lwc1      $f4, 0x28($sp)
/* 109B4C 802E82CC E6000154 */  swc1      $f0, 0x154($s0)
/* 109B50 802E82D0 E60201E4 */  swc1      $f2, 0x1e4($s0)
/* 109B54 802E82D4 E6040274 */  swc1      $f4, 0x274($s0)
/* 109B58 802E82D8 92220034 */  lbu       $v0, 0x34($s1)
/* 109B5C 802E82DC 3C0143B4 */  lui       $at, 0x43b4
/* 109B60 802E82E0 44814000 */  mtc1      $at, $f8
/* 109B64 802E82E4 24420080 */  addiu     $v0, $v0, 0x80
/* 109B68 802E82E8 A2220034 */  sb        $v0, 0x34($s1)
/* 109B6C 802E82EC 304200FF */  andi      $v0, $v0, 0xff
/* 109B70 802E82F0 44820000 */  mtc1      $v0, $f0
/* 109B74 802E82F4 00000000 */  nop
/* 109B78 802E82F8 46800020 */  cvt.s.w   $f0, $f0
/* 109B7C 802E82FC 46080002 */  mul.s     $f0, $f0, $f8
/* 109B80 802E8300 00000000 */  nop
/* 109B84 802E8304 3C013B80 */  lui       $at, 0x3b80
/* 109B88 802E8308 44814000 */  mtc1      $at, $f8
/* 109B8C 802E830C 00000000 */  nop
/* 109B90 802E8310 46080002 */  mul.s     $f0, $f0, $f8
/* 109B94 802E8314 00000000 */  nop
/* 109B98 802E8318 3C0140C9 */  lui       $at, 0x40c9
/* 109B9C 802E831C 34210FD0 */  ori       $at, $at, 0xfd0
/* 109BA0 802E8320 44814000 */  mtc1      $at, $f8
/* 109BA4 802E8324 00000000 */  nop
/* 109BA8 802E8328 46080002 */  mul.s     $f0, $f0, $f8
/* 109BAC 802E832C 00000000 */  nop
/* 109BB0 802E8330 3C0143B4 */  lui       $at, 0x43b4
/* 109BB4 802E8334 44814000 */  mtc1      $at, $f8
/* 109BB8 802E8338 00000000 */  nop
/* 109BBC 802E833C 46080583 */  div.s     $f22, $f0, $f8
/* 109BC0 802E8340 0C00A85B */  jal       sin_rad
/* 109BC4 802E8344 4600B306 */   mov.s    $f12, $f22
/* 109BC8 802E8348 461C0002 */  mul.s     $f0, $f0, $f28
/* 109BCC 802E834C 00000000 */  nop
/* 109BD0 802E8350 C6020154 */  lwc1      $f2, 0x154($s0)
/* 109BD4 802E8354 46001080 */  add.s     $f2, $f2, $f0
/* 109BD8 802E8358 4600B306 */  mov.s     $f12, $f22
/* 109BDC 802E835C 0C00A874 */  jal       cos_rad
/* 109BE0 802E8360 E6020154 */   swc1     $f2, 0x154($s0)
/* 109BE4 802E8364 461C0002 */  mul.s     $f0, $f0, $f28
/* 109BE8 802E8368 00000000 */  nop
/* 109BEC 802E836C C6020274 */  lwc1      $f2, 0x274($s0)
/* 109BF0 802E8370 46001080 */  add.s     $f2, $f2, $f0
/* 109BF4 802E8374 4600E686 */  mov.s     $f26, $f28
/* 109BF8 802E8378 E6020274 */  swc1      $f2, 0x274($s0)
/* 109BFC 802E837C 3C040004 */  lui       $a0, 4
.L802E8380:
/* 109C00 802E8380 02C0282D */  daddu     $a1, $s6, $zero
/* 109C04 802E8384 02A0302D */  daddu     $a2, $s5, $zero
/* 109C08 802E8388 0280382D */  daddu     $a3, $s4, $zero
/* 109C0C 802E838C 27A2002C */  addiu     $v0, $sp, 0x2c
/* 109C10 802E8390 C60201E4 */  lwc1      $f2, 0x1e4($s0)
/* 109C14 802E8394 C6060154 */  lwc1      $f6, 0x154($s0)
/* 109C18 802E8398 461C1080 */  add.s     $f2, $f2, $f28
/* 109C1C 802E839C C6000304 */  lwc1      $f0, 0x304($s0)
/* 109C20 802E83A0 C6040274 */  lwc1      $f4, 0x274($s0)
/* 109C24 802E83A4 46000005 */  abs.s     $f0, $f0
/* 109C28 802E83A8 E7A60020 */  swc1      $f6, 0x20($sp)
/* 109C2C 802E83AC E7A40028 */  swc1      $f4, 0x28($sp)
/* 109C30 802E83B0 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 109C34 802E83B4 E7A20024 */  swc1      $f2, 0x24($sp)
/* 109C38 802E83B8 0C0372DF */  jal       npc_raycast_down_sides
/* 109C3C 802E83BC AFA20010 */   sw       $v0, 0x10($sp)
/* 109C40 802E83C0 1440000B */  bnez      $v0, .L802E83F0
/* 109C44 802E83C4 00000000 */   nop
/* 109C48 802E83C8 C640000C */  lwc1      $f0, 0xc($s2)
/* 109C4C 802E83CC 3C014348 */  lui       $at, 0x4348
/* 109C50 802E83D0 44811000 */  mtc1      $at, $f2
/* 109C54 802E83D4 00000000 */  nop
/* 109C58 802E83D8 46020001 */  sub.s     $f0, $f0, $f2
/* 109C5C 802E83DC C7A20024 */  lwc1      $f2, 0x24($sp)
/* 109C60 802E83E0 4600103C */  c.lt.s    $f2, $f0
/* 109C64 802E83E4 00000000 */  nop
/* 109C68 802E83E8 45000010 */  bc1f      .L802E842C
/* 109C6C 802E83EC 00000000 */   nop
.L802E83F0:
/* 109C70 802E83F0 92220010 */  lbu       $v0, 0x10($s1)
/* 109C74 802E83F4 24420001 */  addiu     $v0, $v0, 1
/* 109C78 802E83F8 A2220010 */  sb        $v0, 0x10($s1)
/* 109C7C 802E83FC C6000304 */  lwc1      $f0, 0x304($s0)
/* 109C80 802E8400 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 109C84 802E8404 46000005 */  abs.s     $f0, $f0
/* 109C88 802E8408 46001080 */  add.s     $f2, $f2, $f0
/* 109C8C 802E840C E61E0304 */  swc1      $f30, 0x304($s0)
/* 109C90 802E8410 E60201E4 */  swc1      $f2, 0x1e4($s0)
/* 109C94 802E8414 82230010 */  lb        $v1, 0x10($s1)
/* 109C98 802E8418 24020002 */  addiu     $v0, $zero, 2
/* 109C9C 802E841C 14620003 */  bne       $v1, $v0, .L802E842C
/* 109CA0 802E8420 240200FE */   addiu    $v0, $zero, 0xfe
/* 109CA4 802E8424 A2220034 */  sb        $v0, 0x34($s1)
/* 109CA8 802E8428 AE0000C4 */  sw        $zero, 0xc4($s0)
.L802E842C:
/* 109CAC 802E842C 92220058 */  lbu       $v0, 0x58($s1)
/* 109CB0 802E8430 44820000 */  mtc1      $v0, $f0
/* 109CB4 802E8434 00000000 */  nop
/* 109CB8 802E8438 46800020 */  cvt.s.w   $f0, $f0
/* 109CBC 802E843C 46180000 */  add.s     $f0, $f0, $f24
/* 109CC0 802E8440 3C014F00 */  lui       $at, 0x4f00
/* 109CC4 802E8444 44814000 */  mtc1      $at, $f8
/* 109CC8 802E8448 00000000 */  nop
/* 109CCC 802E844C 4600403E */  c.le.s    $f8, $f0
/* 109CD0 802E8450 00000000 */  nop
/* 109CD4 802E8454 45010005 */  bc1t      .L802E846C
/* 109CD8 802E8458 26230058 */   addiu    $v1, $s1, 0x58
/* 109CDC 802E845C 4600020D */  trunc.w.s $f8, $f0
/* 109CE0 802E8460 44024000 */  mfc1      $v0, $f8
/* 109CE4 802E8464 080BA121 */  j         .L802E8484
/* 109CE8 802E8468 A0620000 */   sb       $v0, ($v1)
.L802E846C:
/* 109CEC 802E846C 46080001 */  sub.s     $f0, $f0, $f8
/* 109CF0 802E8470 4600020D */  trunc.w.s $f8, $f0
/* 109CF4 802E8474 44024000 */  mfc1      $v0, $f8
/* 109CF8 802E8478 00000000 */  nop
/* 109CFC 802E847C 00571025 */  or        $v0, $v0, $s7
/* 109D00 802E8480 A0620000 */  sb        $v0, ($v1)
.L802E8484:
/* 109D04 802E8484 9222007C */  lbu       $v0, 0x7c($s1)
/* 109D08 802E8488 44820000 */  mtc1      $v0, $f0
/* 109D0C 802E848C 00000000 */  nop
/* 109D10 802E8490 46800020 */  cvt.s.w   $f0, $f0
/* 109D14 802E8494 46180001 */  sub.s     $f0, $f0, $f24
/* 109D18 802E8498 3C014F00 */  lui       $at, 0x4f00
/* 109D1C 802E849C 44814000 */  mtc1      $at, $f8
/* 109D20 802E84A0 00000000 */  nop
/* 109D24 802E84A4 4600403E */  c.le.s    $f8, $f0
/* 109D28 802E84A8 00000000 */  nop
/* 109D2C 802E84AC 45010005 */  bc1t      .L802E84C4
/* 109D30 802E84B0 2623007C */   addiu    $v1, $s1, 0x7c
/* 109D34 802E84B4 4600020D */  trunc.w.s $f8, $f0
/* 109D38 802E84B8 44024000 */  mfc1      $v0, $f8
/* 109D3C 802E84BC 080BA137 */  j         .L802E84DC
/* 109D40 802E84C0 A0620000 */   sb       $v0, ($v1)
.L802E84C4:
/* 109D44 802E84C4 46080001 */  sub.s     $f0, $f0, $f8
/* 109D48 802E84C8 4600020D */  trunc.w.s $f8, $f0
/* 109D4C 802E84CC 44024000 */  mfc1      $v0, $f8
/* 109D50 802E84D0 00000000 */  nop
/* 109D54 802E84D4 00571025 */  or        $v0, $v0, $s7
/* 109D58 802E84D8 A0620000 */  sb        $v0, ($v1)
.L802E84DC:
/* 109D5C 802E84DC 26310001 */  addiu     $s1, $s1, 1
.L802E84E0:
/* 109D60 802E84E0 26420023 */  addiu     $v0, $s2, 0x23
/* 109D64 802E84E4 0222102A */  slt       $v0, $s1, $v0
/* 109D68 802E84E8 1440FECC */  bnez      $v0, .L802E801C
/* 109D6C 802E84EC 26100004 */   addiu    $s0, $s0, 4
/* 109D70 802E84F0 2A620023 */  slti      $v0, $s3, 0x23
/* 109D74 802E84F4 14400003 */  bnez      $v0, .L802E8504
/* 109D78 802E84F8 00000000 */   nop
/* 109D7C 802E84FC 0C043F5A */  jal       exec_entity_commandlist
/* 109D80 802E8500 03C0202D */   daddu    $a0, $fp, $zero
.L802E8504:
/* 109D84 802E8504 8FBF0054 */  lw        $ra, 0x54($sp)
/* 109D88 802E8508 8FBE0050 */  lw        $fp, 0x50($sp)
/* 109D8C 802E850C 8FB7004C */  lw        $s7, 0x4c($sp)
/* 109D90 802E8510 8FB60048 */  lw        $s6, 0x48($sp)
/* 109D94 802E8514 8FB50044 */  lw        $s5, 0x44($sp)
/* 109D98 802E8518 8FB40040 */  lw        $s4, 0x40($sp)
/* 109D9C 802E851C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 109DA0 802E8520 8FB20038 */  lw        $s2, 0x38($sp)
/* 109DA4 802E8524 8FB10034 */  lw        $s1, 0x34($sp)
/* 109DA8 802E8528 8FB00030 */  lw        $s0, 0x30($sp)
/* 109DAC 802E852C D7BE0080 */  ldc1      $f30, 0x80($sp)
/* 109DB0 802E8530 D7BC0078 */  ldc1      $f28, 0x78($sp)
/* 109DB4 802E8534 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* 109DB8 802E8538 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 109DBC 802E853C D7B60060 */  ldc1      $f22, 0x60($sp)
/* 109DC0 802E8540 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 109DC4 802E8544 03E00008 */  jr        $ra
/* 109DC8 802E8548 27BD0088 */   addiu    $sp, $sp, 0x88

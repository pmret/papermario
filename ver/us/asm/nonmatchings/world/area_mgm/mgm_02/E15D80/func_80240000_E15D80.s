.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802484E0_E1E260
.double 59.0

.section .text

glabel func_80240000_E15D80
/* E15D80 80240000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* E15D84 80240004 0000202D */  daddu     $a0, $zero, $zero
/* E15D88 80240008 AFBF006C */  sw        $ra, 0x6c($sp)
/* E15D8C 8024000C AFB60068 */  sw        $s6, 0x68($sp)
/* E15D90 80240010 AFB50064 */  sw        $s5, 0x64($sp)
/* E15D94 80240014 AFB40060 */  sw        $s4, 0x60($sp)
/* E15D98 80240018 AFB3005C */  sw        $s3, 0x5c($sp)
/* E15D9C 8024001C AFB20058 */  sw        $s2, 0x58($sp)
/* E15DA0 80240020 AFB10054 */  sw        $s1, 0x54($sp)
/* E15DA4 80240024 0C00FB3A */  jal       get_enemy
/* E15DA8 80240028 AFB00050 */   sw       $s0, 0x50($sp)
/* E15DAC 8024002C 0040882D */  daddu     $s1, $v0, $zero
/* E15DB0 80240030 8E32006C */  lw        $s2, 0x6c($s1)
/* E15DB4 80240034 8E420028 */  lw        $v0, 0x28($s2)
/* E15DB8 80240038 30420004 */  andi      $v0, $v0, 4
/* E15DBC 8024003C 1040002A */  beqz      $v0, .L802400E8
/* E15DC0 80240040 2405005A */   addiu    $a1, $zero, 0x5a
/* E15DC4 80240044 8E50000C */  lw        $s0, 0xc($s2)
/* E15DC8 80240048 00A0302D */  daddu     $a2, $a1, $zero
/* E15DCC 8024004C 0C051261 */  jal       set_hud_element_render_pos
/* E15DD0 80240050 0200202D */   daddu    $a0, $s0, $zero
/* E15DD4 80240054 0C0511EA */  jal       draw_hud_element_clipped
/* E15DD8 80240058 0200202D */   daddu    $a0, $s0, $zero
/* E15DDC 8024005C 2405005A */  addiu     $a1, $zero, 0x5a
/* E15DE0 80240060 8E500010 */  lw        $s0, 0x10($s2)
/* E15DE4 80240064 24060078 */  addiu     $a2, $zero, 0x78
/* E15DE8 80240068 0C051261 */  jal       set_hud_element_render_pos
/* E15DEC 8024006C 0200202D */   daddu    $a0, $s0, $zero
/* E15DF0 80240070 0C0511EA */  jal       draw_hud_element_clipped
/* E15DF4 80240074 0200202D */   daddu    $a0, $s0, $zero
/* E15DF8 80240078 2404003E */  addiu     $a0, $zero, 0x3e
/* E15DFC 8024007C 24050074 */  addiu     $a1, $zero, 0x74
/* E15E00 80240080 24070079 */  addiu     $a3, $zero, 0x79
/* E15E04 80240084 C6400024 */  lwc1      $f0, 0x24($s2)
/* E15E08 80240088 46800020 */  cvt.s.w   $f0, $f0
/* E15E0C 8024008C 46000021 */  cvt.d.s   $f0, $f0
/* E15E10 80240090 3C014028 */  lui       $at, 0x4028
/* E15E14 80240094 44811800 */  mtc1      $at, $f3
/* E15E18 80240098 44801000 */  mtc1      $zero, $f2
/* E15E1C 8024009C 3C018025 */  lui       $at, %hi(D_802484E0_E1E260)
/* E15E20 802400A0 D42484E0 */  ldc1      $f4, %lo(D_802484E0_E1E260)($at)
/* E15E24 802400A4 46220003 */  div.d     $f0, $f0, $f2
/* E15E28 802400A8 46240002 */  mul.d     $f0, $f0, $f4
/* E15E2C 802400AC 00000000 */  nop
/* E15E30 802400B0 240200E4 */  addiu     $v0, $zero, 0xe4
/* E15E34 802400B4 AFA20014 */  sw        $v0, 0x14($sp)
/* E15E38 802400B8 24020086 */  addiu     $v0, $zero, 0x86
/* E15E3C 802400BC AFA20018 */  sw        $v0, 0x18($sp)
/* E15E40 802400C0 240200FF */  addiu     $v0, $zero, 0xff
/* E15E44 802400C4 AFA00010 */  sw        $zero, 0x10($sp)
/* E15E48 802400C8 AFA2001C */  sw        $v0, 0x1c($sp)
/* E15E4C 802400CC 4620018D */  trunc.w.d $f6, $f0
/* E15E50 802400D0 44063000 */  mfc1      $a2, $f6
/* E15E54 802400D4 00000000 */  nop
/* E15E58 802400D8 00C43021 */  addu      $a2, $a2, $a0
/* E15E5C 802400DC 00063400 */  sll       $a2, $a2, 0x10
/* E15E60 802400E0 0C00AAB1 */  jal       startup_draw_prim_rect_COPY
/* E15E64 802400E4 00063403 */   sra      $a2, $a2, 0x10
.L802400E8:
/* E15E68 802400E8 8E220078 */  lw        $v0, 0x78($s1)
/* E15E6C 802400EC 10400003 */  beqz      $v0, .L802400FC
/* E15E70 802400F0 28420004 */   slti     $v0, $v0, 4
/* E15E74 802400F4 1440000B */  bnez      $v0, .L80240124
/* E15E78 802400F8 00000000 */   nop
.L802400FC:
/* E15E7C 802400FC 8E430014 */  lw        $v1, 0x14($s2)
/* E15E80 80240100 2862FFB1 */  slti      $v0, $v1, -0x4f
/* E15E84 80240104 14400010 */  bnez      $v0, .L80240148
/* E15E88 80240108 2462FFF6 */   addiu    $v0, $v1, -0xa
/* E15E8C 8024010C AE420014 */  sw        $v0, 0x14($s2)
/* E15E90 80240110 2842FFB0 */  slti      $v0, $v0, -0x50
/* E15E94 80240114 1040000C */  beqz      $v0, .L80240148
/* E15E98 80240118 2402FFB0 */   addiu    $v0, $zero, -0x50
/* E15E9C 8024011C 08090052 */  j         .L80240148
/* E15EA0 80240120 AE420014 */   sw       $v0, 0x14($s2)
.L80240124:
/* E15EA4 80240124 8E430014 */  lw        $v1, 0x14($s2)
/* E15EA8 80240128 28620017 */  slti      $v0, $v1, 0x17
/* E15EAC 8024012C 10400006 */  beqz      $v0, .L80240148
/* E15EB0 80240130 2462000A */   addiu    $v0, $v1, 0xa
/* E15EB4 80240134 AE420014 */  sw        $v0, 0x14($s2)
/* E15EB8 80240138 28420018 */  slti      $v0, $v0, 0x18
/* E15EBC 8024013C 14400002 */  bnez      $v0, .L80240148
/* E15EC0 80240140 24020017 */   addiu    $v0, $zero, 0x17
/* E15EC4 80240144 AE420014 */  sw        $v0, 0x14($s2)
.L80240148:
/* E15EC8 80240148 8E220078 */  lw        $v0, 0x78($s1)
/* E15ECC 8024014C 1440000B */  bnez      $v0, .L8024017C
/* E15ED0 80240150 00000000 */   nop
/* E15ED4 80240154 8E430018 */  lw        $v1, 0x18($s2)
/* E15ED8 80240158 28620140 */  slti      $v0, $v1, 0x140
/* E15EDC 8024015C 10400011 */  beqz      $v0, .L802401A4
/* E15EE0 80240160 2462000A */   addiu    $v0, $v1, 0xa
/* E15EE4 80240164 AE420018 */  sw        $v0, 0x18($s2)
/* E15EE8 80240168 28420141 */  slti      $v0, $v0, 0x141
/* E15EEC 8024016C 1440000E */  bnez      $v0, .L802401A8
/* E15EF0 80240170 0000202D */   daddu    $a0, $zero, $zero
/* E15EF4 80240174 08090068 */  j         .L802401A0
/* E15EF8 80240178 24020140 */   addiu    $v0, $zero, 0x140
.L8024017C:
/* E15EFC 8024017C 8E430018 */  lw        $v1, 0x18($s2)
/* E15F00 80240180 286200E2 */  slti      $v0, $v1, 0xe2
/* E15F04 80240184 14400008 */  bnez      $v0, .L802401A8
/* E15F08 80240188 0000202D */   daddu    $a0, $zero, $zero
/* E15F0C 8024018C 2462FFF6 */  addiu     $v0, $v1, -0xa
/* E15F10 80240190 AE420018 */  sw        $v0, 0x18($s2)
/* E15F14 80240194 284200E1 */  slti      $v0, $v0, 0xe1
/* E15F18 80240198 10400003 */  beqz      $v0, .L802401A8
/* E15F1C 8024019C 240200E1 */   addiu    $v0, $zero, 0xe1
.L802401A0:
/* E15F20 802401A0 AE420018 */  sw        $v0, 0x18($s2)
.L802401A4:
/* E15F24 802401A4 0000202D */  daddu     $a0, $zero, $zero
.L802401A8:
/* E15F28 802401A8 24050009 */  addiu     $a1, $zero, 9
/* E15F2C 802401AC 24020050 */  addiu     $v0, $zero, 0x50
/* E15F30 802401B0 AFA20014 */  sw        $v0, 0x14($sp)
/* E15F34 802401B4 24020026 */  addiu     $v0, $zero, 0x26
/* E15F38 802401B8 241100B4 */  addiu     $s1, $zero, 0xb4
/* E15F3C 802401BC 24160140 */  addiu     $s6, $zero, 0x140
/* E15F40 802401C0 241500F0 */  addiu     $s5, $zero, 0xf0
/* E15F44 802401C4 AFA00010 */  sw        $zero, 0x10($sp)
/* E15F48 802401C8 AFA20018 */  sw        $v0, 0x18($sp)
/* E15F4C 802401CC AFB1001C */  sw        $s1, 0x1c($sp)
/* E15F50 802401D0 AFA00020 */  sw        $zero, 0x20($sp)
/* E15F54 802401D4 AFA00024 */  sw        $zero, 0x24($sp)
/* E15F58 802401D8 AFA00028 */  sw        $zero, 0x28($sp)
/* E15F5C 802401DC AFA0002C */  sw        $zero, 0x2c($sp)
/* E15F60 802401E0 AFA00030 */  sw        $zero, 0x30($sp)
/* E15F64 802401E4 AFA00034 */  sw        $zero, 0x34($sp)
/* E15F68 802401E8 AFA00038 */  sw        $zero, 0x38($sp)
/* E15F6C 802401EC AFA0003C */  sw        $zero, 0x3c($sp)
/* E15F70 802401F0 AFA00040 */  sw        $zero, 0x40($sp)
/* E15F74 802401F4 AFB60044 */  sw        $s6, 0x44($sp)
/* E15F78 802401F8 AFB50048 */  sw        $s5, 0x48($sp)
/* E15F7C 802401FC AFA0004C */  sw        $zero, 0x4c($sp)
/* E15F80 80240200 8E460014 */  lw        $a2, 0x14($s2)
/* E15F84 80240204 0C03D4B8 */  jal       draw_box
/* E15F88 80240208 24070017 */   addiu    $a3, $zero, 0x17
/* E15F8C 8024020C 3C040008 */  lui       $a0, 8
/* E15F90 80240210 34840047 */  ori       $a0, $a0, 0x47
/* E15F94 80240214 2406001C */  addiu     $a2, $zero, 0x1c
/* E15F98 80240218 8E450014 */  lw        $a1, 0x14($s2)
/* E15F9C 8024021C 240700FF */  addiu     $a3, $zero, 0xff
/* E15FA0 80240220 AFA00010 */  sw        $zero, 0x10($sp)
/* E15FA4 80240224 AFA00014 */  sw        $zero, 0x14($sp)
/* E15FA8 80240228 0C04993B */  jal       draw_string
/* E15FAC 8024022C 24A5002A */   addiu    $a1, $a1, 0x2a
/* E15FB0 80240230 2406002B */  addiu     $a2, $zero, 0x2b
/* E15FB4 80240234 24070001 */  addiu     $a3, $zero, 1
/* E15FB8 80240238 241300FF */  addiu     $s3, $zero, 0xff
/* E15FBC 8024023C 24140003 */  addiu     $s4, $zero, 3
/* E15FC0 80240240 8E440004 */  lw        $a0, 4($s2)
/* E15FC4 80240244 8E450014 */  lw        $a1, 0x14($s2)
/* E15FC8 80240248 2410000A */  addiu     $s0, $zero, 0xa
/* E15FCC 8024024C AFA00010 */  sw        $zero, 0x10($sp)
/* E15FD0 80240250 AFB30014 */  sw        $s3, 0x14($sp)
/* E15FD4 80240254 AFB40018 */  sw        $s4, 0x18($sp)
/* E15FD8 80240258 02042023 */  subu      $a0, $s0, $a0
/* E15FDC 8024025C 0C049DA7 */  jal       draw_number
/* E15FE0 80240260 24A50041 */   addiu    $a1, $a1, 0x41
/* E15FE4 80240264 3C048025 */  lui       $a0, %hi(D_802482A0_E1E020)
/* E15FE8 80240268 248482A0 */  addiu     $a0, $a0, %lo(D_802482A0_E1E020)
/* E15FEC 8024026C 24050020 */  addiu     $a1, $zero, 0x20
/* E15FF0 80240270 00A0302D */  daddu     $a2, $a1, $zero
/* E15FF4 80240274 24070002 */  addiu     $a3, $zero, 2
/* E15FF8 80240278 3C028025 */  lui       $v0, %hi(D_802484A0_E1E220)
/* E15FFC 8024027C 244284A0 */  addiu     $v0, $v0, %lo(D_802484A0_E1E220)
/* E16000 80240280 AFA00010 */  sw        $zero, 0x10($sp)
/* E16004 80240284 AFA20014 */  sw        $v0, 0x14($sp)
/* E16008 80240288 96430016 */  lhu       $v1, 0x16($s2)
/* E1600C 8024028C 2402001A */  addiu     $v0, $zero, 0x1a
/* E16010 80240290 AFB00020 */  sw        $s0, 0x20($sp)
/* E16014 80240294 24100014 */  addiu     $s0, $zero, 0x14
/* E16018 80240298 AFA2001C */  sw        $v0, 0x1c($sp)
/* E1601C 8024029C 2402012C */  addiu     $v0, $zero, 0x12c
/* E16020 802402A0 AFA20028 */  sw        $v0, 0x28($sp)
/* E16024 802402A4 240200C8 */  addiu     $v0, $zero, 0xc8
/* E16028 802402A8 AFB00024 */  sw        $s0, 0x24($sp)
/* E1602C 802402AC AFA2002C */  sw        $v0, 0x2c($sp)
/* E16030 802402B0 AFB30030 */  sw        $s3, 0x30($sp)
/* E16034 802402B4 24630005 */  addiu     $v1, $v1, 5
/* E16038 802402B8 00031C00 */  sll       $v1, $v1, 0x10
/* E1603C 802402BC 00031C03 */  sra       $v1, $v1, 0x10
/* E16040 802402C0 0C04BA68 */  jal       draw_ci_image_with_clipping
/* E16044 802402C4 AFA30018 */   sw       $v1, 0x18($sp)
/* E16048 802402C8 8E460008 */  lw        $a2, 8($s2)
/* E1604C 802402CC 28C20385 */  slti      $v0, $a2, 0x385
/* E16050 802402D0 50400001 */  beql      $v0, $zero, .L802402D8
/* E16054 802402D4 24060384 */   addiu    $a2, $zero, 0x384
.L802402D8:
/* E16058 802402D8 3C038888 */  lui       $v1, 0x8888
/* E1605C 802402DC 34638889 */  ori       $v1, $v1, 0x8889
/* E16060 802402E0 0000202D */  daddu     $a0, $zero, $zero
/* E16064 802402E4 2405000B */  addiu     $a1, $zero, 0xb
/* E16068 802402E8 2402003C */  addiu     $v0, $zero, 0x3c
/* E1606C 802402EC AFA20014 */  sw        $v0, 0x14($sp)
/* E16070 802402F0 000617C3 */  sra       $v0, $a2, 0x1f
/* E16074 802402F4 3C014024 */  lui       $at, 0x4024
/* E16078 802402F8 44811800 */  mtc1      $at, $f3
/* E1607C 802402FC 44801000 */  mtc1      $zero, $f2
/* E16080 80240300 00C30018 */  mult      $a2, $v1
/* E16084 80240304 AFA00010 */  sw        $zero, 0x10($sp)
/* E16088 80240308 AFB00018 */  sw        $s0, 0x18($sp)
/* E1608C 8024030C AFB1001C */  sw        $s1, 0x1c($sp)
/* E16090 80240310 AFA00020 */  sw        $zero, 0x20($sp)
/* E16094 80240314 AFA00024 */  sw        $zero, 0x24($sp)
/* E16098 80240318 AFA00028 */  sw        $zero, 0x28($sp)
/* E1609C 8024031C AFA0002C */  sw        $zero, 0x2c($sp)
/* E160A0 80240320 AFA00030 */  sw        $zero, 0x30($sp)
/* E160A4 80240324 AFA00034 */  sw        $zero, 0x34($sp)
/* E160A8 80240328 AFA00038 */  sw        $zero, 0x38($sp)
/* E160AC 8024032C 00004010 */  mfhi      $t0
/* E160B0 80240330 01068021 */  addu      $s0, $t0, $a2
/* E160B4 80240334 00108103 */  sra       $s0, $s0, 4
/* E160B8 80240338 02028023 */  subu      $s0, $s0, $v0
/* E160BC 8024033C 00101100 */  sll       $v0, $s0, 4
/* E160C0 80240340 00501023 */  subu      $v0, $v0, $s0
/* E160C4 80240344 00021040 */  sll       $v0, $v0, 1
/* E160C8 80240348 00C21023 */  subu      $v0, $a2, $v0
/* E160CC 8024034C 44820000 */  mtc1      $v0, $f0
/* E160D0 80240350 00000000 */  nop
/* E160D4 80240354 46800020 */  cvt.s.w   $f0, $f0
/* E160D8 80240358 46000021 */  cvt.d.s   $f0, $f0
/* E160DC 8024035C 46220002 */  mul.d     $f0, $f0, $f2
/* E160E0 80240360 00000000 */  nop
/* E160E4 80240364 AFA0003C */  sw        $zero, 0x3c($sp)
/* E160E8 80240368 AFA00040 */  sw        $zero, 0x40($sp)
/* E160EC 8024036C AFB60044 */  sw        $s6, 0x44($sp)
/* E160F0 80240370 AFB50048 */  sw        $s5, 0x48($sp)
/* E160F4 80240374 AFA0004C */  sw        $zero, 0x4c($sp)
/* E160F8 80240378 3C01403E */  lui       $at, 0x403e
/* E160FC 8024037C 44811800 */  mtc1      $at, $f3
/* E16100 80240380 44801000 */  mtc1      $zero, $f2
/* E16104 80240384 8E460018 */  lw        $a2, 0x18($s2)
/* E16108 80240388 46220003 */  div.d     $f0, $f0, $f2
/* E1610C 8024038C 4620018D */  trunc.w.d $f6, $f0
/* E16110 80240390 44113000 */  mfc1      $s1, $f6
/* E16114 80240394 0C03D4B8 */  jal       draw_box
/* E16118 80240398 2407001B */   addiu    $a3, $zero, 0x1b
/* E1611C 8024039C 0200202D */  daddu     $a0, $s0, $zero
/* E16120 802403A0 2406001F */  addiu     $a2, $zero, 0x1f
/* E16124 802403A4 8E450018 */  lw        $a1, 0x18($s2)
/* E16128 802403A8 24070001 */  addiu     $a3, $zero, 1
/* E1612C 802403AC AFA00010 */  sw        $zero, 0x10($sp)
/* E16130 802403B0 AFB30014 */  sw        $s3, 0x14($sp)
/* E16134 802403B4 AFB40018 */  sw        $s4, 0x18($sp)
/* E16138 802403B8 0C049DA7 */  jal       draw_number
/* E1613C 802403BC 24A5001D */   addiu    $a1, $a1, 0x1d
/* E16140 802403C0 0220202D */  daddu     $a0, $s1, $zero
/* E16144 802403C4 2406001F */  addiu     $a2, $zero, 0x1f
/* E16148 802403C8 8E450018 */  lw        $a1, 0x18($s2)
/* E1614C 802403CC 24070001 */  addiu     $a3, $zero, 1
/* E16150 802403D0 AFA00010 */  sw        $zero, 0x10($sp)
/* E16154 802403D4 AFB30014 */  sw        $s3, 0x14($sp)
/* E16158 802403D8 AFA00018 */  sw        $zero, 0x18($sp)
/* E1615C 802403DC 0C049DA7 */  jal       draw_number
/* E16160 802403E0 24A50028 */   addiu    $a1, $a1, 0x28
/* E16164 802403E4 3C040008 */  lui       $a0, 8
/* E16168 802403E8 34840024 */  ori       $a0, $a0, 0x24
/* E1616C 802403EC 2406001D */  addiu     $a2, $zero, 0x1d
/* E16170 802403F0 8E450018 */  lw        $a1, 0x18($s2)
/* E16174 802403F4 240700FF */  addiu     $a3, $zero, 0xff
/* E16178 802403F8 AFA00010 */  sw        $zero, 0x10($sp)
/* E1617C 802403FC AFA00014 */  sw        $zero, 0x14($sp)
/* E16180 80240400 0C04993B */  jal       draw_string
/* E16184 80240404 24A5001E */   addiu    $a1, $a1, 0x1e
/* E16188 80240408 8FBF006C */  lw        $ra, 0x6c($sp)
/* E1618C 8024040C 8FB60068 */  lw        $s6, 0x68($sp)
/* E16190 80240410 8FB50064 */  lw        $s5, 0x64($sp)
/* E16194 80240414 8FB40060 */  lw        $s4, 0x60($sp)
/* E16198 80240418 8FB3005C */  lw        $s3, 0x5c($sp)
/* E1619C 8024041C 8FB20058 */  lw        $s2, 0x58($sp)
/* E161A0 80240420 8FB10054 */  lw        $s1, 0x54($sp)
/* E161A4 80240424 8FB00050 */  lw        $s0, 0x50($sp)
/* E161A8 80240428 03E00008 */  jr        $ra
/* E161AC 8024042C 27BD0070 */   addiu    $sp, $sp, 0x70

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243080_C713B0
.double 0.2, 5.4309136021427385e+209

.section .text

glabel func_80240000_C6E330
/* C6E330 80240000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C6E334 80240004 AFB1002C */  sw        $s1, 0x2c($sp)
/* C6E338 80240008 0080882D */  daddu     $s1, $a0, $zero
/* C6E33C 8024000C AFB20030 */  sw        $s2, 0x30($sp)
/* C6E340 80240010 00A0902D */  daddu     $s2, $a1, $zero
/* C6E344 80240014 AFBF003C */  sw        $ra, 0x3c($sp)
/* C6E348 80240018 AFB40038 */  sw        $s4, 0x38($sp)
/* C6E34C 8024001C AFB30034 */  sw        $s3, 0x34($sp)
/* C6E350 80240020 AFB00028 */  sw        $s0, 0x28($sp)
/* C6E354 80240024 F7B60048 */  sdc1      $f22, 0x48($sp)
/* C6E358 80240028 F7B40040 */  sdc1      $f20, 0x40($sp)
/* C6E35C 8024002C 8E30000C */  lw        $s0, 0xc($s1)
/* C6E360 80240030 8E050000 */  lw        $a1, ($s0)
/* C6E364 80240034 0C0B1EAF */  jal       get_variable
/* C6E368 80240038 26100004 */   addiu    $s0, $s0, 4
/* C6E36C 8024003C 0220202D */  daddu     $a0, $s1, $zero
/* C6E370 80240040 8E050000 */  lw        $a1, ($s0)
/* C6E374 80240044 0C0B1EAF */  jal       get_variable
/* C6E378 80240048 0040A02D */   daddu    $s4, $v0, $zero
/* C6E37C 8024004C 12400022 */  beqz      $s2, .L802400D8
/* C6E380 80240050 0040982D */   daddu    $s3, $v0, $zero
/* C6E384 80240054 12600013 */  beqz      $s3, .L802400A4
/* C6E388 80240058 26710002 */   addiu    $s1, $s3, 2
/* C6E38C 8024005C 96620000 */  lhu       $v0, ($s3)
/* C6E390 80240060 1040001D */  beqz      $v0, .L802400D8
/* C6E394 80240064 0000802D */   daddu    $s0, $zero, $zero
.L80240068:
/* C6E398 80240068 96240000 */  lhu       $a0, ($s1)
/* C6E39C 8024006C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* C6E3A0 80240070 26100001 */   addiu    $s0, $s0, 1
/* C6E3A4 80240074 0C046B4C */  jal       get_model_from_list_index
/* C6E3A8 80240078 0040202D */   daddu    $a0, $v0, $zero
/* C6E3AC 8024007C 0040202D */  daddu     $a0, $v0, $zero
/* C6E3B0 80240080 2405FFFF */  addiu     $a1, $zero, -1
/* C6E3B4 80240084 0C046F1F */  jal       set_mdl_custom_gfx_set
/* C6E3B8 80240088 24060002 */   addiu    $a2, $zero, 2
/* C6E3BC 8024008C 96620000 */  lhu       $v0, ($s3)
/* C6E3C0 80240090 0202102A */  slt       $v0, $s0, $v0
/* C6E3C4 80240094 1440FFF4 */  bnez      $v0, .L80240068
/* C6E3C8 80240098 26310002 */   addiu    $s1, $s1, 2
/* C6E3CC 8024009C 08090036 */  j         .L802400D8
/* C6E3D0 802400A0 00000000 */   nop
.L802400A4:
/* C6E3D4 802400A4 3C118015 */  lui       $s1, %hi(gCurrentModelListPtr)
/* C6E3D8 802400A8 8E3112CC */  lw        $s1, %lo(gCurrentModelListPtr)($s1)
/* C6E3DC 802400AC 0000802D */  daddu     $s0, $zero, $zero
.L802400B0:
/* C6E3E0 802400B0 8E240000 */  lw        $a0, ($s1)
/* C6E3E4 802400B4 50800005 */  beql      $a0, $zero, .L802400CC
/* C6E3E8 802400B8 26100001 */   addiu    $s0, $s0, 1
/* C6E3EC 802400BC 2405FFFF */  addiu     $a1, $zero, -1
/* C6E3F0 802400C0 0C046F1F */  jal       set_mdl_custom_gfx_set
/* C6E3F4 802400C4 24060002 */   addiu    $a2, $zero, 2
/* C6E3F8 802400C8 26100001 */  addiu     $s0, $s0, 1
.L802400CC:
/* C6E3FC 802400CC 2A020100 */  slti      $v0, $s0, 0x100
/* C6E400 802400D0 1440FFF7 */  bnez      $v0, .L802400B0
/* C6E404 802400D4 26310004 */   addiu    $s1, $s1, 4
.L802400D8:
/* C6E408 802400D8 3C028024 */  lui       $v0, %hi(D_802423E0_C70710)
/* C6E40C 802400DC 244223E0 */  addiu     $v0, $v0, %lo(D_802423E0_C70710)
/* C6E410 802400E0 C4420000 */  lwc1      $f2, ($v0)
/* C6E414 802400E4 3C013F80 */  lui       $at, 0x3f80
/* C6E418 802400E8 44810000 */  mtc1      $at, $f0
/* C6E41C 802400EC 00000000 */  nop
/* C6E420 802400F0 46001000 */  add.s     $f0, $f2, $f0
/* C6E424 802400F4 3C0143B4 */  lui       $at, 0x43b4
/* C6E428 802400F8 44811000 */  mtc1      $at, $f2
/* C6E42C 802400FC 00000000 */  nop
/* C6E430 80240100 4600103C */  c.lt.s    $f2, $f0
/* C6E434 80240104 00000000 */  nop
/* C6E438 80240108 45000003 */  bc1f      .L80240118
/* C6E43C 8024010C E4400000 */   swc1     $f0, ($v0)
/* C6E440 80240110 46020001 */  sub.s     $f0, $f0, $f2
/* C6E444 80240114 E4400000 */  swc1      $f0, ($v0)
.L80240118:
/* C6E448 80240118 24020002 */  addiu     $v0, $zero, 2
/* C6E44C 8024011C 12820037 */  beq       $s4, $v0, .L802401FC
/* C6E450 80240120 2A820003 */   slti     $v0, $s4, 3
/* C6E454 80240124 10400005 */  beqz      $v0, .L8024013C
/* C6E458 80240128 24020001 */   addiu    $v0, $zero, 1
/* C6E45C 8024012C 12820008 */  beq       $s4, $v0, .L80240150
/* C6E460 80240130 0000202D */   daddu    $a0, $zero, $zero
/* C6E464 80240134 08090088 */  j         .L80240220
/* C6E468 80240138 00000000 */   nop
.L8024013C:
/* C6E46C 8024013C 2402000A */  addiu     $v0, $zero, 0xa
/* C6E470 80240140 12820077 */  beq       $s4, $v0, .L80240320
/* C6E474 80240144 0000102D */   daddu    $v0, $zero, $zero
/* C6E478 80240148 08090088 */  j         .L80240220
/* C6E47C 8024014C 00000000 */   nop
.L80240150:
/* C6E480 80240150 3C05FD05 */  lui       $a1, 0xfd05
/* C6E484 80240154 0C0B210B */  jal       evt_get_float_variable
/* C6E488 80240158 34A50F80 */   ori      $a1, $a1, 0xf80
/* C6E48C 8024015C 44802000 */  mtc1      $zero, $f4
/* C6E490 80240160 00000000 */  nop
/* C6E494 80240164 4604003E */  c.le.s    $f0, $f4
/* C6E498 80240168 00000000 */  nop
/* C6E49C 8024016C 4501006C */  bc1t      .L80240320
/* C6E4A0 80240170 24020002 */   addiu    $v0, $zero, 2
/* C6E4A4 80240174 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* C6E4A8 80240178 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* C6E4AC 8024017C C4420028 */  lwc1      $f2, 0x28($v0)
/* C6E4B0 80240180 3C01C296 */  lui       $at, 0xc296
/* C6E4B4 80240184 44810000 */  mtc1      $at, $f0
/* C6E4B8 80240188 00000000 */  nop
/* C6E4BC 8024018C 46020081 */  sub.s     $f2, $f0, $f2
/* C6E4C0 80240190 4604103C */  c.lt.s    $f2, $f4
/* C6E4C4 80240194 00000000 */  nop
/* C6E4C8 80240198 45030001 */  bc1tl     .L802401A0
/* C6E4CC 8024019C 46001087 */   neg.s    $f2, $f2
.L802401A0:
/* C6E4D0 802401A0 3C014400 */  lui       $at, 0x4400
/* C6E4D4 802401A4 44810000 */  mtc1      $at, $f0
/* C6E4D8 802401A8 00000000 */  nop
/* C6E4DC 802401AC 46020581 */  sub.s     $f22, $f0, $f2
/* C6E4E0 802401B0 4604B03C */  c.lt.s    $f22, $f4
/* C6E4E4 802401B4 00000000 */  nop
/* C6E4E8 802401B8 45030001 */  bc1tl     .L802401C0
/* C6E4EC 802401BC 46002586 */   mov.s    $f22, $f4
.L802401C0:
/* C6E4F0 802401C0 0000202D */  daddu     $a0, $zero, $zero
/* C6E4F4 802401C4 3C05FD05 */  lui       $a1, 0xfd05
/* C6E4F8 802401C8 0C0B210B */  jal       evt_get_float_variable
/* C6E4FC 802401CC 34A50F80 */   ori      $a1, $a1, 0xf80
/* C6E500 802401D0 3C018024 */  lui       $at, %hi(D_80243080_C713B0)
/* C6E504 802401D4 D4223080 */  ldc1      $f2, %lo(D_80243080_C713B0)($at)
/* C6E508 802401D8 46000021 */  cvt.d.s   $f0, $f0
/* C6E50C 802401DC 46220002 */  mul.d     $f0, $f0, $f2
/* C6E510 802401E0 00000000 */  nop
/* C6E514 802401E4 4600B0A1 */  cvt.d.s   $f2, $f22
/* C6E518 802401E8 46201082 */  mul.d     $f2, $f2, $f0
/* C6E51C 802401EC 00000000 */  nop
/* C6E520 802401F0 241103CA */  addiu     $s1, $zero, 0x3ca
/* C6E524 802401F4 0809008B */  j         .L8024022C
/* C6E528 802401F8 462015A0 */   cvt.s.d  $f22, $f2
.L802401FC:
/* C6E52C 802401FC 3C0142C8 */  lui       $at, 0x42c8
/* C6E530 80240200 4481B000 */  mtc1      $at, $f22
/* C6E534 80240204 0000202D */  daddu     $a0, $zero, $zero
/* C6E538 80240208 3C05FD05 */  lui       $a1, 0xfd05
/* C6E53C 8024020C 0C0B1EAF */  jal       get_variable
/* C6E540 80240210 34A50F80 */   ori      $a1, $a1, 0xf80
/* C6E544 80240214 240303E3 */  addiu     $v1, $zero, 0x3e3
/* C6E548 80240218 0809008B */  j         .L8024022C
/* C6E54C 8024021C 00628823 */   subu     $s1, $v1, $v0
.L80240220:
/* C6E550 80240220 3C0142C8 */  lui       $at, 0x42c8
/* C6E554 80240224 4481B000 */  mtc1      $at, $f22
/* C6E558 80240228 241103CA */  addiu     $s1, $zero, 0x3ca
.L8024022C:
/* C6E55C 8024022C 3C108024 */  lui       $s0, %hi(D_802423E0_C70710)
/* C6E560 80240230 261023E0 */  addiu     $s0, $s0, %lo(D_802423E0_C70710)
/* C6E564 80240234 C6000000 */  lwc1      $f0, ($s0)
/* C6E568 80240238 3C014040 */  lui       $at, 0x4040
/* C6E56C 8024023C 44816000 */  mtc1      $at, $f12
/* C6E570 80240240 00000000 */  nop
/* C6E574 80240244 460C0302 */  mul.s     $f12, $f0, $f12
/* C6E578 80240248 0C00A8BB */  jal       sin_deg
/* C6E57C 8024024C 00000000 */   nop
/* C6E580 80240250 C6020000 */  lwc1      $f2, ($s0)
/* C6E584 80240254 3C014100 */  lui       $at, 0x4100
/* C6E588 80240258 44816000 */  mtc1      $at, $f12
/* C6E58C 8024025C 00000000 */  nop
/* C6E590 80240260 460C1302 */  mul.s     $f12, $f2, $f12
/* C6E594 80240264 00000000 */  nop
/* C6E598 80240268 0C00A8BB */  jal       sin_deg
/* C6E59C 8024026C 46000506 */   mov.s    $f20, $f0
/* C6E5A0 80240270 3C013FE0 */  lui       $at, 0x3fe0
/* C6E5A4 80240274 44811800 */  mtc1      $at, $f3
/* C6E5A8 80240278 44801000 */  mtc1      $zero, $f2
/* C6E5AC 8024027C 4600A521 */  cvt.d.s   $f20, $f20
/* C6E5B0 80240280 4622A502 */  mul.d     $f20, $f20, $f2
/* C6E5B4 80240284 00000000 */  nop
/* C6E5B8 80240288 46000021 */  cvt.d.s   $f0, $f0
/* C6E5BC 8024028C 46220002 */  mul.d     $f0, $f0, $f2
/* C6E5C0 80240290 00000000 */  nop
/* C6E5C4 80240294 4620A500 */  add.d     $f20, $f20, $f0
/* C6E5C8 80240298 4600B021 */  cvt.d.s   $f0, $f22
/* C6E5CC 8024029C 46340502 */  mul.d     $f20, $f0, $f20
/* C6E5D0 802402A0 00000000 */  nop
/* C6E5D4 802402A4 46340000 */  add.d     $f0, $f0, $f20
/* C6E5D8 802402A8 3C0141E0 */  lui       $at, 0x41e0
/* C6E5DC 802402AC 44811800 */  mtc1      $at, $f3
/* C6E5E0 802402B0 44801000 */  mtc1      $zero, $f2
/* C6E5E4 802402B4 00000000 */  nop
/* C6E5E8 802402B8 4620103E */  c.le.d    $f2, $f0
/* C6E5EC 802402BC 00000000 */  nop
/* C6E5F0 802402C0 45030005 */  bc1tl     .L802402D8
/* C6E5F4 802402C4 46220001 */   sub.d    $f0, $f0, $f2
/* C6E5F8 802402C8 4620018D */  trunc.w.d $f6, $f0
/* C6E5FC 802402CC 44073000 */  mfc1      $a3, $f6
/* C6E600 802402D0 080900BC */  j         .L802402F0
/* C6E604 802402D4 2404003C */   addiu    $a0, $zero, 0x3c
.L802402D8:
/* C6E608 802402D8 3C028000 */  lui       $v0, 0x8000
/* C6E60C 802402DC 4620018D */  trunc.w.d $f6, $f0
/* C6E610 802402E0 44073000 */  mfc1      $a3, $f6
/* C6E614 802402E4 00000000 */  nop
/* C6E618 802402E8 00E23825 */  or        $a3, $a3, $v0
/* C6E61C 802402EC 2404003C */  addiu     $a0, $zero, 0x3c
.L802402F0:
/* C6E620 802402F0 24050032 */  addiu     $a1, $zero, 0x32
/* C6E624 802402F4 2406001E */  addiu     $a2, $zero, 0x1e
/* C6E628 802402F8 24020014 */  addiu     $v0, $zero, 0x14
/* C6E62C 802402FC AFA20010 */  sw        $v0, 0x10($sp)
/* C6E630 80240300 AFA20014 */  sw        $v0, 0x14($sp)
/* C6E634 80240304 AFA20018 */  sw        $v0, 0x18($sp)
/* C6E638 80240308 240203E8 */  addiu     $v0, $zero, 0x3e8
/* C6E63C 8024030C 30E700FF */  andi      $a3, $a3, 0xff
/* C6E640 80240310 AFB1001C */  sw        $s1, 0x1c($sp)
/* C6E644 80240314 0C046FAD */  jal       set_model_fog_color_parameters
/* C6E648 80240318 AFA20020 */   sw       $v0, 0x20($sp)
/* C6E64C 8024031C 0000102D */  daddu     $v0, $zero, $zero
.L80240320:
/* C6E650 80240320 8FBF003C */  lw        $ra, 0x3c($sp)
/* C6E654 80240324 8FB40038 */  lw        $s4, 0x38($sp)
/* C6E658 80240328 8FB30034 */  lw        $s3, 0x34($sp)
/* C6E65C 8024032C 8FB20030 */  lw        $s2, 0x30($sp)
/* C6E660 80240330 8FB1002C */  lw        $s1, 0x2c($sp)
/* C6E664 80240334 8FB00028 */  lw        $s0, 0x28($sp)
/* C6E668 80240338 D7B60048 */  ldc1      $f22, 0x48($sp)
/* C6E66C 8024033C D7B40040 */  ldc1      $f20, 0x40($sp)
/* C6E670 80240340 03E00008 */  jr        $ra
/* C6E674 80240344 27BD0050 */   addiu    $sp, $sp, 0x50

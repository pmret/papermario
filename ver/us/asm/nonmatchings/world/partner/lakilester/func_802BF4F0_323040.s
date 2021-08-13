.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BF4F0_323040
/* 323040 802BF4F0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 323044 802BF4F4 AFB20038 */  sw        $s2, 0x38($sp)
/* 323048 802BF4F8 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 32304C 802BF4FC 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 323050 802BF500 AFB3003C */  sw        $s3, 0x3c($sp)
/* 323054 802BF504 3C138011 */  lui       $s3, %hi(gPartnerActionStatus)
/* 323058 802BF508 2673EBB0 */  addiu     $s3, $s3, %lo(gPartnerActionStatus)
/* 32305C 802BF50C AFBF0040 */  sw        $ra, 0x40($sp)
/* 323060 802BF510 AFB10034 */  sw        $s1, 0x34($sp)
/* 323064 802BF514 AFB00030 */  sw        $s0, 0x30($sp)
/* 323068 802BF518 10A00014 */  beqz      $a1, .L802BF56C
/* 32306C 802BF51C 8C90014C */   lw       $s0, 0x14c($a0)
/* 323070 802BF520 3C02802C */  lui       $v0, %hi(D_802BFF0C)
/* 323074 802BF524 8C42FF0C */  lw        $v0, %lo(D_802BFF0C)($v0)
/* 323078 802BF528 14400002 */  bnez      $v0, .L802BF534
/* 32307C 802BF52C 0000182D */   daddu    $v1, $zero, $zero
/* 323080 802BF530 24030003 */  addiu     $v1, $zero, 3
.L802BF534:
/* 323084 802BF534 3C01802C */  lui       $at, %hi(D_802BFF00)
/* 323088 802BF538 AC23FF00 */  sw        $v1, %lo(D_802BFF00)($at)
/* 32308C 802BF53C 0C03BA65 */  jal       partner_init_put_away
/* 323090 802BF540 0200202D */   daddu    $a0, $s0, $zero
/* 323094 802BF544 0C0AF5F7 */  jal       func_802BD7DC
/* 323098 802BF548 00000000 */   nop
/* 32309C 802BF54C 3C02FFBF */  lui       $v0, 0xffbf
/* 3230A0 802BF550 3442FFFF */  ori       $v0, $v0, 0xffff
/* 3230A4 802BF554 8E430004 */  lw        $v1, 4($s2)
/* 3230A8 802BF558 8E440000 */  lw        $a0, ($s2)
/* 3230AC 802BF55C 00621824 */  and       $v1, $v1, $v0
/* 3230B0 802BF560 34840100 */  ori       $a0, $a0, 0x100
/* 3230B4 802BF564 AE430004 */  sw        $v1, 4($s2)
/* 3230B8 802BF568 AE440000 */  sw        $a0, ($s2)
.L802BF56C:
/* 3230BC 802BF56C 3C11802C */  lui       $s1, %hi(D_802BFF00)
/* 3230C0 802BF570 2631FF00 */  addiu     $s1, $s1, %lo(D_802BFF00)
/* 3230C4 802BF574 8E230000 */  lw        $v1, ($s1)
/* 3230C8 802BF578 24020001 */  addiu     $v0, $zero, 1
/* 3230CC 802BF57C 1062005F */  beq       $v1, $v0, .L802BF6FC
/* 3230D0 802BF580 28620002 */   slti     $v0, $v1, 2
/* 3230D4 802BF584 10400005 */  beqz      $v0, .L802BF59C
/* 3230D8 802BF588 24020002 */   addiu    $v0, $zero, 2
/* 3230DC 802BF58C 10600007 */  beqz      $v1, .L802BF5AC
/* 3230E0 802BF590 00000000 */   nop
/* 3230E4 802BF594 080AFE0E */  j         .L802BF838
/* 3230E8 802BF598 00000000 */   nop
.L802BF59C:
/* 3230EC 802BF59C 1062005D */  beq       $v1, $v0, .L802BF714
/* 3230F0 802BF5A0 00000000 */   nop
/* 3230F4 802BF5A4 080AFE0E */  j         .L802BF838
/* 3230F8 802BF5A8 00000000 */   nop
.L802BF5AC:
/* 3230FC 802BF5AC 0C0AF5F7 */  jal       func_802BD7DC
/* 323100 802BF5B0 00000000 */   nop
/* 323104 802BF5B4 3C02800B */  lui       $v0, %hi(gCameras)
/* 323108 802BF5B8 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 32310C 802BF5BC C64200A8 */  lwc1      $f2, 0xa8($s2)
/* 323110 802BF5C0 3C0142B4 */  lui       $at, 0x42b4
/* 323114 802BF5C4 44813000 */  mtc1      $at, $f6
/* 323118 802BF5C8 C444006C */  lwc1      $f4, 0x6c($v0)
/* 32311C 802BF5CC 4602303E */  c.le.s    $f6, $f2
/* 323120 802BF5D0 00000000 */  nop
/* 323124 802BF5D4 4500000E */  bc1f      .L802BF610
/* 323128 802BF5D8 00000000 */   nop
/* 32312C 802BF5DC 3C014387 */  lui       $at, 0x4387
/* 323130 802BF5E0 44810000 */  mtc1      $at, $f0
/* 323134 802BF5E4 00000000 */  nop
/* 323138 802BF5E8 4600103C */  c.lt.s    $f2, $f0
/* 32313C 802BF5EC 00000000 */  nop
/* 323140 802BF5F0 45000007 */  bc1f      .L802BF610
/* 323144 802BF5F4 00000000 */   nop
/* 323148 802BF5F8 3C014334 */  lui       $at, 0x4334
/* 32314C 802BF5FC 44810000 */  mtc1      $at, $f0
/* 323150 802BF600 00000000 */  nop
/* 323154 802BF604 46002000 */  add.s     $f0, $f4, $f0
/* 323158 802BF608 080AFD8B */  j         .L802BF62C
/* 32315C 802BF60C 46060001 */   sub.s    $f0, $f0, $f6
.L802BF610:
/* 323160 802BF610 44800000 */  mtc1      $zero, $f0
/* 323164 802BF614 00000000 */  nop
/* 323168 802BF618 46002000 */  add.s     $f0, $f4, $f0
/* 32316C 802BF61C 3C0142B4 */  lui       $at, 0x42b4
/* 323170 802BF620 44811000 */  mtc1      $at, $f2
/* 323174 802BF624 00000000 */  nop
/* 323178 802BF628 46020001 */  sub.s     $f0, $f0, $f2
.L802BF62C:
/* 32317C 802BF62C E600000C */  swc1      $f0, 0xc($s0)
/* 323180 802BF630 C64C0028 */  lwc1      $f12, 0x28($s2)
/* 323184 802BF634 C64E0030 */  lwc1      $f14, 0x30($s2)
/* 323188 802BF638 8E060060 */  lw        $a2, 0x60($s0)
/* 32318C 802BF63C 0C00A7B5 */  jal       dist2D
/* 323190 802BF640 8E070068 */   lw       $a3, 0x68($s0)
/* 323194 802BF644 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 323198 802BF648 C6000064 */  lwc1      $f0, 0x64($s0)
/* 32319C 802BF64C C602003C */  lwc1      $f2, 0x3c($s0)
/* 3231A0 802BF650 2402000E */  addiu     $v0, $zero, 0xe
/* 3231A4 802BF654 4600103C */  c.lt.s    $f2, $f0
/* 3231A8 802BF658 00000000 */  nop
/* 3231AC 802BF65C 45000009 */  bc1f      .L802BF684
/* 3231B0 802BF660 A602008E */   sh       $v0, 0x8e($s0)
/* 3231B4 802BF664 46020001 */  sub.s     $f0, $f0, $f2
/* 3231B8 802BF668 3C014160 */  lui       $at, 0x4160
/* 3231BC 802BF66C 44811000 */  mtc1      $at, $f2
/* 3231C0 802BF670 3C0140C0 */  lui       $at, 0x40c0
/* 3231C4 802BF674 44812000 */  mtc1      $at, $f4
/* 3231C8 802BF678 46020003 */  div.s     $f0, $f0, $f2
/* 3231CC 802BF67C 080AFDA4 */  j         .L802BF690
/* 3231D0 802BF680 46040000 */   add.s    $f0, $f0, $f4
.L802BF684:
/* 3231D4 802BF684 3C0140C0 */  lui       $at, 0x40c0
/* 3231D8 802BF688 44810000 */  mtc1      $at, $f0
/* 3231DC 802BF68C 00000000 */  nop
.L802BF690:
/* 3231E0 802BF690 E600001C */  swc1      $f0, 0x1c($s0)
/* 3231E4 802BF694 3C013F99 */  lui       $at, 0x3f99
/* 3231E8 802BF698 3421999A */  ori       $at, $at, 0x999a
/* 3231EC 802BF69C 44810000 */  mtc1      $at, $f0
/* 3231F0 802BF6A0 8E060060 */  lw        $a2, 0x60($s0)
/* 3231F4 802BF6A4 8E070068 */  lw        $a3, 0x68($s0)
/* 3231F8 802BF6A8 8602008E */  lh        $v0, 0x8e($s0)
/* 3231FC 802BF6AC E6000014 */  swc1      $f0, 0x14($s0)
/* 323200 802BF6B0 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 323204 802BF6B4 44821000 */  mtc1      $v0, $f2
/* 323208 802BF6B8 00000000 */  nop
/* 32320C 802BF6BC 468010A0 */  cvt.s.w   $f2, $f2
/* 323210 802BF6C0 46020003 */  div.s     $f0, $f0, $f2
/* 323214 802BF6C4 E6000018 */  swc1      $f0, 0x18($s0)
/* 323218 802BF6C8 C64C0028 */  lwc1      $f12, 0x28($s2)
/* 32321C 802BF6CC 0C00A720 */  jal       atan2
/* 323220 802BF6D0 C64E0030 */   lwc1     $f14, 0x30($s2)
/* 323224 802BF6D4 3C040001 */  lui       $a0, 1
/* 323228 802BF6D8 34840006 */  ori       $a0, $a0, 6
/* 32322C 802BF6DC 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* 323230 802BF6E0 E600000C */   swc1     $f0, 0xc($s0)
/* 323234 802BF6E4 3C03802C */  lui       $v1, %hi(D_802BFF00)
/* 323238 802BF6E8 2463FF00 */  addiu     $v1, $v1, %lo(D_802BFF00)
/* 32323C 802BF6EC 8C620000 */  lw        $v0, ($v1)
/* 323240 802BF6F0 24420001 */  addiu     $v0, $v0, 1
/* 323244 802BF6F4 080AFE0E */  j         .L802BF838
/* 323248 802BF6F8 AC620000 */   sw       $v0, ($v1)
.L802BF6FC:
/* 32324C 802BF6FC 3C040001 */  lui       $a0, 1
/* 323250 802BF700 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* 323254 802BF704 34840007 */   ori      $a0, $a0, 7
/* 323258 802BF708 8E220000 */  lw        $v0, ($s1)
/* 32325C 802BF70C 24420001 */  addiu     $v0, $v0, 1
/* 323260 802BF710 AE220000 */  sw        $v0, ($s1)
.L802BF714:
/* 323264 802BF714 C640002C */  lwc1      $f0, 0x2c($s2)
/* 323268 802BF718 C602001C */  lwc1      $f2, 0x1c($s0)
/* 32326C 802BF71C 46020000 */  add.s     $f0, $f0, $f2
/* 323270 802BF720 26440028 */  addiu     $a0, $s2, 0x28
/* 323274 802BF724 E640002C */  swc1      $f0, 0x2c($s2)
/* 323278 802BF728 C600001C */  lwc1      $f0, 0x1c($s0)
/* 32327C 802BF72C C6020014 */  lwc1      $f2, 0x14($s0)
/* 323280 802BF730 8E060018 */  lw        $a2, 0x18($s0)
/* 323284 802BF734 46020001 */  sub.s     $f0, $f0, $f2
/* 323288 802BF738 8E07000C */  lw        $a3, 0xc($s0)
/* 32328C 802BF73C 26450030 */  addiu     $a1, $s2, 0x30
/* 323290 802BF740 0C00A7E7 */  jal       add_vec2D_polar
/* 323294 802BF744 E600001C */   swc1     $f0, 0x1c($s0)
/* 323298 802BF748 0C0392B6 */  jal       func_800E4AD8
/* 32329C 802BF74C 0000202D */   daddu    $a0, $zero, $zero
/* 3232A0 802BF750 C602001C */  lwc1      $f2, 0x1c($s0)
/* 3232A4 802BF754 44800000 */  mtc1      $zero, $f0
/* 3232A8 802BF758 00000000 */  nop
/* 3232AC 802BF75C 4600103E */  c.le.s    $f2, $f0
/* 3232B0 802BF760 00000000 */  nop
/* 3232B4 802BF764 45000011 */  bc1f      .L802BF7AC
/* 3232B8 802BF768 0000202D */   daddu    $a0, $zero, $zero
/* 3232BC 802BF76C 8E420000 */  lw        $v0, ($s2)
/* 3232C0 802BF770 34420004 */  ori       $v0, $v0, 4
/* 3232C4 802BF774 AE420000 */  sw        $v0, ($s2)
/* 3232C8 802BF778 C600001C */  lwc1      $f0, 0x1c($s0)
/* 3232CC 802BF77C 3C01C024 */  lui       $at, 0xc024
/* 3232D0 802BF780 44811800 */  mtc1      $at, $f3
/* 3232D4 802BF784 44801000 */  mtc1      $zero, $f2
/* 3232D8 802BF788 46000021 */  cvt.d.s   $f0, $f0
/* 3232DC 802BF78C 4622003C */  c.lt.d    $f0, $f2
/* 3232E0 802BF790 00000000 */  nop
/* 3232E4 802BF794 45000005 */  bc1f      .L802BF7AC
/* 3232E8 802BF798 00000000 */   nop
/* 3232EC 802BF79C 3C01C120 */  lui       $at, 0xc120
/* 3232F0 802BF7A0 44810000 */  mtc1      $at, $f0
/* 3232F4 802BF7A4 00000000 */  nop
/* 3232F8 802BF7A8 E600001C */  swc1      $f0, 0x1c($s0)
.L802BF7AC:
/* 3232FC 802BF7AC C6420028 */  lwc1      $f2, 0x28($s2)
/* 323300 802BF7B0 864200B0 */  lh        $v0, 0xb0($s2)
/* 323304 802BF7B4 C6400030 */  lwc1      $f0, 0x30($s2)
/* 323308 802BF7B8 27A50020 */  addiu     $a1, $sp, 0x20
/* 32330C 802BF7BC E7A00028 */  swc1      $f0, 0x28($sp)
/* 323310 802BF7C0 44820000 */  mtc1      $v0, $f0
/* 323314 802BF7C4 00000000 */  nop
/* 323318 802BF7C8 46800020 */  cvt.s.w   $f0, $f0
/* 32331C 802BF7CC E7A20020 */  swc1      $f2, 0x20($sp)
/* 323320 802BF7D0 C642002C */  lwc1      $f2, 0x2c($s2)
/* 323324 802BF7D4 864200B0 */  lh        $v0, 0xb0($s2)
/* 323328 802BF7D8 46001080 */  add.s     $f2, $f2, $f0
/* 32332C 802BF7DC 44820000 */  mtc1      $v0, $f0
/* 323330 802BF7E0 00000000 */  nop
/* 323334 802BF7E4 46800020 */  cvt.s.w   $f0, $f0
/* 323338 802BF7E8 27A2002C */  addiu     $v0, $sp, 0x2c
/* 32333C 802BF7EC E7A0002C */  swc1      $f0, 0x2c($sp)
/* 323340 802BF7F0 E7A20024 */  swc1      $f2, 0x24($sp)
/* 323344 802BF7F4 AFA20010 */  sw        $v0, 0x10($sp)
/* 323348 802BF7F8 C600000C */  lwc1      $f0, 0xc($s0)
/* 32334C 802BF7FC 27A60024 */  addiu     $a2, $sp, 0x24
/* 323350 802BF800 E7A00014 */  swc1      $f0, 0x14($sp)
/* 323354 802BF804 860200A6 */  lh        $v0, 0xa6($s0)
/* 323358 802BF808 27A70028 */  addiu     $a3, $sp, 0x28
/* 32335C 802BF80C 44820000 */  mtc1      $v0, $f0
/* 323360 802BF810 00000000 */  nop
/* 323364 802BF814 46800020 */  cvt.s.w   $f0, $f0
/* 323368 802BF818 0C0371DE */  jal       npc_raycast_down_ahead
/* 32336C 802BF81C E7A00018 */   swc1     $f0, 0x18($sp)
/* 323370 802BF820 10400005 */  beqz      $v0, .L802BF838
/* 323374 802BF824 24020003 */   addiu    $v0, $zero, 3
/* 323378 802BF828 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 32337C 802BF82C 3C01802C */  lui       $at, %hi(D_802BFF00)
/* 323380 802BF830 AC22FF00 */  sw        $v0, %lo(D_802BFF00)($at)
/* 323384 802BF834 E640002C */  swc1      $f0, 0x2c($s2)
.L802BF838:
/* 323388 802BF838 3C02800B */  lui       $v0, %hi(gCameras)
/* 32338C 802BF83C 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 323390 802BF840 C6400028 */  lwc1      $f0, 0x28($s2)
/* 323394 802BF844 C642002C */  lwc1      $f2, 0x2c($s2)
/* 323398 802BF848 C6440030 */  lwc1      $f4, 0x30($s2)
/* 32339C 802BF84C 3C11802C */  lui       $s1, %hi(D_802BFF00)
/* 3233A0 802BF850 2631FF00 */  addiu     $s1, $s1, %lo(D_802BFF00)
/* 3233A4 802BF854 E4400060 */  swc1      $f0, 0x60($v0)
/* 3233A8 802BF858 E4420064 */  swc1      $f2, 0x64($v0)
/* 3233AC 802BF85C E4440068 */  swc1      $f4, 0x68($v0)
/* 3233B0 802BF860 8E230000 */  lw        $v1, ($s1)
/* 3233B4 802BF864 24020004 */  addiu     $v0, $zero, 4
/* 3233B8 802BF868 10620041 */  beq       $v1, $v0, .L802BF970
/* 3233BC 802BF86C 28620005 */   slti     $v0, $v1, 5
/* 3233C0 802BF870 10400005 */  beqz      $v0, .L802BF888
/* 3233C4 802BF874 24020003 */   addiu    $v0, $zero, 3
/* 3233C8 802BF878 10620008 */  beq       $v1, $v0, .L802BF89C
/* 3233CC 802BF87C 0000102D */   daddu    $v0, $zero, $zero
/* 3233D0 802BF880 080AFE79 */  j         .L802BF9E4
/* 3233D4 802BF884 00000000 */   nop
.L802BF888:
/* 3233D8 802BF888 24020005 */  addiu     $v0, $zero, 5
/* 3233DC 802BF88C 1062004F */  beq       $v1, $v0, .L802BF9CC
/* 3233E0 802BF890 00000000 */   nop
/* 3233E4 802BF894 080AFE79 */  j         .L802BF9E4
/* 3233E8 802BF898 0000102D */   daddu    $v0, $zero, $zero
.L802BF89C:
/* 3233EC 802BF89C 2402FFB7 */  addiu     $v0, $zero, -0x49
/* 3233F0 802BF8A0 3C05802C */  lui       $a1, %hi(D_802BFF08)
/* 3233F4 802BF8A4 24A5FF08 */  addiu     $a1, $a1, %lo(D_802BFF08)
/* 3233F8 802BF8A8 8E030000 */  lw        $v1, ($s0)
/* 3233FC 802BF8AC 8CA40000 */  lw        $a0, ($a1)
/* 323400 802BF8B0 00621824 */  and       $v1, $v1, $v0
/* 323404 802BF8B4 10800003 */  beqz      $a0, .L802BF8C4
/* 323408 802BF8B8 AE030000 */   sw       $v1, ($s0)
/* 32340C 802BF8BC 0C038050 */  jal       enable_player_static_collisions
/* 323410 802BF8C0 ACA00000 */   sw       $zero, ($a1)
.L802BF8C4:
/* 323414 802BF8C4 0C03802C */  jal       enable_player_shadow
/* 323418 802BF8C8 00000000 */   nop
/* 32341C 802BF8CC 8E420000 */  lw        $v0, ($s2)
/* 323420 802BF8D0 30420800 */  andi      $v0, $v0, 0x800
/* 323424 802BF8D4 10400014 */  beqz      $v0, .L802BF928
/* 323428 802BF8D8 00000000 */   nop
/* 32342C 802BF8DC 3C03802C */  lui       $v1, %hi(D_802BFF04)
/* 323430 802BF8E0 2463FF04 */  addiu     $v1, $v1, %lo(D_802BFF04)
/* 323434 802BF8E4 8C620000 */  lw        $v0, ($v1)
/* 323438 802BF8E8 A2600003 */  sb        $zero, 3($s3)
/* 32343C 802BF8EC 10400003 */  beqz      $v0, .L802BF8FC
/* 323440 802BF8F0 A2600000 */   sb       $zero, ($s3)
/* 323444 802BF8F4 0C038069 */  jal       enable_player_input
/* 323448 802BF8F8 AC600000 */   sw       $zero, ($v1)
.L802BF8FC:
/* 32344C 802BF8FC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 323450 802BF900 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 323454 802BF904 A040007D */  sb        $zero, 0x7d($v0)
/* 323458 802BF908 3C01802C */  lui       $at, %hi(D_802BFF0C)
/* 32345C 802BF90C AC20FF0C */  sw        $zero, %lo(D_802BFF0C)($at)
/* 323460 802BF910 0C03BD17 */  jal       partner_clear_player_tracking
/* 323464 802BF914 0200202D */   daddu    $a0, $s0, $zero
/* 323468 802BF918 0C039769 */  jal       set_action_state
/* 32346C 802BF91C 24040015 */   addiu    $a0, $zero, 0x15
/* 323470 802BF920 080AFE79 */  j         .L802BF9E4
/* 323474 802BF924 24020001 */   addiu    $v0, $zero, 1
.L802BF928:
/* 323478 802BF928 3C02802C */  lui       $v0, %hi(D_802BFF0C)
/* 32347C 802BF92C 8C42FF0C */  lw        $v0, %lo(D_802BFF0C)($v0)
/* 323480 802BF930 14400005 */  bnez      $v0, .L802BF948
/* 323484 802BF934 00000000 */   nop
/* 323488 802BF938 0C0391D1 */  jal       phys_main_collision_below
/* 32348C 802BF93C 00000000 */   nop
/* 323490 802BF940 080AFE56 */  j         .L802BF958
/* 323494 802BF944 00000000 */   nop
.L802BF948:
/* 323498 802BF948 0C039769 */  jal       set_action_state
/* 32349C 802BF94C 24040008 */   addiu    $a0, $zero, 8
/* 3234A0 802BF950 0C038C1B */  jal       gravity_use_fall_parms
/* 3234A4 802BF954 00000000 */   nop
.L802BF958:
/* 3234A8 802BF958 3C03802C */  lui       $v1, %hi(D_802BFF00)
/* 3234AC 802BF95C 2463FF00 */  addiu     $v1, $v1, %lo(D_802BFF00)
/* 3234B0 802BF960 8C620000 */  lw        $v0, ($v1)
/* 3234B4 802BF964 24420001 */  addiu     $v0, $v0, 1
/* 3234B8 802BF968 080AFE78 */  j         .L802BF9E0
/* 3234BC 802BF96C AC620000 */   sw       $v0, ($v1)
.L802BF970:
/* 3234C0 802BF970 2402FEFF */  addiu     $v0, $zero, -0x101
/* 3234C4 802BF974 3C05802C */  lui       $a1, %hi(D_802BFF04)
/* 3234C8 802BF978 24A5FF04 */  addiu     $a1, $a1, %lo(D_802BFF04)
/* 3234CC 802BF97C A2600003 */  sb        $zero, 3($s3)
/* 3234D0 802BF980 A2600000 */  sb        $zero, ($s3)
/* 3234D4 802BF984 8E430000 */  lw        $v1, ($s2)
/* 3234D8 802BF988 8CA40000 */  lw        $a0, ($a1)
/* 3234DC 802BF98C 00621824 */  and       $v1, $v1, $v0
/* 3234E0 802BF990 10800003 */  beqz      $a0, .L802BF9A0
/* 3234E4 802BF994 AE430000 */   sw       $v1, ($s2)
/* 3234E8 802BF998 0C038069 */  jal       enable_player_input
/* 3234EC 802BF99C ACA00000 */   sw       $zero, ($a1)
.L802BF9A0:
/* 3234F0 802BF9A0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 3234F4 802BF9A4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 3234F8 802BF9A8 A040007D */  sb        $zero, 0x7d($v0)
/* 3234FC 802BF9AC 3C01802C */  lui       $at, %hi(D_802BFF0C)
/* 323500 802BF9B0 AC20FF0C */  sw        $zero, %lo(D_802BFF0C)($at)
/* 323504 802BF9B4 0C03BD17 */  jal       partner_clear_player_tracking
/* 323508 802BF9B8 0200202D */   daddu    $a0, $s0, $zero
/* 32350C 802BF9BC 8E220000 */  lw        $v0, ($s1)
/* 323510 802BF9C0 24420001 */  addiu     $v0, $v0, 1
/* 323514 802BF9C4 080AFE78 */  j         .L802BF9E0
/* 323518 802BF9C8 AE220000 */   sw       $v0, ($s1)
.L802BF9CC:
/* 32351C 802BF9CC 0C03BA6E */  jal       partner_put_away
/* 323520 802BF9D0 0200202D */   daddu    $a0, $s0, $zero
/* 323524 802BF9D4 0040182D */  daddu     $v1, $v0, $zero
/* 323528 802BF9D8 14600002 */  bnez      $v1, .L802BF9E4
/* 32352C 802BF9DC 24020001 */   addiu    $v0, $zero, 1
.L802BF9E0:
/* 323530 802BF9E0 0000102D */  daddu     $v0, $zero, $zero
.L802BF9E4:
/* 323534 802BF9E4 8FBF0040 */  lw        $ra, 0x40($sp)
/* 323538 802BF9E8 8FB3003C */  lw        $s3, 0x3c($sp)
/* 32353C 802BF9EC 8FB20038 */  lw        $s2, 0x38($sp)
/* 323540 802BF9F0 8FB10034 */  lw        $s1, 0x34($sp)
/* 323544 802BF9F4 8FB00030 */  lw        $s0, 0x30($sp)
/* 323548 802BF9F8 03E00008 */  jr        $ra
/* 32354C 802BF9FC 27BD0048 */   addiu    $sp, $sp, 0x48

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802B6740_E27C50
.word L802B6184_E27694, L802B6394_E278A4, L802B64A8_E279B8, L802B6544_E27A54, L802B65C0_E27AD0, L802B660C_E27B1C, L802B666C_E27B7C, L802B66C0_E27BD0

glabel D_802B6760_E27C70
.double 0.1

glabel D_802B6768_E27C78
.double 0.01

glabel D_802B6770_E27C80
.double 0.01, 0.0

.section .text

glabel func_802B6060_E27570
/* E27570 802B6060 27BDFF90 */  addiu     $sp, $sp, -0x70
/* E27574 802B6064 AFB00058 */  sw        $s0, 0x58($sp)
/* E27578 802B6068 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E2757C 802B606C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E27580 802B6070 AFBF0064 */  sw        $ra, 0x64($sp)
/* E27584 802B6074 AFB20060 */  sw        $s2, 0x60($sp)
/* E27588 802B6078 AFB1005C */  sw        $s1, 0x5c($sp)
/* E2758C 802B607C F7B40068 */  sdc1      $f20, 0x68($sp)
/* E27590 802B6080 8E040000 */  lw        $a0, ($s0)
/* E27594 802B6084 04830021 */  bgezl     $a0, .L802B610C
/* E27598 802B6088 0200202D */   daddu    $a0, $s0, $zero
/* E2759C 802B608C 3C027FFF */  lui       $v0, 0x7fff
/* E275A0 802B6090 3442FFFF */  ori       $v0, $v0, 0xffff
/* E275A4 802B6094 8E030004 */  lw        $v1, 4($s0)
/* E275A8 802B6098 00821024 */  and       $v0, $a0, $v0
/* E275AC 802B609C AE020000 */  sw        $v0, ($s0)
/* E275B0 802B60A0 A20000B6 */  sb        $zero, 0xb6($s0)
/* E275B4 802B60A4 AE000054 */  sw        $zero, 0x54($s0)
/* E275B8 802B60A8 34630004 */  ori       $v1, $v1, 4
/* E275BC 802B60AC 0C0AD800 */  jal       func_802B6000_E27510
/* E275C0 802B60B0 AE030004 */   sw       $v1, 4($s0)
/* E275C4 802B60B4 3C040001 */  lui       $a0, 1
/* E275C8 802B60B8 3C01802B */  lui       $at, %hi(D_802B6780)
/* E275CC 802B60BC AC206780 */  sw        $zero, %lo(D_802B6780)($at)
/* E275D0 802B60C0 3C01802B */  lui       $at, %hi(D_802B6790)
/* E275D4 802B60C4 AC206790 */  sw        $zero, %lo(D_802B6790)($at)
/* E275D8 802B60C8 3C01802B */  lui       $at, %hi(D_802B6794)
/* E275DC 802B60CC AC206794 */  sw        $zero, %lo(D_802B6794)($at)
/* E275E0 802B60D0 3C01802B */  lui       $at, %hi(D_802B6798)
/* E275E4 802B60D4 AC206798 */  sw        $zero, %lo(D_802B6798)($at)
/* E275E8 802B60D8 3C01802B */  lui       $at, %hi(D_802B679C)
/* E275EC 802B60DC AC20679C */  sw        $zero, %lo(D_802B679C)($at)
/* E275F0 802B60E0 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E275F4 802B60E4 3484000A */   ori      $a0, $a0, 0xa
/* E275F8 802B60E8 24040167 */  addiu     $a0, $zero, 0x167
/* E275FC 802B60EC 0C052736 */  jal       sfx_play_sound_at_player
/* E27600 802B60F0 0000282D */   daddu    $a1, $zero, $zero
/* E27604 802B60F4 3C03800B */  lui       $v1, %hi(gCameras)
/* E27608 802B60F8 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* E2760C 802B60FC 94620002 */  lhu       $v0, 2($v1)
/* E27610 802B6100 34420001 */  ori       $v0, $v0, 1
/* E27614 802B6104 A4620002 */  sh        $v0, 2($v1)
/* E27618 802B6108 0200202D */  daddu     $a0, $s0, $zero
.L802B610C:
/* E2761C 802B610C 27A50028 */  addiu     $a1, $sp, 0x28
/* E27620 802B6110 27A6002C */  addiu     $a2, $sp, 0x2c
/* E27624 802B6114 C6080054 */  lwc1      $f8, 0x54($s0)
/* E27628 802B6118 C6000028 */  lwc1      $f0, 0x28($s0)
/* E2762C 802B611C C602002C */  lwc1      $f2, 0x2c($s0)
/* E27630 802B6120 C6040030 */  lwc1      $f4, 0x30($s0)
/* E27634 802B6124 C60600A0 */  lwc1      $f6, 0xa0($s0)
/* E27638 802B6128 27A70030 */  addiu     $a3, $sp, 0x30
/* E2763C 802B612C E7A00028 */  swc1      $f0, 0x28($sp)
/* E27640 802B6130 E7A2002C */  swc1      $f2, 0x2c($sp)
/* E27644 802B6134 E7A40030 */  swc1      $f4, 0x30($sp)
/* E27648 802B6138 E7A80010 */  swc1      $f8, 0x10($sp)
/* E2764C 802B613C 0C037D18 */  jal       player_test_move_with_slipping
/* E27650 802B6140 E7A60014 */   swc1     $f6, 0x14($sp)
/* E27654 802B6144 C7A00028 */  lwc1      $f0, 0x28($sp)
/* E27658 802B6148 C7A20030 */  lwc1      $f2, 0x30($sp)
/* E2765C 802B614C C7A4002C */  lwc1      $f4, 0x2c($sp)
/* E27660 802B6150 820300B6 */  lb        $v1, 0xb6($s0)
/* E27664 802B6154 AFA20048 */  sw        $v0, 0x48($sp)
/* E27668 802B6158 2C620008 */  sltiu     $v0, $v1, 8
/* E2766C 802B615C E6000028 */  swc1      $f0, 0x28($s0)
/* E27670 802B6160 E6020030 */  swc1      $f2, 0x30($s0)
/* E27674 802B6164 1040016D */  beqz      $v0, .L802B671C
/* E27678 802B6168 E604002C */   swc1     $f4, 0x2c($s0)
/* E2767C 802B616C 00031080 */  sll       $v0, $v1, 2
/* E27680 802B6170 3C01802B */  lui       $at, %hi(jtbl_802B6740_E27C50)
/* E27684 802B6174 00220821 */  addu      $at, $at, $v0
/* E27688 802B6178 8C226740 */  lw        $v0, %lo(jtbl_802B6740_E27C50)($at)
/* E2768C 802B617C 00400008 */  jr        $v0
/* E27690 802B6180 00000000 */   nop
glabel L802B6184_E27694
/* E27694 802B6184 3C02802B */  lui       $v0, %hi(D_802B6780)
/* E27698 802B6188 24426780 */  addiu     $v0, $v0, %lo(D_802B6780)
/* E2769C 802B618C C4400000 */  lwc1      $f0, ($v0)
/* E276A0 802B6190 3C01802B */  lui       $at, %hi(D_802B6760_E27C70)
/* E276A4 802B6194 D4226760 */  ldc1      $f2, %lo(D_802B6760_E27C70)($at)
/* E276A8 802B6198 46000021 */  cvt.d.s   $f0, $f0
/* E276AC 802B619C 46220000 */  add.d     $f0, $f0, $f2
/* E276B0 802B61A0 3C01802B */  lui       $at, %hi(D_802B6784)
/* E276B4 802B61A4 C4226784 */  lwc1      $f2, %lo(D_802B6784)($at)
/* E276B8 802B61A8 46200020 */  cvt.s.d   $f0, $f0
/* E276BC 802B61AC 4600103E */  c.le.s    $f2, $f0
/* E276C0 802B61B0 00000000 */  nop
/* E276C4 802B61B4 45000002 */  bc1f      .L802B61C0
/* E276C8 802B61B8 E4400000 */   swc1     $f0, ($v0)
/* E276CC 802B61BC E4420000 */  swc1      $f2, ($v0)
.L802B61C0:
/* E276D0 802B61C0 C6000054 */  lwc1      $f0, 0x54($s0)
/* E276D4 802B61C4 C4420000 */  lwc1      $f2, ($v0)
/* E276D8 802B61C8 46020000 */  add.s     $f0, $f0, $f2
/* E276DC 802B61CC 3C01802B */  lui       $at, %hi(D_802B6788)
/* E276E0 802B61D0 C4226788 */  lwc1      $f2, %lo(D_802B6788)($at)
/* E276E4 802B61D4 4600103E */  c.le.s    $f2, $f0
/* E276E8 802B61D8 00000000 */  nop
/* E276EC 802B61DC 45000002 */  bc1f      .L802B61E8
/* E276F0 802B61E0 E6000054 */   swc1     $f0, 0x54($s0)
/* E276F4 802B61E4 E6020054 */  swc1      $f2, 0x54($s0)
.L802B61E8:
/* E276F8 802B61E8 0200202D */  daddu     $a0, $s0, $zero
/* E276FC 802B61EC 27A50028 */  addiu     $a1, $sp, 0x28
/* E27700 802B61F0 27A6002C */  addiu     $a2, $sp, 0x2c
/* E27704 802B61F4 27A70030 */  addiu     $a3, $sp, 0x30
/* E27708 802B61F8 3C11802B */  lui       $s1, %hi(D_802B6798)
/* E2770C 802B61FC 26316798 */  addiu     $s1, $s1, %lo(D_802B6798)
/* E27710 802B6200 C6000028 */  lwc1      $f0, 0x28($s0)
/* E27714 802B6204 860200B0 */  lh        $v0, 0xb0($s0)
/* E27718 802B6208 3C0142C8 */  lui       $at, 0x42c8
/* E2771C 802B620C 44813000 */  mtc1      $at, $f6
/* E27720 802B6210 44821000 */  mtc1      $v0, $f2
/* E27724 802B6214 00000000 */  nop
/* E27728 802B6218 468010A0 */  cvt.s.w   $f2, $f2
/* E2772C 802B621C E7A00028 */  swc1      $f0, 0x28($sp)
/* E27730 802B6220 3C013F00 */  lui       $at, 0x3f00
/* E27734 802B6224 44810000 */  mtc1      $at, $f0
/* E27738 802B6228 C6040030 */  lwc1      $f4, 0x30($s0)
/* E2773C 802B622C 46001082 */  mul.s     $f2, $f2, $f0
/* E27740 802B6230 00000000 */  nop
/* E27744 802B6234 E7A60034 */  swc1      $f6, 0x34($sp)
/* E27748 802B6238 E7A40030 */  swc1      $f4, 0x30($sp)
/* E2774C 802B623C C600002C */  lwc1      $f0, 0x2c($s0)
/* E27750 802B6240 3C12802B */  lui       $s2, %hi(D_802B6794)
/* E27754 802B6244 26526794 */  addiu     $s2, $s2, %lo(D_802B6794)
/* E27758 802B6248 46020000 */  add.s     $f0, $f0, $f2
/* E2775C 802B624C C6220000 */  lwc1      $f2, ($s1)
/* E27760 802B6250 27A20034 */  addiu     $v0, $sp, 0x34
/* E27764 802B6254 E6420000 */  swc1      $f2, ($s2)
/* E27768 802B6258 E7A0002C */  swc1      $f0, 0x2c($sp)
/* E2776C 802B625C AFA20010 */  sw        $v0, 0x10($sp)
/* E27770 802B6260 27A20038 */  addiu     $v0, $sp, 0x38
/* E27774 802B6264 AFA20014 */  sw        $v0, 0x14($sp)
/* E27778 802B6268 27A2003C */  addiu     $v0, $sp, 0x3c
/* E2777C 802B626C AFA20018 */  sw        $v0, 0x18($sp)
/* E27780 802B6270 27A20040 */  addiu     $v0, $sp, 0x40
/* E27784 802B6274 AFA2001C */  sw        $v0, 0x1c($sp)
/* E27788 802B6278 27A20044 */  addiu     $v0, $sp, 0x44
/* E2778C 802B627C 0C03791B */  jal       player_raycast_below_cam_relative
/* E27790 802B6280 AFA20020 */   sw       $v0, 0x20($sp)
/* E27794 802B6284 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* E27798 802B6288 AFA20048 */  sw        $v0, 0x48($sp)
/* E2779C 802B628C 04400023 */  bltz      $v0, .L802B631C
/* E277A0 802B6290 E6200000 */   swc1     $f0, ($s1)
/* E277A4 802B6294 0C016F6A */  jal       get_collider_type_by_id
/* E277A8 802B6298 0040202D */   daddu    $a0, $v0, $zero
/* E277AC 802B629C 304200FF */  andi      $v0, $v0, 0xff
/* E277B0 802B62A0 24030005 */  addiu     $v1, $zero, 5
/* E277B4 802B62A4 1443000F */  bne       $v0, $v1, .L802B62E4
/* E277B8 802B62A8 00000000 */   nop
/* E277BC 802B62AC 3C028016 */  lui       $v0, %hi(gCollisionStatus)
/* E277C0 802B62B0 2442A550 */  addiu     $v0, $v0, %lo(gCollisionStatus)
/* E277C4 802B62B4 97A3004A */  lhu       $v1, 0x4a($sp)
/* E277C8 802B62B8 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* E277CC 802B62BC 3C014334 */  lui       $at, 0x4334
/* E277D0 802B62C0 44811000 */  mtc1      $at, $f2
/* E277D4 802B62C4 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* E277D8 802B62C8 46020000 */  add.s     $f0, $f0, $f2
/* E277DC 802B62CC A4430002 */  sh        $v1, 2($v0)
/* E277E0 802B62D0 E604002C */  swc1      $f4, 0x2c($s0)
/* E277E4 802B62D4 3C01802B */  lui       $at, %hi(D_802B6790)
/* E277E8 802B62D8 E4206790 */  swc1      $f0, %lo(D_802B6790)($at)
/* E277EC 802B62DC 080AD9C7 */  j         .L802B671C
/* E277F0 802B62E0 00000000 */   nop
.L802B62E4:
/* E277F4 802B62E4 C6400000 */  lwc1      $f0, ($s2)
/* E277F8 802B62E8 C6220000 */  lwc1      $f2, ($s1)
/* E277FC 802B62EC 46020001 */  sub.s     $f0, $f0, $f2
/* E27800 802B62F0 3C014049 */  lui       $at, 0x4049
/* E27804 802B62F4 44811800 */  mtc1      $at, $f3
/* E27808 802B62F8 44801000 */  mtc1      $zero, $f2
/* E2780C 802B62FC 46000021 */  cvt.d.s   $f0, $f0
/* E27810 802B6300 46200005 */  abs.d     $f0, $f0
/* E27814 802B6304 4620103E */  c.le.d    $f2, $f0
/* E27818 802B6308 00000000 */  nop
/* E2781C 802B630C 45010004 */  bc1t      .L802B6320
/* E27820 802B6310 24020002 */   addiu    $v0, $zero, 2
/* E27824 802B6314 080AD8C8 */  j         .L802B6320
/* E27828 802B6318 24020001 */   addiu    $v0, $zero, 1
.L802B631C:
/* E2782C 802B631C 24020002 */  addiu     $v0, $zero, 2
.L802B6320:
/* E27830 802B6320 A20200B6 */  sb        $v0, 0xb6($s0)
/* E27834 802B6324 3C01802B */  lui       $at, %hi(D_802B6790)
/* E27838 802B6328 C42C6790 */  lwc1      $f12, %lo(D_802B6790)($at)
/* E2783C 802B632C 3C0140C9 */  lui       $at, 0x40c9
/* E27840 802B6330 34210FD0 */  ori       $at, $at, 0xfd0
/* E27844 802B6334 44810000 */  mtc1      $at, $f0
/* E27848 802B6338 00000000 */  nop
/* E2784C 802B633C 46006302 */  mul.s     $f12, $f12, $f0
/* E27850 802B6340 00000000 */  nop
/* E27854 802B6344 27A5004C */  addiu     $a1, $sp, 0x4c
/* E27858 802B6348 3C0143B4 */  lui       $at, 0x43b4
/* E2785C 802B634C 44810000 */  mtc1      $at, $f0
/* E27860 802B6350 27A60050 */  addiu     $a2, $sp, 0x50
/* E27864 802B6354 0C00A82D */  jal       sin_cos_rad
/* E27868 802B6358 46006303 */   div.s    $f12, $f12, $f0
/* E2786C 802B635C C7A0004C */  lwc1      $f0, 0x4c($sp)
/* E27870 802B6360 C7A20050 */  lwc1      $f2, 0x50($sp)
/* E27874 802B6364 C6040054 */  lwc1      $f4, 0x54($s0)
/* E27878 802B6368 46020003 */  div.s     $f0, $f0, $f2
/* E2787C 802B636C 46040002 */  mul.s     $f0, $f0, $f4
/* E27880 802B6370 00000000 */  nop
/* E27884 802B6374 C602002C */  lwc1      $f2, 0x2c($s0)
/* E27888 802B6378 46000005 */  abs.s     $f0, $f0
/* E2788C 802B637C 46001080 */  add.s     $f2, $f2, $f0
/* E27890 802B6380 24040167 */  addiu     $a0, $zero, 0x167
/* E27894 802B6384 0C0154F0 */  jal       snd_stop_sound
/* E27898 802B6388 E602002C */   swc1     $f2, 0x2c($s0)
/* E2789C 802B638C 080AD9C7 */  j         .L802B671C
/* E278A0 802B6390 00000000 */   nop
glabel L802B6394_E278A4
/* E278A4 802B6394 0200202D */  daddu     $a0, $s0, $zero
/* E278A8 802B6398 27A50028 */  addiu     $a1, $sp, 0x28
/* E278AC 802B639C 27A6002C */  addiu     $a2, $sp, 0x2c
/* E278B0 802B63A0 27A70030 */  addiu     $a3, $sp, 0x30
/* E278B4 802B63A4 860200B0 */  lh        $v0, 0xb0($s0)
/* E278B8 802B63A8 3C013F00 */  lui       $at, 0x3f00
/* E278BC 802B63AC 44810000 */  mtc1      $at, $f0
/* E278C0 802B63B0 C6040028 */  lwc1      $f4, 0x28($s0)
/* E278C4 802B63B4 3C014248 */  lui       $at, 0x4248
/* E278C8 802B63B8 44813000 */  mtc1      $at, $f6
/* E278CC 802B63BC 44821000 */  mtc1      $v0, $f2
/* E278D0 802B63C0 00000000 */  nop
/* E278D4 802B63C4 468010A0 */  cvt.s.w   $f2, $f2
/* E278D8 802B63C8 46001082 */  mul.s     $f2, $f2, $f0
/* E278DC 802B63CC 00000000 */  nop
/* E278E0 802B63D0 27A20034 */  addiu     $v0, $sp, 0x34
/* E278E4 802B63D4 E7A40028 */  swc1      $f4, 0x28($sp)
/* E278E8 802B63D8 C600002C */  lwc1      $f0, 0x2c($s0)
/* E278EC 802B63DC C6040030 */  lwc1      $f4, 0x30($s0)
/* E278F0 802B63E0 46020000 */  add.s     $f0, $f0, $f2
/* E278F4 802B63E4 E7A60034 */  swc1      $f6, 0x34($sp)
/* E278F8 802B63E8 E7A40030 */  swc1      $f4, 0x30($sp)
/* E278FC 802B63EC E7A0002C */  swc1      $f0, 0x2c($sp)
/* E27900 802B63F0 AFA20010 */  sw        $v0, 0x10($sp)
/* E27904 802B63F4 27A20038 */  addiu     $v0, $sp, 0x38
/* E27908 802B63F8 AFA20014 */  sw        $v0, 0x14($sp)
/* E2790C 802B63FC 27A2003C */  addiu     $v0, $sp, 0x3c
/* E27910 802B6400 AFA20018 */  sw        $v0, 0x18($sp)
/* E27914 802B6404 27A20040 */  addiu     $v0, $sp, 0x40
/* E27918 802B6408 AFA2001C */  sw        $v0, 0x1c($sp)
/* E2791C 802B640C 27A20044 */  addiu     $v0, $sp, 0x44
/* E27920 802B6410 0C03791B */  jal       player_raycast_below_cam_relative
/* E27924 802B6414 AFA20020 */   sw       $v0, 0x20($sp)
/* E27928 802B6418 04400023 */  bltz      $v0, L802B64A8_E279B8
/* E2792C 802B641C AFA20048 */   sw       $v0, 0x48($sp)
/* E27930 802B6420 C6020054 */  lwc1      $f2, 0x54($s0)
/* E27934 802B6424 3C014040 */  lui       $at, 0x4040
/* E27938 802B6428 44810000 */  mtc1      $at, $f0
/* E2793C 802B642C 00000000 */  nop
/* E27940 802B6430 46001203 */  div.s     $f8, $f2, $f0
/* E27944 802B6434 3C01802B */  lui       $at, %hi(D_802B6768_E27C78)
/* E27948 802B6438 D4226768 */  ldc1      $f2, %lo(D_802B6768_E27C78)($at)
/* E2794C 802B643C 46004021 */  cvt.d.s   $f0, $f8
/* E27950 802B6440 4622003C */  c.lt.d    $f0, $f2
/* E27954 802B6444 00000000 */  nop
/* E27958 802B6448 45030001 */  bc1tl     .L802B6450
/* E2795C 802B644C AE000054 */   sw       $zero, 0x54($s0)
.L802B6450:
/* E27960 802B6450 C6000054 */  lwc1      $f0, 0x54($s0)
/* E27964 802B6454 46080001 */  sub.s     $f0, $f0, $f8
/* E27968 802B6458 4480A000 */  mtc1      $zero, $f20
/* E2796C 802B645C 00000000 */  nop
/* E27970 802B6460 4614003E */  c.le.s    $f0, $f20
/* E27974 802B6464 00000000 */  nop
/* E27978 802B6468 450000AC */  bc1f      .L802B671C
/* E2797C 802B646C E6000054 */   swc1     $f0, 0x54($s0)
/* E27980 802B6470 24040172 */  addiu     $a0, $zero, 0x172
/* E27984 802B6474 0C052736 */  jal       sfx_play_sound_at_player
/* E27988 802B6478 0000282D */   daddu    $a1, $zero, $zero
/* E2798C 802B647C 3C040001 */  lui       $a0, 1
/* E27990 802B6480 0C037FDE */  jal       suggest_player_anim_setUnkFlag
/* E27994 802B6484 34840031 */   ori      $a0, $a0, 0x31
/* E27998 802B6488 24020006 */  addiu     $v0, $zero, 6
/* E2799C 802B648C A20200B6 */  sb        $v0, 0xb6($s0)
/* E279A0 802B6490 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* E279A4 802B6494 2402000F */  addiu     $v0, $zero, 0xf
/* E279A8 802B6498 A6020008 */  sh        $v0, 8($s0)
/* E279AC 802B649C E6140054 */  swc1      $f20, 0x54($s0)
/* E279B0 802B64A0 080AD9C7 */  j         .L802B671C
/* E279B4 802B64A4 E600002C */   swc1     $f0, 0x2c($s0)
glabel L802B64A8_E279B8
/* E279B8 802B64A8 C6000054 */  lwc1      $f0, 0x54($s0)
/* E279BC 802B64AC 3C01802B */  lui       $at, %hi(D_802B678C)
/* E279C0 802B64B0 C422678C */  lwc1      $f2, %lo(D_802B678C)($at)
/* E279C4 802B64B4 46020000 */  add.s     $f0, $f0, $f2
/* E279C8 802B64B8 44802000 */  mtc1      $zero, $f4
/* E279CC 802B64BC 00000000 */  nop
/* E279D0 802B64C0 4604003E */  c.le.s    $f0, $f4
/* E279D4 802B64C4 00000000 */  nop
/* E279D8 802B64C8 45000002 */  bc1f      .L802B64D4
/* E279DC 802B64CC E6000054 */   swc1     $f0, 0x54($s0)
/* E279E0 802B64D0 E6040054 */  swc1      $f4, 0x54($s0)
.L802B64D4:
/* E279E4 802B64D4 C6000070 */  lwc1      $f0, 0x70($s0)
/* E279E8 802B64D8 C6020074 */  lwc1      $f2, 0x74($s0)
/* E279EC 802B64DC 46020000 */  add.s     $f0, $f0, $f2
/* E279F0 802B64E0 C602002C */  lwc1      $f2, 0x2c($s0)
/* E279F4 802B64E4 46001080 */  add.s     $f2, $f2, $f0
/* E279F8 802B64E8 4604003E */  c.le.s    $f0, $f4
/* E279FC 802B64EC E6000070 */  swc1      $f0, 0x70($s0)
/* E27A00 802B64F0 4500008A */  bc1f      .L802B671C
/* E27A04 802B64F4 E602002C */   swc1     $f2, 0x2c($s0)
/* E27A08 802B64F8 3C013DEA */  lui       $at, 0x3dea
/* E27A0C 802B64FC 3421161E */  ori       $at, $at, 0x161e
/* E27A10 802B6500 44810000 */  mtc1      $at, $f0
/* E27A14 802B6504 3C01BE92 */  lui       $at, 0xbe92
/* E27A18 802B6508 3421FEC5 */  ori       $at, $at, 0xfec5
/* E27A1C 802B650C 44811000 */  mtc1      $at, $f2
/* E27A20 802B6510 3C01BE3A */  lui       $at, 0xbe3a
/* E27A24 802B6514 3421ACDA */  ori       $at, $at, 0xacda
/* E27A28 802B6518 44812000 */  mtc1      $at, $f4
/* E27A2C 802B651C 3C013C3C */  lui       $at, 0x3c3c
/* E27A30 802B6520 3421BE62 */  ori       $at, $at, 0xbe62
/* E27A34 802B6524 44813000 */  mtc1      $at, $f6
/* E27A38 802B6528 24020003 */  addiu     $v0, $zero, 3
/* E27A3C 802B652C A20200B6 */  sb        $v0, 0xb6($s0)
/* E27A40 802B6530 E6000070 */  swc1      $f0, 0x70($s0)
/* E27A44 802B6534 E6020074 */  swc1      $f2, 0x74($s0)
/* E27A48 802B6538 E6040078 */  swc1      $f4, 0x78($s0)
/* E27A4C 802B653C 080AD9C7 */  j         .L802B671C
/* E27A50 802B6540 E606007C */   swc1     $f6, 0x7c($s0)
glabel L802B6544_E27A54
/* E27A54 802B6544 3C11802B */  lui       $s1, %hi(D_802B678C)
/* E27A58 802B6548 2631678C */  addiu     $s1, $s1, %lo(D_802B678C)
/* E27A5C 802B654C C6000054 */  lwc1      $f0, 0x54($s0)
/* E27A60 802B6550 C6220000 */  lwc1      $f2, ($s1)
/* E27A64 802B6554 46020000 */  add.s     $f0, $f0, $f2
/* E27A68 802B6558 44801000 */  mtc1      $zero, $f2
/* E27A6C 802B655C 00000000 */  nop
/* E27A70 802B6560 4602003E */  c.le.s    $f0, $f2
/* E27A74 802B6564 00000000 */  nop
/* E27A78 802B6568 45000002 */  bc1f      .L802B6574
/* E27A7C 802B656C E6000054 */   swc1     $f0, 0x54($s0)
/* E27A80 802B6570 E6020054 */  swc1      $f2, 0x54($s0)
.L802B6574:
/* E27A84 802B6574 0C038D36 */  jal       func_800E34D8
/* E27A88 802B6578 00000000 */   nop
/* E27A8C 802B657C 46000306 */  mov.s     $f12, $f0
/* E27A90 802B6580 0C038D45 */  jal       player_check_collision_below
/* E27A94 802B6584 27A50048 */   addiu    $a1, $sp, 0x48
/* E27A98 802B6588 8FA20048 */  lw        $v0, 0x48($sp)
/* E27A9C 802B658C 04400063 */  bltz      $v0, .L802B671C
/* E27AA0 802B6590 E600002C */   swc1     $f0, 0x2c($s0)
/* E27AA4 802B6594 3C040008 */  lui       $a0, 8
/* E27AA8 802B6598 3C01BF80 */  lui       $at, 0xbf80
/* E27AAC 802B659C 44810000 */  mtc1      $at, $f0
/* E27AB0 802B65A0 34840003 */  ori       $a0, $a0, 3
/* E27AB4 802B65A4 0C037FDE */  jal       suggest_player_anim_setUnkFlag
/* E27AB8 802B65A8 E6200000 */   swc1     $f0, ($s1)
/* E27ABC 802B65AC 24040162 */  addiu     $a0, $zero, 0x162
/* E27AC0 802B65B0 0C052736 */  jal       sfx_play_sound_at_player
/* E27AC4 802B65B4 0000282D */   daddu    $a1, $zero, $zero
/* E27AC8 802B65B8 080AD9AC */  j         .L802B66B0
/* E27ACC 802B65BC 00000000 */   nop
glabel L802B65C0_E27AD0
/* E27AD0 802B65C0 C6000054 */  lwc1      $f0, 0x54($s0)
/* E27AD4 802B65C4 3C01802B */  lui       $at, %hi(D_802B678C)
/* E27AD8 802B65C8 C422678C */  lwc1      $f2, %lo(D_802B678C)($at)
/* E27ADC 802B65CC 46020000 */  add.s     $f0, $f0, $f2
/* E27AE0 802B65D0 44801000 */  mtc1      $zero, $f2
/* E27AE4 802B65D4 00000000 */  nop
/* E27AE8 802B65D8 4602003E */  c.le.s    $f0, $f2
/* E27AEC 802B65DC 00000000 */  nop
/* E27AF0 802B65E0 45000002 */  bc1f      .L802B65EC
/* E27AF4 802B65E4 E6000054 */   swc1     $f0, 0x54($s0)
/* E27AF8 802B65E8 E6020054 */  swc1      $f2, 0x54($s0)
.L802B65EC:
/* E27AFC 802B65EC 960200BC */  lhu       $v0, 0xbc($s0)
/* E27B00 802B65F0 1040004A */  beqz      $v0, .L802B671C
/* E27B04 802B65F4 00000000 */   nop
/* E27B08 802B65F8 3C040001 */  lui       $a0, 1
/* E27B0C 802B65FC 0C037FDE */  jal       suggest_player_anim_setUnkFlag
/* E27B10 802B6600 34840030 */   ori      $a0, $a0, 0x30
/* E27B14 802B6604 080AD9AC */  j         .L802B66B0
/* E27B18 802B6608 00000000 */   nop
glabel L802B660C_E27B1C
/* E27B1C 802B660C C6000054 */  lwc1      $f0, 0x54($s0)
/* E27B20 802B6610 3C01802B */  lui       $at, %hi(D_802B678C)
/* E27B24 802B6614 C422678C */  lwc1      $f2, %lo(D_802B678C)($at)
/* E27B28 802B6618 46020000 */  add.s     $f0, $f0, $f2
/* E27B2C 802B661C 44801000 */  mtc1      $zero, $f2
/* E27B30 802B6620 00000000 */  nop
/* E27B34 802B6624 4602003E */  c.le.s    $f0, $f2
/* E27B38 802B6628 00000000 */  nop
/* E27B3C 802B662C 45000002 */  bc1f      .L802B6638
/* E27B40 802B6630 E6000054 */   swc1     $f0, 0x54($s0)
/* E27B44 802B6634 E6020054 */  swc1      $f2, 0x54($s0)
.L802B6638:
/* E27B48 802B6638 960200BC */  lhu       $v0, 0xbc($s0)
/* E27B4C 802B663C 10400037 */  beqz      $v0, .L802B671C
/* E27B50 802B6640 00000000 */   nop
/* E27B54 802B6644 3C040001 */  lui       $a0, 1
/* E27B58 802B6648 0C037FDE */  jal       suggest_player_anim_setUnkFlag
/* E27B5C 802B664C 34840031 */   ori      $a0, $a0, 0x31
/* E27B60 802B6650 24040172 */  addiu     $a0, $zero, 0x172
/* E27B64 802B6654 0C052736 */  jal       sfx_play_sound_at_player
/* E27B68 802B6658 0000282D */   daddu    $a1, $zero, $zero
/* E27B6C 802B665C 920200B6 */  lbu       $v0, 0xb6($s0)
/* E27B70 802B6660 2403000F */  addiu     $v1, $zero, 0xf
/* E27B74 802B6664 080AD9AD */  j         .L802B66B4
/* E27B78 802B6668 A6030008 */   sh       $v1, 8($s0)
glabel L802B666C_E27B7C
/* E27B7C 802B666C C6000054 */  lwc1      $f0, 0x54($s0)
/* E27B80 802B6670 3C01802B */  lui       $at, %hi(D_802B678C)
/* E27B84 802B6674 C422678C */  lwc1      $f2, %lo(D_802B678C)($at)
/* E27B88 802B6678 46020000 */  add.s     $f0, $f0, $f2
/* E27B8C 802B667C 44801000 */  mtc1      $zero, $f2
/* E27B90 802B6680 00000000 */  nop
/* E27B94 802B6684 4602003E */  c.le.s    $f0, $f2
/* E27B98 802B6688 00000000 */  nop
/* E27B9C 802B668C 45000002 */  bc1f      .L802B6698
/* E27BA0 802B6690 E6000054 */   swc1     $f0, 0x54($s0)
/* E27BA4 802B6694 E6020054 */  swc1      $f2, 0x54($s0)
.L802B6698:
/* E27BA8 802B6698 96020008 */  lhu       $v0, 8($s0)
/* E27BAC 802B669C 2442FFFF */  addiu     $v0, $v0, -1
/* E27BB0 802B66A0 A6020008 */  sh        $v0, 8($s0)
/* E27BB4 802B66A4 00021400 */  sll       $v0, $v0, 0x10
/* E27BB8 802B66A8 1440001C */  bnez      $v0, .L802B671C
/* E27BBC 802B66AC 00000000 */   nop
.L802B66B0:
/* E27BC0 802B66B0 920200B6 */  lbu       $v0, 0xb6($s0)
.L802B66B4:
/* E27BC4 802B66B4 24420001 */  addiu     $v0, $v0, 1
/* E27BC8 802B66B8 080AD9C7 */  j         .L802B671C
/* E27BCC 802B66BC A20200B6 */   sb       $v0, 0xb6($s0)
glabel L802B66C0_E27BD0
/* E27BD0 802B66C0 C6020054 */  lwc1      $f2, 0x54($s0)
/* E27BD4 802B66C4 3C014040 */  lui       $at, 0x4040
/* E27BD8 802B66C8 44810000 */  mtc1      $at, $f0
/* E27BDC 802B66CC 00000000 */  nop
/* E27BE0 802B66D0 46001203 */  div.s     $f8, $f2, $f0
/* E27BE4 802B66D4 3C01802B */  lui       $at, %hi(D_802B6770_E27C80)
/* E27BE8 802B66D8 D4226770 */  ldc1      $f2, %lo(D_802B6770_E27C80)($at)
/* E27BEC 802B66DC 46004021 */  cvt.d.s   $f0, $f8
/* E27BF0 802B66E0 4622003C */  c.lt.d    $f0, $f2
/* E27BF4 802B66E4 00000000 */  nop
/* E27BF8 802B66E8 45030001 */  bc1tl     .L802B66F0
/* E27BFC 802B66EC AE000054 */   sw       $zero, 0x54($s0)
.L802B66F0:
/* E27C00 802B66F0 C6000054 */  lwc1      $f0, 0x54($s0)
/* E27C04 802B66F4 46080001 */  sub.s     $f0, $f0, $f8
/* E27C08 802B66F8 44801000 */  mtc1      $zero, $f2
/* E27C0C 802B66FC 00000000 */  nop
/* E27C10 802B6700 4602003E */  c.le.s    $f0, $f2
/* E27C14 802B6704 00000000 */  nop
/* E27C18 802B6708 45000004 */  bc1f      .L802B671C
/* E27C1C 802B670C E6000054 */   swc1     $f0, 0x54($s0)
/* E27C20 802B6710 E6020054 */  swc1      $f2, 0x54($s0)
/* E27C24 802B6714 0C039769 */  jal       set_action_state
/* E27C28 802B6718 0000202D */   daddu    $a0, $zero, $zero
.L802B671C:
/* E27C2C 802B671C 8FBF0064 */  lw        $ra, 0x64($sp)
/* E27C30 802B6720 8FB20060 */  lw        $s2, 0x60($sp)
/* E27C34 802B6724 8FB1005C */  lw        $s1, 0x5c($sp)
/* E27C38 802B6728 8FB00058 */  lw        $s0, 0x58($sp)
/* E27C3C 802B672C D7B40068 */  ldc1      $f20, 0x68($sp)
/* E27C40 802B6730 03E00008 */  jr        $ra
/* E27C44 802B6734 27BD0070 */   addiu    $sp, $sp, 0x70
/* E27C48 802B6738 00000000 */  nop
/* E27C4C 802B673C 00000000 */  nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B60A4_E29514
/* E29514 802B60A4 27BDFF98 */  addiu     $sp, $sp, -0x68
/* E29518 802B60A8 AFB30034 */  sw        $s3, 0x34($sp)
/* E2951C 802B60AC 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* E29520 802B60B0 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* E29524 802B60B4 AFBF003C */  sw        $ra, 0x3c($sp)
/* E29528 802B60B8 AFB40038 */  sw        $s4, 0x38($sp)
/* E2952C 802B60BC AFB20030 */  sw        $s2, 0x30($sp)
/* E29530 802B60C0 AFB1002C */  sw        $s1, 0x2c($sp)
/* E29534 802B60C4 AFB00028 */  sw        $s0, 0x28($sp)
/* E29538 802B60C8 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* E2953C 802B60CC F7BA0058 */  sdc1      $f26, 0x58($sp)
/* E29540 802B60D0 F7B80050 */  sdc1      $f24, 0x50($sp)
/* E29544 802B60D4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* E29548 802B60D8 F7B40040 */  sdc1      $f20, 0x40($sp)
/* E2954C 802B60DC 8E650000 */  lw        $a1, ($s3)
/* E29550 802B60E0 04A10032 */  bgez      $a1, .L802B61AC
/* E29554 802B60E4 3C037FFF */   lui      $v1, 0x7fff
/* E29558 802B60E8 3463FFFF */  ori       $v1, $v1, 0xffff
/* E2955C 802B60EC 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* E29560 802B60F0 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* E29564 802B60F4 8C820000 */  lw        $v0, ($a0)
/* E29568 802B60F8 00A31824 */  and       $v1, $a1, $v1
/* E2956C 802B60FC AE630000 */  sw        $v1, ($s3)
/* E29570 802B6100 34420040 */  ori       $v0, $v0, 0x40
/* E29574 802B6104 0C03BCC0 */  jal       func_800EF300
/* E29578 802B6108 AC820000 */   sw       $v0, ($a0)
/* E2957C 802B610C C660002C */  lwc1      $f0, 0x2c($s3)
/* E29580 802B6110 3C014040 */  lui       $at, 0x4040
/* E29584 802B6114 44811000 */  mtc1      $at, $f2
/* E29588 802B6118 24020001 */  addiu     $v0, $zero, 1
/* E2958C 802B611C A26200B6 */  sb        $v0, 0xb6($s3)
/* E29590 802B6120 A6600008 */  sh        $zero, 8($s3)
/* E29594 802B6124 3C01802B */  lui       $at, %hi(D_802B6EE4)
/* E29598 802B6128 AC206EE4 */  sw        $zero, %lo(D_802B6EE4)($at)
/* E2959C 802B612C 3C01802B */  lui       $at, %hi(D_802B6EE8)
/* E295A0 802B6130 AC206EE8 */  sw        $zero, %lo(D_802B6EE8)($at)
/* E295A4 802B6134 3C01802B */  lui       $at, %hi(D_802B6EF4)
/* E295A8 802B6138 E4206EF4 */  swc1      $f0, %lo(D_802B6EF4)($at)
/* E295AC 802B613C 3C01802B */  lui       $at, %hi(D_802B6EDC)
/* E295B0 802B6140 E4226EDC */  swc1      $f2, %lo(D_802B6EDC)($at)
/* E295B4 802B6144 0C038045 */  jal       disable_player_static_collisions
/* E295B8 802B6148 00000000 */   nop
/* E295BC 802B614C 0C03805E */  jal       disable_player_input
/* E295C0 802B6150 00000000 */   nop
/* E295C4 802B6154 3C030010 */  lui       $v1, 0x10
/* E295C8 802B6158 8E620000 */  lw        $v0, ($s3)
/* E295CC 802B615C 3C048016 */  lui       $a0, %hi(gCollisionStatus+0x2)
/* E295D0 802B6160 8484A552 */  lh        $a0, %lo(gCollisionStatus+0x2)($a0)
/* E295D4 802B6164 00431025 */  or        $v0, $v0, $v1
/* E295D8 802B6168 3C03802B */  lui       $v1, %hi(D_802B6ED0)
/* E295DC 802B616C 24636ED0 */  addiu     $v1, $v1, %lo(D_802B6ED0)
/* E295E0 802B6170 AE620000 */  sw        $v0, ($s3)
/* E295E4 802B6174 04800004 */  bltz      $a0, .L802B6188
/* E295E8 802B6178 AFA40020 */   sw       $a0, 0x20($sp)
/* E295EC 802B617C 30824000 */  andi      $v0, $a0, 0x4000
/* E295F0 802B6180 14400002 */  bnez      $v0, .L802B618C
/* E295F4 802B6184 308203FF */   andi     $v0, $a0, 0x3ff
.L802B6188:
/* E295F8 802B6188 2402FFFF */  addiu     $v0, $zero, -1
.L802B618C:
/* E295FC 802B618C AC620000 */  sw        $v0, ($v1)
/* E29600 802B6190 8E620004 */  lw        $v0, 4($s3)
/* E29604 802B6194 30420003 */  andi      $v0, $v0, 3
/* E29608 802B6198 14400004 */  bnez      $v0, .L802B61AC
/* E2960C 802B619C 00000000 */   nop
/* E29610 802B61A0 3C040001 */  lui       $a0, 1
/* E29614 802B61A4 0C037FBF */  jal       func_800DFEFC
/* E29618 802B61A8 3484002B */   ori      $a0, $a0, 0x2b
.L802B61AC:
/* E2961C 802B61AC 826300B6 */  lb        $v1, 0xb6($s3)
/* E29620 802B61B0 24020001 */  addiu     $v0, $zero, 1
/* E29624 802B61B4 10620005 */  beq       $v1, $v0, .L802B61CC
/* E29628 802B61B8 24020002 */   addiu    $v0, $zero, 2
/* E2962C 802B61BC 106200F6 */  beq       $v1, $v0, .L802B6598
/* E29630 802B61C0 00000000 */   nop
/* E29634 802B61C4 080AD9D6 */  j         .L802B6758
/* E29638 802B61C8 00000000 */   nop
.L802B61CC:
/* E2963C 802B61CC 3C04802B */  lui       $a0, %hi(D_802B6EE4)
/* E29640 802B61D0 24846EE4 */  addiu     $a0, $a0, %lo(D_802B6EE4)
/* E29644 802B61D4 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* E29648 802B61D8 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* E2964C 802B61DC C4800000 */  lwc1      $f0, ($a0)
/* E29650 802B61E0 3C013F80 */  lui       $at, 0x3f80
/* E29654 802B61E4 4481E000 */  mtc1      $at, $f28
/* E29658 802B61E8 8C620000 */  lw        $v0, ($v1)
/* E2965C 802B61EC 3C0141A0 */  lui       $at, 0x41a0
/* E29660 802B61F0 44811000 */  mtc1      $at, $f2
/* E29664 802B61F4 461C0000 */  add.s     $f0, $f0, $f28
/* E29668 802B61F8 34420040 */  ori       $v0, $v0, 0x40
/* E2966C 802B61FC AC620000 */  sw        $v0, ($v1)
/* E29670 802B6200 4600103E */  c.le.s    $f2, $f0
/* E29674 802B6204 00000000 */  nop
/* E29678 802B6208 45000002 */  bc1f      .L802B6214
/* E2967C 802B620C E4800000 */   swc1     $f0, ($a0)
/* E29680 802B6210 E4820000 */  swc1      $f2, ($a0)
.L802B6214:
/* E29684 802B6214 C66000A8 */  lwc1      $f0, 0xa8($s3)
/* E29688 802B6218 C48C0000 */  lwc1      $f12, ($a0)
/* E2968C 802B621C 0C00A6C9 */  jal       clamp_angle
/* E29690 802B6220 460C0300 */   add.s    $f12, $f0, $f12
/* E29694 802B6224 86620008 */  lh        $v0, 8($s3)
/* E29698 802B6228 96630008 */  lhu       $v1, 8($s3)
/* E2969C 802B622C 2842000A */  slti      $v0, $v0, 0xa
/* E296A0 802B6230 10400008 */  beqz      $v0, .L802B6254
/* E296A4 802B6234 E66000A8 */   swc1     $f0, 0xa8($s3)
/* E296A8 802B6238 3C02802B */  lui       $v0, %hi(D_802B6EF4)
/* E296AC 802B623C 24426EF4 */  addiu     $v0, $v0, %lo(D_802B6EF4)
/* E296B0 802B6240 C4400000 */  lwc1      $f0, ($v0)
/* E296B4 802B6244 461C0000 */  add.s     $f0, $f0, $f28
/* E296B8 802B6248 24630001 */  addiu     $v1, $v1, 1
/* E296BC 802B624C A6630008 */  sh        $v1, 8($s3)
/* E296C0 802B6250 E4400000 */  swc1      $f0, ($v0)
.L802B6254:
/* E296C4 802B6254 3C02802B */  lui       $v0, %hi(D_802B6EE8)
/* E296C8 802B6258 24426EE8 */  addiu     $v0, $v0, %lo(D_802B6EE8)
/* E296CC 802B625C C44C0000 */  lwc1      $f12, ($v0)
/* E296D0 802B6260 3C014100 */  lui       $at, 0x4100
/* E296D4 802B6264 44810000 */  mtc1      $at, $f0
/* E296D8 802B6268 00000000 */  nop
/* E296DC 802B626C 46006300 */  add.s     $f12, $f12, $f0
/* E296E0 802B6270 3C0140C9 */  lui       $at, 0x40c9
/* E296E4 802B6274 34210FD0 */  ori       $at, $at, 0xfd0
/* E296E8 802B6278 4481A000 */  mtc1      $at, $f20
/* E296EC 802B627C 0C00A6C9 */  jal       clamp_angle
/* E296F0 802B6280 E44C0000 */   swc1     $f12, ($v0)
/* E296F4 802B6284 46140002 */  mul.s     $f0, $f0, $f20
/* E296F8 802B6288 00000000 */  nop
/* E296FC 802B628C 3C0143B4 */  lui       $at, 0x43b4
/* E29700 802B6290 4481B000 */  mtc1      $at, $f22
/* E29704 802B6294 3C014080 */  lui       $at, 0x4080
/* E29708 802B6298 4481D000 */  mtc1      $at, $f26
/* E2970C 802B629C 0C00A85B */  jal       sin_rad
/* E29710 802B62A0 46160303 */   div.s    $f12, $f0, $f22
/* E29714 802B62A4 461A0002 */  mul.s     $f0, $f0, $f26
/* E29718 802B62A8 00000000 */  nop
/* E2971C 802B62AC 3C01802B */  lui       $at, %hi(D_802B6EF4)
/* E29720 802B62B0 C4226EF4 */  lwc1      $f2, %lo(D_802B6EF4)($at)
/* E29724 802B62B4 46001080 */  add.s     $f2, $f2, $f0
/* E29728 802B62B8 3C04802B */  lui       $a0, %hi(D_802B6ED0)
/* E2972C 802B62BC 8C846ED0 */  lw        $a0, %lo(D_802B6ED0)($a0)
/* E29730 802B62C0 04800042 */  bltz      $a0, .L802B63CC
/* E29734 802B62C4 E662002C */   swc1     $f2, 0x2c($s3)
/* E29738 802B62C8 0C04417A */  jal       get_entity_by_index
/* E2973C 802B62CC 00000000 */   nop
/* E29740 802B62D0 0040902D */  daddu     $s2, $v0, $zero
/* E29744 802B62D4 C64C0048 */  lwc1      $f12, 0x48($s2)
/* E29748 802B62D8 C64E0050 */  lwc1      $f14, 0x50($s2)
/* E2974C 802B62DC 8E660028 */  lw        $a2, 0x28($s3)
/* E29750 802B62E0 0C00A7B5 */  jal       dist2D
/* E29754 802B62E4 8E670030 */   lw       $a3, 0x30($s3)
/* E29758 802B62E8 C64C0048 */  lwc1      $f12, 0x48($s2)
/* E2975C 802B62EC C64E0050 */  lwc1      $f14, 0x50($s2)
/* E29760 802B62F0 8E660028 */  lw        $a2, 0x28($s3)
/* E29764 802B62F4 8E670030 */  lw        $a3, 0x30($s3)
/* E29768 802B62F8 0C00A720 */  jal       atan2
/* E2976C 802B62FC 46000606 */   mov.s    $f24, $f0
/* E29770 802B6300 3C14802B */  lui       $s4, %hi(D_802B6EEC)
/* E29774 802B6304 26946EEC */  addiu     $s4, $s4, %lo(D_802B6EEC)
/* E29778 802B6308 4618D03C */  c.lt.s    $f26, $f24
/* E2977C 802B630C 00000000 */  nop
/* E29780 802B6310 45000002 */  bc1f      .L802B631C
/* E29784 802B6314 E6800000 */   swc1     $f0, ($s4)
/* E29788 802B6318 461CC601 */  sub.s     $f24, $f24, $f28
.L802B631C:
/* E2978C 802B631C 46140302 */  mul.s     $f12, $f0, $f20
/* E29790 802B6320 00000000 */  nop
/* E29794 802B6324 27B00010 */  addiu     $s0, $sp, 0x10
/* E29798 802B6328 0200282D */  daddu     $a1, $s0, $zero
/* E2979C 802B632C 27B10014 */  addiu     $s1, $sp, 0x14
/* E297A0 802B6330 0220302D */  daddu     $a2, $s1, $zero
/* E297A4 802B6334 0C00A82D */  jal       sin_cos_rad
/* E297A8 802B6338 46166303 */   div.s    $f12, $f12, $f22
/* E297AC 802B633C C7A20010 */  lwc1      $f2, 0x10($sp)
/* E297B0 802B6340 46181082 */  mul.s     $f2, $f2, $f24
/* E297B4 802B6344 00000000 */  nop
/* E297B8 802B6348 C7A40014 */  lwc1      $f4, 0x14($sp)
/* E297BC 802B634C 46182102 */  mul.s     $f4, $f4, $f24
/* E297C0 802B6350 00000000 */  nop
/* E297C4 802B6354 C68C0000 */  lwc1      $f12, ($s4)
/* E297C8 802B6358 3C0142B6 */  lui       $at, 0x42b6
/* E297CC 802B635C 44810000 */  mtc1      $at, $f0
/* E297D0 802B6360 00000000 */  nop
/* E297D4 802B6364 46006301 */  sub.s     $f12, $f12, $f0
/* E297D8 802B6368 C6400048 */  lwc1      $f0, 0x48($s2)
/* E297DC 802B636C 46020000 */  add.s     $f0, $f0, $f2
/* E297E0 802B6370 46146302 */  mul.s     $f12, $f12, $f20
/* E297E4 802B6374 00000000 */  nop
/* E297E8 802B6378 E6600028 */  swc1      $f0, 0x28($s3)
/* E297EC 802B637C C6400050 */  lwc1      $f0, 0x50($s2)
/* E297F0 802B6380 0200282D */  daddu     $a1, $s0, $zero
/* E297F4 802B6384 46040001 */  sub.s     $f0, $f0, $f4
/* E297F8 802B6388 0220302D */  daddu     $a2, $s1, $zero
/* E297FC 802B638C 46166303 */  div.s     $f12, $f12, $f22
/* E29800 802B6390 0C00A82D */  jal       sin_cos_rad
/* E29804 802B6394 E6600030 */   swc1     $f0, 0x30($s3)
/* E29808 802B6398 C7A20010 */  lwc1      $f2, 0x10($sp)
/* E2980C 802B639C 3C01802B */  lui       $at, %hi(D_802B6EDC)
/* E29810 802B63A0 C4246EDC */  lwc1      $f4, %lo(D_802B6EDC)($at)
/* E29814 802B63A4 46041082 */  mul.s     $f2, $f2, $f4
/* E29818 802B63A8 00000000 */  nop
/* E2981C 802B63AC C7A00014 */  lwc1      $f0, 0x14($sp)
/* E29820 802B63B0 46000007 */  neg.s     $f0, $f0
/* E29824 802B63B4 46040002 */  mul.s     $f0, $f0, $f4
/* E29828 802B63B8 00000000 */  nop
/* E2982C 802B63BC 3C01802B */  lui       $at, %hi(D_802B6ED4)
/* E29830 802B63C0 E4226ED4 */  swc1      $f2, %lo(D_802B6ED4)($at)
/* E29834 802B63C4 3C01802B */  lui       $at, %hi(D_802B6ED8)
/* E29838 802B63C8 E4206ED8 */  swc1      $f0, %lo(D_802B6ED8)($at)
.L802B63CC:
/* E2983C 802B63CC 27A40018 */  addiu     $a0, $sp, 0x18
/* E29840 802B63D0 0C0388FF */  jal       func_800E23FC
/* E29844 802B63D4 27A5001C */   addiu    $a1, $sp, 0x1c
/* E29848 802B63D8 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* E2984C 802B63DC 44800000 */  mtc1      $zero, $f0
/* E29850 802B63E0 00000000 */  nop
/* E29854 802B63E4 46001032 */  c.eq.s    $f2, $f0
/* E29858 802B63E8 00000000 */  nop
/* E2985C 802B63EC 4501002C */  bc1t      .L802B64A0
/* E29860 802B63F0 27A50010 */   addiu    $a1, $sp, 0x10
/* E29864 802B63F4 C7AC0018 */  lwc1      $f12, 0x18($sp)
/* E29868 802B63F8 3C0140C9 */  lui       $at, 0x40c9
/* E2986C 802B63FC 34210FD0 */  ori       $at, $at, 0xfd0
/* E29870 802B6400 44810000 */  mtc1      $at, $f0
/* E29874 802B6404 00000000 */  nop
/* E29878 802B6408 46006302 */  mul.s     $f12, $f12, $f0
/* E2987C 802B640C 00000000 */  nop
/* E29880 802B6410 3C0143B4 */  lui       $at, 0x43b4
/* E29884 802B6414 44810000 */  mtc1      $at, $f0
/* E29888 802B6418 27A60014 */  addiu     $a2, $sp, 0x14
/* E2988C 802B641C 0C00A82D */  jal       sin_cos_rad
/* E29890 802B6420 46006303 */   div.s    $f12, $f12, $f0
/* E29894 802B6424 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* E29898 802B6428 3C013D00 */  lui       $at, 0x3d00
/* E2989C 802B642C 44810000 */  mtc1      $at, $f0
/* E298A0 802B6430 00000000 */  nop
/* E298A4 802B6434 46002102 */  mul.s     $f4, $f4, $f0
/* E298A8 802B6438 00000000 */  nop
/* E298AC 802B643C 3C01802B */  lui       $at, %hi(D_802B6E90_E2A300)
/* E298B0 802B6440 D4226E90 */  ldc1      $f2, %lo(D_802B6E90_E2A300)($at)
/* E298B4 802B6444 46002021 */  cvt.d.s   $f0, $f4
/* E298B8 802B6448 4622003C */  c.lt.d    $f0, $f2
/* E298BC 802B644C 00000000 */  nop
/* E298C0 802B6450 45000006 */  bc1f      .L802B646C
/* E298C4 802B6454 E7A4001C */   swc1     $f4, 0x1c($sp)
/* E298C8 802B6458 3C013DCC */  lui       $at, 0x3dcc
/* E298CC 802B645C 3421CCCD */  ori       $at, $at, 0xcccd
/* E298D0 802B6460 44810000 */  mtc1      $at, $f0
/* E298D4 802B6464 00000000 */  nop
/* E298D8 802B6468 E7A0001C */  swc1      $f0, 0x1c($sp)
.L802B646C:
/* E298DC 802B646C C7A00010 */  lwc1      $f0, 0x10($sp)
/* E298E0 802B6470 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* E298E4 802B6474 46020002 */  mul.s     $f0, $f0, $f2
/* E298E8 802B6478 00000000 */  nop
/* E298EC 802B647C C7A40014 */  lwc1      $f4, 0x14($sp)
/* E298F0 802B6480 46022102 */  mul.s     $f4, $f4, $f2
/* E298F4 802B6484 00000000 */  nop
/* E298F8 802B6488 C6620028 */  lwc1      $f2, 0x28($s3)
/* E298FC 802B648C 46001080 */  add.s     $f2, $f2, $f0
/* E29900 802B6490 C6600030 */  lwc1      $f0, 0x30($s3)
/* E29904 802B6494 46040001 */  sub.s     $f0, $f0, $f4
/* E29908 802B6498 E6620028 */  swc1      $f2, 0x28($s3)
/* E2990C 802B649C E6600030 */  swc1      $f0, 0x30($s3)
.L802B64A0:
/* E29910 802B64A0 C6600028 */  lwc1      $f0, 0x28($s3)
/* E29914 802B64A4 C662002C */  lwc1      $f2, 0x2c($s3)
/* E29918 802B64A8 C6640030 */  lwc1      $f4, 0x30($s3)
/* E2991C 802B64AC 3C02800B */  lui       $v0, %hi(gCameras)
/* E29920 802B64B0 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* E29924 802B64B4 E4400060 */  swc1      $f0, 0x60($v0)
/* E29928 802B64B8 E4420064 */  swc1      $f2, 0x64($v0)
/* E2992C 802B64BC 0C0AD800 */  jal       func_802B6000_E29470
/* E29930 802B64C0 E4440068 */   swc1     $f4, 0x68($v0)
/* E29934 802B64C4 04400004 */  bltz      $v0, .L802B64D8
/* E29938 802B64C8 AFA20020 */   sw       $v0, 0x20($sp)
/* E2993C 802B64CC 30424000 */  andi      $v0, $v0, 0x4000
/* E29940 802B64D0 14400014 */  bnez      $v0, .L802B6524
/* E29944 802B64D4 00000000 */   nop
.L802B64D8:
/* E29948 802B64D8 C660002C */  lwc1      $f0, 0x2c($s3)
/* E2994C 802B64DC 24020014 */  addiu     $v0, $zero, 0x14
/* E29950 802B64E0 A6620008 */  sh        $v0, 8($s3)
/* E29954 802B64E4 3C01802B */  lui       $at, %hi(D_802B6EE8)
/* E29958 802B64E8 AC206EE8 */  sw        $zero, %lo(D_802B6EE8)($at)
/* E2995C 802B64EC 3C01802B */  lui       $at, %hi(D_802B6EF4)
/* E29960 802B64F0 E4206EF4 */  swc1      $f0, %lo(D_802B6EF4)($at)
/* E29964 802B64F4 926200B6 */  lbu       $v0, 0xb6($s3)
/* E29968 802B64F8 3C013FCC */  lui       $at, 0x3fcc
/* E2996C 802B64FC 3421CCCD */  ori       $at, $at, 0xcccd
/* E29970 802B6500 44810000 */  mtc1      $at, $f0
/* E29974 802B6504 24420001 */  addiu     $v0, $v0, 1
/* E29978 802B6508 A26200B6 */  sb        $v0, 0xb6($s3)
/* E2997C 802B650C 8E620000 */  lw        $v0, ($s3)
/* E29980 802B6510 3C030080 */  lui       $v1, 0x80
/* E29984 802B6514 3C01802B */  lui       $at, %hi(D_802B6EF0)
/* E29988 802B6518 E4206EF0 */  swc1      $f0, %lo(D_802B6EF0)($at)
/* E2998C 802B651C 00431025 */  or        $v0, $v0, $v1
/* E29990 802B6520 AE620000 */  sw        $v0, ($s3)
.L802B6524:
/* E29994 802B6524 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E29998 802B6528 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E2999C 802B652C 8C420010 */  lw        $v0, 0x10($v0)
/* E299A0 802B6530 30422000 */  andi      $v0, $v0, 0x2000
/* E299A4 802B6534 10400088 */  beqz      $v0, .L802B6758
/* E299A8 802B6538 00000000 */   nop
/* E299AC 802B653C 8E620004 */  lw        $v0, 4($s3)
/* E299B0 802B6540 30420003 */  andi      $v0, $v0, 3
/* E299B4 802B6544 14400084 */  bnez      $v0, .L802B6758
/* E299B8 802B6548 3C040001 */   lui      $a0, 1
/* E299BC 802B654C 0C037FDE */  jal       func_800DFF78
/* E299C0 802B6550 34840007 */   ori      $a0, $a0, 7
/* E299C4 802B6554 3C04802B */  lui       $a0, %hi(D_802B6ED0)
/* E299C8 802B6558 8C846ED0 */  lw        $a0, %lo(D_802B6ED0)($a0)
/* E299CC 802B655C 24020003 */  addiu     $v0, $zero, 3
/* E299D0 802B6560 A26200B6 */  sb        $v0, 0xb6($s3)
/* E299D4 802B6564 2402001E */  addiu     $v0, $zero, 0x1e
/* E299D8 802B6568 A6620008 */  sh        $v0, 8($s3)
/* E299DC 802B656C 2402FFFF */  addiu     $v0, $zero, -1
/* E299E0 802B6570 3C01802B */  lui       $at, %hi(D_802B6EE0)
/* E299E4 802B6574 AC206EE0 */  sw        $zero, %lo(D_802B6EE0)($at)
/* E299E8 802B6578 3C018016 */  lui       $at, %hi(gCollisionStatus+0x2)
/* E299EC 802B657C A422A552 */  sh        $v0, %lo(gCollisionStatus+0x2)($at)
/* E299F0 802B6580 0C04417A */  jal       get_entity_by_index
/* E299F4 802B6584 00000000 */   nop
/* E299F8 802B6588 0C043F5A */  jal       exec_entity_updatecmd
/* E299FC 802B658C 0040202D */   daddu    $a0, $v0, $zero
/* E29A00 802B6590 080AD9D6 */  j         .L802B6758
/* E29A04 802B6594 00000000 */   nop
.L802B6598:
/* E29A08 802B6598 3C04802B */  lui       $a0, %hi(D_802B6EE4)
/* E29A0C 802B659C 24846EE4 */  addiu     $a0, $a0, %lo(D_802B6EE4)
/* E29A10 802B65A0 3C11800A */  lui       $s1, %hi(gOverrideFlags)
/* E29A14 802B65A4 2631A650 */  addiu     $s1, $s1, %lo(gOverrideFlags)
/* E29A18 802B65A8 C4800000 */  lwc1      $f0, ($a0)
/* E29A1C 802B65AC 3C013F80 */  lui       $at, 0x3f80
/* E29A20 802B65B0 44811000 */  mtc1      $at, $f2
/* E29A24 802B65B4 8E220000 */  lw        $v0, ($s1)
/* E29A28 802B65B8 46020001 */  sub.s     $f0, $f0, $f2
/* E29A2C 802B65BC 44801000 */  mtc1      $zero, $f2
/* E29A30 802B65C0 34420040 */  ori       $v0, $v0, 0x40
/* E29A34 802B65C4 AE220000 */  sw        $v0, ($s1)
/* E29A38 802B65C8 4602003C */  c.lt.s    $f0, $f2
/* E29A3C 802B65CC 00000000 */  nop
/* E29A40 802B65D0 45000007 */  bc1f      .L802B65F0
/* E29A44 802B65D4 E4800000 */   swc1     $f0, ($a0)
/* E29A48 802B65D8 3C03FFEF */  lui       $v1, 0xffef
/* E29A4C 802B65DC 8E620000 */  lw        $v0, ($s3)
/* E29A50 802B65E0 3463FFFF */  ori       $v1, $v1, 0xffff
/* E29A54 802B65E4 E4820000 */  swc1      $f2, ($a0)
/* E29A58 802B65E8 00431024 */  and       $v0, $v0, $v1
/* E29A5C 802B65EC AE620000 */  sw        $v0, ($s3)
.L802B65F0:
/* E29A60 802B65F0 C66000A8 */  lwc1      $f0, 0xa8($s3)
/* E29A64 802B65F4 C48C0000 */  lwc1      $f12, ($a0)
/* E29A68 802B65F8 0C00A6C9 */  jal       clamp_angle
/* E29A6C 802B65FC 460C0300 */   add.s    $f12, $f0, $f12
/* E29A70 802B6600 3C01802B */  lui       $at, %hi(D_802B6EEC)
/* E29A74 802B6604 C42C6EEC */  lwc1      $f12, %lo(D_802B6EEC)($at)
/* E29A78 802B6608 3C014270 */  lui       $at, 0x4270
/* E29A7C 802B660C 44811000 */  mtc1      $at, $f2
/* E29A80 802B6610 00000000 */  nop
/* E29A84 802B6614 46026301 */  sub.s     $f12, $f12, $f2
/* E29A88 802B6618 3C0140C9 */  lui       $at, 0x40c9
/* E29A8C 802B661C 34210FD0 */  ori       $at, $at, 0xfd0
/* E29A90 802B6620 44811000 */  mtc1      $at, $f2
/* E29A94 802B6624 00000000 */  nop
/* E29A98 802B6628 46026302 */  mul.s     $f12, $f12, $f2
/* E29A9C 802B662C 00000000 */  nop
/* E29AA0 802B6630 27A50010 */  addiu     $a1, $sp, 0x10
/* E29AA4 802B6634 3C0143B4 */  lui       $at, 0x43b4
/* E29AA8 802B6638 44811000 */  mtc1      $at, $f2
/* E29AAC 802B663C 27A60014 */  addiu     $a2, $sp, 0x14
/* E29AB0 802B6640 E66000A8 */  swc1      $f0, 0xa8($s3)
/* E29AB4 802B6644 0C00A82D */  jal       sin_cos_rad
/* E29AB8 802B6648 46026303 */   div.s    $f12, $f12, $f2
/* E29ABC 802B664C 3C02802B */  lui       $v0, %hi(D_802B6EDC)
/* E29AC0 802B6650 24426EDC */  addiu     $v0, $v0, %lo(D_802B6EDC)
/* E29AC4 802B6654 C4400000 */  lwc1      $f0, ($v0)
/* E29AC8 802B6658 3C01802B */  lui       $at, %hi(D_802B6E98_E2A308)
/* E29ACC 802B665C D4226E98 */  ldc1      $f2, %lo(D_802B6E98_E2A308)($at)
/* E29AD0 802B6660 46000021 */  cvt.d.s   $f0, $f0
/* E29AD4 802B6664 46220000 */  add.d     $f0, $f0, $f2
/* E29AD8 802B6668 C7A80010 */  lwc1      $f8, 0x10($sp)
/* E29ADC 802B666C 46200020 */  cvt.s.d   $f0, $f0
/* E29AE0 802B6670 46004202 */  mul.s     $f8, $f8, $f0
/* E29AE4 802B6674 00000000 */  nop
/* E29AE8 802B6678 3C10802B */  lui       $s0, %hi(D_802B6EF0)
/* E29AEC 802B667C 26106EF0 */  addiu     $s0, $s0, %lo(D_802B6EF0)
/* E29AF0 802B6680 C6020000 */  lwc1      $f2, ($s0)
/* E29AF4 802B6684 3C01802B */  lui       $at, %hi(D_802B6EA0_E2A310)
/* E29AF8 802B6688 D4246EA0 */  ldc1      $f4, %lo(D_802B6EA0_E2A310)($at)
/* E29AFC 802B668C 460010A1 */  cvt.d.s   $f2, $f2
/* E29B00 802B6690 46241081 */  sub.d     $f2, $f2, $f4
/* E29B04 802B6694 C7A40014 */  lwc1      $f4, 0x14($sp)
/* E29B08 802B6698 46002107 */  neg.s     $f4, $f4
/* E29B0C 802B669C 46002102 */  mul.s     $f4, $f4, $f0
/* E29B10 802B66A0 00000000 */  nop
/* E29B14 802B66A4 E4400000 */  swc1      $f0, ($v0)
/* E29B18 802B66A8 C6600028 */  lwc1      $f0, 0x28($s3)
/* E29B1C 802B66AC C6660030 */  lwc1      $f6, 0x30($s3)
/* E29B20 802B66B0 46080000 */  add.s     $f0, $f0, $f8
/* E29B24 802B66B4 462010A0 */  cvt.s.d   $f2, $f2
/* E29B28 802B66B8 E6020000 */  swc1      $f2, ($s0)
/* E29B2C 802B66BC 46043180 */  add.s     $f6, $f6, $f4
/* E29B30 802B66C0 3C01802B */  lui       $at, %hi(D_802B6ED4)
/* E29B34 802B66C4 E4286ED4 */  swc1      $f8, %lo(D_802B6ED4)($at)
/* E29B38 802B66C8 3C01802B */  lui       $at, %hi(D_802B6ED8)
/* E29B3C 802B66CC E4246ED8 */  swc1      $f4, %lo(D_802B6ED8)($at)
/* E29B40 802B66D0 E6600028 */  swc1      $f0, 0x28($s3)
/* E29B44 802B66D4 0C0392EE */  jal       func_800E4BB8
/* E29B48 802B66D8 E6660030 */   swc1     $f6, 0x30($s3)
/* E29B4C 802B66DC C60C0000 */  lwc1      $f12, ($s0)
/* E29B50 802B66E0 0C038D45 */  jal       func_800E3514
/* E29B54 802B66E4 27A50020 */   addiu    $a1, $sp, 0x20
/* E29B58 802B66E8 E660002C */  swc1      $f0, 0x2c($s3)
/* E29B5C 802B66EC C6600028 */  lwc1      $f0, 0x28($s3)
/* E29B60 802B66F0 C662002C */  lwc1      $f2, 0x2c($s3)
/* E29B64 802B66F4 C6640030 */  lwc1      $f4, 0x30($s3)
/* E29B68 802B66F8 8FA30020 */  lw        $v1, 0x20($sp)
/* E29B6C 802B66FC 3C02800B */  lui       $v0, %hi(gCameras)
/* E29B70 802B6700 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* E29B74 802B6704 E4400060 */  swc1      $f0, 0x60($v0)
/* E29B78 802B6708 E4420064 */  swc1      $f2, 0x64($v0)
/* E29B7C 802B670C 04600012 */  bltz      $v1, .L802B6758
/* E29B80 802B6710 E4440068 */   swc1     $f4, 0x68($v0)
/* E29B84 802B6714 3C03FFEF */  lui       $v1, 0xffef
/* E29B88 802B6718 8E620000 */  lw        $v0, ($s3)
/* E29B8C 802B671C 3463FFFF */  ori       $v1, $v1, 0xffff
/* E29B90 802B6720 00431024 */  and       $v0, $v0, $v1
/* E29B94 802B6724 0C038069 */  jal       enable_player_input
/* E29B98 802B6728 AE620000 */   sw       $v0, ($s3)
/* E29B9C 802B672C 0C038050 */  jal       enable_player_static_collisions
/* E29BA0 802B6730 00000000 */   nop
/* E29BA4 802B6734 0C039769 */  jal       set_action_state
/* E29BA8 802B6738 2404000A */   addiu    $a0, $zero, 0xa
/* E29BAC 802B673C 0C03BCCA */  jal       enable_partner_ai
/* E29BB0 802B6740 00000000 */   nop
/* E29BB4 802B6744 8E220000 */  lw        $v0, ($s1)
/* E29BB8 802B6748 2403FFBF */  addiu     $v1, $zero, -0x41
/* E29BBC 802B674C 00431024 */  and       $v0, $v0, $v1
/* E29BC0 802B6750 080ADB96 */  j         L802B6E58_E2A2C8
/* E29BC4 802B6754 AE220000 */   sw       $v0, ($s1)
.L802B6758:
/* E29BC8 802B6758 926200B6 */  lbu       $v0, 0xb6($s3)
/* E29BCC 802B675C 2442FFFD */  addiu     $v0, $v0, -3
/* E29BD0 802B6760 00021600 */  sll       $v0, $v0, 0x18
/* E29BD4 802B6764 00021E03 */  sra       $v1, $v0, 0x18
/* E29BD8 802B6768 2C620009 */  sltiu     $v0, $v1, 9
/* E29BDC 802B676C 104001BA */  beqz      $v0, L802B6E58_E2A2C8
/* E29BE0 802B6770 00031080 */   sll      $v0, $v1, 2
/* E29BE4 802B6774 3C01802B */  lui       $at, %hi(jtbl_802B6EA8_E2A318)
/* E29BE8 802B6778 00220821 */  addu      $at, $at, $v0
/* E29BEC 802B677C 8C226EA8 */  lw        $v0, %lo(jtbl_802B6EA8_E2A318)($at)
/* E29BF0 802B6780 00400008 */  jr        $v0
/* E29BF4 802B6784 00000000 */   nop
glabel L802B6788_E29BF8
/* E29BF8 802B6788 3C04802B */  lui       $a0, %hi(D_802B6ED0)
/* E29BFC 802B678C 8C846ED0 */  lw        $a0, %lo(D_802B6ED0)($a0)
/* E29C00 802B6790 0480004D */  bltz      $a0, .L802B68C8
/* E29C04 802B6794 00000000 */   nop
/* E29C08 802B6798 0C04417A */  jal       get_entity_by_index
/* E29C0C 802B679C 00000000 */   nop
/* E29C10 802B67A0 0040902D */  daddu     $s2, $v0, $zero
/* E29C14 802B67A4 C44C0048 */  lwc1      $f12, 0x48($v0)
/* E29C18 802B67A8 C64E0050 */  lwc1      $f14, 0x50($s2)
/* E29C1C 802B67AC 8E660028 */  lw        $a2, 0x28($s3)
/* E29C20 802B67B0 0C00A7B5 */  jal       dist2D
/* E29C24 802B67B4 8E670030 */   lw       $a3, 0x30($s3)
/* E29C28 802B67B8 C64C0048 */  lwc1      $f12, 0x48($s2)
/* E29C2C 802B67BC C64E0050 */  lwc1      $f14, 0x50($s2)
/* E29C30 802B67C0 8E660028 */  lw        $a2, 0x28($s3)
/* E29C34 802B67C4 8E670030 */  lw        $a3, 0x30($s3)
/* E29C38 802B67C8 0C00A720 */  jal       atan2
/* E29C3C 802B67CC 46000606 */   mov.s    $f24, $f0
/* E29C40 802B67D0 46000306 */  mov.s     $f12, $f0
/* E29C44 802B67D4 3C014080 */  lui       $at, 0x4080
/* E29C48 802B67D8 44810000 */  mtc1      $at, $f0
/* E29C4C 802B67DC 3C14802B */  lui       $s4, %hi(D_802B6EEC)
/* E29C50 802B67E0 26946EEC */  addiu     $s4, $s4, %lo(D_802B6EEC)
/* E29C54 802B67E4 4618003C */  c.lt.s    $f0, $f24
/* E29C58 802B67E8 00000000 */  nop
/* E29C5C 802B67EC 45000005 */  bc1f      .L802B6804
/* E29C60 802B67F0 E68C0000 */   swc1     $f12, ($s4)
/* E29C64 802B67F4 3C013F80 */  lui       $at, 0x3f80
/* E29C68 802B67F8 44810000 */  mtc1      $at, $f0
/* E29C6C 802B67FC 00000000 */  nop
/* E29C70 802B6800 4600C601 */  sub.s     $f24, $f24, $f0
.L802B6804:
/* E29C74 802B6804 3C0140C9 */  lui       $at, 0x40c9
/* E29C78 802B6808 34210FD0 */  ori       $at, $at, 0xfd0
/* E29C7C 802B680C 4481A000 */  mtc1      $at, $f20
/* E29C80 802B6810 27B10010 */  addiu     $s1, $sp, 0x10
/* E29C84 802B6814 46146302 */  mul.s     $f12, $f12, $f20
/* E29C88 802B6818 00000000 */  nop
/* E29C8C 802B681C 0220282D */  daddu     $a1, $s1, $zero
/* E29C90 802B6820 27B00014 */  addiu     $s0, $sp, 0x14
/* E29C94 802B6824 3C0143B4 */  lui       $at, 0x43b4
/* E29C98 802B6828 4481B000 */  mtc1      $at, $f22
/* E29C9C 802B682C 0200302D */  daddu     $a2, $s0, $zero
/* E29CA0 802B6830 0C00A82D */  jal       sin_cos_rad
/* E29CA4 802B6834 46166303 */   div.s    $f12, $f12, $f22
/* E29CA8 802B6838 C7A20010 */  lwc1      $f2, 0x10($sp)
/* E29CAC 802B683C 46181082 */  mul.s     $f2, $f2, $f24
/* E29CB0 802B6840 00000000 */  nop
/* E29CB4 802B6844 C7A40014 */  lwc1      $f4, 0x14($sp)
/* E29CB8 802B6848 46182102 */  mul.s     $f4, $f4, $f24
/* E29CBC 802B684C 00000000 */  nop
/* E29CC0 802B6850 C68C0000 */  lwc1      $f12, ($s4)
/* E29CC4 802B6854 3C0142B6 */  lui       $at, 0x42b6
/* E29CC8 802B6858 44810000 */  mtc1      $at, $f0
/* E29CCC 802B685C 00000000 */  nop
/* E29CD0 802B6860 46006301 */  sub.s     $f12, $f12, $f0
/* E29CD4 802B6864 C6400048 */  lwc1      $f0, 0x48($s2)
/* E29CD8 802B6868 46020000 */  add.s     $f0, $f0, $f2
/* E29CDC 802B686C 46146302 */  mul.s     $f12, $f12, $f20
/* E29CE0 802B6870 00000000 */  nop
/* E29CE4 802B6874 E6600028 */  swc1      $f0, 0x28($s3)
/* E29CE8 802B6878 C6400050 */  lwc1      $f0, 0x50($s2)
/* E29CEC 802B687C 0220282D */  daddu     $a1, $s1, $zero
/* E29CF0 802B6880 46040001 */  sub.s     $f0, $f0, $f4
/* E29CF4 802B6884 0200302D */  daddu     $a2, $s0, $zero
/* E29CF8 802B6888 46166303 */  div.s     $f12, $f12, $f22
/* E29CFC 802B688C 0C00A82D */  jal       sin_cos_rad
/* E29D00 802B6890 E6600030 */   swc1     $f0, 0x30($s3)
/* E29D04 802B6894 C7A20010 */  lwc1      $f2, 0x10($sp)
/* E29D08 802B6898 3C01802B */  lui       $at, %hi(D_802B6EDC)
/* E29D0C 802B689C C4246EDC */  lwc1      $f4, %lo(D_802B6EDC)($at)
/* E29D10 802B68A0 46041082 */  mul.s     $f2, $f2, $f4
/* E29D14 802B68A4 00000000 */  nop
/* E29D18 802B68A8 C7A00014 */  lwc1      $f0, 0x14($sp)
/* E29D1C 802B68AC 46000007 */  neg.s     $f0, $f0
/* E29D20 802B68B0 46040002 */  mul.s     $f0, $f0, $f4
/* E29D24 802B68B4 00000000 */  nop
/* E29D28 802B68B8 3C01802B */  lui       $at, %hi(D_802B6ED4)
/* E29D2C 802B68BC E4226ED4 */  swc1      $f2, %lo(D_802B6ED4)($at)
/* E29D30 802B68C0 3C01802B */  lui       $at, %hi(D_802B6ED8)
/* E29D34 802B68C4 E4206ED8 */  swc1      $f0, %lo(D_802B6ED8)($at)
.L802B68C8:
/* E29D38 802B68C8 3C02802B */  lui       $v0, %hi(D_802B6EE8)
/* E29D3C 802B68CC 24426EE8 */  addiu     $v0, $v0, %lo(D_802B6EE8)
/* E29D40 802B68D0 C44C0000 */  lwc1      $f12, ($v0)
/* E29D44 802B68D4 3C014100 */  lui       $at, 0x4100
/* E29D48 802B68D8 44810000 */  mtc1      $at, $f0
/* E29D4C 802B68DC 00000000 */  nop
/* E29D50 802B68E0 46006300 */  add.s     $f12, $f12, $f0
/* E29D54 802B68E4 0C00A6C9 */  jal       clamp_angle
/* E29D58 802B68E8 E44C0000 */   swc1     $f12, ($v0)
/* E29D5C 802B68EC 3C0140C9 */  lui       $at, 0x40c9
/* E29D60 802B68F0 34210FD0 */  ori       $at, $at, 0xfd0
/* E29D64 802B68F4 44811000 */  mtc1      $at, $f2
/* E29D68 802B68F8 00000000 */  nop
/* E29D6C 802B68FC 46020002 */  mul.s     $f0, $f0, $f2
/* E29D70 802B6900 00000000 */  nop
/* E29D74 802B6904 3C0143B4 */  lui       $at, 0x43b4
/* E29D78 802B6908 44816000 */  mtc1      $at, $f12
/* E29D7C 802B690C 0C00A85B */  jal       sin_rad
/* E29D80 802B6910 460C0303 */   div.s    $f12, $f0, $f12
/* E29D84 802B6914 3C014080 */  lui       $at, 0x4080
/* E29D88 802B6918 44811000 */  mtc1      $at, $f2
/* E29D8C 802B691C 00000000 */  nop
/* E29D90 802B6920 46020002 */  mul.s     $f0, $f0, $f2
/* E29D94 802B6924 00000000 */  nop
/* E29D98 802B6928 3C01802B */  lui       $at, %hi(D_802B6EF4)
/* E29D9C 802B692C C4226EF4 */  lwc1      $f2, %lo(D_802B6EF4)($at)
/* E29DA0 802B6930 46001080 */  add.s     $f2, $f2, $f0
/* E29DA4 802B6934 C6600030 */  lwc1      $f0, 0x30($s3)
/* E29DA8 802B6938 E662002C */  swc1      $f2, 0x2c($s3)
/* E29DAC 802B693C C6620028 */  lwc1      $f2, 0x28($s3)
/* E29DB0 802B6940 C664002C */  lwc1      $f4, 0x2c($s3)
/* E29DB4 802B6944 3C02800B */  lui       $v0, %hi(gCameras)
/* E29DB8 802B6948 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* E29DBC 802B694C E4400068 */  swc1      $f0, 0x68($v0)
/* E29DC0 802B6950 E4420060 */  swc1      $f2, 0x60($v0)
/* E29DC4 802B6954 E4440064 */  swc1      $f4, 0x64($v0)
/* E29DC8 802B6958 86620008 */  lh        $v0, 8($s3)
/* E29DCC 802B695C 96640008 */  lhu       $a0, 8($s3)
/* E29DD0 802B6960 10400016 */  beqz      $v0, .L802B69BC
/* E29DD4 802B6964 2482FFFF */   addiu    $v0, $a0, -1
/* E29DD8 802B6968 3C03802B */  lui       $v1, %hi(D_802B6EE4)
/* E29DDC 802B696C 24636EE4 */  addiu     $v1, $v1, %lo(D_802B6EE4)
/* E29DE0 802B6970 C4600000 */  lwc1      $f0, ($v1)
/* E29DE4 802B6974 3C014000 */  lui       $at, 0x4000
/* E29DE8 802B6978 44811000 */  mtc1      $at, $f2
/* E29DEC 802B697C 00000000 */  nop
/* E29DF0 802B6980 46020000 */  add.s     $f0, $f0, $f2
/* E29DF4 802B6984 3C014234 */  lui       $at, 0x4234
/* E29DF8 802B6988 44811000 */  mtc1      $at, $f2
/* E29DFC 802B698C A6620008 */  sh        $v0, 8($s3)
/* E29E00 802B6990 4600103E */  c.le.s    $f2, $f0
/* E29E04 802B6994 00000000 */  nop
/* E29E08 802B6998 45000002 */  bc1f      .L802B69A4
/* E29E0C 802B699C E4600000 */   swc1     $f0, ($v1)
/* E29E10 802B69A0 E4620000 */  swc1      $f2, ($v1)
.L802B69A4:
/* E29E14 802B69A4 C66000A8 */  lwc1      $f0, 0xa8($s3)
/* E29E18 802B69A8 C46C0000 */  lwc1      $f12, ($v1)
/* E29E1C 802B69AC 0C00A6C9 */  jal       clamp_angle
/* E29E20 802B69B0 460C0300 */   add.s    $f12, $f0, $f12
/* E29E24 802B69B4 080ADB96 */  j         L802B6E58_E2A2C8
/* E29E28 802B69B8 E66000A8 */   swc1     $f0, 0xa8($s3)
.L802B69BC:
/* E29E2C 802B69BC 926200B6 */  lbu       $v0, 0xb6($s3)
/* E29E30 802B69C0 2403001E */  addiu     $v1, $zero, 0x1e
/* E29E34 802B69C4 A6630008 */  sh        $v1, 8($s3)
/* E29E38 802B69C8 24420001 */  addiu     $v0, $v0, 1
/* E29E3C 802B69CC 0C03954C */  jal       func_800E5530
/* E29E40 802B69D0 A26200B6 */   sb       $v0, 0xb6($s3)
/* E29E44 802B69D4 080ADB96 */  j         L802B6E58_E2A2C8
/* E29E48 802B69D8 00000000 */   nop
glabel L802B69DC_E29E4C
/* E29E4C 802B69DC 3C02802B */  lui       $v0, %hi(D_802B6EE4)
/* E29E50 802B69E0 24426EE4 */  addiu     $v0, $v0, %lo(D_802B6EE4)
/* E29E54 802B69E4 C4400000 */  lwc1      $f0, ($v0)
/* E29E58 802B69E8 3C014000 */  lui       $at, 0x4000
/* E29E5C 802B69EC 4481B000 */  mtc1      $at, $f22
/* E29E60 802B69F0 00000000 */  nop
/* E29E64 802B69F4 46160000 */  add.s     $f0, $f0, $f22
/* E29E68 802B69F8 3C014234 */  lui       $at, 0x4234
/* E29E6C 802B69FC 4481A000 */  mtc1      $at, $f20
/* E29E70 802B6A00 00000000 */  nop
/* E29E74 802B6A04 4600A03E */  c.le.s    $f20, $f0
/* E29E78 802B6A08 00000000 */  nop
/* E29E7C 802B6A0C 45000002 */  bc1f      .L802B6A18
/* E29E80 802B6A10 E4400000 */   swc1     $f0, ($v0)
/* E29E84 802B6A14 E4540000 */  swc1      $f20, ($v0)
.L802B6A18:
/* E29E88 802B6A18 C66000A8 */  lwc1      $f0, 0xa8($s3)
/* E29E8C 802B6A1C C44C0000 */  lwc1      $f12, ($v0)
/* E29E90 802B6A20 0C00A6C9 */  jal       clamp_angle
/* E29E94 802B6A24 460C0300 */   add.s    $f12, $f0, $f12
/* E29E98 802B6A28 3C02802B */  lui       $v0, %hi(D_802B6EE0)
/* E29E9C 802B6A2C 24426EE0 */  addiu     $v0, $v0, %lo(D_802B6EE0)
/* E29EA0 802B6A30 C4420000 */  lwc1      $f2, ($v0)
/* E29EA4 802B6A34 46161080 */  add.s     $f2, $f2, $f22
/* E29EA8 802B6A38 E66000A8 */  swc1      $f0, 0xa8($s3)
/* E29EAC 802B6A3C 4602A03C */  c.lt.s    $f20, $f2
/* E29EB0 802B6A40 00000000 */  nop
/* E29EB4 802B6A44 45000002 */  bc1f      .L802B6A50
/* E29EB8 802B6A48 E4420000 */   swc1     $f2, ($v0)
/* E29EBC 802B6A4C E4540000 */  swc1      $f20, ($v0)
.L802B6A50:
/* E29EC0 802B6A50 C44C0000 */  lwc1      $f12, ($v0)
/* E29EC4 802B6A54 3C0140C9 */  lui       $at, 0x40c9
/* E29EC8 802B6A58 34210FD0 */  ori       $at, $at, 0xfd0
/* E29ECC 802B6A5C 4481A000 */  mtc1      $at, $f20
/* E29ED0 802B6A60 00000000 */  nop
/* E29ED4 802B6A64 46146302 */  mul.s     $f12, $f12, $f20
/* E29ED8 802B6A68 00000000 */  nop
/* E29EDC 802B6A6C 3C0143B4 */  lui       $at, 0x43b4
/* E29EE0 802B6A70 4481B000 */  mtc1      $at, $f22
/* E29EE4 802B6A74 0C00A85B */  jal       sin_rad
/* E29EE8 802B6A78 46166303 */   div.s    $f12, $f12, $f22
/* E29EEC 802B6A7C 3C10802C */  lui       $s0, %hi(D_802BCE34)
/* E29EF0 802B6A80 2610CE34 */  addiu     $s0, $s0, %lo(D_802BCE34)
/* E29EF4 802B6A84 3C11802C */  lui       $s1, %hi(D_802BCE32)
/* E29EF8 802B6A88 2631CE32 */  addiu     $s1, $s1, %lo(D_802BCE32)
/* E29EFC 802B6A8C 3C014080 */  lui       $at, 0x4080
/* E29F00 802B6A90 44811000 */  mtc1      $at, $f2
/* E29F04 802B6A94 8E660028 */  lw        $a2, 0x28($s3)
/* E29F08 802B6A98 8E670030 */  lw        $a3, 0x30($s3)
/* E29F0C 802B6A9C 46020182 */  mul.s     $f6, $f0, $f2
/* E29F10 802B6AA0 00000000 */  nop
/* E29F14 802B6AA4 86020000 */  lh        $v0, ($s0)
/* E29F18 802B6AA8 86230000 */  lh        $v1, ($s1)
/* E29F1C 802B6AAC C660002C */  lwc1      $f0, 0x2c($s3)
/* E29F20 802B6AB0 44826000 */  mtc1      $v0, $f12
/* E29F24 802B6AB4 00000000 */  nop
/* E29F28 802B6AB8 46806320 */  cvt.s.w   $f12, $f12
/* E29F2C 802B6ABC 46060000 */  add.s     $f0, $f0, $f6
/* E29F30 802B6AC0 C6620028 */  lwc1      $f2, 0x28($s3)
/* E29F34 802B6AC4 44837000 */  mtc1      $v1, $f14
/* E29F38 802B6AC8 00000000 */  nop
/* E29F3C 802B6ACC 468073A0 */  cvt.s.w   $f14, $f14
/* E29F40 802B6AD0 E660002C */  swc1      $f0, 0x2c($s3)
/* E29F44 802B6AD4 46000106 */  mov.s     $f4, $f0
/* E29F48 802B6AD8 C6600030 */  lwc1      $f0, 0x30($s3)
/* E29F4C 802B6ADC 3C02800B */  lui       $v0, %hi(gCameras)
/* E29F50 802B6AE0 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* E29F54 802B6AE4 E4420060 */  swc1      $f2, 0x60($v0)
/* E29F58 802B6AE8 E4440064 */  swc1      $f4, 0x64($v0)
/* E29F5C 802B6AEC 0C00A7B5 */  jal       dist2D
/* E29F60 802B6AF0 E4400068 */   swc1     $f0, 0x68($v0)
/* E29F64 802B6AF4 3C014220 */  lui       $at, 0x4220
/* E29F68 802B6AF8 44811000 */  mtc1      $at, $f2
/* E29F6C 802B6AFC 46000605 */  abs.s     $f24, $f0
/* E29F70 802B6B00 4618103C */  c.lt.s    $f2, $f24
/* E29F74 802B6B04 00000000 */  nop
/* E29F78 802B6B08 45000040 */  bc1f      .L802B6C0C
/* E29F7C 802B6B0C 00000000 */   nop
/* E29F80 802B6B10 3C02802C */  lui       $v0, %hi(D_802BCE30)
/* E29F84 802B6B14 8442CE30 */  lh        $v0, %lo(D_802BCE30)($v0)
/* E29F88 802B6B18 C662002C */  lwc1      $f2, 0x2c($s3)
/* E29F8C 802B6B1C 2442001E */  addiu     $v0, $v0, 0x1e
/* E29F90 802B6B20 44820000 */  mtc1      $v0, $f0
/* E29F94 802B6B24 00000000 */  nop
/* E29F98 802B6B28 46800020 */  cvt.s.w   $f0, $f0
/* E29F9C 802B6B2C 4602003C */  c.lt.s    $f0, $f2
/* E29FA0 802B6B30 00000000 */  nop
/* E29FA4 802B6B34 450000C8 */  bc1f      L802B6E58_E2A2C8
/* E29FA8 802B6B38 00000000 */   nop
/* E29FAC 802B6B3C C66C0028 */  lwc1      $f12, 0x28($s3)
/* E29FB0 802B6B40 86020000 */  lh        $v0, ($s0)
/* E29FB4 802B6B44 C66E0030 */  lwc1      $f14, 0x30($s3)
/* E29FB8 802B6B48 86230000 */  lh        $v1, ($s1)
/* E29FBC 802B6B4C 44825000 */  mtc1      $v0, $f10
/* E29FC0 802B6B50 00000000 */  nop
/* E29FC4 802B6B54 468052A0 */  cvt.s.w   $f10, $f10
/* E29FC8 802B6B58 44065000 */  mfc1      $a2, $f10
/* E29FCC 802B6B5C 44835000 */  mtc1      $v1, $f10
/* E29FD0 802B6B60 00000000 */  nop
/* E29FD4 802B6B64 468052A0 */  cvt.s.w   $f10, $f10
/* E29FD8 802B6B68 926200B6 */  lbu       $v0, 0xb6($s3)
/* E29FDC 802B6B6C 44075000 */  mfc1      $a3, $f10
/* E29FE0 802B6B70 24420001 */  addiu     $v0, $v0, 1
/* E29FE4 802B6B74 0C00A720 */  jal       atan2
/* E29FE8 802B6B78 A26200B6 */   sb       $v0, 0xb6($s3)
/* E29FEC 802B6B7C 46140302 */  mul.s     $f12, $f0, $f20
/* E29FF0 802B6B80 00000000 */  nop
/* E29FF4 802B6B84 27A50010 */  addiu     $a1, $sp, 0x10
/* E29FF8 802B6B88 27A60014 */  addiu     $a2, $sp, 0x14
/* E29FFC 802B6B8C E7A00018 */  swc1      $f0, 0x18($sp)
/* E2A000 802B6B90 0C00A82D */  jal       sin_cos_rad
/* E2A004 802B6B94 46166303 */   div.s    $f12, $f12, $f22
/* E2A008 802B6B98 C7A20010 */  lwc1      $f2, 0x10($sp)
/* E2A00C 802B6B9C 46181082 */  mul.s     $f2, $f2, $f24
/* E2A010 802B6BA0 00000000 */  nop
/* E2A014 802B6BA4 3C013F90 */  lui       $at, 0x3f90
/* E2A018 802B6BA8 44812800 */  mtc1      $at, $f5
/* E2A01C 802B6BAC 44802000 */  mtc1      $zero, $f4
/* E2A020 802B6BB0 460010A1 */  cvt.d.s   $f2, $f2
/* E2A024 802B6BB4 46241082 */  mul.d     $f2, $f2, $f4
/* E2A028 802B6BB8 00000000 */  nop
/* E2A02C 802B6BBC C7A00014 */  lwc1      $f0, 0x14($sp)
/* E2A030 802B6BC0 46000007 */  neg.s     $f0, $f0
/* E2A034 802B6BC4 46180002 */  mul.s     $f0, $f0, $f24
/* E2A038 802B6BC8 00000000 */  nop
/* E2A03C 802B6BCC 46000021 */  cvt.d.s   $f0, $f0
/* E2A040 802B6BD0 46240002 */  mul.d     $f0, $f0, $f4
/* E2A044 802B6BD4 00000000 */  nop
/* E2A048 802B6BD8 C7A40018 */  lwc1      $f4, 0x18($sp)
/* E2A04C 802B6BDC 24020040 */  addiu     $v0, $zero, 0x40
/* E2A050 802B6BE0 A6620008 */  sh        $v0, 8($s3)
/* E2A054 802B6BE4 3C01802B */  lui       $at, %hi(D_802B6EEC)
/* E2A058 802B6BE8 E4246EEC */  swc1      $f4, %lo(D_802B6EEC)($at)
/* E2A05C 802B6BEC 462010A0 */  cvt.s.d   $f2, $f2
/* E2A060 802B6BF0 46200020 */  cvt.s.d   $f0, $f0
/* E2A064 802B6BF4 3C01802B */  lui       $at, %hi(D_802B6ED4)
/* E2A068 802B6BF8 E4226ED4 */  swc1      $f2, %lo(D_802B6ED4)($at)
/* E2A06C 802B6BFC 3C01802B */  lui       $at, %hi(D_802B6ED8)
/* E2A070 802B6C00 E4206ED8 */  swc1      $f0, %lo(D_802B6ED8)($at)
/* E2A074 802B6C04 080ADB96 */  j         L802B6E58_E2A2C8
/* E2A078 802B6C08 00000000 */   nop
.L802B6C0C:
/* E2A07C 802B6C0C 86620008 */  lh        $v0, 8($s3)
/* E2A080 802B6C10 96630008 */  lhu       $v1, 8($s3)
/* E2A084 802B6C14 1440007A */  bnez      $v0, .L802B6E00
/* E2A088 802B6C18 2462FFFF */   addiu    $v0, $v1, -1
/* E2A08C 802B6C1C 2402000A */  addiu     $v0, $zero, 0xa
/* E2A090 802B6C20 A26200B6 */  sb        $v0, 0xb6($s3)
/* E2A094 802B6C24 24020014 */  addiu     $v0, $zero, 0x14
/* E2A098 802B6C28 080ADB96 */  j         L802B6E58_E2A2C8
/* E2A09C 802B6C2C A6620008 */   sh       $v0, 8($s3)
glabel L802B6C30_E2A0A0
/* E2A0A0 802B6C30 C66000A8 */  lwc1      $f0, 0xa8($s3)
/* E2A0A4 802B6C34 3C01802B */  lui       $at, %hi(D_802B6EE4)
/* E2A0A8 802B6C38 C42C6EE4 */  lwc1      $f12, %lo(D_802B6EE4)($at)
/* E2A0AC 802B6C3C 0C00A6C9 */  jal       clamp_angle
/* E2A0B0 802B6C40 460C0300 */   add.s    $f12, $f0, $f12
/* E2A0B4 802B6C44 86620008 */  lh        $v0, 8($s3)
/* E2A0B8 802B6C48 96640008 */  lhu       $a0, 8($s3)
/* E2A0BC 802B6C4C 1040002A */  beqz      $v0, .L802B6CF8
/* E2A0C0 802B6C50 E66000A8 */   swc1     $f0, 0xa8($s3)
/* E2A0C4 802B6C54 3C03802B */  lui       $v1, %hi(D_802B6EE0)
/* E2A0C8 802B6C58 24636EE0 */  addiu     $v1, $v1, %lo(D_802B6EE0)
/* E2A0CC 802B6C5C C4600000 */  lwc1      $f0, ($v1)
/* E2A0D0 802B6C60 3C013F80 */  lui       $at, 0x3f80
/* E2A0D4 802B6C64 44811000 */  mtc1      $at, $f2
/* E2A0D8 802B6C68 46000106 */  mov.s     $f4, $f0
/* E2A0DC 802B6C6C 46020001 */  sub.s     $f0, $f0, $f2
/* E2A0E0 802B6C70 44801000 */  mtc1      $zero, $f2
/* E2A0E4 802B6C74 2482FFFF */  addiu     $v0, $a0, -1
/* E2A0E8 802B6C78 A6620008 */  sh        $v0, 8($s3)
/* E2A0EC 802B6C7C 4602203C */  c.lt.s    $f4, $f2
/* E2A0F0 802B6C80 00000000 */  nop
/* E2A0F4 802B6C84 45000002 */  bc1f      .L802B6C90
/* E2A0F8 802B6C88 E4600000 */   swc1     $f0, ($v1)
/* E2A0FC 802B6C8C E4620000 */  swc1      $f2, ($v1)
.L802B6C90:
/* E2A100 802B6C90 C46C0000 */  lwc1      $f12, ($v1)
/* E2A104 802B6C94 3C0140C9 */  lui       $at, 0x40c9
/* E2A108 802B6C98 34210FD0 */  ori       $at, $at, 0xfd0
/* E2A10C 802B6C9C 44810000 */  mtc1      $at, $f0
/* E2A110 802B6CA0 00000000 */  nop
/* E2A114 802B6CA4 46006302 */  mul.s     $f12, $f12, $f0
/* E2A118 802B6CA8 00000000 */  nop
/* E2A11C 802B6CAC 3C0143B4 */  lui       $at, 0x43b4
/* E2A120 802B6CB0 44810000 */  mtc1      $at, $f0
/* E2A124 802B6CB4 0C00A85B */  jal       sin_rad
/* E2A128 802B6CB8 46006303 */   div.s    $f12, $f12, $f0
/* E2A12C 802B6CBC 46000180 */  add.s     $f6, $f0, $f0
/* E2A130 802B6CC0 C6640028 */  lwc1      $f4, 0x28($s3)
/* E2A134 802B6CC4 3C01802B */  lui       $at, %hi(D_802B6ED4)
/* E2A138 802B6CC8 C4206ED4 */  lwc1      $f0, %lo(D_802B6ED4)($at)
/* E2A13C 802B6CCC C6620030 */  lwc1      $f2, 0x30($s3)
/* E2A140 802B6CD0 46002100 */  add.s     $f4, $f4, $f0
/* E2A144 802B6CD4 3C01802B */  lui       $at, %hi(D_802B6ED8)
/* E2A148 802B6CD8 C4206ED8 */  lwc1      $f0, %lo(D_802B6ED8)($at)
/* E2A14C 802B6CDC 46001080 */  add.s     $f2, $f2, $f0
/* E2A150 802B6CE0 C660002C */  lwc1      $f0, 0x2c($s3)
/* E2A154 802B6CE4 46060000 */  add.s     $f0, $f0, $f6
/* E2A158 802B6CE8 E6640028 */  swc1      $f4, 0x28($s3)
/* E2A15C 802B6CEC E6620030 */  swc1      $f2, 0x30($s3)
/* E2A160 802B6CF0 080ADB40 */  j         .L802B6D00
/* E2A164 802B6CF4 E660002C */   swc1     $f0, 0x2c($s3)
.L802B6CF8:
/* E2A168 802B6CF8 2402000B */  addiu     $v0, $zero, 0xb
/* E2A16C 802B6CFC A26200B6 */  sb        $v0, 0xb6($s3)
.L802B6D00:
/* E2A170 802B6D00 C6600028 */  lwc1      $f0, 0x28($s3)
/* E2A174 802B6D04 C662002C */  lwc1      $f2, 0x2c($s3)
/* E2A178 802B6D08 C6640030 */  lwc1      $f4, 0x30($s3)
/* E2A17C 802B6D0C 3C02800B */  lui       $v0, %hi(gCameras)
/* E2A180 802B6D10 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* E2A184 802B6D14 E4400060 */  swc1      $f0, 0x60($v0)
/* E2A188 802B6D18 E4420064 */  swc1      $f2, 0x64($v0)
/* E2A18C 802B6D1C 080ADB96 */  j         L802B6E58_E2A2C8
/* E2A190 802B6D20 E4440068 */   swc1     $f4, 0x68($v0)
glabel L802B6D24_E2A194
/* E2A194 802B6D24 3C02802B */  lui       $v0, %hi(D_802B6EE4)
/* E2A198 802B6D28 24426EE4 */  addiu     $v0, $v0, %lo(D_802B6EE4)
/* E2A19C 802B6D2C C4400000 */  lwc1      $f0, ($v0)
/* E2A1A0 802B6D30 3C013F80 */  lui       $at, 0x3f80
/* E2A1A4 802B6D34 44811000 */  mtc1      $at, $f2
/* E2A1A8 802B6D38 00000000 */  nop
/* E2A1AC 802B6D3C 46020000 */  add.s     $f0, $f0, $f2
/* E2A1B0 802B6D40 3C014234 */  lui       $at, 0x4234
/* E2A1B4 802B6D44 4481A000 */  mtc1      $at, $f20
/* E2A1B8 802B6D48 00000000 */  nop
/* E2A1BC 802B6D4C 4600A03E */  c.le.s    $f20, $f0
/* E2A1C0 802B6D50 00000000 */  nop
/* E2A1C4 802B6D54 45000002 */  bc1f      .L802B6D60
/* E2A1C8 802B6D58 E4400000 */   swc1     $f0, ($v0)
/* E2A1CC 802B6D5C E4540000 */  swc1      $f20, ($v0)
.L802B6D60:
/* E2A1D0 802B6D60 C66000A8 */  lwc1      $f0, 0xa8($s3)
/* E2A1D4 802B6D64 C44C0000 */  lwc1      $f12, ($v0)
/* E2A1D8 802B6D68 0C00A6C9 */  jal       clamp_angle
/* E2A1DC 802B6D6C 460C0300 */   add.s    $f12, $f0, $f12
/* E2A1E0 802B6D70 3C02802B */  lui       $v0, %hi(D_802B6EE0)
/* E2A1E4 802B6D74 24426EE0 */  addiu     $v0, $v0, %lo(D_802B6EE0)
/* E2A1E8 802B6D78 C4420000 */  lwc1      $f2, ($v0)
/* E2A1EC 802B6D7C 3C014000 */  lui       $at, 0x4000
/* E2A1F0 802B6D80 44812000 */  mtc1      $at, $f4
/* E2A1F4 802B6D84 00000000 */  nop
/* E2A1F8 802B6D88 46041080 */  add.s     $f2, $f2, $f4
/* E2A1FC 802B6D8C E66000A8 */  swc1      $f0, 0xa8($s3)
/* E2A200 802B6D90 4602A03C */  c.lt.s    $f20, $f2
/* E2A204 802B6D94 00000000 */  nop
/* E2A208 802B6D98 45000002 */  bc1f      .L802B6DA4
/* E2A20C 802B6D9C E4420000 */   swc1     $f2, ($v0)
/* E2A210 802B6DA0 E4540000 */  swc1      $f20, ($v0)
.L802B6DA4:
/* E2A214 802B6DA4 C44C0000 */  lwc1      $f12, ($v0)
/* E2A218 802B6DA8 3C0140C9 */  lui       $at, 0x40c9
/* E2A21C 802B6DAC 34210FD0 */  ori       $at, $at, 0xfd0
/* E2A220 802B6DB0 44810000 */  mtc1      $at, $f0
/* E2A224 802B6DB4 00000000 */  nop
/* E2A228 802B6DB8 46006302 */  mul.s     $f12, $f12, $f0
/* E2A22C 802B6DBC 00000000 */  nop
/* E2A230 802B6DC0 3C0143B4 */  lui       $at, 0x43b4
/* E2A234 802B6DC4 44810000 */  mtc1      $at, $f0
/* E2A238 802B6DC8 0C00A85B */  jal       sin_rad
/* E2A23C 802B6DCC 46006303 */   div.s    $f12, $f12, $f0
/* E2A240 802B6DD0 3C014040 */  lui       $at, 0x4040
/* E2A244 802B6DD4 44811000 */  mtc1      $at, $f2
/* E2A248 802B6DD8 00000000 */  nop
/* E2A24C 802B6DDC 46020182 */  mul.s     $f6, $f0, $f2
/* E2A250 802B6DE0 00000000 */  nop
/* E2A254 802B6DE4 C660002C */  lwc1      $f0, 0x2c($s3)
/* E2A258 802B6DE8 86620008 */  lh        $v0, 8($s3)
/* E2A25C 802B6DEC 46060000 */  add.s     $f0, $f0, $f6
/* E2A260 802B6DF0 96630008 */  lhu       $v1, 8($s3)
/* E2A264 802B6DF4 10400004 */  beqz      $v0, L802B6E08_E2A278
/* E2A268 802B6DF8 E660002C */   swc1     $f0, 0x2c($s3)
/* E2A26C 802B6DFC 2462FFFF */  addiu     $v0, $v1, -1
.L802B6E00:
/* E2A270 802B6E00 080ADB96 */  j         L802B6E58_E2A2C8
/* E2A274 802B6E04 A6620008 */   sh       $v0, 8($s3)
glabel L802B6E08_E2A278
/* E2A278 802B6E08 0C038050 */  jal       enable_player_static_collisions
/* E2A27C 802B6E0C 00000000 */   nop
/* E2A280 802B6E10 0C038069 */  jal       enable_player_input
/* E2A284 802B6E14 00000000 */   nop
/* E2A288 802B6E18 3C03FFEF */  lui       $v1, 0xffef
/* E2A28C 802B6E1C 8E620000 */  lw        $v0, ($s3)
/* E2A290 802B6E20 3463FFFF */  ori       $v1, $v1, 0xffff
/* E2A294 802B6E24 00431024 */  and       $v0, $v0, $v1
/* E2A298 802B6E28 3C030080 */  lui       $v1, 0x80
/* E2A29C 802B6E2C 00431025 */  or        $v0, $v0, $v1
/* E2A2A0 802B6E30 0C0397F4 */  jal       start_falling
/* E2A2A4 802B6E34 AE620000 */   sw       $v0, ($s3)
/* E2A2A8 802B6E38 0C03BCCA */  jal       enable_partner_ai
/* E2A2AC 802B6E3C 00000000 */   nop
/* E2A2B0 802B6E40 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* E2A2B4 802B6E44 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* E2A2B8 802B6E48 8C820000 */  lw        $v0, ($a0)
/* E2A2BC 802B6E4C 2403FFBF */  addiu     $v1, $zero, -0x41
/* E2A2C0 802B6E50 00431024 */  and       $v0, $v0, $v1
/* E2A2C4 802B6E54 AC820000 */  sw        $v0, ($a0)
glabel L802B6E58_E2A2C8
/* E2A2C8 802B6E58 8FBF003C */  lw        $ra, 0x3c($sp)
/* E2A2CC 802B6E5C 8FB40038 */  lw        $s4, 0x38($sp)
/* E2A2D0 802B6E60 8FB30034 */  lw        $s3, 0x34($sp)
/* E2A2D4 802B6E64 8FB20030 */  lw        $s2, 0x30($sp)
/* E2A2D8 802B6E68 8FB1002C */  lw        $s1, 0x2c($sp)
/* E2A2DC 802B6E6C 8FB00028 */  lw        $s0, 0x28($sp)
/* E2A2E0 802B6E70 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* E2A2E4 802B6E74 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* E2A2E8 802B6E78 D7B80050 */  ldc1      $f24, 0x50($sp)
/* E2A2EC 802B6E7C D7B60048 */  ldc1      $f22, 0x48($sp)
/* E2A2F0 802B6E80 D7B40040 */  ldc1      $f20, 0x40($sp)
/* E2A2F4 802B6E84 03E00008 */  jr        $ra
/* E2A2F8 802B6E88 27BD0068 */   addiu    $sp, $sp, 0x68
/* E2A2FC 802B6E8C 00000000 */  nop

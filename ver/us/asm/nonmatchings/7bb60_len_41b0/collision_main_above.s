.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel collision_main_above
/* 7BC90 800E27E0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 7BC94 800E27E4 AFB10034 */  sw        $s1, 0x34($sp)
/* 7BC98 800E27E8 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 7BC9C 800E27EC 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 7BCA0 800E27F0 AFBF003C */  sw        $ra, 0x3c($sp)
/* 7BCA4 800E27F4 AFB20038 */  sw        $s2, 0x38($sp)
/* 7BCA8 800E27F8 AFB00030 */  sw        $s0, 0x30($sp)
/* 7BCAC 800E27FC F7B40040 */  sdc1      $f20, 0x40($sp)
/* 7BCB0 800E2800 862200B0 */  lh        $v0, 0xb0($s1)
/* 7BCB4 800E2804 3C013F00 */  lui       $at, 0x3f00
/* 7BCB8 800E2808 44811000 */  mtc1      $at, $f2
/* 7BCBC 800E280C 44820000 */  mtc1      $v0, $f0
/* 7BCC0 800E2810 00000000 */  nop
/* 7BCC4 800E2814 46800020 */  cvt.s.w   $f0, $f0
/* 7BCC8 800E2818 46020002 */  mul.s     $f0, $f0, $f2
/* 7BCCC 800E281C 00000000 */  nop
/* 7BCD0 800E2820 27A40018 */  addiu     $a0, $sp, 0x18
/* 7BCD4 800E2824 C6220028 */  lwc1      $f2, 0x28($s1)
/* 7BCD8 800E2828 27A5001C */  addiu     $a1, $sp, 0x1c
/* 7BCDC 800E282C E7A20020 */  swc1      $f2, 0x20($sp)
/* 7BCE0 800E2830 46000506 */  mov.s     $f20, $f0
/* 7BCE4 800E2834 C620002C */  lwc1      $f0, 0x2c($s1)
/* 7BCE8 800E2838 C6220030 */  lwc1      $f2, 0x30($s1)
/* 7BCEC 800E283C 46140000 */  add.s     $f0, $f0, $f20
/* 7BCF0 800E2840 E7A20028 */  swc1      $f2, 0x28($sp)
/* 7BCF4 800E2844 E7B4002C */  swc1      $f20, 0x2c($sp)
/* 7BCF8 800E2848 0C0388C1 */  jal       player_input_to_move_vector
/* 7BCFC 800E284C E7A00024 */   swc1     $f0, 0x24($sp)
/* 7BD00 800E2850 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* 7BD04 800E2854 44800000 */  mtc1      $zero, $f0
/* 7BD08 800E2858 3C128016 */  lui       $s2, %hi(gCollisionStatus)
/* 7BD0C 800E285C 2652A550 */  addiu     $s2, $s2, %lo(gCollisionStatus)
/* 7BD10 800E2860 46001032 */  c.eq.s    $f2, $f0
/* 7BD14 800E2864 00000000 */  nop
/* 7BD18 800E2868 45010004 */  bc1t      .L800E287C
/* 7BD1C 800E286C 0220202D */   daddu    $a0, $s1, $zero
/* 7BD20 800E2870 C6220080 */  lwc1      $f2, 0x80($s1)
/* 7BD24 800E2874 08038A31 */  j         .L800E28C4
/* 7BD28 800E2878 27A50020 */   addiu    $a1, $sp, 0x20
.L800E287C:
/* 7BD2C 800E287C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7BD30 800E2880 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 7BD34 800E2884 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 7BD38 800E2888 3C0142B4 */  lui       $at, 0x42b4
/* 7BD3C 800E288C 44810000 */  mtc1      $at, $f0
/* 7BD40 800E2890 00031080 */  sll       $v0, $v1, 2
/* 7BD44 800E2894 00431021 */  addu      $v0, $v0, $v1
/* 7BD48 800E2898 00021080 */  sll       $v0, $v0, 2
/* 7BD4C 800E289C 00431023 */  subu      $v0, $v0, $v1
/* 7BD50 800E28A0 000218C0 */  sll       $v1, $v0, 3
/* 7BD54 800E28A4 00431021 */  addu      $v0, $v0, $v1
/* 7BD58 800E28A8 000210C0 */  sll       $v0, $v0, 3
/* 7BD5C 800E28AC 46001081 */  sub.s     $f2, $f2, $f0
/* 7BD60 800E28B0 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 7BD64 800E28B4 00220821 */  addu      $at, $at, $v0
/* 7BD68 800E28B8 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 7BD6C 800E28BC 46001080 */  add.s     $f2, $f2, $f0
/* 7BD70 800E28C0 27A50020 */  addiu     $a1, $sp, 0x20
.L800E28C4:
/* 7BD74 800E28C4 27A2002C */  addiu     $v0, $sp, 0x2c
/* 7BD78 800E28C8 27A60024 */  addiu     $a2, $sp, 0x24
/* 7BD7C 800E28CC 27A70028 */  addiu     $a3, $sp, 0x28
/* 7BD80 800E28D0 E7A20018 */  swc1      $f2, 0x18($sp)
/* 7BD84 800E28D4 AFA20010 */  sw        $v0, 0x10($sp)
/* 7BD88 800E28D8 0C0379F9 */  jal       player_raycast_up_corners
/* 7BD8C 800E28DC E7A20014 */   swc1     $f2, 0x14($sp)
/* 7BD90 800E28E0 0040802D */  daddu     $s0, $v0, $zero
/* 7BD94 800E28E4 06000030 */  bltz      $s0, .L800E29A8
/* 7BD98 800E28E8 A6500008 */   sh       $s0, 8($s2)
/* 7BD9C 800E28EC 922200B4 */  lbu       $v0, 0xb4($s1)
/* 7BDA0 800E28F0 2442FFF8 */  addiu     $v0, $v0, -8
/* 7BDA4 800E28F4 2C420002 */  sltiu     $v0, $v0, 2
/* 7BDA8 800E28F8 1440002C */  bnez      $v0, .L800E29AC
/* 7BDAC 800E28FC 0200102D */   daddu    $v0, $s0, $zero
/* 7BDB0 800E2900 86420002 */  lh        $v0, 2($s2)
/* 7BDB4 800E2904 04410029 */  bgez      $v0, .L800E29AC
/* 7BDB8 800E2908 0200102D */   daddu    $v0, $s0, $zero
/* 7BDBC 800E290C C6200070 */  lwc1      $f0, 0x70($s1)
/* 7BDC0 800E2910 4600A000 */  add.s     $f0, $f20, $f0
/* 7BDC4 800E2914 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 7BDC8 800E2918 46000005 */  abs.s     $f0, $f0
/* 7BDCC 800E291C 4600103E */  c.le.s    $f2, $f0
/* 7BDD0 800E2920 00000000 */  nop
/* 7BDD4 800E2924 45000020 */  bc1f      .L800E29A8
/* 7BDD8 800E2928 32024000 */   andi     $v0, $s0, 0x4000
/* 7BDDC 800E292C 10400006 */  beqz      $v0, .L800E2948
/* 7BDE0 800E2930 00000000 */   nop
/* 7BDE4 800E2934 0C0441A9 */  jal       get_entity_type
/* 7BDE8 800E2938 0200202D */   daddu    $a0, $s0, $zero
/* 7BDEC 800E293C 2403000D */  addiu     $v1, $zero, 0xd
/* 7BDF0 800E2940 1043001A */  beq       $v0, $v1, .L800E29AC
/* 7BDF4 800E2944 0200102D */   daddu    $v0, $s0, $zero
.L800E2948:
/* 7BDF8 800E2948 862200B0 */  lh        $v0, 0xb0($s1)
/* 7BDFC 800E294C 3C0140A0 */  lui       $at, 0x40a0
/* 7BE00 800E2950 44810000 */  mtc1      $at, $f0
/* 7BE04 800E2954 3C014040 */  lui       $at, 0x4040
/* 7BE08 800E2958 44812000 */  mtc1      $at, $f4
/* 7BE0C 800E295C 44821000 */  mtc1      $v0, $f2
/* 7BE10 800E2960 00000000 */  nop
/* 7BE14 800E2964 468010A0 */  cvt.s.w   $f2, $f2
/* 7BE18 800E2968 46001083 */  div.s     $f2, $f2, $f0
/* 7BE1C 800E296C 46041082 */  mul.s     $f2, $f2, $f4
/* 7BE20 800E2970 00000000 */  nop
/* 7BE24 800E2974 C7A00024 */  lwc1      $f0, 0x24($sp)
/* 7BE28 800E2978 46020001 */  sub.s     $f0, $f0, $f2
/* 7BE2C 800E297C 822300B4 */  lb        $v1, 0xb4($s1)
/* 7BE30 800E2980 2402000F */  addiu     $v0, $zero, 0xf
/* 7BE34 800E2984 10620008 */  beq       $v1, $v0, .L800E29A8
/* 7BE38 800E2988 E620002C */   swc1     $f0, 0x2c($s1)
/* 7BE3C 800E298C 2402000D */  addiu     $v0, $zero, 0xd
/* 7BE40 800E2990 10620006 */  beq       $v1, $v0, .L800E29AC
/* 7BE44 800E2994 0200102D */   daddu    $v0, $s0, $zero
/* 7BE48 800E2998 AE200070 */  sw        $zero, 0x70($s1)
/* 7BE4C 800E299C AE200074 */  sw        $zero, 0x74($s1)
/* 7BE50 800E29A0 AE200078 */  sw        $zero, 0x78($s1)
/* 7BE54 800E29A4 AE20007C */  sw        $zero, 0x7c($s1)
.L800E29A8:
/* 7BE58 800E29A8 0200102D */  daddu     $v0, $s0, $zero
.L800E29AC:
/* 7BE5C 800E29AC 8FBF003C */  lw        $ra, 0x3c($sp)
/* 7BE60 800E29B0 8FB20038 */  lw        $s2, 0x38($sp)
/* 7BE64 800E29B4 8FB10034 */  lw        $s1, 0x34($sp)
/* 7BE68 800E29B8 8FB00030 */  lw        $s0, 0x30($sp)
/* 7BE6C 800E29BC D7B40040 */  ldc1      $f20, 0x40($sp)
/* 7BE70 800E29C0 03E00008 */  jr        $ra
/* 7BE74 800E29C4 27BD0048 */   addiu    $sp, $sp, 0x48

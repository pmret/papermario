.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E236E0
/* E236E0 802B6000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E236E4 802B6004 AFB30024 */  sw        $s3, 0x24($sp)
/* E236E8 802B6008 AFB00018 */  sw        $s0, 0x18($sp)
/* E236EC 802B600C 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E236F0 802B6010 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E236F4 802B6014 AFBF002C */  sw        $ra, 0x2c($sp)
/* E236F8 802B6018 AFB40028 */  sw        $s4, 0x28($sp)
/* E236FC 802B601C AFB20020 */  sw        $s2, 0x20($sp)
/* E23700 802B6020 AFB1001C */  sw        $s1, 0x1c($sp)
/* E23704 802B6024 8E050004 */  lw        $a1, 4($s0)
/* E23708 802B6028 3C148011 */  lui       $s4, %hi(gPlayerData)
/* E2370C 802B602C 2694F290 */  addiu     $s4, $s4, %lo(gPlayerData)
/* E23710 802B6030 30A21000 */  andi      $v0, $a1, 0x1000
/* E23714 802B6034 10400005 */  beqz      $v0, .L802B604C
/* E23718 802B6038 0000982D */   daddu    $s3, $zero, $zero
/* E2371C 802B603C 0C0AD97A */  jal       func_802B65E8_E23CC8
/* E23720 802B6040 00000000 */   nop
/* E23724 802B6044 080AD89A */  j         .L802B6268
/* E23728 802B6048 00000000 */   nop
.L802B604C:
/* E2372C 802B604C 8E030000 */  lw        $v1, ($s0)
/* E23730 802B6050 04610016 */  bgez      $v1, .L802B60AC
/* E23734 802B6054 3C027F77 */   lui      $v0, 0x7f77
/* E23738 802B6058 3442FFFF */  ori       $v0, $v0, 0xffff
/* E2373C 802B605C 24130001 */  addiu     $s3, $zero, 1
/* E23740 802B6060 00621024 */  and       $v0, $v1, $v0
/* E23744 802B6064 AE020000 */  sw        $v0, ($s0)
/* E23748 802B6068 30624000 */  andi      $v0, $v1, 0x4000
/* E2374C 802B606C 14400003 */  bnez      $v0, .L802B607C
/* E23750 802B6070 AE000060 */   sw       $zero, 0x60($s0)
/* E23754 802B6074 C6000058 */  lwc1      $f0, 0x58($s0)
/* E23758 802B6078 E6000054 */  swc1      $f0, 0x54($s0)
.L802B607C:
/* E2375C 802B607C 30A24000 */  andi      $v0, $a1, 0x4000
/* E23760 802B6080 10400003 */  beqz      $v0, .L802B6090
/* E23764 802B6084 3C040009 */   lui      $a0, 9
/* E23768 802B6088 080AD829 */  j         .L802B60A4
/* E2376C 802B608C 34840003 */   ori      $a0, $a0, 3
.L802B6090:
/* E23770 802B6090 30A20001 */  andi      $v0, $a1, 1
/* E23774 802B6094 14400003 */  bnez      $v0, .L802B60A4
/* E23778 802B6098 3C040006 */   lui      $a0, 6
/* E2377C 802B609C 3C040001 */  lui       $a0, 1
/* E23780 802B60A0 34840004 */  ori       $a0, $a0, 4
.L802B60A4:
/* E23784 802B60A4 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E23788 802B60A8 00000000 */   nop
.L802B60AC:
/* E2378C 802B60AC 8E020000 */  lw        $v0, ($s0)
/* E23790 802B60B0 30424000 */  andi      $v0, $v0, 0x4000
/* E23794 802B60B4 10400006 */  beqz      $v0, .L802B60D0
/* E23798 802B60B8 24040008 */   addiu    $a0, $zero, 8
/* E2379C 802B60BC C60000A0 */  lwc1      $f0, 0xa0($s0)
/* E237A0 802B60C0 0C039426 */  jal       try_player_footstep_sounds
/* E237A4 802B60C4 E6000080 */   swc1     $f0, 0x80($s0)
/* E237A8 802B60C8 080AD89A */  j         .L802B6268
/* E237AC 802B60CC 00000000 */   nop
.L802B60D0:
/* E237B0 802B60D0 27B20010 */  addiu     $s2, $sp, 0x10
/* E237B4 802B60D4 0240202D */  daddu     $a0, $s2, $zero
/* E237B8 802B60D8 27B10014 */  addiu     $s1, $sp, 0x14
/* E237BC 802B60DC 0C0388C1 */  jal       player_input_to_move_vector
/* E237C0 802B60E0 0220282D */   daddu    $a1, $s1, $zero
/* E237C4 802B60E4 0C039454 */  jal       phys_update_interact_collider
/* E237C8 802B60E8 00000000 */   nop
/* E237CC 802B60EC 0C039858 */  jal       check_input_jump
/* E237D0 802B60F0 00000000 */   nop
/* E237D4 802B60F4 1440005C */  bnez      $v0, .L802B6268
/* E237D8 802B60F8 00000000 */   nop
/* E237DC 802B60FC 16600006 */  bnez      $s3, .L802B6118
/* E237E0 802B6100 0240202D */   daddu    $a0, $s2, $zero
/* E237E4 802B6104 0C039838 */  jal       check_input_hammer
/* E237E8 802B6108 00000000 */   nop
/* E237EC 802B610C 14400056 */  bnez      $v0, .L802B6268
/* E237F0 802B6110 00000000 */   nop
/* E237F4 802B6114 0240202D */  daddu     $a0, $s2, $zero
.L802B6118:
/* E237F8 802B6118 0C0388C1 */  jal       player_input_to_move_vector
/* E237FC 802B611C 0220282D */   daddu    $a1, $s1, $zero
/* E23800 802B6120 C7A40014 */  lwc1      $f4, 0x14($sp)
/* E23804 802B6124 44800000 */  mtc1      $zero, $f0
/* E23808 802B6128 00000000 */  nop
/* E2380C 802B612C 46002032 */  c.eq.s    $f4, $f0
/* E23810 802B6130 00000000 */  nop
/* E23814 802B6134 45000005 */  bc1f      .L802B614C
/* E23818 802B6138 00000000 */   nop
/* E2381C 802B613C 0C039769 */  jal       set_action_state
/* E23820 802B6140 0000202D */   daddu    $a0, $zero, $zero
/* E23824 802B6144 080AD89A */  j         .L802B6268
/* E23828 802B6148 00000000 */   nop
.L802B614C:
/* E2382C 802B614C C7A60010 */  lwc1      $f6, 0x10($sp)
/* E23830 802B6150 3C01800F */  lui       $at, %hi(D_800F7B40)
/* E23834 802B6154 C4207B40 */  lwc1      $f0, %lo(D_800F7B40)($at)
/* E23838 802B6158 46800020 */  cvt.s.w   $f0, $f0
/* E2383C 802B615C 46060001 */  sub.s     $f0, $f0, $f6
/* E23840 802B6160 3C0142B4 */  lui       $at, 0x42b4
/* E23844 802B6164 44811000 */  mtc1      $at, $f2
/* E23848 802B6168 46000005 */  abs.s     $f0, $f0
/* E2384C 802B616C 4602003E */  c.le.s    $f0, $f2
/* E23850 802B6170 00000000 */  nop
/* E23854 802B6174 4500001C */  bc1f      .L802B61E8
/* E23858 802B6178 00000000 */   nop
/* E2385C 802B617C 3C01800F */  lui       $at, %hi(D_800F7B44)
/* E23860 802B6180 C4207B44 */  lwc1      $f0, %lo(D_800F7B44)($at)
/* E23864 802B6184 46800020 */  cvt.s.w   $f0, $f0
/* E23868 802B6188 46002001 */  sub.s     $f0, $f4, $f0
/* E2386C 802B618C 4600020D */  trunc.w.s $f8, $f0
/* E23870 802B6190 44024000 */  mfc1      $v0, $f8
/* E23874 802B6194 00000000 */  nop
/* E23878 802B6198 04420001 */  bltzl     $v0, .L802B61A0
/* E2387C 802B619C 00021023 */   negu     $v0, $v0
.L802B61A0:
/* E23880 802B61A0 28420014 */  slti      $v0, $v0, 0x14
/* E23884 802B61A4 10400010 */  beqz      $v0, .L802B61E8
/* E23888 802B61A8 00000000 */   nop
/* E2388C 802B61AC 8E020004 */  lw        $v0, 4($s0)
/* E23890 802B61B0 0440000A */  bltz      $v0, .L802B61DC
/* E23894 802B61B4 3C037FFF */   lui      $v1, 0x7fff
/* E23898 802B61B8 3C0141A0 */  lui       $at, 0x41a0
/* E2389C 802B61BC 44810000 */  mtc1      $at, $f0
/* E238A0 802B61C0 00000000 */  nop
/* E238A4 802B61C4 4604003E */  c.le.s    $f0, $f4
/* E238A8 802B61C8 00000000 */  nop
/* E238AC 802B61CC 45030002 */  bc1tl     .L802B61D8
/* E238B0 802B61D0 E6060080 */   swc1     $f6, 0x80($s0)
/* E238B4 802B61D4 3C037FFF */  lui       $v1, 0x7fff
.L802B61D8:
/* E238B8 802B61D8 8E020004 */  lw        $v0, 4($s0)
.L802B61DC:
/* E238BC 802B61DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* E238C0 802B61E0 080AD881 */  j         .L802B6204
/* E238C4 802B61E4 00431024 */   and      $v0, $v0, $v1
.L802B61E8:
/* E238C8 802B61E8 8E020004 */  lw        $v0, 4($s0)
/* E238CC 802B61EC 04410004 */  bgez      $v0, .L802B6200
/* E238D0 802B61F0 3C038000 */   lui      $v1, 0x8000
/* E238D4 802B61F4 C7A00010 */  lwc1      $f0, 0x10($sp)
/* E238D8 802B61F8 080AD882 */  j         .L802B6208
/* E238DC 802B61FC E6000080 */   swc1     $f0, 0x80($s0)
.L802B6200:
/* E238E0 802B6200 00431025 */  or        $v0, $v0, $v1
.L802B6204:
/* E238E4 802B6204 AE020004 */  sw        $v0, 4($s0)
.L802B6208:
/* E238E8 802B6208 0C03A752 */  jal       is_ability_active
/* E238EC 802B620C 2404000B */   addiu    $a0, $zero, 0xb
/* E238F0 802B6210 14400010 */  bnez      $v0, .L802B6254
/* E238F4 802B6214 00000000 */   nop
/* E238F8 802B6218 8E0200E8 */  lw        $v0, 0xe8($s0)
/* E238FC 802B621C 00420018 */  mult      $v0, $v0
/* E23900 802B6220 00001812 */  mflo      $v1
/* E23904 802B6224 8E0200EC */  lw        $v0, 0xec($s0)
/* E23908 802B6228 00000000 */  nop
/* E2390C 802B622C 00420018 */  mult      $v0, $v0
/* E23910 802B6230 00003812 */  mflo      $a3
/* E23914 802B6234 00671021 */  addu      $v0, $v1, $a3
/* E23918 802B6238 28420BD2 */  slti      $v0, $v0, 0xbd2
/* E2391C 802B623C 14400005 */  bnez      $v0, .L802B6254
/* E23920 802B6240 00000000 */   nop
/* E23924 802B6244 0C039769 */  jal       set_action_state
/* E23928 802B6248 24040002 */   addiu    $a0, $zero, 2
/* E2392C 802B624C 080AD89A */  j         .L802B6268
/* E23930 802B6250 00000000 */   nop
.L802B6254:
/* E23934 802B6254 0C039426 */  jal       try_player_footstep_sounds
/* E23938 802B6258 24040008 */   addiu    $a0, $zero, 8
/* E2393C 802B625C 8E8202AC */  lw        $v0, 0x2ac($s4)
/* E23940 802B6260 24420001 */  addiu     $v0, $v0, 1
/* E23944 802B6264 AE8202AC */  sw        $v0, 0x2ac($s4)
.L802B6268:
/* E23948 802B6268 8FBF002C */  lw        $ra, 0x2c($sp)
/* E2394C 802B626C 8FB40028 */  lw        $s4, 0x28($sp)
/* E23950 802B6270 8FB30024 */  lw        $s3, 0x24($sp)
/* E23954 802B6274 8FB20020 */  lw        $s2, 0x20($sp)
/* E23958 802B6278 8FB1001C */  lw        $s1, 0x1c($sp)
/* E2395C 802B627C 8FB00018 */  lw        $s0, 0x18($sp)
/* E23960 802B6280 03E00008 */  jr        $ra
/* E23964 802B6284 27BD0030 */   addiu    $sp, $sp, 0x30

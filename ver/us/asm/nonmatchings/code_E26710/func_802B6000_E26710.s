.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E26710
/* E26710 802B6000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E26714 802B6004 AFB00018 */  sw        $s0, 0x18($sp)
/* E26718 802B6008 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E2671C 802B600C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E26720 802B6010 AFBF0020 */  sw        $ra, 0x20($sp)
/* E26724 802B6014 AFB1001C */  sw        $s1, 0x1c($sp)
/* E26728 802B6018 F7B40028 */  sdc1      $f20, 0x28($sp)
/* E2672C 802B601C 8E040000 */  lw        $a0, ($s0)
/* E26730 802B6020 3C118016 */  lui       $s1, %hi(gCollisionStatus)
/* E26734 802B6024 2631A550 */  addiu     $s1, $s1, %lo(gCollisionStatus)
/* E26738 802B6028 0481003E */  bgez      $a0, .L802B6124
/* E2673C 802B602C 3C027FFF */   lui      $v0, 0x7fff
/* E26740 802B6030 3442FFFF */  ori       $v0, $v0, 0xffff
/* E26744 802B6034 3C030002 */  lui       $v1, 2
/* E26748 802B6038 3463000A */  ori       $v1, $v1, 0xa
/* E2674C 802B603C 00821024 */  and       $v0, $a0, $v0
/* E26750 802B6040 00431025 */  or        $v0, $v0, $v1
/* E26754 802B6044 0C03963C */  jal       func_800E58F0
/* E26758 802B6048 AE020000 */   sw       $v0, ($s0)
/* E2675C 802B604C 3C014180 */  lui       $at, 0x4180
/* E26760 802B6050 44810000 */  mtc1      $at, $f0
/* E26764 802B6054 3C01C0EC */  lui       $at, 0xc0ec
/* E26768 802B6058 34215C14 */  ori       $at, $at, 0x5c14
/* E2676C 802B605C 44811000 */  mtc1      $at, $f2
/* E26770 802B6060 3C01405C */  lui       $at, 0x405c
/* E26774 802B6064 34219AAA */  ori       $at, $at, 0x9aaa
/* E26778 802B6068 44812000 */  mtc1      $at, $f4
/* E2677C 802B606C 3C01BF40 */  lui       $at, 0xbf40
/* E26780 802B6070 44813000 */  mtc1      $at, $f6
/* E26784 802B6074 3C040008 */  lui       $a0, 8
/* E26788 802B6078 A20000B6 */  sb        $zero, 0xb6($s0)
/* E2678C 802B607C AE000054 */  sw        $zero, 0x54($s0)
/* E26790 802B6080 E6000070 */  swc1      $f0, 0x70($s0)
/* E26794 802B6084 E6020074 */  swc1      $f2, 0x74($s0)
/* E26798 802B6088 E6040078 */  swc1      $f4, 0x78($s0)
/* E2679C 802B608C 0C037FDE */  jal       func_800DFF78
/* E267A0 802B6090 E606007C */   swc1     $f6, 0x7c($s0)
/* E267A4 802B6094 0C03805E */  jal       disable_player_input
/* E267A8 802B6098 00000000 */   nop
/* E267AC 802B609C 8E020000 */  lw        $v0, ($s0)
/* E267B0 802B60A0 3C04800B */  lui       $a0, %hi(gCameras)
/* E267B4 802B60A4 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* E267B8 802B60A8 34420200 */  ori       $v0, $v0, 0x200
/* E267BC 802B60AC AE020000 */  sw        $v0, ($s0)
/* E267C0 802B60B0 94820002 */  lhu       $v0, 2($a0)
/* E267C4 802B60B4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E267C8 802B60B8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E267CC 802B60BC 34420001 */  ori       $v0, $v0, 1
/* E267D0 802B60C0 A4820002 */  sh        $v0, 2($a0)
/* E267D4 802B60C4 00031080 */  sll       $v0, $v1, 2
/* E267D8 802B60C8 00431021 */  addu      $v0, $v0, $v1
/* E267DC 802B60CC 00021080 */  sll       $v0, $v0, 2
/* E267E0 802B60D0 00431023 */  subu      $v0, $v0, $v1
/* E267E4 802B60D4 000218C0 */  sll       $v1, $v0, 3
/* E267E8 802B60D8 00431021 */  addu      $v0, $v0, $v1
/* E267EC 802B60DC 000210C0 */  sll       $v0, $v0, 3
/* E267F0 802B60E0 00441021 */  addu      $v0, $v0, $a0
/* E267F4 802B60E4 C6000080 */  lwc1      $f0, 0x80($s0)
/* E267F8 802B60E8 C44C006C */  lwc1      $f12, 0x6c($v0)
/* E267FC 802B60EC 0C00A6C9 */  jal       clamp_angle
/* E26800 802B60F0 460C0301 */   sub.s    $f12, $f0, $f12
/* E26804 802B60F4 3C014334 */  lui       $at, 0x4334
/* E26808 802B60F8 44811000 */  mtc1      $at, $f2
/* E2680C 802B60FC 3C01C270 */  lui       $at, 0xc270
/* E26810 802B6100 44812000 */  mtc1      $at, $f4
/* E26814 802B6104 4602003E */  c.le.s    $f0, $f2
/* E26818 802B6108 00000000 */  nop
/* E2681C 802B610C 45020005 */  bc1fl     .L802B6124
/* E26820 802B6110 E60400D4 */   swc1     $f4, 0xd4($s0)
/* E26824 802B6114 3C014270 */  lui       $at, 0x4270
/* E26828 802B6118 44812000 */  mtc1      $at, $f4
/* E2682C 802B611C 00000000 */  nop
/* E26830 802B6120 E60400D4 */  swc1      $f4, 0xd4($s0)
.L802B6124:
/* E26834 802B6124 820200B6 */  lb        $v0, 0xb6($s0)
/* E26838 802B6128 28420004 */  slti      $v0, $v0, 4
/* E2683C 802B612C 1040001E */  beqz      $v0, .L802B61A8
/* E26840 802B6130 00000000 */   nop
/* E26844 802B6134 C60200D4 */  lwc1      $f2, 0xd4($s0)
/* E26848 802B6138 44802000 */  mtc1      $zero, $f4
/* E2684C 802B613C 00000000 */  nop
/* E26850 802B6140 4602203E */  c.le.s    $f4, $f2
/* E26854 802B6144 00000000 */  nop
/* E26858 802B6148 4500000C */  bc1f      .L802B617C
/* E2685C 802B614C 00000000 */   nop
/* E26860 802B6150 C60000A8 */  lwc1      $f0, 0xa8($s0)
/* E26864 802B6154 46020000 */  add.s     $f0, $f0, $f2
/* E26868 802B6158 3C0143B4 */  lui       $at, 0x43b4
/* E2686C 802B615C 44811000 */  mtc1      $at, $f2
/* E26870 802B6160 00000000 */  nop
/* E26874 802B6164 4600103E */  c.le.s    $f2, $f0
/* E26878 802B6168 00000000 */  nop
/* E2687C 802B616C 4500000E */  bc1f      .L802B61A8
/* E26880 802B6170 E60000A8 */   swc1     $f0, 0xa8($s0)
/* E26884 802B6174 080AD869 */  j         .L802B61A4
/* E26888 802B6178 46020001 */   sub.s    $f0, $f0, $f2
.L802B617C:
/* E2688C 802B617C C60000A8 */  lwc1      $f0, 0xa8($s0)
/* E26890 802B6180 46020080 */  add.s     $f2, $f0, $f2
/* E26894 802B6184 4604103C */  c.lt.s    $f2, $f4
/* E26898 802B6188 00000000 */  nop
/* E2689C 802B618C 45000006 */  bc1f      .L802B61A8
/* E268A0 802B6190 E60200A8 */   swc1     $f2, 0xa8($s0)
/* E268A4 802B6194 3C0143B4 */  lui       $at, 0x43b4
/* E268A8 802B6198 44810000 */  mtc1      $at, $f0
/* E268AC 802B619C 00000000 */  nop
/* E268B0 802B61A0 46001000 */  add.s     $f0, $f2, $f0
.L802B61A4:
/* E268B4 802B61A4 E60000A8 */  swc1      $f0, 0xa8($s0)
.L802B61A8:
/* E268B8 802B61A8 C6020070 */  lwc1      $f2, 0x70($s0)
/* E268BC 802B61AC 44800000 */  mtc1      $zero, $f0
/* E268C0 802B61B0 00000000 */  nop
/* E268C4 802B61B4 4600103E */  c.le.s    $f2, $f0
/* E268C8 802B61B8 00000000 */  nop
/* E268CC 802B61BC 45000009 */  bc1f      .L802B61E4
/* E268D0 802B61C0 00000000 */   nop
/* E268D4 802B61C4 3C028011 */  lui       $v0, %hi(D_8010C944)
/* E268D8 802B61C8 8C42C944 */  lw        $v0, %lo(D_8010C944)($v0)
/* E268DC 802B61CC C600002C */  lwc1      $f0, 0x2c($s0)
/* E268E0 802B61D0 00021080 */  sll       $v0, $v0, 2
/* E268E4 802B61D4 4600020D */  trunc.w.s $f8, $f0
/* E268E8 802B61D8 3C018011 */  lui       $at, %hi(D_8010EF10)
/* E268EC 802B61DC 00220821 */  addu      $at, $at, $v0
/* E268F0 802B61E0 E428EF10 */  swc1      $f8, %lo(D_8010EF10)($at)
.L802B61E4:
/* E268F4 802B61E4 3C058011 */  lui       $a1, %hi(D_8010C944)
/* E268F8 802B61E8 24A5C944 */  addiu     $a1, $a1, %lo(D_8010C944)
/* E268FC 802B61EC 8CA20000 */  lw        $v0, ($a1)
/* E26900 802B61F0 C60000A8 */  lwc1      $f0, 0xa8($s0)
/* E26904 802B61F4 00022040 */  sll       $a0, $v0, 1
/* E26908 802B61F8 24420001 */  addiu     $v0, $v0, 1
/* E2690C 802B61FC 4600020D */  trunc.w.s $f8, $f0
/* E26910 802B6200 44034000 */  mfc1      $v1, $f8
/* E26914 802B6204 3C018011 */  lui       $at, %hi(D_8010F6B8)
/* E26918 802B6208 00240821 */  addu      $at, $at, $a0
/* E2691C 802B620C A423F6B8 */  sh        $v1, %lo(D_8010F6B8)($at)
/* E26920 802B6210 ACA20000 */  sw        $v0, ($a1)
/* E26924 802B6214 28420006 */  slti      $v0, $v0, 6
/* E26928 802B6218 50400001 */  beql      $v0, $zero, .L802B6220
/* E2692C 802B621C ACA00000 */   sw       $zero, ($a1)
.L802B6220:
/* E26930 802B6220 820300B6 */  lb        $v1, 0xb6($s0)
/* E26934 802B6224 2C62000D */  sltiu     $v0, $v1, 0xd
/* E26938 802B6228 104000DE */  beqz      $v0, L802B65A4_E26CB4
/* E2693C 802B622C 00031080 */   sll      $v0, $v1, 2
/* E26940 802B6230 3C01802B */  lui       $at, %hi(jtbl_802B6690_E26DA0)
/* E26944 802B6234 00220821 */  addu      $at, $at, $v0
/* E26948 802B6238 8C226690 */  lw        $v0, %lo(jtbl_802B6690_E26DA0)($at)
/* E2694C 802B623C 00400008 */  jr        $v0
/* E26950 802B6240 00000000 */   nop
glabel L802B6244_E26954
/* E26954 802B6244 0C038D12 */  jal       integrate_gravity
/* E26958 802B6248 00000000 */   nop
/* E2695C 802B624C 46000506 */  mov.s     $f20, $f0
/* E26960 802B6250 4600A306 */  mov.s     $f12, $f20
/* E26964 802B6254 0C038D45 */  jal       func_800E3514
/* E26968 802B6258 27A50010 */   addiu    $a1, $sp, 0x10
/* E2696C 802B625C 8FA20010 */  lw        $v0, 0x10($sp)
/* E26970 802B6260 04400014 */  bltz      $v0, .L802B62B4
/* E26974 802B6264 E600002C */   swc1     $f0, 0x2c($s0)
/* E26978 802B6268 96240002 */  lhu       $a0, 2($s1)
/* E2697C 802B626C 30824000 */  andi      $v0, $a0, 0x4000
/* E26980 802B6270 10400010 */  beqz      $v0, .L802B62B4
/* E26984 802B6274 00042400 */   sll      $a0, $a0, 0x10
/* E26988 802B6278 0C0441A9 */  jal       get_entity_type
/* E2698C 802B627C 00042403 */   sra      $a0, $a0, 0x10
/* E26990 802B6280 2442FFF9 */  addiu     $v0, $v0, -7
/* E26994 802B6284 2C420002 */  sltiu     $v0, $v0, 2
/* E26998 802B6288 1040000A */  beqz      $v0, .L802B62B4
/* E2699C 802B628C 00000000 */   nop
/* E269A0 802B6290 0C04417A */  jal       get_entity_by_index
/* E269A4 802B6294 86240002 */   lh       $a0, 2($s1)
/* E269A8 802B6298 90430006 */  lbu       $v1, 6($v0)
/* E269AC 802B629C 34630001 */  ori       $v1, $v1, 1
/* E269B0 802B62A0 0C03805E */  jal       disable_player_input
/* E269B4 802B62A4 A0430006 */   sb       $v1, 6($v0)
/* E269B8 802B62A8 2402000B */  addiu     $v0, $zero, 0xb
/* E269BC 802B62AC 080AD969 */  j         L802B65A4_E26CB4
/* E269C0 802B62B0 A20200B6 */   sb       $v0, 0xb6($s0)
.L802B62B4:
/* E269C4 802B62B4 44800000 */  mtc1      $zero, $f0
/* E269C8 802B62B8 00000000 */  nop
/* E269CC 802B62BC 4600A03E */  c.le.s    $f20, $f0
/* E269D0 802B62C0 00000000 */  nop
/* E269D4 802B62C4 4500000E */  bc1f      .L802B6300
/* E269D8 802B62C8 00000000 */   nop
/* E269DC 802B62CC 0C0389AC */  jal       func_800E26B0
/* E269E0 802B62D0 00000000 */   nop
/* E269E4 802B62D4 24040147 */  addiu     $a0, $zero, 0x147
/* E269E8 802B62D8 0000282D */  daddu     $a1, $zero, $zero
/* E269EC 802B62DC 24020003 */  addiu     $v0, $zero, 3
/* E269F0 802B62E0 A6020008 */  sh        $v0, 8($s0)
/* E269F4 802B62E4 8E020000 */  lw        $v0, ($s0)
/* E269F8 802B62E8 920300B6 */  lbu       $v1, 0xb6($s0)
/* E269FC 802B62EC 34420004 */  ori       $v0, $v0, 4
/* E26A00 802B62F0 24630001 */  addiu     $v1, $v1, 1
/* E26A04 802B62F4 AE020000 */  sw        $v0, ($s0)
/* E26A08 802B62F8 0C052736 */  jal       sfx_play_sound_at_player
/* E26A0C 802B62FC A20300B6 */   sb       $v1, 0xb6($s0)
.L802B6300:
/* E26A10 802B6300 8FA20010 */  lw        $v0, 0x10($sp)
/* E26A14 802B6304 044000A7 */  bltz      $v0, L802B65A4_E26CB4
/* E26A18 802B6308 3C03FFFD */   lui      $v1, 0xfffd
/* E26A1C 802B630C 3463FFF7 */  ori       $v1, $v1, 0xfff7
/* E26A20 802B6310 8E020000 */  lw        $v0, ($s0)
/* E26A24 802B6314 2404000A */  addiu     $a0, $zero, 0xa
/* E26A28 802B6318 00431024 */  and       $v0, $v0, $v1
/* E26A2C 802B631C 0C039769 */  jal       set_action_state
/* E26A30 802B6320 AE020000 */   sw       $v0, ($s0)
/* E26A34 802B6324 080AD969 */  j         L802B65A4_E26CB4
/* E26A38 802B6328 00000000 */   nop
glabel L802B632C_E26A3C
/* E26A3C 802B632C 96020008 */  lhu       $v0, 8($s0)
/* E26A40 802B6330 2442FFFF */  addiu     $v0, $v0, -1
/* E26A44 802B6334 A6020008 */  sh        $v0, 8($s0)
/* E26A48 802B6338 00021400 */  sll       $v0, $v0, 0x10
/* E26A4C 802B633C 1C400099 */  bgtz      $v0, L802B65A4_E26CB4
/* E26A50 802B6340 00000000 */   nop
/* E26A54 802B6344 920200B6 */  lbu       $v0, 0xb6($s0)
/* E26A58 802B6348 24420001 */  addiu     $v0, $v0, 1
/* E26A5C 802B634C 080AD969 */  j         L802B65A4_E26CB4
/* E26A60 802B6350 A20200B6 */   sb       $v0, 0xb6($s0)
glabel L802B6354_E26A64
/* E26A64 802B6354 0C038D12 */  jal       integrate_gravity
/* E26A68 802B6358 00000000 */   nop
/* E26A6C 802B635C 46000506 */  mov.s     $f20, $f0
/* E26A70 802B6360 4600A306 */  mov.s     $f12, $f20
/* E26A74 802B6364 0C038D45 */  jal       func_800E3514
/* E26A78 802B6368 27A50010 */   addiu    $a1, $sp, 0x10
/* E26A7C 802B636C 3C01C2C8 */  lui       $at, 0xc2c8
/* E26A80 802B6370 44811000 */  mtc1      $at, $f2
/* E26A84 802B6374 00000000 */  nop
/* E26A88 802B6378 4602A03C */  c.lt.s    $f20, $f2
/* E26A8C 802B637C 00000000 */  nop
/* E26A90 802B6380 45000005 */  bc1f      .L802B6398
/* E26A94 802B6384 E600002C */   swc1     $f0, 0x2c($s0)
/* E26A98 802B6388 AE00007C */  sw        $zero, 0x7c($s0)
/* E26A9C 802B638C AE000078 */  sw        $zero, 0x78($s0)
/* E26AA0 802B6390 AE000074 */  sw        $zero, 0x74($s0)
/* E26AA4 802B6394 E6020070 */  swc1      $f2, 0x70($s0)
.L802B6398:
/* E26AA8 802B6398 8FA20010 */  lw        $v0, 0x10($sp)
/* E26AAC 802B639C 04400081 */  bltz      $v0, L802B65A4_E26CB4
/* E26AB0 802B63A0 00000000 */   nop
/* E26AB4 802B63A4 96240002 */  lhu       $a0, 2($s1)
/* E26AB8 802B63A8 30824000 */  andi      $v0, $a0, 0x4000
/* E26ABC 802B63AC 1040002D */  beqz      $v0, .L802B6464
/* E26AC0 802B63B0 00042400 */   sll      $a0, $a0, 0x10
/* E26AC4 802B63B4 0C0441A9 */  jal       get_entity_type
/* E26AC8 802B63B8 00042403 */   sra      $a0, $a0, 0x10
/* E26ACC 802B63BC 0040182D */  daddu     $v1, $v0, $zero
/* E26AD0 802B63C0 2462FFD2 */  addiu     $v0, $v1, -0x2e
/* E26AD4 802B63C4 2C420002 */  sltiu     $v0, $v0, 2
/* E26AD8 802B63C8 10400009 */  beqz      $v0, .L802B63F0
/* E26ADC 802B63CC 2404000A */   addiu    $a0, $zero, 0xa
/* E26AE0 802B63D0 3C03FFFD */  lui       $v1, 0xfffd
/* E26AE4 802B63D4 3463FFF7 */  ori       $v1, $v1, 0xfff7
/* E26AE8 802B63D8 8E020000 */  lw        $v0, ($s0)
/* E26AEC 802B63DC 00431024 */  and       $v0, $v0, $v1
/* E26AF0 802B63E0 0C039769 */  jal       set_action_state
/* E26AF4 802B63E4 AE020000 */   sw       $v0, ($s0)
/* E26AF8 802B63E8 080AD978 */  j         .L802B65E0
/* E26AFC 802B63EC 00000000 */   nop
.L802B63F0:
/* E26B00 802B63F0 2462FFF9 */  addiu     $v0, $v1, -7
/* E26B04 802B63F4 2C420002 */  sltiu     $v0, $v0, 2
/* E26B08 802B63F8 1040001A */  beqz      $v0, .L802B6464
/* E26B0C 802B63FC 3C03FFFD */   lui      $v1, 0xfffd
/* E26B10 802B6400 8E020000 */  lw        $v0, ($s0)
/* E26B14 802B6404 3463FFF7 */  ori       $v1, $v1, 0xfff7
/* E26B18 802B6408 00431024 */  and       $v0, $v0, $v1
/* E26B1C 802B640C 0C038C9E */  jal       phys_player_land
/* E26B20 802B6410 AE020000 */   sw       $v0, ($s0)
/* E26B24 802B6414 0000202D */  daddu     $a0, $zero, $zero
/* E26B28 802B6418 0080282D */  daddu     $a1, $a0, $zero
/* E26B2C 802B641C 0C0B2D5B */  jal       exec_ShakeCam1
/* E26B30 802B6420 24060004 */   addiu    $a2, $zero, 4
/* E26B34 802B6424 2404014A */  addiu     $a0, $zero, 0x14a
/* E26B38 802B6428 0C052736 */  jal       sfx_play_sound_at_player
/* E26B3C 802B642C 0000282D */   daddu    $a1, $zero, $zero
/* E26B40 802B6430 24040100 */  addiu     $a0, $zero, 0x100
/* E26B44 802B6434 0C00A3C2 */  jal       start_rumble
/* E26B48 802B6438 24050032 */   addiu    $a1, $zero, 0x32
/* E26B4C 802B643C 3C048016 */  lui       $a0, %hi(D_8015A578)
/* E26B50 802B6440 2484A578 */  addiu     $a0, $a0, %lo(D_8015A578)
/* E26B54 802B6444 C600002C */  lwc1      $f0, 0x2c($s0)
/* E26B58 802B6448 8E030000 */  lw        $v1, ($s0)
/* E26B5C 802B644C 24020001 */  addiu     $v0, $zero, 1
/* E26B60 802B6450 A0820000 */  sb        $v0, ($a0)
/* E26B64 802B6454 34630400 */  ori       $v1, $v1, 0x400
/* E26B68 802B6458 E4800008 */  swc1      $f0, 8($a0)
/* E26B6C 802B645C 080AD978 */  j         .L802B65E0
/* E26B70 802B6460 AE030000 */   sw       $v1, ($s0)
.L802B6464:
/* E26B74 802B6464 8FA40010 */  lw        $a0, 0x10($sp)
/* E26B78 802B6468 0C016F6A */  jal       get_collider_type_by_id
/* E26B7C 802B646C 00000000 */   nop
/* E26B80 802B6470 304300FF */  andi      $v1, $v0, 0xff
/* E26B84 802B6474 24020003 */  addiu     $v0, $zero, 3
/* E26B88 802B6478 1462000E */  bne       $v1, $v0, .L802B64B4
/* E26B8C 802B647C 24020002 */   addiu    $v0, $zero, 2
/* E26B90 802B6480 3C05FFFD */  lui       $a1, 0xfffd
/* E26B94 802B6484 34A5FFF7 */  ori       $a1, $a1, 0xfff7
/* E26B98 802B6488 24040017 */  addiu     $a0, $zero, 0x17
/* E26B9C 802B648C 8E020000 */  lw        $v0, ($s0)
/* E26BA0 802B6490 24030001 */  addiu     $v1, $zero, 1
/* E26BA4 802B6494 A20300BF */  sb        $v1, 0xbf($s0)
/* E26BA8 802B6498 00451024 */  and       $v0, $v0, $a1
/* E26BAC 802B649C 0C039769 */  jal       set_action_state
/* E26BB0 802B64A0 AE020000 */   sw       $v0, ($s0)
/* E26BB4 802B64A4 8E020000 */  lw        $v0, ($s0)
/* E26BB8 802B64A8 34420800 */  ori       $v0, $v0, 0x800
/* E26BBC 802B64AC 080AD978 */  j         .L802B65E0
/* E26BC0 802B64B0 AE020000 */   sw       $v0, ($s0)
.L802B64B4:
/* E26BC4 802B64B4 14620009 */  bne       $v1, $v0, .L802B64DC
/* E26BC8 802B64B8 0000202D */   daddu    $a0, $zero, $zero
/* E26BCC 802B64BC 0C039769 */  jal       set_action_state
/* E26BD0 802B64C0 24040017 */   addiu    $a0, $zero, 0x17
/* E26BD4 802B64C4 3C03FFFD */  lui       $v1, 0xfffd
/* E26BD8 802B64C8 8E020000 */  lw        $v0, ($s0)
/* E26BDC 802B64CC 3463FFF7 */  ori       $v1, $v1, 0xfff7
/* E26BE0 802B64D0 00431024 */  and       $v0, $v0, $v1
/* E26BE4 802B64D4 080AD978 */  j         .L802B65E0
/* E26BE8 802B64D8 AE020000 */   sw       $v0, ($s0)
.L802B64DC:
/* E26BEC 802B64DC 0080282D */  daddu     $a1, $a0, $zero
/* E26BF0 802B64E0 24060004 */  addiu     $a2, $zero, 4
/* E26BF4 802B64E4 24020008 */  addiu     $v0, $zero, 8
/* E26BF8 802B64E8 A6020008 */  sh        $v0, 8($s0)
/* E26BFC 802B64EC 920200B6 */  lbu       $v0, 0xb6($s0)
/* E26C00 802B64F0 24030010 */  addiu     $v1, $zero, 0x10
/* E26C04 802B64F4 A60000C0 */  sh        $zero, 0xc0($s0)
/* E26C08 802B64F8 A20300B4 */  sb        $v1, 0xb4($s0)
/* E26C0C 802B64FC 24420001 */  addiu     $v0, $v0, 1
/* E26C10 802B6500 0C0B2D5B */  jal       exec_ShakeCam1
/* E26C14 802B6504 A20200B6 */   sb       $v0, 0xb6($s0)
/* E26C18 802B6508 2404014A */  addiu     $a0, $zero, 0x14a
/* E26C1C 802B650C 0C052736 */  jal       sfx_play_sound_at_player
/* E26C20 802B6510 0000282D */   daddu    $a1, $zero, $zero
/* E26C24 802B6514 24040100 */  addiu     $a0, $zero, 0x100
/* E26C28 802B6518 0C00A3C2 */  jal       start_rumble
/* E26C2C 802B651C 24050032 */   addiu    $a1, $zero, 0x32
/* E26C30 802B6520 3C048016 */  lui       $a0, %hi(D_8015A578)
/* E26C34 802B6524 2484A578 */  addiu     $a0, $a0, %lo(D_8015A578)
/* E26C38 802B6528 C600002C */  lwc1      $f0, 0x2c($s0)
/* E26C3C 802B652C 8E030000 */  lw        $v1, ($s0)
/* E26C40 802B6530 24020001 */  addiu     $v0, $zero, 1
/* E26C44 802B6534 A0820000 */  sb        $v0, ($a0)
/* E26C48 802B6538 34630400 */  ori       $v1, $v1, 0x400
/* E26C4C 802B653C E4800008 */  swc1      $f0, 8($a0)
/* E26C50 802B6540 080AD969 */  j         L802B65A4_E26CB4
/* E26C54 802B6544 AE030000 */   sw       $v1, ($s0)
glabel L802B6548_E26C58
/* E26C58 802B6548 96020008 */  lhu       $v0, 8($s0)
/* E26C5C 802B654C 2442FFFF */  addiu     $v0, $v0, -1
/* E26C60 802B6550 A6020008 */  sh        $v0, 8($s0)
/* E26C64 802B6554 00021400 */  sll       $v0, $v0, 0x10
/* E26C68 802B6558 14400012 */  bnez      $v0, L802B65A4_E26CB4
/* E26C6C 802B655C 3C02FFFD */   lui      $v0, 0xfffd
/* E26C70 802B6560 3442FFF7 */  ori       $v0, $v0, 0xfff7
/* E26C74 802B6564 2404000A */  addiu     $a0, $zero, 0xa
/* E26C78 802B6568 920300B6 */  lbu       $v1, 0xb6($s0)
/* E26C7C 802B656C 8E050000 */  lw        $a1, ($s0)
/* E26C80 802B6570 24630001 */  addiu     $v1, $v1, 1
/* E26C84 802B6574 00A22824 */  and       $a1, $a1, $v0
/* E26C88 802B6578 A20300B6 */  sb        $v1, 0xb6($s0)
/* E26C8C 802B657C 0C039769 */  jal       set_action_state
/* E26C90 802B6580 AE050000 */   sw       $a1, ($s0)
/* E26C94 802B6584 080AD969 */  j         L802B65A4_E26CB4
/* E26C98 802B6588 00000000 */   nop
glabel L802B658C_E26C9C
/* E26C9C 802B658C 0C039769 */  jal       set_action_state
/* E26CA0 802B6590 24040007 */   addiu    $a0, $zero, 7
/* E26CA4 802B6594 920200B6 */  lbu       $v0, 0xb6($s0)
/* E26CA8 802B6598 24420001 */  addiu     $v0, $v0, 1
/* E26CAC 802B659C 0C038069 */  jal       enable_player_input
/* E26CB0 802B65A0 A20200B6 */   sb       $v0, 0xb6($s0)
glabel L802B65A4_E26CB4
/* E26CB4 802B65A4 C6020070 */  lwc1      $f2, 0x70($s0)
/* E26CB8 802B65A8 44800000 */  mtc1      $zero, $f0
/* E26CBC 802B65AC 00000000 */  nop
/* E26CC0 802B65B0 4600103C */  c.lt.s    $f2, $f0
/* E26CC4 802B65B4 00000000 */  nop
/* E26CC8 802B65B8 45000009 */  bc1f      .L802B65E0
/* E26CCC 802B65BC 00000000 */   nop
/* E26CD0 802B65C0 0C0AD97E */  jal       func_802B65F8_E26D08
/* E26CD4 802B65C4 00000000 */   nop
/* E26CD8 802B65C8 04400005 */  bltz      $v0, .L802B65E0
/* E26CDC 802B65CC AFA20010 */   sw       $v0, 0x10($sp)
/* E26CE0 802B65D0 97A30012 */  lhu       $v1, 0x12($sp)
/* E26CE4 802B65D4 2402FFFF */  addiu     $v0, $zero, -1
/* E26CE8 802B65D8 A6220004 */  sh        $v0, 4($s1)
/* E26CEC 802B65DC A6230002 */  sh        $v1, 2($s1)
.L802B65E0:
/* E26CF0 802B65E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* E26CF4 802B65E4 8FB1001C */  lw        $s1, 0x1c($sp)
/* E26CF8 802B65E8 8FB00018 */  lw        $s0, 0x18($sp)
/* E26CFC 802B65EC D7B40028 */  ldc1      $f20, 0x28($sp)
/* E26D00 802B65F0 03E00008 */  jr        $ra
/* E26D04 802B65F4 27BD0030 */   addiu    $sp, $sp, 0x30

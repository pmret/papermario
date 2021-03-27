.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802B62B0_E29450
.word L802B607C_E2921C, L802B60F4_E29294, L802B6174_E29314, L802B6228_E293C8, L802B6298_E29438, L802B6250_E293F0, 0, 0

.section .text

glabel func_802B6000_E291A0
/* E291A0 802B6000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E291A4 802B6004 AFB1001C */  sw        $s1, 0x1c($sp)
/* E291A8 802B6008 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E291AC 802B600C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E291B0 802B6010 AFBF0020 */  sw        $ra, 0x20($sp)
/* E291B4 802B6014 AFB00018 */  sw        $s0, 0x18($sp)
/* E291B8 802B6018 F7B40028 */  sdc1      $f20, 0x28($sp)
/* E291BC 802B601C 8E250000 */  lw        $a1, ($s1)
/* E291C0 802B6020 04A1000D */  bgez      $a1, .L802B6058
/* E291C4 802B6024 3C027FFF */   lui      $v0, 0x7fff
/* E291C8 802B6028 3442FFFF */  ori       $v0, $v0, 0xffff
/* E291CC 802B602C 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* E291D0 802B6030 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* E291D4 802B6034 8C830000 */  lw        $v1, ($a0)
/* E291D8 802B6038 00A21024 */  and       $v0, $a1, $v0
/* E291DC 802B603C AE220000 */  sw        $v0, ($s1)
/* E291E0 802B6040 A22000B6 */  sb        $zero, 0xb6($s1)
/* E291E4 802B6044 34630040 */  ori       $v1, $v1, 0x40
/* E291E8 802B6048 0C038045 */  jal       disable_player_static_collisions
/* E291EC 802B604C AC830000 */   sw       $v1, ($a0)
/* E291F0 802B6050 0C03805E */  jal       disable_player_input
/* E291F4 802B6054 00000000 */   nop
.L802B6058:
/* E291F8 802B6058 822300B6 */  lb        $v1, 0xb6($s1)
/* E291FC 802B605C 2C620006 */  sltiu     $v0, $v1, 6
/* E29200 802B6060 1040008D */  beqz      $v0, L802B6298_E29438
/* E29204 802B6064 00031080 */   sll      $v0, $v1, 2
/* E29208 802B6068 3C01802B */  lui       $at, %hi(jtbl_802B62B0_E29450)
/* E2920C 802B606C 00220821 */  addu      $at, $at, $v0
/* E29210 802B6070 8C2262B0 */  lw        $v0, %lo(jtbl_802B62B0_E29450)($at)
/* E29214 802B6074 00400008 */  jr        $v0
/* E29218 802B6078 00000000 */   nop
glabel L802B607C_E2921C
/* E2921C 802B607C 3C040001 */  lui       $a0, 1
/* E29220 802B6080 0C037FBF */  jal       func_800DFEFC
/* E29224 802B6084 3484002E */   ori      $a0, $a0, 0x2e
/* E29228 802B6088 3C014180 */  lui       $at, 0x4180
/* E2922C 802B608C 44810000 */  mtc1      $at, $f0
/* E29230 802B6090 3C013F80 */  lui       $at, 0x3f80
/* E29234 802B6094 44811000 */  mtc1      $at, $f2
/* E29238 802B6098 3C013FF0 */  lui       $at, 0x3ff0
/* E2923C 802B609C 44812000 */  mtc1      $at, $f4
/* E29240 802B60A0 24020020 */  addiu     $v0, $zero, 0x20
/* E29244 802B60A4 3C01802B */  lui       $at, %hi(D_802B62E0)
/* E29248 802B60A8 AC2262E0 */  sw        $v0, %lo(D_802B62E0)($at)
/* E2924C 802B60AC 3C01802B */  lui       $at, %hi(D_802B62D0)
/* E29250 802B60B0 E42062D0 */  swc1      $f0, %lo(D_802B62D0)($at)
/* E29254 802B60B4 3C014080 */  lui       $at, 0x4080
/* E29258 802B60B8 44810000 */  mtc1      $at, $f0
/* E2925C 802B60BC 3C02802B */  lui       $v0, %hi(D_802B62D4)
/* E29260 802B60C0 244262D4 */  addiu     $v0, $v0, %lo(D_802B62D4)
/* E29264 802B60C4 E4400000 */  swc1      $f0, ($v0)
/* E29268 802B60C8 3C01802B */  lui       $at, %hi(D_802B62D8)
/* E2926C 802B60CC E42262D8 */  swc1      $f2, %lo(D_802B62D8)($at)
/* E29270 802B60D0 E4440000 */  swc1      $f4, ($v0)
/* E29274 802B60D4 922200B6 */  lbu       $v0, 0xb6($s1)
/* E29278 802B60D8 C6200080 */  lwc1      $f0, 0x80($s1)
/* E2927C 802B60DC 24420001 */  addiu     $v0, $v0, 1
/* E29280 802B60E0 A22200B6 */  sb        $v0, 0xb6($s1)
/* E29284 802B60E4 3C01802B */  lui       $at, %hi(D_802B62DC)
/* E29288 802B60E8 E42062DC */  swc1      $f0, %lo(D_802B62DC)($at)
/* E2928C 802B60EC 080AD8A6 */  j         L802B6298_E29438
/* E29290 802B60F0 00000000 */   nop
glabel L802B60F4_E29294
/* E29294 802B60F4 26240028 */  addiu     $a0, $s1, 0x28
/* E29298 802B60F8 3C10802B */  lui       $s0, %hi(D_802B62D0)
/* E2929C 802B60FC 261062D0 */  addiu     $s0, $s0, %lo(D_802B62D0)
/* E292A0 802B6100 C622002C */  lwc1      $f2, 0x2c($s1)
/* E292A4 802B6104 C6000000 */  lwc1      $f0, ($s0)
/* E292A8 802B6108 3C06802B */  lui       $a2, %hi(D_802B62D4)
/* E292AC 802B610C 8CC662D4 */  lw        $a2, %lo(D_802B62D4)($a2)
/* E292B0 802B6110 46001080 */  add.s     $f2, $f2, $f0
/* E292B4 802B6114 3C01802B */  lui       $at, %hi(D_802B62D8)
/* E292B8 802B6118 C42462D8 */  lwc1      $f4, %lo(D_802B62D8)($at)
/* E292BC 802B611C 3C07802B */  lui       $a3, %hi(D_802B62DC)
/* E292C0 802B6120 8CE762DC */  lw        $a3, %lo(D_802B62DC)($a3)
/* E292C4 802B6124 46040001 */  sub.s     $f0, $f0, $f4
/* E292C8 802B6128 26250030 */  addiu     $a1, $s1, 0x30
/* E292CC 802B612C E622002C */  swc1      $f2, 0x2c($s1)
/* E292D0 802B6130 0C00A7E7 */  jal       add_vec2D_polar
/* E292D4 802B6134 E6000000 */   swc1     $f0, ($s0)
/* E292D8 802B6138 3C02800B */  lui       $v0, %hi(gCameras)
/* E292DC 802B613C 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* E292E0 802B6140 C6220028 */  lwc1      $f2, 0x28($s1)
/* E292E4 802B6144 C624002C */  lwc1      $f4, 0x2c($s1)
/* E292E8 802B6148 C6080000 */  lwc1      $f8, ($s0)
/* E292EC 802B614C 44800000 */  mtc1      $zero, $f0
/* E292F0 802B6150 C6260030 */  lwc1      $f6, 0x30($s1)
/* E292F4 802B6154 4600403E */  c.le.s    $f8, $f0
/* E292F8 802B6158 E4420060 */  swc1      $f2, 0x60($v0)
/* E292FC 802B615C E4440064 */  swc1      $f4, 0x64($v0)
/* E29300 802B6160 4500004D */  bc1f      L802B6298_E29438
/* E29304 802B6164 E4460068 */   swc1     $f6, 0x68($v0)
/* E29308 802B6168 922200B6 */  lbu       $v0, 0xb6($s1)
/* E2930C 802B616C 080AD888 */  j         .L802B6220
/* E29310 802B6170 24420001 */   addiu    $v0, $v0, 1
glabel L802B6174_E29314
/* E29314 802B6174 26240028 */  addiu     $a0, $s1, 0x28
/* E29318 802B6178 3C10802B */  lui       $s0, %hi(D_802B62D0)
/* E2931C 802B617C 261062D0 */  addiu     $s0, $s0, %lo(D_802B62D0)
/* E29320 802B6180 C622002C */  lwc1      $f2, 0x2c($s1)
/* E29324 802B6184 C6000000 */  lwc1      $f0, ($s0)
/* E29328 802B6188 3C06802B */  lui       $a2, %hi(D_802B62D4)
/* E2932C 802B618C 8CC662D4 */  lw        $a2, %lo(D_802B62D4)($a2)
/* E29330 802B6190 46001080 */  add.s     $f2, $f2, $f0
/* E29334 802B6194 3C01802B */  lui       $at, %hi(D_802B62D8)
/* E29338 802B6198 C42462D8 */  lwc1      $f4, %lo(D_802B62D8)($at)
/* E2933C 802B619C 3C07802B */  lui       $a3, %hi(D_802B62DC)
/* E29340 802B61A0 8CE762DC */  lw        $a3, %lo(D_802B62DC)($a3)
/* E29344 802B61A4 46040001 */  sub.s     $f0, $f0, $f4
/* E29348 802B61A8 26250030 */  addiu     $a1, $s1, 0x30
/* E2934C 802B61AC E622002C */  swc1      $f2, 0x2c($s1)
/* E29350 802B61B0 0C00A7E7 */  jal       add_vec2D_polar
/* E29354 802B61B4 E6000000 */   swc1     $f0, ($s0)
/* E29358 802B61B8 27A50010 */  addiu     $a1, $sp, 0x10
/* E2935C 802B61BC C6200028 */  lwc1      $f0, 0x28($s1)
/* E29360 802B61C0 C622002C */  lwc1      $f2, 0x2c($s1)
/* E29364 802B61C4 C6240030 */  lwc1      $f4, 0x30($s1)
/* E29368 802B61C8 C60C0000 */  lwc1      $f12, ($s0)
/* E2936C 802B61CC 3C02800B */  lui       $v0, %hi(gCameras)
/* E29370 802B61D0 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* E29374 802B61D4 E4400060 */  swc1      $f0, 0x60($v0)
/* E29378 802B61D8 E4420064 */  swc1      $f2, 0x64($v0)
/* E2937C 802B61DC 0C038D45 */  jal       func_800E3514
/* E29380 802B61E0 E4440068 */   swc1     $f4, 0x68($v0)
/* E29384 802B61E4 8FA20010 */  lw        $v0, 0x10($sp)
/* E29388 802B61E8 0440002B */  bltz      $v0, L802B6298_E29438
/* E2938C 802B61EC 46000506 */   mov.s    $f20, $f0
/* E29390 802B61F0 24040162 */  addiu     $a0, $zero, 0x162
/* E29394 802B61F4 0C052736 */  jal       sfx_play_sound_at_player
/* E29398 802B61F8 0000282D */   daddu    $a1, $zero, $zero
/* E2939C 802B61FC 3C040008 */  lui       $a0, 8
/* E293A0 802B6200 0C037FDE */  jal       func_800DFF78
/* E293A4 802B6204 34840003 */   ori      $a0, $a0, 3
/* E293A8 802B6208 922200B6 */  lbu       $v0, 0xb6($s1)
/* E293AC 802B620C 2403000A */  addiu     $v1, $zero, 0xa
/* E293B0 802B6210 E634002C */  swc1      $f20, 0x2c($s1)
/* E293B4 802B6214 3C01802B */  lui       $at, %hi(D_802B62E0)
/* E293B8 802B6218 AC2362E0 */  sw        $v1, %lo(D_802B62E0)($at)
/* E293BC 802B621C 24420001 */  addiu     $v0, $v0, 1
.L802B6220:
/* E293C0 802B6220 080AD8A6 */  j         L802B6298_E29438
/* E293C4 802B6224 A22200B6 */   sb       $v0, 0xb6($s1)
glabel L802B6228_E293C8
/* E293C8 802B6228 962200BC */  lhu       $v0, 0xbc($s1)
/* E293CC 802B622C 1040001A */  beqz      $v0, L802B6298_E29438
/* E293D0 802B6230 3C040001 */   lui      $a0, 1
/* E293D4 802B6234 0C037FDE */  jal       func_800DFF78
/* E293D8 802B6238 34840030 */   ori      $a0, $a0, 0x30
/* E293DC 802B623C 24020005 */  addiu     $v0, $zero, 5
/* E293E0 802B6240 A22200B6 */  sb        $v0, 0xb6($s1)
/* E293E4 802B6244 2402000F */  addiu     $v0, $zero, 0xf
/* E293E8 802B6248 080AD8A6 */  j         L802B6298_E29438
/* E293EC 802B624C A6220008 */   sh       $v0, 8($s1)
glabel L802B6250_E293F0
/* E293F0 802B6250 86220008 */  lh        $v0, 8($s1)
/* E293F4 802B6254 96230008 */  lhu       $v1, 8($s1)
/* E293F8 802B6258 10400003 */  beqz      $v0, .L802B6268
/* E293FC 802B625C 2462FFFF */   addiu    $v0, $v1, -1
/* E29400 802B6260 080AD8A6 */  j         L802B6298_E29438
/* E29404 802B6264 A6220008 */   sh       $v0, 8($s1)
.L802B6268:
/* E29408 802B6268 0C038050 */  jal       enable_player_static_collisions
/* E2940C 802B626C 00000000 */   nop
/* E29410 802B6270 0C038069 */  jal       enable_player_input
/* E29414 802B6274 00000000 */   nop
/* E29418 802B6278 0C039769 */  jal       set_action_state
/* E2941C 802B627C 0000202D */   daddu    $a0, $zero, $zero
/* E29420 802B6280 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* E29424 802B6284 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* E29428 802B6288 8C430000 */  lw        $v1, ($v0)
/* E2942C 802B628C 2404FFBF */  addiu     $a0, $zero, -0x41
/* E29430 802B6290 00641824 */  and       $v1, $v1, $a0
/* E29434 802B6294 AC430000 */  sw        $v1, ($v0)
glabel L802B6298_E29438
/* E29438 802B6298 8FBF0020 */  lw        $ra, 0x20($sp)
/* E2943C 802B629C 8FB1001C */  lw        $s1, 0x1c($sp)
/* E29440 802B62A0 8FB00018 */  lw        $s0, 0x18($sp)
/* E29444 802B62A4 D7B40028 */  ldc1      $f20, 0x28($sp)
/* E29448 802B62A8 03E00008 */  jr        $ra
/* E2944C 802B62AC 27BD0030 */   addiu    $sp, $sp, 0x30

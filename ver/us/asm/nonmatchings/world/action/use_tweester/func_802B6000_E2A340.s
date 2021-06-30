.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802B6360_E2A6A0
.double 0.6, 0.0

.section .text

glabel func_802B6000_E2A340
/* E2A340 802B6000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E2A344 802B6004 AFB1001C */  sw        $s1, 0x1c($sp)
/* E2A348 802B6008 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E2A34C 802B600C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E2A350 802B6010 AFBF0024 */  sw        $ra, 0x24($sp)
/* E2A354 802B6014 AFB20020 */  sw        $s2, 0x20($sp)
/* E2A358 802B6018 AFB00018 */  sw        $s0, 0x18($sp)
/* E2A35C 802B601C F7B40028 */  sdc1      $f20, 0x28($sp)
/* E2A360 802B6020 8E230000 */  lw        $v1, ($s1)
/* E2A364 802B6024 3C128011 */  lui       $s2, %hi(D_8010C934)
/* E2A368 802B6028 8E52C934 */  lw        $s2, %lo(D_8010C934)($s2)
/* E2A36C 802B602C 0461002F */  bgez      $v1, .L802B60EC
/* E2A370 802B6030 3C027FFF */   lui      $v0, 0x7fff
/* E2A374 802B6034 3442FFFF */  ori       $v0, $v0, 0xffff
/* E2A378 802B6038 00621024 */  and       $v0, $v1, $v0
/* E2A37C 802B603C 0C038045 */  jal       disable_player_static_collisions
/* E2A380 802B6040 AE220000 */   sw       $v0, ($s1)
/* E2A384 802B6044 0C03805E */  jal       disable_player_input
/* E2A388 802B6048 00000000 */   nop
/* E2A38C 802B604C 3C030010 */  lui       $v1, 0x10
/* E2A390 802B6050 34630008 */  ori       $v1, $v1, 8
/* E2A394 802B6054 3C040008 */  lui       $a0, 8
/* E2A398 802B6058 8E220000 */  lw        $v0, ($s1)
/* E2A39C 802B605C 3484001F */  ori       $a0, $a0, 0x1f
/* E2A3A0 802B6060 00431025 */  or        $v0, $v0, $v1
/* E2A3A4 802B6064 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E2A3A8 802B6068 AE220000 */   sw       $v0, ($s1)
/* E2A3AC 802B606C 3C10802B */  lui       $s0, %hi(D_802B6350_E2A690)
/* E2A3B0 802B6070 26106350 */  addiu     $s0, $s0, %lo(D_802B6350_E2A690)
/* E2A3B4 802B6074 8E040000 */  lw        $a0, ($s0)
/* E2A3B8 802B6078 2405001C */  addiu     $a1, $zero, 0x1c
/* E2A3BC 802B607C 0C00A580 */  jal       mem_clear
/* E2A3C0 802B6080 A22000B6 */   sb       $zero, 0xb6($s1)
/* E2A3C4 802B6084 C62C0028 */  lwc1      $f12, 0x28($s1)
/* E2A3C8 802B6088 C62E0030 */  lwc1      $f14, 0x30($s1)
/* E2A3CC 802B608C 8E460048 */  lw        $a2, 0x48($s2)
/* E2A3D0 802B6090 0C00A7B5 */  jal       dist2D
/* E2A3D4 802B6094 8E470050 */   lw       $a3, 0x50($s2)
/* E2A3D8 802B6098 8E020000 */  lw        $v0, ($s0)
/* E2A3DC 802B609C 46000005 */  abs.s     $f0, $f0
/* E2A3E0 802B60A0 E440000C */  swc1      $f0, 0xc($v0)
/* E2A3E4 802B60A4 C64C0048 */  lwc1      $f12, 0x48($s2)
/* E2A3E8 802B60A8 C64E0050 */  lwc1      $f14, 0x50($s2)
/* E2A3EC 802B60AC 8E260028 */  lw        $a2, 0x28($s1)
/* E2A3F0 802B60B0 0C00A720 */  jal       atan2
/* E2A3F4 802B60B4 8E270030 */   lw       $a3, 0x30($s1)
/* E2A3F8 802B60B8 240402F6 */  addiu     $a0, $zero, 0x2f6
/* E2A3FC 802B60BC 0000282D */  daddu     $a1, $zero, $zero
/* E2A400 802B60C0 8E030000 */  lw        $v1, ($s0)
/* E2A404 802B60C4 3C0140C0 */  lui       $at, 0x40c0
/* E2A408 802B60C8 44811000 */  mtc1      $at, $f2
/* E2A40C 802B60CC 3C014248 */  lui       $at, 0x4248
/* E2A410 802B60D0 44812000 */  mtc1      $at, $f4
/* E2A414 802B60D4 24020078 */  addiu     $v0, $zero, 0x78
/* E2A418 802B60D8 E4600010 */  swc1      $f0, 0x10($v1)
/* E2A41C 802B60DC E4620014 */  swc1      $f2, 0x14($v1)
/* E2A420 802B60E0 E4640018 */  swc1      $f4, 0x18($v1)
/* E2A424 802B60E4 0C052736 */  jal       sfx_play_sound_at_player
/* E2A428 802B60E8 AC620000 */   sw       $v0, ($v1)
.L802B60EC:
/* E2A42C 802B60EC 822300B6 */  lb        $v1, 0xb6($s1)
/* E2A430 802B60F0 10600005 */  beqz      $v1, .L802B6108
/* E2A434 802B60F4 24020001 */   addiu    $v0, $zero, 1
/* E2A438 802B60F8 1062007A */  beq       $v1, $v0, .L802B62E4
/* E2A43C 802B60FC 00000000 */   nop
/* E2A440 802B6100 080AD8CB */  j         .L802B632C
/* E2A444 802B6104 00000000 */   nop
.L802B6108:
/* E2A448 802B6108 3C10802B */  lui       $s0, %hi(D_802B6350_E2A690)
/* E2A44C 802B610C 26106350 */  addiu     $s0, $s0, %lo(D_802B6350_E2A690)
/* E2A450 802B6110 8E020000 */  lw        $v0, ($s0)
/* E2A454 802B6114 3C0140C9 */  lui       $at, 0x40c9
/* E2A458 802B6118 34210FD0 */  ori       $at, $at, 0xfd0
/* E2A45C 802B611C 44810000 */  mtc1      $at, $f0
/* E2A460 802B6120 C44C0010 */  lwc1      $f12, 0x10($v0)
/* E2A464 802B6124 46006302 */  mul.s     $f12, $f12, $f0
/* E2A468 802B6128 00000000 */  nop
/* E2A46C 802B612C 27A50010 */  addiu     $a1, $sp, 0x10
/* E2A470 802B6130 3C0143B4 */  lui       $at, 0x43b4
/* E2A474 802B6134 44810000 */  mtc1      $at, $f0
/* E2A478 802B6138 27A60014 */  addiu     $a2, $sp, 0x14
/* E2A47C 802B613C 0C00A82D */  jal       sin_cos_rad
/* E2A480 802B6140 46006303 */   div.s    $f12, $f12, $f0
/* E2A484 802B6144 8E020000 */  lw        $v0, ($s0)
/* E2A488 802B6148 C7A20010 */  lwc1      $f2, 0x10($sp)
/* E2A48C 802B614C C440000C */  lwc1      $f0, 0xc($v0)
/* E2A490 802B6150 46001082 */  mul.s     $f2, $f2, $f0
/* E2A494 802B6154 00000000 */  nop
/* E2A498 802B6158 C6400048 */  lwc1      $f0, 0x48($s2)
/* E2A49C 802B615C 46020000 */  add.s     $f0, $f0, $f2
/* E2A4A0 802B6160 E6200028 */  swc1      $f0, 0x28($s1)
/* E2A4A4 802B6164 C7A20014 */  lwc1      $f2, 0x14($sp)
/* E2A4A8 802B6168 C440000C */  lwc1      $f0, 0xc($v0)
/* E2A4AC 802B616C 46001082 */  mul.s     $f2, $f2, $f0
/* E2A4B0 802B6170 00000000 */  nop
/* E2A4B4 802B6174 C6400050 */  lwc1      $f0, 0x50($s2)
/* E2A4B8 802B6178 46020001 */  sub.s     $f0, $f0, $f2
/* E2A4BC 802B617C E6200030 */  swc1      $f0, 0x30($s1)
/* E2A4C0 802B6180 C4400010 */  lwc1      $f0, 0x10($v0)
/* E2A4C4 802B6184 C44C0014 */  lwc1      $f12, 0x14($v0)
/* E2A4C8 802B6188 0C00A6C9 */  jal       clamp_angle
/* E2A4CC 802B618C 460C0301 */   sub.s    $f12, $f0, $f12
/* E2A4D0 802B6190 8E100000 */  lw        $s0, ($s0)
/* E2A4D4 802B6194 3C0141A0 */  lui       $at, 0x41a0
/* E2A4D8 802B6198 44811000 */  mtc1      $at, $f2
/* E2A4DC 802B619C C604000C */  lwc1      $f4, 0xc($s0)
/* E2A4E0 802B61A0 4604103C */  c.lt.s    $f2, $f4
/* E2A4E4 802B61A4 00000000 */  nop
/* E2A4E8 802B61A8 45000005 */  bc1f      .L802B61C0
/* E2A4EC 802B61AC E6000010 */   swc1     $f0, 0x10($s0)
/* E2A4F0 802B61B0 3C013F80 */  lui       $at, 0x3f80
/* E2A4F4 802B61B4 44810000 */  mtc1      $at, $f0
/* E2A4F8 802B61B8 080AD87B */  j         .L802B61EC
/* E2A4FC 802B61BC 46002001 */   sub.s    $f0, $f4, $f0
.L802B61C0:
/* E2A500 802B61C0 3C014198 */  lui       $at, 0x4198
/* E2A504 802B61C4 44810000 */  mtc1      $at, $f0
/* E2A508 802B61C8 00000000 */  nop
/* E2A50C 802B61CC 4600203C */  c.lt.s    $f4, $f0
/* E2A510 802B61D0 00000000 */  nop
/* E2A514 802B61D4 45000006 */  bc1f      .L802B61F0
/* E2A518 802B61D8 00000000 */   nop
/* E2A51C 802B61DC 3C013F80 */  lui       $at, 0x3f80
/* E2A520 802B61E0 44810000 */  mtc1      $at, $f0
/* E2A524 802B61E4 00000000 */  nop
/* E2A528 802B61E8 46002000 */  add.s     $f0, $f4, $f0
.L802B61EC:
/* E2A52C 802B61EC E600000C */  swc1      $f0, 0xc($s0)
.L802B61F0:
/* E2A530 802B61F0 3C10802B */  lui       $s0, %hi(D_802B6350_E2A690)
/* E2A534 802B61F4 26106350 */  addiu     $s0, $s0, %lo(D_802B6350_E2A690)
/* E2A538 802B61F8 8E020000 */  lw        $v0, ($s0)
/* E2A53C 802B61FC 3C0140C9 */  lui       $at, 0x40c9
/* E2A540 802B6200 34210FD0 */  ori       $at, $at, 0xfd0
/* E2A544 802B6204 44810000 */  mtc1      $at, $f0
/* E2A548 802B6208 C44C0018 */  lwc1      $f12, 0x18($v0)
/* E2A54C 802B620C 46006302 */  mul.s     $f12, $f12, $f0
/* E2A550 802B6210 00000000 */  nop
/* E2A554 802B6214 3C0143B4 */  lui       $at, 0x43b4
/* E2A558 802B6218 4481A000 */  mtc1      $at, $f20
/* E2A55C 802B621C 0C00A85B */  jal       sin_rad
/* E2A560 802B6220 46146303 */   div.s    $f12, $f12, $f20
/* E2A564 802B6224 8E020000 */  lw        $v0, ($s0)
/* E2A568 802B6228 3C014040 */  lui       $at, 0x4040
/* E2A56C 802B622C 44812000 */  mtc1      $at, $f4
/* E2A570 802B6230 C4420018 */  lwc1      $f2, 0x18($v0)
/* E2A574 802B6234 46041080 */  add.s     $f2, $f2, $f4
/* E2A578 802B6238 3C014316 */  lui       $at, 0x4316
/* E2A57C 802B623C 44813000 */  mtc1      $at, $f6
/* E2A580 802B6240 00000000 */  nop
/* E2A584 802B6244 4602303C */  c.lt.s    $f6, $f2
/* E2A588 802B6248 E4420018 */  swc1      $f2, 0x18($v0)
/* E2A58C 802B624C 46040082 */  mul.s     $f2, $f0, $f4
/* E2A590 802B6250 00000000 */  nop
/* E2A594 802B6254 45030001 */  bc1tl     .L802B625C
/* E2A598 802B6258 E4460018 */   swc1     $f6, 0x18($v0)
.L802B625C:
/* E2A59C 802B625C C620002C */  lwc1      $f0, 0x2c($s1)
/* E2A5A0 802B6260 46020000 */  add.s     $f0, $f0, $f2
/* E2A5A4 802B6264 8E020000 */  lw        $v0, ($s0)
/* E2A5A8 802B6268 E620002C */  swc1      $f0, 0x2c($s1)
/* E2A5AC 802B626C C44C0010 */  lwc1      $f12, 0x10($v0)
/* E2A5B0 802B6270 0C00A6C9 */  jal       clamp_angle
/* E2A5B4 802B6274 460CA301 */   sub.s    $f12, $f20, $f12
/* E2A5B8 802B6278 8E020000 */  lw        $v0, ($s0)
/* E2A5BC 802B627C E62000A8 */  swc1      $f0, 0xa8($s1)
/* E2A5C0 802B6280 C4400014 */  lwc1      $f0, 0x14($v0)
/* E2A5C4 802B6284 3C01802B */  lui       $at, %hi(D_802B6360_E2A6A0)
/* E2A5C8 802B6288 D4226360 */  ldc1      $f2, %lo(D_802B6360_E2A6A0)($at)
/* E2A5CC 802B628C 46000021 */  cvt.d.s   $f0, $f0
/* E2A5D0 802B6290 46220000 */  add.d     $f0, $f0, $f2
/* E2A5D4 802B6294 3C014220 */  lui       $at, 0x4220
/* E2A5D8 802B6298 44811000 */  mtc1      $at, $f2
/* E2A5DC 802B629C 46200020 */  cvt.s.d   $f0, $f0
/* E2A5E0 802B62A0 4600103C */  c.lt.s    $f2, $f0
/* E2A5E4 802B62A4 00000000 */  nop
/* E2A5E8 802B62A8 45000002 */  bc1f      .L802B62B4
/* E2A5EC 802B62AC E4400014 */   swc1     $f0, 0x14($v0)
/* E2A5F0 802B62B0 E4420014 */  swc1      $f2, 0x14($v0)
.L802B62B4:
/* E2A5F4 802B62B4 8E030000 */  lw        $v1, ($s0)
/* E2A5F8 802B62B8 8C620000 */  lw        $v0, ($v1)
/* E2A5FC 802B62BC 2442FFFF */  addiu     $v0, $v0, -1
/* E2A600 802B62C0 1440001A */  bnez      $v0, .L802B632C
/* E2A604 802B62C4 AC620000 */   sw       $v0, ($v1)
/* E2A608 802B62C8 922200B6 */  lbu       $v0, 0xb6($s1)
/* E2A60C 802B62CC 0240202D */  daddu     $a0, $s2, $zero
/* E2A610 802B62D0 24420001 */  addiu     $v0, $v0, 1
/* E2A614 802B62D4 0C04419E */  jal       entity_start_script
/* E2A618 802B62D8 A22200B6 */   sb       $v0, 0xb6($s1)
/* E2A61C 802B62DC 080AD8CB */  j         .L802B632C
/* E2A620 802B62E0 00000000 */   nop
.L802B62E4:
/* E2A624 802B62E4 0C038039 */  jal       disable_player_shadow
/* E2A628 802B62E8 00000000 */   nop
/* E2A62C 802B62EC 3C048011 */  lui       $a0, %hi(wPartnerNpc)
/* E2A630 802B62F0 8C84C930 */  lw        $a0, %lo(wPartnerNpc)($a0)
/* E2A634 802B62F4 0C00EAFF */  jal       disable_npc_shadow
/* E2A638 802B62F8 00000000 */   nop
/* E2A63C 802B62FC 24020032 */  addiu     $v0, $zero, 0x32
/* E2A640 802B6300 0C038050 */  jal       enable_player_static_collisions
/* E2A644 802B6304 A6220010 */   sh       $v0, 0x10($s1)
/* E2A648 802B6308 0C038069 */  jal       enable_player_input
/* E2A64C 802B630C 00000000 */   nop
/* E2A650 802B6310 3C03FFEF */  lui       $v1, 0xffef
/* E2A654 802B6314 3463FFF7 */  ori       $v1, $v1, 0xfff7
/* E2A658 802B6318 8E220000 */  lw        $v0, ($s1)
/* E2A65C 802B631C 0000202D */  daddu     $a0, $zero, $zero
/* E2A660 802B6320 00431024 */  and       $v0, $v0, $v1
/* E2A664 802B6324 0C039769 */  jal       set_action_state
/* E2A668 802B6328 AE220000 */   sw       $v0, ($s1)
.L802B632C:
/* E2A66C 802B632C 8FBF0024 */  lw        $ra, 0x24($sp)
/* E2A670 802B6330 8FB20020 */  lw        $s2, 0x20($sp)
/* E2A674 802B6334 8FB1001C */  lw        $s1, 0x1c($sp)
/* E2A678 802B6338 8FB00018 */  lw        $s0, 0x18($sp)
/* E2A67C 802B633C D7B40028 */  ldc1      $f20, 0x28($sp)
/* E2A680 802B6340 03E00008 */  jr        $ra
/* E2A684 802B6344 27BD0030 */   addiu    $sp, $sp, 0x30
/* E2A688 802B6348 00000000 */  nop
/* E2A68C 802B634C 00000000 */  nop

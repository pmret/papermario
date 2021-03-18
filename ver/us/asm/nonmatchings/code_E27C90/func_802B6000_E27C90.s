.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E27C90
/* E27C90 802B6000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E27C94 802B6004 AFB00020 */  sw        $s0, 0x20($sp)
/* E27C98 802B6008 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E27C9C 802B600C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E27CA0 802B6010 AFBF0028 */  sw        $ra, 0x28($sp)
/* E27CA4 802B6014 AFB10024 */  sw        $s1, 0x24($sp)
/* E27CA8 802B6018 8E020000 */  lw        $v0, ($s0)
/* E27CAC 802B601C 04410048 */  bgez      $v0, .L802B6140
/* E27CB0 802B6020 0200882D */   daddu    $s1, $s0, $zero
/* E27CB4 802B6024 3C037FFF */  lui       $v1, 0x7fff
/* E27CB8 802B6028 3463FFFF */  ori       $v1, $v1, 0xffff
/* E27CBC 802B602C 3C040001 */  lui       $a0, 1
/* E27CC0 802B6030 00431824 */  and       $v1, $v0, $v1
/* E27CC4 802B6034 8E020004 */  lw        $v0, 4($s0)
/* E27CC8 802B6038 34840019 */  ori       $a0, $a0, 0x19
/* E27CCC 802B603C AE030000 */  sw        $v1, ($s0)
/* E27CD0 802B6040 34630808 */  ori       $v1, $v1, 0x808
/* E27CD4 802B6044 AE030000 */  sw        $v1, ($s0)
/* E27CD8 802B6048 34420004 */  ori       $v0, $v0, 4
/* E27CDC 802B604C 0C037FDE */  jal       func_800DFF78
/* E27CE0 802B6050 AE020004 */   sw       $v0, 4($s0)
/* E27CE4 802B6054 C60C0028 */  lwc1      $f12, 0x28($s0)
/* E27CE8 802B6058 C60E0030 */  lwc1      $f14, 0x30($s0)
/* E27CEC 802B605C 3C014192 */  lui       $at, 0x4192
/* E27CF0 802B6060 3421C745 */  ori       $at, $at, 0xc745
/* E27CF4 802B6064 44811000 */  mtc1      $at, $f2
/* E27CF8 802B6068 3C01C06F */  lui       $at, 0xc06f
/* E27CFC 802B606C 34213B64 */  ori       $at, $at, 0x3b64
/* E27D00 802B6070 44812000 */  mtc1      $at, $f4
/* E27D04 802B6074 3C013F4E */  lui       $at, 0x3f4e
/* E27D08 802B6078 34214F76 */  ori       $at, $at, 0x4f76
/* E27D0C 802B607C 44813000 */  mtc1      $at, $f6
/* E27D10 802B6080 86020016 */  lh        $v0, 0x16($s0)
/* E27D14 802B6084 3C01BDCA */  lui       $at, 0xbdca
/* E27D18 802B6088 3421233A */  ori       $at, $at, 0x233a
/* E27D1C 802B608C 44810000 */  mtc1      $at, $f0
/* E27D20 802B6090 8604001A */  lh        $a0, 0x1a($s0)
/* E27D24 802B6094 3C03800B */  lui       $v1, %hi(gCameras)
/* E27D28 802B6098 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* E27D2C 802B609C A20000B6 */  sb        $zero, 0xb6($s0)
/* E27D30 802B60A0 44824000 */  mtc1      $v0, $f8
/* E27D34 802B60A4 00000000 */  nop
/* E27D38 802B60A8 46804220 */  cvt.s.w   $f8, $f8
/* E27D3C 802B60AC 44064000 */  mfc1      $a2, $f8
/* E27D40 802B60B0 44844000 */  mtc1      $a0, $f8
/* E27D44 802B60B4 00000000 */  nop
/* E27D48 802B60B8 46804220 */  cvt.s.w   $f8, $f8
/* E27D4C 802B60BC E6020070 */  swc1      $f2, 0x70($s0)
/* E27D50 802B60C0 E6040074 */  swc1      $f4, 0x74($s0)
/* E27D54 802B60C4 E6060078 */  swc1      $f6, 0x78($s0)
/* E27D58 802B60C8 E600007C */  swc1      $f0, 0x7c($s0)
/* E27D5C 802B60CC 94620002 */  lhu       $v0, 2($v1)
/* E27D60 802B60D0 44074000 */  mfc1      $a3, $f8
/* E27D64 802B60D4 34420001 */  ori       $v0, $v0, 1
/* E27D68 802B60D8 0C00A720 */  jal       atan2
/* E27D6C 802B60DC A4620002 */   sh       $v0, 2($v1)
/* E27D70 802B60E0 86020016 */  lh        $v0, 0x16($s0)
/* E27D74 802B60E4 8603001A */  lh        $v1, 0x1a($s0)
/* E27D78 802B60E8 3C01802B */  lui       $at, %hi(D_802B62B0)
/* E27D7C 802B60EC E42062B0 */  swc1      $f0, %lo(D_802B62B0)($at)
/* E27D80 802B60F0 44826000 */  mtc1      $v0, $f12
/* E27D84 802B60F4 00000000 */  nop
/* E27D88 802B60F8 46806320 */  cvt.s.w   $f12, $f12
/* E27D8C 802B60FC 44837000 */  mtc1      $v1, $f14
/* E27D90 802B6100 00000000 */  nop
/* E27D94 802B6104 0C038022 */  jal       func_800E0088
/* E27D98 802B6108 468073A0 */   cvt.s.w  $f14, $f14
/* E27D9C 802B610C 3C014190 */  lui       $at, 0x4190
/* E27DA0 802B6110 44811000 */  mtc1      $at, $f2
/* E27DA4 802B6114 24040001 */  addiu     $a0, $zero, 1
/* E27DA8 802B6118 46020003 */  div.s     $f0, $f0, $f2
/* E27DAC 802B611C 0C03A8CD */  jal       subtract_hp
/* E27DB0 802B6120 E6000054 */   swc1     $f0, 0x54($s0)
/* E27DB4 802B6124 0C03A5D8 */  jal       open_status_menu_long
/* E27DB8 802B6128 00000000 */   nop
/* E27DBC 802B612C 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* E27DC0 802B6130 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* E27DC4 802B6134 8C620000 */  lw        $v0, ($v1)
/* E27DC8 802B6138 34420040 */  ori       $v0, $v0, 0x40
/* E27DCC 802B613C AC620000 */  sw        $v0, ($v1)
.L802B6140:
/* E27DD0 802B6140 3C01802B */  lui       $at, %hi(D_802B62B0)
/* E27DD4 802B6144 C42C62B0 */  lwc1      $f12, %lo(D_802B62B0)($at)
/* E27DD8 802B6148 3C0140C9 */  lui       $at, 0x40c9
/* E27DDC 802B614C 34210FD0 */  ori       $at, $at, 0xfd0
/* E27DE0 802B6150 44810000 */  mtc1      $at, $f0
/* E27DE4 802B6154 00000000 */  nop
/* E27DE8 802B6158 46006302 */  mul.s     $f12, $f12, $f0
/* E27DEC 802B615C 00000000 */  nop
/* E27DF0 802B6160 27A50010 */  addiu     $a1, $sp, 0x10
/* E27DF4 802B6164 3C0143B4 */  lui       $at, 0x43b4
/* E27DF8 802B6168 44810000 */  mtc1      $at, $f0
/* E27DFC 802B616C 27A60014 */  addiu     $a2, $sp, 0x14
/* E27E00 802B6170 0C00A82D */  jal       sin_cos_rad
/* E27E04 802B6174 46006303 */   div.s    $f12, $f12, $f0
/* E27E08 802B6178 3C030004 */  lui       $v1, 4
/* E27E0C 802B617C 8E020000 */  lw        $v0, ($s0)
/* E27E10 802B6180 C6060054 */  lwc1      $f6, 0x54($s0)
/* E27E14 802B6184 00431024 */  and       $v0, $v0, $v1
/* E27E18 802B6188 10400008 */  beqz      $v0, .L802B61AC
/* E27E1C 802B618C 00000000 */   nop
/* E27E20 802B6190 3C013FE0 */  lui       $at, 0x3fe0
/* E27E24 802B6194 44811800 */  mtc1      $at, $f3
/* E27E28 802B6198 44801000 */  mtc1      $zero, $f2
/* E27E2C 802B619C 46003021 */  cvt.d.s   $f0, $f6
/* E27E30 802B61A0 46220002 */  mul.d     $f0, $f0, $f2
/* E27E34 802B61A4 00000000 */  nop
/* E27E38 802B61A8 462001A0 */  cvt.s.d   $f6, $f0
.L802B61AC:
/* E27E3C 802B61AC C7A00010 */  lwc1      $f0, 0x10($sp)
/* E27E40 802B61B0 46003002 */  mul.s     $f0, $f6, $f0
/* E27E44 802B61B4 00000000 */  nop
/* E27E48 802B61B8 C7A40014 */  lwc1      $f4, 0x14($sp)
/* E27E4C 802B61BC 46043102 */  mul.s     $f4, $f6, $f4
/* E27E50 802B61C0 00000000 */  nop
/* E27E54 802B61C4 C6020028 */  lwc1      $f2, 0x28($s0)
/* E27E58 802B61C8 46001080 */  add.s     $f2, $f2, $f0
/* E27E5C 802B61CC C6000030 */  lwc1      $f0, 0x30($s0)
/* E27E60 802B61D0 820200B6 */  lb        $v0, 0xb6($s0)
/* E27E64 802B61D4 46040001 */  sub.s     $f0, $f0, $f4
/* E27E68 802B61D8 E6020028 */  swc1      $f2, 0x28($s0)
/* E27E6C 802B61DC 14400012 */  bnez      $v0, .L802B6228
/* E27E70 802B61E0 E6000030 */   swc1     $f0, 0x30($s0)
/* E27E74 802B61E4 0C038D12 */  jal       integrate_gravity
/* E27E78 802B61E8 00000000 */   nop
/* E27E7C 802B61EC C600002C */  lwc1      $f0, 0x2c($s0)
/* E27E80 802B61F0 C6040070 */  lwc1      $f4, 0x70($s0)
/* E27E84 802B61F4 46040000 */  add.s     $f0, $f0, $f4
/* E27E88 802B61F8 44801000 */  mtc1      $zero, $f2
/* E27E8C 802B61FC 00000000 */  nop
/* E27E90 802B6200 4602203C */  c.lt.s    $f4, $f2
/* E27E94 802B6204 00000000 */  nop
/* E27E98 802B6208 45000021 */  bc1f      .L802B6290
/* E27E9C 802B620C E600002C */   swc1     $f0, 0x2c($s0)
/* E27EA0 802B6210 8E020000 */  lw        $v0, ($s0)
/* E27EA4 802B6214 24030001 */  addiu     $v1, $zero, 1
/* E27EA8 802B6218 A20300B6 */  sb        $v1, 0xb6($s0)
/* E27EAC 802B621C 34420004 */  ori       $v0, $v0, 4
/* E27EB0 802B6220 080AD8A4 */  j         .L802B6290
/* E27EB4 802B6224 AE020000 */   sw       $v0, ($s0)
.L802B6228:
/* E27EB8 802B6228 0C038D36 */  jal       func_800E34D8
/* E27EBC 802B622C 00000000 */   nop
/* E27EC0 802B6230 46000306 */  mov.s     $f12, $f0
/* E27EC4 802B6234 0C038D45 */  jal       func_800E3514
/* E27EC8 802B6238 27A50018 */   addiu    $a1, $sp, 0x18
/* E27ECC 802B623C 8FA40018 */  lw        $a0, 0x18($sp)
/* E27ED0 802B6240 04800013 */  bltz      $a0, .L802B6290
/* E27ED4 802B6244 E620002C */   swc1     $f0, 0x2c($s1)
/* E27ED8 802B6248 0C016F6A */  jal       get_collider_type_by_id
/* E27EDC 802B624C 00000000 */   nop
/* E27EE0 802B6250 2404000A */  addiu     $a0, $zero, 0xa
/* E27EE4 802B6254 0C039769 */  jal       set_action_state
/* E27EE8 802B6258 AFA20018 */   sw       $v0, 0x18($sp)
/* E27EEC 802B625C 2402003C */  addiu     $v0, $zero, 0x3c
/* E27EF0 802B6260 2403F7FF */  addiu     $v1, $zero, -0x801
/* E27EF4 802B6264 A6220010 */  sh        $v0, 0x10($s1)
/* E27EF8 802B6268 8E220000 */  lw        $v0, ($s1)
/* E27EFC 802B626C 3C04800A */  lui       $a0, %hi(gOverrideFlags)
/* E27F00 802B6270 2484A650 */  addiu     $a0, $a0, %lo(gOverrideFlags)
/* E27F04 802B6274 A22000BF */  sb        $zero, 0xbf($s1)
/* E27F08 802B6278 00431024 */  and       $v0, $v0, $v1
/* E27F0C 802B627C AE220000 */  sw        $v0, ($s1)
/* E27F10 802B6280 8C820000 */  lw        $v0, ($a0)
/* E27F14 802B6284 2403FFBF */  addiu     $v1, $zero, -0x41
/* E27F18 802B6288 00431024 */  and       $v0, $v0, $v1
/* E27F1C 802B628C AC820000 */  sw        $v0, ($a0)
.L802B6290:
/* E27F20 802B6290 8FBF0028 */  lw        $ra, 0x28($sp)
/* E27F24 802B6294 8FB10024 */  lw        $s1, 0x24($sp)
/* E27F28 802B6298 8FB00020 */  lw        $s0, 0x20($sp)
/* E27F2C 802B629C 03E00008 */  jr        $ra
/* E27F30 802B62A0 27BD0030 */   addiu    $sp, $sp, 0x30
/* E27F34 802B62A4 00000000 */  nop
/* E27F38 802B62A8 00000000 */  nop
/* E27F3C 802B62AC 00000000 */  nop

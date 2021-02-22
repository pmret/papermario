.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6048_E24F18
/* E24F18 802B6048 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* E24F1C 802B604C AFB3002C */  sw        $s3, 0x2c($sp)
/* E24F20 802B6050 AFB40030 */  sw        $s4, 0x30($sp)
/* E24F24 802B6054 3C148011 */  lui       $s4, %hi(gPlayerStatus)
/* E24F28 802B6058 2694EFC8 */  addiu     $s4, $s4, %lo(gPlayerStatus)
/* E24F2C 802B605C 3C038011 */  lui       $v1, %hi(gPlayerData+0x1)
/* E24F30 802B6060 8063F291 */  lb        $v1, %lo(gPlayerData+0x1)($v1)
/* E24F34 802B6064 24020002 */  addiu     $v0, $zero, 2
/* E24F38 802B6068 AFBF0034 */  sw        $ra, 0x34($sp)
/* E24F3C 802B606C AFB20028 */  sw        $s2, 0x28($sp)
/* E24F40 802B6070 AFB10024 */  sw        $s1, 0x24($sp)
/* E24F44 802B6074 AFB00020 */  sw        $s0, 0x20($sp)
/* E24F48 802B6078 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* E24F4C 802B607C F7B80048 */  sdc1      $f24, 0x48($sp)
/* E24F50 802B6080 F7B60040 */  sdc1      $f22, 0x40($sp)
/* E24F54 802B6084 F7B40038 */  sdc1      $f20, 0x38($sp)
/* E24F58 802B6088 14620008 */  bne       $v1, $v0, .L802B60AC
/* E24F5C 802B608C 0080982D */   daddu    $s3, $a0, $zero
/* E24F60 802B6090 3C013F99 */  lui       $at, 0x3f99
/* E24F64 802B6094 3421999A */  ori       $at, $at, 0x999a
/* E24F68 802B6098 4481C000 */  mtc1      $at, $f24
/* E24F6C 802B609C 24120001 */  addiu     $s2, $zero, 1
/* E24F70 802B60A0 2411001C */  addiu     $s1, $zero, 0x1c
/* E24F74 802B60A4 080AD83A */  j         .L802B60E8
/* E24F78 802B60A8 2410211A */   addiu    $s0, $zero, 0x211a
.L802B60AC:
/* E24F7C 802B60AC 24020001 */  addiu     $v0, $zero, 1
/* E24F80 802B60B0 14620008 */  bne       $v1, $v0, .L802B60D4
/* E24F84 802B60B4 24120001 */   addiu    $s2, $zero, 1
/* E24F88 802B60B8 3C013F4C */  lui       $at, 0x3f4c
/* E24F8C 802B60BC 3421CCCD */  ori       $at, $at, 0xcccd
/* E24F90 802B60C0 4481C000 */  mtc1      $at, $f24
/* E24F94 802B60C4 0040902D */  daddu     $s2, $v0, $zero
/* E24F98 802B60C8 24110010 */  addiu     $s1, $zero, 0x10
/* E24F9C 802B60CC 080AD83A */  j         .L802B60E8
/* E24FA0 802B60D0 24102119 */   addiu    $s0, $zero, 0x2119
.L802B60D4:
/* E24FA4 802B60D4 3C013ECC */  lui       $at, 0x3ecc
/* E24FA8 802B60D8 3421CCCD */  ori       $at, $at, 0xcccd
/* E24FAC 802B60DC 4481C000 */  mtc1      $at, $f24
/* E24FB0 802B60E0 24110004 */  addiu     $s1, $zero, 4
/* E24FB4 802B60E4 24102118 */  addiu     $s0, $zero, 0x2118
.L802B60E8:
/* E24FB8 802B60E8 0C0394D2 */  jal       func_800E5348
/* E24FBC 802B60EC 00000000 */   nop
/* E24FC0 802B60F0 3C0140C9 */  lui       $at, 0x40c9
/* E24FC4 802B60F4 34210FD0 */  ori       $at, $at, 0xfd0
/* E24FC8 802B60F8 44811000 */  mtc1      $at, $f2
/* E24FCC 802B60FC 00000000 */  nop
/* E24FD0 802B6100 46020502 */  mul.s     $f20, $f0, $f2
/* E24FD4 802B6104 00000000 */  nop
/* E24FD8 802B6108 3C0143B4 */  lui       $at, 0x43b4
/* E24FDC 802B610C 44810000 */  mtc1      $at, $f0
/* E24FE0 802B6110 00000000 */  nop
/* E24FE4 802B6114 4600A503 */  div.s     $f20, $f20, $f0
/* E24FE8 802B6118 0C00A85B */  jal       sin_rad
/* E24FEC 802B611C 4600A306 */   mov.s    $f12, $f20
/* E24FF0 802B6120 3C0141C8 */  lui       $at, 0x41c8
/* E24FF4 802B6124 44811000 */  mtc1      $at, $f2
/* E24FF8 802B6128 00000000 */  nop
/* E24FFC 802B612C 46020582 */  mul.s     $f22, $f0, $f2
/* E25000 802B6130 00000000 */  nop
/* E25004 802B6134 0C00A874 */  jal       cos_rad
/* E25008 802B6138 4600A306 */   mov.s    $f12, $f20
/* E2500C 802B613C 3C01C1C8 */  lui       $at, 0xc1c8
/* E25010 802B6140 44811000 */  mtc1      $at, $f2
/* E25014 802B6144 00000000 */  nop
/* E25018 802B6148 46020082 */  mul.s     $f2, $f0, $f2
/* E2501C 802B614C 00000000 */  nop
/* E25020 802B6150 06610008 */  bgez      $s3, .L802B6174
/* E25024 802B6154 24130003 */   addiu    $s3, $zero, 3
/* E25028 802B6158 C6800028 */  lwc1      $f0, 0x28($s4)
/* E2502C 802B615C 24130006 */  addiu     $s3, $zero, 6
/* E25030 802B6160 46160680 */  add.s     $f26, $f0, $f22
/* E25034 802B6164 C6800030 */  lwc1      $f0, 0x30($s4)
/* E25038 802B6168 C694002C */  lwc1      $f20, 0x2c($s4)
/* E2503C 802B616C 080AD86D */  j         .L802B61B4
/* E25040 802B6170 46020580 */   add.s    $f22, $f0, $f2
.L802B6174:
/* E25044 802B6174 3C02802B */  lui       $v0, %hi(D_802B6DB0_E25C80)
/* E25048 802B6178 8C426DB0 */  lw        $v0, %lo(D_802B6DB0_E25C80)($v0)
/* E2504C 802B617C C4400000 */  lwc1      $f0, ($v0)
/* E25050 802B6180 46160680 */  add.s     $f26, $f0, $f22
/* E25054 802B6184 C4400008 */  lwc1      $f0, 8($v0)
/* E25058 802B6188 868300B0 */  lh        $v1, 0xb0($s4)
/* E2505C 802B618C 46020580 */  add.s     $f22, $f0, $f2
/* E25060 802B6190 C4420004 */  lwc1      $f2, 4($v0)
/* E25064 802B6194 44830000 */  mtc1      $v1, $f0
/* E25068 802B6198 00000000 */  nop
/* E2506C 802B619C 46800020 */  cvt.s.w   $f0, $f0
/* E25070 802B61A0 46001080 */  add.s     $f2, $f2, $f0
/* E25074 802B61A4 3C0140A0 */  lui       $at, 0x40a0
/* E25078 802B61A8 44810000 */  mtc1      $at, $f0
/* E2507C 802B61AC 24110001 */  addiu     $s1, $zero, 1
/* E25080 802B61B0 46001501 */  sub.s     $f20, $f2, $f0
.L802B61B4:
/* E25084 802B61B4 0000202D */  daddu     $a0, $zero, $zero
/* E25088 802B61B8 24050002 */  addiu     $a1, $zero, 2
/* E2508C 802B61BC 4407C000 */  mfc1      $a3, $f24
/* E25090 802B61C0 0C0B2D72 */  jal       exec_ShakeCamX
/* E25094 802B61C4 0240302D */   daddu    $a2, $s2, $zero
/* E25098 802B61C8 0000202D */  daddu     $a0, $zero, $zero
/* E2509C 802B61CC 44910000 */  mtc1      $s1, $f0
/* E250A0 802B61D0 00000000 */  nop
/* E250A4 802B61D4 46800020 */  cvt.s.w   $f0, $f0
/* E250A8 802B61D8 26430003 */  addiu     $v1, $s2, 3
/* E250AC 802B61DC 00031040 */  sll       $v0, $v1, 1
/* E250B0 802B61E0 4405D000 */  mfc1      $a1, $f26
/* E250B4 802B61E4 4406A000 */  mfc1      $a2, $f20
/* E250B8 802B61E8 4407B000 */  mfc1      $a3, $f22
/* E250BC 802B61EC 00431021 */  addu      $v0, $v0, $v1
/* E250C0 802B61F0 E7A00010 */  swc1      $f0, 0x10($sp)
/* E250C4 802B61F4 AFB30014 */  sw        $s3, 0x14($sp)
/* E250C8 802B61F8 AFA00018 */  sw        $zero, 0x18($sp)
/* E250CC 802B61FC 0C01C0DC */  jal       func_80070370
/* E250D0 802B6200 AFA2001C */   sw       $v0, 0x1c($sp)
/* E250D4 802B6204 0C03A752 */  jal       is_ability_active
/* E250D8 802B6208 2404000F */   addiu    $a0, $zero, 0xf
/* E250DC 802B620C 2443FFFF */  addiu     $v1, $v0, -1
/* E250E0 802B6210 2C620006 */  sltiu     $v0, $v1, 6
/* E250E4 802B6214 10400011 */  beqz      $v0, .L802B625C
/* E250E8 802B6218 00031080 */   sll      $v0, $v1, 2
/* E250EC 802B621C 3C01802B */  lui       $at, %hi(jtbl_802B6DF0_E25CC0)
/* E250F0 802B6220 00220821 */  addu      $at, $at, $v0
/* E250F4 802B6224 8C226DF0 */  lw        $v0, %lo(jtbl_802B6DF0_E25CC0)($at)
/* E250F8 802B6228 00400008 */  jr        $v0
/* E250FC 802B622C 00000000 */   nop
glabel L802B6230_E25100
/* E25100 802B6230 080AD897 */  j         .L802B625C
/* E25104 802B6234 24100372 */   addiu    $s0, $zero, 0x372
glabel L802B6238_E25108
/* E25108 802B6238 080AD897 */  j         .L802B625C
/* E2510C 802B623C 241000F1 */   addiu    $s0, $zero, 0xf1
glabel L802B6240_E25110
/* E25110 802B6240 080AD897 */  j         .L802B625C
/* E25114 802B6244 241000DC */   addiu    $s0, $zero, 0xdc
glabel L802B6248_E25118
/* E25118 802B6248 080AD897 */  j         .L802B625C
/* E2511C 802B624C 24102072 */   addiu    $s0, $zero, 0x2072
glabel L802B6250_E25120
/* E25120 802B6250 080AD897 */  j         .L802B625C
/* E25124 802B6254 24102073 */   addiu    $s0, $zero, 0x2073
glabel L802B6258_E25128
/* E25128 802B6258 2410205B */  addiu     $s0, $zero, 0x205b
.L802B625C:
/* E2512C 802B625C 0200202D */  daddu     $a0, $s0, $zero
/* E25130 802B6260 0C052736 */  jal       play_sound_at_player
/* E25134 802B6264 0000282D */   daddu    $a1, $zero, $zero
/* E25138 802B6268 24040100 */  addiu     $a0, $zero, 0x100
/* E2513C 802B626C 0C00A3C2 */  jal       start_rumble
/* E25140 802B6270 24050032 */   addiu    $a1, $zero, 0x32
/* E25144 802B6274 8FBF0034 */  lw        $ra, 0x34($sp)
/* E25148 802B6278 8FB40030 */  lw        $s4, 0x30($sp)
/* E2514C 802B627C 8FB3002C */  lw        $s3, 0x2c($sp)
/* E25150 802B6280 8FB20028 */  lw        $s2, 0x28($sp)
/* E25154 802B6284 8FB10024 */  lw        $s1, 0x24($sp)
/* E25158 802B6288 8FB00020 */  lw        $s0, 0x20($sp)
/* E2515C 802B628C D7BA0050 */  ldc1      $f26, 0x50($sp)
/* E25160 802B6290 D7B80048 */  ldc1      $f24, 0x48($sp)
/* E25164 802B6294 D7B60040 */  ldc1      $f22, 0x40($sp)
/* E25168 802B6298 D7B40038 */  ldc1      $f20, 0x38($sp)
/* E2516C 802B629C 03E00008 */  jr        $ra
/* E25170 802B62A0 27BD0058 */   addiu    $sp, $sp, 0x58

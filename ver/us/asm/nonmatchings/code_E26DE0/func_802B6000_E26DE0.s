.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802B66E0_E274C0
.word L802B60D0_E26EB0, L802B65CC_E273AC, L802B6208_E26FE8, L802B6278_E27058, L802B631C_E270FC, L802B64DC_E272BC, L802B6568_E27348, L802B6594_E27374, L802B65CC_E273AC, L802B65CC_E273AC, L802B65CC_E273AC, L802B65B4_E27394, L802B65CC_E273AC, 0

glabel D_802B6718_E274F8
.double 0.54

glabel D_802B6720_E27500
.double 1.4

glabel D_802B6728_E27508
.double 360.0

.section .text

glabel func_802B6000_E26DE0
/* E26DE0 802B6000 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* E26DE4 802B6004 AFB00018 */  sw        $s0, 0x18($sp)
/* E26DE8 802B6008 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E26DEC 802B600C 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E26DF0 802B6010 AFBF0024 */  sw        $ra, 0x24($sp)
/* E26DF4 802B6014 AFB20020 */  sw        $s2, 0x20($sp)
/* E26DF8 802B6018 AFB1001C */  sw        $s1, 0x1c($sp)
/* E26DFC 802B601C F7B60030 */  sdc1      $f22, 0x30($sp)
/* E26E00 802B6020 F7B40028 */  sdc1      $f20, 0x28($sp)
/* E26E04 802B6024 8E030000 */  lw        $v1, ($s0)
/* E26E08 802B6028 3C118016 */  lui       $s1, %hi(gCollisionStatus)
/* E26E0C 802B602C 2631A550 */  addiu     $s1, $s1, %lo(gCollisionStatus)
/* E26E10 802B6030 0461001D */  bgez      $v1, .L802B60A8
/* E26E14 802B6034 3C027FFF */   lui      $v0, 0x7fff
/* E26E18 802B6038 3442FFF9 */  ori       $v0, $v0, 0xfff9
/* E26E1C 802B603C 3C040001 */  lui       $a0, 1
/* E26E20 802B6040 3484000A */  ori       $a0, $a0, 0xa
/* E26E24 802B6044 00621024 */  and       $v0, $v1, $v0
/* E26E28 802B6048 3C0140A6 */  lui       $at, 0x40a6
/* E26E2C 802B604C 34216666 */  ori       $at, $at, 0x6666
/* E26E30 802B6050 44810000 */  mtc1      $at, $f0
/* E26E34 802B6054 3442000A */  ori       $v0, $v0, 0xa
/* E26E38 802B6058 AE020000 */  sw        $v0, ($s0)
/* E26E3C 802B605C A20000B6 */  sb        $zero, 0xb6($s0)
/* E26E40 802B6060 AE000054 */  sw        $zero, 0x54($s0)
/* E26E44 802B6064 3C01802B */  lui       $at, %hi(D_802B6730)
/* E26E48 802B6068 AC206730 */  sw        $zero, %lo(D_802B6730)($at)
/* E26E4C 802B606C 0C037FBF */  jal       func_800DFEFC
/* E26E50 802B6070 E6000070 */   swc1     $f0, 0x70($s0)
/* E26E54 802B6074 0C03805E */  jal       disable_player_input
/* E26E58 802B6078 00000000 */   nop
/* E26E5C 802B607C 24040146 */  addiu     $a0, $zero, 0x146
/* E26E60 802B6080 0000282D */  daddu     $a1, $zero, $zero
/* E26E64 802B6084 3C06800B */  lui       $a2, %hi(gCameras)
/* E26E68 802B6088 24C61D80 */  addiu     $a2, $a2, %lo(gCameras)
/* E26E6C 802B608C 8E020000 */  lw        $v0, ($s0)
/* E26E70 802B6090 94C30002 */  lhu       $v1, 2($a2)
/* E26E74 802B6094 34420200 */  ori       $v0, $v0, 0x200
/* E26E78 802B6098 34630001 */  ori       $v1, $v1, 1
/* E26E7C 802B609C AE020000 */  sw        $v0, ($s0)
/* E26E80 802B60A0 0C052736 */  jal       play_sound_at_player
/* E26E84 802B60A4 A4C30002 */   sh       $v1, 2($a2)
.L802B60A8:
/* E26E88 802B60A8 820300B6 */  lb        $v1, 0xb6($s0)
/* E26E8C 802B60AC 2C62000D */  sltiu     $v0, $v1, 0xd
/* E26E90 802B60B0 10400146 */  beqz      $v0, L802B65CC_E273AC
/* E26E94 802B60B4 0000902D */   daddu    $s2, $zero, $zero
/* E26E98 802B60B8 00031080 */  sll       $v0, $v1, 2
/* E26E9C 802B60BC 3C01802B */  lui       $at, %hi(jtbl_802B66E0_E274C0)
/* E26EA0 802B60C0 00220821 */  addu      $at, $at, $v0
/* E26EA4 802B60C4 8C2266E0 */  lw        $v0, %lo(jtbl_802B66E0_E274C0)($at)
/* E26EA8 802B60C8 00400008 */  jr        $v0
/* E26EAC 802B60CC 00000000 */   nop
glabel L802B60D0_E26EB0
/* E26EB0 802B60D0 3C014220 */  lui       $at, 0x4220
/* E26EB4 802B60D4 44811000 */  mtc1      $at, $f2
/* E26EB8 802B60D8 C600008C */  lwc1      $f0, 0x8c($s0)
/* E26EBC 802B60DC 3C0143B4 */  lui       $at, 0x43b4
/* E26EC0 802B60E0 44812000 */  mtc1      $at, $f4
/* E26EC4 802B60E4 46020000 */  add.s     $f0, $f0, $f2
/* E26EC8 802B60E8 3C01802B */  lui       $at, %hi(D_802B6730)
/* E26ECC 802B60EC E4226730 */  swc1      $f2, %lo(D_802B6730)($at)
/* E26ED0 802B60F0 4600203E */  c.le.s    $f4, $f0
/* E26ED4 802B60F4 00000000 */  nop
/* E26ED8 802B60F8 45000002 */  bc1f      .L802B6104
/* E26EDC 802B60FC E600008C */   swc1     $f0, 0x8c($s0)
/* E26EE0 802B6100 E604008C */  swc1      $f4, 0x8c($s0)
.L802B6104:
/* E26EE4 802B6104 C6040070 */  lwc1      $f4, 0x70($s0)
/* E26EE8 802B6108 44800000 */  mtc1      $zero, $f0
/* E26EEC 802B610C 00000000 */  nop
/* E26EF0 802B6110 4604003E */  c.le.s    $f0, $f4
/* E26EF4 802B6114 00000000 */  nop
/* E26EF8 802B6118 45000023 */  bc1f      .L802B61A8
/* E26EFC 802B611C 00000000 */   nop
/* E26F00 802B6120 3C01802B */  lui       $at, %hi(D_802B6718_E274F8)
/* E26F04 802B6124 D4226718 */  ldc1      $f2, %lo(D_802B6718_E274F8)($at)
/* E26F08 802B6128 46002021 */  cvt.d.s   $f0, $f4
/* E26F0C 802B612C 46220001 */  sub.d     $f0, $f0, $f2
/* E26F10 802B6130 462000A0 */  cvt.s.d   $f2, $f0
/* E26F14 802B6134 E6020070 */  swc1      $f2, 0x70($s0)
/* E26F18 802B6138 86240008 */  lh        $a0, 8($s1)
/* E26F1C 802B613C 96220008 */  lhu       $v0, 8($s1)
/* E26F20 802B6140 04810004 */  bgez      $a0, .L802B6154
/* E26F24 802B6144 30424000 */   andi     $v0, $v0, 0x4000
/* E26F28 802B6148 C600002C */  lwc1      $f0, 0x2c($s0)
/* E26F2C 802B614C 080AD869 */  j         .L802B61A4
/* E26F30 802B6150 46020000 */   add.s    $f0, $f0, $f2
.L802B6154:
/* E26F34 802B6154 10400014 */  beqz      $v0, .L802B61A8
/* E26F38 802B6158 00000000 */   nop
/* E26F3C 802B615C 0C04417A */  jal       get_entity_by_index
/* E26F40 802B6160 00000000 */   nop
/* E26F44 802B6164 0040182D */  daddu     $v1, $v0, $zero
/* E26F48 802B6168 1060000F */  beqz      $v1, .L802B61A8
/* E26F4C 802B616C 00000000 */   nop
/* E26F50 802B6170 860200B0 */  lh        $v0, 0xb0($s0)
/* E26F54 802B6174 3C013FE0 */  lui       $at, 0x3fe0
/* E26F58 802B6178 44810800 */  mtc1      $at, $f1
/* E26F5C 802B617C 44800000 */  mtc1      $zero, $f0
/* E26F60 802B6180 44821000 */  mtc1      $v0, $f2
/* E26F64 802B6184 00000000 */  nop
/* E26F68 802B6188 468010A1 */  cvt.d.w   $f2, $f2
/* E26F6C 802B618C 46201082 */  mul.d     $f2, $f2, $f0
/* E26F70 802B6190 00000000 */  nop
/* E26F74 802B6194 C460004C */  lwc1      $f0, 0x4c($v1)
/* E26F78 802B6198 46000021 */  cvt.d.s   $f0, $f0
/* E26F7C 802B619C 46220001 */  sub.d     $f0, $f0, $f2
/* E26F80 802B61A0 46200020 */  cvt.s.d   $f0, $f0
.L802B61A4:
/* E26F84 802B61A4 E600002C */  swc1      $f0, 0x2c($s0)
.L802B61A8:
/* E26F88 802B61A8 C602008C */  lwc1      $f2, 0x8c($s0)
/* E26F8C 802B61AC 3C0143B4 */  lui       $at, 0x43b4
/* E26F90 802B61B0 44810000 */  mtc1      $at, $f0
/* E26F94 802B61B4 00000000 */  nop
/* E26F98 802B61B8 46001032 */  c.eq.s    $f2, $f0
/* E26F9C 802B61BC 00000000 */  nop
/* E26FA0 802B61C0 4500000F */  bc1f      .L802B6200
/* E26FA4 802B61C4 2402FFFF */   addiu    $v0, $zero, -1
/* E26FA8 802B61C8 C6020070 */  lwc1      $f2, 0x70($s0)
/* E26FAC 802B61CC 44800000 */  mtc1      $zero, $f0
/* E26FB0 802B61D0 00000000 */  nop
/* E26FB4 802B61D4 4600103E */  c.le.s    $f2, $f0
/* E26FB8 802B61D8 00000000 */  nop
/* E26FBC 802B61DC 45000007 */  bc1f      .L802B61FC
/* E26FC0 802B61E0 24020005 */   addiu    $v0, $zero, 5
/* E26FC4 802B61E4 3C014000 */  lui       $at, 0x4000
/* E26FC8 802B61E8 44810000 */  mtc1      $at, $f0
/* E26FCC 802B61EC A6020008 */  sh        $v0, 8($s0)
/* E26FD0 802B61F0 24020002 */  addiu     $v0, $zero, 2
/* E26FD4 802B61F4 A20200B6 */  sb        $v0, 0xb6($s0)
/* E26FD8 802B61F8 E6000070 */  swc1      $f0, 0x70($s0)
.L802B61FC:
/* E26FDC 802B61FC 2402FFFF */  addiu     $v0, $zero, -1
.L802B6200:
/* E26FE0 802B6200 080AD973 */  j         L802B65CC_E273AC
/* E26FE4 802B6204 A6220008 */   sh       $v0, 8($s1)
glabel L802B6208_E26FE8
/* E26FE8 802B6208 C6020070 */  lwc1      $f2, 0x70($s0)
/* E26FEC 802B620C 44800000 */  mtc1      $zero, $f0
/* E26FF0 802B6210 00000000 */  nop
/* E26FF4 802B6214 4602003E */  c.le.s    $f0, $f2
/* E26FF8 802B6218 00000000 */  nop
/* E26FFC 802B621C 4500000C */  bc1f      .L802B6250
/* E27000 802B6220 00000000 */   nop
/* E27004 802B6224 3C01802B */  lui       $at, %hi(D_802B6720_E27500)
/* E27008 802B6228 D4206720 */  ldc1      $f0, %lo(D_802B6720_E27500)($at)
/* E2700C 802B622C 460010A1 */  cvt.d.s   $f2, $f2
/* E27010 802B6230 46201081 */  sub.d     $f2, $f2, $f0
/* E27014 802B6234 86220008 */  lh        $v0, 8($s1)
/* E27018 802B6238 462010A0 */  cvt.s.d   $f2, $f2
/* E2701C 802B623C 04410004 */  bgez      $v0, .L802B6250
/* E27020 802B6240 E6020070 */   swc1     $f2, 0x70($s0)
/* E27024 802B6244 C600002C */  lwc1      $f0, 0x2c($s0)
/* E27028 802B6248 46020000 */  add.s     $f0, $f0, $f2
/* E2702C 802B624C E600002C */  swc1      $f0, 0x2c($s0)
.L802B6250:
/* E27030 802B6250 96020008 */  lhu       $v0, 8($s0)
/* E27034 802B6254 2442FFFF */  addiu     $v0, $v0, -1
/* E27038 802B6258 A6020008 */  sh        $v0, 8($s0)
/* E2703C 802B625C 00021400 */  sll       $v0, $v0, 0x10
/* E27040 802B6260 1C4000DA */  bgtz      $v0, L802B65CC_E273AC
/* E27044 802B6264 00000000 */   nop
/* E27048 802B6268 920200B6 */  lbu       $v0, 0xb6($s0)
/* E2704C 802B626C 24420001 */  addiu     $v0, $v0, 1
/* E27050 802B6270 080AD973 */  j         L802B65CC_E273AC
/* E27054 802B6274 A20200B6 */   sb       $v0, 0xb6($s0)
glabel L802B6278_E27058
/* E27058 802B6278 4480A000 */  mtc1      $zero, $f20
/* E2705C 802B627C 27A50010 */  addiu     $a1, $sp, 0x10
/* E27060 802B6280 0C038D45 */  jal       func_800E3514
/* E27064 802B6284 4600A306 */   mov.s    $f12, $f20
/* E27068 802B6288 3C014234 */  lui       $at, 0x4234
/* E2706C 802B628C 44811000 */  mtc1      $at, $f2
/* E27070 802B6290 C604008C */  lwc1      $f4, 0x8c($s0)
/* E27074 802B6294 E600002C */  swc1      $f0, 0x2c($s0)
/* E27078 802B6298 46022100 */  add.s     $f4, $f4, $f2
/* E2707C 802B629C 3C01802B */  lui       $at, %hi(D_802B6730)
/* E27080 802B62A0 E4226730 */  swc1      $f2, %lo(D_802B6730)($at)
/* E27084 802B62A4 3C01802B */  lui       $at, %hi(D_802B6728_E27508)
/* E27088 802B62A8 D4226728 */  ldc1      $f2, %lo(D_802B6728_E27508)($at)
/* E2708C 802B62AC 46002021 */  cvt.d.s   $f0, $f4
/* E27090 802B62B0 4620103E */  c.le.d    $f2, $f0
/* E27094 802B62B4 00000000 */  nop
/* E27098 802B62B8 450000C4 */  bc1f      L802B65CC_E273AC
/* E2709C 802B62BC E604008C */   swc1     $f4, 0x8c($s0)
/* E270A0 802B62C0 3C040001 */  lui       $a0, 1
/* E270A4 802B62C4 3C01C05E */  lui       $at, 0xc05e
/* E270A8 802B62C8 34215C92 */  ori       $at, $at, 0x5c92
/* E270AC 802B62CC 44810000 */  mtc1      $at, $f0
/* E270B0 802B62D0 920200B6 */  lbu       $v0, 0xb6($s0)
/* E270B4 802B62D4 3C01BF98 */  lui       $at, 0xbf98
/* E270B8 802B62D8 34215F07 */  ori       $at, $at, 0x5f07
/* E270BC 802B62DC 44811000 */  mtc1      $at, $f2
/* E270C0 802B62E0 3484000B */  ori       $a0, $a0, 0xb
/* E270C4 802B62E4 E614008C */  swc1      $f20, 0x8c($s0)
/* E270C8 802B62E8 E6000074 */  swc1      $f0, 0x74($s0)
/* E270CC 802B62EC 3C013EF0 */  lui       $at, 0x3ef0
/* E270D0 802B62F0 3421D845 */  ori       $at, $at, 0xd845
/* E270D4 802B62F4 44810000 */  mtc1      $at, $f0
/* E270D8 802B62F8 C6040074 */  lwc1      $f4, 0x74($s0)
/* E270DC 802B62FC 24420001 */  addiu     $v0, $v0, 1
/* E270E0 802B6300 A20200B6 */  sb        $v0, 0xb6($s0)
/* E270E4 802B6304 E602007C */  swc1      $f2, 0x7c($s0)
/* E270E8 802B6308 E6000078 */  swc1      $f0, 0x78($s0)
/* E270EC 802B630C 0C037FBF */  jal       func_800DFEFC
/* E270F0 802B6310 E6040070 */   swc1     $f4, 0x70($s0)
/* E270F4 802B6314 080AD973 */  j         L802B65CC_E273AC
/* E270F8 802B6318 00000000 */   nop
glabel L802B631C_E270FC
/* E270FC 802B631C 0C038D36 */  jal       func_800E34D8
/* E27100 802B6320 00000000 */   nop
/* E27104 802B6324 46000506 */  mov.s     $f20, $f0
/* E27108 802B6328 4600A306 */  mov.s     $f12, $f20
/* E2710C 802B632C 0C038D45 */  jal       func_800E3514
/* E27110 802B6330 27A50010 */   addiu    $a1, $sp, 0x10
/* E27114 802B6334 3C01C2C8 */  lui       $at, 0xc2c8
/* E27118 802B6338 44811000 */  mtc1      $at, $f2
/* E2711C 802B633C 00000000 */  nop
/* E27120 802B6340 4602A03C */  c.lt.s    $f20, $f2
/* E27124 802B6344 00000000 */  nop
/* E27128 802B6348 45000005 */  bc1f      .L802B6360
/* E2712C 802B634C E600002C */   swc1     $f0, 0x2c($s0)
/* E27130 802B6350 AE00007C */  sw        $zero, 0x7c($s0)
/* E27134 802B6354 AE000078 */  sw        $zero, 0x78($s0)
/* E27138 802B6358 AE000074 */  sw        $zero, 0x74($s0)
/* E2713C 802B635C E6020070 */  swc1      $f2, 0x70($s0)
.L802B6360:
/* E27140 802B6360 8FA20010 */  lw        $v0, 0x10($sp)
/* E27144 802B6364 04400099 */  bltz      $v0, L802B65CC_E273AC
/* E27148 802B6368 00000000 */   nop
/* E2714C 802B636C 96240002 */  lhu       $a0, 2($s1)
/* E27150 802B6370 30824000 */  andi      $v0, $a0, 0x4000
/* E27154 802B6374 10400013 */  beqz      $v0, .L802B63C4
/* E27158 802B6378 00042400 */   sll      $a0, $a0, 0x10
/* E2715C 802B637C 0C0441A9 */  jal       get_entity_type
/* E27160 802B6380 00042403 */   sra      $a0, $a0, 0x10
/* E27164 802B6384 2442FFF9 */  addiu     $v0, $v0, -7
/* E27168 802B6388 2C420002 */  sltiu     $v0, $v0, 2
/* E2716C 802B638C 1040000D */  beqz      $v0, .L802B63C4
/* E27170 802B6390 00000000 */   nop
/* E27174 802B6394 0C04417A */  jal       get_entity_by_index
/* E27178 802B6398 86240002 */   lh       $a0, 2($s1)
/* E2717C 802B639C 90430006 */  lbu       $v1, 6($v0)
/* E27180 802B63A0 34630001 */  ori       $v1, $v1, 1
/* E27184 802B63A4 A0430006 */  sb        $v1, 6($v0)
/* E27188 802B63A8 2402000B */  addiu     $v0, $zero, 0xb
/* E2718C 802B63AC A20200B6 */  sb        $v0, 0xb6($s0)
/* E27190 802B63B0 8E020000 */  lw        $v0, ($s0)
/* E27194 802B63B4 2403FFF7 */  addiu     $v1, $zero, -9
/* E27198 802B63B8 00431024 */  and       $v0, $v0, $v1
/* E2719C 802B63BC 080AD973 */  j         L802B65CC_E273AC
/* E271A0 802B63C0 AE020000 */   sw       $v0, ($s0)
.L802B63C4:
/* E271A4 802B63C4 8FA40010 */  lw        $a0, 0x10($sp)
/* E271A8 802B63C8 0C016F6A */  jal       get_collider_type_by_id
/* E271AC 802B63CC 00000000 */   nop
/* E271B0 802B63D0 304300FF */  andi      $v1, $v0, 0xff
/* E271B4 802B63D4 24020003 */  addiu     $v0, $zero, 3
/* E271B8 802B63D8 54620009 */  bnel      $v1, $v0, .L802B6400
/* E271BC 802B63DC 24020002 */   addiu    $v0, $zero, 2
/* E271C0 802B63E0 24040017 */  addiu     $a0, $zero, 0x17
/* E271C4 802B63E4 24020001 */  addiu     $v0, $zero, 1
/* E271C8 802B63E8 0C039769 */  jal       set_action_state
/* E271CC 802B63EC A20200BF */   sb       $v0, 0xbf($s0)
/* E271D0 802B63F0 8E020000 */  lw        $v0, ($s0)
/* E271D4 802B63F4 2403FFF7 */  addiu     $v1, $zero, -9
/* E271D8 802B63F8 080AD906 */  j         .L802B6418
/* E271DC 802B63FC 34420800 */   ori      $v0, $v0, 0x800
.L802B6400:
/* E271E0 802B6400 14620008 */  bne       $v1, $v0, .L802B6424
/* E271E4 802B6404 3C040001 */   lui      $a0, 1
/* E271E8 802B6408 0C039769 */  jal       set_action_state
/* E271EC 802B640C 24040017 */   addiu    $a0, $zero, 0x17
/* E271F0 802B6410 8E020000 */  lw        $v0, ($s0)
/* E271F4 802B6414 2403FFF7 */  addiu     $v1, $zero, -9
.L802B6418:
/* E271F8 802B6418 00431024 */  and       $v0, $v0, $v1
/* E271FC 802B641C 080AD98A */  j         .L802B6628
/* E27200 802B6420 AE020000 */   sw       $v0, ($s0)
.L802B6424:
/* E27204 802B6424 3C01C05E */  lui       $at, 0xc05e
/* E27208 802B6428 34215C92 */  ori       $at, $at, 0x5c92
/* E2720C 802B642C 44810000 */  mtc1      $at, $f0
/* E27210 802B6430 3C013EF0 */  lui       $at, 0x3ef0
/* E27214 802B6434 3421D845 */  ori       $at, $at, 0xd845
/* E27218 802B6438 44811000 */  mtc1      $at, $f2
/* E2721C 802B643C 3C01BF98 */  lui       $at, 0xbf98
/* E27220 802B6440 34215F07 */  ori       $at, $at, 0x5f07
/* E27224 802B6444 44812000 */  mtc1      $at, $f4
/* E27228 802B6448 3C014120 */  lui       $at, 0x4120
/* E2722C 802B644C 44813000 */  mtc1      $at, $f6
/* E27230 802B6450 3484000B */  ori       $a0, $a0, 0xb
/* E27234 802B6454 E6000074 */  swc1      $f0, 0x74($s0)
/* E27238 802B6458 E6020078 */  swc1      $f2, 0x78($s0)
/* E2723C 802B645C E604007C */  swc1      $f4, 0x7c($s0)
/* E27240 802B6460 0C037FBF */  jal       func_800DFEFC
/* E27244 802B6464 E6060070 */   swc1     $f6, 0x70($s0)
/* E27248 802B6468 0000202D */  daddu     $a0, $zero, $zero
/* E2724C 802B646C 0080282D */  daddu     $a1, $a0, $zero
/* E27250 802B6470 2402000E */  addiu     $v0, $zero, 0xe
/* E27254 802B6474 A20200B4 */  sb        $v0, 0xb4($s0)
/* E27258 802B6478 2402000C */  addiu     $v0, $zero, 0xc
/* E2725C 802B647C 920300B6 */  lbu       $v1, 0xb6($s0)
/* E27260 802B6480 24060004 */  addiu     $a2, $zero, 4
/* E27264 802B6484 A60000C0 */  sh        $zero, 0xc0($s0)
/* E27268 802B6488 A2020280 */  sb        $v0, 0x280($s0)
/* E2726C 802B648C AE00008C */  sw        $zero, 0x8c($s0)
/* E27270 802B6490 24630001 */  addiu     $v1, $v1, 1
/* E27274 802B6494 0C0B2D5B */  jal       exec_ShakeCam1
/* E27278 802B6498 A20300B6 */   sb       $v1, 0xb6($s0)
/* E2727C 802B649C 24040149 */  addiu     $a0, $zero, 0x149
/* E27280 802B64A0 0C052736 */  jal       play_sound_at_player
/* E27284 802B64A4 0000282D */   daddu    $a1, $zero, $zero
/* E27288 802B64A8 24040080 */  addiu     $a0, $zero, 0x80
/* E2728C 802B64AC 0C00A3C2 */  jal       start_rumble
/* E27290 802B64B0 24050019 */   addiu    $a1, $zero, 0x19
/* E27294 802B64B4 3C048016 */  lui       $a0, %hi(D_8015A578)
/* E27298 802B64B8 2484A578 */  addiu     $a0, $a0, %lo(D_8015A578)
/* E2729C 802B64BC C600002C */  lwc1      $f0, 0x2c($s0)
/* E272A0 802B64C0 8E030000 */  lw        $v1, ($s0)
/* E272A4 802B64C4 24020001 */  addiu     $v0, $zero, 1
/* E272A8 802B64C8 A0820000 */  sb        $v0, ($a0)
/* E272AC 802B64CC 34630400 */  ori       $v1, $v1, 0x400
/* E272B0 802B64D0 E4800008 */  swc1      $f0, 8($a0)
/* E272B4 802B64D4 080AD973 */  j         L802B65CC_E273AC
/* E272B8 802B64D8 AE030000 */   sw       $v1, ($s0)
glabel L802B64DC_E272BC
/* E272BC 802B64DC 0C038D12 */  jal       integrate_gravity
/* E272C0 802B64E0 00000000 */   nop
/* E272C4 802B64E4 4480B000 */  mtc1      $zero, $f22
/* E272C8 802B64E8 46000506 */  mov.s     $f20, $f0
/* E272CC 802B64EC 4616A032 */  c.eq.s    $f20, $f22
/* E272D0 802B64F0 00000000 */  nop
/* E272D4 802B64F4 45030035 */  bc1tl     L802B65CC_E273AC
/* E272D8 802B64F8 24120001 */   addiu    $s2, $zero, 1
/* E272DC 802B64FC C6000070 */  lwc1      $f0, 0x70($s0)
/* E272E0 802B6500 4600B03C */  c.lt.s    $f22, $f0
/* E272E4 802B6504 00000000 */  nop
/* E272E8 802B6508 45000005 */  bc1f      .L802B6520
/* E272EC 802B650C 4600A306 */   mov.s    $f12, $f20
/* E272F0 802B6510 C600002C */  lwc1      $f0, 0x2c($s0)
/* E272F4 802B6514 46140000 */  add.s     $f0, $f0, $f20
/* E272F8 802B6518 080AD955 */  j         .L802B6554
/* E272FC 802B651C E600002C */   swc1     $f0, 0x2c($s0)
.L802B6520:
/* E27300 802B6520 0C038D45 */  jal       func_800E3514
/* E27304 802B6524 27A50010 */   addiu    $a1, $sp, 0x10
/* E27308 802B6528 C6020070 */  lwc1      $f2, 0x70($s0)
/* E2730C 802B652C 4616103C */  c.lt.s    $f2, $f22
/* E27310 802B6530 00000000 */  nop
/* E27314 802B6534 45000007 */  bc1f      .L802B6554
/* E27318 802B6538 E600002C */   swc1     $f0, 0x2c($s0)
/* E2731C 802B653C 8FA20010 */  lw        $v0, 0x10($sp)
/* E27320 802B6540 04400004 */  bltz      $v0, .L802B6554
/* E27324 802B6544 00000000 */   nop
/* E27328 802B6548 920200B6 */  lbu       $v0, 0xb6($s0)
/* E2732C 802B654C 24420001 */  addiu     $v0, $v0, 1
/* E27330 802B6550 A20200B6 */  sb        $v0, 0xb6($s0)
.L802B6554:
/* E27334 802B6554 44806000 */  mtc1      $zero, $f12
/* E27338 802B6558 0C038D45 */  jal       func_800E3514
/* E2733C 802B655C 27A50010 */   addiu    $a1, $sp, 0x10
/* E27340 802B6560 080AD973 */  j         L802B65CC_E273AC
/* E27344 802B6564 E600002C */   swc1     $f0, 0x2c($s0)
glabel L802B6568_E27348
/* E27348 802B6568 4480A000 */  mtc1      $zero, $f20
/* E2734C 802B656C 27A50010 */  addiu     $a1, $sp, 0x10
/* E27350 802B6570 0C038D45 */  jal       func_800E3514
/* E27354 802B6574 4600A306 */   mov.s    $f12, $f20
/* E27358 802B6578 8FA20010 */  lw        $v0, 0x10($sp)
/* E2735C 802B657C 04400005 */  bltz      $v0, L802B6594_E27374
/* E27360 802B6580 E600002C */   swc1     $f0, 0x2c($s0)
/* E27364 802B6584 E6140070 */  swc1      $f20, 0x70($s0)
/* E27368 802B6588 E6140074 */  swc1      $f20, 0x74($s0)
/* E2736C 802B658C E6140078 */  swc1      $f20, 0x78($s0)
/* E27370 802B6590 E614007C */  swc1      $f20, 0x7c($s0)
glabel L802B6594_E27374
/* E27374 802B6594 92020280 */  lbu       $v0, 0x280($s0)
/* E27378 802B6598 2442FFFF */  addiu     $v0, $v0, -1
/* E2737C 802B659C A2020280 */  sb        $v0, 0x280($s0)
/* E27380 802B65A0 00021600 */  sll       $v0, $v0, 0x18
/* E27384 802B65A4 1C400009 */  bgtz      $v0, L802B65CC_E273AC
/* E27388 802B65A8 00000000 */   nop
/* E2738C 802B65AC 080AD973 */  j         L802B65CC_E273AC
/* E27390 802B65B0 24120001 */   addiu    $s2, $zero, 1
glabel L802B65B4_E27394
/* E27394 802B65B4 0C039769 */  jal       set_action_state
/* E27398 802B65B8 24040007 */   addiu    $a0, $zero, 7
/* E2739C 802B65BC 920200B6 */  lbu       $v0, 0xb6($s0)
/* E273A0 802B65C0 24420001 */  addiu     $v0, $v0, 1
/* E273A4 802B65C4 0C038069 */  jal       enable_player_input
/* E273A8 802B65C8 A20200B6 */   sb       $v0, 0xb6($s0)
glabel L802B65CC_E273AC
/* E273AC 802B65CC 12400007 */  beqz      $s2, .L802B65EC
/* E273B0 802B65D0 00000000 */   nop
/* E273B4 802B65D4 0C039769 */  jal       set_action_state
/* E273B8 802B65D8 2404000A */   addiu    $a0, $zero, 0xa
/* E273BC 802B65DC 8E020000 */  lw        $v0, ($s0)
/* E273C0 802B65E0 2403FFF7 */  addiu     $v1, $zero, -9
/* E273C4 802B65E4 00431024 */  and       $v0, $v0, $v1
/* E273C8 802B65E8 AE020000 */  sw        $v0, ($s0)
.L802B65EC:
/* E273CC 802B65EC C6020070 */  lwc1      $f2, 0x70($s0)
/* E273D0 802B65F0 44800000 */  mtc1      $zero, $f0
/* E273D4 802B65F4 00000000 */  nop
/* E273D8 802B65F8 4600103C */  c.lt.s    $f2, $f0
/* E273DC 802B65FC 00000000 */  nop
/* E273E0 802B6600 45000009 */  bc1f      .L802B6628
/* E273E4 802B6604 00000000 */   nop
/* E273E8 802B6608 0C0AD992 */  jal       func_802B6648_E27428
/* E273EC 802B660C 00000000 */   nop
/* E273F0 802B6610 04400005 */  bltz      $v0, .L802B6628
/* E273F4 802B6614 AFA20010 */   sw       $v0, 0x10($sp)
/* E273F8 802B6618 97A30012 */  lhu       $v1, 0x12($sp)
/* E273FC 802B661C 2402FFFF */  addiu     $v0, $zero, -1
/* E27400 802B6620 A6220004 */  sh        $v0, 4($s1)
/* E27404 802B6624 A6230002 */  sh        $v1, 2($s1)
.L802B6628:
/* E27408 802B6628 8FBF0024 */  lw        $ra, 0x24($sp)
/* E2740C 802B662C 8FB20020 */  lw        $s2, 0x20($sp)
/* E27410 802B6630 8FB1001C */  lw        $s1, 0x1c($sp)
/* E27414 802B6634 8FB00018 */  lw        $s0, 0x18($sp)
/* E27418 802B6638 D7B60030 */  ldc1      $f22, 0x30($sp)
/* E2741C 802B663C D7B40028 */  ldc1      $f20, 0x28($sp)
/* E27420 802B6640 03E00008 */  jr        $ra
/* E27424 802B6644 27BD0038 */   addiu    $sp, $sp, 0x38

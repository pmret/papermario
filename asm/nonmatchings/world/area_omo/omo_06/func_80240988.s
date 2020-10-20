.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240988
/* DB8298 80240988 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB829C 8024098C AFB10014 */  sw        $s1, 0x14($sp)
/* DB82A0 80240990 0080882D */  daddu     $s1, $a0, $zero
/* DB82A4 80240994 AFBF001C */  sw        $ra, 0x1c($sp)
/* DB82A8 80240998 AFB20018 */  sw        $s2, 0x18($sp)
/* DB82AC 8024099C AFB00010 */  sw        $s0, 0x10($sp)
/* DB82B0 802409A0 8E240084 */  lw        $a0, 0x84($s1)
/* DB82B4 802409A4 0C04C3D6 */  jal       get_item_entity
/* DB82B8 802409A8 00A0802D */   daddu    $s0, $a1, $zero
/* DB82BC 802409AC 12000005 */  beqz      $s0, .L802409C4
/* DB82C0 802409B0 0040902D */   daddu    $s2, $v0, $zero
/* DB82C4 802409B4 C640000C */  lwc1      $f0, 0xc($s2)
/* DB82C8 802409B8 AE200074 */  sw        $zero, 0x74($s1)
/* DB82CC 802409BC AE20007C */  sw        $zero, 0x7c($s1)
/* DB82D0 802409C0 E6200078 */  swc1      $f0, 0x78($s1)
.L802409C4:
/* DB82D4 802409C4 8E230074 */  lw        $v1, 0x74($s1)
/* DB82D8 802409C8 10600005 */  beqz      $v1, .L802409E0
/* DB82DC 802409CC 24020001 */   addiu    $v0, $zero, 1
/* DB82E0 802409D0 10620024 */  beq       $v1, $v0, .L80240A64
/* DB82E4 802409D4 00000000 */   nop      
/* DB82E8 802409D8 080902AF */  j         .L80240ABC
/* DB82EC 802409DC 00000000 */   nop      
.L802409E0:
/* DB82F0 802409E0 3C013FC9 */  lui       $at, 0x3fc9
/* DB82F4 802409E4 34210FD8 */  ori       $at, $at, 0xfd8
/* DB82F8 802409E8 44810000 */  mtc1      $at, $f0
/* DB82FC 802409EC C62C007C */  lwc1      $f12, 0x7c($s1)
/* DB8300 802409F0 46806320 */  cvt.s.w   $f12, $f12
/* DB8304 802409F4 46006302 */  mul.s     $f12, $f12, $f0
/* DB8308 802409F8 00000000 */  nop       
/* DB830C 802409FC 3C0141F0 */  lui       $at, 0x41f0
/* DB8310 80240A00 44810000 */  mtc1      $at, $f0
/* DB8314 80240A04 0C00A874 */  jal       cos_rad
/* DB8318 80240A08 46006303 */   div.s    $f12, $f12, $f0
/* DB831C 80240A0C 3C013F80 */  lui       $at, 0x3f80
/* DB8320 80240A10 44811000 */  mtc1      $at, $f2
/* DB8324 80240A14 00000000 */  nop       
/* DB8328 80240A18 46001081 */  sub.s     $f2, $f2, $f0
/* DB832C 80240A1C 3C0141A0 */  lui       $at, 0x41a0
/* DB8330 80240A20 44810000 */  mtc1      $at, $f0
/* DB8334 80240A24 00000000 */  nop       
/* DB8338 80240A28 46001082 */  mul.s     $f2, $f2, $f0
/* DB833C 80240A2C 00000000 */  nop       
/* DB8340 80240A30 C6200078 */  lwc1      $f0, 0x78($s1)
/* DB8344 80240A34 46020000 */  add.s     $f0, $f0, $f2
/* DB8348 80240A38 E640000C */  swc1      $f0, 0xc($s2)
/* DB834C 80240A3C 8E23007C */  lw        $v1, 0x7c($s1)
/* DB8350 80240A40 2402001E */  addiu     $v0, $zero, 0x1e
/* DB8354 80240A44 14620005 */  bne       $v1, $v0, .L80240A5C
/* DB8358 80240A48 24620001 */   addiu    $v0, $v1, 1
/* DB835C 80240A4C 24020001 */  addiu     $v0, $zero, 1
/* DB8360 80240A50 AE220074 */  sw        $v0, 0x74($s1)
/* DB8364 80240A54 080902AF */  j         .L80240ABC
/* DB8368 80240A58 AE20007C */   sw       $zero, 0x7c($s1)
.L80240A5C:
/* DB836C 80240A5C 080902AF */  j         .L80240ABC
/* DB8370 80240A60 AE22007C */   sw       $v0, 0x7c($s1)
.L80240A64:
/* DB8374 80240A64 C62C007C */  lwc1      $f12, 0x7c($s1)
/* DB8378 80240A68 0C00A8D4 */  jal       cos_deg
/* DB837C 80240A6C 46806320 */   cvt.s.w  $f12, $f12
/* DB8380 80240A70 3C014040 */  lui       $at, 0x4040
/* DB8384 80240A74 44811000 */  mtc1      $at, $f2
/* DB8388 80240A78 00000000 */  nop       
/* DB838C 80240A7C 46020002 */  mul.s     $f0, $f0, $f2
/* DB8390 80240A80 00000000 */  nop       
/* DB8394 80240A84 3C014188 */  lui       $at, 0x4188
/* DB8398 80240A88 44812000 */  mtc1      $at, $f4
/* DB839C 80240A8C C6220078 */  lwc1      $f2, 0x78($s1)
/* DB83A0 80240A90 46041080 */  add.s     $f2, $f2, $f4
/* DB83A4 80240A94 46001080 */  add.s     $f2, $f2, $f0
/* DB83A8 80240A98 E642000C */  swc1      $f2, 0xc($s2)
/* DB83AC 80240A9C 8E22007C */  lw        $v0, 0x7c($s1)
/* DB83B0 80240AA0 24420009 */  addiu     $v0, $v0, 9
/* DB83B4 80240AA4 44826000 */  mtc1      $v0, $f12
/* DB83B8 80240AA8 00000000 */  nop       
/* DB83BC 80240AAC 0C00A6C9 */  jal       clamp_angle
/* DB83C0 80240AB0 46806320 */   cvt.s.w  $f12, $f12
/* DB83C4 80240AB4 4600018D */  trunc.w.s $f6, $f0
/* DB83C8 80240AB8 E626007C */  swc1      $f6, 0x7c($s1)
.L80240ABC:
/* DB83CC 80240ABC 8FBF001C */  lw        $ra, 0x1c($sp)
/* DB83D0 80240AC0 8FB20018 */  lw        $s2, 0x18($sp)
/* DB83D4 80240AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* DB83D8 80240AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* DB83DC 80240ACC 0000102D */  daddu     $v0, $zero, $zero
/* DB83E0 80240AD0 03E00008 */  jr        $ra
/* DB83E4 80240AD4 27BD0020 */   addiu    $sp, $sp, 0x20

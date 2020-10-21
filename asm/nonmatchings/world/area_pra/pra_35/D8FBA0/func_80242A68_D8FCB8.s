.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A68_D8FCB8
/* D8FCB8 80242A68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8FCBC 80242A6C AFB10014 */  sw        $s1, 0x14($sp)
/* D8FCC0 80242A70 0080882D */  daddu     $s1, $a0, $zero
/* D8FCC4 80242A74 AFBF001C */  sw        $ra, 0x1c($sp)
/* D8FCC8 80242A78 AFB20018 */  sw        $s2, 0x18($sp)
/* D8FCCC 80242A7C AFB00010 */  sw        $s0, 0x10($sp)
/* D8FCD0 80242A80 8E240084 */  lw        $a0, 0x84($s1)
/* D8FCD4 80242A84 0C04C3D6 */  jal       get_item_entity
/* D8FCD8 80242A88 00A0802D */   daddu    $s0, $a1, $zero
/* D8FCDC 80242A8C 12000005 */  beqz      $s0, .L80242AA4
/* D8FCE0 80242A90 0040902D */   daddu    $s2, $v0, $zero
/* D8FCE4 80242A94 C640000C */  lwc1      $f0, 0xc($s2)
/* D8FCE8 80242A98 AE200074 */  sw        $zero, 0x74($s1)
/* D8FCEC 80242A9C AE20007C */  sw        $zero, 0x7c($s1)
/* D8FCF0 80242AA0 E6200078 */  swc1      $f0, 0x78($s1)
.L80242AA4:
/* D8FCF4 80242AA4 8E230074 */  lw        $v1, 0x74($s1)
/* D8FCF8 80242AA8 10600005 */  beqz      $v1, .L80242AC0
/* D8FCFC 80242AAC 24020001 */   addiu    $v0, $zero, 1
/* D8FD00 80242AB0 10620024 */  beq       $v1, $v0, .L80242B44
/* D8FD04 80242AB4 00000000 */   nop      
/* D8FD08 80242AB8 08090AE7 */  j         .L80242B9C
/* D8FD0C 80242ABC 00000000 */   nop      
.L80242AC0:
/* D8FD10 80242AC0 3C013FC9 */  lui       $at, 0x3fc9
/* D8FD14 80242AC4 34210FD8 */  ori       $at, $at, 0xfd8
/* D8FD18 80242AC8 44810000 */  mtc1      $at, $f0
/* D8FD1C 80242ACC C62C007C */  lwc1      $f12, 0x7c($s1)
/* D8FD20 80242AD0 46806320 */  cvt.s.w   $f12, $f12
/* D8FD24 80242AD4 46006302 */  mul.s     $f12, $f12, $f0
/* D8FD28 80242AD8 00000000 */  nop       
/* D8FD2C 80242ADC 3C0141F0 */  lui       $at, 0x41f0
/* D8FD30 80242AE0 44810000 */  mtc1      $at, $f0
/* D8FD34 80242AE4 0C00A874 */  jal       cos_rad
/* D8FD38 80242AE8 46006303 */   div.s    $f12, $f12, $f0
/* D8FD3C 80242AEC 3C013F80 */  lui       $at, 0x3f80
/* D8FD40 80242AF0 44811000 */  mtc1      $at, $f2
/* D8FD44 80242AF4 00000000 */  nop       
/* D8FD48 80242AF8 46001081 */  sub.s     $f2, $f2, $f0
/* D8FD4C 80242AFC 3C0141A0 */  lui       $at, 0x41a0
/* D8FD50 80242B00 44810000 */  mtc1      $at, $f0
/* D8FD54 80242B04 00000000 */  nop       
/* D8FD58 80242B08 46001082 */  mul.s     $f2, $f2, $f0
/* D8FD5C 80242B0C 00000000 */  nop       
/* D8FD60 80242B10 C6200078 */  lwc1      $f0, 0x78($s1)
/* D8FD64 80242B14 46020000 */  add.s     $f0, $f0, $f2
/* D8FD68 80242B18 E640000C */  swc1      $f0, 0xc($s2)
/* D8FD6C 80242B1C 8E23007C */  lw        $v1, 0x7c($s1)
/* D8FD70 80242B20 2402001E */  addiu     $v0, $zero, 0x1e
/* D8FD74 80242B24 14620005 */  bne       $v1, $v0, .L80242B3C
/* D8FD78 80242B28 24620001 */   addiu    $v0, $v1, 1
/* D8FD7C 80242B2C 24020001 */  addiu     $v0, $zero, 1
/* D8FD80 80242B30 AE220074 */  sw        $v0, 0x74($s1)
/* D8FD84 80242B34 08090AE7 */  j         .L80242B9C
/* D8FD88 80242B38 AE20007C */   sw       $zero, 0x7c($s1)
.L80242B3C:
/* D8FD8C 80242B3C 08090AE7 */  j         .L80242B9C
/* D8FD90 80242B40 AE22007C */   sw       $v0, 0x7c($s1)
.L80242B44:
/* D8FD94 80242B44 C62C007C */  lwc1      $f12, 0x7c($s1)
/* D8FD98 80242B48 0C00A8D4 */  jal       cos_deg
/* D8FD9C 80242B4C 46806320 */   cvt.s.w  $f12, $f12
/* D8FDA0 80242B50 3C014040 */  lui       $at, 0x4040
/* D8FDA4 80242B54 44811000 */  mtc1      $at, $f2
/* D8FDA8 80242B58 00000000 */  nop       
/* D8FDAC 80242B5C 46020002 */  mul.s     $f0, $f0, $f2
/* D8FDB0 80242B60 00000000 */  nop       
/* D8FDB4 80242B64 3C014188 */  lui       $at, 0x4188
/* D8FDB8 80242B68 44812000 */  mtc1      $at, $f4
/* D8FDBC 80242B6C C6220078 */  lwc1      $f2, 0x78($s1)
/* D8FDC0 80242B70 46041080 */  add.s     $f2, $f2, $f4
/* D8FDC4 80242B74 46001080 */  add.s     $f2, $f2, $f0
/* D8FDC8 80242B78 E642000C */  swc1      $f2, 0xc($s2)
/* D8FDCC 80242B7C 8E22007C */  lw        $v0, 0x7c($s1)
/* D8FDD0 80242B80 24420009 */  addiu     $v0, $v0, 9
/* D8FDD4 80242B84 44826000 */  mtc1      $v0, $f12
/* D8FDD8 80242B88 00000000 */  nop       
/* D8FDDC 80242B8C 0C00A6C9 */  jal       clamp_angle
/* D8FDE0 80242B90 46806320 */   cvt.s.w  $f12, $f12
/* D8FDE4 80242B94 4600018D */  trunc.w.s $f6, $f0
/* D8FDE8 80242B98 E626007C */  swc1      $f6, 0x7c($s1)
.L80242B9C:
/* D8FDEC 80242B9C 8FBF001C */  lw        $ra, 0x1c($sp)
/* D8FDF0 80242BA0 8FB20018 */  lw        $s2, 0x18($sp)
/* D8FDF4 80242BA4 8FB10014 */  lw        $s1, 0x14($sp)
/* D8FDF8 80242BA8 8FB00010 */  lw        $s0, 0x10($sp)
/* D8FDFC 80242BAC 0000102D */  daddu     $v0, $zero, $zero
/* D8FE00 80242BB0 03E00008 */  jr        $ra
/* D8FE04 80242BB4 27BD0020 */   addiu    $sp, $sp, 0x20

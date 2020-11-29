.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A98_CB9C98
/* CB9C98 80240A98 27BDFF68 */  addiu     $sp, $sp, -0x98
/* CB9C9C 80240A9C 24040030 */  addiu     $a0, $zero, 0x30
/* CB9CA0 80240AA0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* CB9CA4 80240AA4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* CB9CA8 80240AA8 3C05800B */  lui       $a1, %hi(gCameras)
/* CB9CAC 80240AAC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* CB9CB0 80240AB0 AFBF0064 */  sw        $ra, 0x64($sp)
/* CB9CB4 80240AB4 AFBE0060 */  sw        $fp, 0x60($sp)
/* CB9CB8 80240AB8 AFB7005C */  sw        $s7, 0x5c($sp)
/* CB9CBC 80240ABC AFB60058 */  sw        $s6, 0x58($sp)
/* CB9CC0 80240AC0 AFB50054 */  sw        $s5, 0x54($sp)
/* CB9CC4 80240AC4 AFB40050 */  sw        $s4, 0x50($sp)
/* CB9CC8 80240AC8 AFB3004C */  sw        $s3, 0x4c($sp)
/* CB9CCC 80240ACC AFB20048 */  sw        $s2, 0x48($sp)
/* CB9CD0 80240AD0 AFB10044 */  sw        $s1, 0x44($sp)
/* CB9CD4 80240AD4 AFB00040 */  sw        $s0, 0x40($sp)
/* CB9CD8 80240AD8 F7BE0090 */  sdc1      $f30, 0x90($sp)
/* CB9CDC 80240ADC F7BC0088 */  sdc1      $f28, 0x88($sp)
/* CB9CE0 80240AE0 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* CB9CE4 80240AE4 F7B80078 */  sdc1      $f24, 0x78($sp)
/* CB9CE8 80240AE8 F7B60070 */  sdc1      $f22, 0x70($sp)
/* CB9CEC 80240AEC F7B40068 */  sdc1      $f20, 0x68($sp)
/* CB9CF0 80240AF0 00031080 */  sll       $v0, $v1, 2
/* CB9CF4 80240AF4 00431021 */  addu      $v0, $v0, $v1
/* CB9CF8 80240AF8 00021080 */  sll       $v0, $v0, 2
/* CB9CFC 80240AFC 00431023 */  subu      $v0, $v0, $v1
/* CB9D00 80240B00 000218C0 */  sll       $v1, $v0, 3
/* CB9D04 80240B04 00431021 */  addu      $v0, $v0, $v1
/* CB9D08 80240B08 000210C0 */  sll       $v0, $v0, 3
/* CB9D0C 80240B0C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* CB9D10 80240B10 0045B821 */   addu     $s7, $v0, $a1
/* CB9D14 80240B14 0C046B4C */  jal       get_model_from_list_index
/* CB9D18 80240B18 0040202D */   daddu    $a0, $v0, $zero
/* CB9D1C 80240B1C 0040F02D */  daddu     $fp, $v0, $zero
/* CB9D20 80240B20 27B40028 */  addiu     $s4, $sp, 0x28
/* CB9D24 80240B24 27B2002C */  addiu     $s2, $sp, 0x2c
/* CB9D28 80240B28 27B30030 */  addiu     $s3, $sp, 0x30
/* CB9D2C 80240B2C 27B10034 */  addiu     $s1, $sp, 0x34
/* CB9D30 80240B30 8FC20008 */  lw        $v0, 8($fp)
/* CB9D34 80240B34 C7C00098 */  lwc1      $f0, 0x98($fp)
/* CB9D38 80240B38 8C42000C */  lw        $v0, 0xc($v0)
/* CB9D3C 80240B3C 3C013F80 */  lui       $at, 0x3f80
/* CB9D40 80240B40 4481E000 */  mtc1      $at, $f28
/* CB9D44 80240B44 C45E0004 */  lwc1      $f30, 4($v0)
/* CB9D48 80240B48 4680F7A0 */  cvt.s.w   $f30, $f30
/* CB9D4C 80240B4C 461E0001 */  sub.s     $f0, $f0, $f30
/* CB9D50 80240B50 C448001C */  lwc1      $f8, 0x1c($v0)
/* CB9D54 80240B54 46804220 */  cvt.s.w   $f8, $f8
/* CB9D58 80240B58 E7A80038 */  swc1      $f8, 0x38($sp)
/* CB9D5C 80240B5C 44050000 */  mfc1      $a1, $f0
/* CB9D60 80240B60 C7C000A0 */  lwc1      $f0, 0xa0($fp)
/* CB9D64 80240B64 26F000D4 */  addiu     $s0, $s7, 0xd4
/* CB9D68 80240B68 E7BC0010 */  swc1      $f28, 0x10($sp)
/* CB9D6C 80240B6C AFB40014 */  sw        $s4, 0x14($sp)
/* CB9D70 80240B70 AFB20018 */  sw        $s2, 0x18($sp)
/* CB9D74 80240B74 AFB3001C */  sw        $s3, 0x1c($sp)
/* CB9D78 80240B78 46080201 */  sub.s     $f8, $f0, $f8
/* CB9D7C 80240B7C AFB10020 */  sw        $s1, 0x20($sp)
/* CB9D80 80240B80 8FC6009C */  lw        $a2, 0x9c($fp)
/* CB9D84 80240B84 44074000 */  mfc1      $a3, $f8
/* CB9D88 80240B88 0C00A588 */  jal       transform_point
/* CB9D8C 80240B8C 0200202D */   daddu    $a0, $s0, $zero
/* CB9D90 80240B90 C7A00034 */  lwc1      $f0, 0x34($sp)
/* CB9D94 80240B94 C7A60028 */  lwc1      $f6, 0x28($sp)
/* CB9D98 80240B98 4600E003 */  div.s     $f0, $f28, $f0
/* CB9D9C 80240B9C 46003182 */  mul.s     $f6, $f6, $f0
/* CB9DA0 80240BA0 00000000 */  nop       
/* CB9DA4 80240BA4 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* CB9DA8 80240BA8 46000087 */  neg.s     $f2, $f0
/* CB9DAC 80240BAC 46022102 */  mul.s     $f4, $f4, $f2
/* CB9DB0 80240BB0 00000000 */  nop       
/* CB9DB4 80240BB4 C7A20030 */  lwc1      $f2, 0x30($sp)
/* CB9DB8 80240BB8 46001082 */  mul.s     $f2, $f2, $f0
/* CB9DBC 80240BBC 00000000 */  nop       
/* CB9DC0 80240BC0 44804000 */  mtc1      $zero, $f8
/* CB9DC4 80240BC4 00000000 */  nop       
/* CB9DC8 80240BC8 4608003C */  c.lt.s    $f0, $f8
/* CB9DCC 80240BCC E7A00034 */  swc1      $f0, 0x34($sp)
/* CB9DD0 80240BD0 E7A60028 */  swc1      $f6, 0x28($sp)
/* CB9DD4 80240BD4 E7A4002C */  swc1      $f4, 0x2c($sp)
/* CB9DD8 80240BD8 45000003 */  bc1f      .L80240BE8
/* CB9DDC 80240BDC E7A20030 */   swc1     $f2, 0x30($sp)
/* CB9DE0 80240BE0 E7A80028 */  swc1      $f8, 0x28($sp)
/* CB9DE4 80240BE4 E7BC002C */  swc1      $f28, 0x2c($sp)
.L80240BE8:
/* CB9DE8 80240BE8 C7B40028 */  lwc1      $f20, 0x28($sp)
/* CB9DEC 80240BEC C7B6002C */  lwc1      $f22, 0x2c($sp)
/* CB9DF0 80240BF0 C7C00098 */  lwc1      $f0, 0x98($fp)
/* CB9DF4 80240BF4 C7C200A0 */  lwc1      $f2, 0xa0($fp)
/* CB9DF8 80240BF8 C7A80038 */  lwc1      $f8, 0x38($sp)
/* CB9DFC 80240BFC E7BC0010 */  swc1      $f28, 0x10($sp)
/* CB9E00 80240C00 AFB40014 */  sw        $s4, 0x14($sp)
/* CB9E04 80240C04 AFB20018 */  sw        $s2, 0x18($sp)
/* CB9E08 80240C08 461E0001 */  sub.s     $f0, $f0, $f30
/* CB9E0C 80240C0C AFB3001C */  sw        $s3, 0x1c($sp)
/* CB9E10 80240C10 AFB10020 */  sw        $s1, 0x20($sp)
/* CB9E14 80240C14 46081200 */  add.s     $f8, $f2, $f8
/* CB9E18 80240C18 8FC6009C */  lw        $a2, 0x9c($fp)
/* CB9E1C 80240C1C 44050000 */  mfc1      $a1, $f0
/* CB9E20 80240C20 44074000 */  mfc1      $a3, $f8
/* CB9E24 80240C24 0C00A588 */  jal       transform_point
/* CB9E28 80240C28 0200202D */   daddu    $a0, $s0, $zero
/* CB9E2C 80240C2C C7A00034 */  lwc1      $f0, 0x34($sp)
/* CB9E30 80240C30 C7A60028 */  lwc1      $f6, 0x28($sp)
/* CB9E34 80240C34 4600E003 */  div.s     $f0, $f28, $f0
/* CB9E38 80240C38 46003182 */  mul.s     $f6, $f6, $f0
/* CB9E3C 80240C3C 00000000 */  nop       
/* CB9E40 80240C40 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* CB9E44 80240C44 46000087 */  neg.s     $f2, $f0
/* CB9E48 80240C48 46022102 */  mul.s     $f4, $f4, $f2
/* CB9E4C 80240C4C 00000000 */  nop       
/* CB9E50 80240C50 C7A20030 */  lwc1      $f2, 0x30($sp)
/* CB9E54 80240C54 46001082 */  mul.s     $f2, $f2, $f0
/* CB9E58 80240C58 00000000 */  nop       
/* CB9E5C 80240C5C 4600A606 */  mov.s     $f24, $f20
/* CB9E60 80240C60 44804000 */  mtc1      $zero, $f8
/* CB9E64 80240C64 4600B686 */  mov.s     $f26, $f22
/* CB9E68 80240C68 4608003C */  c.lt.s    $f0, $f8
/* CB9E6C 80240C6C E7A00034 */  swc1      $f0, 0x34($sp)
/* CB9E70 80240C70 E7A60028 */  swc1      $f6, 0x28($sp)
/* CB9E74 80240C74 E7A4002C */  swc1      $f4, 0x2c($sp)
/* CB9E78 80240C78 45000003 */  bc1f      .L80240C88
/* CB9E7C 80240C7C E7A20030 */   swc1     $f2, 0x30($sp)
/* CB9E80 80240C80 E7A80028 */  swc1      $f8, 0x28($sp)
/* CB9E84 80240C84 E7BC002C */  swc1      $f28, 0x2c($sp)
.L80240C88:
/* CB9E88 80240C88 C7A20028 */  lwc1      $f2, 0x28($sp)
/* CB9E8C 80240C8C 4614103C */  c.lt.s    $f2, $f20
/* CB9E90 80240C90 00000000 */  nop       
/* CB9E94 80240C94 45030001 */  bc1tl     .L80240C9C
/* CB9E98 80240C98 46001606 */   mov.s    $f24, $f2
.L80240C9C:
/* CB9E9C 80240C9C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CB9EA0 80240CA0 4616003C */  c.lt.s    $f0, $f22
/* CB9EA4 80240CA4 00000000 */  nop       
/* CB9EA8 80240CA8 45030001 */  bc1tl     .L80240CB0
/* CB9EAC 80240CAC 46000686 */   mov.s    $f26, $f0
.L80240CB0:
/* CB9EB0 80240CB0 4602A03C */  c.lt.s    $f20, $f2
/* CB9EB4 80240CB4 00000000 */  nop       
/* CB9EB8 80240CB8 45030001 */  bc1tl     .L80240CC0
/* CB9EBC 80240CBC 46001506 */   mov.s    $f20, $f2
.L80240CC0:
/* CB9EC0 80240CC0 4600B03C */  c.lt.s    $f22, $f0
/* CB9EC4 80240CC4 00000000 */  nop       
/* CB9EC8 80240CC8 45030001 */  bc1tl     .L80240CD0
/* CB9ECC 80240CCC 46000586 */   mov.s    $f22, $f0
.L80240CD0:
/* CB9ED0 80240CD0 C7C00098 */  lwc1      $f0, 0x98($fp)
/* CB9ED4 80240CD4 C7C200A0 */  lwc1      $f2, 0xa0($fp)
/* CB9ED8 80240CD8 C7A80038 */  lwc1      $f8, 0x38($sp)
/* CB9EDC 80240CDC E7BC0010 */  swc1      $f28, 0x10($sp)
/* CB9EE0 80240CE0 AFB40014 */  sw        $s4, 0x14($sp)
/* CB9EE4 80240CE4 AFB20018 */  sw        $s2, 0x18($sp)
/* CB9EE8 80240CE8 461E0000 */  add.s     $f0, $f0, $f30
/* CB9EEC 80240CEC AFB3001C */  sw        $s3, 0x1c($sp)
/* CB9EF0 80240CF0 AFB10020 */  sw        $s1, 0x20($sp)
/* CB9EF4 80240CF4 46081200 */  add.s     $f8, $f2, $f8
/* CB9EF8 80240CF8 8FC6009C */  lw        $a2, 0x9c($fp)
/* CB9EFC 80240CFC 44050000 */  mfc1      $a1, $f0
/* CB9F00 80240D00 44074000 */  mfc1      $a3, $f8
/* CB9F04 80240D04 0C00A588 */  jal       transform_point
/* CB9F08 80240D08 0200202D */   daddu    $a0, $s0, $zero
/* CB9F0C 80240D0C C7A00034 */  lwc1      $f0, 0x34($sp)
/* CB9F10 80240D10 C7A60028 */  lwc1      $f6, 0x28($sp)
/* CB9F14 80240D14 4600E003 */  div.s     $f0, $f28, $f0
/* CB9F18 80240D18 46003182 */  mul.s     $f6, $f6, $f0
/* CB9F1C 80240D1C 00000000 */  nop       
/* CB9F20 80240D20 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* CB9F24 80240D24 46000087 */  neg.s     $f2, $f0
/* CB9F28 80240D28 46022102 */  mul.s     $f4, $f4, $f2
/* CB9F2C 80240D2C 00000000 */  nop       
/* CB9F30 80240D30 C7A20030 */  lwc1      $f2, 0x30($sp)
/* CB9F34 80240D34 46001082 */  mul.s     $f2, $f2, $f0
/* CB9F38 80240D38 00000000 */  nop       
/* CB9F3C 80240D3C 44804000 */  mtc1      $zero, $f8
/* CB9F40 80240D40 00000000 */  nop       
/* CB9F44 80240D44 4608003C */  c.lt.s    $f0, $f8
/* CB9F48 80240D48 E7A00034 */  swc1      $f0, 0x34($sp)
/* CB9F4C 80240D4C E7A60028 */  swc1      $f6, 0x28($sp)
/* CB9F50 80240D50 E7A4002C */  swc1      $f4, 0x2c($sp)
/* CB9F54 80240D54 45000003 */  bc1f      .L80240D64
/* CB9F58 80240D58 E7A20030 */   swc1     $f2, 0x30($sp)
/* CB9F5C 80240D5C E7BC0028 */  swc1      $f28, 0x28($sp)
/* CB9F60 80240D60 E7BC002C */  swc1      $f28, 0x2c($sp)
.L80240D64:
/* CB9F64 80240D64 C7A20028 */  lwc1      $f2, 0x28($sp)
/* CB9F68 80240D68 4618103C */  c.lt.s    $f2, $f24
/* CB9F6C 80240D6C 00000000 */  nop       
/* CB9F70 80240D70 45030001 */  bc1tl     .L80240D78
/* CB9F74 80240D74 46001606 */   mov.s    $f24, $f2
.L80240D78:
/* CB9F78 80240D78 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CB9F7C 80240D7C 461A003C */  c.lt.s    $f0, $f26
/* CB9F80 80240D80 00000000 */  nop       
/* CB9F84 80240D84 45030001 */  bc1tl     .L80240D8C
/* CB9F88 80240D88 46000686 */   mov.s    $f26, $f0
.L80240D8C:
/* CB9F8C 80240D8C 4602A03C */  c.lt.s    $f20, $f2
/* CB9F90 80240D90 00000000 */  nop       
/* CB9F94 80240D94 45030001 */  bc1tl     .L80240D9C
/* CB9F98 80240D98 46001506 */   mov.s    $f20, $f2
.L80240D9C:
/* CB9F9C 80240D9C 4600B03C */  c.lt.s    $f22, $f0
/* CB9FA0 80240DA0 00000000 */  nop       
/* CB9FA4 80240DA4 45030001 */  bc1tl     .L80240DAC
/* CB9FA8 80240DA8 46000586 */   mov.s    $f22, $f0
.L80240DAC:
/* CB9FAC 80240DAC C7C00098 */  lwc1      $f0, 0x98($fp)
/* CB9FB0 80240DB0 C7C200A0 */  lwc1      $f2, 0xa0($fp)
/* CB9FB4 80240DB4 C7A80038 */  lwc1      $f8, 0x38($sp)
/* CB9FB8 80240DB8 E7BC0010 */  swc1      $f28, 0x10($sp)
/* CB9FBC 80240DBC AFB40014 */  sw        $s4, 0x14($sp)
/* CB9FC0 80240DC0 AFB20018 */  sw        $s2, 0x18($sp)
/* CB9FC4 80240DC4 461E0000 */  add.s     $f0, $f0, $f30
/* CB9FC8 80240DC8 AFB3001C */  sw        $s3, 0x1c($sp)
/* CB9FCC 80240DCC AFB10020 */  sw        $s1, 0x20($sp)
/* CB9FD0 80240DD0 46081201 */  sub.s     $f8, $f2, $f8
/* CB9FD4 80240DD4 8FC6009C */  lw        $a2, 0x9c($fp)
/* CB9FD8 80240DD8 44050000 */  mfc1      $a1, $f0
/* CB9FDC 80240DDC 44074000 */  mfc1      $a3, $f8
/* CB9FE0 80240DE0 0C00A588 */  jal       transform_point
/* CB9FE4 80240DE4 26E400D4 */   addiu    $a0, $s7, 0xd4
/* CB9FE8 80240DE8 C7A00034 */  lwc1      $f0, 0x34($sp)
/* CB9FEC 80240DEC C7A60028 */  lwc1      $f6, 0x28($sp)
/* CB9FF0 80240DF0 4600E003 */  div.s     $f0, $f28, $f0
/* CB9FF4 80240DF4 46003182 */  mul.s     $f6, $f6, $f0
/* CB9FF8 80240DF8 00000000 */  nop       
/* CB9FFC 80240DFC C7A4002C */  lwc1      $f4, 0x2c($sp)
/* CBA000 80240E00 46000087 */  neg.s     $f2, $f0
/* CBA004 80240E04 46022102 */  mul.s     $f4, $f4, $f2
/* CBA008 80240E08 00000000 */  nop       
/* CBA00C 80240E0C C7A20030 */  lwc1      $f2, 0x30($sp)
/* CBA010 80240E10 46001082 */  mul.s     $f2, $f2, $f0
/* CBA014 80240E14 00000000 */  nop       
/* CBA018 80240E18 44804000 */  mtc1      $zero, $f8
/* CBA01C 80240E1C 00000000 */  nop       
/* CBA020 80240E20 4608003C */  c.lt.s    $f0, $f8
/* CBA024 80240E24 E7A00034 */  swc1      $f0, 0x34($sp)
/* CBA028 80240E28 E7A60028 */  swc1      $f6, 0x28($sp)
/* CBA02C 80240E2C E7A4002C */  swc1      $f4, 0x2c($sp)
/* CBA030 80240E30 45000003 */  bc1f      .L80240E40
/* CBA034 80240E34 E7A20030 */   swc1     $f2, 0x30($sp)
/* CBA038 80240E38 E7BC0028 */  swc1      $f28, 0x28($sp)
/* CBA03C 80240E3C E7BC002C */  swc1      $f28, 0x2c($sp)
.L80240E40:
/* CBA040 80240E40 C7A20028 */  lwc1      $f2, 0x28($sp)
/* CBA044 80240E44 4618103C */  c.lt.s    $f2, $f24
/* CBA048 80240E48 00000000 */  nop       
/* CBA04C 80240E4C 45030001 */  bc1tl     .L80240E54
/* CBA050 80240E50 46001606 */   mov.s    $f24, $f2
.L80240E54:
/* CBA054 80240E54 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CBA058 80240E58 461A003C */  c.lt.s    $f0, $f26
/* CBA05C 80240E5C 00000000 */  nop       
/* CBA060 80240E60 45030001 */  bc1tl     .L80240E68
/* CBA064 80240E64 46000686 */   mov.s    $f26, $f0
.L80240E68:
/* CBA068 80240E68 4602A03C */  c.lt.s    $f20, $f2
/* CBA06C 80240E6C 00000000 */  nop       
/* CBA070 80240E70 45030001 */  bc1tl     .L80240E78
/* CBA074 80240E74 46001506 */   mov.s    $f20, $f2
.L80240E78:
/* CBA078 80240E78 4600B03C */  c.lt.s    $f22, $f0
/* CBA07C 80240E7C 00000000 */  nop       
/* CBA080 80240E80 45030001 */  bc1tl     .L80240E88
/* CBA084 80240E84 46000586 */   mov.s    $f22, $f0
.L80240E88:
/* CBA088 80240E88 4614C032 */  c.eq.s    $f24, $f20
/* CBA08C 80240E8C 00000000 */  nop       
/* CBA090 80240E90 45000005 */  bc1f      .L80240EA8
/* CBA094 80240E94 00000000 */   nop      
/* CBA098 80240E98 4616D032 */  c.eq.s    $f26, $f22
/* CBA09C 80240E9C 00000000 */  nop       
/* CBA0A0 80240EA0 450100CE */  bc1t      .L802411DC
/* CBA0A4 80240EA4 00000000 */   nop      
.L80240EA8:
/* CBA0A8 80240EA8 86E2000A */  lh        $v0, 0xa($s7)
/* CBA0AC 80240EAC 44821000 */  mtc1      $v0, $f2
/* CBA0B0 80240EB0 00000000 */  nop       
/* CBA0B4 80240EB4 468010A0 */  cvt.s.w   $f2, $f2
/* CBA0B8 80240EB8 4602C002 */  mul.s     $f0, $f24, $f2
/* CBA0BC 80240EBC 00000000 */  nop       
/* CBA0C0 80240EC0 46020000 */  add.s     $f0, $f0, $f2
/* CBA0C4 80240EC4 3C013F00 */  lui       $at, 0x3f00
/* CBA0C8 80240EC8 44813000 */  mtc1      $at, $f6
/* CBA0CC 80240ECC 00000000 */  nop       
/* CBA0D0 80240ED0 46060602 */  mul.s     $f24, $f0, $f6
/* CBA0D4 80240ED4 00000000 */  nop       
/* CBA0D8 80240ED8 86E2000C */  lh        $v0, 0xc($s7)
/* CBA0DC 80240EDC 44822000 */  mtc1      $v0, $f4
/* CBA0E0 80240EE0 00000000 */  nop       
/* CBA0E4 80240EE4 46802120 */  cvt.s.w   $f4, $f4
/* CBA0E8 80240EE8 4604D002 */  mul.s     $f0, $f26, $f4
/* CBA0EC 80240EEC 00000000 */  nop       
/* CBA0F0 80240EF0 46040000 */  add.s     $f0, $f0, $f4
/* CBA0F4 80240EF4 3C18E300 */  lui       $t8, 0xe300
/* CBA0F8 80240EF8 37180A01 */  ori       $t8, $t8, 0xa01
/* CBA0FC 80240EFC 46060682 */  mul.s     $f26, $f0, $f6
/* CBA100 80240F00 00000000 */  nop       
/* CBA104 80240F04 3C14E200 */  lui       $s4, 0xe200
/* CBA108 80240F08 3694001C */  ori       $s4, $s4, 0x1c
/* CBA10C 80240F0C 3C060F0A */  lui       $a2, 0xf0a
/* CBA110 80240F10 34C64010 */  ori       $a2, $a2, 0x4010
/* CBA114 80240F14 4602A002 */  mul.s     $f0, $f20, $f2
/* CBA118 80240F18 00000000 */  nop       
/* CBA11C 80240F1C 3C13FF10 */  lui       $s3, 0xff10
/* CBA120 80240F20 3673013F */  ori       $s3, $s3, 0x13f
/* CBA124 80240F24 3C15FCFF */  lui       $s5, 0xfcff
/* CBA128 80240F28 36B5FFFF */  ori       $s5, $s5, 0xffff
/* CBA12C 80240F2C 46020000 */  add.s     $f0, $f0, $f2
/* CBA130 80240F30 3C16E200 */  lui       $s6, 0xe200
/* CBA134 80240F34 36D61D00 */  ori       $s6, $s6, 0x1d00
/* CBA138 80240F38 46060502 */  mul.s     $f20, $f0, $f6
/* CBA13C 80240F3C 00000000 */  nop       
/* CBA140 80240F40 3C04800A */  lui       $a0, %hi(nuGfxZBuffer)
/* CBA144 80240F44 8C84A5DC */  lw        $a0, %lo(nuGfxZBuffer)($a0)
/* CBA148 80240F48 3C12800A */  lui       $s2, %hi(D_8009A66C)
/* CBA14C 80240F4C 2652A66C */  addiu     $s2, $s2, %lo(D_8009A66C)
/* CBA150 80240F50 AFB8003C */  sw        $t8, 0x3c($sp)
/* CBA154 80240F54 8E510000 */  lw        $s1, ($s2)
/* CBA158 80240F58 4604B002 */  mul.s     $f0, $f22, $f4
/* CBA15C 80240F5C 00000000 */  nop       
/* CBA160 80240F60 86E3000E */  lh        $v1, 0xe($s7)
/* CBA164 80240F64 86E50010 */  lh        $a1, 0x10($s7)
/* CBA168 80240F68 0220102D */  daddu     $v0, $s1, $zero
/* CBA16C 80240F6C 26310008 */  addiu     $s1, $s1, 8
/* CBA170 80240F70 46040000 */  add.s     $f0, $f0, $f4
/* CBA174 80240F74 AE510000 */  sw        $s1, ($s2)
/* CBA178 80240F78 AC580000 */  sw        $t8, ($v0)
/* CBA17C 80240F7C 46060582 */  mul.s     $f22, $f0, $f6
/* CBA180 80240F80 00000000 */  nop       
/* CBA184 80240F84 AC400004 */  sw        $zero, 4($v0)
/* CBA188 80240F88 26220008 */  addiu     $v0, $s1, 8
/* CBA18C 80240F8C AE420000 */  sw        $v0, ($s2)
/* CBA190 80240F90 44851000 */  mtc1      $a1, $f2
/* CBA194 80240F94 00000000 */  nop       
/* CBA198 80240F98 468010A0 */  cvt.s.w   $f2, $f2
/* CBA19C 80240F9C 4602D680 */  add.s     $f26, $f26, $f2
/* CBA1A0 80240FA0 26220010 */  addiu     $v0, $s1, 0x10
/* CBA1A4 80240FA4 44830000 */  mtc1      $v1, $f0
/* CBA1A8 80240FA8 00000000 */  nop       
/* CBA1AC 80240FAC 46800020 */  cvt.s.w   $f0, $f0
/* CBA1B0 80240FB0 4600C600 */  add.s     $f24, $f24, $f0
/* CBA1B4 80240FB4 AE340000 */  sw        $s4, ($s1)
/* CBA1B8 80240FB8 AE260004 */  sw        $a2, 4($s1)
/* CBA1BC 80240FBC 4600A500 */  add.s     $f20, $f20, $f0
/* CBA1C0 80240FC0 AE420000 */  sw        $v0, ($s2)
/* CBA1C4 80240FC4 AE330008 */  sw        $s3, 8($s1)
/* CBA1C8 80240FC8 0C0187A4 */  jal       osVirtualToPhysical
/* CBA1CC 80240FCC 4602B580 */   add.s    $f22, $f22, $f2
/* CBA1D0 80240FD0 3C03FFFD */  lui       $v1, 0xfffd
/* CBA1D4 80240FD4 3463FEFF */  ori       $v1, $v1, 0xfeff
/* CBA1D8 80240FD8 3C05F8F0 */  lui       $a1, 0xf8f0
/* CBA1DC 80240FDC 8E500000 */  lw        $s0, ($s2)
/* CBA1E0 80240FE0 34A5F000 */  ori       $a1, $a1, 0xf000
/* CBA1E4 80240FE4 AE22000C */  sw        $v0, 0xc($s1)
/* CBA1E8 80240FE8 3C11E700 */  lui       $s1, 0xe700
/* CBA1EC 80240FEC 3C04800A */  lui       $a0, %hi(D_8009A64C)
/* CBA1F0 80240FF0 8C84A64C */  lw        $a0, %lo(D_8009A64C)($a0)
/* CBA1F4 80240FF4 0200102D */  daddu     $v0, $s0, $zero
/* CBA1F8 80240FF8 26100008 */  addiu     $s0, $s0, 8
/* CBA1FC 80240FFC AE500000 */  sw        $s0, ($s2)
/* CBA200 80241000 AC550000 */  sw        $s5, ($v0)
/* CBA204 80241004 AC430004 */  sw        $v1, 4($v0)
/* CBA208 80241008 26020008 */  addiu     $v0, $s0, 8
/* CBA20C 8024100C AE420000 */  sw        $v0, ($s2)
/* CBA210 80241010 3C02FA00 */  lui       $v0, 0xfa00
/* CBA214 80241014 AE020000 */  sw        $v0, ($s0)
/* CBA218 80241018 26020010 */  addiu     $v0, $s0, 0x10
/* CBA21C 8024101C AE050004 */  sw        $a1, 4($s0)
/* CBA220 80241020 AE420000 */  sw        $v0, ($s2)
/* CBA224 80241024 3C02DE00 */  lui       $v0, 0xde00
/* CBA228 80241028 AE110008 */  sw        $s1, 8($s0)
/* CBA22C 8024102C AE00000C */  sw        $zero, 0xc($s0)
/* CBA230 80241030 AE020010 */  sw        $v0, 0x10($s0)
/* CBA234 80241034 8FC30008 */  lw        $v1, 8($fp)
/* CBA238 80241038 26020018 */  addiu     $v0, $s0, 0x18
/* CBA23C 8024103C AE420000 */  sw        $v0, ($s2)
/* CBA240 80241040 8C630004 */  lw        $v1, 4($v1)
/* CBA244 80241044 26020020 */  addiu     $v0, $s0, 0x20
/* CBA248 80241048 AE420000 */  sw        $v0, ($s2)
/* CBA24C 8024104C 8C630000 */  lw        $v1, ($v1)
/* CBA250 80241050 26020028 */  addiu     $v0, $s0, 0x28
/* CBA254 80241054 AE420000 */  sw        $v0, ($s2)
/* CBA258 80241058 AE110018 */  sw        $s1, 0x18($s0)
/* CBA25C 8024105C AE00001C */  sw        $zero, 0x1c($s0)
/* CBA260 80241060 AE130020 */  sw        $s3, 0x20($s0)
/* CBA264 80241064 0C0187A4 */  jal       osVirtualToPhysical
/* CBA268 80241068 AE030014 */   sw       $v1, 0x14($s0)
/* CBA26C 8024106C 3C090050 */  lui       $t1, 0x50
/* CBA270 80241070 35294E50 */  ori       $t1, $t1, 0x4e50
/* CBA274 80241074 3C0AE300 */  lui       $t2, 0xe300
/* CBA278 80241078 354A1201 */  ori       $t2, $t2, 0x1201
/* CBA27C 8024107C 3C0BE300 */  lui       $t3, 0xe300
/* CBA280 80241080 356B0C00 */  ori       $t3, $t3, 0xc00
/* CBA284 80241084 3C0CD700 */  lui       $t4, 0xd700
/* CBA288 80241088 358C0002 */  ori       $t4, $t4, 2
/* CBA28C 8024108C 3C0DE300 */  lui       $t5, 0xe300
/* CBA290 80241090 35AD1001 */  ori       $t5, $t5, 0x1001
/* CBA294 80241094 3C0EE300 */  lui       $t6, 0xe300
/* CBA298 80241098 35CE0D01 */  ori       $t6, $t6, 0xd01
/* CBA29C 8024109C 3C0FE300 */  lui       $t7, 0xe300
/* CBA2A0 802410A0 35EF0F00 */  ori       $t7, $t7, 0xf00
/* CBA2A4 802410A4 3C13FFFC */  lui       $s3, 0xfffc
/* CBA2A8 802410A8 3673F67B */  ori       $s3, $s3, 0xf67b
/* CBA2AC 802410AC 4600C20D */  trunc.w.s $f8, $f24
/* CBA2B0 802410B0 44044000 */  mfc1      $a0, $f8
/* CBA2B4 802410B4 4600D20D */  trunc.w.s $f8, $f26
/* CBA2B8 802410B8 44054000 */  mfc1      $a1, $f8
/* CBA2BC 802410BC 4600A20D */  trunc.w.s $f8, $f20
/* CBA2C0 802410C0 44064000 */  mfc1      $a2, $f8
/* CBA2C4 802410C4 8E430000 */  lw        $v1, ($s2)
/* CBA2C8 802410C8 4600B20D */  trunc.w.s $f8, $f22
/* CBA2CC 802410CC 44074000 */  mfc1      $a3, $f8
/* CBA2D0 802410D0 AE020024 */  sw        $v0, 0x24($s0)
/* CBA2D4 802410D4 24020004 */  addiu     $v0, $zero, 4
/* CBA2D8 802410D8 0060402D */  daddu     $t0, $v1, $zero
/* CBA2DC 802410DC 24630008 */  addiu     $v1, $v1, 8
/* CBA2E0 802410E0 AE430000 */  sw        $v1, ($s2)
/* CBA2E4 802410E4 AD020004 */  sw        $v0, 4($t0)
/* CBA2E8 802410E8 24620008 */  addiu     $v0, $v1, 8
/* CBA2EC 802410EC AD160000 */  sw        $s6, ($t0)
/* CBA2F0 802410F0 AE420000 */  sw        $v0, ($s2)
/* CBA2F4 802410F4 3C02EE00 */  lui       $v0, 0xee00
/* CBA2F8 802410F8 AC620000 */  sw        $v0, ($v1)
/* CBA2FC 802410FC 3C027FDE */  lui       $v0, 0x7fde
/* CBA300 80241100 AC620004 */  sw        $v0, 4($v1)
/* CBA304 80241104 24620010 */  addiu     $v0, $v1, 0x10
/* CBA308 80241108 AE420000 */  sw        $v0, ($s2)
/* CBA30C 8024110C 24620018 */  addiu     $v0, $v1, 0x18
/* CBA310 80241110 AC740008 */  sw        $s4, 8($v1)
/* CBA314 80241114 AC69000C */  sw        $t1, 0xc($v1)
/* CBA318 80241118 AE420000 */  sw        $v0, ($s2)
/* CBA31C 8024111C 24620020 */  addiu     $v0, $v1, 0x20
/* CBA320 80241120 AC6A0010 */  sw        $t2, 0x10($v1)
/* CBA324 80241124 AC600014 */  sw        $zero, 0x14($v1)
/* CBA328 80241128 AE420000 */  sw        $v0, ($s2)
/* CBA32C 8024112C 24620028 */  addiu     $v0, $v1, 0x28
/* CBA330 80241130 AC6B0018 */  sw        $t3, 0x18($v1)
/* CBA334 80241134 AC60001C */  sw        $zero, 0x1c($v1)
/* CBA338 80241138 AE420000 */  sw        $v0, ($s2)
/* CBA33C 8024113C 2402FFFF */  addiu     $v0, $zero, -1
/* CBA340 80241140 AC620024 */  sw        $v0, 0x24($v1)
/* CBA344 80241144 24620030 */  addiu     $v0, $v1, 0x30
/* CBA348 80241148 AC6C0020 */  sw        $t4, 0x20($v1)
/* CBA34C 8024114C AE420000 */  sw        $v0, ($s2)
/* CBA350 80241150 24620038 */  addiu     $v0, $v1, 0x38
/* CBA354 80241154 AC6D0028 */  sw        $t5, 0x28($v1)
/* CBA358 80241158 AC60002C */  sw        $zero, 0x2c($v1)
/* CBA35C 8024115C AE420000 */  sw        $v0, ($s2)
/* CBA360 80241160 24620040 */  addiu     $v0, $v1, 0x40
/* CBA364 80241164 AC6E0030 */  sw        $t6, 0x30($v1)
/* CBA368 80241168 AC600034 */  sw        $zero, 0x34($v1)
/* CBA36C 8024116C AE420000 */  sw        $v0, ($s2)
/* CBA370 80241170 24620048 */  addiu     $v0, $v1, 0x48
/* CBA374 80241174 AC6F0038 */  sw        $t7, 0x38($v1)
/* CBA378 80241178 AC60003C */  sw        $zero, 0x3c($v1)
/* CBA37C 8024117C AE420000 */  sw        $v0, ($s2)
/* CBA380 80241180 24620050 */  addiu     $v0, $v1, 0x50
/* CBA384 80241184 AC750040 */  sw        $s5, 0x40($v1)
/* CBA388 80241188 AC730044 */  sw        $s3, 0x44($v1)
/* CBA38C 8024118C AE420000 */  sw        $v0, ($s2)
/* CBA390 80241190 AC710048 */  sw        $s1, 0x48($v1)
/* CBA394 80241194 0C09012C */  jal       func_802404B0_CB96B0
/* CBA398 80241198 AC60004C */   sw       $zero, 0x4c($v1)
/* CBA39C 8024119C 8E420000 */  lw        $v0, ($s2)
/* CBA3A0 802411A0 0040182D */  daddu     $v1, $v0, $zero
/* CBA3A4 802411A4 24420008 */  addiu     $v0, $v0, 8
/* CBA3A8 802411A8 AE420000 */  sw        $v0, ($s2)
/* CBA3AC 802411AC AC710000 */  sw        $s1, ($v1)
/* CBA3B0 802411B0 AC600004 */  sw        $zero, 4($v1)
/* CBA3B4 802411B4 24430008 */  addiu     $v1, $v0, 8
/* CBA3B8 802411B8 AE430000 */  sw        $v1, ($s2)
/* CBA3BC 802411BC 8FB8003C */  lw        $t8, 0x3c($sp)
/* CBA3C0 802411C0 3C030010 */  lui       $v1, 0x10
/* CBA3C4 802411C4 AC580000 */  sw        $t8, ($v0)
/* CBA3C8 802411C8 AC430004 */  sw        $v1, 4($v0)
/* CBA3CC 802411CC 24430010 */  addiu     $v1, $v0, 0x10
/* CBA3D0 802411D0 AE430000 */  sw        $v1, ($s2)
/* CBA3D4 802411D4 AC560008 */  sw        $s6, 8($v0)
/* CBA3D8 802411D8 AC40000C */  sw        $zero, 0xc($v0)
.L802411DC:
/* CBA3DC 802411DC 8FBF0064 */  lw        $ra, 0x64($sp)
/* CBA3E0 802411E0 8FBE0060 */  lw        $fp, 0x60($sp)
/* CBA3E4 802411E4 8FB7005C */  lw        $s7, 0x5c($sp)
/* CBA3E8 802411E8 8FB60058 */  lw        $s6, 0x58($sp)
/* CBA3EC 802411EC 8FB50054 */  lw        $s5, 0x54($sp)
/* CBA3F0 802411F0 8FB40050 */  lw        $s4, 0x50($sp)
/* CBA3F4 802411F4 8FB3004C */  lw        $s3, 0x4c($sp)
/* CBA3F8 802411F8 8FB20048 */  lw        $s2, 0x48($sp)
/* CBA3FC 802411FC 8FB10044 */  lw        $s1, 0x44($sp)
/* CBA400 80241200 8FB00040 */  lw        $s0, 0x40($sp)
/* CBA404 80241204 D7BE0090 */  ldc1      $f30, 0x90($sp)
/* CBA408 80241208 D7BC0088 */  ldc1      $f28, 0x88($sp)
/* CBA40C 8024120C D7BA0080 */  ldc1      $f26, 0x80($sp)
/* CBA410 80241210 D7B80078 */  ldc1      $f24, 0x78($sp)
/* CBA414 80241214 D7B60070 */  ldc1      $f22, 0x70($sp)
/* CBA418 80241218 D7B40068 */  ldc1      $f20, 0x68($sp)
/* CBA41C 8024121C 03E00008 */  jr        $ra
/* CBA420 80241220 27BD0098 */   addiu    $sp, $sp, 0x98
/* CBA424 80241224 00000000 */  nop       
/* CBA428 80241228 00000000 */  nop       
/* CBA42C 8024122C 00000000 */  nop       

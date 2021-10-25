.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B10_ED4D30
/* ED4D30 80240B10 27BDFF68 */  addiu     $sp, $sp, -0x98
/* ED4D34 80240B14 24040030 */  addiu     $a0, $zero, 0x30
/* ED4D38 80240B18 3C038008 */  lui       $v1, %hi(dead_gCurrentCameraID)
/* ED4D3C 80240B1C 8C63C760 */  lw        $v1, %lo(dead_gCurrentCameraID)($v1)
/* ED4D40 80240B20 3C05800C */  lui       $a1, %hi(dead_gCameras)
/* ED4D44 80240B24 24A58D80 */  addiu     $a1, $a1, %lo(dead_gCameras)
/* ED4D48 80240B28 AFBF0064 */  sw        $ra, 0x64($sp)
/* ED4D4C 80240B2C AFBE0060 */  sw        $fp, 0x60($sp)
/* ED4D50 80240B30 AFB7005C */  sw        $s7, 0x5c($sp)
/* ED4D54 80240B34 AFB60058 */  sw        $s6, 0x58($sp)
/* ED4D58 80240B38 AFB50054 */  sw        $s5, 0x54($sp)
/* ED4D5C 80240B3C AFB40050 */  sw        $s4, 0x50($sp)
/* ED4D60 80240B40 AFB3004C */  sw        $s3, 0x4c($sp)
/* ED4D64 80240B44 AFB20048 */  sw        $s2, 0x48($sp)
/* ED4D68 80240B48 AFB10044 */  sw        $s1, 0x44($sp)
/* ED4D6C 80240B4C AFB00040 */  sw        $s0, 0x40($sp)
/* ED4D70 80240B50 F7BE0090 */  sdc1      $f30, 0x90($sp)
/* ED4D74 80240B54 F7BC0088 */  sdc1      $f28, 0x88($sp)
/* ED4D78 80240B58 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* ED4D7C 80240B5C F7B80078 */  sdc1      $f24, 0x78($sp)
/* ED4D80 80240B60 F7B60070 */  sdc1      $f22, 0x70($sp)
/* ED4D84 80240B64 F7B40068 */  sdc1      $f20, 0x68($sp)
/* ED4D88 80240B68 00031080 */  sll       $v0, $v1, 2
/* ED4D8C 80240B6C 00431021 */  addu      $v0, $v0, $v1
/* ED4D90 80240B70 00021080 */  sll       $v0, $v0, 2
/* ED4D94 80240B74 00431023 */  subu      $v0, $v0, $v1
/* ED4D98 80240B78 000218C0 */  sll       $v1, $v0, 3
/* ED4D9C 80240B7C 00431021 */  addu      $v0, $v0, $v1
/* ED4DA0 80240B80 000210C0 */  sll       $v0, $v0, 3
/* ED4DA4 80240B84 0C04949C */  jal       dead_get_model_list_index_from_tree_index
/* ED4DA8 80240B88 0045B021 */   addu     $s6, $v0, $a1
/* ED4DAC 80240B8C 0C0493D1 */  jal       dead_get_model_from_list_index
/* ED4DB0 80240B90 0040202D */   daddu    $a0, $v0, $zero
/* ED4DB4 80240B94 0040882D */  daddu     $s1, $v0, $zero
/* ED4DB8 80240B98 27B50028 */  addiu     $s5, $sp, 0x28
/* ED4DBC 80240B9C 27B3002C */  addiu     $s3, $sp, 0x2c
/* ED4DC0 80240BA0 27B40030 */  addiu     $s4, $sp, 0x30
/* ED4DC4 80240BA4 27B20034 */  addiu     $s2, $sp, 0x34
/* ED4DC8 80240BA8 8E220008 */  lw        $v0, 8($s1)
/* ED4DCC 80240BAC C6200098 */  lwc1      $f0, 0x98($s1)
/* ED4DD0 80240BB0 8C42000C */  lw        $v0, 0xc($v0)
/* ED4DD4 80240BB4 3C013F80 */  lui       $at, 0x3f80
/* ED4DD8 80240BB8 4481C000 */  mtc1      $at, $f24
/* ED4DDC 80240BBC C45E0004 */  lwc1      $f30, 4($v0)
/* ED4DE0 80240BC0 4680F7A0 */  cvt.s.w   $f30, $f30
/* ED4DE4 80240BC4 461E0001 */  sub.s     $f0, $f0, $f30
/* ED4DE8 80240BC8 C448001C */  lwc1      $f8, 0x1c($v0)
/* ED4DEC 80240BCC 46804220 */  cvt.s.w   $f8, $f8
/* ED4DF0 80240BD0 E7A80038 */  swc1      $f8, 0x38($sp)
/* ED4DF4 80240BD4 44050000 */  mfc1      $a1, $f0
/* ED4DF8 80240BD8 C62000A0 */  lwc1      $f0, 0xa0($s1)
/* ED4DFC 80240BDC 26D000D4 */  addiu     $s0, $s6, 0xd4
/* ED4E00 80240BE0 E7B80010 */  swc1      $f24, 0x10($sp)
/* ED4E04 80240BE4 AFB50014 */  sw        $s5, 0x14($sp)
/* ED4E08 80240BE8 AFB30018 */  sw        $s3, 0x18($sp)
/* ED4E0C 80240BEC AFB4001C */  sw        $s4, 0x1c($sp)
/* ED4E10 80240BF0 46080201 */  sub.s     $f8, $f0, $f8
/* ED4E14 80240BF4 AFB20020 */  sw        $s2, 0x20($sp)
/* ED4E18 80240BF8 8E26009C */  lw        $a2, 0x9c($s1)
/* ED4E1C 80240BFC 44074000 */  mfc1      $a3, $f8
/* ED4E20 80240C00 0C00AA44 */  jal       func_8002A910
/* ED4E24 80240C04 0200202D */   daddu    $a0, $s0, $zero
/* ED4E28 80240C08 C7A00034 */  lwc1      $f0, 0x34($sp)
/* ED4E2C 80240C0C C7A60028 */  lwc1      $f6, 0x28($sp)
/* ED4E30 80240C10 4600C003 */  div.s     $f0, $f24, $f0
/* ED4E34 80240C14 46003182 */  mul.s     $f6, $f6, $f0
/* ED4E38 80240C18 00000000 */  nop
/* ED4E3C 80240C1C C7A4002C */  lwc1      $f4, 0x2c($sp)
/* ED4E40 80240C20 46000087 */  neg.s     $f2, $f0
/* ED4E44 80240C24 46022102 */  mul.s     $f4, $f4, $f2
/* ED4E48 80240C28 00000000 */  nop
/* ED4E4C 80240C2C C7A20030 */  lwc1      $f2, 0x30($sp)
/* ED4E50 80240C30 46001082 */  mul.s     $f2, $f2, $f0
/* ED4E54 80240C34 00000000 */  nop
/* ED4E58 80240C38 44804000 */  mtc1      $zero, $f8
/* ED4E5C 80240C3C 00000000 */  nop
/* ED4E60 80240C40 4608003C */  c.lt.s    $f0, $f8
/* ED4E64 80240C44 E7A00034 */  swc1      $f0, 0x34($sp)
/* ED4E68 80240C48 E7A60028 */  swc1      $f6, 0x28($sp)
/* ED4E6C 80240C4C E7A4002C */  swc1      $f4, 0x2c($sp)
/* ED4E70 80240C50 45000003 */  bc1f      .L80240C60
/* ED4E74 80240C54 E7A20030 */   swc1     $f2, 0x30($sp)
/* ED4E78 80240C58 E7A80028 */  swc1      $f8, 0x28($sp)
/* ED4E7C 80240C5C E7B8002C */  swc1      $f24, 0x2c($sp)
.L80240C60:
/* ED4E80 80240C60 C7B60028 */  lwc1      $f22, 0x28($sp)
/* ED4E84 80240C64 C7B4002C */  lwc1      $f20, 0x2c($sp)
/* ED4E88 80240C68 C6200098 */  lwc1      $f0, 0x98($s1)
/* ED4E8C 80240C6C C62200A0 */  lwc1      $f2, 0xa0($s1)
/* ED4E90 80240C70 C7A80038 */  lwc1      $f8, 0x38($sp)
/* ED4E94 80240C74 E7B80010 */  swc1      $f24, 0x10($sp)
/* ED4E98 80240C78 AFB50014 */  sw        $s5, 0x14($sp)
/* ED4E9C 80240C7C AFB30018 */  sw        $s3, 0x18($sp)
/* ED4EA0 80240C80 461E0001 */  sub.s     $f0, $f0, $f30
/* ED4EA4 80240C84 AFB4001C */  sw        $s4, 0x1c($sp)
/* ED4EA8 80240C88 AFB20020 */  sw        $s2, 0x20($sp)
/* ED4EAC 80240C8C 46081200 */  add.s     $f8, $f2, $f8
/* ED4EB0 80240C90 8E26009C */  lw        $a2, 0x9c($s1)
/* ED4EB4 80240C94 44050000 */  mfc1      $a1, $f0
/* ED4EB8 80240C98 44074000 */  mfc1      $a3, $f8
/* ED4EBC 80240C9C 0C00AA44 */  jal       func_8002A910
/* ED4EC0 80240CA0 0200202D */   daddu    $a0, $s0, $zero
/* ED4EC4 80240CA4 C7A00034 */  lwc1      $f0, 0x34($sp)
/* ED4EC8 80240CA8 C7A60028 */  lwc1      $f6, 0x28($sp)
/* ED4ECC 80240CAC 4600C003 */  div.s     $f0, $f24, $f0
/* ED4ED0 80240CB0 46003182 */  mul.s     $f6, $f6, $f0
/* ED4ED4 80240CB4 00000000 */  nop
/* ED4ED8 80240CB8 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* ED4EDC 80240CBC 46000087 */  neg.s     $f2, $f0
/* ED4EE0 80240CC0 46022102 */  mul.s     $f4, $f4, $f2
/* ED4EE4 80240CC4 00000000 */  nop
/* ED4EE8 80240CC8 C7A20030 */  lwc1      $f2, 0x30($sp)
/* ED4EEC 80240CCC 46001082 */  mul.s     $f2, $f2, $f0
/* ED4EF0 80240CD0 00000000 */  nop
/* ED4EF4 80240CD4 4600B686 */  mov.s     $f26, $f22
/* ED4EF8 80240CD8 44804000 */  mtc1      $zero, $f8
/* ED4EFC 80240CDC 4600A706 */  mov.s     $f28, $f20
/* ED4F00 80240CE0 4608003C */  c.lt.s    $f0, $f8
/* ED4F04 80240CE4 E7A00034 */  swc1      $f0, 0x34($sp)
/* ED4F08 80240CE8 E7A60028 */  swc1      $f6, 0x28($sp)
/* ED4F0C 80240CEC E7A4002C */  swc1      $f4, 0x2c($sp)
/* ED4F10 80240CF0 45000003 */  bc1f      .L80240D00
/* ED4F14 80240CF4 E7A20030 */   swc1     $f2, 0x30($sp)
/* ED4F18 80240CF8 E7A80028 */  swc1      $f8, 0x28($sp)
/* ED4F1C 80240CFC E7B8002C */  swc1      $f24, 0x2c($sp)
.L80240D00:
/* ED4F20 80240D00 C7A20028 */  lwc1      $f2, 0x28($sp)
/* ED4F24 80240D04 4616103C */  c.lt.s    $f2, $f22
/* ED4F28 80240D08 00000000 */  nop
/* ED4F2C 80240D0C 45030001 */  bc1tl     .L80240D14
/* ED4F30 80240D10 46001686 */   mov.s    $f26, $f2
.L80240D14:
/* ED4F34 80240D14 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* ED4F38 80240D18 4614003C */  c.lt.s    $f0, $f20
/* ED4F3C 80240D1C 00000000 */  nop
/* ED4F40 80240D20 45030001 */  bc1tl     .L80240D28
/* ED4F44 80240D24 46000706 */   mov.s    $f28, $f0
.L80240D28:
/* ED4F48 80240D28 4602B03C */  c.lt.s    $f22, $f2
/* ED4F4C 80240D2C 00000000 */  nop
/* ED4F50 80240D30 45030001 */  bc1tl     .L80240D38
/* ED4F54 80240D34 46001586 */   mov.s    $f22, $f2
.L80240D38:
/* ED4F58 80240D38 4600A03C */  c.lt.s    $f20, $f0
/* ED4F5C 80240D3C 00000000 */  nop
/* ED4F60 80240D40 45030001 */  bc1tl     .L80240D48
/* ED4F64 80240D44 46000506 */   mov.s    $f20, $f0
.L80240D48:
/* ED4F68 80240D48 C6200098 */  lwc1      $f0, 0x98($s1)
/* ED4F6C 80240D4C C62200A0 */  lwc1      $f2, 0xa0($s1)
/* ED4F70 80240D50 C7A80038 */  lwc1      $f8, 0x38($sp)
/* ED4F74 80240D54 E7B80010 */  swc1      $f24, 0x10($sp)
/* ED4F78 80240D58 AFB50014 */  sw        $s5, 0x14($sp)
/* ED4F7C 80240D5C AFB30018 */  sw        $s3, 0x18($sp)
/* ED4F80 80240D60 461E0000 */  add.s     $f0, $f0, $f30
/* ED4F84 80240D64 AFB4001C */  sw        $s4, 0x1c($sp)
/* ED4F88 80240D68 AFB20020 */  sw        $s2, 0x20($sp)
/* ED4F8C 80240D6C 46081200 */  add.s     $f8, $f2, $f8
/* ED4F90 80240D70 8E26009C */  lw        $a2, 0x9c($s1)
/* ED4F94 80240D74 44050000 */  mfc1      $a1, $f0
/* ED4F98 80240D78 44074000 */  mfc1      $a3, $f8
/* ED4F9C 80240D7C 0C00AA44 */  jal       func_8002A910
/* ED4FA0 80240D80 0200202D */   daddu    $a0, $s0, $zero
/* ED4FA4 80240D84 C7A00034 */  lwc1      $f0, 0x34($sp)
/* ED4FA8 80240D88 C7A60028 */  lwc1      $f6, 0x28($sp)
/* ED4FAC 80240D8C 4600C003 */  div.s     $f0, $f24, $f0
/* ED4FB0 80240D90 46003182 */  mul.s     $f6, $f6, $f0
/* ED4FB4 80240D94 00000000 */  nop
/* ED4FB8 80240D98 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* ED4FBC 80240D9C 46000087 */  neg.s     $f2, $f0
/* ED4FC0 80240DA0 46022102 */  mul.s     $f4, $f4, $f2
/* ED4FC4 80240DA4 00000000 */  nop
/* ED4FC8 80240DA8 C7A20030 */  lwc1      $f2, 0x30($sp)
/* ED4FCC 80240DAC 46001082 */  mul.s     $f2, $f2, $f0
/* ED4FD0 80240DB0 00000000 */  nop
/* ED4FD4 80240DB4 44804000 */  mtc1      $zero, $f8
/* ED4FD8 80240DB8 00000000 */  nop
/* ED4FDC 80240DBC 4608003C */  c.lt.s    $f0, $f8
/* ED4FE0 80240DC0 E7A00034 */  swc1      $f0, 0x34($sp)
/* ED4FE4 80240DC4 E7A60028 */  swc1      $f6, 0x28($sp)
/* ED4FE8 80240DC8 E7A4002C */  swc1      $f4, 0x2c($sp)
/* ED4FEC 80240DCC 45000003 */  bc1f      .L80240DDC
/* ED4FF0 80240DD0 E7A20030 */   swc1     $f2, 0x30($sp)
/* ED4FF4 80240DD4 E7B80028 */  swc1      $f24, 0x28($sp)
/* ED4FF8 80240DD8 E7B8002C */  swc1      $f24, 0x2c($sp)
.L80240DDC:
/* ED4FFC 80240DDC C7A20028 */  lwc1      $f2, 0x28($sp)
/* ED5000 80240DE0 461A103C */  c.lt.s    $f2, $f26
/* ED5004 80240DE4 00000000 */  nop
/* ED5008 80240DE8 45030001 */  bc1tl     .L80240DF0
/* ED500C 80240DEC 46001686 */   mov.s    $f26, $f2
.L80240DF0:
/* ED5010 80240DF0 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* ED5014 80240DF4 461C003C */  c.lt.s    $f0, $f28
/* ED5018 80240DF8 00000000 */  nop
/* ED501C 80240DFC 45030001 */  bc1tl     .L80240E04
/* ED5020 80240E00 46000706 */   mov.s    $f28, $f0
.L80240E04:
/* ED5024 80240E04 4602B03C */  c.lt.s    $f22, $f2
/* ED5028 80240E08 00000000 */  nop
/* ED502C 80240E0C 45030001 */  bc1tl     .L80240E14
/* ED5030 80240E10 46001586 */   mov.s    $f22, $f2
.L80240E14:
/* ED5034 80240E14 4600A03C */  c.lt.s    $f20, $f0
/* ED5038 80240E18 00000000 */  nop
/* ED503C 80240E1C 45030001 */  bc1tl     .L80240E24
/* ED5040 80240E20 46000506 */   mov.s    $f20, $f0
.L80240E24:
/* ED5044 80240E24 C6200098 */  lwc1      $f0, 0x98($s1)
/* ED5048 80240E28 C62200A0 */  lwc1      $f2, 0xa0($s1)
/* ED504C 80240E2C C7A80038 */  lwc1      $f8, 0x38($sp)
/* ED5050 80240E30 E7B80010 */  swc1      $f24, 0x10($sp)
/* ED5054 80240E34 AFB50014 */  sw        $s5, 0x14($sp)
/* ED5058 80240E38 AFB30018 */  sw        $s3, 0x18($sp)
/* ED505C 80240E3C 461E0000 */  add.s     $f0, $f0, $f30
/* ED5060 80240E40 AFB4001C */  sw        $s4, 0x1c($sp)
/* ED5064 80240E44 AFB20020 */  sw        $s2, 0x20($sp)
/* ED5068 80240E48 46081201 */  sub.s     $f8, $f2, $f8
/* ED506C 80240E4C 8E26009C */  lw        $a2, 0x9c($s1)
/* ED5070 80240E50 44050000 */  mfc1      $a1, $f0
/* ED5074 80240E54 44074000 */  mfc1      $a3, $f8
/* ED5078 80240E58 0C00AA44 */  jal       func_8002A910
/* ED507C 80240E5C 26C400D4 */   addiu    $a0, $s6, 0xd4
/* ED5080 80240E60 C7A00034 */  lwc1      $f0, 0x34($sp)
/* ED5084 80240E64 C7A60028 */  lwc1      $f6, 0x28($sp)
/* ED5088 80240E68 4600C003 */  div.s     $f0, $f24, $f0
/* ED508C 80240E6C 46003182 */  mul.s     $f6, $f6, $f0
/* ED5090 80240E70 00000000 */  nop
/* ED5094 80240E74 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* ED5098 80240E78 46000087 */  neg.s     $f2, $f0
/* ED509C 80240E7C 46022102 */  mul.s     $f4, $f4, $f2
/* ED50A0 80240E80 00000000 */  nop
/* ED50A4 80240E84 C7A20030 */  lwc1      $f2, 0x30($sp)
/* ED50A8 80240E88 46001082 */  mul.s     $f2, $f2, $f0
/* ED50AC 80240E8C 00000000 */  nop
/* ED50B0 80240E90 44804000 */  mtc1      $zero, $f8
/* ED50B4 80240E94 00000000 */  nop
/* ED50B8 80240E98 4608003C */  c.lt.s    $f0, $f8
/* ED50BC 80240E9C E7A00034 */  swc1      $f0, 0x34($sp)
/* ED50C0 80240EA0 E7A60028 */  swc1      $f6, 0x28($sp)
/* ED50C4 80240EA4 E7A4002C */  swc1      $f4, 0x2c($sp)
/* ED50C8 80240EA8 45000003 */  bc1f      .L80240EB8
/* ED50CC 80240EAC E7A20030 */   swc1     $f2, 0x30($sp)
/* ED50D0 80240EB0 E7B80028 */  swc1      $f24, 0x28($sp)
/* ED50D4 80240EB4 E7B8002C */  swc1      $f24, 0x2c($sp)
.L80240EB8:
/* ED50D8 80240EB8 C7A20028 */  lwc1      $f2, 0x28($sp)
/* ED50DC 80240EBC 461A103C */  c.lt.s    $f2, $f26
/* ED50E0 80240EC0 00000000 */  nop
/* ED50E4 80240EC4 45030001 */  bc1tl     .L80240ECC
/* ED50E8 80240EC8 46001686 */   mov.s    $f26, $f2
.L80240ECC:
/* ED50EC 80240ECC C7A0002C */  lwc1      $f0, 0x2c($sp)
/* ED50F0 80240ED0 461C003C */  c.lt.s    $f0, $f28
/* ED50F4 80240ED4 00000000 */  nop
/* ED50F8 80240ED8 45030001 */  bc1tl     .L80240EE0
/* ED50FC 80240EDC 46000706 */   mov.s    $f28, $f0
.L80240EE0:
/* ED5100 80240EE0 4602B03C */  c.lt.s    $f22, $f2
/* ED5104 80240EE4 00000000 */  nop
/* ED5108 80240EE8 45030001 */  bc1tl     .L80240EF0
/* ED510C 80240EEC 46001586 */   mov.s    $f22, $f2
.L80240EF0:
/* ED5110 80240EF0 4600A03C */  c.lt.s    $f20, $f0
/* ED5114 80240EF4 00000000 */  nop
/* ED5118 80240EF8 45030001 */  bc1tl     .L80240F00
/* ED511C 80240EFC 46000506 */   mov.s    $f20, $f0
.L80240F00:
/* ED5120 80240F00 4616D032 */  c.eq.s    $f26, $f22
/* ED5124 80240F04 00000000 */  nop
/* ED5128 80240F08 45000005 */  bc1f      .L80240F20
/* ED512C 80240F0C 00000000 */   nop
/* ED5130 80240F10 4614E032 */  c.eq.s    $f28, $f20
/* ED5134 80240F14 00000000 */  nop
/* ED5138 80240F18 450100EC */  bc1t      .L802412CC
/* ED513C 80240F1C 00000000 */   nop
.L80240F20:
/* ED5140 80240F20 86C2000A */  lh        $v0, 0xa($s6)
/* ED5144 80240F24 44821000 */  mtc1      $v0, $f2
/* ED5148 80240F28 00000000 */  nop
/* ED514C 80240F2C 468010A0 */  cvt.s.w   $f2, $f2
/* ED5150 80240F30 4602D002 */  mul.s     $f0, $f26, $f2
/* ED5154 80240F34 00000000 */  nop
/* ED5158 80240F38 46020000 */  add.s     $f0, $f0, $f2
/* ED515C 80240F3C 3C013F00 */  lui       $at, 0x3f00
/* ED5160 80240F40 44813000 */  mtc1      $at, $f6
/* ED5164 80240F44 00000000 */  nop
/* ED5168 80240F48 46060682 */  mul.s     $f26, $f0, $f6
/* ED516C 80240F4C 00000000 */  nop
/* ED5170 80240F50 86C2000C */  lh        $v0, 0xc($s6)
/* ED5174 80240F54 44822000 */  mtc1      $v0, $f4
/* ED5178 80240F58 00000000 */  nop
/* ED517C 80240F5C 46802120 */  cvt.s.w   $f4, $f4
/* ED5180 80240F60 4604E002 */  mul.s     $f0, $f28, $f4
/* ED5184 80240F64 00000000 */  nop
/* ED5188 80240F68 46040000 */  add.s     $f0, $f0, $f4
/* ED518C 80240F6C 46060702 */  mul.s     $f28, $f0, $f6
/* ED5190 80240F70 00000000 */  nop
/* ED5194 80240F74 4602B002 */  mul.s     $f0, $f22, $f2
/* ED5198 80240F78 00000000 */  nop
/* ED519C 80240F7C 3C18E300 */  lui       $t8, 0xe300
/* ED51A0 80240F80 37180A01 */  ori       $t8, $t8, 0xa01
/* ED51A4 80240F84 3C1EE200 */  lui       $fp, 0xe200
/* ED51A8 80240F88 37DE001C */  ori       $fp, $fp, 0x1c
/* ED51AC 80240F8C 46020000 */  add.s     $f0, $f0, $f2
/* ED51B0 80240F90 3C060F0A */  lui       $a2, 0xf0a
/* ED51B4 80240F94 34C64010 */  ori       $a2, $a2, 0x4010
/* ED51B8 80240F98 46060582 */  mul.s     $f22, $f0, $f6
/* ED51BC 80240F9C 00000000 */  nop
/* ED51C0 80240FA0 3C13800A */  lui       $s3, %hi(D_800A15C4)
/* ED51C4 80240FA4 267315C4 */  addiu     $s3, $s3, %lo(D_800A15C4)
/* ED51C8 80240FA8 3C12800A */  lui       $s2, %hi(D_800A1530)
/* ED51CC 80240FAC 26521530 */  addiu     $s2, $s2, %lo(D_800A1530)
/* ED51D0 80240FB0 AFB8003C */  sw        $t8, 0x3c($sp)
/* ED51D4 80240FB4 8E700000 */  lw        $s0, ($s3)
/* ED51D8 80240FB8 4604A002 */  mul.s     $f0, $f20, $f4
/* ED51DC 80240FBC 00000000 */  nop
/* ED51E0 80240FC0 8E440000 */  lw        $a0, ($s2)
/* ED51E4 80240FC4 86C3000E */  lh        $v1, 0xe($s6)
/* ED51E8 80240FC8 86C50010 */  lh        $a1, 0x10($s6)
/* ED51EC 80240FCC 0200102D */  daddu     $v0, $s0, $zero
/* ED51F0 80240FD0 46040000 */  add.s     $f0, $f0, $f4
/* ED51F4 80240FD4 26100008 */  addiu     $s0, $s0, 8
/* ED51F8 80240FD8 AE700000 */  sw        $s0, ($s3)
/* ED51FC 80240FDC 46060502 */  mul.s     $f20, $f0, $f6
/* ED5200 80240FE0 00000000 */  nop
/* ED5204 80240FE4 AC580000 */  sw        $t8, ($v0)
/* ED5208 80240FE8 AC400004 */  sw        $zero, 4($v0)
/* ED520C 80240FEC 26020008 */  addiu     $v0, $s0, 8
/* ED5210 80240FF0 44831000 */  mtc1      $v1, $f2
/* ED5214 80240FF4 00000000 */  nop
/* ED5218 80240FF8 468010A0 */  cvt.s.w   $f2, $f2
/* ED521C 80240FFC 4602D680 */  add.s     $f26, $f26, $f2
/* ED5220 80241000 AE620000 */  sw        $v0, ($s3)
/* ED5224 80241004 26020010 */  addiu     $v0, $s0, 0x10
/* ED5228 80241008 4602B580 */  add.s     $f22, $f22, $f2
/* ED522C 8024100C AE1E0000 */  sw        $fp, ($s0)
/* ED5230 80241010 44850000 */  mtc1      $a1, $f0
/* ED5234 80241014 00000000 */  nop
/* ED5238 80241018 46800020 */  cvt.s.w   $f0, $f0
/* ED523C 8024101C 4600E700 */  add.s     $f28, $f28, $f0
/* ED5240 80241020 AE060004 */  sw        $a2, 4($s0)
/* ED5244 80241024 AE620000 */  sw        $v0, ($s3)
/* ED5248 80241028 0C019BF8 */  jal       func_80066FE0
/* ED524C 8024102C 4600A500 */   add.s    $f20, $f20, $f0
/* ED5250 80241030 30420007 */  andi      $v0, $v0, 7
/* ED5254 80241034 1040000B */  beqz      $v0, .L80241064
/* ED5258 80241038 3C15FF10 */   lui      $s5, 0xff10
/* ED525C 8024103C 8E440000 */  lw        $a0, ($s2)
/* ED5260 80241040 0C019BF8 */  jal       func_80066FE0
/* ED5264 80241044 00000000 */   nop
/* ED5268 80241048 3C048024 */  lui       $a0, %hi(D_80244BB8_ED8DD8)
/* ED526C 8024104C 24844BB8 */  addiu     $a0, $a0, %lo(D_80244BB8_ED8DD8)
/* ED5270 80241050 3C058024 */  lui       $a1, %hi(D_80244BEC_ED8E0C)
/* ED5274 80241054 24A54BEC */  addiu     $a1, $a1, %lo(D_80244BEC_ED8E0C)
/* ED5278 80241058 240600AF */  addiu     $a2, $zero, 0xaf
/* ED527C 8024105C 0C00973F */  jal       osSyncPrintf
/* ED5280 80241060 0040382D */   daddu    $a3, $v0, $zero
.L80241064:
/* ED5284 80241064 36B5013F */  ori       $s5, $s5, 0x13f
/* ED5288 80241068 3C17FCFF */  lui       $s7, 0xfcff
/* ED528C 8024106C 8E440000 */  lw        $a0, ($s2)
/* ED5290 80241070 36F7FFFF */  ori       $s7, $s7, 0xffff
/* ED5294 80241074 0C019BF8 */  jal       func_80066FE0
/* ED5298 80241078 AE150008 */   sw       $s5, 8($s0)
/* ED529C 8024107C 3C03FFFD */  lui       $v1, 0xfffd
/* ED52A0 80241080 3463FEFF */  ori       $v1, $v1, 0xfeff
/* ED52A4 80241084 3C05F8F0 */  lui       $a1, 0xf8f0
/* ED52A8 80241088 3C14800A */  lui       $s4, %hi(D_800A15A4)
/* ED52AC 8024108C 269415A4 */  addiu     $s4, $s4, %lo(D_800A15A4)
/* ED52B0 80241090 34A5F000 */  ori       $a1, $a1, 0xf000
/* ED52B4 80241094 8E720000 */  lw        $s2, ($s3)
/* ED52B8 80241098 8E840000 */  lw        $a0, ($s4)
/* ED52BC 8024109C 3C16E700 */  lui       $s6, 0xe700
/* ED52C0 802410A0 AE02000C */  sw        $v0, 0xc($s0)
/* ED52C4 802410A4 0240102D */  daddu     $v0, $s2, $zero
/* ED52C8 802410A8 26520008 */  addiu     $s2, $s2, 8
/* ED52CC 802410AC AE720000 */  sw        $s2, ($s3)
/* ED52D0 802410B0 AC570000 */  sw        $s7, ($v0)
/* ED52D4 802410B4 AC430004 */  sw        $v1, 4($v0)
/* ED52D8 802410B8 26420008 */  addiu     $v0, $s2, 8
/* ED52DC 802410BC AE620000 */  sw        $v0, ($s3)
/* ED52E0 802410C0 3C02FA00 */  lui       $v0, 0xfa00
/* ED52E4 802410C4 AE420000 */  sw        $v0, ($s2)
/* ED52E8 802410C8 26420010 */  addiu     $v0, $s2, 0x10
/* ED52EC 802410CC AE450004 */  sw        $a1, 4($s2)
/* ED52F0 802410D0 AE620000 */  sw        $v0, ($s3)
/* ED52F4 802410D4 3C02DE00 */  lui       $v0, 0xde00
/* ED52F8 802410D8 AE560008 */  sw        $s6, 8($s2)
/* ED52FC 802410DC AE40000C */  sw        $zero, 0xc($s2)
/* ED5300 802410E0 AE420010 */  sw        $v0, 0x10($s2)
/* ED5304 802410E4 8E230008 */  lw        $v1, 8($s1)
/* ED5308 802410E8 26420018 */  addiu     $v0, $s2, 0x18
/* ED530C 802410EC AE620000 */  sw        $v0, ($s3)
/* ED5310 802410F0 8C630004 */  lw        $v1, 4($v1)
/* ED5314 802410F4 26420020 */  addiu     $v0, $s2, 0x20
/* ED5318 802410F8 AE620000 */  sw        $v0, ($s3)
/* ED531C 802410FC 8C630000 */  lw        $v1, ($v1)
/* ED5320 80241100 26420028 */  addiu     $v0, $s2, 0x28
/* ED5324 80241104 AE620000 */  sw        $v0, ($s3)
/* ED5328 80241108 AE560018 */  sw        $s6, 0x18($s2)
/* ED532C 8024110C AE40001C */  sw        $zero, 0x1c($s2)
/* ED5330 80241110 0C019BF8 */  jal       func_80066FE0
/* ED5334 80241114 AE430014 */   sw       $v1, 0x14($s2)
/* ED5338 80241118 30420007 */  andi      $v0, $v0, 7
/* ED533C 8024111C 1040000B */  beqz      $v0, .L8024114C
/* ED5340 80241120 3C11E200 */   lui      $s1, 0xe200
/* ED5344 80241124 8E840000 */  lw        $a0, ($s4)
/* ED5348 80241128 0C019BF8 */  jal       func_80066FE0
/* ED534C 8024112C 00000000 */   nop
/* ED5350 80241130 3C048024 */  lui       $a0, %hi(D_80244BB8_ED8DD8)
/* ED5354 80241134 24844BB8 */  addiu     $a0, $a0, %lo(D_80244BB8_ED8DD8)
/* ED5358 80241138 3C058024 */  lui       $a1, %hi(D_80244BEC_ED8E0C)
/* ED535C 8024113C 24A54BEC */  addiu     $a1, $a1, %lo(D_80244BEC_ED8E0C)
/* ED5360 80241140 240600BA */  addiu     $a2, $zero, 0xba
/* ED5364 80241144 0C00973F */  jal       osSyncPrintf
/* ED5368 80241148 0040382D */   daddu    $a3, $v0, $zero
.L8024114C:
/* ED536C 8024114C 8E840000 */  lw        $a0, ($s4)
/* ED5370 80241150 36311D00 */  ori       $s1, $s1, 0x1d00
/* ED5374 80241154 0C019BF8 */  jal       func_80066FE0
/* ED5378 80241158 AE550020 */   sw       $s5, 0x20($s2)
/* ED537C 8024115C 3C090050 */  lui       $t1, 0x50
/* ED5380 80241160 35294E50 */  ori       $t1, $t1, 0x4e50
/* ED5384 80241164 3C0AE300 */  lui       $t2, 0xe300
/* ED5388 80241168 354A1201 */  ori       $t2, $t2, 0x1201
/* ED538C 8024116C 3C0BE300 */  lui       $t3, 0xe300
/* ED5390 80241170 356B0C00 */  ori       $t3, $t3, 0xc00
/* ED5394 80241174 3C0CD700 */  lui       $t4, 0xd700
/* ED5398 80241178 358C0002 */  ori       $t4, $t4, 2
/* ED539C 8024117C 3C0DE300 */  lui       $t5, 0xe300
/* ED53A0 80241180 35AD1001 */  ori       $t5, $t5, 0x1001
/* ED53A4 80241184 3C0EE300 */  lui       $t6, 0xe300
/* ED53A8 80241188 35CE0D01 */  ori       $t6, $t6, 0xd01
/* ED53AC 8024118C 3C0FE300 */  lui       $t7, 0xe300
/* ED53B0 80241190 35EF0F00 */  ori       $t7, $t7, 0xf00
/* ED53B4 80241194 3C10FFFC */  lui       $s0, 0xfffc
/* ED53B8 80241198 3610F67B */  ori       $s0, $s0, 0xf67b
/* ED53BC 8024119C 4600D20D */  trunc.w.s $f8, $f26
/* ED53C0 802411A0 44044000 */  mfc1      $a0, $f8
/* ED53C4 802411A4 4600E20D */  trunc.w.s $f8, $f28
/* ED53C8 802411A8 44054000 */  mfc1      $a1, $f8
/* ED53CC 802411AC 4600B20D */  trunc.w.s $f8, $f22
/* ED53D0 802411B0 44064000 */  mfc1      $a2, $f8
/* ED53D4 802411B4 8E630000 */  lw        $v1, ($s3)
/* ED53D8 802411B8 4600A20D */  trunc.w.s $f8, $f20
/* ED53DC 802411BC 44074000 */  mfc1      $a3, $f8
/* ED53E0 802411C0 AE420024 */  sw        $v0, 0x24($s2)
/* ED53E4 802411C4 24020004 */  addiu     $v0, $zero, 4
/* ED53E8 802411C8 0060402D */  daddu     $t0, $v1, $zero
/* ED53EC 802411CC 24630008 */  addiu     $v1, $v1, 8
/* ED53F0 802411D0 AE630000 */  sw        $v1, ($s3)
/* ED53F4 802411D4 AD020004 */  sw        $v0, 4($t0)
/* ED53F8 802411D8 24620008 */  addiu     $v0, $v1, 8
/* ED53FC 802411DC AD110000 */  sw        $s1, ($t0)
/* ED5400 802411E0 AE620000 */  sw        $v0, ($s3)
/* ED5404 802411E4 3C02EE00 */  lui       $v0, 0xee00
/* ED5408 802411E8 AC620000 */  sw        $v0, ($v1)
/* ED540C 802411EC 3C027FDE */  lui       $v0, 0x7fde
/* ED5410 802411F0 AC620004 */  sw        $v0, 4($v1)
/* ED5414 802411F4 24620010 */  addiu     $v0, $v1, 0x10
/* ED5418 802411F8 AE620000 */  sw        $v0, ($s3)
/* ED541C 802411FC 24620018 */  addiu     $v0, $v1, 0x18
/* ED5420 80241200 AC7E0008 */  sw        $fp, 8($v1)
/* ED5424 80241204 AC69000C */  sw        $t1, 0xc($v1)
/* ED5428 80241208 AE620000 */  sw        $v0, ($s3)
/* ED542C 8024120C 24620020 */  addiu     $v0, $v1, 0x20
/* ED5430 80241210 AC6A0010 */  sw        $t2, 0x10($v1)
/* ED5434 80241214 AC600014 */  sw        $zero, 0x14($v1)
/* ED5438 80241218 AE620000 */  sw        $v0, ($s3)
/* ED543C 8024121C 24620028 */  addiu     $v0, $v1, 0x28
/* ED5440 80241220 AC6B0018 */  sw        $t3, 0x18($v1)
/* ED5444 80241224 AC60001C */  sw        $zero, 0x1c($v1)
/* ED5448 80241228 AE620000 */  sw        $v0, ($s3)
/* ED544C 8024122C 2402FFFF */  addiu     $v0, $zero, -1
/* ED5450 80241230 AC620024 */  sw        $v0, 0x24($v1)
/* ED5454 80241234 24620030 */  addiu     $v0, $v1, 0x30
/* ED5458 80241238 AC6C0020 */  sw        $t4, 0x20($v1)
/* ED545C 8024123C AE620000 */  sw        $v0, ($s3)
/* ED5460 80241240 24620038 */  addiu     $v0, $v1, 0x38
/* ED5464 80241244 AC6D0028 */  sw        $t5, 0x28($v1)
/* ED5468 80241248 AC60002C */  sw        $zero, 0x2c($v1)
/* ED546C 8024124C AE620000 */  sw        $v0, ($s3)
/* ED5470 80241250 24620040 */  addiu     $v0, $v1, 0x40
/* ED5474 80241254 AC6E0030 */  sw        $t6, 0x30($v1)
/* ED5478 80241258 AC600034 */  sw        $zero, 0x34($v1)
/* ED547C 8024125C AE620000 */  sw        $v0, ($s3)
/* ED5480 80241260 24620048 */  addiu     $v0, $v1, 0x48
/* ED5484 80241264 AC6F0038 */  sw        $t7, 0x38($v1)
/* ED5488 80241268 AC60003C */  sw        $zero, 0x3c($v1)
/* ED548C 8024126C AE620000 */  sw        $v0, ($s3)
/* ED5490 80241270 24620050 */  addiu     $v0, $v1, 0x50
/* ED5494 80241274 AC770040 */  sw        $s7, 0x40($v1)
/* ED5498 80241278 AC700044 */  sw        $s0, 0x44($v1)
/* ED549C 8024127C AE620000 */  sw        $v0, ($s3)
/* ED54A0 80241280 AC760048 */  sw        $s6, 0x48($v1)
/* ED54A4 80241284 0C09012C */  jal       func_802404B0_ED46D0
/* ED54A8 80241288 AC60004C */   sw       $zero, 0x4c($v1)
/* ED54AC 8024128C 8E620000 */  lw        $v0, ($s3)
/* ED54B0 80241290 0040182D */  daddu     $v1, $v0, $zero
/* ED54B4 80241294 24420008 */  addiu     $v0, $v0, 8
/* ED54B8 80241298 AE620000 */  sw        $v0, ($s3)
/* ED54BC 8024129C AC760000 */  sw        $s6, ($v1)
/* ED54C0 802412A0 AC600004 */  sw        $zero, 4($v1)
/* ED54C4 802412A4 24430008 */  addiu     $v1, $v0, 8
/* ED54C8 802412A8 AE630000 */  sw        $v1, ($s3)
/* ED54CC 802412AC 8FB8003C */  lw        $t8, 0x3c($sp)
/* ED54D0 802412B0 3C030010 */  lui       $v1, 0x10
/* ED54D4 802412B4 AC580000 */  sw        $t8, ($v0)
/* ED54D8 802412B8 AC430004 */  sw        $v1, 4($v0)
/* ED54DC 802412BC 24430010 */  addiu     $v1, $v0, 0x10
/* ED54E0 802412C0 AE630000 */  sw        $v1, ($s3)
/* ED54E4 802412C4 AC510008 */  sw        $s1, 8($v0)
/* ED54E8 802412C8 AC40000C */  sw        $zero, 0xc($v0)
.L802412CC:
/* ED54EC 802412CC 8FBF0064 */  lw        $ra, 0x64($sp)
/* ED54F0 802412D0 8FBE0060 */  lw        $fp, 0x60($sp)
/* ED54F4 802412D4 8FB7005C */  lw        $s7, 0x5c($sp)
/* ED54F8 802412D8 8FB60058 */  lw        $s6, 0x58($sp)
/* ED54FC 802412DC 8FB50054 */  lw        $s5, 0x54($sp)
/* ED5500 802412E0 8FB40050 */  lw        $s4, 0x50($sp)
/* ED5504 802412E4 8FB3004C */  lw        $s3, 0x4c($sp)
/* ED5508 802412E8 8FB20048 */  lw        $s2, 0x48($sp)
/* ED550C 802412EC 8FB10044 */  lw        $s1, 0x44($sp)
/* ED5510 802412F0 8FB00040 */  lw        $s0, 0x40($sp)
/* ED5514 802412F4 D7BE0090 */  ldc1      $f30, 0x90($sp)
/* ED5518 802412F8 D7BC0088 */  ldc1      $f28, 0x88($sp)
/* ED551C 802412FC D7BA0080 */  ldc1      $f26, 0x80($sp)
/* ED5520 80241300 D7B80078 */  ldc1      $f24, 0x78($sp)
/* ED5524 80241304 D7B60070 */  ldc1      $f22, 0x70($sp)
/* ED5528 80241308 D7B40068 */  ldc1      $f20, 0x68($sp)
/* ED552C 8024130C 03E00008 */  jr        $ra
/* ED5530 80241310 27BD0098 */   addiu    $sp, $sp, 0x98
/* ED5534 80241314 00000000 */  nop
/* ED5538 80241318 00000000 */  nop
/* ED553C 8024131C 00000000 */  nop

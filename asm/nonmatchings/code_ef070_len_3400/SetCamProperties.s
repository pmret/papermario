.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetCamProperties
/* F0D9C 802CC3EC 27BDFF60 */  addiu     $sp, $sp, -0xa0
/* F0DA0 802CC3F0 AFB1005C */  sw        $s1, 0x5c($sp)
/* F0DA4 802CC3F4 0080882D */  daddu     $s1, $a0, $zero
/* F0DA8 802CC3F8 AFB20060 */  sw        $s2, 0x60($sp)
/* F0DAC 802CC3FC 00A0902D */  daddu     $s2, $a1, $zero
/* F0DB0 802CC400 AFBF0068 */  sw        $ra, 0x68($sp)
/* F0DB4 802CC404 AFB30064 */  sw        $s3, 0x64($sp)
/* F0DB8 802CC408 AFB00058 */  sw        $s0, 0x58($sp)
/* F0DBC 802CC40C F7BE0098 */  sdc1      $f30, 0x98($sp)
/* F0DC0 802CC410 F7BC0090 */  sdc1      $f28, 0x90($sp)
/* F0DC4 802CC414 F7BA0088 */  sdc1      $f26, 0x88($sp)
/* F0DC8 802CC418 F7B80080 */  sdc1      $f24, 0x80($sp)
/* F0DCC 802CC41C F7B60078 */  sdc1      $f22, 0x78($sp)
/* F0DD0 802CC420 F7B40070 */  sdc1      $f20, 0x70($sp)
/* F0DD4 802CC424 8E30000C */  lw        $s0, 0xc($s1)
/* F0DD8 802CC428 8E050000 */  lw        $a1, ($s0)
/* F0DDC 802CC42C 0C0B1EAF */  jal       get_variable
/* F0DE0 802CC430 26100004 */   addiu    $s0, $s0, 4
/* F0DE4 802CC434 8E050000 */  lw        $a1, ($s0)
/* F0DE8 802CC438 26100004 */  addiu     $s0, $s0, 4
/* F0DEC 802CC43C 0220202D */  daddu     $a0, $s1, $zero
/* F0DF0 802CC440 3C06800B */  lui       $a2, %hi(gCameras)
/* F0DF4 802CC444 24C61D80 */  addiu     $a2, $a2, %lo(gCameras)
/* F0DF8 802CC448 00021880 */  sll       $v1, $v0, 2
/* F0DFC 802CC44C 00621821 */  addu      $v1, $v1, $v0
/* F0E00 802CC450 00031880 */  sll       $v1, $v1, 2
/* F0E04 802CC454 00621823 */  subu      $v1, $v1, $v0
/* F0E08 802CC458 000310C0 */  sll       $v0, $v1, 3
/* F0E0C 802CC45C 00621821 */  addu      $v1, $v1, $v0
/* F0E10 802CC460 000318C0 */  sll       $v1, $v1, 3
/* F0E14 802CC464 0C0B210B */  jal       get_float_variable
/* F0E18 802CC468 00669821 */   addu     $s3, $v1, $a2
/* F0E1C 802CC46C 8E050000 */  lw        $a1, ($s0)
/* F0E20 802CC470 26100004 */  addiu     $s0, $s0, 4
/* F0E24 802CC474 0220202D */  daddu     $a0, $s1, $zero
/* F0E28 802CC478 0C0B210B */  jal       get_float_variable
/* F0E2C 802CC47C E7A00054 */   swc1     $f0, 0x54($sp)
/* F0E30 802CC480 8E050000 */  lw        $a1, ($s0)
/* F0E34 802CC484 26100004 */  addiu     $s0, $s0, 4
/* F0E38 802CC488 0220202D */  daddu     $a0, $s1, $zero
/* F0E3C 802CC48C 0C0B210B */  jal       get_float_variable
/* F0E40 802CC490 46000606 */   mov.s    $f24, $f0
/* F0E44 802CC494 8E050000 */  lw        $a1, ($s0)
/* F0E48 802CC498 26100004 */  addiu     $s0, $s0, 4
/* F0E4C 802CC49C 0220202D */  daddu     $a0, $s1, $zero
/* F0E50 802CC4A0 0C0B210B */  jal       get_float_variable
/* F0E54 802CC4A4 46000586 */   mov.s    $f22, $f0
/* F0E58 802CC4A8 8E050000 */  lw        $a1, ($s0)
/* F0E5C 802CC4AC 26100004 */  addiu     $s0, $s0, 4
/* F0E60 802CC4B0 0220202D */  daddu     $a0, $s1, $zero
/* F0E64 802CC4B4 0C0B210B */  jal       get_float_variable
/* F0E68 802CC4B8 46000506 */   mov.s    $f20, $f0
/* F0E6C 802CC4BC 8E050000 */  lw        $a1, ($s0)
/* F0E70 802CC4C0 26100004 */  addiu     $s0, $s0, 4
/* F0E74 802CC4C4 0220202D */  daddu     $a0, $s1, $zero
/* F0E78 802CC4C8 0C0B210B */  jal       get_float_variable
/* F0E7C 802CC4CC 46000786 */   mov.s    $f30, $f0
/* F0E80 802CC4D0 0220202D */  daddu     $a0, $s1, $zero
/* F0E84 802CC4D4 8E050000 */  lw        $a1, ($s0)
/* F0E88 802CC4D8 0C0B210B */  jal       get_float_variable
/* F0E8C 802CC4DC 46000706 */   mov.s    $f28, $f0
/* F0E90 802CC4E0 12400049 */  beqz      $s2, .L802CC608
/* F0E94 802CC4E4 46000686 */   mov.s    $f26, $f0
/* F0E98 802CC4E8 27A20038 */  addiu     $v0, $sp, 0x38
/* F0E9C 802CC4EC 3C0146FF */  lui       $at, 0x46ff
/* F0EA0 802CC4F0 3421FE00 */  ori       $at, $at, 0xfe00
/* F0EA4 802CC4F4 44811000 */  mtc1      $at, $f2
/* F0EA8 802CC4F8 44802000 */  mtc1      $zero, $f4
/* F0EAC 802CC4FC 3C01BF80 */  lui       $at, 0xbf80
/* F0EB0 802CC500 44810000 */  mtc1      $at, $f0
/* F0EB4 802CC504 3C014120 */  lui       $at, 0x4120
/* F0EB8 802CC508 44817000 */  mtc1      $at, $f14
/* F0EBC 802CC50C 4406A000 */  mfc1      $a2, $f20
/* F0EC0 802CC510 4600C306 */  mov.s     $f12, $f24
/* F0EC4 802CC514 E7A20044 */  swc1      $f2, 0x44($sp)
/* F0EC8 802CC518 AFA20018 */  sw        $v0, 0x18($sp)
/* F0ECC 802CC51C 27A2003C */  addiu     $v0, $sp, 0x3c
/* F0ED0 802CC520 AFA2001C */  sw        $v0, 0x1c($sp)
/* F0ED4 802CC524 27A20040 */  addiu     $v0, $sp, 0x40
/* F0ED8 802CC528 AFA20020 */  sw        $v0, 0x20($sp)
/* F0EDC 802CC52C 27A20044 */  addiu     $v0, $sp, 0x44
/* F0EE0 802CC530 AFA20024 */  sw        $v0, 0x24($sp)
/* F0EE4 802CC534 27A20048 */  addiu     $v0, $sp, 0x48
/* F0EE8 802CC538 AFA20028 */  sw        $v0, 0x28($sp)
/* F0EEC 802CC53C 27A2004C */  addiu     $v0, $sp, 0x4c
/* F0EF0 802CC540 AFA2002C */  sw        $v0, 0x2c($sp)
/* F0EF4 802CC544 27A20050 */  addiu     $v0, $sp, 0x50
/* F0EF8 802CC548 44072000 */  mfc1      $a3, $f4
/* F0EFC 802CC54C 460EB380 */  add.s     $f14, $f22, $f14
/* F0F00 802CC550 E7A00010 */  swc1      $f0, 0x10($sp)
/* F0F04 802CC554 E7A40014 */  swc1      $f4, 0x14($sp)
/* F0F08 802CC558 0C017449 */  jal       test_ray_zones
/* F0F0C 802CC55C AFA20030 */   sw       $v0, 0x30($sp)
/* F0F10 802CC560 0040182D */  daddu     $v1, $v0, $zero
/* F0F14 802CC564 0460001A */  bltz      $v1, .L802CC5D0
/* F0F18 802CC568 000310C0 */   sll      $v0, $v1, 3
/* F0F1C 802CC56C 00431023 */  subu      $v0, $v0, $v1
/* F0F20 802CC570 3C03800E */  lui       $v1, %hi(D_800D91D4)
/* F0F24 802CC574 8C6391D4 */  lw        $v1, %lo(D_800D91D4)($v1)
/* F0F28 802CC578 00021080 */  sll       $v0, $v0, 2
/* F0F2C 802CC57C 00431021 */  addu      $v0, $v0, $v1
/* F0F30 802CC580 8C420010 */  lw        $v0, 0x10($v0)
/* F0F34 802CC584 266304D8 */  addiu     $v1, $s3, 0x4d8
/* F0F38 802CC588 24440020 */  addiu     $a0, $v0, 0x20
.L802CC58C:
/* F0F3C 802CC58C 8C480000 */  lw        $t0, ($v0)
/* F0F40 802CC590 8C490004 */  lw        $t1, 4($v0)
/* F0F44 802CC594 8C4A0008 */  lw        $t2, 8($v0)
/* F0F48 802CC598 8C4B000C */  lw        $t3, 0xc($v0)
/* F0F4C 802CC59C AC680000 */  sw        $t0, ($v1)
/* F0F50 802CC5A0 AC690004 */  sw        $t1, 4($v1)
/* F0F54 802CC5A4 AC6A0008 */  sw        $t2, 8($v1)
/* F0F58 802CC5A8 AC6B000C */  sw        $t3, 0xc($v1)
/* F0F5C 802CC5AC 24420010 */  addiu     $v0, $v0, 0x10
/* F0F60 802CC5B0 1444FFF6 */  bne       $v0, $a0, .L802CC58C
/* F0F64 802CC5B4 24630010 */   addiu    $v1, $v1, 0x10
/* F0F68 802CC5B8 8C480000 */  lw        $t0, ($v0)
/* F0F6C 802CC5BC 8C490004 */  lw        $t1, 4($v0)
/* F0F70 802CC5C0 8C4A0008 */  lw        $t2, 8($v0)
/* F0F74 802CC5C4 AC680000 */  sw        $t0, ($v1)
/* F0F78 802CC5C8 AC690004 */  sw        $t1, 4($v1)
/* F0F7C 802CC5CC AC6A0008 */  sw        $t2, 8($v1)
.L802CC5D0:
/* F0F80 802CC5D0 0000102D */  daddu     $v0, $zero, $zero
/* F0F84 802CC5D4 E67804B0 */  swc1      $f24, 0x4b0($s3)
/* F0F88 802CC5D8 E67604B4 */  swc1      $f22, 0x4b4($s3)
/* F0F8C 802CC5DC E67404B8 */  swc1      $f20, 0x4b8($s3)
/* F0F90 802CC5E0 E67E04DC */  swc1      $f30, 0x4dc($s3)
/* F0F94 802CC5E4 E67C04E0 */  swc1      $f28, 0x4e0($s3)
/* F0F98 802CC5E8 E67A04FC */  swc1      $f26, 0x4fc($s3)
/* F0F9C 802CC5EC C7A60054 */  lwc1      $f6, 0x54($sp)
/* F0FA0 802CC5F0 24030001 */  addiu     $v1, $zero, 1
/* F0FA4 802CC5F4 E6660490 */  swc1      $f6, 0x490($s3)
/* F0FA8 802CC5F8 A6630506 */  sh        $v1, 0x506($s3)
/* F0FAC 802CC5FC A6630504 */  sh        $v1, 0x504($s3)
/* F0FB0 802CC600 080B318B */  j         .L802CC62C
/* F0FB4 802CC604 AE600508 */   sw       $zero, 0x508($s3)
.L802CC608:
/* F0FB8 802CC608 C6620484 */  lwc1      $f2, 0x484($s3)
/* F0FBC 802CC60C 3C013F80 */  lui       $at, 0x3f80
/* F0FC0 802CC610 44810000 */  mtc1      $at, $f0
/* F0FC4 802CC614 00000000 */  nop       
/* F0FC8 802CC618 4602003E */  c.le.s    $f0, $f2
/* F0FCC 802CC61C 00000000 */  nop       
/* F0FD0 802CC620 45010002 */  bc1t      .L802CC62C
/* F0FD4 802CC624 24020002 */   addiu    $v0, $zero, 2
/* F0FD8 802CC628 0000102D */  daddu     $v0, $zero, $zero
.L802CC62C:
/* F0FDC 802CC62C 8FBF0068 */  lw        $ra, 0x68($sp)
/* F0FE0 802CC630 8FB30064 */  lw        $s3, 0x64($sp)
/* F0FE4 802CC634 8FB20060 */  lw        $s2, 0x60($sp)
/* F0FE8 802CC638 8FB1005C */  lw        $s1, 0x5c($sp)
/* F0FEC 802CC63C 8FB00058 */  lw        $s0, 0x58($sp)
/* F0FF0 802CC640 D7BE0098 */  ldc1      $f30, 0x98($sp)
/* F0FF4 802CC644 D7BC0090 */  ldc1      $f28, 0x90($sp)
/* F0FF8 802CC648 D7BA0088 */  ldc1      $f26, 0x88($sp)
/* F0FFC 802CC64C D7B80080 */  ldc1      $f24, 0x80($sp)
/* F1000 802CC650 D7B60078 */  ldc1      $f22, 0x78($sp)
/* F1004 802CC654 D7B40070 */  ldc1      $f20, 0x70($sp)
/* F1008 802CC658 03E00008 */  jr        $ra
/* F100C 802CC65C 27BD00A0 */   addiu    $sp, $sp, 0xa0

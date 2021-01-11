.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A5C_EDF41C
/* EDF41C 80240A5C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* EDF420 80240A60 AFB3004C */  sw        $s3, 0x4c($sp)
/* EDF424 80240A64 0080982D */  daddu     $s3, $a0, $zero
/* EDF428 80240A68 AFBF0054 */  sw        $ra, 0x54($sp)
/* EDF42C 80240A6C AFB40050 */  sw        $s4, 0x50($sp)
/* EDF430 80240A70 AFB20048 */  sw        $s2, 0x48($sp)
/* EDF434 80240A74 AFB10044 */  sw        $s1, 0x44($sp)
/* EDF438 80240A78 AFB00040 */  sw        $s0, 0x40($sp)
/* EDF43C 80240A7C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* EDF440 80240A80 F7B80068 */  sdc1      $f24, 0x68($sp)
/* EDF444 80240A84 F7B60060 */  sdc1      $f22, 0x60($sp)
/* EDF448 80240A88 F7B40058 */  sdc1      $f20, 0x58($sp)
/* EDF44C 80240A8C 8E710148 */  lw        $s1, 0x148($s3)
/* EDF450 80240A90 00A0902D */  daddu     $s2, $a1, $zero
/* EDF454 80240A94 86240008 */  lh        $a0, 8($s1)
/* EDF458 80240A98 0C00F92F */  jal       func_8003E4BC
/* EDF45C 80240A9C 00C0A02D */   daddu    $s4, $a2, $zero
/* EDF460 80240AA0 0040802D */  daddu     $s0, $v0, $zero
/* EDF464 80240AA4 C6200078 */  lwc1      $f0, 0x78($s1)
/* EDF468 80240AA8 46800020 */  cvt.s.w   $f0, $f0
/* EDF46C 80240AAC 46000021 */  cvt.d.s   $f0, $f0
/* EDF470 80240AB0 3C014059 */  lui       $at, 0x4059
/* EDF474 80240AB4 44811800 */  mtc1      $at, $f3
/* EDF478 80240AB8 44801000 */  mtc1      $zero, $f2
/* EDF47C 80240ABC 8602008E */  lh        $v0, 0x8e($s0)
/* EDF480 80240AC0 9603008E */  lhu       $v1, 0x8e($s0)
/* EDF484 80240AC4 46220003 */  div.d     $f0, $f0, $f2
/* EDF488 80240AC8 46200620 */  cvt.s.d   $f24, $f0
/* EDF48C 80240ACC C6200088 */  lwc1      $f0, 0x88($s1)
/* EDF490 80240AD0 46800020 */  cvt.s.w   $f0, $f0
/* EDF494 80240AD4 46000021 */  cvt.d.s   $f0, $f0
/* EDF498 80240AD8 46220003 */  div.d     $f0, $f0, $f2
/* EDF49C 80240ADC 46200020 */  cvt.s.d   $f0, $f0
/* EDF4A0 80240AE0 18400003 */  blez      $v0, .L80240AF0
/* EDF4A4 80240AE4 4600C680 */   add.s    $f26, $f24, $f0
/* EDF4A8 80240AE8 2462FFFF */  addiu     $v0, $v1, -1
/* EDF4AC 80240AEC A602008E */  sh        $v0, 0x8e($s0)
.L80240AF0:
/* EDF4B0 80240AF0 8E220070 */  lw        $v0, 0x70($s1)
/* EDF4B4 80240AF4 18400034 */  blez      $v0, .L80240BC8
/* EDF4B8 80240AF8 00000000 */   nop      
/* EDF4BC 80240AFC C62C0074 */  lwc1      $f12, 0x74($s1)
/* EDF4C0 80240B00 46806320 */  cvt.s.w   $f12, $f12
/* EDF4C4 80240B04 44820000 */  mtc1      $v0, $f0
/* EDF4C8 80240B08 00000000 */  nop       
/* EDF4CC 80240B0C 46800020 */  cvt.s.w   $f0, $f0
/* EDF4D0 80240B10 46000021 */  cvt.d.s   $f0, $f0
/* EDF4D4 80240B14 46220003 */  div.d     $f0, $f0, $f2
/* EDF4D8 80240B18 0C00AD77 */  jal       func_8002B5DC
/* EDF4DC 80240B1C 462005A0 */   cvt.s.d  $f22, $f0
/* EDF4E0 80240B20 8E020000 */  lw        $v0, ($s0)
/* EDF4E4 80240B24 30420008 */  andi      $v0, $v0, 8
/* EDF4E8 80240B28 10400003 */  beqz      $v0, .L80240B38
/* EDF4EC 80240B2C 46000506 */   mov.s    $f20, $f0
/* EDF4F0 80240B30 080902DE */  j         .L80240B78
/* EDF4F4 80240B34 0000102D */   daddu    $v0, $zero, $zero
.L80240B38:
/* EDF4F8 80240B38 27A50028 */  addiu     $a1, $sp, 0x28
/* EDF4FC 80240B3C 27A6002C */  addiu     $a2, $sp, 0x2c
/* EDF500 80240B40 C6000038 */  lwc1      $f0, 0x38($s0)
/* EDF504 80240B44 C602003C */  lwc1      $f2, 0x3c($s0)
/* EDF508 80240B48 C6040040 */  lwc1      $f4, 0x40($s0)
/* EDF50C 80240B4C 3C01447A */  lui       $at, 0x447a
/* EDF510 80240B50 44813000 */  mtc1      $at, $f6
/* EDF514 80240B54 27A20034 */  addiu     $v0, $sp, 0x34
/* EDF518 80240B58 E7A00028 */  swc1      $f0, 0x28($sp)
/* EDF51C 80240B5C E7A2002C */  swc1      $f2, 0x2c($sp)
/* EDF520 80240B60 E7A40030 */  swc1      $f4, 0x30($sp)
/* EDF524 80240B64 E7A60034 */  swc1      $f6, 0x34($sp)
/* EDF528 80240B68 AFA20010 */  sw        $v0, 0x10($sp)
/* EDF52C 80240B6C 8E040080 */  lw        $a0, 0x80($s0)
/* EDF530 80240B70 0C03908F */  jal       func_800E423C
/* EDF534 80240B74 27A70030 */   addiu    $a3, $sp, 0x30
.L80240B78:
/* EDF538 80240B78 10400007 */  beqz      $v0, .L80240B98
/* EDF53C 80240B7C 00000000 */   nop      
/* EDF540 80240B80 4616A082 */  mul.s     $f2, $f20, $f22
/* EDF544 80240B84 00000000 */  nop       
/* EDF548 80240B88 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* EDF54C 80240B8C 46180000 */  add.s     $f0, $f0, $f24
/* EDF550 80240B90 080902E9 */  j         .L80240BA4
/* EDF554 80240B94 46020000 */   add.s    $f0, $f0, $f2
.L80240B98:
/* EDF558 80240B98 4616A002 */  mul.s     $f0, $f20, $f22
/* EDF55C 80240B9C 00000000 */  nop       
/* EDF560 80240BA0 4600D000 */  add.s     $f0, $f26, $f0
.L80240BA4:
/* EDF564 80240BA4 E600003C */  swc1      $f0, 0x3c($s0)
/* EDF568 80240BA8 8E220074 */  lw        $v0, 0x74($s1)
/* EDF56C 80240BAC 2442000A */  addiu     $v0, $v0, 0xa
/* EDF570 80240BB0 44826000 */  mtc1      $v0, $f12
/* EDF574 80240BB4 00000000 */  nop       
/* EDF578 80240BB8 0C00AB85 */  jal       func_8002AE14
/* EDF57C 80240BBC 46806320 */   cvt.s.w  $f12, $f12
/* EDF580 80240BC0 4600020D */  trunc.w.s $f8, $f0
/* EDF584 80240BC4 E6280074 */  swc1      $f8, 0x74($s1)
.L80240BC8:
/* EDF588 80240BC8 8E220090 */  lw        $v0, 0x90($s1)
/* EDF58C 80240BCC 1C400040 */  bgtz      $v0, .L80240CD0
/* EDF590 80240BD0 2442FFFF */   addiu    $v0, $v0, -1
/* EDF594 80240BD4 860200A8 */  lh        $v0, 0xa8($s0)
/* EDF598 80240BD8 C600003C */  lwc1      $f0, 0x3c($s0)
/* EDF59C 80240BDC 44821000 */  mtc1      $v0, $f2
/* EDF5A0 80240BE0 00000000 */  nop       
/* EDF5A4 80240BE4 468010A0 */  cvt.s.w   $f2, $f2
/* EDF5A8 80240BE8 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EDF5AC 80240BEC 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EDF5B0 80240BF0 46020000 */  add.s     $f0, $f0, $f2
/* EDF5B4 80240BF4 3C014024 */  lui       $at, 0x4024
/* EDF5B8 80240BF8 44812800 */  mtc1      $at, $f5
/* EDF5BC 80240BFC 44802000 */  mtc1      $zero, $f4
/* EDF5C0 80240C00 C442002C */  lwc1      $f2, 0x2c($v0)
/* EDF5C4 80240C04 46000021 */  cvt.d.s   $f0, $f0
/* EDF5C8 80240C08 46240000 */  add.d     $f0, $f0, $f4
/* EDF5CC 80240C0C 460010A1 */  cvt.d.s   $f2, $f2
/* EDF5D0 80240C10 4620103C */  c.lt.d    $f2, $f0
/* EDF5D4 80240C14 00000000 */  nop       
/* EDF5D8 80240C18 4500002E */  bc1f      .L80240CD4
/* EDF5DC 80240C1C 0280202D */   daddu    $a0, $s4, $zero
/* EDF5E0 80240C20 24020001 */  addiu     $v0, $zero, 1
/* EDF5E4 80240C24 AFA20010 */  sw        $v0, 0x10($sp)
/* EDF5E8 80240C28 8E460024 */  lw        $a2, 0x24($s2)
/* EDF5EC 80240C2C 8E470028 */  lw        $a3, 0x28($s2)
/* EDF5F0 80240C30 0C013469 */  jal       func_8004D1A4
/* EDF5F4 80240C34 0220282D */   daddu    $a1, $s1, $zero
/* EDF5F8 80240C38 10400026 */  beqz      $v0, .L80240CD4
/* EDF5FC 80240C3C 0000202D */   daddu    $a0, $zero, $zero
/* EDF600 80240C40 0200282D */  daddu     $a1, $s0, $zero
/* EDF604 80240C44 0000302D */  daddu     $a2, $zero, $zero
/* EDF608 80240C48 2412000C */  addiu     $s2, $zero, 0xc
/* EDF60C 80240C4C 860300A8 */  lh        $v1, 0xa8($s0)
/* EDF610 80240C50 3C013F80 */  lui       $at, 0x3f80
/* EDF614 80240C54 44810000 */  mtc1      $at, $f0
/* EDF618 80240C58 3C014000 */  lui       $at, 0x4000
/* EDF61C 80240C5C 44811000 */  mtc1      $at, $f2
/* EDF620 80240C60 3C01C1A0 */  lui       $at, 0xc1a0
/* EDF624 80240C64 44812000 */  mtc1      $at, $f4
/* EDF628 80240C68 44834000 */  mtc1      $v1, $f8
/* EDF62C 80240C6C 00000000 */  nop       
/* EDF630 80240C70 46804220 */  cvt.s.w   $f8, $f8
/* EDF634 80240C74 44074000 */  mfc1      $a3, $f8
/* EDF638 80240C78 27A20038 */  addiu     $v0, $sp, 0x38
/* EDF63C 80240C7C AFB2001C */  sw        $s2, 0x1c($sp)
/* EDF640 80240C80 AFA20020 */  sw        $v0, 0x20($sp)
/* EDF644 80240C84 E7A00010 */  swc1      $f0, 0x10($sp)
/* EDF648 80240C88 E7A20014 */  swc1      $f2, 0x14($sp)
/* EDF64C 80240C8C 0C01D444 */  jal       func_80075110
/* EDF650 80240C90 E7A40018 */   swc1     $f4, 0x18($sp)
/* EDF654 80240C94 0200202D */  daddu     $a0, $s0, $zero
/* EDF658 80240C98 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EDF65C 80240C9C C480003C */  lwc1      $f0, 0x3c($a0)
/* EDF660 80240CA0 3C060020 */  lui       $a2, 0x20
/* EDF664 80240CA4 0C013600 */  jal       func_8004D800
/* EDF668 80240CA8 E4800064 */   swc1     $f0, 0x64($a0)
/* EDF66C 80240CAC 8E220018 */  lw        $v0, 0x18($s1)
/* EDF670 80240CB0 9442002A */  lhu       $v0, 0x2a($v0)
/* EDF674 80240CB4 30420001 */  andi      $v0, $v0, 1
/* EDF678 80240CB8 10400003 */  beqz      $v0, .L80240CC8
/* EDF67C 80240CBC 2402000A */   addiu    $v0, $zero, 0xa
/* EDF680 80240CC0 0809035C */  j         .L80240D70
/* EDF684 80240CC4 AE620070 */   sw       $v0, 0x70($s3)
.L80240CC8:
/* EDF688 80240CC8 0809035C */  j         .L80240D70
/* EDF68C 80240CCC AE720070 */   sw       $s2, 0x70($s3)
.L80240CD0:
/* EDF690 80240CD0 AE220090 */  sw        $v0, 0x90($s1)
.L80240CD4:
/* EDF694 80240CD4 8602008C */  lh        $v0, 0x8c($s0)
/* EDF698 80240CD8 14400025 */  bnez      $v0, .L80240D70
/* EDF69C 80240CDC 00000000 */   nop      
/* EDF6A0 80240CE0 8602008E */  lh        $v0, 0x8e($s0)
/* EDF6A4 80240CE4 1C400022 */  bgtz      $v0, .L80240D70
/* EDF6A8 80240CE8 00000000 */   nop      
/* EDF6AC 80240CEC 8E620074 */  lw        $v0, 0x74($s3)
/* EDF6B0 80240CF0 2442FFFF */  addiu     $v0, $v0, -1
/* EDF6B4 80240CF4 1840001D */  blez      $v0, .L80240D6C
/* EDF6B8 80240CF8 AE620074 */   sw       $v0, 0x74($s3)
/* EDF6BC 80240CFC 8E220018 */  lw        $v0, 0x18($s1)
/* EDF6C0 80240D00 9442002A */  lhu       $v0, 0x2a($v0)
/* EDF6C4 80240D04 30420010 */  andi      $v0, $v0, 0x10
/* EDF6C8 80240D08 14400007 */  bnez      $v0, .L80240D28
/* EDF6CC 80240D0C 00000000 */   nop      
/* EDF6D0 80240D10 C600000C */  lwc1      $f0, 0xc($s0)
/* EDF6D4 80240D14 3C014334 */  lui       $at, 0x4334
/* EDF6D8 80240D18 44816000 */  mtc1      $at, $f12
/* EDF6DC 80240D1C 0C00AB85 */  jal       func_8002AE14
/* EDF6E0 80240D20 460C0300 */   add.s    $f12, $f0, $f12
/* EDF6E4 80240D24 E600000C */  swc1      $f0, 0xc($s0)
.L80240D28:
/* EDF6E8 80240D28 0C00AB3B */  jal       func_8002ACEC
/* EDF6EC 80240D2C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* EDF6F0 80240D30 3C032E8B */  lui       $v1, 0x2e8b
/* EDF6F4 80240D34 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* EDF6F8 80240D38 00430018 */  mult      $v0, $v1
/* EDF6FC 80240D3C 00021FC3 */  sra       $v1, $v0, 0x1f
/* EDF700 80240D40 00004010 */  mfhi      $t0
/* EDF704 80240D44 00082043 */  sra       $a0, $t0, 1
/* EDF708 80240D48 00832023 */  subu      $a0, $a0, $v1
/* EDF70C 80240D4C 00041840 */  sll       $v1, $a0, 1
/* EDF710 80240D50 00641821 */  addu      $v1, $v1, $a0
/* EDF714 80240D54 00031880 */  sll       $v1, $v1, 2
/* EDF718 80240D58 00641823 */  subu      $v1, $v1, $a0
/* EDF71C 80240D5C 00431023 */  subu      $v0, $v0, $v1
/* EDF720 80240D60 24420005 */  addiu     $v0, $v0, 5
/* EDF724 80240D64 0809035C */  j         .L80240D70
/* EDF728 80240D68 A602008E */   sh       $v0, 0x8e($s0)
.L80240D6C:
/* EDF72C 80240D6C AE600070 */  sw        $zero, 0x70($s3)
.L80240D70:
/* EDF730 80240D70 8FBF0054 */  lw        $ra, 0x54($sp)
/* EDF734 80240D74 8FB40050 */  lw        $s4, 0x50($sp)
/* EDF738 80240D78 8FB3004C */  lw        $s3, 0x4c($sp)
/* EDF73C 80240D7C 8FB20048 */  lw        $s2, 0x48($sp)
/* EDF740 80240D80 8FB10044 */  lw        $s1, 0x44($sp)
/* EDF744 80240D84 8FB00040 */  lw        $s0, 0x40($sp)
/* EDF748 80240D88 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* EDF74C 80240D8C D7B80068 */  ldc1      $f24, 0x68($sp)
/* EDF750 80240D90 D7B60060 */  ldc1      $f22, 0x60($sp)
/* EDF754 80240D94 D7B40058 */  ldc1      $f20, 0x58($sp)
/* EDF758 80240D98 03E00008 */  jr        $ra
/* EDF75C 80240D9C 27BD0078 */   addiu    $sp, $sp, 0x78

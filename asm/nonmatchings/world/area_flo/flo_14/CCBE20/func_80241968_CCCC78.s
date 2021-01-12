.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241968_CCCC78
/* CCCC78 80241968 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CCCC7C 8024196C AFB20030 */  sw        $s2, 0x30($sp)
/* CCCC80 80241970 0080902D */  daddu     $s2, $a0, $zero
/* CCCC84 80241974 AFBF0038 */  sw        $ra, 0x38($sp)
/* CCCC88 80241978 AFB30034 */  sw        $s3, 0x34($sp)
/* CCCC8C 8024197C AFB1002C */  sw        $s1, 0x2c($sp)
/* CCCC90 80241980 AFB00028 */  sw        $s0, 0x28($sp)
/* CCCC94 80241984 F7B60048 */  sdc1      $f22, 0x48($sp)
/* CCCC98 80241988 F7B40040 */  sdc1      $f20, 0x40($sp)
/* CCCC9C 8024198C 8E510148 */  lw        $s1, 0x148($s2)
/* CCCCA0 80241990 86240008 */  lh        $a0, 8($s1)
/* CCCCA4 80241994 0C00EABB */  jal       get_npc_unsafe
/* CCCCA8 80241998 00A0982D */   daddu    $s3, $a1, $zero
/* CCCCAC 8024199C 0040802D */  daddu     $s0, $v0, $zero
/* CCCCB0 802419A0 0200202D */  daddu     $a0, $s0, $zero
/* CCCCB4 802419A4 C6220088 */  lwc1      $f2, 0x88($s1)
/* CCCCB8 802419A8 468010A0 */  cvt.s.w   $f2, $f2
/* CCCCBC 802419AC 460010A1 */  cvt.d.s   $f2, $f2
/* CCCCC0 802419B0 C604001C */  lwc1      $f4, 0x1c($s0)
/* CCCCC4 802419B4 C6000014 */  lwc1      $f0, 0x14($s0)
/* CCCCC8 802419B8 8E050018 */  lw        $a1, 0x18($s0)
/* CCCCCC 802419BC 46002100 */  add.s     $f4, $f4, $f0
/* CCCCD0 802419C0 8E06000C */  lw        $a2, 0xc($s0)
/* CCCCD4 802419C4 C6200078 */  lwc1      $f0, 0x78($s1)
/* CCCCD8 802419C8 46800020 */  cvt.s.w   $f0, $f0
/* CCCCDC 802419CC E604001C */  swc1      $f4, 0x1c($s0)
/* CCCCE0 802419D0 3C014059 */  lui       $at, 0x4059
/* CCCCE4 802419D4 44812800 */  mtc1      $at, $f5
/* CCCCE8 802419D8 44802000 */  mtc1      $zero, $f4
/* CCCCEC 802419DC 46000021 */  cvt.d.s   $f0, $f0
/* CCCCF0 802419E0 46240003 */  div.d     $f0, $f0, $f4
/* CCCCF4 802419E4 46200520 */  cvt.s.d   $f20, $f0
/* CCCCF8 802419E8 46241083 */  div.d     $f2, $f2, $f4
/* CCCCFC 802419EC 0C00EA95 */  jal       npc_move_heading
/* CCCD00 802419F0 462015A0 */   cvt.s.d  $f22, $f2
/* CCCD04 802419F4 C604001C */  lwc1      $f4, 0x1c($s0)
/* CCCD08 802419F8 44801000 */  mtc1      $zero, $f2
/* CCCD0C 802419FC 44801800 */  mtc1      $zero, $f3
/* CCCD10 80241A00 46002021 */  cvt.d.s   $f0, $f4
/* CCCD14 80241A04 4620103E */  c.le.d    $f2, $f0
/* CCCD18 80241A08 00000000 */  nop
/* CCCD1C 80241A0C 45000030 */  bc1f      .L80241AD0
/* CCCD20 80241A10 00000000 */   nop
/* CCCD24 80241A14 C600003C */  lwc1      $f0, 0x3c($s0)
/* CCCD28 80241A18 46040000 */  add.s     $f0, $f0, $f4
/* CCCD2C 80241A1C E600003C */  swc1      $f0, 0x3c($s0)
/* CCCD30 80241A20 8E2200CC */  lw        $v0, 0xcc($s1)
/* CCCD34 80241A24 8C420024 */  lw        $v0, 0x24($v0)
/* CCCD38 80241A28 AE020028 */  sw        $v0, 0x28($s0)
/* CCCD3C 80241A2C A2200007 */  sb        $zero, 7($s1)
/* CCCD40 80241A30 8E020000 */  lw        $v0, ($s0)
/* CCCD44 80241A34 30420008 */  andi      $v0, $v0, 8
/* CCCD48 80241A38 14400011 */  bnez      $v0, .L80241A80
/* CCCD4C 80241A3C 0000102D */   daddu    $v0, $zero, $zero
/* CCCD50 80241A40 27A50018 */  addiu     $a1, $sp, 0x18
/* CCCD54 80241A44 27A6001C */  addiu     $a2, $sp, 0x1c
/* CCCD58 80241A48 C6000038 */  lwc1      $f0, 0x38($s0)
/* CCCD5C 80241A4C C602003C */  lwc1      $f2, 0x3c($s0)
/* CCCD60 80241A50 C6040040 */  lwc1      $f4, 0x40($s0)
/* CCCD64 80241A54 3C01447A */  lui       $at, 0x447a
/* CCCD68 80241A58 44813000 */  mtc1      $at, $f6
/* CCCD6C 80241A5C 27A20024 */  addiu     $v0, $sp, 0x24
/* CCCD70 80241A60 E7A00018 */  swc1      $f0, 0x18($sp)
/* CCCD74 80241A64 E7A2001C */  swc1      $f2, 0x1c($sp)
/* CCCD78 80241A68 E7A40020 */  swc1      $f4, 0x20($sp)
/* CCCD7C 80241A6C E7A60024 */  swc1      $f6, 0x24($sp)
/* CCCD80 80241A70 AFA20010 */  sw        $v0, 0x10($sp)
/* CCCD84 80241A74 8E040080 */  lw        $a0, 0x80($s0)
/* CCCD88 80241A78 0C0372DF */  jal       func_800DCB7C
/* CCCD8C 80241A7C 27A70020 */   addiu    $a3, $sp, 0x20
.L80241A80:
/* CCCD90 80241A80 1040000B */  beqz      $v0, .L80241AB0
/* CCCD94 80241A84 00000000 */   nop
/* CCCD98 80241A88 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CCCD9C 80241A8C 46140080 */  add.s     $f2, $f0, $f20
/* CCCDA0 80241A90 C600003C */  lwc1      $f0, 0x3c($s0)
/* CCCDA4 80241A94 4600103E */  c.le.s    $f2, $f0
/* CCCDA8 80241A98 00000000 */  nop
/* CCCDAC 80241A9C 4500008D */  bc1f      .L80241CD4
/* CCCDB0 80241AA0 00000000 */   nop
/* CCCDB4 80241AA4 E602003C */  swc1      $f2, 0x3c($s0)
/* CCCDB8 80241AA8 08090735 */  j         .L80241CD4
/* CCCDBC 80241AAC AE400070 */   sw       $zero, 0x70($s2)
.L80241AB0:
/* CCCDC0 80241AB0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CCCDC4 80241AB4 C6000064 */  lwc1      $f0, 0x64($s0)
/* CCCDC8 80241AB8 4602003E */  c.le.s    $f0, $f2
/* CCCDCC 80241ABC 00000000 */  nop
/* CCCDD0 80241AC0 45030084 */  bc1tl     .L80241CD4
/* CCCDD4 80241AC4 AE400070 */   sw       $zero, 0x70($s2)
/* CCCDD8 80241AC8 08090735 */  j         .L80241CD4
/* CCCDDC 80241ACC 00000000 */   nop
.L80241AD0:
/* CCCDE0 80241AD0 4622003C */  c.lt.d    $f0, $f2
/* CCCDE4 80241AD4 00000000 */  nop
/* CCCDE8 80241AD8 4500007E */  bc1f      .L80241CD4
/* CCCDEC 80241ADC 00000000 */   nop
/* CCCDF0 80241AE0 9602008E */  lhu       $v0, 0x8e($s0)
/* CCCDF4 80241AE4 24420001 */  addiu     $v0, $v0, 1
/* CCCDF8 80241AE8 A602008E */  sh        $v0, 0x8e($s0)
/* CCCDFC 80241AEC 00021400 */  sll       $v0, $v0, 0x10
/* CCCE00 80241AF0 8E630020 */  lw        $v1, 0x20($s3)
/* CCCE04 80241AF4 00021403 */  sra       $v0, $v0, 0x10
/* CCCE08 80241AF8 0043102A */  slt       $v0, $v0, $v1
/* CCCE0C 80241AFC 14400026 */  bnez      $v0, .L80241B98
/* CCCE10 80241B00 00000000 */   nop
/* CCCE14 80241B04 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CCCE18 80241B08 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CCCE1C 80241B0C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CCCE20 80241B10 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CCCE24 80241B14 A600008E */  sh        $zero, 0x8e($s0)
/* CCCE28 80241B18 8C460028 */  lw        $a2, 0x28($v0)
/* CCCE2C 80241B1C 0C00A720 */  jal       atan2
/* CCCE30 80241B20 8C470030 */   lw       $a3, 0x30($v0)
/* CCCE34 80241B24 46000506 */  mov.s     $f20, $f0
/* CCCE38 80241B28 C60C000C */  lwc1      $f12, 0xc($s0)
/* CCCE3C 80241B2C 0C00A70A */  jal       get_clamped_angle_diff
/* CCCE40 80241B30 4600A386 */   mov.s    $f14, $f20
/* CCCE44 80241B34 46000086 */  mov.s     $f2, $f0
/* CCCE48 80241B38 8E62001C */  lw        $v0, 0x1c($s3)
/* CCCE4C 80241B3C 46001005 */  abs.s     $f0, $f2
/* CCCE50 80241B40 44822000 */  mtc1      $v0, $f4
/* CCCE54 80241B44 00000000 */  nop
/* CCCE58 80241B48 46802120 */  cvt.s.w   $f4, $f4
/* CCCE5C 80241B4C 4600203C */  c.lt.s    $f4, $f0
/* CCCE60 80241B50 00000000 */  nop
/* CCCE64 80241B54 4500000D */  bc1f      .L80241B8C
/* CCCE68 80241B58 00000000 */   nop
/* CCCE6C 80241B5C 44800000 */  mtc1      $zero, $f0
/* CCCE70 80241B60 C614000C */  lwc1      $f20, 0xc($s0)
/* CCCE74 80241B64 4600103C */  c.lt.s    $f2, $f0
/* CCCE78 80241B68 00000000 */  nop
/* CCCE7C 80241B6C 45000006 */  bc1f      .L80241B88
/* CCCE80 80241B70 00021023 */   negu     $v0, $v0
/* CCCE84 80241B74 44820000 */  mtc1      $v0, $f0
/* CCCE88 80241B78 00000000 */  nop
/* CCCE8C 80241B7C 46800020 */  cvt.s.w   $f0, $f0
/* CCCE90 80241B80 080906E3 */  j         .L80241B8C
/* CCCE94 80241B84 4600A500 */   add.s    $f20, $f20, $f0
.L80241B88:
/* CCCE98 80241B88 4604A500 */  add.s     $f20, $f20, $f4
.L80241B8C:
/* CCCE9C 80241B8C 0C00A6C9 */  jal       clamp_angle
/* CCCEA0 80241B90 4600A306 */   mov.s    $f12, $f20
/* CCCEA4 80241B94 E600000C */  swc1      $f0, 0xc($s0)
.L80241B98:
/* CCCEA8 80241B98 8E020000 */  lw        $v0, ($s0)
/* CCCEAC 80241B9C 30420008 */  andi      $v0, $v0, 8
/* CCCEB0 80241BA0 1040000A */  beqz      $v0, .L80241BCC
/* CCCEB4 80241BA4 27A50018 */   addiu    $a1, $sp, 0x18
/* CCCEB8 80241BA8 C602003C */  lwc1      $f2, 0x3c($s0)
/* CCCEBC 80241BAC C600001C */  lwc1      $f0, 0x1c($s0)
/* CCCEC0 80241BB0 46001080 */  add.s     $f2, $f2, $f0
/* CCCEC4 80241BB4 4616103C */  c.lt.s    $f2, $f22
/* CCCEC8 80241BB8 00000000 */  nop
/* CCCECC 80241BBC 45020045 */  bc1fl     .L80241CD4
/* CCCED0 80241BC0 E602003C */   swc1     $f2, 0x3c($s0)
/* CCCED4 80241BC4 08090734 */  j         .L80241CD0
/* CCCED8 80241BC8 E616003C */   swc1     $f22, 0x3c($s0)
.L80241BCC:
/* CCCEDC 80241BCC C6000038 */  lwc1      $f0, 0x38($s0)
/* CCCEE0 80241BD0 27A6001C */  addiu     $a2, $sp, 0x1c
/* CCCEE4 80241BD4 E7A00018 */  swc1      $f0, 0x18($sp)
/* CCCEE8 80241BD8 860200A8 */  lh        $v0, 0xa8($s0)
/* CCCEEC 80241BDC C600001C */  lwc1      $f0, 0x1c($s0)
/* CCCEF0 80241BE0 C604003C */  lwc1      $f4, 0x3c($s0)
/* CCCEF4 80241BE4 44821000 */  mtc1      $v0, $f2
/* CCCEF8 80241BE8 00000000 */  nop
/* CCCEFC 80241BEC 468010A0 */  cvt.s.w   $f2, $f2
/* CCCF00 80241BF0 46000005 */  abs.s     $f0, $f0
/* CCCF04 80241BF4 46020000 */  add.s     $f0, $f0, $f2
/* CCCF08 80241BF8 C6060040 */  lwc1      $f6, 0x40($s0)
/* CCCF0C 80241BFC 27A20024 */  addiu     $v0, $sp, 0x24
/* CCCF10 80241C00 46022100 */  add.s     $f4, $f4, $f2
/* CCCF14 80241C04 3C014024 */  lui       $at, 0x4024
/* CCCF18 80241C08 44811800 */  mtc1      $at, $f3
/* CCCF1C 80241C0C 44801000 */  mtc1      $zero, $f2
/* CCCF20 80241C10 46000021 */  cvt.d.s   $f0, $f0
/* CCCF24 80241C14 46220000 */  add.d     $f0, $f0, $f2
/* CCCF28 80241C18 E7A60020 */  swc1      $f6, 0x20($sp)
/* CCCF2C 80241C1C E7A4001C */  swc1      $f4, 0x1c($sp)
/* CCCF30 80241C20 46200020 */  cvt.s.d   $f0, $f0
/* CCCF34 80241C24 E7A00024 */  swc1      $f0, 0x24($sp)
/* CCCF38 80241C28 AFA20010 */  sw        $v0, 0x10($sp)
/* CCCF3C 80241C2C 8E040080 */  lw        $a0, 0x80($s0)
/* CCCF40 80241C30 0C0372DF */  jal       func_800DCB7C
/* CCCF44 80241C34 27A70020 */   addiu    $a3, $sp, 0x20
/* CCCF48 80241C38 10400015 */  beqz      $v0, .L80241C90
/* CCCF4C 80241C3C 00000000 */   nop
/* CCCF50 80241C40 860200A8 */  lh        $v0, 0xa8($s0)
/* CCCF54 80241C44 C604001C */  lwc1      $f4, 0x1c($s0)
/* CCCF58 80241C48 44820000 */  mtc1      $v0, $f0
/* CCCF5C 80241C4C 00000000 */  nop
/* CCCF60 80241C50 46800020 */  cvt.s.w   $f0, $f0
/* CCCF64 80241C54 46002085 */  abs.s     $f2, $f4
/* CCCF68 80241C58 46020000 */  add.s     $f0, $f0, $f2
/* CCCF6C 80241C5C C7A20024 */  lwc1      $f2, 0x24($sp)
/* CCCF70 80241C60 4600103E */  c.le.s    $f2, $f0
/* CCCF74 80241C64 00000000 */  nop
/* CCCF78 80241C68 45000005 */  bc1f      .L80241C80
/* CCCF7C 80241C6C 00000000 */   nop
/* CCCF80 80241C70 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CCCF84 80241C74 AE00001C */  sw        $zero, 0x1c($s0)
/* CCCF88 80241C78 08090735 */  j         .L80241CD4
/* CCCF8C 80241C7C E600003C */   swc1     $f0, 0x3c($s0)
.L80241C80:
/* CCCF90 80241C80 C600003C */  lwc1      $f0, 0x3c($s0)
/* CCCF94 80241C84 46040000 */  add.s     $f0, $f0, $f4
/* CCCF98 80241C88 08090735 */  j         .L80241CD4
/* CCCF9C 80241C8C E600003C */   swc1     $f0, 0x3c($s0)
.L80241C90:
/* CCCFA0 80241C90 C606003C */  lwc1      $f6, 0x3c($s0)
/* CCCFA4 80241C94 860200A8 */  lh        $v0, 0xa8($s0)
/* CCCFA8 80241C98 46163081 */  sub.s     $f2, $f6, $f22
/* CCCFAC 80241C9C 44820000 */  mtc1      $v0, $f0
/* CCCFB0 80241CA0 00000000 */  nop
/* CCCFB4 80241CA4 46800020 */  cvt.s.w   $f0, $f0
/* CCCFB8 80241CA8 46001080 */  add.s     $f2, $f2, $f0
/* CCCFBC 80241CAC C604001C */  lwc1      $f4, 0x1c($s0)
/* CCCFC0 80241CB0 46002005 */  abs.s     $f0, $f4
/* CCCFC4 80241CB4 4602003C */  c.lt.s    $f0, $f2
/* CCCFC8 80241CB8 00000000 */  nop
/* CCCFCC 80241CBC 45020005 */  bc1fl     .L80241CD4
/* CCCFD0 80241CC0 AE00001C */   sw       $zero, 0x1c($s0)
/* CCCFD4 80241CC4 46043000 */  add.s     $f0, $f6, $f4
/* CCCFD8 80241CC8 08090735 */  j         .L80241CD4
/* CCCFDC 80241CCC E600003C */   swc1     $f0, 0x3c($s0)
.L80241CD0:
/* CCCFE0 80241CD0 AE00001C */  sw        $zero, 0x1c($s0)
.L80241CD4:
/* CCCFE4 80241CD4 8FBF0038 */  lw        $ra, 0x38($sp)
/* CCCFE8 80241CD8 8FB30034 */  lw        $s3, 0x34($sp)
/* CCCFEC 80241CDC 8FB20030 */  lw        $s2, 0x30($sp)
/* CCCFF0 80241CE0 8FB1002C */  lw        $s1, 0x2c($sp)
/* CCCFF4 80241CE4 8FB00028 */  lw        $s0, 0x28($sp)
/* CCCFF8 80241CE8 D7B60048 */  ldc1      $f22, 0x48($sp)
/* CCCFFC 80241CEC D7B40040 */  ldc1      $f20, 0x40($sp)
/* CCD000 80241CF0 03E00008 */  jr        $ra
/* CCD004 80241CF4 27BD0050 */   addiu    $sp, $sp, 0x50

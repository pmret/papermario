.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241968_EE7F18
/* EE7F18 80241968 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EE7F1C 8024196C AFB20030 */  sw        $s2, 0x30($sp)
/* EE7F20 80241970 0080902D */  daddu     $s2, $a0, $zero
/* EE7F24 80241974 AFBF0038 */  sw        $ra, 0x38($sp)
/* EE7F28 80241978 AFB30034 */  sw        $s3, 0x34($sp)
/* EE7F2C 8024197C AFB1002C */  sw        $s1, 0x2c($sp)
/* EE7F30 80241980 AFB00028 */  sw        $s0, 0x28($sp)
/* EE7F34 80241984 F7B60048 */  sdc1      $f22, 0x48($sp)
/* EE7F38 80241988 F7B40040 */  sdc1      $f20, 0x40($sp)
/* EE7F3C 8024198C 8E510148 */  lw        $s1, 0x148($s2)
/* EE7F40 80241990 86240008 */  lh        $a0, 8($s1)
/* EE7F44 80241994 0C00F92F */  jal       func_8003E4BC
/* EE7F48 80241998 00A0982D */   daddu    $s3, $a1, $zero
/* EE7F4C 8024199C 0040802D */  daddu     $s0, $v0, $zero
/* EE7F50 802419A0 0200202D */  daddu     $a0, $s0, $zero
/* EE7F54 802419A4 C6220088 */  lwc1      $f2, 0x88($s1)
/* EE7F58 802419A8 468010A0 */  cvt.s.w   $f2, $f2
/* EE7F5C 802419AC 460010A1 */  cvt.d.s   $f2, $f2
/* EE7F60 802419B0 C604001C */  lwc1      $f4, 0x1c($s0)
/* EE7F64 802419B4 C6000014 */  lwc1      $f0, 0x14($s0)
/* EE7F68 802419B8 8E050018 */  lw        $a1, 0x18($s0)
/* EE7F6C 802419BC 46002100 */  add.s     $f4, $f4, $f0
/* EE7F70 802419C0 8E06000C */  lw        $a2, 0xc($s0)
/* EE7F74 802419C4 C6200078 */  lwc1      $f0, 0x78($s1)
/* EE7F78 802419C8 46800020 */  cvt.s.w   $f0, $f0
/* EE7F7C 802419CC E604001C */  swc1      $f4, 0x1c($s0)
/* EE7F80 802419D0 3C014059 */  lui       $at, 0x4059
/* EE7F84 802419D4 44812800 */  mtc1      $at, $f5
/* EE7F88 802419D8 44802000 */  mtc1      $zero, $f4
/* EE7F8C 802419DC 46000021 */  cvt.d.s   $f0, $f0
/* EE7F90 802419E0 46240003 */  div.d     $f0, $f0, $f4
/* EE7F94 802419E4 46200520 */  cvt.s.d   $f20, $f0
/* EE7F98 802419E8 46241083 */  div.d     $f2, $f2, $f4
/* EE7F9C 802419EC 0C00F909 */  jal       func_8003E424
/* EE7FA0 802419F0 462015A0 */   cvt.s.d  $f22, $f2
/* EE7FA4 802419F4 C604001C */  lwc1      $f4, 0x1c($s0)
/* EE7FA8 802419F8 44801000 */  mtc1      $zero, $f2
/* EE7FAC 802419FC 44801800 */  mtc1      $zero, $f3
/* EE7FB0 80241A00 46002021 */  cvt.d.s   $f0, $f4
/* EE7FB4 80241A04 4620103E */  c.le.d    $f2, $f0
/* EE7FB8 80241A08 00000000 */  nop
/* EE7FBC 80241A0C 45000030 */  bc1f      .L80241AD0
/* EE7FC0 80241A10 00000000 */   nop
/* EE7FC4 80241A14 C600003C */  lwc1      $f0, 0x3c($s0)
/* EE7FC8 80241A18 46040000 */  add.s     $f0, $f0, $f4
/* EE7FCC 80241A1C E600003C */  swc1      $f0, 0x3c($s0)
/* EE7FD0 80241A20 8E2200CC */  lw        $v0, 0xcc($s1)
/* EE7FD4 80241A24 8C420024 */  lw        $v0, 0x24($v0)
/* EE7FD8 80241A28 AE020028 */  sw        $v0, 0x28($s0)
/* EE7FDC 80241A2C A2200007 */  sb        $zero, 7($s1)
/* EE7FE0 80241A30 8E020000 */  lw        $v0, ($s0)
/* EE7FE4 80241A34 30420008 */  andi      $v0, $v0, 8
/* EE7FE8 80241A38 14400011 */  bnez      $v0, .L80241A80
/* EE7FEC 80241A3C 0000102D */   daddu    $v0, $zero, $zero
/* EE7FF0 80241A40 27A50018 */  addiu     $a1, $sp, 0x18
/* EE7FF4 80241A44 27A6001C */  addiu     $a2, $sp, 0x1c
/* EE7FF8 80241A48 C6000038 */  lwc1      $f0, 0x38($s0)
/* EE7FFC 80241A4C C602003C */  lwc1      $f2, 0x3c($s0)
/* EE8000 80241A50 C6040040 */  lwc1      $f4, 0x40($s0)
/* EE8004 80241A54 3C01447A */  lui       $at, 0x447a
/* EE8008 80241A58 44813000 */  mtc1      $at, $f6
/* EE800C 80241A5C 27A20024 */  addiu     $v0, $sp, 0x24
/* EE8010 80241A60 E7A00018 */  swc1      $f0, 0x18($sp)
/* EE8014 80241A64 E7A2001C */  swc1      $f2, 0x1c($sp)
/* EE8018 80241A68 E7A40020 */  swc1      $f4, 0x20($sp)
/* EE801C 80241A6C E7A60024 */  swc1      $f6, 0x24($sp)
/* EE8020 80241A70 AFA20010 */  sw        $v0, 0x10($sp)
/* EE8024 80241A74 8E040080 */  lw        $a0, 0x80($s0)
/* EE8028 80241A78 0C03908F */  jal       func_800E423C
/* EE802C 80241A7C 27A70020 */   addiu    $a3, $sp, 0x20
.L80241A80:
/* EE8030 80241A80 1040000B */  beqz      $v0, .L80241AB0
/* EE8034 80241A84 00000000 */   nop
/* EE8038 80241A88 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* EE803C 80241A8C 46140080 */  add.s     $f2, $f0, $f20
/* EE8040 80241A90 C600003C */  lwc1      $f0, 0x3c($s0)
/* EE8044 80241A94 4600103E */  c.le.s    $f2, $f0
/* EE8048 80241A98 00000000 */  nop
/* EE804C 80241A9C 4500008D */  bc1f      .L80241CD4
/* EE8050 80241AA0 00000000 */   nop
/* EE8054 80241AA4 E602003C */  swc1      $f2, 0x3c($s0)
/* EE8058 80241AA8 08090735 */  j         .L80241CD4
/* EE805C 80241AAC AE400070 */   sw       $zero, 0x70($s2)
.L80241AB0:
/* EE8060 80241AB0 C602003C */  lwc1      $f2, 0x3c($s0)
/* EE8064 80241AB4 C6000064 */  lwc1      $f0, 0x64($s0)
/* EE8068 80241AB8 4602003E */  c.le.s    $f0, $f2
/* EE806C 80241ABC 00000000 */  nop
/* EE8070 80241AC0 45030084 */  bc1tl     .L80241CD4
/* EE8074 80241AC4 AE400070 */   sw       $zero, 0x70($s2)
/* EE8078 80241AC8 08090735 */  j         .L80241CD4
/* EE807C 80241ACC 00000000 */   nop
.L80241AD0:
/* EE8080 80241AD0 4622003C */  c.lt.d    $f0, $f2
/* EE8084 80241AD4 00000000 */  nop
/* EE8088 80241AD8 4500007E */  bc1f      .L80241CD4
/* EE808C 80241ADC 00000000 */   nop
/* EE8090 80241AE0 9602008E */  lhu       $v0, 0x8e($s0)
/* EE8094 80241AE4 24420001 */  addiu     $v0, $v0, 1
/* EE8098 80241AE8 A602008E */  sh        $v0, 0x8e($s0)
/* EE809C 80241AEC 00021400 */  sll       $v0, $v0, 0x10
/* EE80A0 80241AF0 8E630020 */  lw        $v1, 0x20($s3)
/* EE80A4 80241AF4 00021403 */  sra       $v0, $v0, 0x10
/* EE80A8 80241AF8 0043102A */  slt       $v0, $v0, $v1
/* EE80AC 80241AFC 14400026 */  bnez      $v0, .L80241B98
/* EE80B0 80241B00 00000000 */   nop
/* EE80B4 80241B04 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EE80B8 80241B08 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EE80BC 80241B0C 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EE80C0 80241B10 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EE80C4 80241B14 A600008E */  sh        $zero, 0x8e($s0)
/* EE80C8 80241B18 8C460028 */  lw        $a2, 0x28($v0)
/* EE80CC 80241B1C 0C00ABDC */  jal       fio_validate_header_checksums
/* EE80D0 80241B20 8C470030 */   lw       $a3, 0x30($v0)
/* EE80D4 80241B24 46000506 */  mov.s     $f20, $f0
/* EE80D8 80241B28 C60C000C */  lwc1      $f12, 0xc($s0)
/* EE80DC 80241B2C 0C00ABC6 */  jal       func_8002AF18
/* EE80E0 80241B30 4600A386 */   mov.s    $f14, $f20
/* EE80E4 80241B34 46000086 */  mov.s     $f2, $f0
/* EE80E8 80241B38 8E62001C */  lw        $v0, 0x1c($s3)
/* EE80EC 80241B3C 46001005 */  abs.s     $f0, $f2
/* EE80F0 80241B40 44822000 */  mtc1      $v0, $f4
/* EE80F4 80241B44 00000000 */  nop
/* EE80F8 80241B48 46802120 */  cvt.s.w   $f4, $f4
/* EE80FC 80241B4C 4600203C */  c.lt.s    $f4, $f0
/* EE8100 80241B50 00000000 */  nop
/* EE8104 80241B54 4500000D */  bc1f      .L80241B8C
/* EE8108 80241B58 00000000 */   nop
/* EE810C 80241B5C 44800000 */  mtc1      $zero, $f0
/* EE8110 80241B60 C614000C */  lwc1      $f20, 0xc($s0)
/* EE8114 80241B64 4600103C */  c.lt.s    $f2, $f0
/* EE8118 80241B68 00000000 */  nop
/* EE811C 80241B6C 45000006 */  bc1f      .L80241B88
/* EE8120 80241B70 00021023 */   negu     $v0, $v0
/* EE8124 80241B74 44820000 */  mtc1      $v0, $f0
/* EE8128 80241B78 00000000 */  nop
/* EE812C 80241B7C 46800020 */  cvt.s.w   $f0, $f0
/* EE8130 80241B80 080906E3 */  j         .L80241B8C
/* EE8134 80241B84 4600A500 */   add.s    $f20, $f20, $f0
.L80241B88:
/* EE8138 80241B88 4604A500 */  add.s     $f20, $f20, $f4
.L80241B8C:
/* EE813C 80241B8C 0C00AB85 */  jal       func_8002AE14
/* EE8140 80241B90 4600A306 */   mov.s    $f12, $f20
/* EE8144 80241B94 E600000C */  swc1      $f0, 0xc($s0)
.L80241B98:
/* EE8148 80241B98 8E020000 */  lw        $v0, ($s0)
/* EE814C 80241B9C 30420008 */  andi      $v0, $v0, 8
/* EE8150 80241BA0 1040000A */  beqz      $v0, .L80241BCC
/* EE8154 80241BA4 27A50018 */   addiu    $a1, $sp, 0x18
/* EE8158 80241BA8 C602003C */  lwc1      $f2, 0x3c($s0)
/* EE815C 80241BAC C600001C */  lwc1      $f0, 0x1c($s0)
/* EE8160 80241BB0 46001080 */  add.s     $f2, $f2, $f0
/* EE8164 80241BB4 4616103C */  c.lt.s    $f2, $f22
/* EE8168 80241BB8 00000000 */  nop
/* EE816C 80241BBC 45020045 */  bc1fl     .L80241CD4
/* EE8170 80241BC0 E602003C */   swc1     $f2, 0x3c($s0)
/* EE8174 80241BC4 08090734 */  j         .L80241CD0
/* EE8178 80241BC8 E616003C */   swc1     $f22, 0x3c($s0)
.L80241BCC:
/* EE817C 80241BCC C6000038 */  lwc1      $f0, 0x38($s0)
/* EE8180 80241BD0 27A6001C */  addiu     $a2, $sp, 0x1c
/* EE8184 80241BD4 E7A00018 */  swc1      $f0, 0x18($sp)
/* EE8188 80241BD8 860200A8 */  lh        $v0, 0xa8($s0)
/* EE818C 80241BDC C600001C */  lwc1      $f0, 0x1c($s0)
/* EE8190 80241BE0 C604003C */  lwc1      $f4, 0x3c($s0)
/* EE8194 80241BE4 44821000 */  mtc1      $v0, $f2
/* EE8198 80241BE8 00000000 */  nop
/* EE819C 80241BEC 468010A0 */  cvt.s.w   $f2, $f2
/* EE81A0 80241BF0 46000005 */  abs.s     $f0, $f0
/* EE81A4 80241BF4 46020000 */  add.s     $f0, $f0, $f2
/* EE81A8 80241BF8 C6060040 */  lwc1      $f6, 0x40($s0)
/* EE81AC 80241BFC 27A20024 */  addiu     $v0, $sp, 0x24
/* EE81B0 80241C00 46022100 */  add.s     $f4, $f4, $f2
/* EE81B4 80241C04 3C014024 */  lui       $at, 0x4024
/* EE81B8 80241C08 44811800 */  mtc1      $at, $f3
/* EE81BC 80241C0C 44801000 */  mtc1      $zero, $f2
/* EE81C0 80241C10 46000021 */  cvt.d.s   $f0, $f0
/* EE81C4 80241C14 46220000 */  add.d     $f0, $f0, $f2
/* EE81C8 80241C18 E7A60020 */  swc1      $f6, 0x20($sp)
/* EE81CC 80241C1C E7A4001C */  swc1      $f4, 0x1c($sp)
/* EE81D0 80241C20 46200020 */  cvt.s.d   $f0, $f0
/* EE81D4 80241C24 E7A00024 */  swc1      $f0, 0x24($sp)
/* EE81D8 80241C28 AFA20010 */  sw        $v0, 0x10($sp)
/* EE81DC 80241C2C 8E040080 */  lw        $a0, 0x80($s0)
/* EE81E0 80241C30 0C03908F */  jal       func_800E423C
/* EE81E4 80241C34 27A70020 */   addiu    $a3, $sp, 0x20
/* EE81E8 80241C38 10400015 */  beqz      $v0, .L80241C90
/* EE81EC 80241C3C 00000000 */   nop
/* EE81F0 80241C40 860200A8 */  lh        $v0, 0xa8($s0)
/* EE81F4 80241C44 C604001C */  lwc1      $f4, 0x1c($s0)
/* EE81F8 80241C48 44820000 */  mtc1      $v0, $f0
/* EE81FC 80241C4C 00000000 */  nop
/* EE8200 80241C50 46800020 */  cvt.s.w   $f0, $f0
/* EE8204 80241C54 46002085 */  abs.s     $f2, $f4
/* EE8208 80241C58 46020000 */  add.s     $f0, $f0, $f2
/* EE820C 80241C5C C7A20024 */  lwc1      $f2, 0x24($sp)
/* EE8210 80241C60 4600103E */  c.le.s    $f2, $f0
/* EE8214 80241C64 00000000 */  nop
/* EE8218 80241C68 45000005 */  bc1f      .L80241C80
/* EE821C 80241C6C 00000000 */   nop
/* EE8220 80241C70 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* EE8224 80241C74 AE00001C */  sw        $zero, 0x1c($s0)
/* EE8228 80241C78 08090735 */  j         .L80241CD4
/* EE822C 80241C7C E600003C */   swc1     $f0, 0x3c($s0)
.L80241C80:
/* EE8230 80241C80 C600003C */  lwc1      $f0, 0x3c($s0)
/* EE8234 80241C84 46040000 */  add.s     $f0, $f0, $f4
/* EE8238 80241C88 08090735 */  j         .L80241CD4
/* EE823C 80241C8C E600003C */   swc1     $f0, 0x3c($s0)
.L80241C90:
/* EE8240 80241C90 C606003C */  lwc1      $f6, 0x3c($s0)
/* EE8244 80241C94 860200A8 */  lh        $v0, 0xa8($s0)
/* EE8248 80241C98 46163081 */  sub.s     $f2, $f6, $f22
/* EE824C 80241C9C 44820000 */  mtc1      $v0, $f0
/* EE8250 80241CA0 00000000 */  nop
/* EE8254 80241CA4 46800020 */  cvt.s.w   $f0, $f0
/* EE8258 80241CA8 46001080 */  add.s     $f2, $f2, $f0
/* EE825C 80241CAC C604001C */  lwc1      $f4, 0x1c($s0)
/* EE8260 80241CB0 46002005 */  abs.s     $f0, $f4
/* EE8264 80241CB4 4602003C */  c.lt.s    $f0, $f2
/* EE8268 80241CB8 00000000 */  nop
/* EE826C 80241CBC 45020005 */  bc1fl     .L80241CD4
/* EE8270 80241CC0 AE00001C */   sw       $zero, 0x1c($s0)
/* EE8274 80241CC4 46043000 */  add.s     $f0, $f6, $f4
/* EE8278 80241CC8 08090735 */  j         .L80241CD4
/* EE827C 80241CCC E600003C */   swc1     $f0, 0x3c($s0)
.L80241CD0:
/* EE8280 80241CD0 AE00001C */  sw        $zero, 0x1c($s0)
.L80241CD4:
/* EE8284 80241CD4 8FBF0038 */  lw        $ra, 0x38($sp)
/* EE8288 80241CD8 8FB30034 */  lw        $s3, 0x34($sp)
/* EE828C 80241CDC 8FB20030 */  lw        $s2, 0x30($sp)
/* EE8290 80241CE0 8FB1002C */  lw        $s1, 0x2c($sp)
/* EE8294 80241CE4 8FB00028 */  lw        $s0, 0x28($sp)
/* EE8298 80241CE8 D7B60048 */  ldc1      $f22, 0x48($sp)
/* EE829C 80241CEC D7B40040 */  ldc1      $f20, 0x40($sp)
/* EE82A0 80241CF0 03E00008 */  jr        $ra
/* EE82A4 80241CF4 27BD0050 */   addiu    $sp, $sp, 0x50

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024190C_A0880C
/* A0880C 8024190C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A08810 80241910 AFB20030 */  sw        $s2, 0x30($sp)
/* A08814 80241914 0080902D */  daddu     $s2, $a0, $zero
/* A08818 80241918 AFBF0038 */  sw        $ra, 0x38($sp)
/* A0881C 8024191C AFB30034 */  sw        $s3, 0x34($sp)
/* A08820 80241920 AFB1002C */  sw        $s1, 0x2c($sp)
/* A08824 80241924 AFB00028 */  sw        $s0, 0x28($sp)
/* A08828 80241928 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A0882C 8024192C F7B40040 */  sdc1      $f20, 0x40($sp)
/* A08830 80241930 8E510148 */  lw        $s1, 0x148($s2)
/* A08834 80241934 86240008 */  lh        $a0, 8($s1)
/* A08838 80241938 0C00EABB */  jal       get_npc_unsafe
/* A0883C 8024193C 00A0982D */   daddu    $s3, $a1, $zero
/* A08840 80241940 0040802D */  daddu     $s0, $v0, $zero
/* A08844 80241944 0200202D */  daddu     $a0, $s0, $zero
/* A08848 80241948 C6220088 */  lwc1      $f2, 0x88($s1)
/* A0884C 8024194C 468010A0 */  cvt.s.w   $f2, $f2
/* A08850 80241950 460010A1 */  cvt.d.s   $f2, $f2
/* A08854 80241954 C604001C */  lwc1      $f4, 0x1c($s0)
/* A08858 80241958 C6000014 */  lwc1      $f0, 0x14($s0)
/* A0885C 8024195C 8E050018 */  lw        $a1, 0x18($s0)
/* A08860 80241960 46002100 */  add.s     $f4, $f4, $f0
/* A08864 80241964 8E06000C */  lw        $a2, 0xc($s0)
/* A08868 80241968 C6200078 */  lwc1      $f0, 0x78($s1)
/* A0886C 8024196C 46800020 */  cvt.s.w   $f0, $f0
/* A08870 80241970 E604001C */  swc1      $f4, 0x1c($s0)
/* A08874 80241974 3C014059 */  lui       $at, 0x4059
/* A08878 80241978 44812800 */  mtc1      $at, $f5
/* A0887C 8024197C 44802000 */  mtc1      $zero, $f4
/* A08880 80241980 46000021 */  cvt.d.s   $f0, $f0
/* A08884 80241984 46240003 */  div.d     $f0, $f0, $f4
/* A08888 80241988 46200520 */  cvt.s.d   $f20, $f0
/* A0888C 8024198C 46241083 */  div.d     $f2, $f2, $f4
/* A08890 80241990 0C00EA95 */  jal       npc_move_heading
/* A08894 80241994 462015A0 */   cvt.s.d  $f22, $f2
/* A08898 80241998 C604001C */  lwc1      $f4, 0x1c($s0)
/* A0889C 8024199C 44801000 */  mtc1      $zero, $f2
/* A088A0 802419A0 44801800 */  mtc1      $zero, $f3
/* A088A4 802419A4 46002021 */  cvt.d.s   $f0, $f4
/* A088A8 802419A8 4620103E */  c.le.d    $f2, $f0
/* A088AC 802419AC 00000000 */  nop       
/* A088B0 802419B0 45000030 */  bc1f      .L80241A74
/* A088B4 802419B4 00000000 */   nop      
/* A088B8 802419B8 C600003C */  lwc1      $f0, 0x3c($s0)
/* A088BC 802419BC 46040000 */  add.s     $f0, $f0, $f4
/* A088C0 802419C0 E600003C */  swc1      $f0, 0x3c($s0)
/* A088C4 802419C4 8E2200CC */  lw        $v0, 0xcc($s1)
/* A088C8 802419C8 8C420024 */  lw        $v0, 0x24($v0)
/* A088CC 802419CC AE020028 */  sw        $v0, 0x28($s0)
/* A088D0 802419D0 A2200007 */  sb        $zero, 7($s1)
/* A088D4 802419D4 8E020000 */  lw        $v0, ($s0)
/* A088D8 802419D8 30420008 */  andi      $v0, $v0, 8
/* A088DC 802419DC 14400011 */  bnez      $v0, .L80241A24
/* A088E0 802419E0 0000102D */   daddu    $v0, $zero, $zero
/* A088E4 802419E4 27A50018 */  addiu     $a1, $sp, 0x18
/* A088E8 802419E8 27A6001C */  addiu     $a2, $sp, 0x1c
/* A088EC 802419EC C6000038 */  lwc1      $f0, 0x38($s0)
/* A088F0 802419F0 C602003C */  lwc1      $f2, 0x3c($s0)
/* A088F4 802419F4 C6040040 */  lwc1      $f4, 0x40($s0)
/* A088F8 802419F8 3C01447A */  lui       $at, 0x447a
/* A088FC 802419FC 44813000 */  mtc1      $at, $f6
/* A08900 80241A00 27A20024 */  addiu     $v0, $sp, 0x24
/* A08904 80241A04 E7A00018 */  swc1      $f0, 0x18($sp)
/* A08908 80241A08 E7A2001C */  swc1      $f2, 0x1c($sp)
/* A0890C 80241A0C E7A40020 */  swc1      $f4, 0x20($sp)
/* A08910 80241A10 E7A60024 */  swc1      $f6, 0x24($sp)
/* A08914 80241A14 AFA20010 */  sw        $v0, 0x10($sp)
/* A08918 80241A18 8E040080 */  lw        $a0, 0x80($s0)
/* A0891C 80241A1C 0C0372DF */  jal       func_800DCB7C
/* A08920 80241A20 27A70020 */   addiu    $a3, $sp, 0x20
.L80241A24:
/* A08924 80241A24 1040000B */  beqz      $v0, .L80241A54
/* A08928 80241A28 00000000 */   nop      
/* A0892C 80241A2C C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A08930 80241A30 46140080 */  add.s     $f2, $f0, $f20
/* A08934 80241A34 C600003C */  lwc1      $f0, 0x3c($s0)
/* A08938 80241A38 4600103E */  c.le.s    $f2, $f0
/* A0893C 80241A3C 00000000 */  nop       
/* A08940 80241A40 4500008D */  bc1f      .L80241C78
/* A08944 80241A44 00000000 */   nop      
/* A08948 80241A48 E602003C */  swc1      $f2, 0x3c($s0)
/* A0894C 80241A4C 0809071E */  j         .L80241C78
/* A08950 80241A50 AE400070 */   sw       $zero, 0x70($s2)
.L80241A54:
/* A08954 80241A54 C602003C */  lwc1      $f2, 0x3c($s0)
/* A08958 80241A58 C6000064 */  lwc1      $f0, 0x64($s0)
/* A0895C 80241A5C 4602003E */  c.le.s    $f0, $f2
/* A08960 80241A60 00000000 */  nop       
/* A08964 80241A64 45030084 */  bc1tl     .L80241C78
/* A08968 80241A68 AE400070 */   sw       $zero, 0x70($s2)
/* A0896C 80241A6C 0809071E */  j         .L80241C78
/* A08970 80241A70 00000000 */   nop      
.L80241A74:
/* A08974 80241A74 4622003C */  c.lt.d    $f0, $f2
/* A08978 80241A78 00000000 */  nop       
/* A0897C 80241A7C 4500007E */  bc1f      .L80241C78
/* A08980 80241A80 00000000 */   nop      
/* A08984 80241A84 9602008E */  lhu       $v0, 0x8e($s0)
/* A08988 80241A88 24420001 */  addiu     $v0, $v0, 1
/* A0898C 80241A8C A602008E */  sh        $v0, 0x8e($s0)
/* A08990 80241A90 00021400 */  sll       $v0, $v0, 0x10
/* A08994 80241A94 8E630020 */  lw        $v1, 0x20($s3)
/* A08998 80241A98 00021403 */  sra       $v0, $v0, 0x10
/* A0899C 80241A9C 0043102A */  slt       $v0, $v0, $v1
/* A089A0 80241AA0 14400026 */  bnez      $v0, .L80241B3C
/* A089A4 80241AA4 00000000 */   nop      
/* A089A8 80241AA8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A089AC 80241AAC C60E0040 */  lwc1      $f14, 0x40($s0)
/* A089B0 80241AB0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A089B4 80241AB4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A089B8 80241AB8 A600008E */  sh        $zero, 0x8e($s0)
/* A089BC 80241ABC 8C460028 */  lw        $a2, 0x28($v0)
/* A089C0 80241AC0 0C00A720 */  jal       atan2
/* A089C4 80241AC4 8C470030 */   lw       $a3, 0x30($v0)
/* A089C8 80241AC8 46000506 */  mov.s     $f20, $f0
/* A089CC 80241ACC C60C000C */  lwc1      $f12, 0xc($s0)
/* A089D0 80241AD0 0C00A70A */  jal       get_clamped_angle_diff
/* A089D4 80241AD4 4600A386 */   mov.s    $f14, $f20
/* A089D8 80241AD8 46000086 */  mov.s     $f2, $f0
/* A089DC 80241ADC 8E62001C */  lw        $v0, 0x1c($s3)
/* A089E0 80241AE0 46001005 */  abs.s     $f0, $f2
/* A089E4 80241AE4 44822000 */  mtc1      $v0, $f4
/* A089E8 80241AE8 00000000 */  nop       
/* A089EC 80241AEC 46802120 */  cvt.s.w   $f4, $f4
/* A089F0 80241AF0 4600203C */  c.lt.s    $f4, $f0
/* A089F4 80241AF4 00000000 */  nop       
/* A089F8 80241AF8 4500000D */  bc1f      .L80241B30
/* A089FC 80241AFC 00000000 */   nop      
/* A08A00 80241B00 44800000 */  mtc1      $zero, $f0
/* A08A04 80241B04 C614000C */  lwc1      $f20, 0xc($s0)
/* A08A08 80241B08 4600103C */  c.lt.s    $f2, $f0
/* A08A0C 80241B0C 00000000 */  nop       
/* A08A10 80241B10 45000006 */  bc1f      .L80241B2C
/* A08A14 80241B14 00021023 */   negu     $v0, $v0
/* A08A18 80241B18 44820000 */  mtc1      $v0, $f0
/* A08A1C 80241B1C 00000000 */  nop       
/* A08A20 80241B20 46800020 */  cvt.s.w   $f0, $f0
/* A08A24 80241B24 080906CC */  j         .L80241B30
/* A08A28 80241B28 4600A500 */   add.s    $f20, $f20, $f0
.L80241B2C:
/* A08A2C 80241B2C 4604A500 */  add.s     $f20, $f20, $f4
.L80241B30:
/* A08A30 80241B30 0C00A6C9 */  jal       clamp_angle
/* A08A34 80241B34 4600A306 */   mov.s    $f12, $f20
/* A08A38 80241B38 E600000C */  swc1      $f0, 0xc($s0)
.L80241B3C:
/* A08A3C 80241B3C 8E020000 */  lw        $v0, ($s0)
/* A08A40 80241B40 30420008 */  andi      $v0, $v0, 8
/* A08A44 80241B44 1040000A */  beqz      $v0, .L80241B70
/* A08A48 80241B48 27A50018 */   addiu    $a1, $sp, 0x18
/* A08A4C 80241B4C C602003C */  lwc1      $f2, 0x3c($s0)
/* A08A50 80241B50 C600001C */  lwc1      $f0, 0x1c($s0)
/* A08A54 80241B54 46001080 */  add.s     $f2, $f2, $f0
/* A08A58 80241B58 4616103C */  c.lt.s    $f2, $f22
/* A08A5C 80241B5C 00000000 */  nop       
/* A08A60 80241B60 45020045 */  bc1fl     .L80241C78
/* A08A64 80241B64 E602003C */   swc1     $f2, 0x3c($s0)
/* A08A68 80241B68 0809071D */  j         .L80241C74
/* A08A6C 80241B6C E616003C */   swc1     $f22, 0x3c($s0)
.L80241B70:
/* A08A70 80241B70 C6000038 */  lwc1      $f0, 0x38($s0)
/* A08A74 80241B74 27A6001C */  addiu     $a2, $sp, 0x1c
/* A08A78 80241B78 E7A00018 */  swc1      $f0, 0x18($sp)
/* A08A7C 80241B7C 860200A8 */  lh        $v0, 0xa8($s0)
/* A08A80 80241B80 C600001C */  lwc1      $f0, 0x1c($s0)
/* A08A84 80241B84 C604003C */  lwc1      $f4, 0x3c($s0)
/* A08A88 80241B88 44821000 */  mtc1      $v0, $f2
/* A08A8C 80241B8C 00000000 */  nop       
/* A08A90 80241B90 468010A0 */  cvt.s.w   $f2, $f2
/* A08A94 80241B94 46000005 */  abs.s     $f0, $f0
/* A08A98 80241B98 46020000 */  add.s     $f0, $f0, $f2
/* A08A9C 80241B9C C6060040 */  lwc1      $f6, 0x40($s0)
/* A08AA0 80241BA0 27A20024 */  addiu     $v0, $sp, 0x24
/* A08AA4 80241BA4 46022100 */  add.s     $f4, $f4, $f2
/* A08AA8 80241BA8 3C014024 */  lui       $at, 0x4024
/* A08AAC 80241BAC 44811800 */  mtc1      $at, $f3
/* A08AB0 80241BB0 44801000 */  mtc1      $zero, $f2
/* A08AB4 80241BB4 46000021 */  cvt.d.s   $f0, $f0
/* A08AB8 80241BB8 46220000 */  add.d     $f0, $f0, $f2
/* A08ABC 80241BBC E7A60020 */  swc1      $f6, 0x20($sp)
/* A08AC0 80241BC0 E7A4001C */  swc1      $f4, 0x1c($sp)
/* A08AC4 80241BC4 46200020 */  cvt.s.d   $f0, $f0
/* A08AC8 80241BC8 E7A00024 */  swc1      $f0, 0x24($sp)
/* A08ACC 80241BCC AFA20010 */  sw        $v0, 0x10($sp)
/* A08AD0 80241BD0 8E040080 */  lw        $a0, 0x80($s0)
/* A08AD4 80241BD4 0C0372DF */  jal       func_800DCB7C
/* A08AD8 80241BD8 27A70020 */   addiu    $a3, $sp, 0x20
/* A08ADC 80241BDC 10400015 */  beqz      $v0, .L80241C34
/* A08AE0 80241BE0 00000000 */   nop      
/* A08AE4 80241BE4 860200A8 */  lh        $v0, 0xa8($s0)
/* A08AE8 80241BE8 C604001C */  lwc1      $f4, 0x1c($s0)
/* A08AEC 80241BEC 44820000 */  mtc1      $v0, $f0
/* A08AF0 80241BF0 00000000 */  nop       
/* A08AF4 80241BF4 46800020 */  cvt.s.w   $f0, $f0
/* A08AF8 80241BF8 46002085 */  abs.s     $f2, $f4
/* A08AFC 80241BFC 46020000 */  add.s     $f0, $f0, $f2
/* A08B00 80241C00 C7A20024 */  lwc1      $f2, 0x24($sp)
/* A08B04 80241C04 4600103E */  c.le.s    $f2, $f0
/* A08B08 80241C08 00000000 */  nop       
/* A08B0C 80241C0C 45000005 */  bc1f      .L80241C24
/* A08B10 80241C10 00000000 */   nop      
/* A08B14 80241C14 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A08B18 80241C18 AE00001C */  sw        $zero, 0x1c($s0)
/* A08B1C 80241C1C 0809071E */  j         .L80241C78
/* A08B20 80241C20 E600003C */   swc1     $f0, 0x3c($s0)
.L80241C24:
/* A08B24 80241C24 C600003C */  lwc1      $f0, 0x3c($s0)
/* A08B28 80241C28 46040000 */  add.s     $f0, $f0, $f4
/* A08B2C 80241C2C 0809071E */  j         .L80241C78
/* A08B30 80241C30 E600003C */   swc1     $f0, 0x3c($s0)
.L80241C34:
/* A08B34 80241C34 C606003C */  lwc1      $f6, 0x3c($s0)
/* A08B38 80241C38 860200A8 */  lh        $v0, 0xa8($s0)
/* A08B3C 80241C3C 46163081 */  sub.s     $f2, $f6, $f22
/* A08B40 80241C40 44820000 */  mtc1      $v0, $f0
/* A08B44 80241C44 00000000 */  nop       
/* A08B48 80241C48 46800020 */  cvt.s.w   $f0, $f0
/* A08B4C 80241C4C 46001080 */  add.s     $f2, $f2, $f0
/* A08B50 80241C50 C604001C */  lwc1      $f4, 0x1c($s0)
/* A08B54 80241C54 46002005 */  abs.s     $f0, $f4
/* A08B58 80241C58 4602003C */  c.lt.s    $f0, $f2
/* A08B5C 80241C5C 00000000 */  nop       
/* A08B60 80241C60 45020005 */  bc1fl     .L80241C78
/* A08B64 80241C64 AE00001C */   sw       $zero, 0x1c($s0)
/* A08B68 80241C68 46043000 */  add.s     $f0, $f6, $f4
/* A08B6C 80241C6C 0809071E */  j         .L80241C78
/* A08B70 80241C70 E600003C */   swc1     $f0, 0x3c($s0)
.L80241C74:
/* A08B74 80241C74 AE00001C */  sw        $zero, 0x1c($s0)
.L80241C78:
/* A08B78 80241C78 8FBF0038 */  lw        $ra, 0x38($sp)
/* A08B7C 80241C7C 8FB30034 */  lw        $s3, 0x34($sp)
/* A08B80 80241C80 8FB20030 */  lw        $s2, 0x30($sp)
/* A08B84 80241C84 8FB1002C */  lw        $s1, 0x2c($sp)
/* A08B88 80241C88 8FB00028 */  lw        $s0, 0x28($sp)
/* A08B8C 80241C8C D7B60048 */  ldc1      $f22, 0x48($sp)
/* A08B90 80241C90 D7B40040 */  ldc1      $f20, 0x40($sp)
/* A08B94 80241C94 03E00008 */  jr        $ra
/* A08B98 80241C98 27BD0050 */   addiu    $sp, $sp, 0x50

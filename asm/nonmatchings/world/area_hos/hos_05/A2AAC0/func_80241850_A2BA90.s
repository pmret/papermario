.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241850_A2BA90
/* A2BA90 80241850 27BDFF80 */  addiu     $sp, $sp, -0x80
/* A2BA94 80241854 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* A2BA98 80241858 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* A2BA9C 8024185C 3C04800B */  lui       $a0, %hi(gCameras)
/* A2BAA0 80241860 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* A2BAA4 80241864 AFBF0064 */  sw        $ra, 0x64($sp)
/* A2BAA8 80241868 AFB20060 */  sw        $s2, 0x60($sp)
/* A2BAAC 8024186C AFB1005C */  sw        $s1, 0x5c($sp)
/* A2BAB0 80241870 AFB00058 */  sw        $s0, 0x58($sp)
/* A2BAB4 80241874 F7B80078 */  sdc1      $f24, 0x78($sp)
/* A2BAB8 80241878 F7B60070 */  sdc1      $f22, 0x70($sp)
/* A2BABC 8024187C F7B40068 */  sdc1      $f20, 0x68($sp)
/* A2BAC0 80241880 00031080 */  sll       $v0, $v1, 2
/* A2BAC4 80241884 00431021 */  addu      $v0, $v0, $v1
/* A2BAC8 80241888 00021080 */  sll       $v0, $v0, 2
/* A2BACC 8024188C 00431023 */  subu      $v0, $v0, $v1
/* A2BAD0 80241890 000218C0 */  sll       $v1, $v0, 3
/* A2BAD4 80241894 00431021 */  addu      $v0, $v0, $v1
/* A2BAD8 80241898 000210C0 */  sll       $v0, $v0, 3
/* A2BADC 8024189C 10A00004 */  beqz      $a1, .L802418B0
/* A2BAE0 802418A0 00448821 */   addu     $s1, $v0, $a0
/* A2BAE4 802418A4 96220000 */  lhu       $v0, ($s1)
/* A2BAE8 802418A8 34420008 */  ori       $v0, $v0, 8
/* A2BAEC 802418AC A6220000 */  sh        $v0, ($s1)
.L802418B0:
/* A2BAF0 802418B0 3C128025 */  lui       $s2, 0x8025
/* A2BAF4 802418B4 26529908 */  addiu     $s2, $s2, -0x66f8
/* A2BAF8 802418B8 8E430000 */  lw        $v1, ($s2)
/* A2BAFC 802418BC 00031100 */  sll       $v0, $v1, 4
/* A2BB00 802418C0 00431023 */  subu      $v0, $v0, $v1
/* A2BB04 802418C4 00021080 */  sll       $v0, $v0, 2
/* A2BB08 802418C8 00431021 */  addu      $v0, $v0, $v1
/* A2BB0C 802418CC 00021080 */  sll       $v0, $v0, 2
/* A2BB10 802418D0 00431023 */  subu      $v0, $v0, $v1
/* A2BB14 802418D4 00021040 */  sll       $v0, $v0, 1
/* A2BB18 802418D8 44826000 */  mtc1      $v0, $f12
/* A2BB1C 802418DC 00000000 */  nop       
/* A2BB20 802418E0 0C00A8BB */  jal       sin_deg
/* A2BB24 802418E4 46806320 */   cvt.s.w  $f12, $f12
/* A2BB28 802418E8 3C108025 */  lui       $s0, 0x8025
/* A2BB2C 802418EC 2610990C */  addiu     $s0, $s0, -0x66f4
/* A2BB30 802418F0 8E430000 */  lw        $v1, ($s2)
/* A2BB34 802418F4 C6160000 */  lwc1      $f22, ($s0)
/* A2BB38 802418F8 000311C0 */  sll       $v0, $v1, 7
/* A2BB3C 802418FC 00431023 */  subu      $v0, $v0, $v1
/* A2BB40 80241900 00021040 */  sll       $v0, $v0, 1
/* A2BB44 80241904 4600B582 */  mul.s     $f22, $f22, $f0
/* A2BB48 80241908 00000000 */  nop       
/* A2BB4C 8024190C 44826000 */  mtc1      $v0, $f12
/* A2BB50 80241910 00000000 */  nop       
/* A2BB54 80241914 0C00A8D4 */  jal       cos_deg
/* A2BB58 80241918 46806320 */   cvt.s.w  $f12, $f12
/* A2BB5C 8024191C C6140000 */  lwc1      $f20, ($s0)
/* A2BB60 80241920 4600A502 */  mul.s     $f20, $f20, $f0
/* A2BB64 80241924 00000000 */  nop       
/* A2BB68 80241928 4480C000 */  mtc1      $zero, $f24
/* A2BB6C 8024192C 26300194 */  addiu     $s0, $s1, 0x194
/* A2BB70 80241930 4407C000 */  mfc1      $a3, $f24
/* A2BB74 80241934 4405B000 */  mfc1      $a1, $f22
/* A2BB78 80241938 4406A000 */  mfc1      $a2, $f20
/* A2BB7C 8024193C 0C019E40 */  jal       guTranslateF
/* A2BB80 80241940 0200202D */   daddu    $a0, $s0, $zero
/* A2BB84 80241944 4405B000 */  mfc1      $a1, $f22
/* A2BB88 80241948 4406A000 */  mfc1      $a2, $f20
/* A2BB8C 8024194C 4407C000 */  mfc1      $a3, $f24
/* A2BB90 80241950 3C0141A0 */  lui       $at, 0x41a0
/* A2BB94 80241954 4481B000 */  mtc1      $at, $f22
/* A2BB98 80241958 0C019E40 */  jal       guTranslateF
/* A2BB9C 8024195C 0200202D */   daddu    $a0, $s0, $zero
/* A2BBA0 80241960 4405B000 */  mfc1      $a1, $f22
/* A2BBA4 80241964 4406C000 */  mfc1      $a2, $f24
/* A2BBA8 80241968 4407C000 */  mfc1      $a3, $f24
/* A2BBAC 8024196C 3C013F80 */  lui       $at, 0x3f80
/* A2BBB0 80241970 4481A000 */  mtc1      $at, $f20
/* A2BBB4 80241974 27A40018 */  addiu     $a0, $sp, 0x18
/* A2BBB8 80241978 0C019EC8 */  jal       guRotateF
/* A2BBBC 8024197C E7B40010 */   swc1     $f20, 0x10($sp)
/* A2BBC0 80241980 27A40018 */  addiu     $a0, $sp, 0x18
/* A2BBC4 80241984 0200282D */  daddu     $a1, $s0, $zero
/* A2BBC8 80241988 0C019D80 */  jal       guMtxCatF
/* A2BBCC 8024198C 0200302D */   daddu    $a2, $s0, $zero
/* A2BBD0 80241990 8E430000 */  lw        $v1, ($s2)
/* A2BBD4 80241994 24020001 */  addiu     $v0, $zero, 1
/* A2BBD8 80241998 A6220506 */  sh        $v0, 0x506($s1)
/* A2BBDC 8024199C 2862000A */  slti      $v0, $v1, 0xa
/* A2BBE0 802419A0 10400004 */  beqz      $v0, .L802419B4
/* A2BBE4 802419A4 24620001 */   addiu    $v0, $v1, 1
/* A2BBE8 802419A8 AE420000 */  sw        $v0, ($s2)
/* A2BBEC 802419AC 08090674 */  j         .L802419D0
/* A2BBF0 802419B0 0000102D */   daddu    $v0, $zero, $zero
.L802419B4:
/* A2BBF4 802419B4 4405B000 */  mfc1      $a1, $f22
/* A2BBF8 802419B8 4406C000 */  mfc1      $a2, $f24
/* A2BBFC 802419BC 0200202D */  daddu     $a0, $s0, $zero
/* A2BC00 802419C0 E7B40010 */  swc1      $f20, 0x10($sp)
/* A2BC04 802419C4 0C019EC8 */  jal       guRotateF
/* A2BC08 802419C8 00C0382D */   daddu    $a3, $a2, $zero
/* A2BC0C 802419CC 24020001 */  addiu     $v0, $zero, 1
.L802419D0:
/* A2BC10 802419D0 8FBF0064 */  lw        $ra, 0x64($sp)
/* A2BC14 802419D4 8FB20060 */  lw        $s2, 0x60($sp)
/* A2BC18 802419D8 8FB1005C */  lw        $s1, 0x5c($sp)
/* A2BC1C 802419DC 8FB00058 */  lw        $s0, 0x58($sp)
/* A2BC20 802419E0 D7B80078 */  ldc1      $f24, 0x78($sp)
/* A2BC24 802419E4 D7B60070 */  ldc1      $f22, 0x70($sp)
/* A2BC28 802419E8 D7B40068 */  ldc1      $f20, 0x68($sp)
/* A2BC2C 802419EC 03E00008 */  jr        $ra
/* A2BC30 802419F0 27BD0080 */   addiu    $sp, $sp, 0x80

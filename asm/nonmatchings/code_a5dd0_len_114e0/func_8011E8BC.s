.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011E8BC
/* B4FBC 8011E8BC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B4FC0 8011E8C0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B4FC4 8011E8C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B4FC8 8011E8C8 AFBF001C */  sw        $ra, 0x1c($sp)
/* B4FCC 8011E8CC AFB20018 */  sw        $s2, 0x18($sp)
/* B4FD0 8011E8D0 AFB10014 */  sw        $s1, 0x14($sp)
/* B4FD4 8011E8D4 AFB00010 */  sw        $s0, 0x10($sp)
/* B4FD8 8011E8D8 80420070 */  lb        $v0, 0x70($v0)
/* B4FDC 8011E8DC 10400003 */  beqz      $v0, .L8011E8EC
/* B4FE0 8011E8E0 30820800 */   andi     $v0, $a0, 0x800
/* B4FE4 8011E8E4 10400055 */  beqz      $v0, .L8011EA3C
/* B4FE8 8011E8E8 00000000 */   nop
.L8011E8EC:
/* B4FEC 8011E8EC 2402F7FF */  addiu     $v0, $zero, -0x801
/* B4FF0 8011E8F0 00822024 */  and       $a0, $a0, $v0
/* B4FF4 8011E8F4 3C038015 */  lui       $v1, %hi(gCurrentAnimMeshListPtr)
/* B4FF8 8011E8F8 8C633A40 */  lw        $v1, %lo(gCurrentAnimMeshListPtr)($v1)
/* B4FFC 8011E8FC 00041080 */  sll       $v0, $a0, 2
/* B5000 8011E900 00431021 */  addu      $v0, $v0, $v1
/* B5004 8011E904 8C500000 */  lw        $s0, ($v0)
/* B5008 8011E908 1200004C */  beqz      $s0, .L8011EA3C
/* B500C 8011E90C 00000000 */   nop
/* B5010 8011E910 8E040000 */  lw        $a0, ($s0)
/* B5014 8011E914 10800049 */  beqz      $a0, .L8011EA3C
/* B5018 8011E918 3C020004 */   lui      $v0, 4
/* B501C 8011E91C 00821024 */  and       $v0, $a0, $v0
/* B5020 8011E920 14400046 */  bnez      $v0, .L8011EA3C
/* B5024 8011E924 0000182D */   daddu    $v1, $zero, $zero
/* B5028 8011E928 C6000090 */  lwc1      $f0, 0x90($s0)
/* B502C 8011E92C C6020094 */  lwc1      $f2, 0x94($s0)
/* B5030 8011E930 2402FFBF */  addiu     $v0, $zero, -0x41
/* B5034 8011E934 46020001 */  sub.s     $f0, $f0, $f2
/* B5038 8011E938 44801000 */  mtc1      $zero, $f2
/* B503C 8011E93C 00821024 */  and       $v0, $a0, $v0
/* B5040 8011E940 AE020000 */  sw        $v0, ($s0)
/* B5044 8011E944 4602003E */  c.le.s    $f0, $f2
/* B5048 8011E948 00000000 */  nop
/* B504C 8011E94C 45000014 */  bc1f      .L8011E9A0
/* B5050 8011E950 E6000090 */   swc1     $f0, 0x90($s0)
/* B5054 8011E954 30428000 */  andi      $v0, $v0, 0x8000
/* B5058 8011E958 14400008 */  bnez      $v0, .L8011E97C
/* B505C 8011E95C 0200202D */   daddu    $a0, $s0, $zero
.L8011E960:
/* B5060 8011E960 0C047AFC */  jal       func_8011EBF0
/* B5064 8011E964 0200202D */   daddu    $a0, $s0, $zero
/* B5068 8011E968 0040182D */  daddu     $v1, $v0, $zero
/* B506C 8011E96C 1C60FFFC */  bgtz      $v1, .L8011E960
/* B5070 8011E970 2402FFFF */   addiu    $v0, $zero, -1
/* B5074 8011E974 08047A69 */  j         .L8011E9A4
/* B5078 8011E978 00000000 */   nop
.L8011E97C:
/* B507C 8011E97C 3C013F80 */  lui       $at, 0x3f80
/* B5080 8011E980 44810000 */  mtc1      $at, $f0
/* B5084 8011E984 0C04819E */  jal       func_80120678
/* B5088 8011E988 E6000090 */   swc1     $f0, 0x90($s0)
.L8011E98C:
/* B508C 8011E98C 0C0481BE */  jal       func_801206F8
/* B5090 8011E990 0200202D */   daddu    $a0, $s0, $zero
/* B5094 8011E994 0040182D */  daddu     $v1, $v0, $zero
/* B5098 8011E998 1C60FFFC */  bgtz      $v1, .L8011E98C
/* B509C 8011E99C 00000000 */   nop
.L8011E9A0:
/* B50A0 8011E9A0 2402FFFF */  addiu     $v0, $zero, -1
.L8011E9A4:
/* B50A4 8011E9A4 10620025 */  beq       $v1, $v0, .L8011EA3C
/* B50A8 8011E9A8 0200202D */   daddu    $a0, $s0, $zero
/* B50AC 8011E9AC 0C047C16 */  jal       func_8011F058
/* B50B0 8011E9B0 0000282D */   daddu    $a1, $zero, $zero
/* B50B4 8011E9B4 0000882D */  daddu     $s1, $zero, $zero
/* B50B8 8011E9B8 2412FFFF */  addiu     $s2, $zero, -1
/* B50BC 8011E9BC 3C108015 */  lui       $s0, %hi(D_801533C0)
/* B50C0 8011E9C0 261033C0 */  addiu     $s0, $s0, %lo(D_801533C0)
.L8011E9C4:
/* B50C4 8011E9C4 8E020000 */  lw        $v0, ($s0)
/* B50C8 8011E9C8 04420008 */  bltzl     $v0, .L8011E9EC
/* B50CC 8011E9CC 26310001 */   addiu    $s1, $s1, 1
/* B50D0 8011E9D0 2442FFFF */  addiu     $v0, $v0, -1
/* B50D4 8011E9D4 14400004 */  bnez      $v0, .L8011E9E8
/* B50D8 8011E9D8 AE020000 */   sw       $v0, ($s0)
/* B50DC 8011E9DC 8E040004 */  lw        $a0, 4($s0)
/* B50E0 8011E9E0 0C00AB1E */  jal       general_heap_free
/* B50E4 8011E9E4 AE120000 */   sw       $s2, ($s0)
.L8011E9E8:
/* B50E8 8011E9E8 26310001 */  addiu     $s1, $s1, 1
.L8011E9EC:
/* B50EC 8011E9EC 2A220060 */  slti      $v0, $s1, 0x60
/* B50F0 8011E9F0 1440FFF4 */  bnez      $v0, .L8011E9C4
/* B50F4 8011E9F4 26100008 */   addiu    $s0, $s0, 8
/* B50F8 8011E9F8 0000882D */  daddu     $s1, $zero, $zero
/* B50FC 8011E9FC 2412FFFF */  addiu     $s2, $zero, -1
/* B5100 8011EA00 3C108015 */  lui       $s0, %hi(D_801536C0)
/* B5104 8011EA04 261036C0 */  addiu     $s0, $s0, %lo(D_801536C0)
.L8011EA08:
/* B5108 8011EA08 8E020000 */  lw        $v0, ($s0)
/* B510C 8011EA0C 04420008 */  bltzl     $v0, .L8011EA30
/* B5110 8011EA10 26310001 */   addiu    $s1, $s1, 1
/* B5114 8011EA14 2442FFFF */  addiu     $v0, $v0, -1
/* B5118 8011EA18 14400004 */  bnez      $v0, .L8011EA2C
/* B511C 8011EA1C AE020000 */   sw       $v0, ($s0)
/* B5120 8011EA20 8E040004 */  lw        $a0, 4($s0)
/* B5124 8011EA24 0C00AB1E */  jal       general_heap_free
/* B5128 8011EA28 AE120000 */   sw       $s2, ($s0)
.L8011EA2C:
/* B512C 8011EA2C 26310001 */  addiu     $s1, $s1, 1
.L8011EA30:
/* B5130 8011EA30 2A220060 */  slti      $v0, $s1, 0x60
/* B5134 8011EA34 1440FFF4 */  bnez      $v0, .L8011EA08
/* B5138 8011EA38 26100008 */   addiu    $s0, $s0, 8
.L8011EA3C:
/* B513C 8011EA3C 8FBF001C */  lw        $ra, 0x1c($sp)
/* B5140 8011EA40 8FB20018 */  lw        $s2, 0x18($sp)
/* B5144 8011EA44 8FB10014 */  lw        $s1, 0x14($sp)
/* B5148 8011EA48 8FB00010 */  lw        $s0, 0x10($sp)
/* B514C 8011EA4C 03E00008 */  jr        $ra
/* B5150 8011EA50 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E495C
/* 3DE95C E00E495C 27BDFF20 */  addiu     $sp, $sp, -0xe0
/* 3DE960 E00E4960 AFB700BC */  sw        $s7, 0xbc($sp)
/* 3DE964 E00E4964 0080B82D */  daddu     $s7, $a0, $zero
/* 3DE968 E00E4968 3C05DB06 */  lui       $a1, 0xdb06
/* 3DE96C E00E496C 34A50024 */  ori       $a1, $a1, 0x24
/* 3DE970 E00E4970 AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3DE974 E00E4974 24120001 */  addiu     $s2, $zero, 1
/* 3DE978 E00E4978 3C09800A */  lui       $t1, %hi(gMasterGfxPos)
/* 3DE97C E00E497C 2529A66C */  addiu     $t1, $t1, %lo(gMasterGfxPos)
/* 3DE980 E00E4980 3C02E700 */  lui       $v0, 0xe700
/* 3DE984 E00E4984 AFBF00C4 */  sw        $ra, 0xc4($sp)
/* 3DE988 E00E4988 AFBE00C0 */  sw        $fp, 0xc0($sp)
/* 3DE98C E00E498C AFB600B8 */  sw        $s6, 0xb8($sp)
/* 3DE990 E00E4990 AFB500B4 */  sw        $s5, 0xb4($sp)
/* 3DE994 E00E4994 AFB400B0 */  sw        $s4, 0xb0($sp)
/* 3DE998 E00E4998 AFB300AC */  sw        $s3, 0xac($sp)
/* 3DE99C E00E499C AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3DE9A0 E00E49A0 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3DE9A4 E00E49A4 F7B800D8 */  sdc1      $f24, 0xd8($sp)
/* 3DE9A8 E00E49A8 F7B600D0 */  sdc1      $f22, 0xd0($sp)
/* 3DE9AC E00E49AC F7B400C8 */  sdc1      $f20, 0xc8($sp)
/* 3DE9B0 E00E49B0 8D240000 */  lw        $a0, ($t1)
/* 3DE9B4 E00E49B4 8EE8000C */  lw        $t0, 0xc($s7)
/* 3DE9B8 E00E49B8 3C01437F */  lui       $at, 0x437f
/* 3DE9BC E00E49BC 44810000 */  mtc1      $at, $f0
/* 3DE9C0 E00E49C0 0080182D */  daddu     $v1, $a0, $zero
/* 3DE9C4 E00E49C4 24840008 */  addiu     $a0, $a0, 8
/* 3DE9C8 E00E49C8 AD240000 */  sw        $a0, ($t1)
/* 3DE9CC E00E49CC 8D140000 */  lw        $s4, ($t0)
/* 3DE9D0 E00E49D0 C5040058 */  lwc1      $f4, 0x58($t0)
/* 3DE9D4 E00E49D4 C5020044 */  lwc1      $f2, 0x44($t0)
/* 3DE9D8 E00E49D8 468010A0 */  cvt.s.w   $f2, $f2
/* 3DE9DC E00E49DC AC620000 */  sw        $v0, ($v1)
/* 3DE9E0 E00E49E0 24820008 */  addiu     $v0, $a0, 8
/* 3DE9E4 E00E49E4 AC600004 */  sw        $zero, 4($v1)
/* 3DE9E8 E00E49E8 AD220000 */  sw        $v0, ($t1)
/* 3DE9EC E00E49EC AC850000 */  sw        $a1, ($a0)
/* 3DE9F0 E00E49F0 8EE30010 */  lw        $v1, 0x10($s7)
/* 3DE9F4 E00E49F4 24820010 */  addiu     $v0, $a0, 0x10
/* 3DE9F8 E00E49F8 AD220000 */  sw        $v0, ($t1)
/* 3DE9FC E00E49FC 3C02FB00 */  lui       $v0, 0xfb00
/* 3DEA00 E00E4A00 8C63001C */  lw        $v1, 0x1c($v1)
/* 3DEA04 E00E4A04 46001083 */  div.s     $f2, $f2, $f0
/* 3DEA08 E00E4A08 AC820008 */  sw        $v0, 8($a0)
/* 3DEA0C E00E4A0C 3C028000 */  lui       $v0, 0x8000
/* 3DEA10 E00E4A10 46041502 */  mul.s     $f20, $f2, $f4
/* 3DEA14 E00E4A14 00000000 */  nop
/* 3DEA18 E00E4A18 00621821 */  addu      $v1, $v1, $v0
/* 3DEA1C E00E4A1C AC830004 */  sw        $v1, 4($a0)
/* 3DEA20 E00E4A20 9102004B */  lbu       $v0, 0x4b($t0)
/* 3DEA24 E00E4A24 9105004F */  lbu       $a1, 0x4f($t0)
/* 3DEA28 E00E4A28 91060053 */  lbu       $a2, 0x53($t0)
/* 3DEA2C E00E4A2C 91070057 */  lbu       $a3, 0x57($t0)
/* 3DEA30 E00E4A30 3C03DE00 */  lui       $v1, 0xde00
/* 3DEA34 E00E4A34 AC830010 */  sw        $v1, 0x10($a0)
/* 3DEA38 E00E4A38 00021600 */  sll       $v0, $v0, 0x18
/* 3DEA3C E00E4A3C 00052C00 */  sll       $a1, $a1, 0x10
/* 3DEA40 E00E4A40 00451025 */  or        $v0, $v0, $a1
/* 3DEA44 E00E4A44 00063200 */  sll       $a2, $a2, 8
/* 3DEA48 E00E4A48 00461025 */  or        $v0, $v0, $a2
/* 3DEA4C E00E4A4C 00471025 */  or        $v0, $v0, $a3
/* 3DEA50 E00E4A50 AC82000C */  sw        $v0, 0xc($a0)
/* 3DEA54 E00E4A54 00141080 */  sll       $v0, $s4, 2
/* 3DEA58 E00E4A58 3C03E00E */  lui       $v1, %hi(D_E00E4DA8)
/* 3DEA5C E00E4A5C 00621821 */  addu      $v1, $v1, $v0
/* 3DEA60 E00E4A60 8C634DA8 */  lw        $v1, %lo(D_E00E4DA8)($v1)
/* 3DEA64 E00E4A64 24820018 */  addiu     $v0, $a0, 0x18
/* 3DEA68 E00E4A68 AD220000 */  sw        $v0, ($t1)
/* 3DEA6C E00E4A6C AC830014 */  sw        $v1, 0x14($a0)
/* 3DEA70 E00E4A70 8EE20008 */  lw        $v0, 8($s7)
/* 3DEA74 E00E4A74 0242102A */  slt       $v0, $s2, $v0
/* 3DEA78 E00E4A78 104000B6 */  beqz      $v0, .LE00E4D54
/* 3DEA7C E00E4A7C 25080064 */   addiu    $t0, $t0, 0x64
/* 3DEA80 E00E4A80 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 3DEA84 E00E4A84 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 3DEA88 E00E4A88 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 3DEA8C E00E4A8C 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 3DEA90 E00E4A90 3C130001 */  lui       $s3, 1
/* 3DEA94 E00E4A94 36731630 */  ori       $s3, $s3, 0x1630
/* 3DEA98 E00E4A98 0120882D */  daddu     $s1, $t1, $zero
/* 3DEA9C E00E4A9C 3C1EE00E */  lui       $fp, %hi(D_E00E4D90)
/* 3DEAA0 E00E4AA0 27DE4D90 */  addiu     $fp, $fp, %lo(D_E00E4D90)
/* 3DEAA4 E00E4AA4 25100060 */  addiu     $s0, $t0, 0x60
/* 3DEAA8 E00E4AA8 4480C000 */  mtc1      $zero, $f24
/* 3DEAAC E00E4AAC 3C014F00 */  lui       $at, 0x4f00
/* 3DEAB0 E00E4AB0 4481B000 */  mtc1      $at, $f22
.LE00E4AB4:
/* 3DEAB4 E00E4AB4 8E02FFCC */  lw        $v0, -0x34($s0)
/* 3DEAB8 E00E4AB8 044000A1 */  bltz      $v0, .LE00E4D40
/* 3DEABC E00E4ABC 27A40020 */   addiu    $a0, $sp, 0x20
/* 3DEAC0 E00E4AC0 3C0A800B */  lui       $t2, %hi(gCameras)
/* 3DEAC4 E00E4AC4 254A1D80 */  addiu     $t2, $t2, %lo(gCameras)
/* 3DEAC8 E00E4AC8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3DEACC E00E4ACC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3DEAD0 E00E4AD0 4405C000 */  mfc1      $a1, $f24
/* 3DEAD4 E00E4AD4 C600FFF8 */  lwc1      $f0, -8($s0)
/* 3DEAD8 E00E4AD8 00031080 */  sll       $v0, $v1, 2
/* 3DEADC E00E4ADC 00431021 */  addu      $v0, $v0, $v1
/* 3DEAE0 E00E4AE0 00021080 */  sll       $v0, $v0, 2
/* 3DEAE4 E00E4AE4 00431023 */  subu      $v0, $v0, $v1
/* 3DEAE8 E00E4AE8 000218C0 */  sll       $v1, $v0, 3
/* 3DEAEC E00E4AEC 00431021 */  addu      $v0, $v0, $v1
/* 3DEAF0 E00E4AF0 46140002 */  mul.s     $f0, $f0, $f20
/* 3DEAF4 E00E4AF4 00000000 */  nop
/* 3DEAF8 E00E4AF8 000210C0 */  sll       $v0, $v0, 3
/* 3DEAFC E00E4AFC 004A1021 */  addu      $v0, $v0, $t2
/* 3DEB00 E00E4B00 C442006C */  lwc1      $f2, 0x6c($v0)
/* 3DEB04 E00E4B04 4407C000 */  mfc1      $a3, $f24
/* 3DEB08 E00E4B08 46001087 */  neg.s     $f2, $f2
/* 3DEB0C E00E4B0C 44061000 */  mfc1      $a2, $f2
/* 3DEB10 E00E4B10 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3DEB14 E00E4B14 C600FFA4 */  lwc1      $f0, -0x5c($s0)
/* 3DEB18 E00E4B18 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3DEB1C E00E4B1C C600FFA8 */  lwc1      $f0, -0x58($s0)
/* 3DEB20 E00E4B20 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3DEB24 E00E4B24 C600FFAC */  lwc1      $f0, -0x54($s0)
/* 3DEB28 E00E4B28 0C080180 */  jal       shim_guPositionF
/* 3DEB2C E00E4B2C E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3DEB30 E00E4B30 27A40020 */  addiu     $a0, $sp, 0x20
/* 3DEB34 E00E4B34 96A50000 */  lhu       $a1, ($s5)
/* 3DEB38 E00E4B38 8EC20000 */  lw        $v0, ($s6)
/* 3DEB3C E00E4B3C 00052980 */  sll       $a1, $a1, 6
/* 3DEB40 E00E4B40 00B32821 */  addu      $a1, $a1, $s3
/* 3DEB44 E00E4B44 0C080118 */  jal       shim_guMtxF2L
/* 3DEB48 E00E4B48 00452821 */   addu     $a1, $v0, $a1
/* 3DEB4C E00E4B4C 8E240000 */  lw        $a0, ($s1)
/* 3DEB50 E00E4B50 0080282D */  daddu     $a1, $a0, $zero
/* 3DEB54 E00E4B54 24840008 */  addiu     $a0, $a0, 8
/* 3DEB58 E00E4B58 AE240000 */  sw        $a0, ($s1)
/* 3DEB5C E00E4B5C 96A20000 */  lhu       $v0, ($s5)
/* 3DEB60 E00E4B60 3C03DA38 */  lui       $v1, 0xda38
/* 3DEB64 E00E4B64 ACA30000 */  sw        $v1, ($a1)
/* 3DEB68 E00E4B68 24430001 */  addiu     $v1, $v0, 1
/* 3DEB6C E00E4B6C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3DEB70 E00E4B70 00021180 */  sll       $v0, $v0, 6
/* 3DEB74 E00E4B74 A6A30000 */  sh        $v1, ($s5)
/* 3DEB78 E00E4B78 8EC30000 */  lw        $v1, ($s6)
/* 3DEB7C E00E4B7C 00531021 */  addu      $v0, $v0, $s3
/* 3DEB80 E00E4B80 00621821 */  addu      $v1, $v1, $v0
/* 3DEB84 E00E4B84 24820008 */  addiu     $v0, $a0, 8
/* 3DEB88 E00E4B88 ACA30004 */  sw        $v1, 4($a1)
/* 3DEB8C E00E4B8C AE220000 */  sw        $v0, ($s1)
/* 3DEB90 E00E4B90 24020050 */  addiu     $v0, $zero, 0x50
/* 3DEB94 E00E4B94 8E03FFCC */  lw        $v1, -0x34($s0)
/* 3DEB98 E00E4B98 24850004 */  addiu     $a1, $a0, 4
/* 3DEB9C E00E4B9C 00431023 */  subu      $v0, $v0, $v1
/* 3DEBA0 E00E4BA0 304200FF */  andi      $v0, $v0, 0xff
/* 3DEBA4 E00E4BA4 3C03FA00 */  lui       $v1, 0xfa00
/* 3DEBA8 E00E4BA8 00431025 */  or        $v0, $v0, $v1
/* 3DEBAC E00E4BAC AC820000 */  sw        $v0, ($a0)
/* 3DEBB0 E00E4BB0 C600FFE4 */  lwc1      $f0, -0x1c($s0)
/* 3DEBB4 E00E4BB4 46800020 */  cvt.s.w   $f0, $f0
/* 3DEBB8 E00E4BB8 4600A002 */  mul.s     $f0, $f20, $f0
/* 3DEBBC E00E4BBC 00000000 */  nop
/* 3DEBC0 E00E4BC0 9203FFDB */  lbu       $v1, -0x25($s0)
/* 3DEBC4 E00E4BC4 9204FFDF */  lbu       $a0, -0x21($s0)
/* 3DEBC8 E00E4BC8 9202FFE3 */  lbu       $v0, -0x1d($s0)
/* 3DEBCC E00E4BCC 00031E00 */  sll       $v1, $v1, 0x18
/* 3DEBD0 E00E4BD0 00042400 */  sll       $a0, $a0, 0x10
/* 3DEBD4 E00E4BD4 00641825 */  or        $v1, $v1, $a0
/* 3DEBD8 E00E4BD8 00021200 */  sll       $v0, $v0, 8
/* 3DEBDC E00E4BDC 4600B03E */  c.le.s    $f22, $f0
/* 3DEBE0 E00E4BE0 00000000 */  nop
/* 3DEBE4 E00E4BE4 45010005 */  bc1t      .LE00E4BFC
/* 3DEBE8 E00E4BE8 00621825 */   or       $v1, $v1, $v0
/* 3DEBEC E00E4BEC 4600018D */  trunc.w.s $f6, $f0
/* 3DEBF0 E00E4BF0 44043000 */  mfc1      $a0, $f6
/* 3DEBF4 E00E4BF4 08039306 */  j         .LE00E4C18
/* 3DEBF8 E00E4BF8 308200FF */   andi     $v0, $a0, 0xff
.LE00E4BFC:
/* 3DEBFC E00E4BFC 46160001 */  sub.s     $f0, $f0, $f22
/* 3DEC00 E00E4C00 3C028000 */  lui       $v0, 0x8000
/* 3DEC04 E00E4C04 4600018D */  trunc.w.s $f6, $f0
/* 3DEC08 E00E4C08 44043000 */  mfc1      $a0, $f6
/* 3DEC0C E00E4C0C 00000000 */  nop
/* 3DEC10 E00E4C10 00822025 */  or        $a0, $a0, $v0
/* 3DEC14 E00E4C14 308200FF */  andi      $v0, $a0, 0xff
.LE00E4C18:
/* 3DEC18 E00E4C18 00621025 */  or        $v0, $v1, $v0
/* 3DEC1C E00E4C1C 8E260000 */  lw        $a2, ($s1)
/* 3DEC20 E00E4C20 3C03F200 */  lui       $v1, 0xf200
/* 3DEC24 E00E4C24 ACA20000 */  sw        $v0, ($a1)
/* 3DEC28 E00E4C28 C600FFFC */  lwc1      $f0, -4($s0)
/* 3DEC2C E00E4C2C 00C0282D */  daddu     $a1, $a2, $zero
/* 3DEC30 E00E4C30 4600018D */  trunc.w.s $f6, $f0
/* 3DEC34 E00E4C34 44043000 */  mfc1      $a0, $f6
/* 3DEC38 E00E4C38 00000000 */  nop
/* 3DEC3C E00E4C3C 00042080 */  sll       $a0, $a0, 2
/* 3DEC40 E00E4C40 30840FFF */  andi      $a0, $a0, 0xfff
/* 3DEC44 E00E4C44 00042300 */  sll       $a0, $a0, 0xc
/* 3DEC48 E00E4C48 C6000000 */  lwc1      $f0, ($s0)
/* 3DEC4C E00E4C4C 24C60008 */  addiu     $a2, $a2, 8
/* 3DEC50 E00E4C50 4600018D */  trunc.w.s $f6, $f0
/* 3DEC54 E00E4C54 44023000 */  mfc1      $v0, $f6
/* 3DEC58 E00E4C58 00000000 */  nop
/* 3DEC5C E00E4C5C 00021080 */  sll       $v0, $v0, 2
/* 3DEC60 E00E4C60 30420FFF */  andi      $v0, $v0, 0xfff
/* 3DEC64 E00E4C64 00431025 */  or        $v0, $v0, $v1
/* 3DEC68 E00E4C68 00822025 */  or        $a0, $a0, $v0
/* 3DEC6C E00E4C6C ACA40000 */  sw        $a0, ($a1)
/* 3DEC70 E00E4C70 C600FFFC */  lwc1      $f0, -4($s0)
/* 3DEC74 E00E4C74 3C030100 */  lui       $v1, 0x100
/* 3DEC78 E00E4C78 AE260000 */  sw        $a2, ($s1)
/* 3DEC7C E00E4C7C 4600018D */  trunc.w.s $f6, $f0
/* 3DEC80 E00E4C80 44043000 */  mfc1      $a0, $f6
/* 3DEC84 E00E4C84 00000000 */  nop
/* 3DEC88 E00E4C88 2484000F */  addiu     $a0, $a0, 0xf
/* 3DEC8C E00E4C8C 00042080 */  sll       $a0, $a0, 2
/* 3DEC90 E00E4C90 30840FFF */  andi      $a0, $a0, 0xfff
/* 3DEC94 E00E4C94 C6000000 */  lwc1      $f0, ($s0)
/* 3DEC98 E00E4C98 00042300 */  sll       $a0, $a0, 0xc
/* 3DEC9C E00E4C9C 4600018D */  trunc.w.s $f6, $f0
/* 3DECA0 E00E4CA0 44023000 */  mfc1      $v0, $f6
/* 3DECA4 E00E4CA4 00000000 */  nop
/* 3DECA8 E00E4CA8 2442000F */  addiu     $v0, $v0, 0xf
/* 3DECAC E00E4CAC 00021080 */  sll       $v0, $v0, 2
/* 3DECB0 E00E4CB0 30420FFF */  andi      $v0, $v0, 0xfff
/* 3DECB4 E00E4CB4 00431025 */  or        $v0, $v0, $v1
/* 3DECB8 E00E4CB8 00822025 */  or        $a0, $a0, $v0
/* 3DECBC E00E4CBC 24020002 */  addiu     $v0, $zero, 2
/* 3DECC0 E00E4CC0 1682000E */  bne       $s4, $v0, .LE00E4CFC
/* 3DECC4 E00E4CC4 ACA40004 */   sw       $a0, 4($a1)
/* 3DECC8 E00E4CC8 3C04F200 */  lui       $a0, 0xf200
/* 3DECCC E00E4CCC 3484007C */  ori       $a0, $a0, 0x7c
/* 3DECD0 E00E4CD0 24C20008 */  addiu     $v0, $a2, 8
/* 3DECD4 E00E4CD4 3243001F */  andi      $v1, $s2, 0x1f
/* 3DECD8 E00E4CD8 AE220000 */  sw        $v0, ($s1)
/* 3DECDC E00E4CDC 000314C0 */  sll       $v0, $v1, 0x13
/* 3DECE0 E00E4CE0 00441025 */  or        $v0, $v0, $a0
/* 3DECE4 E00E4CE4 000319C0 */  sll       $v1, $v1, 7
/* 3DECE8 E00E4CE8 3463007C */  ori       $v1, $v1, 0x7c
/* 3DECEC E00E4CEC 00031B00 */  sll       $v1, $v1, 0xc
/* 3DECF0 E00E4CF0 3463007C */  ori       $v1, $v1, 0x7c
/* 3DECF4 E00E4CF4 ACC20000 */  sw        $v0, ($a2)
/* 3DECF8 E00E4CF8 ACC30004 */  sw        $v1, 4($a2)
.LE00E4CFC:
/* 3DECFC E00E4CFC 3C06D838 */  lui       $a2, 0xd838
/* 3DED00 E00E4D00 34C60002 */  ori       $a2, $a2, 2
/* 3DED04 E00E4D04 8E230000 */  lw        $v1, ($s1)
/* 3DED08 E00E4D08 3C02DE00 */  lui       $v0, 0xde00
/* 3DED0C E00E4D0C 0060282D */  daddu     $a1, $v1, $zero
/* 3DED10 E00E4D10 24630008 */  addiu     $v1, $v1, 8
/* 3DED14 E00E4D14 AE230000 */  sw        $v1, ($s1)
/* 3DED18 E00E4D18 ACA20000 */  sw        $v0, ($a1)
/* 3DED1C E00E4D1C 00141080 */  sll       $v0, $s4, 2
/* 3DED20 E00E4D20 005E1021 */  addu      $v0, $v0, $fp
/* 3DED24 E00E4D24 8C440000 */  lw        $a0, ($v0)
/* 3DED28 E00E4D28 24620008 */  addiu     $v0, $v1, 8
/* 3DED2C E00E4D2C AE220000 */  sw        $v0, ($s1)
/* 3DED30 E00E4D30 24020040 */  addiu     $v0, $zero, 0x40
/* 3DED34 E00E4D34 ACA40004 */  sw        $a0, 4($a1)
/* 3DED38 E00E4D38 AC660000 */  sw        $a2, ($v1)
/* 3DED3C E00E4D3C AC620004 */  sw        $v0, 4($v1)
.LE00E4D40:
/* 3DED40 E00E4D40 26520001 */  addiu     $s2, $s2, 1
/* 3DED44 E00E4D44 8EE20008 */  lw        $v0, 8($s7)
/* 3DED48 E00E4D48 0242102A */  slt       $v0, $s2, $v0
/* 3DED4C E00E4D4C 1440FF59 */  bnez      $v0, .LE00E4AB4
/* 3DED50 E00E4D50 26100064 */   addiu    $s0, $s0, 0x64
.LE00E4D54:
/* 3DED54 E00E4D54 8FBF00C4 */  lw        $ra, 0xc4($sp)
/* 3DED58 E00E4D58 8FBE00C0 */  lw        $fp, 0xc0($sp)
/* 3DED5C E00E4D5C 8FB700BC */  lw        $s7, 0xbc($sp)
/* 3DED60 E00E4D60 8FB600B8 */  lw        $s6, 0xb8($sp)
/* 3DED64 E00E4D64 8FB500B4 */  lw        $s5, 0xb4($sp)
/* 3DED68 E00E4D68 8FB400B0 */  lw        $s4, 0xb0($sp)
/* 3DED6C E00E4D6C 8FB300AC */  lw        $s3, 0xac($sp)
/* 3DED70 E00E4D70 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3DED74 E00E4D74 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3DED78 E00E4D78 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3DED7C E00E4D7C D7B800D8 */  ldc1      $f24, 0xd8($sp)
/* 3DED80 E00E4D80 D7B600D0 */  ldc1      $f22, 0xd0($sp)
/* 3DED84 E00E4D84 D7B400C8 */  ldc1      $f20, 0xc8($sp)
/* 3DED88 E00E4D88 03E00008 */  jr        $ra
/* 3DED8C E00E4D8C 27BD00E0 */   addiu    $sp, $sp, 0xe0

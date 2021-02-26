.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050A00
/* 2BE00 80050A00 0080302D */  daddu     $a2, $a0, $zero
/* 2BE04 80050A04 240300FF */  addiu     $v1, $zero, 0xff
/* 2BE08 80050A08 90C2002A */  lbu       $v0, 0x2a($a2)
/* 2BE0C 80050A0C 94C50028 */  lhu       $a1, 0x28($a2)
/* 2BE10 80050A10 14430004 */  bne       $v0, $v1, .L80050A24
/* 2BE14 80050A14 24A2FF06 */   addiu    $v0, $a1, -0xfa
/* 2BE18 80050A18 80C20038 */  lb        $v0, 0x38($a2)
/* 2BE1C 80050A1C A0C2002A */  sb        $v0, 0x2a($a2)
/* 2BE20 80050A20 24A2FF06 */  addiu     $v0, $a1, -0xfa
.L80050A24:
/* 2BE24 80050A24 3042FFFF */  andi      $v0, $v0, 0xffff
/* 2BE28 80050A28 2C422617 */  sltiu     $v0, $v0, 0x2617
/* 2BE2C 80050A2C 10400022 */  beqz      $v0, .L80050AB8
/* 2BE30 80050A30 3C041CF0 */   lui      $a0, 0x1cf0
/* 2BE34 80050A34 34846ADB */  ori       $a0, $a0, 0x6adb
/* 2BE38 80050A38 30A3FFFF */  andi      $v1, $a1, 0xffff
/* 2BE3C 80050A3C 00031080 */  sll       $v0, $v1, 2
/* 2BE40 80050A40 00431021 */  addu      $v0, $v0, $v1
/* 2BE44 80050A44 00021040 */  sll       $v0, $v0, 1
/* 2BE48 80050A48 00440019 */  multu     $v0, $a0
/* 2BE4C 80050A4C 90C3002B */  lbu       $v1, 0x2b($a2)
/* 2BE50 80050A50 00002010 */  mfhi      $a0
/* 2BE54 80050A54 00441023 */  subu      $v0, $v0, $a0
/* 2BE58 80050A58 00021042 */  srl       $v0, $v0, 1
/* 2BE5C 80050A5C 00822021 */  addu      $a0, $a0, $v0
/* 2BE60 80050A60 90C2002A */  lbu       $v0, 0x2a($a2)
/* 2BE64 80050A64 00042182 */  srl       $a0, $a0, 6
/* 2BE68 80050A68 00621823 */  subu      $v1, $v1, $v0
/* 2BE6C 80050A6C 00031E00 */  sll       $v1, $v1, 0x18
/* 2BE70 80050A70 3082FFFF */  andi      $v0, $a0, 0xffff
/* 2BE74 80050A74 14400002 */  bnez      $v0, .L80050A80
/* 2BE78 80050A78 0062001A */   div      $zero, $v1, $v0
/* 2BE7C 80050A7C 0007000D */  break     7
.L80050A80:
/* 2BE80 80050A80 2401FFFF */   addiu    $at, $zero, -1
/* 2BE84 80050A84 14410004 */  bne       $v0, $at, .L80050A98
/* 2BE88 80050A88 3C018000 */   lui      $at, 0x8000
/* 2BE8C 80050A8C 14610002 */  bne       $v1, $at, .L80050A98
/* 2BE90 80050A90 00000000 */   nop
/* 2BE94 80050A94 0006000D */  break     6
.L80050A98:
/* 2BE98 80050A98 00001812 */   mflo     $v1
/* 2BE9C 80050A9C 90C5002B */  lbu       $a1, 0x2b($a2)
/* 2BEA0 80050AA0 90C2002A */  lbu       $v0, 0x2a($a2)
/* 2BEA4 80050AA4 A0C50042 */  sb        $a1, 0x42($a2)
/* 2BEA8 80050AA8 A4C40040 */  sh        $a0, 0x40($a2)
/* 2BEAC 80050AAC 00021600 */  sll       $v0, $v0, 0x18
/* 2BEB0 80050AB0 ACC20038 */  sw        $v0, 0x38($a2)
/* 2BEB4 80050AB4 ACC3003C */  sw        $v1, 0x3c($a2)
.L80050AB8:
/* 2BEB8 80050AB8 A4C00028 */  sh        $zero, 0x28($a2)
/* 2BEBC 80050ABC A0C0002A */  sb        $zero, 0x2a($a2)
/* 2BEC0 80050AC0 03E00008 */  jr        $ra
/* 2BEC4 80050AC4 A0C0002B */   sb       $zero, 0x2b($a2)

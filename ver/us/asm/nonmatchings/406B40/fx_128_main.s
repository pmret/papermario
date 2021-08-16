.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_128_main
/* 406B40 E011C000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 406B44 E011C004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 406B48 E011C008 4485A000 */  mtc1      $a1, $f20
/* 406B4C E011C00C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 406B50 E011C010 4486B000 */  mtc1      $a2, $f22
/* 406B54 E011C014 AFB20030 */  sw        $s2, 0x30($sp)
/* 406B58 E011C018 0080902D */  daddu     $s2, $a0, $zero
/* 406B5C E011C01C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 406B60 E011C020 4487C000 */  mtc1      $a3, $f24
/* 406B64 E011C024 27A40010 */  addiu     $a0, $sp, 0x10
/* 406B68 E011C028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 406B6C E011C02C 8FB10064 */  lw        $s1, 0x64($sp)
/* 406B70 E011C030 3C02E012 */  lui       $v0, %hi(func_E011C0F4)
/* 406B74 E011C034 2442C0F4 */  addiu     $v0, $v0, %lo(func_E011C0F4)
/* 406B78 E011C038 AFA20018 */  sw        $v0, 0x18($sp)
/* 406B7C E011C03C 3C02E012 */  lui       $v0, %hi(func_E011C0FC)
/* 406B80 E011C040 2442C0FC */  addiu     $v0, $v0, %lo(func_E011C0FC)
/* 406B84 E011C044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 406B88 E011C048 3C02E012 */  lui       $v0, %hi(func_E011C17C)
/* 406B8C E011C04C 2442C17C */  addiu     $v0, $v0, %lo(func_E011C17C)
/* 406B90 E011C050 AFA20020 */  sw        $v0, 0x20($sp)
/* 406B94 E011C054 24020080 */  addiu     $v0, $zero, 0x80
/* 406B98 E011C058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 406B9C E011C05C AFB00028 */  sw        $s0, 0x28($sp)
/* 406BA0 E011C060 AFA00010 */  sw        $zero, 0x10($sp)
/* 406BA4 E011C064 AFA00024 */  sw        $zero, 0x24($sp)
/* 406BA8 E011C068 0C080124 */  jal       func_E0200490
/* 406BAC E011C06C AFA20014 */   sw       $v0, 0x14($sp)
/* 406BB0 E011C070 24040020 */  addiu     $a0, $zero, 0x20
/* 406BB4 E011C074 24030001 */  addiu     $v1, $zero, 1
/* 406BB8 E011C078 0040802D */  daddu     $s0, $v0, $zero
/* 406BBC E011C07C 0C08012C */  jal       func_E02004B0
/* 406BC0 E011C080 AE030008 */   sw       $v1, 8($s0)
/* 406BC4 E011C084 0040202D */  daddu     $a0, $v0, $zero
/* 406BC8 E011C088 14800003 */  bnez      $a0, .LE011C098
/* 406BCC E011C08C AE02000C */   sw       $v0, 0xc($s0)
.LE011C090:
/* 406BD0 E011C090 08047024 */  j         .LE011C090
/* 406BD4 E011C094 00000000 */   nop
.LE011C098:
/* 406BD8 E011C098 AC920000 */  sw        $s2, ($a0)
/* 406BDC E011C09C 1E200004 */  bgtz      $s1, .LE011C0B0
/* 406BE0 E011C0A0 AC800014 */   sw       $zero, 0x14($a0)
/* 406BE4 E011C0A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 406BE8 E011C0A8 0804702D */  j         .LE011C0B4
/* 406BEC E011C0AC AC820010 */   sw       $v0, 0x10($a0)
.LE011C0B0:
/* 406BF0 E011C0B0 AC910010 */  sw        $s1, 0x10($a0)
.LE011C0B4:
/* 406BF4 E011C0B4 0200102D */  daddu     $v0, $s0, $zero
/* 406BF8 E011C0B8 240300FF */  addiu     $v1, $zero, 0xff
/* 406BFC E011C0BC AC830018 */  sw        $v1, 0x18($a0)
/* 406C00 E011C0C0 E4940004 */  swc1      $f20, 4($a0)
/* 406C04 E011C0C4 E4960008 */  swc1      $f22, 8($a0)
/* 406C08 E011C0C8 E498000C */  swc1      $f24, 0xc($a0)
/* 406C0C E011C0CC AC80001C */  sw        $zero, 0x1c($a0)
/* 406C10 E011C0D0 8FBF0034 */  lw        $ra, 0x34($sp)
/* 406C14 E011C0D4 8FB20030 */  lw        $s2, 0x30($sp)
/* 406C18 E011C0D8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 406C1C E011C0DC 8FB00028 */  lw        $s0, 0x28($sp)
/* 406C20 E011C0E0 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 406C24 E011C0E4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 406C28 E011C0E8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 406C2C E011C0EC 03E00008 */  jr        $ra
/* 406C30 E011C0F0 27BD0050 */   addiu    $sp, $sp, 0x50

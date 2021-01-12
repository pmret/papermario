.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0128000
/* 414BA0 E0128000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 414BA4 E0128004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 414BA8 E0128008 4485A000 */  mtc1      $a1, $f20
/* 414BAC E012800C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 414BB0 E0128010 4486B000 */  mtc1      $a2, $f22
/* 414BB4 E0128014 AFB20030 */  sw        $s2, 0x30($sp)
/* 414BB8 E0128018 0080902D */  daddu     $s2, $a0, $zero
/* 414BBC E012801C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 414BC0 E0128020 4487C000 */  mtc1      $a3, $f24
/* 414BC4 E0128024 27A40010 */  addiu     $a0, $sp, 0x10
/* 414BC8 E0128028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 414BCC E012802C 8FB10064 */  lw        $s1, 0x64($sp)
/* 414BD0 E0128030 3C02E013 */  lui       $v0, %hi(func_E0128128)
/* 414BD4 E0128034 24428128 */  addiu     $v0, $v0, %lo(func_E0128128)
/* 414BD8 E0128038 AFA20018 */  sw        $v0, 0x18($sp)
/* 414BDC E012803C 3C02E013 */  lui       $v0, %hi(func_E0128130)
/* 414BE0 E0128040 24428130 */  addiu     $v0, $v0, %lo(func_E0128130)
/* 414BE4 E0128044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 414BE8 E0128048 3C02E013 */  lui       $v0, %hi(func_E0128198)
/* 414BEC E012804C 24428198 */  addiu     $v0, $v0, %lo(func_E0128198)
/* 414BF0 E0128050 AFA20020 */  sw        $v0, 0x20($sp)
/* 414BF4 E0128054 24020086 */  addiu     $v0, $zero, 0x86
/* 414BF8 E0128058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 414BFC E012805C AFB00028 */  sw        $s0, 0x28($sp)
/* 414C00 E0128060 AFA00010 */  sw        $zero, 0x10($sp)
/* 414C04 E0128064 AFA00024 */  sw        $zero, 0x24($sp)
/* 414C08 E0128068 0C080124 */  jal       func_E0200490
/* 414C0C E012806C AFA20014 */   sw       $v0, 0x14($sp)
/* 414C10 E0128070 24040038 */  addiu     $a0, $zero, 0x38
/* 414C14 E0128074 24030001 */  addiu     $v1, $zero, 1
/* 414C18 E0128078 0040802D */  daddu     $s0, $v0, $zero
/* 414C1C E012807C 0C08012C */  jal       func_E02004B0
/* 414C20 E0128080 AE030008 */   sw       $v1, 8($s0)
/* 414C24 E0128084 0040202D */  daddu     $a0, $v0, $zero
/* 414C28 E0128088 14800003 */  bnez      $a0, .LE0128098
/* 414C2C E012808C AE02000C */   sw       $v0, 0xc($s0)
.LE0128090:
/* 414C30 E0128090 0804A024 */  j         .LE0128090
/* 414C34 E0128094 00000000 */   nop
.LE0128098:
/* 414C38 E0128098 AC920000 */  sw        $s2, ($a0)
/* 414C3C E012809C 1E200004 */  bgtz      $s1, .LE01280B0
/* 414C40 E01280A0 AC800014 */   sw       $zero, 0x14($a0)
/* 414C44 E01280A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 414C48 E01280A8 0804A02D */  j         .LE01280B4
/* 414C4C E01280AC AC820010 */   sw       $v0, 0x10($a0)
.LE01280B0:
/* 414C50 E01280B0 AC910010 */  sw        $s1, 0x10($a0)
.LE01280B4:
/* 414C54 E01280B4 0200102D */  daddu     $v0, $s0, $zero
/* 414C58 E01280B8 240300FF */  addiu     $v1, $zero, 0xff
/* 414C5C E01280BC AC830024 */  sw        $v1, 0x24($a0)
/* 414C60 E01280C0 E4940004 */  swc1      $f20, 4($a0)
/* 414C64 E01280C4 E4960008 */  swc1      $f22, 8($a0)
/* 414C68 E01280C8 E498000C */  swc1      $f24, 0xc($a0)
/* 414C6C E01280CC C7A00060 */  lwc1      $f0, 0x60($sp)
/* 414C70 E01280D0 24030046 */  addiu     $v1, $zero, 0x46
/* 414C74 E01280D4 AC830018 */  sw        $v1, 0x18($a0)
/* 414C78 E01280D8 240300B4 */  addiu     $v1, $zero, 0xb4
/* 414C7C E01280DC AC83001C */  sw        $v1, 0x1c($a0)
/* 414C80 E01280E0 24030078 */  addiu     $v1, $zero, 0x78
/* 414C84 E01280E4 AC830020 */  sw        $v1, 0x20($a0)
/* 414C88 E01280E8 24030014 */  addiu     $v1, $zero, 0x14
/* 414C8C E01280EC AC830028 */  sw        $v1, 0x28($a0)
/* 414C90 E01280F0 240300E6 */  addiu     $v1, $zero, 0xe6
/* 414C94 E01280F4 AC83002C */  sw        $v1, 0x2c($a0)
/* 414C98 E01280F8 24030032 */  addiu     $v1, $zero, 0x32
/* 414C9C E01280FC AC830030 */  sw        $v1, 0x30($a0)
/* 414CA0 E0128100 E4800034 */  swc1      $f0, 0x34($a0)
/* 414CA4 E0128104 8FBF0034 */  lw        $ra, 0x34($sp)
/* 414CA8 E0128108 8FB20030 */  lw        $s2, 0x30($sp)
/* 414CAC E012810C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 414CB0 E0128110 8FB00028 */  lw        $s0, 0x28($sp)
/* 414CB4 E0128114 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 414CB8 E0128118 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 414CBC E012811C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 414CC0 E0128120 03E00008 */  jr        $ra
/* 414CC4 E0128124 27BD0050 */   addiu    $sp, $sp, 0x50

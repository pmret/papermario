.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0068000
/* 36A8D0 E0068000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 36A8D4 E0068004 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 36A8D8 E0068008 4485B000 */  mtc1      $a1, $f22
/* 36A8DC E006800C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 36A8E0 E0068010 4486C000 */  mtc1      $a2, $f24
/* 36A8E4 E0068014 AFB1002C */  sw        $s1, 0x2c($sp)
/* 36A8E8 E0068018 0080882D */  daddu     $s1, $a0, $zero
/* 36A8EC E006801C F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 36A8F0 E0068020 4487D000 */  mtc1      $a3, $f26
/* 36A8F4 E0068024 27A40010 */  addiu     $a0, $sp, 0x10
/* 36A8F8 E0068028 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 36A8FC E006802C C7B40068 */  lwc1      $f20, 0x68($sp)
/* 36A900 E0068030 3C02E007 */  lui       $v0, %hi(func_E0068140)
/* 36A904 E0068034 24428140 */  addiu     $v0, $v0, %lo(func_E0068140)
/* 36A908 E0068038 AFA20018 */  sw        $v0, 0x18($sp)
/* 36A90C E006803C 3C02E007 */  lui       $v0, %hi(func_E0068148)
/* 36A910 E0068040 24428148 */  addiu     $v0, $v0, %lo(func_E0068148)
/* 36A914 E0068044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 36A918 E0068048 3C02E007 */  lui       $v0, %hi(func_E00681D8)
/* 36A91C E006804C 244281D8 */  addiu     $v0, $v0, %lo(func_E00681D8)
/* 36A920 E0068050 AFA20020 */  sw        $v0, 0x20($sp)
/* 36A924 E0068054 24020034 */  addiu     $v0, $zero, 0x34
/* 36A928 E0068058 AFBF0030 */  sw        $ra, 0x30($sp)
/* 36A92C E006805C AFB00028 */  sw        $s0, 0x28($sp)
/* 36A930 E0068060 AFA00010 */  sw        $zero, 0x10($sp)
/* 36A934 E0068064 AFA00024 */  sw        $zero, 0x24($sp)
/* 36A938 E0068068 0C080124 */  jal       func_E0200490
/* 36A93C E006806C AFA20014 */   sw       $v0, 0x14($sp)
/* 36A940 E0068070 2404002C */  addiu     $a0, $zero, 0x2c
/* 36A944 E0068074 24030001 */  addiu     $v1, $zero, 1
/* 36A948 E0068078 0040802D */  daddu     $s0, $v0, $zero
/* 36A94C E006807C 0C08012C */  jal       func_E02004B0
/* 36A950 E0068080 AE030008 */   sw       $v1, 8($s0)
/* 36A954 E0068084 0040202D */  daddu     $a0, $v0, $zero
/* 36A958 E0068088 14800003 */  bnez      $a0, .LE0068098
/* 36A95C E006808C AE02000C */   sw       $v0, 0xc($s0)
.LE0068090:
/* 36A960 E0068090 0801A024 */  j         .LE0068090
/* 36A964 E0068094 00000000 */   nop
.LE0068098:
/* 36A968 E0068098 240300FF */  addiu     $v1, $zero, 0xff
/* 36A96C E006809C 24020064 */  addiu     $v0, $zero, 0x64
/* 36A970 E00680A0 AC910000 */  sw        $s1, ($a0)
/* 36A974 E00680A4 E4960004 */  swc1      $f22, 4($a0)
/* 36A978 E00680A8 E4980008 */  swc1      $f24, 8($a0)
/* 36A97C E00680AC E49A000C */  swc1      $f26, 0xc($a0)
/* 36A980 E00680B0 AC830018 */  sw        $v1, 0x18($a0)
/* 36A984 E00680B4 E4940014 */  swc1      $f20, 0x14($a0)
/* 36A988 E00680B8 E4940010 */  swc1      $f20, 0x10($a0)
/* 36A98C E00680BC AC82001C */  sw        $v0, 0x1c($a0)
/* 36A990 E00680C0 0620000B */  bltz      $s1, .LE00680F0
/* 36A994 E00680C4 AC800020 */   sw       $zero, 0x20($a0)
/* 36A998 E00680C8 2A220002 */  slti      $v0, $s1, 2
/* 36A99C E00680CC 10400009 */  beqz      $v0, .LE00680F4
/* 36A9A0 E00680D0 240200FF */   addiu    $v0, $zero, 0xff
/* 36A9A4 E00680D4 A0800024 */  sb        $zero, 0x24($a0)
/* 36A9A8 E00680D8 A0800025 */  sb        $zero, 0x25($a0)
/* 36A9AC E00680DC A0800026 */  sb        $zero, 0x26($a0)
/* 36A9B0 E00680E0 A0830027 */  sb        $v1, 0x27($a0)
/* 36A9B4 E00680E4 A0830028 */  sb        $v1, 0x28($a0)
/* 36A9B8 E00680E8 0801A045 */  j         .LE0068114
/* 36A9BC E00680EC A0830029 */   sb       $v1, 0x29($a0)
.LE00680F0:
/* 36A9C0 E00680F0 240200FF */  addiu     $v0, $zero, 0xff
.LE00680F4:
/* 36A9C4 E00680F4 240300E1 */  addiu     $v1, $zero, 0xe1
/* 36A9C8 E00680F8 A0820024 */  sb        $v0, 0x24($a0)
/* 36A9CC E00680FC A0820025 */  sb        $v0, 0x25($a0)
/* 36A9D0 E0068100 A0820026 */  sb        $v0, 0x26($a0)
/* 36A9D4 E0068104 A0820028 */  sb        $v0, 0x28($a0)
/* 36A9D8 E0068108 240200EB */  addiu     $v0, $zero, 0xeb
/* 36A9DC E006810C A0830027 */  sb        $v1, 0x27($a0)
/* 36A9E0 E0068110 A0820029 */  sb        $v0, 0x29($a0)
.LE0068114:
/* 36A9E4 E0068114 8FA2006C */  lw        $v0, 0x6c($sp)
/* 36A9E8 E0068118 AC500000 */  sw        $s0, ($v0)
/* 36A9EC E006811C 8FBF0030 */  lw        $ra, 0x30($sp)
/* 36A9F0 E0068120 8FB1002C */  lw        $s1, 0x2c($sp)
/* 36A9F4 E0068124 8FB00028 */  lw        $s0, 0x28($sp)
/* 36A9F8 E0068128 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 36A9FC E006812C D7B80048 */  ldc1      $f24, 0x48($sp)
/* 36AA00 E0068130 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 36AA04 E0068134 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 36AA08 E0068138 03E00008 */  jr        $ra
/* 36AA0C E006813C 27BD0058 */   addiu    $sp, $sp, 0x58

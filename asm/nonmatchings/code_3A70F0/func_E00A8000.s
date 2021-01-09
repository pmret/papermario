.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A8000
/* 3A70F0 E00A8000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3A70F4 E00A8004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3A70F8 E00A8008 4485A000 */  mtc1      $a1, $f20
/* 3A70FC E00A800C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3A7100 E00A8010 0080882D */  daddu     $s1, $a0, $zero
/* 3A7104 E00A8014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3A7108 E00A8018 4486B000 */  mtc1      $a2, $f22
/* 3A710C E00A801C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A7110 E00A8020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3A7114 E00A8024 4487C000 */  mtc1      $a3, $f24
/* 3A7118 E00A8028 3C02E00B */  lui       $v0, %hi(func_E00A80FC)
/* 3A711C E00A802C 244280FC */  addiu     $v0, $v0, %lo(func_E00A80FC)
/* 3A7120 E00A8030 AFA20018 */  sw        $v0, 0x18($sp)
/* 3A7124 E00A8034 3C02E00B */  lui       $v0, %hi(func_E00A8104)
/* 3A7128 E00A8038 24428104 */  addiu     $v0, $v0, %lo(func_E00A8104)
/* 3A712C E00A803C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3A7130 E00A8040 3C02E00B */  lui       $v0, %hi(func_E00A82D4)
/* 3A7134 E00A8044 244282D4 */  addiu     $v0, $v0, %lo(func_E00A82D4)
/* 3A7138 E00A8048 AFA20020 */  sw        $v0, 0x20($sp)
/* 3A713C E00A804C 24020054 */  addiu     $v0, $zero, 0x54
/* 3A7140 E00A8050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3A7144 E00A8054 AFB00028 */  sw        $s0, 0x28($sp)
/* 3A7148 E00A8058 AFA00010 */  sw        $zero, 0x10($sp)
/* 3A714C E00A805C AFA00024 */  sw        $zero, 0x24($sp)
/* 3A7150 E00A8060 0C080124 */  jal       func_E0200490
/* 3A7154 E00A8064 AFA20014 */   sw       $v0, 0x14($sp)
/* 3A7158 E00A8068 2404010C */  addiu     $a0, $zero, 0x10c
/* 3A715C E00A806C 24030001 */  addiu     $v1, $zero, 1
/* 3A7160 E00A8070 0040802D */  daddu     $s0, $v0, $zero
/* 3A7164 E00A8074 0C08012C */  jal       func_E02004B0
/* 3A7168 E00A8078 AE030008 */   sw       $v1, 8($s0)
/* 3A716C E00A807C 14400003 */  bnez      $v0, .LE00A808C
/* 3A7170 E00A8080 AE02000C */   sw       $v0, 0xc($s0)
.LE00A8084:
/* 3A7174 E00A8084 0802A021 */  j         .LE00A8084
/* 3A7178 E00A8088 00000000 */   nop      
.LE00A808C:
/* 3A717C E00A808C 0000202D */  daddu     $a0, $zero, $zero
/* 3A7180 E00A8090 0040182D */  daddu     $v1, $v0, $zero
/* 3A7184 E00A8094 44800000 */  mtc1      $zero, $f0
/* 3A7188 E00A8098 24020064 */  addiu     $v0, $zero, 0x64
/* 3A718C E00A809C AC620004 */  sw        $v0, 4($v1)
/* 3A7190 E00A80A0 240200FF */  addiu     $v0, $zero, 0xff
/* 3A7194 E00A80A4 AC710000 */  sw        $s1, ($v1)
/* 3A7198 E00A80A8 AC620018 */  sw        $v0, 0x18($v1)
/* 3A719C E00A80AC E474000C */  swc1      $f20, 0xc($v1)
/* 3A71A0 E00A80B0 E4760010 */  swc1      $f22, 0x10($v1)
/* 3A71A4 E00A80B4 E4780014 */  swc1      $f24, 0x14($v1)
/* 3A71A8 E00A80B8 AC600008 */  sw        $zero, 8($v1)
.LE00A80BC:
/* 3A71AC E00A80BC AC60001C */  sw        $zero, 0x1c($v1)
/* 3A71B0 E00A80C0 E46000E4 */  swc1      $f0, 0xe4($v1)
/* 3A71B4 E00A80C4 E46000BC */  swc1      $f0, 0xbc($v1)
/* 3A71B8 E00A80C8 24840001 */  addiu     $a0, $a0, 1
/* 3A71BC E00A80CC 2882000A */  slti      $v0, $a0, 0xa
/* 3A71C0 E00A80D0 1440FFFA */  bnez      $v0, .LE00A80BC
/* 3A71C4 E00A80D4 24630004 */   addiu    $v1, $v1, 4
/* 3A71C8 E00A80D8 0200102D */  daddu     $v0, $s0, $zero
/* 3A71CC E00A80DC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3A71D0 E00A80E0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3A71D4 E00A80E4 8FB00028 */  lw        $s0, 0x28($sp)
/* 3A71D8 E00A80E8 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3A71DC E00A80EC D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3A71E0 E00A80F0 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3A71E4 E00A80F4 03E00008 */  jr        $ra
/* 3A71E8 E00A80F8 27BD0050 */   addiu    $sp, $sp, 0x50

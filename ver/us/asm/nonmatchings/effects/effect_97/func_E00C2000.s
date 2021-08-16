.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C2000
/* 3C11D0 E00C2000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3C11D4 E00C2004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3C11D8 E00C2008 4485A000 */  mtc1      $a1, $f20
/* 3C11DC E00C200C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3C11E0 E00C2010 4486B000 */  mtc1      $a2, $f22
/* 3C11E4 E00C2014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3C11E8 E00C2018 0080902D */  daddu     $s2, $a0, $zero
/* 3C11EC E00C201C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3C11F0 E00C2020 4487C000 */  mtc1      $a3, $f24
/* 3C11F4 E00C2024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3C11F8 E00C2028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3C11FC E00C202C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3C1200 E00C2030 3C02E00C */  lui       $v0, %hi(func_E00C2124)
/* 3C1204 E00C2034 24422124 */  addiu     $v0, $v0, %lo(func_E00C2124)
/* 3C1208 E00C2038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3C120C E00C203C 3C02E00C */  lui       $v0, %hi(func_E00C212C)
/* 3C1210 E00C2040 2442212C */  addiu     $v0, $v0, %lo(func_E00C212C)
/* 3C1214 E00C2044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3C1218 E00C2048 3C02E00C */  lui       $v0, %hi(func_E00C21CC)
/* 3C121C E00C204C 244221CC */  addiu     $v0, $v0, %lo(func_E00C21CC)
/* 3C1220 E00C2050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3C1224 E00C2054 24020061 */  addiu     $v0, $zero, 0x61
/* 3C1228 E00C2058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3C122C E00C205C AFB00028 */  sw        $s0, 0x28($sp)
/* 3C1230 E00C2060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3C1234 E00C2064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3C1238 E00C2068 0C080124 */  jal       func_E0200490
/* 3C123C E00C206C AFA20014 */   sw       $v0, 0x14($sp)
/* 3C1240 E00C2070 2404002C */  addiu     $a0, $zero, 0x2c
/* 3C1244 E00C2074 24030001 */  addiu     $v1, $zero, 1
/* 3C1248 E00C2078 0040802D */  daddu     $s0, $v0, $zero
/* 3C124C E00C207C 0C08012C */  jal       func_E02004B0
/* 3C1250 E00C2080 AE030008 */   sw       $v1, 8($s0)
/* 3C1254 E00C2084 0040202D */  daddu     $a0, $v0, $zero
/* 3C1258 E00C2088 14800003 */  bnez      $a0, .LE00C2098
/* 3C125C E00C208C AE02000C */   sw       $v0, 0xc($s0)
.LE00C2090:
/* 3C1260 E00C2090 08030824 */  j         .LE00C2090
/* 3C1264 E00C2094 00000000 */   nop
.LE00C2098:
/* 3C1268 E00C2098 AC920000 */  sw        $s2, ($a0)
/* 3C126C E00C209C 1E200004 */  bgtz      $s1, .LE00C20B0
/* 3C1270 E00C20A0 AC800014 */   sw       $zero, 0x14($a0)
/* 3C1274 E00C20A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3C1278 E00C20A8 0803082D */  j         .LE00C20B4
/* 3C127C E00C20AC AC820010 */   sw       $v0, 0x10($a0)
.LE00C20B0:
/* 3C1280 E00C20B0 AC910010 */  sw        $s1, 0x10($a0)
.LE00C20B4:
/* 3C1284 E00C20B4 0200102D */  daddu     $v0, $s0, $zero
/* 3C1288 E00C20B8 AC800024 */  sw        $zero, 0x24($a0)
/* 3C128C E00C20BC E4940004 */  swc1      $f20, 4($a0)
/* 3C1290 E00C20C0 E4960008 */  swc1      $f22, 8($a0)
/* 3C1294 E00C20C4 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3C1298 E00C20C8 3C01E00C */  lui       $at, %hi(D_E00C29A0)
/* 3C129C E00C20CC D42229A0 */  ldc1      $f2, %lo(D_E00C29A0)($at)
/* 3C12A0 E00C20D0 46000021 */  cvt.d.s   $f0, $f0
/* 3C12A4 E00C20D4 46220002 */  mul.d     $f0, $f0, $f2
/* 3C12A8 E00C20D8 00000000 */  nop
/* 3C12AC E00C20DC 24030046 */  addiu     $v1, $zero, 0x46
/* 3C12B0 E00C20E0 AC830018 */  sw        $v1, 0x18($a0)
/* 3C12B4 E00C20E4 240300B4 */  addiu     $v1, $zero, 0xb4
/* 3C12B8 E00C20E8 AC83001C */  sw        $v1, 0x1c($a0)
/* 3C12BC E00C20EC 24030078 */  addiu     $v1, $zero, 0x78
/* 3C12C0 E00C20F0 E498000C */  swc1      $f24, 0xc($a0)
/* 3C12C4 E00C20F4 AC830020 */  sw        $v1, 0x20($a0)
/* 3C12C8 E00C20F8 46200020 */  cvt.s.d   $f0, $f0
/* 3C12CC E00C20FC E4800028 */  swc1      $f0, 0x28($a0)
/* 3C12D0 E00C2100 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3C12D4 E00C2104 8FB20030 */  lw        $s2, 0x30($sp)
/* 3C12D8 E00C2108 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3C12DC E00C210C 8FB00028 */  lw        $s0, 0x28($sp)
/* 3C12E0 E00C2110 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3C12E4 E00C2114 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3C12E8 E00C2118 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3C12EC E00C211C 03E00008 */  jr        $ra
/* 3C12F0 E00C2120 27BD0050 */   addiu    $sp, $sp, 0x50

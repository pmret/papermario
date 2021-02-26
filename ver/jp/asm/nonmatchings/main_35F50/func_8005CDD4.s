.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005CDD4
/* 381D4 8005CDD4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 381D8 8005CDD8 C7A00048 */  lwc1      $f0, 0x48($sp)
/* 381DC 8005CDDC C7A2004C */  lwc1      $f2, 0x4c($sp)
/* 381E0 8005CDE0 AFBE0030 */  sw        $fp, 0x30($sp)
/* 381E4 8005CDE4 8FBE005C */  lw        $fp, 0x5c($sp)
/* 381E8 8005CDE8 AFB50024 */  sw        $s5, 0x24($sp)
/* 381EC 8005CDEC 3C15800E */  lui       $s5, %hi(D_800D91B0)
/* 381F0 8005CDF0 26B591B0 */  addiu     $s5, $s5, %lo(D_800D91B0)
/* 381F4 8005CDF4 AFBF0034 */  sw        $ra, 0x34($sp)
/* 381F8 8005CDF8 AFB7002C */  sw        $s7, 0x2c($sp)
/* 381FC 8005CDFC AFB60028 */  sw        $s6, 0x28($sp)
/* 38200 8005CE00 AFB40020 */  sw        $s4, 0x20($sp)
/* 38204 8005CE04 AFB3001C */  sw        $s3, 0x1c($sp)
/* 38208 8005CE08 AFB20018 */  sw        $s2, 0x18($sp)
/* 3820C 8005CE0C AFB10014 */  sw        $s1, 0x14($sp)
/* 38210 8005CE10 AFB00010 */  sw        $s0, 0x10($sp)
/* 38214 8005CE14 86A2000C */  lh        $v0, 0xc($s5)
/* 38218 8005CE18 2416FFFF */  addiu     $s6, $zero, -1
/* 3821C 8005CE1C 3C01800A */  lui       $at, %hi(D_800A204C)
/* 38220 8005CE20 AC27204C */  sw        $a3, %lo(D_800A204C)($at)
/* 38224 8005CE24 3C01800A */  lui       $at, %hi(D_800A2040)
/* 38228 8005CE28 E42C2040 */  swc1      $f12, %lo(D_800A2040)($at)
/* 3822C 8005CE2C 3C01800A */  lui       $at, %hi(D_800A2044)
/* 38230 8005CE30 E42E2044 */  swc1      $f14, %lo(D_800A2044)($at)
/* 38234 8005CE34 3C01800A */  lui       $at, %hi(D_800A2048)
/* 38238 8005CE38 AC262048 */  sw        $a2, %lo(D_800A2048)($at)
/* 3823C 8005CE3C 3C01800A */  lui       $at, %hi(D_800A2050)
/* 38240 8005CE40 E4202050 */  swc1      $f0, %lo(D_800A2050)($at)
/* 38244 8005CE44 3C01800A */  lui       $at, %hi(D_800A2054)
/* 38248 8005CE48 E4222054 */  swc1      $f2, %lo(D_800A2054)($at)
/* 3824C 8005CE4C C7C00000 */  lwc1      $f0, ($fp)
/* 38250 8005CE50 3C01800A */  lui       $at, %hi(D_800A2064)
/* 38254 8005CE54 E4202064 */  swc1      $f0, %lo(D_800A2064)($at)
/* 38258 8005CE58 18400022 */  blez      $v0, .L8005CEE4
/* 3825C 8005CE5C 0000982D */   daddu    $s3, $zero, $zero
/* 38260 8005CE60 3C170001 */  lui       $s7, 1
/* 38264 8005CE64 0260A02D */  daddu     $s4, $s3, $zero
.L8005CE68:
/* 38268 8005CE68 8EA20004 */  lw        $v0, 4($s5)
/* 3826C 8005CE6C 00549021 */  addu      $s2, $v0, $s4
/* 38270 8005CE70 8E420000 */  lw        $v0, ($s2)
/* 38274 8005CE74 00571024 */  and       $v0, $v0, $s7
/* 38278 8005CE78 14400015 */  bnez      $v0, .L8005CED0
/* 3827C 8005CE7C 00000000 */   nop
/* 38280 8005CE80 8643000A */  lh        $v1, 0xa($s2)
/* 38284 8005CE84 10600012 */  beqz      $v1, .L8005CED0
/* 38288 8005CE88 00000000 */   nop
/* 3828C 8005CE8C 8E420010 */  lw        $v0, 0x10($s2)
/* 38290 8005CE90 1040000F */  beqz      $v0, .L8005CED0
/* 38294 8005CE94 00000000 */   nop
/* 38298 8005CE98 8E51000C */  lw        $s1, 0xc($s2)
/* 3829C 8005CE9C 1860000C */  blez      $v1, .L8005CED0
/* 382A0 8005CEA0 0000802D */   daddu    $s0, $zero, $zero
/* 382A4 8005CEA4 0220202D */  daddu     $a0, $s1, $zero
.L8005CEA8:
/* 382A8 8005CEA8 8EA50000 */  lw        $a1, ($s5)
/* 382AC 8005CEAC 0C017053 */  jal       func_8005C14C
/* 382B0 8005CEB0 26310040 */   addiu    $s1, $s1, 0x40
/* 382B4 8005CEB4 54400001 */  bnel      $v0, $zero, .L8005CEBC
/* 382B8 8005CEB8 0260B02D */   daddu    $s6, $s3, $zero
.L8005CEBC:
/* 382BC 8005CEBC 8642000A */  lh        $v0, 0xa($s2)
/* 382C0 8005CEC0 26100001 */  addiu     $s0, $s0, 1
/* 382C4 8005CEC4 0202102A */  slt       $v0, $s0, $v0
/* 382C8 8005CEC8 1440FFF7 */  bnez      $v0, .L8005CEA8
/* 382CC 8005CECC 0220202D */   daddu    $a0, $s1, $zero
.L8005CED0:
/* 382D0 8005CED0 86A2000C */  lh        $v0, 0xc($s5)
/* 382D4 8005CED4 26730001 */  addiu     $s3, $s3, 1
/* 382D8 8005CED8 0262102A */  slt       $v0, $s3, $v0
/* 382DC 8005CEDC 1440FFE2 */  bnez      $v0, .L8005CE68
/* 382E0 8005CEE0 2694001C */   addiu    $s4, $s4, 0x1c
.L8005CEE4:
/* 382E4 8005CEE4 06C0001D */  bltz      $s6, .L8005CF5C
/* 382E8 8005CEE8 02C0102D */   daddu    $v0, $s6, $zero
/* 382EC 8005CEEC 3C01800A */  lui       $at, %hi(D_800A2058)
/* 382F0 8005CEF0 C4202058 */  lwc1      $f0, %lo(D_800A2058)($at)
/* 382F4 8005CEF4 8FA20050 */  lw        $v0, 0x50($sp)
/* 382F8 8005CEF8 E4400000 */  swc1      $f0, ($v0)
/* 382FC 8005CEFC 3C01800A */  lui       $at, %hi(D_800A205C)
/* 38300 8005CF00 C420205C */  lwc1      $f0, %lo(D_800A205C)($at)
/* 38304 8005CF04 8FA20054 */  lw        $v0, 0x54($sp)
/* 38308 8005CF08 E4400000 */  swc1      $f0, ($v0)
/* 3830C 8005CF0C 3C01800A */  lui       $at, %hi(D_800A2060)
/* 38310 8005CF10 C4202060 */  lwc1      $f0, %lo(D_800A2060)($at)
/* 38314 8005CF14 8FA20058 */  lw        $v0, 0x58($sp)
/* 38318 8005CF18 E4400000 */  swc1      $f0, ($v0)
/* 3831C 8005CF1C 3C01800A */  lui       $at, %hi(D_800A2064)
/* 38320 8005CF20 C4202064 */  lwc1      $f0, %lo(D_800A2064)($at)
/* 38324 8005CF24 E7C00000 */  swc1      $f0, ($fp)
/* 38328 8005CF28 3C01800A */  lui       $at, %hi(D_800A2068)
/* 3832C 8005CF2C C4202068 */  lwc1      $f0, %lo(D_800A2068)($at)
/* 38330 8005CF30 8FA20060 */  lw        $v0, 0x60($sp)
/* 38334 8005CF34 E4400000 */  swc1      $f0, ($v0)
/* 38338 8005CF38 3C01800A */  lui       $at, %hi(D_800A206C)
/* 3833C 8005CF3C C420206C */  lwc1      $f0, %lo(D_800A206C)($at)
/* 38340 8005CF40 8FA20064 */  lw        $v0, 0x64($sp)
/* 38344 8005CF44 E4400000 */  swc1      $f0, ($v0)
/* 38348 8005CF48 3C01800A */  lui       $at, %hi(D_800A2070)
/* 3834C 8005CF4C C4202070 */  lwc1      $f0, %lo(D_800A2070)($at)
/* 38350 8005CF50 8FA30068 */  lw        $v1, 0x68($sp)
/* 38354 8005CF54 02C0102D */  daddu     $v0, $s6, $zero
/* 38358 8005CF58 E4600000 */  swc1      $f0, ($v1)
.L8005CF5C:
/* 3835C 8005CF5C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 38360 8005CF60 8FBE0030 */  lw        $fp, 0x30($sp)
/* 38364 8005CF64 8FB7002C */  lw        $s7, 0x2c($sp)
/* 38368 8005CF68 8FB60028 */  lw        $s6, 0x28($sp)
/* 3836C 8005CF6C 8FB50024 */  lw        $s5, 0x24($sp)
/* 38370 8005CF70 8FB40020 */  lw        $s4, 0x20($sp)
/* 38374 8005CF74 8FB3001C */  lw        $s3, 0x1c($sp)
/* 38378 8005CF78 8FB20018 */  lw        $s2, 0x18($sp)
/* 3837C 8005CF7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 38380 8005CF80 8FB00010 */  lw        $s0, 0x10($sp)
/* 38384 8005CF84 03E00008 */  jr        $ra
/* 38388 8005CF88 27BD0038 */   addiu    $sp, $sp, 0x38

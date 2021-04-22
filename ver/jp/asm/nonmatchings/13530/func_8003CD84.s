.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003CD84
/* 18184 8003CD84 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 18188 8003CD88 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 1818C 8003CD8C 4486D000 */  mtc1      $a2, $f26
/* 18190 8003CD90 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 18194 8003CD94 46006606 */  mov.s     $f24, $f12
/* 18198 8003CD98 AFB20018 */  sw        $s2, 0x18($sp)
/* 1819C 8003CD9C 0000902D */  daddu     $s2, $zero, $zero
/* 181A0 8003CDA0 AFB10014 */  sw        $s1, 0x14($sp)
/* 181A4 8003CDA4 0240882D */  daddu     $s1, $s2, $zero
/* 181A8 8003CDA8 AFB40020 */  sw        $s4, 0x20($sp)
/* 181AC 8003CDAC 3C140400 */  lui       $s4, 0x400
/* 181B0 8003CDB0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 181B4 8003CDB4 3C138000 */  lui       $s3, 0x8000
/* 181B8 8003CDB8 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 181BC 8003CDBC 4487A000 */  mtc1      $a3, $f20
/* 181C0 8003CDC0 36730004 */  ori       $s3, $s3, 4
/* 181C4 8003CDC4 AFBF0024 */  sw        $ra, 0x24($sp)
/* 181C8 8003CDC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 181CC 8003CDCC F7B60030 */  sdc1      $f22, 0x30($sp)
/* 181D0 8003CDD0 4600A586 */  mov.s     $f22, $f20
.L8003CDD4:
/* 181D4 8003CDD4 3C03800A */  lui       $v1, %hi(D_8009E9A0)
/* 181D8 8003CDD8 8C63E9A0 */  lw        $v1, %lo(D_8009E9A0)($v1)
/* 181DC 8003CDDC 00111080 */  sll       $v0, $s1, 2
/* 181E0 8003CDE0 00431021 */  addu      $v0, $v0, $v1
/* 181E4 8003CDE4 8C500000 */  lw        $s0, ($v0)
/* 181E8 8003CDE8 5200001B */  beql      $s0, $zero, .L8003CE58
/* 181EC 8003CDEC 26310001 */   addiu    $s1, $s1, 1
/* 181F0 8003CDF0 8E030000 */  lw        $v1, ($s0)
/* 181F4 8003CDF4 50600018 */  beql      $v1, $zero, .L8003CE58
/* 181F8 8003CDF8 26310001 */   addiu    $s1, $s1, 1
/* 181FC 8003CDFC 00741024 */  and       $v0, $v1, $s4
/* 18200 8003CE00 50400015 */  beql      $v0, $zero, .L8003CE58
/* 18204 8003CE04 26310001 */   addiu    $s1, $s1, 1
/* 18208 8003CE08 00731024 */  and       $v0, $v1, $s3
/* 1820C 8003CE0C 54400012 */  bnel      $v0, $zero, .L8003CE58
/* 18210 8003CE10 26310001 */   addiu    $s1, $s1, 1
/* 18214 8003CE14 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 18218 8003CE18 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 1821C 8003CE1C 4406C000 */  mfc1      $a2, $f24
/* 18220 8003CE20 4407D000 */  mfc1      $a3, $f26
/* 18224 8003CE24 0C00A7A5 */  jal       func_80029E94
/* 18228 8003CE28 00000000 */   nop
/* 1822C 8003CE2C 46000005 */  abs.s     $f0, $f0
/* 18230 8003CE30 4616003E */  c.le.s    $f0, $f22
/* 18234 8003CE34 00000000 */  nop
/* 18238 8003CE38 45000007 */  bc1f      .L8003CE58
/* 1823C 8003CE3C 26310001 */   addiu    $s1, $s1, 1
/* 18240 8003CE40 4614003C */  c.lt.s    $f0, $f20
/* 18244 8003CE44 00000000 */  nop
/* 18248 8003CE48 45000003 */  bc1f      .L8003CE58
/* 1824C 8003CE4C 00000000 */   nop
/* 18250 8003CE50 46000506 */  mov.s     $f20, $f0
/* 18254 8003CE54 0200902D */  daddu     $s2, $s0, $zero
.L8003CE58:
/* 18258 8003CE58 2A220040 */  slti      $v0, $s1, 0x40
/* 1825C 8003CE5C 1440FFDD */  bnez      $v0, .L8003CDD4
/* 18260 8003CE60 0240102D */   daddu    $v0, $s2, $zero
/* 18264 8003CE64 8FBF0024 */  lw        $ra, 0x24($sp)
/* 18268 8003CE68 8FB40020 */  lw        $s4, 0x20($sp)
/* 1826C 8003CE6C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 18270 8003CE70 8FB20018 */  lw        $s2, 0x18($sp)
/* 18274 8003CE74 8FB10014 */  lw        $s1, 0x14($sp)
/* 18278 8003CE78 8FB00010 */  lw        $s0, 0x10($sp)
/* 1827C 8003CE7C D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 18280 8003CE80 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 18284 8003CE84 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 18288 8003CE88 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 1828C 8003CE8C 03E00008 */  jr        $ra
/* 18290 8003CE90 27BD0048 */   addiu    $sp, $sp, 0x48

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003C000
/* 34F4C0 E003C000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 34F4C4 E003C004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 34F4C8 E003C008 4485A000 */  mtc1      $a1, $f20
/* 34F4CC E003C00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 34F4D0 E003C010 4486B000 */  mtc1      $a2, $f22
/* 34F4D4 E003C014 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 34F4D8 E003C018 4487D000 */  mtc1      $a3, $f26
/* 34F4DC E003C01C AFB20030 */  sw        $s2, 0x30($sp)
/* 34F4E0 E003C020 8FB20080 */  lw        $s2, 0x80($sp)
/* 34F4E4 E003C024 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 34F4E8 E003C028 C7B80078 */  lwc1      $f24, 0x78($sp)
/* 34F4EC E003C02C AFB1002C */  sw        $s1, 0x2c($sp)
/* 34F4F0 E003C030 0080882D */  daddu     $s1, $a0, $zero
/* 34F4F4 E003C034 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 34F4F8 E003C038 C7BC007C */  lwc1      $f28, 0x7c($sp)
/* 34F4FC E003C03C 27A40010 */  addiu     $a0, $sp, 0x10
/* 34F500 E003C040 AFBF0038 */  sw        $ra, 0x38($sp)
/* 34F504 E003C044 AFB30034 */  sw        $s3, 0x34($sp)
/* 34F508 E003C048 AFB00028 */  sw        $s0, 0x28($sp)
/* 34F50C E003C04C 2A420015 */  slti      $v0, $s2, 0x15
/* 34F510 E003C050 14400002 */  bnez      $v0, .LE003C05C
/* 34F514 E003C054 0240802D */   daddu    $s0, $s2, $zero
/* 34F518 E003C058 24120014 */  addiu     $s2, $zero, 0x14
.LE003C05C:
/* 34F51C E003C05C 26520001 */  addiu     $s2, $s2, 1
/* 34F520 E003C060 3C02E004 */  lui       $v0, %hi(func_E003C23C)
/* 34F524 E003C064 2442C23C */  addiu     $v0, $v0, %lo(func_E003C23C)
/* 34F528 E003C068 AFA20018 */  sw        $v0, 0x18($sp)
/* 34F52C E003C06C 3C02E004 */  lui       $v0, %hi(func_E003C244)
/* 34F530 E003C070 2442C244 */  addiu     $v0, $v0, %lo(func_E003C244)
/* 34F534 E003C074 AFA2001C */  sw        $v0, 0x1c($sp)
/* 34F538 E003C078 3C02E004 */  lui       $v0, %hi(func_E003C474)
/* 34F53C E003C07C 2442C474 */  addiu     $v0, $v0, %lo(func_E003C474)
/* 34F540 E003C080 AFA20020 */  sw        $v0, 0x20($sp)
/* 34F544 E003C084 3C02E004 */  lui       $v0, %hi(func_E003C47C)
/* 34F548 E003C088 2442C47C */  addiu     $v0, $v0, %lo(func_E003C47C)
/* 34F54C E003C08C AFA20024 */  sw        $v0, 0x24($sp)
/* 34F550 E003C090 2402001E */  addiu     $v0, $zero, 0x1e
/* 34F554 E003C094 AFA00010 */  sw        $zero, 0x10($sp)
/* 34F558 E003C098 0C080124 */  jal       func_E0200490
/* 34F55C E003C09C AFA20014 */   sw       $v0, 0x14($sp)
/* 34F560 E003C0A0 00122180 */  sll       $a0, $s2, 6
/* 34F564 E003C0A4 0040982D */  daddu     $s3, $v0, $zero
/* 34F568 E003C0A8 0C08012C */  jal       func_E02004B0
/* 34F56C E003C0AC AE720008 */   sw       $s2, 8($s3)
/* 34F570 E003C0B0 0040182D */  daddu     $v1, $v0, $zero
/* 34F574 E003C0B4 14600003 */  bnez      $v1, .LE003C0C4
/* 34F578 E003C0B8 AE63000C */   sw       $v1, 0xc($s3)
.LE003C0BC:
/* 34F57C E003C0BC 0800F02F */  j         .LE003C0BC
/* 34F580 E003C0C0 00000000 */   nop      
.LE003C0C4:
/* 34F584 E003C0C4 24020064 */  addiu     $v0, $zero, 0x64
/* 34F588 E003C0C8 AC710000 */  sw        $s1, ($v1)
/* 34F58C E003C0CC E4740004 */  swc1      $f20, 4($v1)
/* 34F590 E003C0D0 E4760008 */  swc1      $f22, 8($v1)
/* 34F594 E003C0D4 E47A000C */  swc1      $f26, 0xc($v1)
/* 34F598 E003C0D8 E4780028 */  swc1      $f24, 0x28($v1)
/* 34F59C E003C0DC AC620030 */  sw        $v0, 0x30($v1)
/* 34F5A0 E003C0E0 AC600034 */  sw        $zero, 0x34($v1)
/* 34F5A4 E003C0E4 AC70003C */  sw        $s0, 0x3c($v1)
/* 34F5A8 E003C0E8 24110001 */  addiu     $s1, $zero, 1
/* 34F5AC E003C0EC 0232102A */  slt       $v0, $s1, $s2
/* 34F5B0 E003C0F0 10400044 */  beqz      $v0, .LE003C204
/* 34F5B4 E003C0F4 24630040 */   addiu    $v1, $v1, 0x40
/* 34F5B8 E003C0F8 2470002C */  addiu     $s0, $v1, 0x2c
/* 34F5BC E003C0FC 44920000 */  mtc1      $s2, $f0
/* 34F5C0 E003C100 00000000 */  nop       
/* 34F5C4 E003C104 46800020 */  cvt.s.w   $f0, $f0
/* 34F5C8 E003C108 3C0141F0 */  lui       $at, 0x41f0
/* 34F5CC E003C10C 44811000 */  mtc1      $at, $f2
/* 34F5D0 E003C110 3C013FF8 */  lui       $at, 0x3ff8
/* 34F5D4 E003C114 4481B800 */  mtc1      $at, $f23
/* 34F5D8 E003C118 4480B000 */  mtc1      $zero, $f22
/* 34F5DC E003C11C 46001681 */  sub.s     $f26, $f2, $f0
.LE003C120:
/* 34F5E0 E003C120 001117C2 */  srl       $v0, $s1, 0x1f
/* 34F5E4 E003C124 02221021 */  addu      $v0, $s1, $v0
/* 34F5E8 E003C128 00021043 */  sra       $v0, $v0, 1
/* 34F5EC E003C12C 00021040 */  sll       $v0, $v0, 1
/* 34F5F0 E003C130 02221023 */  subu      $v0, $s1, $v0
/* 34F5F4 E003C134 00021040 */  sll       $v0, $v0, 1
/* 34F5F8 E003C138 AE00FFD8 */  sw        $zero, -0x28($s0)
/* 34F5FC E003C13C C600FFD8 */  lwc1      $f0, -0x28($s0)
/* 34F600 E003C140 2442FFFF */  addiu     $v0, $v0, -1
/* 34F604 E003C144 AE00FFDC */  sw        $zero, -0x24($s0)
/* 34F608 E003C148 00510018 */  mult      $v0, $s1
/* 34F60C E003C14C C602FFDC */  lwc1      $f2, -0x24($s0)
/* 34F610 E003C150 AE00FFE0 */  sw        $zero, -0x20($s0)
/* 34F614 E003C154 E600FFE4 */  swc1      $f0, -0x1c($s0)
/* 34F618 E003C158 00001012 */  mflo      $v0
/* 34F61C E003C15C 00021FC2 */  srl       $v1, $v0, 0x1f
/* 34F620 E003C160 00431021 */  addu      $v0, $v0, $v1
/* 34F624 E003C164 00021043 */  sra       $v0, $v0, 1
/* 34F628 E003C168 4482A000 */  mtc1      $v0, $f20
/* 34F62C E003C16C 00000000 */  nop       
/* 34F630 E003C170 4680A520 */  cvt.s.w   $f20, $f20
/* 34F634 E003C174 461AA502 */  mul.s     $f20, $f20, $f26
/* 34F638 E003C178 00000000 */  nop       
/* 34F63C E003C17C C600FFE0 */  lwc1      $f0, -0x20($s0)
/* 34F640 E003C180 E602FFE8 */  swc1      $f2, -0x18($s0)
/* 34F644 E003C184 3C013E4C */  lui       $at, 0x3e4c
/* 34F648 E003C188 3421CCCD */  ori       $at, $at, 0xcccd
/* 34F64C E003C18C 44811000 */  mtc1      $at, $f2
/* 34F650 E003C190 4614E500 */  add.s     $f20, $f28, $f20
/* 34F654 E003C194 E600FFEC */  swc1      $f0, -0x14($s0)
/* 34F658 E003C198 E602000C */  swc1      $f2, 0xc($s0)
/* 34F65C E003C19C 0C080140 */  jal       func_E0200500
/* 34F660 E003C1A0 4600A306 */   mov.s    $f12, $f20
/* 34F664 E003C1A4 46000007 */  neg.s     $f0, $f0
/* 34F668 E003C1A8 46180002 */  mul.s     $f0, $f0, $f24
/* 34F66C E003C1AC 00000000 */  nop       
/* 34F670 E003C1B0 46000021 */  cvt.d.s   $f0, $f0
/* 34F674 E003C1B4 46360002 */  mul.d     $f0, $f0, $f22
/* 34F678 E003C1B8 00000000 */  nop       
/* 34F67C E003C1BC 4600A306 */  mov.s     $f12, $f20
/* 34F680 E003C1C0 46200020 */  cvt.s.d   $f0, $f0
/* 34F684 E003C1C4 0C080144 */  jal       func_E0200510
/* 34F688 E003C1C8 E600FFF0 */   swc1     $f0, -0x10($s0)
/* 34F68C E003C1CC 46180002 */  mul.s     $f0, $f0, $f24
/* 34F690 E003C1D0 00000000 */  nop       
/* 34F694 E003C1D4 46000021 */  cvt.d.s   $f0, $f0
/* 34F698 E003C1D8 46360002 */  mul.d     $f0, $f0, $f22
/* 34F69C E003C1DC 00000000 */  nop       
/* 34F6A0 E003C1E0 26310001 */  addiu     $s1, $s1, 1
/* 34F6A4 E003C1E4 240200FF */  addiu     $v0, $zero, 0xff
/* 34F6A8 E003C1E8 AE020000 */  sw        $v0, ($s0)
/* 34F6AC E003C1EC 0232102A */  slt       $v0, $s1, $s2
/* 34F6B0 E003C1F0 AE00FFF8 */  sw        $zero, -8($s0)
/* 34F6B4 E003C1F4 46200020 */  cvt.s.d   $f0, $f0
/* 34F6B8 E003C1F8 E600FFF4 */  swc1      $f0, -0xc($s0)
/* 34F6BC E003C1FC 1440FFC8 */  bnez      $v0, .LE003C120
/* 34F6C0 E003C200 26100040 */   addiu    $s0, $s0, 0x40
.LE003C204:
/* 34F6C4 E003C204 8FA20084 */  lw        $v0, 0x84($sp)
/* 34F6C8 E003C208 AC530000 */  sw        $s3, ($v0)
/* 34F6CC E003C20C 8FBF0038 */  lw        $ra, 0x38($sp)
/* 34F6D0 E003C210 8FB30034 */  lw        $s3, 0x34($sp)
/* 34F6D4 E003C214 8FB20030 */  lw        $s2, 0x30($sp)
/* 34F6D8 E003C218 8FB1002C */  lw        $s1, 0x2c($sp)
/* 34F6DC E003C21C 8FB00028 */  lw        $s0, 0x28($sp)
/* 34F6E0 E003C220 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 34F6E4 E003C224 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 34F6E8 E003C228 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 34F6EC E003C22C D7B60048 */  ldc1      $f22, 0x48($sp)
/* 34F6F0 E003C230 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 34F6F4 E003C234 03E00008 */  jr        $ra
/* 34F6F8 E003C238 27BD0068 */   addiu    $sp, $sp, 0x68

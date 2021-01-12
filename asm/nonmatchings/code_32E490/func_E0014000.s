.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0014000
/* 32E490 E0014000 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 32E494 E0014004 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 32E498 E0014008 46006686 */  mov.s     $f26, $f12
/* 32E49C E001400C F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 32E4A0 E0014010 46007706 */  mov.s     $f28, $f14
/* 32E4A4 E0014014 27A40010 */  addiu     $a0, $sp, 0x10
/* 32E4A8 E0014018 F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 32E4AC E001401C 4486F000 */  mtc1      $a2, $f30
/* 32E4B0 E0014020 3C02E001 */  lui       $v0, %hi(func_E0014258)
/* 32E4B4 E0014024 24424258 */  addiu     $v0, $v0, %lo(func_E0014258)
/* 32E4B8 E0014028 AFA20018 */  sw        $v0, 0x18($sp)
/* 32E4BC E001402C 3C02E001 */  lui       $v0, %hi(func_E0014260)
/* 32E4C0 E0014030 24424260 */  addiu     $v0, $v0, %lo(func_E0014260)
/* 32E4C4 E0014034 AFA2001C */  sw        $v0, 0x1c($sp)
/* 32E4C8 E0014038 3C02E001 */  lui       $v0, %hi(func_E001449C)
/* 32E4CC E001403C 2442449C */  addiu     $v0, $v0, %lo(func_E001449C)
/* 32E4D0 E0014040 AFA20020 */  sw        $v0, 0x20($sp)
/* 32E4D4 E0014044 2402000A */  addiu     $v0, $zero, 0xa
/* 32E4D8 E0014048 AFBF003C */  sw        $ra, 0x3c($sp)
/* 32E4DC E001404C AFB40038 */  sw        $s4, 0x38($sp)
/* 32E4E0 E0014050 AFB30034 */  sw        $s3, 0x34($sp)
/* 32E4E4 E0014054 AFB20030 */  sw        $s2, 0x30($sp)
/* 32E4E8 E0014058 AFB1002C */  sw        $s1, 0x2c($sp)
/* 32E4EC E001405C AFB00028 */  sw        $s0, 0x28($sp)
/* 32E4F0 E0014060 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 32E4F4 E0014064 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 32E4F8 E0014068 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 32E4FC E001406C AFA7007C */  sw        $a3, 0x7c($sp)
/* 32E500 E0014070 AFA00010 */  sw        $zero, 0x10($sp)
/* 32E504 E0014074 AFA00024 */  sw        $zero, 0x24($sp)
/* 32E508 E0014078 0C080124 */  jal       func_E0200490
/* 32E50C E001407C AFA20014 */   sw       $v0, 0x14($sp)
/* 32E510 E0014080 24040260 */  addiu     $a0, $zero, 0x260
/* 32E514 E0014084 24140008 */  addiu     $s4, $zero, 8
/* 32E518 E0014088 0040802D */  daddu     $s0, $v0, $zero
/* 32E51C E001408C 0C08012C */  jal       func_E02004B0
/* 32E520 E0014090 AE140008 */   sw       $s4, 8($s0)
/* 32E524 E0014094 0040882D */  daddu     $s1, $v0, $zero
/* 32E528 E0014098 16200003 */  bnez      $s1, .LE00140A8
/* 32E52C E001409C AE11000C */   sw       $s1, 0xc($s0)
.LE00140A0:
/* 32E530 E00140A0 08005028 */  j         .LE00140A0
/* 32E534 E00140A4 00000000 */   nop
.LE00140A8:
/* 32E538 E00140A8 0220202D */  daddu     $a0, $s1, $zero
/* 32E53C E00140AC 00142880 */  sll       $a1, $s4, 2
/* 32E540 E00140B0 00B42821 */  addu      $a1, $a1, $s4
/* 32E544 E00140B4 00052880 */  sll       $a1, $a1, 2
/* 32E548 E00140B8 00B42823 */  subu      $a1, $a1, $s4
/* 32E54C E00140BC 0C080130 */  jal       func_E02004C0
/* 32E550 E00140C0 00052880 */   sll      $a1, $a1, 2
/* 32E554 E00140C4 12800056 */  beqz      $s4, .LE0014220
/* 32E558 E00140C8 0000902D */   daddu    $s2, $zero, $zero
/* 32E55C E00140CC 26300048 */  addiu     $s0, $s1, 0x48
/* 32E560 E00140D0 0240982D */  daddu     $s3, $s2, $zero
/* 32E564 E00140D4 3C013F80 */  lui       $at, 0x3f80
/* 32E568 E00140D8 4481C000 */  mtc1      $at, $f24
/* 32E56C E00140DC 3C01E001 */  lui       $at, %hi(D_E0014780)
/* 32E570 E00140E0 D4364780 */  ldc1      $f22, %lo(D_E0014780)($at)
.LE00140E4:
/* 32E574 E00140E4 2404000A */  addiu     $a0, $zero, 0xa
/* 32E578 E00140E8 24020001 */  addiu     $v0, $zero, 1
/* 32E57C E00140EC AE220000 */  sw        $v0, ($s1)
/* 32E580 E00140F0 240200FF */  addiu     $v0, $zero, 0xff
/* 32E584 E00140F4 AE00FFF8 */  sw        $zero, -8($s0)
/* 32E588 E00140F8 E61AFFC4 */  swc1      $f26, -0x3c($s0)
/* 32E58C E00140FC E61CFFC8 */  swc1      $f28, -0x38($s0)
/* 32E590 E0014100 E61EFFCC */  swc1      $f30, -0x34($s0)
/* 32E594 E0014104 E618FFD0 */  swc1      $f24, -0x30($s0)
/* 32E598 E0014108 E618FFD4 */  swc1      $f24, -0x2c($s0)
/* 32E59C E001410C E618FFD8 */  swc1      $f24, -0x28($s0)
/* 32E5A0 E0014110 0C080138 */  jal       func_E02004E0
/* 32E5A4 E0014114 A202FFC0 */   sb       $v0, -0x40($s0)
/* 32E5A8 E0014118 44820000 */  mtc1      $v0, $f0
/* 32E5AC E001411C 00000000 */  nop
/* 32E5B0 E0014120 46800021 */  cvt.d.w   $f0, $f0
/* 32E5B4 E0014124 46360002 */  mul.d     $f0, $f0, $f22
/* 32E5B8 E0014128 00000000 */  nop
/* 32E5BC E001412C 3C013FF0 */  lui       $at, 0x3ff0
/* 32E5C0 E0014130 44811800 */  mtc1      $at, $f3
/* 32E5C4 E0014134 44801000 */  mtc1      $zero, $f2
/* 32E5C8 E0014138 00000000 */  nop
/* 32E5CC E001413C 46220000 */  add.d     $f0, $f0, $f2
/* 32E5D0 E0014140 2404000A */  addiu     $a0, $zero, 0xa
/* 32E5D4 E0014144 46200020 */  cvt.s.d   $f0, $f0
/* 32E5D8 E0014148 0C080138 */  jal       func_E02004E0
/* 32E5DC E001414C E600FFDC */   swc1     $f0, -0x24($s0)
/* 32E5E0 E0014150 44820000 */  mtc1      $v0, $f0
/* 32E5E4 E0014154 00000000 */  nop
/* 32E5E8 E0014158 46800021 */  cvt.d.w   $f0, $f0
/* 32E5EC E001415C 46360002 */  mul.d     $f0, $f0, $f22
/* 32E5F0 E0014160 00000000 */  nop
/* 32E5F4 E0014164 3C01E001 */  lui       $at, %hi(D_E0014788)
/* 32E5F8 E0014168 D4224788 */  ldc1      $f2, %lo(D_E0014788)($at)
/* 32E5FC E001416C 26520001 */  addiu     $s2, $s2, 1
/* 32E600 E0014170 46220000 */  add.d     $f0, $f0, $f2
/* 32E604 E0014174 2631004C */  addiu     $s1, $s1, 0x4c
/* 32E608 E0014178 2404003C */  addiu     $a0, $zero, 0x3c
/* 32E60C E001417C 46200020 */  cvt.s.d   $f0, $f0
/* 32E610 E0014180 0C080000 */  jal       func_E0200000
/* 32E614 E0014184 E600FFE0 */   swc1     $f0, -0x20($s0)
/* 32E618 E0014188 44936000 */  mtc1      $s3, $f12
/* 32E61C E001418C 00000000 */  nop
/* 32E620 E0014190 46806320 */  cvt.s.w   $f12, $f12
/* 32E624 E0014194 2673002D */  addiu     $s3, $s3, 0x2d
/* 32E628 E0014198 C7A8007C */  lwc1      $f8, 0x7c($sp)
/* 32E62C E001419C 44820000 */  mtc1      $v0, $f0
/* 32E630 E00141A0 00000000 */  nop
/* 32E634 E00141A4 46800020 */  cvt.s.w   $f0, $f0
/* 32E638 E00141A8 E600FFE4 */  swc1      $f0, -0x1c($s0)
/* 32E63C E00141AC 3C013F00 */  lui       $at, 0x3f00
/* 32E640 E00141B0 44810000 */  mtc1      $at, $f0
/* 32E644 E00141B4 3C01BCA3 */  lui       $at, 0xbca3
/* 32E648 E00141B8 3421D70A */  ori       $at, $at, 0xd70a
/* 32E64C E00141BC 44811000 */  mtc1      $at, $f2
/* 32E650 E00141C0 3C013851 */  lui       $at, 0x3851
/* 32E654 E00141C4 3421B717 */  ori       $at, $at, 0xb717
/* 32E658 E00141C8 44812000 */  mtc1      $at, $f4
/* 32E65C E00141CC 3C01C079 */  lui       $at, 0xc079
/* 32E660 E00141D0 3421999A */  ori       $at, $at, 0x999a
/* 32E664 E00141D4 44813000 */  mtc1      $at, $f6
/* 32E668 E00141D8 2402001E */  addiu     $v0, $zero, 0x1e
/* 32E66C E00141DC A602FFBE */  sh        $v0, -0x42($s0)
/* 32E670 E00141E0 460C4300 */  add.s     $f12, $f8, $f12
/* 32E674 E00141E4 E600FFEC */  swc1      $f0, -0x14($s0)
/* 32E678 E00141E8 E602FFF0 */  swc1      $f2, -0x10($s0)
/* 32E67C E00141EC E604FFF4 */  swc1      $f4, -0xc($s0)
/* 32E680 E00141F0 0C08013C */  jal       func_E02004F0
/* 32E684 E00141F4 E606FFE8 */   swc1     $f6, -0x18($s0)
/* 32E688 E00141F8 46000506 */  mov.s     $f20, $f0
/* 32E68C E00141FC 0C080140 */  jal       func_E0200500
/* 32E690 E0014200 4600A306 */   mov.s    $f12, $f20
/* 32E694 E0014204 4600A306 */  mov.s     $f12, $f20
/* 32E698 E0014208 0C080144 */  jal       func_E0200510
/* 32E69C E001420C E600FFFC */   swc1     $f0, -4($s0)
/* 32E6A0 E0014210 E6000000 */  swc1      $f0, ($s0)
/* 32E6A4 E0014214 0254102A */  slt       $v0, $s2, $s4
/* 32E6A8 E0014218 1440FFB2 */  bnez      $v0, .LE00140E4
/* 32E6AC E001421C 2610004C */   addiu    $s0, $s0, 0x4c
.LE0014220:
/* 32E6B0 E0014220 8FBF003C */  lw        $ra, 0x3c($sp)
/* 32E6B4 E0014224 8FB40038 */  lw        $s4, 0x38($sp)
/* 32E6B8 E0014228 8FB30034 */  lw        $s3, 0x34($sp)
/* 32E6BC E001422C 8FB20030 */  lw        $s2, 0x30($sp)
/* 32E6C0 E0014230 8FB1002C */  lw        $s1, 0x2c($sp)
/* 32E6C4 E0014234 8FB00028 */  lw        $s0, 0x28($sp)
/* 32E6C8 E0014238 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 32E6CC E001423C D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 32E6D0 E0014240 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 32E6D4 E0014244 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 32E6D8 E0014248 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 32E6DC E001424C D7B40040 */  ldc1      $f20, 0x40($sp)
/* 32E6E0 E0014250 03E00008 */  jr        $ra
/* 32E6E4 E0014254 27BD0070 */   addiu    $sp, $sp, 0x70

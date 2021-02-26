.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80063B60
/* 3EF60 80063B60 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3EF64 80063B64 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* 3EF68 80063B68 C7BA0060 */  lwc1      $f26, 0x60($sp)
/* 3EF6C 80063B6C F7BC0040 */  sdc1      $f28, 0x40($sp)
/* 3EF70 80063B70 C7BC0064 */  lwc1      $f28, 0x64($sp)
/* 3EF74 80063B74 F7BE0048 */  sdc1      $f30, 0x48($sp)
/* 3EF78 80063B78 C7BE0068 */  lwc1      $f30, 0x68($sp)
/* 3EF7C 80063B7C F7B80030 */  sdc1      $f24, 0x30($sp)
/* 3EF80 80063B80 4486C000 */  mtc1      $a2, $f24
/* 3EF84 80063B84 AFB00010 */  sw        $s0, 0x10($sp)
/* 3EF88 80063B88 00808021 */  addu      $s0, $a0, $zero
/* 3EF8C 80063B8C AFB10014 */  sw        $s1, 0x14($sp)
/* 3EF90 80063B90 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 3EF94 80063B94 4487B000 */  mtc1      $a3, $f22
/* 3EF98 80063B98 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3EF9C 80063B9C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 3EFA0 80063BA0 0C019D20 */  jal       func_80067480
/* 3EFA4 80063BA4 00A08821 */   addu     $s1, $a1, $zero
/* 3EFA8 80063BA8 3C01800A */  lui       $at, %hi(D_80099B90)
/* 3EFAC 80063BAC D4229B90 */  ldc1      $f2, %lo(D_80099B90)($at)
/* 3EFB0 80063BB0 4600C021 */  cvt.d.s   $f0, $f24
/* 3EFB4 80063BB4 46220002 */  mul.d     $f0, $f0, $f2
/* 3EFB8 80063BB8 3C014000 */  lui       $at, 0x4000
/* 3EFBC 80063BBC 4481A000 */  mtc1      $at, $f20
/* 3EFC0 80063BC0 46200620 */  cvt.s.d   $f24, $f0
/* 3EFC4 80063BC4 4614C503 */  div.s     $f20, $f24, $f20
/* 3EFC8 80063BC8 0C00A864 */  jal       func_8002A190
/* 3EFCC 80063BCC 4600A306 */   mov.s    $f12, $f20
/* 3EFD0 80063BD0 4600A306 */  mov.s     $f12, $f20
/* 3EFD4 80063BD4 0C00A84B */  jal       func_8002A12C
/* 3EFD8 80063BD8 46000506 */   mov.s    $f20, $f0
/* 3EFDC 80063BDC 4600A503 */  div.s     $f20, $f20, $f0
/* 3EFE0 80063BE0 461CD100 */  add.s     $f4, $f26, $f28
/* 3EFE4 80063BE4 461CD081 */  sub.s     $f2, $f26, $f28
/* 3EFE8 80063BE8 46022103 */  div.s     $f4, $f4, $f2
/* 3EFEC 80063BEC 461AD000 */  add.s     $f0, $f26, $f26
/* 3EFF0 80063BF0 461C0002 */  mul.s     $f0, $f0, $f28
/* 3EFF4 80063BF4 46020003 */  div.s     $f0, $f0, $f2
/* 3EFF8 80063BF8 4616A583 */  div.s     $f22, $f20, $f22
/* 3EFFC 80063BFC 3C01BF80 */  lui       $at, 0xbf80
/* 3F000 80063C00 44811000 */  mtc1      $at, $f2
/* 3F004 80063C04 00002821 */  addu      $a1, $zero, $zero
/* 3F008 80063C08 AE00003C */  sw        $zero, 0x3c($s0)
/* 3F00C 80063C0C E602002C */  swc1      $f2, 0x2c($s0)
/* 3F010 80063C10 E6140014 */  swc1      $f20, 0x14($s0)
/* 3F014 80063C14 E6040028 */  swc1      $f4, 0x28($s0)
/* 3F018 80063C18 E6000038 */  swc1      $f0, 0x38($s0)
/* 3F01C 80063C1C E6160000 */  swc1      $f22, ($s0)
.L80063C20:
/* 3F020 80063C20 00002021 */  addu      $a0, $zero, $zero
/* 3F024 80063C24 02001821 */  addu      $v1, $s0, $zero
.L80063C28:
/* 3F028 80063C28 C4600000 */  lwc1      $f0, ($v1)
/* 3F02C 80063C2C 461E0002 */  mul.s     $f0, $f0, $f30
/* 3F030 80063C30 24840001 */  addiu     $a0, $a0, 1
/* 3F034 80063C34 28820004 */  slti      $v0, $a0, 4
/* 3F038 80063C38 E4600000 */  swc1      $f0, ($v1)
/* 3F03C 80063C3C 1440FFFA */  bnez      $v0, .L80063C28
/* 3F040 80063C40 24630004 */   addiu    $v1, $v1, 4
/* 3F044 80063C44 24A50001 */  addiu     $a1, $a1, 1
/* 3F048 80063C48 28A20004 */  slti      $v0, $a1, 4
/* 3F04C 80063C4C 1440FFF4 */  bnez      $v0, .L80063C20
/* 3F050 80063C50 26100010 */   addiu    $s0, $s0, 0x10
/* 3F054 80063C54 12200023 */  beqz      $s1, .L80063CE4
/* 3F058 80063C58 00000000 */   nop
/* 3F05C 80063C5C 461CD080 */  add.s     $f2, $f26, $f28
/* 3F060 80063C60 3C01800A */  lui       $at, %hi(D_80099B98)
/* 3F064 80063C64 D4209B98 */  ldc1      $f0, %lo(D_80099B98)($at)
/* 3F068 80063C68 460010A1 */  cvt.d.s   $f2, $f2
/* 3F06C 80063C6C 4620103E */  c.le.d    $f2, $f0
/* 3F070 80063C70 00000000 */  nop
/* 3F074 80063C74 00000000 */  nop
/* 3F078 80063C78 45010019 */  bc1t      .L80063CE0
/* 3F07C 80063C7C 3402FFFF */   ori      $v0, $zero, 0xffff
/* 3F080 80063C80 3C01800A */  lui       $at, %hi(D_80099BA0)
/* 3F084 80063C84 D4209BA0 */  ldc1      $f0, %lo(D_80099BA0)($at)
/* 3F088 80063C88 46220083 */  div.d     $f2, $f0, $f2
/* 3F08C 80063C8C 3C01800A */  lui       $at, %hi(D_80099BA8)
/* 3F090 80063C90 D4209BA8 */  ldc1      $f0, %lo(D_80099BA8)($at)
/* 3F094 80063C94 4622003E */  c.le.d    $f0, $f2
/* 3F098 80063C98 00000000 */  nop
/* 3F09C 80063C9C 00000000 */  nop
/* 3F0A0 80063CA0 45030006 */  bc1tl     .L80063CBC
/* 3F0A4 80063CA4 46201001 */   sub.d    $f0, $f2, $f0
/* 3F0A8 80063CA8 4620100D */  trunc.w.d $f0, $f2
/* 3F0AC 80063CAC 44030000 */  mfc1      $v1, $f0
/* 3F0B0 80063CB0 00000000 */  nop
/* 3F0B4 80063CB4 08018F34 */  j         .L80063CD0
/* 3F0B8 80063CB8 00601021 */   addu     $v0, $v1, $zero
.L80063CBC:
/* 3F0BC 80063CBC 4620008D */  trunc.w.d $f2, $f0
/* 3F0C0 80063CC0 44031000 */  mfc1      $v1, $f2
/* 3F0C4 80063CC4 3C028000 */  lui       $v0, 0x8000
/* 3F0C8 80063CC8 00621825 */  or        $v1, $v1, $v0
/* 3F0CC 80063CCC 00601021 */  addu      $v0, $v1, $zero
.L80063CD0:
/* 3F0D0 80063CD0 A6220000 */  sh        $v0, ($s1)
/* 3F0D4 80063CD4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3F0D8 80063CD8 14400002 */  bnez      $v0, .L80063CE4
/* 3F0DC 80063CDC 24020001 */   addiu    $v0, $zero, 1
.L80063CE0:
/* 3F0E0 80063CE0 A6220000 */  sh        $v0, ($s1)
.L80063CE4:
/* 3F0E4 80063CE4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3F0E8 80063CE8 8FB10014 */  lw        $s1, 0x14($sp)
/* 3F0EC 80063CEC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3F0F0 80063CF0 D7BE0048 */  ldc1      $f30, 0x48($sp)
/* 3F0F4 80063CF4 D7BC0040 */  ldc1      $f28, 0x40($sp)
/* 3F0F8 80063CF8 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* 3F0FC 80063CFC D7B80030 */  ldc1      $f24, 0x30($sp)
/* 3F100 80063D00 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 3F104 80063D04 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 3F108 80063D08 03E00008 */  jr        $ra
/* 3F10C 80063D0C 27BD0050 */   addiu    $sp, $sp, 0x50

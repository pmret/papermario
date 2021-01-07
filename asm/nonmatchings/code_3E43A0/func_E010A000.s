.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E010A000
/* 3E43A0 E010A000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3E43A4 E010A004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3E43A8 E010A008 4485A000 */  mtc1      $a1, $f20
/* 3E43AC E010A00C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3E43B0 E010A010 4486B000 */  mtc1      $a2, $f22
/* 3E43B4 E010A014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3E43B8 E010A018 0080902D */  daddu     $s2, $a0, $zero
/* 3E43BC E010A01C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3E43C0 E010A020 4487C000 */  mtc1      $a3, $f24
/* 3E43C4 E010A024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3E43C8 E010A028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3E43CC E010A02C 8FB10070 */  lw        $s1, 0x70($sp)
/* 3E43D0 E010A030 3C02E011 */  lui       $v0, %hi(D_E010A184)
/* 3E43D4 E010A034 2442A184 */  addiu     $v0, $v0, %lo(D_E010A184)
/* 3E43D8 E010A038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3E43DC E010A03C 3C02E011 */  lui       $v0, %hi(D_E010A18C)
/* 3E43E0 E010A040 2442A18C */  addiu     $v0, $v0, %lo(D_E010A18C)
/* 3E43E4 E010A044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3E43E8 E010A048 3C02E011 */  lui       $v0, %hi(D_E010A4A0)
/* 3E43EC E010A04C 2442A4A0 */  addiu     $v0, $v0, %lo(D_E010A4A0)
/* 3E43F0 E010A050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3E43F4 E010A054 24020077 */  addiu     $v0, $zero, 0x77
/* 3E43F8 E010A058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3E43FC E010A05C AFB00028 */  sw        $s0, 0x28($sp)
/* 3E4400 E010A060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3E4404 E010A064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3E4408 E010A068 0C080124 */  jal       func_E0200490
/* 3E440C E010A06C AFA20014 */   sw       $v0, 0x14($sp)
/* 3E4410 E010A070 240400B0 */  addiu     $a0, $zero, 0xb0
/* 3E4414 E010A074 24030001 */  addiu     $v1, $zero, 1
/* 3E4418 E010A078 0040802D */  daddu     $s0, $v0, $zero
/* 3E441C E010A07C 0C08012C */  jal       func_E02004B0
/* 3E4420 E010A080 AE030008 */   sw       $v1, 8($s0)
/* 3E4424 E010A084 0040202D */  daddu     $a0, $v0, $zero
/* 3E4428 E010A088 14800003 */  bnez      $a0, .LE010A098
/* 3E442C E010A08C AE02000C */   sw       $v0, 0xc($s0)
.LE010A090:
/* 3E4430 E010A090 08042824 */  j         .LE010A090
/* 3E4434 E010A094 00000000 */   nop      
.LE010A098:
/* 3E4438 E010A098 AC920000 */  sw        $s2, ($a0)
/* 3E443C E010A09C 1E200003 */  bgtz      $s1, .LE010A0AC
/* 3E4440 E010A0A0 AC800020 */   sw       $zero, 0x20($a0)
/* 3E4444 E010A0A4 0804282C */  j         .LE010A0B0
/* 3E4448 E010A0A8 240203E8 */   addiu    $v0, $zero, 0x3e8
.LE010A0AC:
/* 3E444C E010A0AC 26220020 */  addiu     $v0, $s1, 0x20
.LE010A0B0:
/* 3E4450 E010A0B0 AC82001C */  sw        $v0, 0x1c($a0)
/* 3E4454 E010A0B4 240300FF */  addiu     $v1, $zero, 0xff
/* 3E4458 E010A0B8 AC80004C */  sw        $zero, 0x4c($a0)
/* 3E445C E010A0BC AC830030 */  sw        $v1, 0x30($a0)
/* 3E4460 E010A0C0 E4940004 */  swc1      $f20, 4($a0)
/* 3E4464 E010A0C4 E4960008 */  swc1      $f22, 8($a0)
/* 3E4468 E010A0C8 E498000C */  swc1      $f24, 0xc($a0)
/* 3E446C E010A0CC AC800044 */  sw        $zero, 0x44($a0)
/* 3E4470 E010A0D0 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3E4474 E010A0D4 3C01447A */  lui       $at, 0x447a
/* 3E4478 E010A0D8 44811000 */  mtc1      $at, $f2
/* 3E447C E010A0DC E4800010 */  swc1      $f0, 0x10($a0)
/* 3E4480 E010A0E0 C7A00064 */  lwc1      $f0, 0x64($sp)
/* 3E4484 E010A0E4 0000302D */  daddu     $a2, $zero, $zero
/* 3E4488 E010A0E8 E4800014 */  swc1      $f0, 0x14($a0)
/* 3E448C E010A0EC C7A00068 */  lwc1      $f0, 0x68($sp)
/* 3E4490 E010A0F0 0080282D */  daddu     $a1, $a0, $zero
/* 3E4494 E010A0F4 E4800018 */  swc1      $f0, 0x18($a0)
/* 3E4498 E010A0F8 C7A0006C */  lwc1      $f0, 0x6c($sp)
/* 3E449C E010A0FC 24020064 */  addiu     $v0, $zero, 0x64
/* 3E44A0 E010A100 AC82002C */  sw        $v0, 0x2c($a0)
/* 3E44A4 E010A104 AC820038 */  sw        $v0, 0x38($a0)
/* 3E44A8 E010A108 24020096 */  addiu     $v0, $zero, 0x96
/* 3E44AC E010A10C AC830024 */  sw        $v1, 0x24($a0)
/* 3E44B0 E010A110 AC830028 */  sw        $v1, 0x28($a0)
/* 3E44B4 E010A114 AC830034 */  sw        $v1, 0x34($a0)
/* 3E44B8 E010A118 AC82003C */  sw        $v0, 0x3c($a0)
/* 3E44BC E010A11C AC830040 */  sw        $v1, 0x40($a0)
/* 3E44C0 E010A120 E4800048 */  swc1      $f0, 0x48($a0)
.LE010A124:
/* 3E44C4 E010A124 C4800004 */  lwc1      $f0, 4($a0)
/* 3E44C8 E010A128 E4A00050 */  swc1      $f0, 0x50($a1)
/* 3E44CC E010A12C C4800008 */  lwc1      $f0, 8($a0)
/* 3E44D0 E010A130 46020001 */  sub.s     $f0, $f0, $f2
/* 3E44D4 E010A134 24C60001 */  addiu     $a2, $a2, 1
/* 3E44D8 E010A138 E4A00060 */  swc1      $f0, 0x60($a1)
/* 3E44DC E010A13C C480000C */  lwc1      $f0, 0xc($a0)
/* 3E44E0 E010A140 28C20004 */  slti      $v0, $a2, 4
/* 3E44E4 E010A144 ACA00080 */  sw        $zero, 0x80($a1)
/* 3E44E8 E010A148 ACA00090 */  sw        $zero, 0x90($a1)
/* 3E44EC E010A14C ACA000A0 */  sw        $zero, 0xa0($a1)
/* 3E44F0 E010A150 E4A00070 */  swc1      $f0, 0x70($a1)
/* 3E44F4 E010A154 1440FFF3 */  bnez      $v0, .LE010A124
/* 3E44F8 E010A158 24A50004 */   addiu    $a1, $a1, 4
/* 3E44FC E010A15C 0200102D */  daddu     $v0, $s0, $zero
/* 3E4500 E010A160 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3E4504 E010A164 8FB20030 */  lw        $s2, 0x30($sp)
/* 3E4508 E010A168 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3E450C E010A16C 8FB00028 */  lw        $s0, 0x28($sp)
/* 3E4510 E010A170 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3E4514 E010A174 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3E4518 E010A178 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3E451C E010A17C 03E00008 */  jr        $ra
/* 3E4520 E010A180 27BD0050 */   addiu    $sp, $sp, 0x50

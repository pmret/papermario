.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0120000
/* 40B3F0 E0120000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 40B3F4 E0120004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 40B3F8 E0120008 4485A000 */  mtc1      $a1, $f20
/* 40B3FC E012000C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 40B400 E0120010 4486B000 */  mtc1      $a2, $f22
/* 40B404 E0120014 AFB20030 */  sw        $s2, 0x30($sp)
/* 40B408 E0120018 0080902D */  daddu     $s2, $a0, $zero
/* 40B40C E012001C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 40B410 E0120020 4487C000 */  mtc1      $a3, $f24
/* 40B414 E0120024 27A40010 */  addiu     $a0, $sp, 0x10
/* 40B418 E0120028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 40B41C E012002C 8FB10064 */  lw        $s1, 0x64($sp)
/* 40B420 E0120030 3C02E012 */  lui       $v0, %hi(D_E0120134)
/* 40B424 E0120034 24420134 */  addiu     $v0, $v0, %lo(D_E0120134)
/* 40B428 E0120038 AFA20018 */  sw        $v0, 0x18($sp)
/* 40B42C E012003C 3C02E012 */  lui       $v0, %hi(D_E012013C)
/* 40B430 E0120040 2442013C */  addiu     $v0, $v0, %lo(D_E012013C)
/* 40B434 E0120044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 40B438 E0120048 3C02E012 */  lui       $v0, %hi(D_E012039C)
/* 40B43C E012004C 2442039C */  addiu     $v0, $v0, %lo(D_E012039C)
/* 40B440 E0120050 AFA20020 */  sw        $v0, 0x20($sp)
/* 40B444 E0120054 24020082 */  addiu     $v0, $zero, 0x82
/* 40B448 E0120058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 40B44C E012005C AFB00028 */  sw        $s0, 0x28($sp)
/* 40B450 E0120060 AFA00010 */  sw        $zero, 0x10($sp)
/* 40B454 E0120064 AFA00024 */  sw        $zero, 0x24($sp)
/* 40B458 E0120068 0C080124 */  jal       func_E0200490
/* 40B45C E012006C AFA20014 */   sw       $v0, 0x14($sp)
/* 40B460 E0120070 24040040 */  addiu     $a0, $zero, 0x40
/* 40B464 E0120074 24030001 */  addiu     $v1, $zero, 1
/* 40B468 E0120078 0040802D */  daddu     $s0, $v0, $zero
/* 40B46C E012007C 0C08012C */  jal       func_E02004B0
/* 40B470 E0120080 AE030008 */   sw       $v1, 8($s0)
/* 40B474 E0120084 0040202D */  daddu     $a0, $v0, $zero
/* 40B478 E0120088 14800003 */  bnez      $a0, .LE0120098
/* 40B47C E012008C AE02000C */   sw       $v0, 0xc($s0)
.LE0120090:
/* 40B480 E0120090 08048024 */  j         .LE0120090
/* 40B484 E0120094 00000000 */   nop      
.LE0120098:
/* 40B488 E0120098 AC920000 */  sw        $s2, ($a0)
/* 40B48C E012009C 1E200004 */  bgtz      $s1, .LE01200B0
/* 40B490 E01200A0 AC800014 */   sw       $zero, 0x14($a0)
/* 40B494 E01200A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 40B498 E01200A8 0804802D */  j         .LE01200B4
/* 40B49C E01200AC AC820010 */   sw       $v0, 0x10($a0)
.LE01200B0:
/* 40B4A0 E01200B0 AC910010 */  sw        $s1, 0x10($a0)
.LE01200B4:
/* 40B4A4 E01200B4 24050004 */  addiu     $a1, $zero, 4
/* 40B4A8 E01200B8 24830010 */  addiu     $v1, $a0, 0x10
/* 40B4AC E01200BC E4940004 */  swc1      $f20, 4($a0)
/* 40B4B0 E01200C0 E4960008 */  swc1      $f22, 8($a0)
/* 40B4B4 E01200C4 E498000C */  swc1      $f24, 0xc($a0)
/* 40B4B8 E01200C8 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 40B4BC E01200CC 240200FF */  addiu     $v0, $zero, 0xff
/* 40B4C0 E01200D0 A0820018 */  sb        $v0, 0x18($a0)
/* 40B4C4 E01200D4 A0820019 */  sb        $v0, 0x19($a0)
/* 40B4C8 E01200D8 A082001A */  sb        $v0, 0x1a($a0)
/* 40B4CC E01200DC A082001B */  sb        $v0, 0x1b($a0)
/* 40B4D0 E01200E0 A082001C */  sb        $v0, 0x1c($a0)
/* 40B4D4 E01200E4 A082001D */  sb        $v0, 0x1d($a0)
/* 40B4D8 E01200E8 A082001E */  sb        $v0, 0x1e($a0)
/* 40B4DC E01200EC E4800034 */  swc1      $f0, 0x34($a0)
.LE01200F0:
/* 40B4E0 E01200F0 AC600020 */  sw        $zero, 0x20($v1)
/* 40B4E4 E01200F4 24A5FFFF */  addiu     $a1, $a1, -1
/* 40B4E8 E01200F8 04A1FFFD */  bgez      $a1, .LE01200F0
/* 40B4EC E01200FC 2463FFFC */   addiu    $v1, $v1, -4
/* 40B4F0 E0120100 0200102D */  daddu     $v0, $s0, $zero
/* 40B4F4 E0120104 240300FF */  addiu     $v1, $zero, 0xff
/* 40B4F8 E0120108 AC83003C */  sw        $v1, 0x3c($a0)
/* 40B4FC E012010C AC800038 */  sw        $zero, 0x38($a0)
/* 40B500 E0120110 8FBF0034 */  lw        $ra, 0x34($sp)
/* 40B504 E0120114 8FB20030 */  lw        $s2, 0x30($sp)
/* 40B508 E0120118 8FB1002C */  lw        $s1, 0x2c($sp)
/* 40B50C E012011C 8FB00028 */  lw        $s0, 0x28($sp)
/* 40B510 E0120120 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 40B514 E0120124 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 40B518 E0120128 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 40B51C E012012C 03E00008 */  jr        $ra
/* 40B520 E0120130 27BD0050 */   addiu    $sp, $sp, 0x50

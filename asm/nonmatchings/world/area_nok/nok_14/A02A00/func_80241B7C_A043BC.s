.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B7C_A043BC
/* A043BC 80241B7C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A043C0 80241B80 AFB00028 */  sw        $s0, 0x28($sp)
/* A043C4 80241B84 00A0802D */  daddu     $s0, $a1, $zero
/* A043C8 80241B88 AFB1002C */  sw        $s1, 0x2c($sp)
/* A043CC 80241B8C 00C0882D */  daddu     $s1, $a2, $zero
/* A043D0 80241B90 AFBF0034 */  sw        $ra, 0x34($sp)
/* A043D4 80241B94 AFB20030 */  sw        $s2, 0x30($sp)
/* A043D8 80241B98 AE200070 */  sw        $zero, 0x70($s1)
/* A043DC 80241B9C 8C830000 */  lw        $v1, ($a0)
/* A043E0 80241BA0 2402FDFF */  addiu     $v0, $zero, -0x201
/* A043E4 80241BA4 A480008E */  sh        $zero, 0x8e($a0)
/* A043E8 80241BA8 00621824 */  and       $v1, $v1, $v0
/* A043EC 80241BAC 34650800 */  ori       $a1, $v1, 0x800
/* A043F0 80241BB0 AC850000 */  sw        $a1, ($a0)
/* A043F4 80241BB4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* A043F8 80241BB8 8C420034 */  lw        $v0, 0x34($v0)
/* A043FC 80241BBC 10400003 */  beqz      $v0, .L80241BCC
/* A04400 80241BC0 00E0902D */   daddu    $s2, $a3, $zero
/* A04404 80241BC4 080906F5 */  j         .L80241BD4
/* A04408 80241BC8 34620808 */   ori      $v0, $v1, 0x808
.L80241BCC:
/* A0440C 80241BCC 2402FFF7 */  addiu     $v0, $zero, -9
/* A04410 80241BD0 00A21024 */  and       $v0, $a1, $v0
.L80241BD4:
/* A04414 80241BD4 AC820000 */  sw        $v0, ($a0)
/* A04418 80241BD8 27A20024 */  addiu     $v0, $sp, 0x24
/* A0441C 80241BDC 27A50018 */  addiu     $a1, $sp, 0x18
/* A04420 80241BE0 C4800038 */  lwc1      $f0, 0x38($a0)
/* A04424 80241BE4 C482003C */  lwc1      $f2, 0x3c($a0)
/* A04428 80241BE8 C4840040 */  lwc1      $f4, 0x40($a0)
/* A0442C 80241BEC 3C01447A */  lui       $at, 0x447a
/* A04430 80241BF0 44813000 */  mtc1      $at, $f6
/* A04434 80241BF4 27A6001C */  addiu     $a2, $sp, 0x1c
/* A04438 80241BF8 E7A00018 */  swc1      $f0, 0x18($sp)
/* A0443C 80241BFC E7A2001C */  swc1      $f2, 0x1c($sp)
/* A04440 80241C00 E7A40020 */  swc1      $f4, 0x20($sp)
/* A04444 80241C04 E7A60024 */  swc1      $f6, 0x24($sp)
/* A04448 80241C08 AFA20010 */  sw        $v0, 0x10($sp)
/* A0444C 80241C0C 8C840080 */  lw        $a0, 0x80($a0)
/* A04450 80241C10 0C0372DF */  jal       func_800DCB7C
/* A04454 80241C14 27A70020 */   addiu    $a3, $sp, 0x20
/* A04458 80241C18 C7A20024 */  lwc1      $f2, 0x24($sp)
/* A0445C 80241C1C 3C014059 */  lui       $at, 0x4059
/* A04460 80241C20 44812800 */  mtc1      $at, $f5
/* A04464 80241C24 44802000 */  mtc1      $zero, $f4
/* A04468 80241C28 460010A1 */  cvt.d.s   $f2, $f2
/* A0446C 80241C2C 46241082 */  mul.d     $f2, $f2, $f4
/* A04470 80241C30 00000000 */  nop       
/* A04474 80241C34 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A04478 80241C38 46000021 */  cvt.d.s   $f0, $f0
/* A0447C 80241C3C 46240002 */  mul.d     $f0, $f0, $f4
/* A04480 80241C40 00000000 */  nop       
/* A04484 80241C44 3C013FE0 */  lui       $at, 0x3fe0
/* A04488 80241C48 44812800 */  mtc1      $at, $f5
/* A0448C 80241C4C 44802000 */  mtc1      $zero, $f4
/* A04490 80241C50 00000000 */  nop       
/* A04494 80241C54 46241080 */  add.d     $f2, $f2, $f4
/* A04498 80241C58 AE000074 */  sw        $zero, 0x74($s0)
/* A0449C 80241C5C 46240000 */  add.d     $f0, $f0, $f4
/* A044A0 80241C60 AE000090 */  sw        $zero, 0x90($s0)
/* A044A4 80241C64 4620120D */  trunc.w.d $f8, $f2
/* A044A8 80241C68 E6080078 */  swc1      $f8, 0x78($s0)
/* A044AC 80241C6C 4620020D */  trunc.w.d $f8, $f0
/* A044B0 80241C70 E6080088 */  swc1      $f8, 0x88($s0)
/* A044B4 80241C74 8E420014 */  lw        $v0, 0x14($s2)
/* A044B8 80241C78 AE220074 */  sw        $v0, 0x74($s1)
/* A044BC 80241C7C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* A044C0 80241C80 34420010 */  ori       $v0, $v0, 0x10
/* A044C4 80241C84 AE0200B0 */  sw        $v0, 0xb0($s0)
/* A044C8 80241C88 8FBF0034 */  lw        $ra, 0x34($sp)
/* A044CC 80241C8C 8FB20030 */  lw        $s2, 0x30($sp)
/* A044D0 80241C90 8FB1002C */  lw        $s1, 0x2c($sp)
/* A044D4 80241C94 8FB00028 */  lw        $s0, 0x28($sp)
/* A044D8 80241C98 03E00008 */  jr        $ra
/* A044DC 80241C9C 27BD0038 */   addiu    $sp, $sp, 0x38

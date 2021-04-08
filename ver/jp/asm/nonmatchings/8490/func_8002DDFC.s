.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002DDFC
/* 91FC 8002DDFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9200 8002DE00 0080382D */  daddu     $a3, $a0, $zero
/* 9204 8002DE04 0000202D */  daddu     $a0, $zero, $zero
/* 9208 8002DE08 3C03800B */  lui       $v1, %hi(D_800B1D60)
/* 920C 8002DE0C 24631D60 */  addiu     $v1, $v1, %lo(D_800B1D60)
/* 9210 8002DE10 AFBF001C */  sw        $ra, 0x1c($sp)
/* 9214 8002DE14 AFB00018 */  sw        $s0, 0x18($sp)
.L8002DE18:
/* 9218 8002DE18 0060802D */  daddu     $s0, $v1, $zero
/* 921C 8002DE1C 96020000 */  lhu       $v0, ($s0)
/* 9220 8002DE20 10400006 */  beqz      $v0, .L8002DE3C
/* 9224 8002DE24 28820004 */   slti     $v0, $a0, 4
/* 9228 8002DE28 24840001 */  addiu     $a0, $a0, 1
/* 922C 8002DE2C 28820004 */  slti      $v0, $a0, 4
/* 9230 8002DE30 1440FFF9 */  bnez      $v0, .L8002DE18
/* 9234 8002DE34 26030558 */   addiu    $v1, $s0, 0x558
/* 9238 8002DE38 28820004 */  slti      $v0, $a0, 4
.L8002DE3C:
/* 923C 8002DE3C 54400003 */  bnel      $v0, $zero, .L8002DE4C
/* 9240 8002DE40 24030001 */   addiu    $v1, $zero, 1
.L8002DE44:
/* 9244 8002DE44 0800B791 */  j         .L8002DE44
/* 9248 8002DE48 00000000 */   nop
.L8002DE4C:
/* 924C 8002DE4C 94E20000 */  lhu       $v0, ($a3)
/* 9250 8002DE50 3C01C2C8 */  lui       $at, 0xc2c8
/* 9254 8002DE54 44810000 */  mtc1      $at, $f0
/* 9258 8002DE58 A6000002 */  sh        $zero, 2($s0)
/* 925C 8002DE5C AE00003C */  sw        $zero, 0x3c($s0)
/* 9260 8002DE60 AE000040 */  sw        $zero, 0x40($s0)
/* 9264 8002DE64 AE000044 */  sw        $zero, 0x44($s0)
/* 9268 8002DE68 AE000048 */  sw        $zero, 0x48($s0)
/* 926C 8002DE6C AE00004C */  sw        $zero, 0x4c($s0)
/* 9270 8002DE70 AE00006C */  sw        $zero, 0x6c($s0)
/* 9274 8002DE74 AE000078 */  sw        $zero, 0x78($s0)
/* 9278 8002DE78 AE00007C */  sw        $zero, 0x7c($s0)
/* 927C 8002DE7C AE000084 */  sw        $zero, 0x84($s0)
/* 9280 8002DE80 AE000088 */  sw        $zero, 0x88($s0)
/* 9284 8002DE84 AE00008C */  sw        $zero, 0x8c($s0)
/* 9288 8002DE88 34420005 */  ori       $v0, $v0, 5
/* 928C 8002DE8C A6020000 */  sh        $v0, ($s0)
/* 9290 8002DE90 E6000050 */  swc1      $f0, 0x50($s0)
/* 9294 8002DE94 90E20002 */  lbu       $v0, 2($a3)
/* 9298 8002DE98 A6030006 */  sh        $v1, 6($s0)
/* 929C 8002DE9C 00021600 */  sll       $v0, $v0, 0x18
/* 92A0 8002DEA0 00021603 */  sra       $v0, $v0, 0x18
/* 92A4 8002DEA4 A6020004 */  sh        $v0, 4($s0)
/* 92A8 8002DEA8 94E2000C */  lhu       $v0, 0xc($a3)
/* 92AC 8002DEAC A6020012 */  sh        $v0, 0x12($s0)
/* 92B0 8002DEB0 94E2000E */  lhu       $v0, 0xe($a3)
/* 92B4 8002DEB4 00042400 */  sll       $a0, $a0, 0x10
/* 92B8 8002DEB8 A6020014 */  sh        $v0, 0x14($s0)
/* 92BC 8002DEBC 84E30010 */  lh        $v1, 0x10($a3)
/* 92C0 8002DEC0 24020064 */  addiu     $v0, $zero, 0x64
/* 92C4 8002DEC4 A602002A */  sh        $v0, 0x2a($s0)
/* 92C8 8002DEC8 44830000 */  mtc1      $v1, $f0
/* 92CC 8002DECC 00000000 */  nop
/* 92D0 8002DED0 46800020 */  cvt.s.w   $f0, $f0
/* 92D4 8002DED4 E6000018 */  swc1      $f0, 0x18($s0)
/* 92D8 8002DED8 84E20006 */  lh        $v0, 6($a3)
/* 92DC 8002DEDC 84E50008 */  lh        $a1, 8($a3)
/* 92E0 8002DEE0 84E6000A */  lh        $a2, 0xa($a3)
/* 92E4 8002DEE4 84E70004 */  lh        $a3, 4($a3)
/* 92E8 8002DEE8 00042403 */  sra       $a0, $a0, 0x10
/* 92EC 8002DEEC 0C00B7E9 */  jal       func_8002DFA4
/* 92F0 8002DEF0 AFA20010 */   sw       $v0, 0x10($sp)
/* 92F4 8002DEF4 3C01447A */  lui       $at, 0x447a
/* 92F8 8002DEF8 44810000 */  mtc1      $at, $f0
/* 92FC 8002DEFC 3C013E4C */  lui       $at, 0x3e4c
/* 9300 8002DF00 3421CCCD */  ori       $at, $at, 0xcccd
/* 9304 8002DF04 44811000 */  mtc1      $at, $f2
/* 9308 8002DF08 3C013F80 */  lui       $at, 0x3f80
/* 930C 8002DF0C 44812000 */  mtc1      $at, $f4
/* 9310 8002DF10 2402FFFF */  addiu     $v0, $zero, -1
/* 9314 8002DF14 A6020212 */  sh        $v0, 0x212($s0)
/* 9318 8002DF18 24020001 */  addiu     $v0, $zero, 1
/* 931C 8002DF1C AE020530 */  sw        $v0, 0x530($s0)
/* 9320 8002DF20 0200102D */  daddu     $v0, $s0, $zero
/* 9324 8002DF24 A600002C */  sh        $zero, 0x2c($s0)
/* 9328 8002DF28 A600002E */  sh        $zero, 0x2e($s0)
/* 932C 8002DF2C A6000030 */  sh        $zero, 0x30($s0)
/* 9330 8002DF30 AE0000C0 */  sw        $zero, 0xc0($s0)
/* 9334 8002DF34 AE000054 */  sw        $zero, 0x54($s0)
/* 9338 8002DF38 AE000058 */  sw        $zero, 0x58($s0)
/* 933C 8002DF3C AE00005C */  sw        $zero, 0x5c($s0)
/* 9340 8002DF40 AE000060 */  sw        $zero, 0x60($s0)
/* 9344 8002DF44 AE000064 */  sw        $zero, 0x64($s0)
/* 9348 8002DF48 AE000068 */  sw        $zero, 0x68($s0)
/* 934C 8002DF4C AE000098 */  sw        $zero, 0x98($s0)
/* 9350 8002DF50 AE00009C */  sw        $zero, 0x9c($s0)
/* 9354 8002DF54 AE0001FC */  sw        $zero, 0x1fc($s0)
/* 9358 8002DF58 AE000200 */  sw        $zero, 0x200($s0)
/* 935C 8002DF5C AE00050C */  sw        $zero, 0x50c($s0)
/* 9360 8002DF60 AE000510 */  sw        $zero, 0x510($s0)
/* 9364 8002DF64 AE000514 */  sw        $zero, 0x514($s0)
/* 9368 8002DF68 AE000518 */  sw        $zero, 0x518($s0)
/* 936C 8002DF6C AE00051C */  sw        $zero, 0x51c($s0)
/* 9370 8002DF70 AE000524 */  sw        $zero, 0x524($s0)
/* 9374 8002DF74 AE000528 */  sw        $zero, 0x528($s0)
/* 9378 8002DF78 AE00052C */  sw        $zero, 0x52c($s0)
/* 937C 8002DF7C AE000534 */  sw        $zero, 0x534($s0)
/* 9380 8002DF80 A6000506 */  sh        $zero, 0x506($s0)
/* 9384 8002DF84 A6000504 */  sh        $zero, 0x504($s0)
/* 9388 8002DF88 E60000C4 */  swc1      $f0, 0xc4($s0)
/* 938C 8002DF8C E6020520 */  swc1      $f2, 0x520($s0)
/* 9390 8002DF90 E6040490 */  swc1      $f4, 0x490($s0)
/* 9394 8002DF94 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9398 8002DF98 8FB00018 */  lw        $s0, 0x18($sp)
/* 939C 8002DF9C 03E00008 */  jr        $ra
/* 93A0 8002DFA0 27BD0020 */   addiu    $sp, $sp, 0x20

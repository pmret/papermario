.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E2F60
/* 7C410 800E2F60 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 7C414 800E2F64 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 7C418 800E2F68 90A200B4 */  lbu       $v0, 0xb4($a1)
/* 7C41C 800E2F6C 2442FFFD */  addiu     $v0, $v0, -3
/* 7C420 800E2F70 00021600 */  sll       $v0, $v0, 0x18
/* 7C424 800E2F74 00021E03 */  sra       $v1, $v0, 0x18
/* 7C428 800E2F78 2C620015 */  sltiu     $v0, $v1, 0x15
/* 7C42C 800E2F7C 10400039 */  beqz      $v0, L800E3064_7C514
/* 7C430 800E2F80 00031080 */   sll      $v0, $v1, 2
/* 7C434 800E2F84 3C018011 */  lui       $at, %hi(jtbl_8010BDE8)
/* 7C438 800E2F88 00220821 */  addu      $at, $at, $v0
/* 7C43C 800E2F8C 8C22BDE8 */  lw        $v0, %lo(jtbl_8010BDE8)($at)
/* 7C440 800E2F90 00400008 */  jr        $v0
/* 7C444 800E2F94 00000000 */   nop
glabel L800E2F98_7C448
/* 7C448 800E2F98 3C014120 */  lui       $at, 0x4120
/* 7C44C 800E2F9C 44810000 */  mtc1      $at, $f0
/* 7C450 800E2FA0 3C01C0A0 */  lui       $at, 0xc0a0
/* 7C454 800E2FA4 44811000 */  mtc1      $at, $f2
/* 7C458 800E2FA8 3C013FC0 */  lui       $at, 0x3fc0
/* 7C45C 800E2FAC 44812000 */  mtc1      $at, $f4
/* 7C460 800E2FB0 3C01BE99 */  lui       $at, 0xbe99
/* 7C464 800E2FB4 3421999A */  ori       $at, $at, 0x999a
/* 7C468 800E2FB8 44813000 */  mtc1      $at, $f6
/* 7C46C 800E2FBC E4A00070 */  swc1      $f0, 0x70($a1)
/* 7C470 800E2FC0 E4A20074 */  swc1      $f2, 0x74($a1)
/* 7C474 800E2FC4 E4A40078 */  swc1      $f4, 0x78($a1)
/* 7C478 800E2FC8 03E00008 */  jr        $ra
/* 7C47C 800E2FCC E4A6007C */   swc1     $f6, 0x7c($a1)
glabel L800E2FD0_7C480
/* 7C480 800E2FD0 3C04800F */  lui       $a0, %hi(D_800F7B50)
/* 7C484 800E2FD4 24847B50 */  addiu     $a0, $a0, %lo(D_800F7B50)
/* 7C488 800E2FD8 8CA20000 */  lw        $v0, ($a1)
/* 7C48C 800E2FDC 3C030004 */  lui       $v1, 4
/* 7C490 800E2FE0 00431024 */  and       $v0, $v0, $v1
/* 7C494 800E2FE4 1440000C */  bnez      $v0, .L800E3018
/* 7C498 800E2FE8 0080302D */   daddu    $a2, $a0, $zero
/* 7C49C 800E2FEC C4800000 */  lwc1      $f0, ($a0)
/* 7C4A0 800E2FF0 24840004 */  addiu     $a0, $a0, 4
/* 7C4A4 800E2FF4 E4A00070 */  swc1      $f0, 0x70($a1)
/* 7C4A8 800E2FF8 C4800000 */  lwc1      $f0, ($a0)
/* 7C4AC 800E2FFC 24840004 */  addiu     $a0, $a0, 4
/* 7C4B0 800E3000 E4A00074 */  swc1      $f0, 0x74($a1)
/* 7C4B4 800E3004 C4800000 */  lwc1      $f0, ($a0)
/* 7C4B8 800E3008 E4A00078 */  swc1      $f0, 0x78($a1)
/* 7C4BC 800E300C C4800004 */  lwc1      $f0, 4($a0)
/* 7C4C0 800E3010 03E00008 */  jr        $ra
/* 7C4C4 800E3014 E4A0007C */   swc1     $f0, 0x7c($a1)
.L800E3018:
/* 7C4C8 800E3018 C4880000 */  lwc1      $f8, ($a0)
/* 7C4CC 800E301C 3C013F00 */  lui       $at, 0x3f00
/* 7C4D0 800E3020 44811000 */  mtc1      $at, $f2
/* 7C4D4 800E3024 00000000 */  nop
/* 7C4D8 800E3028 46024202 */  mul.s     $f8, $f8, $f2
/* 7C4DC 800E302C 00000000 */  nop
/* 7C4E0 800E3030 C4C60004 */  lwc1      $f6, 4($a2)
/* 7C4E4 800E3034 46023182 */  mul.s     $f6, $f6, $f2
/* 7C4E8 800E3038 00000000 */  nop
/* 7C4EC 800E303C C4C40008 */  lwc1      $f4, 8($a2)
/* 7C4F0 800E3040 46022102 */  mul.s     $f4, $f4, $f2
/* 7C4F4 800E3044 00000000 */  nop
/* 7C4F8 800E3048 C4C0000C */  lwc1      $f0, 0xc($a2)
/* 7C4FC 800E304C 46020002 */  mul.s     $f0, $f0, $f2
/* 7C500 800E3050 00000000 */  nop
/* 7C504 800E3054 E4A80070 */  swc1      $f8, 0x70($a1)
/* 7C508 800E3058 E4A60074 */  swc1      $f6, 0x74($a1)
/* 7C50C 800E305C E4A40078 */  swc1      $f4, 0x78($a1)
/* 7C510 800E3060 E4A0007C */  swc1      $f0, 0x7c($a1)
glabel L800E3064_7C514
/* 7C514 800E3064 03E00008 */  jr        $ra
/* 7C518 800E3068 00000000 */   nop

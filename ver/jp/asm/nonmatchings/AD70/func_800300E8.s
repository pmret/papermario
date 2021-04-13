.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800300E8
/* B4E8 800300E8 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* B4EC 800300EC 3C0146FF */  lui       $at, 0x46ff
/* B4F0 800300F0 3421FE00 */  ori       $at, $at, 0xfe00
/* B4F4 800300F4 44811000 */  mtc1      $at, $f2
/* B4F8 800300F8 44802000 */  mtc1      $zero, $f4
/* B4FC 800300FC 3C01BF80 */  lui       $at, 0xbf80
/* B500 80030100 44810000 */  mtc1      $at, $f0
/* B504 80030104 44072000 */  mfc1      $a3, $f4
/* B508 80030108 27A20038 */  addiu     $v0, $sp, 0x38
/* B50C 8003010C AFBF0058 */  sw        $ra, 0x58($sp)
/* B510 80030110 E7A20044 */  swc1      $f2, 0x44($sp)
/* B514 80030114 AFA20018 */  sw        $v0, 0x18($sp)
/* B518 80030118 27A2003C */  addiu     $v0, $sp, 0x3c
/* B51C 8003011C AFA2001C */  sw        $v0, 0x1c($sp)
/* B520 80030120 27A20040 */  addiu     $v0, $sp, 0x40
/* B524 80030124 AFA20020 */  sw        $v0, 0x20($sp)
/* B528 80030128 27A20044 */  addiu     $v0, $sp, 0x44
/* B52C 8003012C AFA20024 */  sw        $v0, 0x24($sp)
/* B530 80030130 27A20048 */  addiu     $v0, $sp, 0x48
/* B534 80030134 AFA20028 */  sw        $v0, 0x28($sp)
/* B538 80030138 27A2004C */  addiu     $v0, $sp, 0x4c
/* B53C 8003013C AFA2002C */  sw        $v0, 0x2c($sp)
/* B540 80030140 27A20050 */  addiu     $v0, $sp, 0x50
/* B544 80030144 E7A00010 */  swc1      $f0, 0x10($sp)
/* B548 80030148 E7A40014 */  swc1      $f4, 0x14($sp)
/* B54C 8003014C 0C017375 */  jal       func_8005CDD4
/* B550 80030150 AFA20030 */   sw       $v0, 0x30($sp)
/* B554 80030154 0040182D */  daddu     $v1, $v0, $zero
/* B558 80030158 04600008 */  bltz      $v1, .L8003017C
/* B55C 8003015C 000310C0 */   sll      $v0, $v1, 3
/* B560 80030160 00431023 */  subu      $v0, $v0, $v1
/* B564 80030164 3C03800E */  lui       $v1, %hi(D_800D91B4)
/* B568 80030168 8C6391B4 */  lw        $v1, %lo(D_800D91B4)($v1)
/* B56C 8003016C 00021080 */  sll       $v0, $v0, 2
/* B570 80030170 00431021 */  addu      $v0, $v0, $v1
/* B574 80030174 0800C060 */  j         .L80030180
/* B578 80030178 8C420010 */   lw       $v0, 0x10($v0)
.L8003017C:
/* B57C 8003017C 0000102D */  daddu     $v0, $zero, $zero
.L80030180:
/* B580 80030180 8FBF0058 */  lw        $ra, 0x58($sp)
/* B584 80030184 03E00008 */  jr        $ra
/* B588 80030188 27BD0060 */   addiu    $sp, $sp, 0x60

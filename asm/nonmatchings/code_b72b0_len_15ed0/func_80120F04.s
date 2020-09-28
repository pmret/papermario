.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80120F04
/* B7604 80120F04 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B7608 80120F08 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B760C 80120F0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B7610 80120F10 AFBF0014 */  sw        $ra, 0x14($sp)
/* B7614 80120F14 AFB00010 */  sw        $s0, 0x10($sp)
/* B7618 80120F18 80420070 */  lb        $v0, 0x70($v0)
/* B761C 80120F1C 10400003 */  beqz      $v0, .L80120F2C
/* B7620 80120F20 30820800 */   andi     $v0, $a0, 0x800
/* B7624 80120F24 10400020 */  beqz      $v0, .L80120FA8
/* B7628 80120F28 00000000 */   nop      
.L80120F2C:
/* B762C 80120F2C 2402F7FF */  addiu     $v0, $zero, -0x801
/* B7630 80120F30 00822024 */  and       $a0, $a0, $v0
/* B7634 80120F34 3C038015 */  lui       $v1, 0x8015
/* B7638 80120F38 8C634370 */  lw        $v1, 0x4370($v1)
/* B763C 80120F3C 00041080 */  sll       $v0, $a0, 2
/* B7640 80120F40 00431021 */  addu      $v0, $v0, $v1
/* B7644 80120F44 8C500000 */  lw        $s0, ($v0)
/* B7648 80120F48 12000017 */  beqz      $s0, .L80120FA8
/* B764C 80120F4C 00000000 */   nop      
/* B7650 80120F50 8E030000 */  lw        $v1, ($s0)
/* B7654 80120F54 10600014 */  beqz      $v1, .L80120FA8
/* B7658 80120F58 30620020 */   andi     $v0, $v1, 0x20
/* B765C 80120F5C 14400012 */  bnez      $v0, .L80120FA8
/* B7660 80120F60 3C020002 */   lui      $v0, 2
/* B7664 80120F64 00621024 */  and       $v0, $v1, $v0
/* B7668 80120F68 1440000F */  bnez      $v0, .L80120FA8
/* B766C 80120F6C 2402FEFF */   addiu    $v0, $zero, -0x101
/* B7670 80120F70 C6000008 */  lwc1      $f0, 8($s0)
/* B7674 80120F74 C602000C */  lwc1      $f2, 0xc($s0)
/* B7678 80120F78 46020001 */  sub.s     $f0, $f0, $f2
/* B767C 80120F7C 44801000 */  mtc1      $zero, $f2
/* B7680 80120F80 00621024 */  and       $v0, $v1, $v0
/* B7684 80120F84 AE020000 */  sw        $v0, ($s0)
/* B7688 80120F88 4602003E */  c.le.s    $f0, $f2
/* B768C 80120F8C 00000000 */  nop       
/* B7690 80120F90 45000005 */  bc1f      .L80120FA8
/* B7694 80120F94 E6000008 */   swc1     $f0, 8($s0)
.L80120F98:
/* B7698 80120F98 0C0483EE */  jal       func_80120FB8
/* B769C 80120F9C 0200202D */   daddu    $a0, $s0, $zero
/* B76A0 80120FA0 1440FFFD */  bnez      $v0, .L80120F98
/* B76A4 80120FA4 00000000 */   nop      
.L80120FA8:
/* B76A8 80120FA8 8FBF0014 */  lw        $ra, 0x14($sp)
/* B76AC 80120FAC 8FB00010 */  lw        $s0, 0x10($sp)
/* B76B0 80120FB0 03E00008 */  jr        $ra
/* B76B4 80120FB4 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetEnemyHP
/* 1AAEA8 8027C5C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1AAEAC 8027C5CC AFB20018 */  sw        $s2, 0x18($sp)
/* 1AAEB0 8027C5D0 0080902D */  daddu     $s2, $a0, $zero
/* 1AAEB4 8027C5D4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1AAEB8 8027C5D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AAEBC 8027C5DC AFB00010 */  sw        $s0, 0x10($sp)
/* 1AAEC0 8027C5E0 8E51000C */  lw        $s1, 0xc($s2)
/* 1AAEC4 8027C5E4 8E250000 */  lw        $a1, ($s1)
/* 1AAEC8 8027C5E8 0C0B1EAF */  jal       get_variable
/* 1AAECC 8027C5EC 26310004 */   addiu    $s1, $s1, 4
/* 1AAED0 8027C5F0 0040802D */  daddu     $s0, $v0, $zero
/* 1AAED4 8027C5F4 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1AAED8 8027C5F8 16020002 */  bne       $s0, $v0, .L8027C604
/* 1AAEDC 8027C5FC 00000000 */   nop      
/* 1AAEE0 8027C600 8E500148 */  lw        $s0, 0x148($s2)
.L8027C604:
/* 1AAEE4 8027C604 8E250000 */  lw        $a1, ($s1)
/* 1AAEE8 8027C608 0C0B1EAF */  jal       get_variable
/* 1AAEEC 8027C60C 0240202D */   daddu    $a0, $s2, $zero
/* 1AAEF0 8027C610 0200202D */  daddu     $a0, $s0, $zero
/* 1AAEF4 8027C614 0C09A75B */  jal       get_actor
/* 1AAEF8 8027C618 0040802D */   daddu    $s0, $v0, $zero
/* 1AAEFC 8027C61C 0040282D */  daddu     $a1, $v0, $zero
/* 1AAF00 8027C620 A0B001B8 */  sb        $s0, 0x1b8($a1)
/* 1AAF04 8027C624 00108600 */  sll       $s0, $s0, 0x18
/* 1AAF08 8027C628 00108603 */  sra       $s0, $s0, 0x18
/* 1AAF0C 8027C62C 80A201B9 */  lb        $v0, 0x1b9($a1)
/* 1AAF10 8027C630 90A301B9 */  lbu       $v1, 0x1b9($a1)
/* 1AAF14 8027C634 0050102A */  slt       $v0, $v0, $s0
/* 1AAF18 8027C638 54400001 */  bnel      $v0, $zero, .L8027C640
/* 1AAF1C 8027C63C A0A301B8 */   sb       $v1, 0x1b8($a1)
.L8027C640:
/* 1AAF20 8027C640 80A201B8 */  lb        $v0, 0x1b8($a1)
/* 1AAF24 8027C644 80A401B9 */  lb        $a0, 0x1b9($a1)
/* 1AAF28 8027C648 00021840 */  sll       $v1, $v0, 1
/* 1AAF2C 8027C64C 00621821 */  addu      $v1, $v1, $v0
/* 1AAF30 8027C650 000318C0 */  sll       $v1, $v1, 3
/* 1AAF34 8027C654 00621821 */  addu      $v1, $v1, $v0
/* 1AAF38 8027C658 14800002 */  bnez      $a0, .L8027C664
/* 1AAF3C 8027C65C 0064001A */   div      $zero, $v1, $a0
/* 1AAF40 8027C660 0007000D */  break     7
.L8027C664:
/* 1AAF44 8027C664 2401FFFF */   addiu    $at, $zero, -1
/* 1AAF48 8027C668 14810004 */  bne       $a0, $at, .L8027C67C
/* 1AAF4C 8027C66C 3C018000 */   lui      $at, 0x8000
/* 1AAF50 8027C670 14610002 */  bne       $v1, $at, .L8027C67C
/* 1AAF54 8027C674 00000000 */   nop      
/* 1AAF58 8027C678 0006000D */  break     6
.L8027C67C:
/* 1AAF5C 8027C67C 00001812 */   mflo     $v1
/* 1AAF60 8027C680 A0A301BC */  sb        $v1, 0x1bc($a1)
/* 1AAF64 8027C684 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1AAF68 8027C688 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AAF6C 8027C68C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AAF70 8027C690 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AAF74 8027C694 24020002 */  addiu     $v0, $zero, 2
/* 1AAF78 8027C698 03E00008 */  jr        $ra
/* 1AAF7C 8027C69C 27BD0020 */   addiu    $sp, $sp, 0x20

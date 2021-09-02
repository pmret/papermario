.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel crash_printf_msg
/* 7608 8002C208 AFA60008 */  sw        $a2, 8($sp)
/* 760C 8002C20C AFA7000C */  sw        $a3, 0xc($sp)
/* 7610 8002C210 27BDFED0 */  addiu     $sp, $sp, -0x130
/* 7614 8002C214 AFB20118 */  sw        $s2, 0x118($sp)
/* 7618 8002C218 0080902D */  daddu     $s2, $a0, $zero
/* 761C 8002C21C AFB50124 */  sw        $s5, 0x124($sp)
/* 7620 8002C220 00A0A82D */  daddu     $s5, $a1, $zero
/* 7624 8002C224 3C048003 */  lui       $a0, %hi(func_8002C1D4)
/* 7628 8002C228 2484C1D4 */  addiu     $a0, $a0, %lo(func_8002C1D4)
/* 762C 8002C22C 27A50010 */  addiu     $a1, $sp, 0x10
/* 7630 8002C230 27A7013C */  addiu     $a3, $sp, 0x13c
/* 7634 8002C234 AFBF0128 */  sw        $ra, 0x128($sp)
/* 7638 8002C238 AFB40120 */  sw        $s4, 0x120($sp)
/* 763C 8002C23C AFB3011C */  sw        $s3, 0x11c($sp)
/* 7640 8002C240 AFB10114 */  sw        $s1, 0x114($sp)
/* 7644 8002C244 0C0192A8 */  jal       _Printf
/* 7648 8002C248 AFB00110 */   sw       $s0, 0x110($sp)
/* 764C 8002C24C 0040802D */  daddu     $s0, $v0, $zero
/* 7650 8002C250 1A000010 */  blez      $s0, .L8002C294
/* 7654 8002C254 27B10010 */   addiu    $s1, $sp, 0x10
/* 7658 8002C258 3C148007 */  lui       $s4, %hi(D_80077210)
/* 765C 8002C25C 26947210 */  addiu     $s4, $s4, %lo(D_80077210)
/* 7660 8002C260 241300FF */  addiu     $s3, $zero, 0xff
.L8002C264:
/* 7664 8002C264 92220000 */  lbu       $v0, ($s1)
/* 7668 8002C268 3042007F */  andi      $v0, $v0, 0x7f
/* 766C 8002C26C 00541021 */  addu      $v0, $v0, $s4
/* 7670 8002C270 90460000 */  lbu       $a2, ($v0)
/* 7674 8002C274 10D30003 */  beq       $a2, $s3, .L8002C284
/* 7678 8002C278 0240202D */   daddu    $a0, $s2, $zero
/* 767C 8002C27C 0C00B015 */  jal       func_8002C054
/* 7680 8002C280 02A0282D */   daddu    $a1, $s5, $zero
.L8002C284:
/* 7684 8002C284 26520006 */  addiu     $s2, $s2, 6
/* 7688 8002C288 2610FFFF */  addiu     $s0, $s0, -1
/* 768C 8002C28C 1E00FFF5 */  bgtz      $s0, .L8002C264
/* 7690 8002C290 26310001 */   addiu    $s1, $s1, 1
.L8002C294:
/* 7694 8002C294 8FBF0128 */  lw        $ra, 0x128($sp)
/* 7698 8002C298 8FB50124 */  lw        $s5, 0x124($sp)
/* 769C 8002C29C 8FB40120 */  lw        $s4, 0x120($sp)
/* 76A0 8002C2A0 8FB3011C */  lw        $s3, 0x11c($sp)
/* 76A4 8002C2A4 8FB20118 */  lw        $s2, 0x118($sp)
/* 76A8 8002C2A8 8FB10114 */  lw        $s1, 0x114($sp)
/* 76AC 8002C2AC 8FB00110 */  lw        $s0, 0x110($sp)
/* 76B0 8002C2B0 03E00008 */  jr        $ra
/* 76B4 8002C2B4 27BD0130 */   addiu    $sp, $sp, 0x130

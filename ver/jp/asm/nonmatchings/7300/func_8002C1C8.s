.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C1C8
/* 75C8 8002C1C8 AFA60008 */  sw        $a2, 8($sp)
/* 75CC 8002C1CC AFA7000C */  sw        $a3, 0xc($sp)
/* 75D0 8002C1D0 27BDFED0 */  addiu     $sp, $sp, -0x130
/* 75D4 8002C1D4 AFB20118 */  sw        $s2, 0x118($sp)
/* 75D8 8002C1D8 0080902D */  daddu     $s2, $a0, $zero
/* 75DC 8002C1DC AFB50124 */  sw        $s5, 0x124($sp)
/* 75E0 8002C1E0 00A0A82D */  daddu     $s5, $a1, $zero
/* 75E4 8002C1E4 3C048003 */  lui       $a0, %hi(func_8002C194)
/* 75E8 8002C1E8 2484C194 */  addiu     $a0, $a0, %lo(func_8002C194)
/* 75EC 8002C1EC 27A50010 */  addiu     $a1, $sp, 0x10
/* 75F0 8002C1F0 27A7013C */  addiu     $a3, $sp, 0x13c
/* 75F4 8002C1F4 AFBF0128 */  sw        $ra, 0x128($sp)
/* 75F8 8002C1F8 AFB40120 */  sw        $s4, 0x120($sp)
/* 75FC 8002C1FC AFB3011C */  sw        $s3, 0x11c($sp)
/* 7600 8002C200 AFB10114 */  sw        $s1, 0x114($sp)
/* 7604 8002C204 0C01929C */  jal       _Printf
/* 7608 8002C208 AFB00110 */   sw       $s0, 0x110($sp)
/* 760C 8002C20C 0040802D */  daddu     $s0, $v0, $zero
/* 7610 8002C210 1A000010 */  blez      $s0, .L8002C254
/* 7614 8002C214 27B10010 */   addiu    $s1, $sp, 0x10
/* 7618 8002C218 3C148007 */  lui       $s4, %hi(D_800771F0)
/* 761C 8002C21C 269471F0 */  addiu     $s4, $s4, %lo(D_800771F0)
/* 7620 8002C220 241300FF */  addiu     $s3, $zero, 0xff
.L8002C224:
/* 7624 8002C224 92220000 */  lbu       $v0, ($s1)
/* 7628 8002C228 3042007F */  andi      $v0, $v0, 0x7f
/* 762C 8002C22C 00541021 */  addu      $v0, $v0, $s4
/* 7630 8002C230 90460000 */  lbu       $a2, ($v0)
/* 7634 8002C234 10D30003 */  beq       $a2, $s3, .L8002C244
/* 7638 8002C238 0240202D */   daddu    $a0, $s2, $zero
/* 763C 8002C23C 0C00B005 */  jal       func_8002C014
/* 7640 8002C240 02A0282D */   daddu    $a1, $s5, $zero
.L8002C244:
/* 7644 8002C244 26520006 */  addiu     $s2, $s2, 6
/* 7648 8002C248 2610FFFF */  addiu     $s0, $s0, -1
/* 764C 8002C24C 1E00FFF5 */  bgtz      $s0, .L8002C224
/* 7650 8002C250 26310001 */   addiu    $s1, $s1, 1
.L8002C254:
/* 7654 8002C254 8FBF0128 */  lw        $ra, 0x128($sp)
/* 7658 8002C258 8FB50124 */  lw        $s5, 0x124($sp)
/* 765C 8002C25C 8FB40120 */  lw        $s4, 0x120($sp)
/* 7660 8002C260 8FB3011C */  lw        $s3, 0x11c($sp)
/* 7664 8002C264 8FB20118 */  lw        $s2, 0x118($sp)
/* 7668 8002C268 8FB10114 */  lw        $s1, 0x114($sp)
/* 766C 8002C26C 8FB00110 */  lw        $s0, 0x110($sp)
/* 7670 8002C270 03E00008 */  jr        $ra
/* 7674 8002C274 27BD0130 */   addiu    $sp, $sp, 0x130

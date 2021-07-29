.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C278
/* 7678 8002C278 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 767C 8002C27C AFBF0018 */  sw        $ra, 0x18($sp)
/* 7680 8002C280 8CE30000 */  lw        $v1, ($a3)
/* 7684 8002C284 000315C2 */  srl       $v0, $v1, 0x17
/* 7688 8002C288 304200FF */  andi      $v0, $v0, 0xff
/* 768C 8002C28C 2442FFFF */  addiu     $v0, $v0, -1
/* 7690 8002C290 2C4200FE */  sltiu     $v0, $v0, 0xfe
/* 7694 8002C294 14400003 */  bnez      $v0, .L8002C2A4
/* 7698 8002C298 00C0402D */   daddu    $t0, $a2, $zero
/* 769C 8002C29C 1460000A */  bnez      $v1, .L8002C2C8
/* 76A0 8002C2A0 00000000 */   nop
.L8002C2A4:
/* 76A4 8002C2A4 3C06800A */  lui       $a2, %hi(D_80098014)
/* 76A8 8002C2A8 24C68014 */  addiu     $a2, $a2, %lo(D_80098014)
/* 76AC 8002C2AC C4E00000 */  lwc1      $f0, ($a3)
/* 76B0 8002C2B0 46000021 */  cvt.d.s   $f0, $f0
/* 76B4 8002C2B4 F7A00010 */  sdc1      $f0, 0x10($sp)
/* 76B8 8002C2B8 0C00B072 */  jal       func_8002C1C8
/* 76BC 8002C2BC 0100382D */   daddu    $a3, $t0, $zero
/* 76C0 8002C2C0 0800B0B6 */  j         .L8002C2D8
/* 76C4 8002C2C4 00000000 */   nop
.L8002C2C8:
/* 76C8 8002C2C8 3C06800A */  lui       $a2, %hi(D_80098020)
/* 76CC 8002C2CC 24C68020 */  addiu     $a2, $a2, %lo(D_80098020)
/* 76D0 8002C2D0 0C00B072 */  jal       func_8002C1C8
/* 76D4 8002C2D4 0100382D */   daddu    $a3, $t0, $zero
.L8002C2D8:
/* 76D8 8002C2D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 76DC 8002C2DC 03E00008 */  jr        $ra
/* 76E0 8002C2E0 27BD0020 */   addiu    $sp, $sp, 0x20

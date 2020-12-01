.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E89F8
/* 10A278 802E89F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10A27C 802E89FC AFBF0010 */  sw        $ra, 0x10($sp)
/* 10A280 802E8A00 8C850040 */  lw        $a1, 0x40($a0)
/* 10A284 802E8A04 8CA20004 */  lw        $v0, 4($a1)
/* 10A288 802E8A08 2403FFFF */  addiu     $v1, $zero, -1
/* 10A28C 802E8A0C 2442FFFF */  addiu     $v0, $v0, -1
/* 10A290 802E8A10 1043000C */  beq       $v0, $v1, .L802E8A44
/* 10A294 802E8A14 ACA20004 */   sw       $v0, 4($a1)
/* 10A298 802E8A18 8CA20008 */  lw        $v0, 8($a1)
/* 10A29C 802E8A1C 14400009 */  bnez      $v0, .L802E8A44
/* 10A2A0 802E8A20 00000000 */   nop      
/* 10A2A4 802E8A24 C480004C */  lwc1      $f0, 0x4c($a0)
/* 10A2A8 802E8A28 3C01802F */  lui       $at, %hi(D_802EB380)
/* 10A2AC 802E8A2C D422B380 */  ldc1      $f2, %lo(D_802EB380)($at)
/* 10A2B0 802E8A30 46000021 */  cvt.d.s   $f0, $f0
/* 10A2B4 802E8A34 46220000 */  add.d     $f0, $f0, $f2
/* 10A2B8 802E8A38 46200020 */  cvt.s.d   $f0, $f0
/* 10A2BC 802E8A3C 080BA293 */  j         .L802E8A4C
/* 10A2C0 802E8A40 E480004C */   swc1     $f0, 0x4c($a0)
.L802E8A44:
/* 10A2C4 802E8A44 0C043F5A */  jal       func_8010FD68
/* 10A2C8 802E8A48 ACA00004 */   sw       $zero, 4($a1)
.L802E8A4C:
/* 10A2CC 802E8A4C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 10A2D0 802E8A50 03E00008 */  jr        $ra
/* 10A2D4 802E8A54 27BD0018 */   addiu    $sp, $sp, 0x18

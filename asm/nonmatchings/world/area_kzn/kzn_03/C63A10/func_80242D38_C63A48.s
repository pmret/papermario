.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D38_C63A48
/* C63A48 80242D38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C63A4C 80242D3C 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x18)
/* C63A50 80242D40 8442EFE0 */  lh        $v0, %lo(gPlayerStatus+0x18)($v0)
/* C63A54 80242D44 3C014089 */  lui       $at, 0x4089
/* C63A58 80242D48 44810800 */  mtc1      $at, $f1
/* C63A5C 80242D4C 44800000 */  mtc1      $zero, $f0
/* C63A60 80242D50 2406FFFF */  addiu     $a2, $zero, -1
/* C63A64 80242D54 44821000 */  mtc1      $v0, $f2
/* C63A68 80242D58 00000000 */  nop       
/* C63A6C 80242D5C 468010A1 */  cvt.d.w   $f2, $f2
/* C63A70 80242D60 4622003C */  c.lt.d    $f0, $f2
/* C63A74 80242D64 00000000 */  nop       
/* C63A78 80242D68 45000002 */  bc1f      .L80242D74
/* C63A7C 80242D6C AFBF0010 */   sw       $ra, 0x10($sp)
/* C63A80 80242D70 0000302D */  daddu     $a2, $zero, $zero
.L80242D74:
/* C63A84 80242D74 3C018024 */  lui       $at, %hi(D_80247410)
/* C63A88 80242D78 D4207410 */  ldc1      $f0, %lo(D_80247410)($at)
/* C63A8C 80242D7C 4620103C */  c.lt.d    $f2, $f0
/* C63A90 80242D80 00000000 */  nop       
/* C63A94 80242D84 45030001 */  bc1tl     .L80242D8C
/* C63A98 80242D88 24060001 */   addiu    $a2, $zero, 1
.L80242D8C:
/* C63A9C 80242D8C 04C00004 */  bltz      $a2, .L80242DA0
/* C63AA0 80242D90 00000000 */   nop      
/* C63AA4 80242D94 3C05FD05 */  lui       $a1, 0xfd05
/* C63AA8 80242D98 0C0B2026 */  jal       set_variable
/* C63AAC 80242D9C 34A50F89 */   ori      $a1, $a1, 0xf89
.L80242DA0:
/* C63AB0 80242DA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* C63AB4 80242DA4 0000102D */  daddu     $v0, $zero, $zero
/* C63AB8 80242DA8 03E00008 */  jr        $ra
/* C63ABC 80242DAC 27BD0018 */   addiu    $sp, $sp, 0x18

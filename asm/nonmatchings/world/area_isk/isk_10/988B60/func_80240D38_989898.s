.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D38_989898
/* 989898 80240D38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 98989C 80240D3C 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x18)
/* 9898A0 80240D40 8442EFE0 */  lh        $v0, %lo(gPlayerStatus+0x18)($v0)
/* 9898A4 80240D44 3C018024 */  lui       $at, 0x8024
/* 9898A8 80240D48 D4201EA0 */  ldc1      $f0, 0x1ea0($at)
/* 9898AC 80240D4C 2406FFFF */  addiu     $a2, $zero, -1
/* 9898B0 80240D50 44821000 */  mtc1      $v0, $f2
/* 9898B4 80240D54 00000000 */  nop       
/* 9898B8 80240D58 468010A1 */  cvt.d.w   $f2, $f2
/* 9898BC 80240D5C 4622003C */  c.lt.d    $f0, $f2
/* 9898C0 80240D60 00000000 */  nop       
/* 9898C4 80240D64 45000002 */  bc1f      .L80240D70
/* 9898C8 80240D68 AFBF0010 */   sw       $ra, 0x10($sp)
/* 9898CC 80240D6C 0000302D */  daddu     $a2, $zero, $zero
.L80240D70:
/* 9898D0 80240D70 3C018024 */  lui       $at, 0x8024
/* 9898D4 80240D74 D4201EA8 */  ldc1      $f0, 0x1ea8($at)
/* 9898D8 80240D78 4620103C */  c.lt.d    $f2, $f0
/* 9898DC 80240D7C 00000000 */  nop       
/* 9898E0 80240D80 45030001 */  bc1tl     .L80240D88
/* 9898E4 80240D84 24060001 */   addiu    $a2, $zero, 1
.L80240D88:
/* 9898E8 80240D88 04C00004 */  bltz      $a2, .L80240D9C
/* 9898EC 80240D8C 00000000 */   nop      
/* 9898F0 80240D90 3C05FD05 */  lui       $a1, 0xfd05
/* 9898F4 80240D94 0C0B2026 */  jal       set_variable
/* 9898F8 80240D98 34A50F89 */   ori      $a1, $a1, 0xf89
.L80240D9C:
/* 9898FC 80240D9C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 989900 80240DA0 0000102D */  daddu     $v0, $zero, $zero
/* 989904 80240DA4 03E00008 */  jr        $ra
/* 989908 80240DA8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 98990C 80240DAC 00000000 */  nop       

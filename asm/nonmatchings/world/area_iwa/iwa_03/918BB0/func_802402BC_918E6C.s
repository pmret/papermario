.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402BC_918E6C
/* 918E6C 802402BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 918E70 802402C0 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x18)
/* 918E74 802402C4 8442EFE0 */  lh        $v0, %lo(gPlayerStatus+0x18)($v0)
/* 918E78 802402C8 3C014069 */  lui       $at, 0x4069
/* 918E7C 802402CC 44810800 */  mtc1      $at, $f1
/* 918E80 802402D0 44800000 */  mtc1      $zero, $f0
/* 918E84 802402D4 2406FFFF */  addiu     $a2, $zero, -1
/* 918E88 802402D8 44821000 */  mtc1      $v0, $f2
/* 918E8C 802402DC 00000000 */  nop       
/* 918E90 802402E0 468010A1 */  cvt.d.w   $f2, $f2
/* 918E94 802402E4 4622003C */  c.lt.d    $f0, $f2
/* 918E98 802402E8 00000000 */  nop       
/* 918E9C 802402EC 45000002 */  bc1f      .L802402F8
/* 918EA0 802402F0 AFBF0010 */   sw       $ra, 0x10($sp)
/* 918EA4 802402F4 0000302D */  daddu     $a2, $zero, $zero
.L802402F8:
/* 918EA8 802402F8 3C014044 */  lui       $at, 0x4044
/* 918EAC 802402FC 44810800 */  mtc1      $at, $f1
/* 918EB0 80240300 44800000 */  mtc1      $zero, $f0
/* 918EB4 80240304 00000000 */  nop       
/* 918EB8 80240308 4620103C */  c.lt.d    $f2, $f0
/* 918EBC 8024030C 00000000 */  nop       
/* 918EC0 80240310 45030001 */  bc1tl     .L80240318
/* 918EC4 80240314 24060001 */   addiu    $a2, $zero, 1
.L80240318:
/* 918EC8 80240318 04C00004 */  bltz      $a2, .L8024032C
/* 918ECC 8024031C 00000000 */   nop      
/* 918ED0 80240320 3C05FD05 */  lui       $a1, 0xfd05
/* 918ED4 80240324 0C0B2026 */  jal       set_variable
/* 918ED8 80240328 34A50F89 */   ori      $a1, $a1, 0xf89
.L8024032C:
/* 918EDC 8024032C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 918EE0 80240330 0000102D */  daddu     $v0, $zero, $zero
/* 918EE4 80240334 03E00008 */  jr        $ra
/* 918EE8 80240338 27BD0018 */   addiu    $sp, $sp, 0x18
/* 918EEC 8024033C 00000000 */  nop       

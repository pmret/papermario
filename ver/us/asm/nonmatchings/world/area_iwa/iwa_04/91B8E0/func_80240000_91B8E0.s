.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_91B8E0
/* 91B8E0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 91B8E4 80240004 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x18)
/* 91B8E8 80240008 8442EFE0 */  lh        $v0, %lo(gPlayerStatus+0x18)($v0)
/* 91B8EC 8024000C 3C01C059 */  lui       $at, 0xc059
/* 91B8F0 80240010 44810800 */  mtc1      $at, $f1
/* 91B8F4 80240014 44800000 */  mtc1      $zero, $f0
/* 91B8F8 80240018 2406FFFF */  addiu     $a2, $zero, -1
/* 91B8FC 8024001C 44821000 */  mtc1      $v0, $f2
/* 91B900 80240020 00000000 */  nop
/* 91B904 80240024 468010A1 */  cvt.d.w   $f2, $f2
/* 91B908 80240028 4622003C */  c.lt.d    $f0, $f2
/* 91B90C 8024002C 00000000 */  nop
/* 91B910 80240030 45000002 */  bc1f      .L8024003C
/* 91B914 80240034 AFBF0010 */   sw       $ra, 0x10($sp)
/* 91B918 80240038 0000302D */  daddu     $a2, $zero, $zero
.L8024003C:
/* 91B91C 8024003C 3C01C06E */  lui       $at, 0xc06e
/* 91B920 80240040 44810800 */  mtc1      $at, $f1
/* 91B924 80240044 44800000 */  mtc1      $zero, $f0
/* 91B928 80240048 00000000 */  nop
/* 91B92C 8024004C 4620103C */  c.lt.d    $f2, $f0
/* 91B930 80240050 00000000 */  nop
/* 91B934 80240054 45030001 */  bc1tl     .L8024005C
/* 91B938 80240058 24060001 */   addiu    $a2, $zero, 1
.L8024005C:
/* 91B93C 8024005C 04C00004 */  bltz      $a2, .L80240070
/* 91B940 80240060 00000000 */   nop
/* 91B944 80240064 3C05FD05 */  lui       $a1, 0xfd05
/* 91B948 80240068 0C0B2026 */  jal       evt_set_variable
/* 91B94C 8024006C 34A50F89 */   ori      $a1, $a1, 0xf89
.L80240070:
/* 91B950 80240070 8FBF0010 */  lw        $ra, 0x10($sp)
/* 91B954 80240074 0000102D */  daddu     $v0, $zero, $zero
/* 91B958 80240078 03E00008 */  jr        $ra
/* 91B95C 8024007C 27BD0018 */   addiu    $sp, $sp, 0x18

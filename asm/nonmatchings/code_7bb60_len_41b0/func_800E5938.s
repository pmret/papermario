.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E5938
/* 7EDE8 800E5938 3C088011 */  lui       $t0, %hi(D_8010C944)
/* 7EDEC 800E593C 8D08C944 */  lw        $t0, %lo(D_8010C944)($t0)
/* 7EDF0 800E5940 01044023 */  subu      $t0, $t0, $a0
/* 7EDF4 800E5944 05020001 */  bltzl     $t0, .L800E594C
/* 7EDF8 800E5948 25080005 */   addiu    $t0, $t0, 5
.L800E594C:
/* 7EDFC 800E594C 00081880 */  sll       $v1, $t0, 2
/* 7EE00 800E5950 3C028011 */  lui       $v0, %hi(D_8010EF28)
/* 7EE04 800E5954 00431021 */  addu      $v0, $v0, $v1
/* 7EE08 800E5958 8C42EF28 */  lw        $v0, %lo(D_8010EF28)($v0)
/* 7EE0C 800E595C ACA20000 */  sw        $v0, ($a1)
/* 7EE10 800E5960 3C028011 */  lui       $v0, %hi(D_8010EF10)
/* 7EE14 800E5964 00431021 */  addu      $v0, $v0, $v1
/* 7EE18 800E5968 8C42EF10 */  lw        $v0, %lo(D_8010EF10)($v0)
/* 7EE1C 800E596C ACC20000 */  sw        $v0, ($a2)
/* 7EE20 800E5970 3C028011 */  lui       $v0, %hi(D_8010EF40)
/* 7EE24 800E5974 00431021 */  addu      $v0, $v0, $v1
/* 7EE28 800E5978 8C42EF40 */  lw        $v0, %lo(D_8010EF40)($v0)
/* 7EE2C 800E597C ACE20000 */  sw        $v0, ($a3)
/* 7EE30 800E5980 00081040 */  sll       $v0, $t0, 1
/* 7EE34 800E5984 3C018011 */  lui       $at, %hi(D_8010F6B8)
/* 7EE38 800E5988 00220821 */  addu      $at, $at, $v0
/* 7EE3C 800E598C 8422F6B8 */  lh        $v0, %lo(D_8010F6B8)($at)
/* 7EE40 800E5990 44820000 */  mtc1      $v0, $f0
/* 7EE44 800E5994 00000000 */  nop
/* 7EE48 800E5998 03E00008 */  jr        $ra
/* 7EE4C 800E599C 46800020 */   cvt.s.w  $f0, $f0

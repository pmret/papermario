.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_8010BEE8
.double 180.0

.section .text

glabel phys_is_on_sloped_ground
/* 7DB78 800E46C8 3C048011 */  lui       $a0, %hi(gPlayerStatus+0xCC)
/* 7DB7C 800E46CC 8C84F094 */  lw        $a0, %lo(gPlayerStatus+0xCC)($a0)
/* 7DB80 800E46D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7DB84 800E46D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7DB88 800E46D8 0C044181 */  jal       get_shadow_by_index
/* 7DB8C 800E46DC 00000000 */   nop
/* 7DB90 800E46E0 C4400030 */  lwc1      $f0, 0x30($v0)
/* 7DB94 800E46E4 3C018011 */  lui       $at, %hi(D_8010BEE8)
/* 7DB98 800E46E8 D424BEE8 */  ldc1      $f4, %lo(D_8010BEE8)($at)
/* 7DB9C 800E46EC C4420028 */  lwc1      $f2, 0x28($v0)
/* 7DBA0 800E46F0 46000021 */  cvt.d.s   $f0, $f0
/* 7DBA4 800E46F4 46240000 */  add.d     $f0, $f0, $f4
/* 7DBA8 800E46F8 24020001 */  addiu     $v0, $zero, 1
/* 7DBAC 800E46FC 460010A1 */  cvt.d.s   $f2, $f2
/* 7DBB0 800E4700 46241080 */  add.d     $f2, $f2, $f4
/* 7DBB4 800E4704 3C0141A0 */  lui       $at, 0x41a0
/* 7DBB8 800E4708 44812000 */  mtc1      $at, $f4
/* 7DBBC 800E470C 46200020 */  cvt.s.d   $f0, $f0
/* 7DBC0 800E4710 46000005 */  abs.s     $f0, $f0
/* 7DBC4 800E4714 4604003C */  c.lt.s    $f0, $f4
/* 7DBC8 800E4718 00000000 */  nop
/* 7DBCC 800E471C 45000006 */  bc1f      .L800E4738
/* 7DBD0 800E4720 46201020 */   cvt.s.d  $f0, $f2
/* 7DBD4 800E4724 46000005 */  abs.s     $f0, $f0
/* 7DBD8 800E4728 4604003C */  c.lt.s    $f0, $f4
/* 7DBDC 800E472C 00000000 */  nop
/* 7DBE0 800E4730 45030001 */  bc1tl     .L800E4738
/* 7DBE4 800E4734 0000102D */   daddu    $v0, $zero, $zero
.L800E4738:
/* 7DBE8 800E4738 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7DBEC 800E473C 03E00008 */  jr        $ra
/* 7DBF0 800E4740 27BD0018 */   addiu    $sp, $sp, 0x18

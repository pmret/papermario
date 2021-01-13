.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE014_31DB84
/* 31DB84 802BE014 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31DB88 802BE018 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 31DB8C 802BE01C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 31DB90 802BE020 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31DB94 802BE024 C4420054 */  lwc1      $f2, 0x54($v0)
/* 31DB98 802BE028 C440005C */  lwc1      $f0, 0x5c($v0)
/* 31DB9C 802BE02C 4602003E */  c.le.s    $f0, $f2
/* 31DBA0 802BE030 00000000 */  nop
/* 31DBA4 802BE034 45000003 */  bc1f      .L802BE044
/* 31DBA8 802BE038 3C040006 */   lui      $a0, 6
/* 31DBAC 802BE03C 080AF817 */  j         .L802BE05C
/* 31DBB0 802BE040 34840002 */   ori      $a0, $a0, 2
.L802BE044:
/* 31DBB4 802BE044 C4400058 */  lwc1      $f0, 0x58($v0)
/* 31DBB8 802BE048 4602003E */  c.le.s    $f0, $f2
/* 31DBBC 802BE04C 00000000 */  nop
/* 31DBC0 802BE050 45000002 */  bc1f      .L802BE05C
/* 31DBC4 802BE054 34840007 */   ori      $a0, $a0, 7
/* 31DBC8 802BE058 3C040006 */  lui       $a0, 6
.L802BE05C:
/* 31DBCC 802BE05C 0C037FBF */  jal       func_800DFEFC
/* 31DBD0 802BE060 00000000 */   nop
/* 31DBD4 802BE064 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31DBD8 802BE068 03E00008 */  jr        $ra
/* 31DBDC 802BE06C 27BD0018 */   addiu    $sp, $sp, 0x18

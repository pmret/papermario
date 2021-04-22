.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800527F4
/* 2DBF4 800527F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2DBF8 800527F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 2DBFC 800527FC 0080802D */  daddu     $s0, $a0, $zero
/* 2DC00 80052800 AFBF0014 */  sw        $ra, 0x14($sp)
/* 2DC04 80052804 9203003A */  lbu       $v1, 0x3a($s0)
/* 2DC08 80052808 86020040 */  lh        $v0, 0x40($s0)
/* 2DC0C 8005280C 00620018 */  mult      $v1, $v0
/* 2DC10 80052810 00002812 */  mflo      $a1
/* 2DC14 80052814 9202003F */  lbu       $v0, 0x3f($s0)
/* 2DC18 80052818 00000000 */  nop
/* 2DC1C 8005281C 00A20018 */  mult      $a1, $v0
/* 2DC20 80052820 00002812 */  mflo      $a1
/* 2DC24 80052824 8E030030 */  lw        $v1, 0x30($s0)
/* 2DC28 80052828 00051383 */  sra       $v0, $a1, 0xe
/* 2DC2C 8005282C 00430018 */  mult      $v0, $v1
/* 2DC30 80052830 8E040028 */  lw        $a0, 0x28($s0)
/* 2DC34 80052834 00002812 */  mflo      $a1
/* 2DC38 80052838 000511C3 */  sra       $v0, $a1, 7
/* 2DC3C 8005283C 0C014A1C */  jal       func_80052870
/* 2DC40 80052840 A602000C */   sh       $v0, 0xc($s0)
/* 2DC44 80052844 AE020008 */  sw        $v0, 8($s0)
/* 2DC48 80052848 9202003D */  lbu       $v0, 0x3d($s0)
/* 2DC4C 8005284C 92030043 */  lbu       $v1, 0x43($s0)
/* 2DC50 80052850 304200FD */  andi      $v0, $v0, 0xfd
/* 2DC54 80052854 34630004 */  ori       $v1, $v1, 4
/* 2DC58 80052858 A202003D */  sb        $v0, 0x3d($s0)
/* 2DC5C 8005285C A2030043 */  sb        $v1, 0x43($s0)
/* 2DC60 80052860 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2DC64 80052864 8FB00010 */  lw        $s0, 0x10($sp)
/* 2DC68 80052868 03E00008 */  jr        $ra
/* 2DC6C 8005286C 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D2C_8035AC
/* 8035AC 80242D2C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 8035B0 80242D30 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 8035B4 80242D34 10A00002 */  beqz      $a1, .L80242D40
/* 8035B8 80242D38 2402003C */   addiu    $v0, $zero, 0x3c
/* 8035BC 80242D3C AC820070 */  sw        $v0, 0x70($a0)
.L80242D40:
/* 8035C0 80242D40 C4620080 */  lwc1      $f2, 0x80($v1)
/* 8035C4 80242D44 3C0141F0 */  lui       $at, 0x41f0
/* 8035C8 80242D48 44810000 */  mtc1      $at, $f0
/* 8035CC 80242D4C 00000000 */  nop       
/* 8035D0 80242D50 46001000 */  add.s     $f0, $f2, $f0
/* 8035D4 80242D54 3C0143B4 */  lui       $at, 0x43b4
/* 8035D8 80242D58 44811000 */  mtc1      $at, $f2
/* 8035DC 80242D5C 00000000 */  nop       
/* 8035E0 80242D60 4600103E */  c.le.s    $f2, $f0
/* 8035E4 80242D64 00000000 */  nop       
/* 8035E8 80242D68 45000003 */  bc1f      .L80242D78
/* 8035EC 80242D6C E4600080 */   swc1     $f0, 0x80($v1)
/* 8035F0 80242D70 46020001 */  sub.s     $f0, $f0, $f2
/* 8035F4 80242D74 E4600080 */  swc1      $f0, 0x80($v1)
.L80242D78:
/* 8035F8 80242D78 8C820070 */  lw        $v0, 0x70($a0)
/* 8035FC 80242D7C 2442FFFF */  addiu     $v0, $v0, -1
/* 803600 80242D80 AC820070 */  sw        $v0, 0x70($a0)
/* 803604 80242D84 000217C3 */  sra       $v0, $v0, 0x1f
/* 803608 80242D88 03E00008 */  jr        $ra
/* 80360C 80242D8C 30420002 */   andi     $v0, $v0, 2

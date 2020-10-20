.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B84_9C6F64
/* 9C6F64 80241B84 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 9C6F68 80241B88 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 9C6F6C 80241B8C 10A00002 */  beqz      $a1, .L80241B98
/* 9C6F70 80241B90 2402003C */   addiu    $v0, $zero, 0x3c
/* 9C6F74 80241B94 AC820070 */  sw        $v0, 0x70($a0)
.L80241B98:
/* 9C6F78 80241B98 C4620080 */  lwc1      $f2, 0x80($v1)
/* 9C6F7C 80241B9C 3C0141F0 */  lui       $at, 0x41f0
/* 9C6F80 80241BA0 44810000 */  mtc1      $at, $f0
/* 9C6F84 80241BA4 00000000 */  nop       
/* 9C6F88 80241BA8 46001000 */  add.s     $f0, $f2, $f0
/* 9C6F8C 80241BAC 3C0143B4 */  lui       $at, 0x43b4
/* 9C6F90 80241BB0 44811000 */  mtc1      $at, $f2
/* 9C6F94 80241BB4 00000000 */  nop       
/* 9C6F98 80241BB8 4600103E */  c.le.s    $f2, $f0
/* 9C6F9C 80241BBC 00000000 */  nop       
/* 9C6FA0 80241BC0 45000003 */  bc1f      .L80241BD0
/* 9C6FA4 80241BC4 E4600080 */   swc1     $f0, 0x80($v1)
/* 9C6FA8 80241BC8 46020001 */  sub.s     $f0, $f0, $f2
/* 9C6FAC 80241BCC E4600080 */  swc1      $f0, 0x80($v1)
.L80241BD0:
/* 9C6FB0 80241BD0 8C820070 */  lw        $v0, 0x70($a0)
/* 9C6FB4 80241BD4 2442FFFF */  addiu     $v0, $v0, -1
/* 9C6FB8 80241BD8 AC820070 */  sw        $v0, 0x70($a0)
/* 9C6FBC 80241BDC 000217C3 */  sra       $v0, $v0, 0x1f
/* 9C6FC0 80241BE0 03E00008 */  jr        $ra
/* 9C6FC4 80241BE4 30420002 */   andi     $v0, $v0, 2

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C78_ECA978
/* ECA978 80240C78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ECA97C 80240C7C AFBF0018 */  sw        $ra, 0x18($sp)
/* ECA980 80240C80 0C00F94D */  jal       func_8003E534
/* ECA984 80240C84 2404FFFC */   addiu    $a0, $zero, -4
/* ECA988 80240C88 3C0141F0 */  lui       $at, 0x41f0
/* ECA98C 80240C8C 44810000 */  mtc1      $at, $f0
/* ECA990 80240C90 C442003C */  lwc1      $f2, 0x3c($v0)
/* ECA994 80240C94 46001080 */  add.s     $f2, $f2, $f0
/* ECA998 80240C98 E7A00010 */  swc1      $f0, 0x10($sp)
/* ECA99C 80240C9C 8C450038 */  lw        $a1, 0x38($v0)
/* ECA9A0 80240CA0 8C470040 */  lw        $a3, 0x40($v0)
/* ECA9A4 80240CA4 44061000 */  mfc1      $a2, $f2
/* ECA9A8 80240CA8 0C01D45C */  jal       func_80075170
/* ECA9AC 80240CAC 24040002 */   addiu    $a0, $zero, 2
/* ECA9B0 80240CB0 8FBF0018 */  lw        $ra, 0x18($sp)
/* ECA9B4 80240CB4 24020002 */  addiu     $v0, $zero, 2
/* ECA9B8 80240CB8 03E00008 */  jr        $ra
/* ECA9BC 80240CBC 27BD0020 */   addiu    $sp, $sp, 0x20

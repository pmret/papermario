.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CC0_ECA9C0
/* ECA9C0 80240CC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ECA9C4 80240CC4 AFBF0018 */  sw        $ra, 0x18($sp)
/* ECA9C8 80240CC8 0C00F94D */  jal       func_8003E534
/* ECA9CC 80240CCC 2404FFFC */   addiu    $a0, $zero, -4
/* ECA9D0 80240CD0 3C0141F0 */  lui       $at, 0x41f0
/* ECA9D4 80240CD4 44810000 */  mtc1      $at, $f0
/* ECA9D8 80240CD8 C442003C */  lwc1      $f2, 0x3c($v0)
/* ECA9DC 80240CDC 46001080 */  add.s     $f2, $f2, $f0
/* ECA9E0 80240CE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* ECA9E4 80240CE4 8C450038 */  lw        $a1, 0x38($v0)
/* ECA9E8 80240CE8 8C470040 */  lw        $a3, 0x40($v0)
/* ECA9EC 80240CEC 44061000 */  mfc1      $a2, $f2
/* ECA9F0 80240CF0 0C01D45C */  jal       func_80075170
/* ECA9F4 80240CF4 24040004 */   addiu    $a0, $zero, 4
/* ECA9F8 80240CF8 8FBF0018 */  lw        $ra, 0x18($sp)
/* ECA9FC 80240CFC 24020002 */  addiu     $v0, $zero, 2
/* ECAA00 80240D00 03E00008 */  jr        $ra
/* ECAA04 80240D04 27BD0020 */   addiu    $sp, $sp, 0x20

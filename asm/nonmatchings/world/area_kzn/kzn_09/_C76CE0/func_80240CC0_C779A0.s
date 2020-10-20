.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CC0_C779A0
/* C779A0 80240CC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C779A4 80240CC4 AFBF0018 */  sw        $ra, 0x18($sp)
/* C779A8 80240CC8 0C00EAD2 */  jal       get_npc_safe
/* C779AC 80240CCC 2404FFFC */   addiu    $a0, $zero, -4
/* C779B0 80240CD0 3C0141F0 */  lui       $at, 0x41f0
/* C779B4 80240CD4 44810000 */  mtc1      $at, $f0
/* C779B8 80240CD8 C442003C */  lwc1      $f2, 0x3c($v0)
/* C779BC 80240CDC 46001080 */  add.s     $f2, $f2, $f0
/* C779C0 80240CE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* C779C4 80240CE4 8C450038 */  lw        $a1, 0x38($v0)
/* C779C8 80240CE8 8C470040 */  lw        $a3, 0x40($v0)
/* C779CC 80240CEC 44061000 */  mfc1      $a2, $f2
/* C779D0 80240CF0 0C01BFBC */  jal       func_8006FEF0
/* C779D4 80240CF4 24040004 */   addiu    $a0, $zero, 4
/* C779D8 80240CF8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C779DC 80240CFC 24020002 */  addiu     $v0, $zero, 2
/* C779E0 80240D00 03E00008 */  jr        $ra
/* C779E4 80240D04 27BD0020 */   addiu    $sp, $sp, 0x20

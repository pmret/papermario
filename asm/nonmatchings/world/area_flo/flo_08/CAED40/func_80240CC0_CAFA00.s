.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CC0_CAFA00
/* CAFA00 80240CC0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAFA04 80240CC4 AFBF0018 */  sw        $ra, 0x18($sp)
/* CAFA08 80240CC8 0C00EAD2 */  jal       get_npc_safe
/* CAFA0C 80240CCC 2404FFFC */   addiu    $a0, $zero, -4
/* CAFA10 80240CD0 3C0141F0 */  lui       $at, 0x41f0
/* CAFA14 80240CD4 44810000 */  mtc1      $at, $f0
/* CAFA18 80240CD8 C442003C */  lwc1      $f2, 0x3c($v0)
/* CAFA1C 80240CDC 46001080 */  add.s     $f2, $f2, $f0
/* CAFA20 80240CE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* CAFA24 80240CE4 8C450038 */  lw        $a1, 0x38($v0)
/* CAFA28 80240CE8 8C470040 */  lw        $a3, 0x40($v0)
/* CAFA2C 80240CEC 44061000 */  mfc1      $a2, $f2
/* CAFA30 80240CF0 0C01BFBC */  jal       func_8006FEF0
/* CAFA34 80240CF4 24040004 */   addiu    $a0, $zero, 4
/* CAFA38 80240CF8 8FBF0018 */  lw        $ra, 0x18($sp)
/* CAFA3C 80240CFC 24020002 */  addiu     $v0, $zero, 2
/* CAFA40 80240D00 03E00008 */  jr        $ra
/* CAFA44 80240D04 27BD0020 */   addiu    $sp, $sp, 0x20

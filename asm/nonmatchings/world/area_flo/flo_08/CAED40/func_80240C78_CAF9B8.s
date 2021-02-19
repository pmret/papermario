.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_08_UnkPartnerPosFunc
/* CAF9B8 80240C78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAF9BC 80240C7C AFBF0018 */  sw        $ra, 0x18($sp)
/* CAF9C0 80240C80 0C00EAD2 */  jal       get_npc_safe
/* CAF9C4 80240C84 2404FFFC */   addiu    $a0, $zero, -4
/* CAF9C8 80240C88 3C0141F0 */  lui       $at, 0x41f0
/* CAF9CC 80240C8C 44810000 */  mtc1      $at, $f0
/* CAF9D0 80240C90 C442003C */  lwc1      $f2, 0x3c($v0)
/* CAF9D4 80240C94 46001080 */  add.s     $f2, $f2, $f0
/* CAF9D8 80240C98 E7A00010 */  swc1      $f0, 0x10($sp)
/* CAF9DC 80240C9C 8C450038 */  lw        $a1, 0x38($v0)
/* CAF9E0 80240CA0 8C470040 */  lw        $a3, 0x40($v0)
/* CAF9E4 80240CA4 44061000 */  mfc1      $a2, $f2
/* CAF9E8 80240CA8 0C01BFBC */  jal       func_8006FEF0
/* CAF9EC 80240CAC 24040002 */   addiu    $a0, $zero, 2
/* CAF9F0 80240CB0 8FBF0018 */  lw        $ra, 0x18($sp)
/* CAF9F4 80240CB4 24020002 */  addiu     $v0, $zero, 2
/* CAF9F8 80240CB8 03E00008 */  jr        $ra
/* CAF9FC 80240CBC 27BD0020 */   addiu    $sp, $sp, 0x20

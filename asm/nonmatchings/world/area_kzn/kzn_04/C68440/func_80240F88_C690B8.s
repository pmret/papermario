.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_04_UnkPartnerPosFunc
/* C690B8 80240F88 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C690BC 80240F8C AFBF0018 */  sw        $ra, 0x18($sp)
/* C690C0 80240F90 0C00EAD2 */  jal       get_npc_safe
/* C690C4 80240F94 2404FFFC */   addiu    $a0, $zero, -4
/* C690C8 80240F98 3C0141F0 */  lui       $at, 0x41f0
/* C690CC 80240F9C 44810000 */  mtc1      $at, $f0
/* C690D0 80240FA0 C442003C */  lwc1      $f2, 0x3c($v0)
/* C690D4 80240FA4 46001080 */  add.s     $f2, $f2, $f0
/* C690D8 80240FA8 E7A00010 */  swc1      $f0, 0x10($sp)
/* C690DC 80240FAC 8C450038 */  lw        $a1, 0x38($v0)
/* C690E0 80240FB0 8C470040 */  lw        $a3, 0x40($v0)
/* C690E4 80240FB4 44061000 */  mfc1      $a2, $f2
/* C690E8 80240FB8 0C01BFBC */  jal       func_8006FEF0
/* C690EC 80240FBC 24040002 */   addiu    $a0, $zero, 2
/* C690F0 80240FC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C690F4 80240FC4 24020002 */  addiu     $v0, $zero, 2
/* C690F8 80240FC8 03E00008 */  jr        $ra
/* C690FC 80240FCC 27BD0020 */   addiu    $sp, $sp, 0x20

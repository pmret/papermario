.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243090_C395C0
/* C395C0 80243090 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C395C4 80243094 AFBF0018 */  sw        $ra, 0x18($sp)
/* C395C8 80243098 0C00EAD2 */  jal       get_npc_safe
/* C395CC 8024309C 2404FFFC */   addiu    $a0, $zero, -4
/* C395D0 802430A0 3C0141F0 */  lui       $at, 0x41f0
/* C395D4 802430A4 44810000 */  mtc1      $at, $f0
/* C395D8 802430A8 C442003C */  lwc1      $f2, 0x3c($v0)
/* C395DC 802430AC 46001080 */  add.s     $f2, $f2, $f0
/* C395E0 802430B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* C395E4 802430B4 8C450038 */  lw        $a1, 0x38($v0)
/* C395E8 802430B8 8C470040 */  lw        $a3, 0x40($v0)
/* C395EC 802430BC 44061000 */  mfc1      $a2, $f2
/* C395F0 802430C0 0C01BFBC */  jal       func_8006FEF0
/* C395F4 802430C4 24040004 */   addiu    $a0, $zero, 4
/* C395F8 802430C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C395FC 802430CC 24020002 */  addiu     $v0, $zero, 2
/* C39600 802430D0 03E00008 */  jr        $ra
/* C39604 802430D4 27BD0020 */   addiu    $sp, $sp, 0x20

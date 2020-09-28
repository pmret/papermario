.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel init_dynamic_entity_list
/* B9814 80123114 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B9818 80123118 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B981C 8012311C 80420070 */  lb        $v0, 0x70($v0)
/* B9820 80123120 14400007 */  bnez      $v0, .L80123140
/* B9824 80123124 00000000 */   nop      
/* B9828 80123128 3C028015 */  lui       $v0, %hi(gWorldDynamicEntityList)
/* B982C 8012312C 244243A0 */  addiu     $v0, $v0, %lo(gWorldDynamicEntityList)
/* B9830 80123130 3C018015 */  lui       $at, %hi(gCurrentDynamicEntityListPtr)
/* B9834 80123134 AC224420 */  sw        $v0, %lo(gCurrentDynamicEntityListPtr)($at)
/* B9838 80123138 03E00008 */  jr        $ra
/* B983C 8012313C 00000000 */   nop      
.L80123140:
/* B9840 80123140 3C028015 */  lui       $v0, %hi(gBattleDynamicEntityList)
/* B9844 80123144 244243E0 */  addiu     $v0, $v0, %lo(gBattleDynamicEntityList)
/* B9848 80123148 3C018015 */  lui       $at, %hi(gCurrentDynamicEntityListPtr)
/* B984C 8012314C AC224420 */  sw        $v0, %lo(gCurrentDynamicEntityListPtr)($at)
/* B9850 80123150 03E00008 */  jr        $ra
/* B9854 80123154 00000000 */   nop      

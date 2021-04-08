.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_dynamic_entity_list
/* B97B8 801230B8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B97BC 801230BC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B97C0 801230C0 80420070 */  lb        $v0, 0x70($v0)
/* B97C4 801230C4 14400005 */  bnez      $v0, .L801230DC
/* B97C8 801230C8 00000000 */   nop
/* B97CC 801230CC 3C028015 */  lui       $v0, %hi(gWorldDynamicEntityList)
/* B97D0 801230D0 244243A0 */  addiu     $v0, $v0, %lo(gWorldDynamicEntityList)
/* B97D4 801230D4 08048C39 */  j         .L801230E4
/* B97D8 801230D8 00000000 */   nop
.L801230DC:
/* B97DC 801230DC 3C028015 */  lui       $v0, %hi(gBattleDynamicEntityList)
/* B97E0 801230E0 244243E0 */  addiu     $v0, $v0, %lo(gBattleDynamicEntityList)
.L801230E4:
/* B97E4 801230E4 3C018015 */  lui       $at, %hi(gCurrentDynamicEntityListPtr)
/* B97E8 801230E8 AC224420 */  sw        $v0, %lo(gCurrentDynamicEntityListPtr)($at)
/* B97EC 801230EC 3C028015 */  lui       $v0, %hi(gCurrentDynamicEntityListPtr)
/* B97F0 801230F0 8C424420 */  lw        $v0, %lo(gCurrentDynamicEntityListPtr)($v0)
/* B97F4 801230F4 2403000F */  addiu     $v1, $zero, 0xf
/* B97F8 801230F8 2442003C */  addiu     $v0, $v0, 0x3c
.L801230FC:
/* B97FC 801230FC AC400000 */  sw        $zero, ($v0)
/* B9800 80123100 2463FFFF */  addiu     $v1, $v1, -1
/* B9804 80123104 0461FFFD */  bgez      $v1, .L801230FC
/* B9808 80123108 2442FFFC */   addiu    $v0, $v0, -4
/* B980C 8012310C 03E00008 */  jr        $ra
/* B9810 80123110 00000000 */   nop

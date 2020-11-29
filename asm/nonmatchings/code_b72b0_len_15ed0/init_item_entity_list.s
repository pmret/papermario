.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel init_item_entity_list
/* C77CC 801310CC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* C77D0 801310D0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* C77D4 801310D4 80420070 */  lb        $v0, 0x70($v0)
/* C77D8 801310D8 14400005 */  bnez      $v0, .L801310F0
/* C77DC 801310DC 00000000 */   nop      
/* C77E0 801310E0 3C028015 */  lui       $v0, %hi(D_80155DA0)
/* C77E4 801310E4 24425DA0 */  addiu     $v0, $v0, %lo(D_80155DA0)
/* C77E8 801310E8 0804C43E */  j         .L801310F8
/* C77EC 801310EC 00000000 */   nop      
.L801310F0:
/* C77F0 801310F0 3C028015 */  lui       $v0, %hi(D_801561A0)
/* C77F4 801310F4 244261A0 */  addiu     $v0, $v0, %lo(D_801561A0)
.L801310F8:
/* C77F8 801310F8 3C018015 */  lui       $at, %hi(D_801565A0)
/* C77FC 801310FC AC2265A0 */  sw        $v0, %lo(D_801565A0)($at)
/* C7800 80131100 3C018015 */  lui       $at, %hi(D_801565A4)
/* C7804 80131104 A42065A4 */  sh        $zero, %lo(D_801565A4)($at)
/* C7808 80131108 3C018015 */  lui       $at, %hi(D_801565A8)
/* C780C 8013110C A42065A8 */  sh        $zero, %lo(D_801565A8)($at)
/* C7810 80131110 3C018015 */  lui       $at, %hi(D_801512F8)
/* C7814 80131114 AC2012F8 */  sw        $zero, %lo(D_801512F8)($at)
/* C7818 80131118 3C018015 */  lui       $at, %hi(D_80155D84)
/* C781C 8013111C AC205D84 */  sw        $zero, %lo(D_80155D84)($at)
/* C7820 80131120 03E00008 */  jr        $ra
/* C7824 80131124 00000000 */   nop      

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800331D0
/* E5D0 800331D0 3C03800A */  lui       $v1, %hi(D_8009A630)
/* E5D4 800331D4 2463A630 */  addiu     $v1, $v1, %lo(D_8009A630)
/* E5D8 800331D8 8C620000 */  lw        $v0, ($v1)
/* E5DC 800331DC 34420008 */  ori       $v0, $v0, 8
/* E5E0 800331E0 AC620000 */  sw        $v0, ($v1)
/* E5E4 800331E4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E5E8 800331E8 8C63417C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E5EC 800331EC 24020003 */  addiu     $v0, $zero, 3
/* E5F0 800331F0 03E00008 */  jr        $ra
/* E5F4 800331F4 A06200AC */   sb       $v0, 0xac($v1)

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801341B0
/* CA8B0 801341B0 00042080 */  sll       $a0, $a0, 2
/* CA8B4 801341B4 3C028015 */  lui       $v0, 0x8015
/* CA8B8 801341B8 8C4265A0 */  lw        $v0, 0x65a0($v0)
/* CA8BC 801341BC 3C05800A */  lui       $a1, %hi(D_8009A650)
/* CA8C0 801341C0 24A5A650 */  addiu     $a1, $a1, %lo(D_8009A650)
/* CA8C4 801341C4 00822021 */  addu      $a0, $a0, $v0
/* CA8C8 801341C8 8C840000 */  lw        $a0, ($a0)
/* CA8CC 801341CC 8CA20000 */  lw        $v0, ($a1)
/* CA8D0 801341D0 8C830000 */  lw        $v1, ($a0)
/* CA8D4 801341D4 34420040 */  ori       $v0, $v0, 0x40
/* CA8D8 801341D8 ACA20000 */  sw        $v0, ($a1)
/* CA8DC 801341DC 34630100 */  ori       $v1, $v1, 0x100
/* CA8E0 801341E0 03E00008 */  jr        $ra
/* CA8E4 801341E4 AC830000 */   sw       $v1, ($a0)

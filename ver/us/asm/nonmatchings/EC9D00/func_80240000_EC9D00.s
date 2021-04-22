.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_EC9D00
/* EC9D00 80240000 3C03800A */  lui       $v1, %hi(D_800A15A8)
/* EC9D04 80240004 246315A8 */  addiu     $v1, $v1, %lo(D_800A15A8)
/* EC9D08 80240008 8C620000 */  lw        $v0, ($v1)
/* EC9D0C 8024000C 34420040 */  ori       $v0, $v0, 0x40
/* EC9D10 80240010 AC620000 */  sw        $v0, ($v1)
/* EC9D14 80240014 03E00008 */  jr        $ra
/* EC9D18 80240018 24020002 */   addiu    $v0, $zero, 2

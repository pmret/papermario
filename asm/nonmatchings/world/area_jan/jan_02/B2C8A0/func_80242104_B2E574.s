.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242104_B2E574
/* B2E574 80242104 3C028025 */  lui       $v0, 0x8025
/* B2E578 80242108 8C428948 */  lw        $v0, -0x76b8($v0)
/* B2E57C 8024210C 8C42000C */  lw        $v0, 0xc($v0)
/* B2E580 80242110 AC40001C */  sw        $zero, 0x1c($v0)
/* B2E584 80242114 03E00008 */  jr        $ra
/* B2E588 80242118 24020002 */   addiu    $v0, $zero, 2

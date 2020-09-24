.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_area_flags
/* DBA90 80145390 3C028007 */  lui       $v0, 0x8007
/* DBA94 80145394 8C42419C */  lw        $v0, 0x419c($v0)
/* DBA98 80145398 8442008A */  lh        $v0, 0x8a($v0)
/* DBA9C 8014539C 3C04800E */  lui       $a0, 0x800e
/* DBAA0 801453A0 2484ACC0 */  addiu     $a0, $a0, -0x5340
/* DBAA4 801453A4 1040000C */  beqz      $v0, .L801453D8
/* DBAA8 801453A8 24020007 */   addiu    $v0, $zero, 7
/* DBAAC 801453AC 2483001C */  addiu     $v1, $a0, 0x1c
.L801453B0:
/* DBAB0 801453B0 AC6012B0 */  sw        $zero, 0x12b0($v1)
/* DBAB4 801453B4 2442FFFF */  addiu     $v0, $v0, -1
/* DBAB8 801453B8 0441FFFD */  bgez      $v0, .L801453B0
/* DBABC 801453BC 2463FFFC */   addiu    $v1, $v1, -4
/* DBAC0 801453C0 2402000F */  addiu     $v0, $zero, 0xf
/* DBAC4 801453C4 00821821 */  addu      $v1, $a0, $v0
.L801453C8:
/* DBAC8 801453C8 A06012D0 */  sb        $zero, 0x12d0($v1)
/* DBACC 801453CC 2442FFFF */  addiu     $v0, $v0, -1
/* DBAD0 801453D0 0441FFFD */  bgez      $v0, .L801453C8
/* DBAD4 801453D4 2463FFFF */   addiu    $v1, $v1, -1
.L801453D8:
/* DBAD8 801453D8 03E00008 */  jr        $ra
/* DBADC 801453DC 00000000 */   nop      

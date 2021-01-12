.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240030_B150E0
/* B150E0 80240030 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B150E4 80240034 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B150E8 80240038 8C420010 */  lw        $v0, 0x10($v0)
/* B150EC 8024003C 30428000 */  andi      $v0, $v0, 0x8000
/* B150F0 80240040 14400007 */  bnez      $v0, .L80240060
/* B150F4 80240044 24020001 */   addiu    $v0, $zero, 1
/* B150F8 80240048 8C830084 */  lw        $v1, 0x84($a0)
/* B150FC 8024004C 2463FFFF */  addiu     $v1, $v1, -1
/* B15100 80240050 2C620001 */  sltiu     $v0, $v1, 1
/* B15104 80240054 00021040 */  sll       $v0, $v0, 1
/* B15108 80240058 03E00008 */  jr        $ra
/* B1510C 8024005C AC830084 */   sw       $v1, 0x84($a0)
.L80240060:
/* B15110 80240060 AC820084 */  sw        $v0, 0x84($a0)
/* B15114 80240064 03E00008 */  jr        $ra
/* B15118 80240068 24020002 */   addiu    $v0, $zero, 2
/* B1511C 8024006C 00000000 */  nop

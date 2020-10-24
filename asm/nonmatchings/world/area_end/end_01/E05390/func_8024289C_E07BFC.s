.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024289C_E07BFC
/* E07BFC 8024289C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* E07C00 802428A0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* E07C04 802428A4 8C420010 */  lw        $v0, 0x10($v0)
/* E07C08 802428A8 30429000 */  andi      $v0, $v0, 0x9000
/* E07C0C 802428AC 0002102B */  sltu      $v0, $zero, $v0
/* E07C10 802428B0 03E00008 */  jr        $ra
/* E07C14 802428B4 00021040 */   sll      $v0, $v0, 1
/* E07C18 802428B8 00000000 */  nop       
/* E07C1C 802428BC 00000000 */  nop       

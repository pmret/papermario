.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D5FA4
/* FA954 802D5FA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FA958 802D5FA8 AFBF0010 */  sw        $ra, 0x10($sp)
/* FA95C 802D5FAC 8C82000C */  lw        $v0, 0xc($a0)
/* FA960 802D5FB0 0C0B1EAF */  jal       get_variable
/* FA964 802D5FB4 8C450000 */   lw       $a1, ($v0)
/* FA968 802D5FB8 0000202D */  daddu     $a0, $zero, $zero
/* FA96C 802D5FBC 00021400 */  sll       $v0, $v0, 0x10
/* FA970 802D5FC0 0C052AC3 */  jal       func_8014AB0C
/* FA974 802D5FC4 00022C03 */   sra      $a1, $v0, 0x10
/* FA978 802D5FC8 8FBF0010 */  lw        $ra, 0x10($sp)
/* FA97C 802D5FCC 24020002 */  addiu     $v0, $zero, 2
/* FA980 802D5FD0 03E00008 */  jr        $ra
/* FA984 802D5FD4 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D5EE0
/* FA890 802D5EE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FA894 802D5EE4 AFBF0010 */  sw        $ra, 0x10($sp)
/* FA898 802D5EE8 8C82000C */  lw        $v0, 0xc($a0)
/* FA89C 802D5EEC 0C0B1EAF */  jal       get_variable
/* FA8A0 802D5EF0 8C450000 */   lw       $a1, ($v0)
/* FA8A4 802D5EF4 3C048016 */  lui       $a0, 0x8016
/* FA8A8 802D5EF8 24849AF0 */  addiu     $a0, $a0, -0x6510
/* FA8AC 802D5EFC 00021840 */  sll       $v1, $v0, 1
/* FA8B0 802D5F00 00621821 */  addu      $v1, $v1, $v0
/* FA8B4 802D5F04 00031900 */  sll       $v1, $v1, 4
/* FA8B8 802D5F08 00641821 */  addu      $v1, $v1, $a0
/* FA8BC 802D5F0C 94640000 */  lhu       $a0, ($v1)
/* FA8C0 802D5F10 24020002 */  addiu     $v0, $zero, 2
/* FA8C4 802D5F14 00822025 */  or        $a0, $a0, $v0
/* FA8C8 802D5F18 A4640000 */  sh        $a0, ($v1)
/* FA8CC 802D5F1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* FA8D0 802D5F20 03E00008 */  jr        $ra
/* FA8D4 802D5F24 27BD0018 */   addiu    $sp, $sp, 0x18

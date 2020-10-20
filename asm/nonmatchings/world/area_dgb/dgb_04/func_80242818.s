.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242818
/* C38D48 80242818 3C028011 */  lui       $v0, 0x8011
/* C38D4C 8024281C 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* C38D50 80242820 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C38D54 80242824 AFBF0010 */  sw        $ra, 0x10($sp)
/* C38D58 80242828 00021100 */  sll       $v0, $v0, 4
/* C38D5C 8024282C 3C048009 */  lui       $a0, 0x8009
/* C38D60 80242830 00822021 */  addu      $a0, $a0, $v0
/* C38D64 80242834 8C84EF20 */  lw        $a0, -0x10e0($a0)
/* C38D68 80242838 0C0496CF */  jal       set_message_string
/* C38D6C 8024283C 0000282D */   daddu    $a1, $zero, $zero
/* C38D70 80242840 8FBF0010 */  lw        $ra, 0x10($sp)
/* C38D74 80242844 24020002 */  addiu     $v0, $zero, 2
/* C38D78 80242848 03E00008 */  jr        $ra
/* C38D7C 8024284C 27BD0018 */   addiu    $sp, $sp, 0x18

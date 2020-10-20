.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870
/* BD40E0 80240870 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD40E4 80240874 AFBF0010 */  sw        $ra, 0x10($sp)
/* BD40E8 80240878 8C840084 */  lw        $a0, 0x84($a0)
/* BD40EC 8024087C 0C04D052 */  jal       set_item_entity_flags
/* BD40F0 80240880 3C050008 */   lui      $a1, 8
/* BD40F4 80240884 8FBF0010 */  lw        $ra, 0x10($sp)
/* BD40F8 80240888 24020002 */  addiu     $v0, $zero, 2
/* BD40FC 8024088C 03E00008 */  jr        $ra
/* BD4100 80240890 27BD0018 */   addiu    $sp, $sp, 0x18
/* BD4104 80240894 00000000 */  nop       
/* BD4108 80240898 00000000 */  nop       
/* BD410C 8024089C 00000000 */  nop       

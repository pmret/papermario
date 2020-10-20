.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802420C4
/* D21F54 802420C4 3C028011 */  lui       $v0, 0x8011
/* D21F58 802420C8 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* D21F5C 802420CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21F60 802420D0 10400003 */  beqz      $v0, .L802420E0
/* D21F64 802420D4 AFBF0010 */   sw       $ra, 0x10($sp)
/* D21F68 802420D8 0C03AE06 */  jal       partner_suspend_ability_script
/* D21F6C 802420DC 00000000 */   nop      
.L802420E0:
/* D21F70 802420E0 24020002 */  addiu     $v0, $zero, 2
/* D21F74 802420E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* D21F78 802420E8 03E00008 */  jr        $ra
/* D21F7C 802420EC 27BD0018 */   addiu    $sp, $sp, 0x18

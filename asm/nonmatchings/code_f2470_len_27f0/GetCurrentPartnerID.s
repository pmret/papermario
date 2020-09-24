.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetCurrentPartnerID
/* F4624 802CFC74 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F4628 802CFC78 AFBF0010 */  sw        $ra, 0x10($sp)
/* F462C 802CFC7C 8C82000C */  lw        $v0, 0xc($a0)
/* F4630 802CFC80 3C068011 */  lui       $a2, 0x8011
/* F4634 802CFC84 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* F4638 802CFC88 0C0B2026 */  jal       set_variable
/* F463C 802CFC8C 8C450000 */   lw       $a1, ($v0)
/* F4640 802CFC90 8FBF0010 */  lw        $ra, 0x10($sp)
/* F4644 802CFC94 24020002 */  addiu     $v0, $zero, 2
/* F4648 802CFC98 03E00008 */  jr        $ra
/* F464C 802CFC9C 27BD0018 */   addiu    $sp, $sp, 0x18

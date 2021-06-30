.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel item_entity_enable_shadow
/* C76AC 80130FAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C76B0 80130FB0 2403FFBF */  addiu     $v1, $zero, -0x41
/* C76B4 80130FB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* C76B8 80130FB8 8C820000 */  lw        $v0, ($a0)
/* C76BC 80130FBC 84850020 */  lh        $a1, 0x20($a0)
/* C76C0 80130FC0 00431024 */  and       $v0, $v0, $v1
/* C76C4 80130FC4 04A00007 */  bltz      $a1, .L80130FE4
/* C76C8 80130FC8 AC820000 */   sw       $v0, ($a0)
/* C76CC 80130FCC 0C044181 */  jal       get_shadow_by_index
/* C76D0 80130FD0 00A0202D */   daddu    $a0, $a1, $zero
/* C76D4 80130FD4 8C430000 */  lw        $v1, ($v0)
/* C76D8 80130FD8 2404FFFE */  addiu     $a0, $zero, -2
/* C76DC 80130FDC 00641824 */  and       $v1, $v1, $a0
/* C76E0 80130FE0 AC430000 */  sw        $v1, ($v0)
.L80130FE4:
/* C76E4 80130FE4 8FBF0010 */  lw        $ra, 0x10($sp)
/* C76E8 80130FE8 03E00008 */  jr        $ra
/* C76EC 80130FEC 27BD0018 */   addiu    $sp, $sp, 0x18

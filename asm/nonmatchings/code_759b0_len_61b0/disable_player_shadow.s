.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel disable_player_shadow
/* 79594 800E00E4 3C048011 */  lui       $a0, 0x8011
/* 79598 800E00E8 8C84F094 */  lw        $a0, -0xf6c($a0)
/* 7959C 800E00EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 795A0 800E00F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 795A4 800E00F4 0C044181 */  jal       get_shadow_by_index
/* 795A8 800E00F8 00000000 */   nop      
/* 795AC 800E00FC 8C430000 */  lw        $v1, ($v0)
/* 795B0 800E0100 34630001 */  ori       $v1, $v1, 1
/* 795B4 800E0104 AC430000 */  sw        $v1, ($v0)
/* 795B8 800E0108 8FBF0010 */  lw        $ra, 0x10($sp)
/* 795BC 800E010C 03E00008 */  jr        $ra
/* 795C0 800E0110 27BD0018 */   addiu    $sp, $sp, 0x18

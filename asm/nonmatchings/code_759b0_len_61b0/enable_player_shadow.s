.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_player_shadow
/* 79560 800E00B0 3C048011 */  lui       $a0, 0x8011
/* 79564 800E00B4 8C84F094 */  lw        $a0, -0xf6c($a0)
/* 79568 800E00B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7956C 800E00BC AFBF0010 */  sw        $ra, 0x10($sp)
/* 79570 800E00C0 0C044181 */  jal       get_shadow_by_index
/* 79574 800E00C4 00000000 */   nop      
/* 79578 800E00C8 8C430000 */  lw        $v1, ($v0)
/* 7957C 800E00CC 2404FFFE */  addiu     $a0, $zero, -2
/* 79580 800E00D0 00641824 */  and       $v1, $v1, $a0
/* 79584 800E00D4 AC430000 */  sw        $v1, ($v0)
/* 79588 800E00D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7958C 800E00DC 03E00008 */  jr        $ra
/* 79590 800E00E0 27BD0018 */   addiu    $sp, $sp, 0x18

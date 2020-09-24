.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_player_status
/* 79100 800DFC50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79104 800DFC54 3C048011 */  lui       $a0, 0x8011
/* 79108 800DFC58 2484EFC8 */  addiu     $a0, $a0, -0x1038
/* 7910C 800DFC5C AFBF0010 */  sw        $ra, 0x10($sp)
/* 79110 800DFC60 0C00A580 */  jal       mem_clear
/* 79114 800DFC64 24050288 */   addiu    $a1, $zero, 0x288
/* 79118 800DFC68 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7911C 800DFC6C 03E00008 */  jr        $ra
/* 79120 800DFC70 27BD0018 */   addiu    $sp, $sp, 0x18

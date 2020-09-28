.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_hero_shadows
/* 18488C 80255FAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 184890 80255FB0 3C05800E */  lui       $a1, 0x800e
/* 184894 80255FB4 8CA5C14C */  lw        $a1, -0x3eb4($a1)
/* 184898 80255FB8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 18489C 80255FBC 0C09566F */  jal       update_actor_shadow
/* 1848A0 80255FC0 24040001 */   addiu    $a0, $zero, 1
/* 1848A4 80255FC4 0C095EEB */  jal       update_player_actor_shadow
/* 1848A8 80255FC8 00000000 */   nop      
/* 1848AC 80255FCC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1848B0 80255FD0 03E00008 */  jr        $ra
/* 1848B4 80255FD4 27BD0018 */   addiu    $sp, $sp, 0x18

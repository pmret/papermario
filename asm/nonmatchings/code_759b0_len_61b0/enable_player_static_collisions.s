.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_player_static_collisions
/* 795F0 800E0140 3C048011 */  lui       $a0, 0x8011
/* 795F4 800E0144 2484EFC8 */  addiu     $a0, $a0, -0x1038
/* 795F8 800E0148 90820014 */  lbu       $v0, 0x14($a0)
/* 795FC 800E014C 2442FFFF */  addiu     $v0, $v0, -1
/* 79600 800E0150 A0820014 */  sb        $v0, 0x14($a0)
/* 79604 800E0154 00021600 */  sll       $v0, $v0, 0x18
/* 79608 800E0158 00022E03 */  sra       $a1, $v0, 0x18
/* 7960C 800E015C 14A00004 */  bnez      $a1, .L800E0170
/* 79610 800E0160 2403EFFF */   addiu    $v1, $zero, -0x1001
/* 79614 800E0164 8C820000 */  lw        $v0, ($a0)
/* 79618 800E0168 00431024 */  and       $v0, $v0, $v1
/* 7961C 800E016C AC820000 */  sw        $v0, ($a0)
.L800E0170:
/* 79620 800E0170 03E00008 */  jr        $ra
/* 79624 800E0174 00A0102D */   daddu    $v0, $a1, $zero

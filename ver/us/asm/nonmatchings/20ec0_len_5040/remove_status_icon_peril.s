.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel remove_status_icon_peril
/* 234F4 800480F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 234F8 800480F8 00041040 */  sll       $v0, $a0, 1
/* 234FC 800480FC 00441021 */  addu      $v0, $v0, $a0
/* 23500 80048100 00021080 */  sll       $v0, $v0, 2
/* 23504 80048104 00441023 */  subu      $v0, $v0, $a0
/* 23508 80048108 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 2350C 8004810C 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 23510 80048110 00021100 */  sll       $v0, $v0, 4
/* 23514 80048114 AFBF0010 */  sw        $ra, 0x10($sp)
/* 23518 80048118 00621821 */  addu      $v1, $v1, $v0
/* 2351C 8004811C 806200A0 */  lb        $v0, 0xa0($v1)
/* 23520 80048120 10400004 */  beqz      $v0, .L80048134
/* 23524 80048124 00000000 */   nop
/* 23528 80048128 8C6400A4 */  lw        $a0, 0xa4($v1)
/* 2352C 8004812C 0C05123D */  jal       free_hud_element
/* 23530 80048130 A06000A0 */   sb       $zero, 0xa0($v1)
.L80048134:
/* 23534 80048134 8FBF0010 */  lw        $ra, 0x10($sp)
/* 23538 80048138 03E00008 */  jr        $ra
/* 2353C 8004813C 27BD0018 */   addiu    $sp, $sp, 0x18

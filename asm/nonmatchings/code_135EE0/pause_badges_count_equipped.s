.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_count_equipped
/* 13A3F0 802470B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13A3F4 802470B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 13A3F8 802470B8 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 13A3FC 802470BC 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 13A400 802470C0 26040208 */  addiu     $a0, $s0, 0x208
/* 13A404 802470C4 3C068024 */  lui       $a2, 0x8024
/* 13A408 802470C8 24C66FE0 */  addiu     $a2, $a2, 0x6fe0
/* 13A40C 802470CC AFBF0014 */  sw        $ra, 0x14($sp)
/* 13A410 802470D0 0C091293 */  jal       pause_sort_item_list
/* 13A414 802470D4 24050040 */   addiu    $a1, $zero, 0x40
/* 13A418 802470D8 0000182D */  daddu     $v1, $zero, $zero
.L802470DC:
/* 13A41C 802470DC 86020208 */  lh        $v0, 0x208($s0)
/* 13A420 802470E0 10400005 */  beqz      $v0, .L802470F8
/* 13A424 802470E4 00000000 */   nop      
/* 13A428 802470E8 24630001 */  addiu     $v1, $v1, 1
/* 13A42C 802470EC 28620040 */  slti      $v0, $v1, 0x40
/* 13A430 802470F0 1440FFFA */  bnez      $v0, .L802470DC
/* 13A434 802470F4 26100002 */   addiu    $s0, $s0, 2
.L802470F8:
/* 13A438 802470F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 13A43C 802470FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 13A440 80247100 0060102D */  daddu     $v0, $v1, $zero
/* 13A444 80247104 03E00008 */  jr        $ra
/* 13A448 80247108 27BD0018 */   addiu    $sp, $sp, 0x18

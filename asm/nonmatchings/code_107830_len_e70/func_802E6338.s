.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E6338
/* 107BB8 802E6338 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 107BBC 802E633C AFBF0014 */  sw        $ra, 0x14($sp)
/* 107BC0 802E6340 AFB00010 */  sw        $s0, 0x10($sp)
/* 107BC4 802E6344 8C900040 */  lw        $s0, 0x40($a0)
/* 107BC8 802E6348 0C03A752 */  jal       is_ability_active
/* 107BCC 802E634C 24040029 */   addiu    $a0, $zero, 0x29
/* 107BD0 802E6350 1040000B */  beqz      $v0, .L802E6380
/* 107BD4 802E6354 00000000 */   nop
/* 107BD8 802E6358 0C05152F */  jal       get_global_flag
/* 107BDC 802E635C 96040006 */   lhu      $a0, 6($s0)
/* 107BE0 802E6360 14400007 */  bnez      $v0, .L802E6380
/* 107BE4 802E6364 00000000 */   nop
/* 107BE8 802E6368 3C038016 */  lui       $v1, %hi(D_8015A578)
/* 107BEC 802E636C 2463A578 */  addiu     $v1, $v1, %lo(D_8015A578)
/* 107BF0 802E6370 80620002 */  lb        $v0, 2($v1)
/* 107BF4 802E6374 14400002 */  bnez      $v0, .L802E6380
/* 107BF8 802E6378 24020001 */   addiu    $v0, $zero, 1
/* 107BFC 802E637C A0620002 */  sb        $v0, 2($v1)
.L802E6380:
/* 107C00 802E6380 8FBF0014 */  lw        $ra, 0x14($sp)
/* 107C04 802E6384 8FB00010 */  lw        $s0, 0x10($sp)
/* 107C08 802E6388 03E00008 */  jr        $ra
/* 107C0C 802E638C 27BD0018 */   addiu    $sp, $sp, 0x18

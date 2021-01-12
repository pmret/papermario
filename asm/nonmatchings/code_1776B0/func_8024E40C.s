.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E40C
/* 17CCEC 8024E40C 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17CCF0 8024E410 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17CCF4 8024E414 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17CCF8 8024E418 14400005 */  bnez      $v0, .L8024E430
/* 17CCFC 8024E41C AFBF0010 */   sw       $ra, 0x10($sp)
/* 17CD00 8024E420 3C01802A */  lui       $at, %hi(D_8029F2A4)
/* 17CD04 8024E424 A020F2A4 */  sb        $zero, %lo(D_8029F2A4)($at)
/* 17CD08 8024E428 0C0933CD */  jal       use_cam_preset
/* 17CD0C 8024E42C 00000000 */   nop
.L8024E430:
/* 17CD10 8024E430 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17CD14 8024E434 03E00008 */  jr        $ra
/* 17CD18 8024E438 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel move_cam_over
/* 17CDB8 8024E4D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 17CDBC 8024E4DC 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17CDC0 8024E4E0 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17CDC4 8024E4E4 0080182D */  daddu     $v1, $a0, $zero
/* 17CDC8 8024E4E8 1440000A */  bnez      $v0, .L8024E514
/* 17CDCC 8024E4EC AFBF0010 */   sw       $ra, 0x10($sp)
/* 17CDD0 8024E4F0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 17CDD4 8024E4F4 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 17CDD8 8024E4F8 8C4400C4 */  lw        $a0, 0xc4($v0)
/* 17CDDC 8024E4FC 3C01802A */  lui       $at, %hi(D_8029F29E)
/* 17CDE0 8024E500 A423F29E */  sh        $v1, %lo(D_8029F29E)($at)
/* 17CDE4 8024E504 10800003 */  beqz      $a0, .L8024E514
/* 17CDE8 8024E508 00000000 */   nop      
/* 17CDEC 8024E50C 0C0B0F41 */  jal       restart_script
/* 17CDF0 8024E510 00000000 */   nop      
.L8024E514:
/* 17CDF4 8024E514 8FBF0010 */  lw        $ra, 0x10($sp)
/* 17CDF8 8024E518 03E00008 */  jr        $ra
/* 17CDFC 8024E51C 27BD0018 */   addiu    $sp, $sp, 0x18

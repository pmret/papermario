.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024E3D8
/* 17CCB8 8024E3D8 3C028028 */  lui   $v0, 0x8028
/* 17CCBC 8024E3DC 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17CCC0 8024E3E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17CCC4 8024E3E4 14400006 */  bnez  $v0, .L8024E400
/* 17CCC8 8024E3E8 AFBF0010 */   sw    $ra, 0x10($sp)
/* 17CCCC 8024E3EC 24020001 */  addiu $v0, $zero, 1
/* 17CCD0 8024E3F0 3C01802A */  lui   $at, 0x802a
/* 17CCD4 8024E3F4 A022F2A4 */  sb    $v0, -0xd5c($at)
/* 17CCD8 8024E3F8 0C0933CD */  jal   use_cam_preset
/* 17CCDC 8024E3FC 00000000 */   nop   
.L8024E400:
/* 17CCE0 8024E400 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17CCE4 8024E404 03E00008 */  jr    $ra
/* 17CCE8 8024E408 27BD0018 */   addiu $sp, $sp, 0x18


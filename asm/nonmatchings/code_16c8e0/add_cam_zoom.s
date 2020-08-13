.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel add_cam_zoom
/* 17CE94 8024E5B4 3C028028 */  lui   $v0, 0x8028
/* 17CE98 8024E5B8 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17CE9C 8024E5BC 14400006 */  bnez  $v0, .L8024E5D8
/* 17CEA0 8024E5C0 00000000 */   nop   
/* 17CEA4 8024E5C4 3C03802A */  lui   $v1, 0x802a
/* 17CEA8 8024E5C8 2463F280 */  addiu $v1, $v1, -0xd80
/* 17CEAC 8024E5CC 94620000 */  lhu   $v0, ($v1)
/* 17CEB0 8024E5D0 00441021 */  addu  $v0, $v0, $a0
/* 17CEB4 8024E5D4 A4620000 */  sh    $v0, ($v1)
.L8024E5D8:
/* 17CEB8 8024E5D8 03E00008 */  jr    $ra
/* 17CEBC 8024E5DC 00000000 */   nop   


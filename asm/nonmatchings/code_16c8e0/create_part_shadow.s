.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel create_part_shadow
/* 195BFC 8026731C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 195C00 80267320 AFB00010 */  sw    $s0, 0x10($sp)
/* 195C04 80267324 AFBF0014 */  sw    $ra, 0x14($sp)
/* 195C08 80267328 0C09A75B */  jal   get_actor
/* 195C0C 8026732C 00A0802D */   daddu $s0, $a1, $zero
/* 195C10 80267330 0040202D */  daddu $a0, $v0, $zero
/* 195C14 80267334 0C099117 */  jal   get_actor_part
/* 195C18 80267338 0200282D */   daddu $a1, $s0, $zero
/* 195C1C 8026733C 0000202D */  daddu $a0, $zero, $zero
/* 195C20 80267340 0040802D */  daddu $s0, $v0, $zero
/* 195C24 80267344 2403FFFB */  addiu $v1, $zero, -5
/* 195C28 80267348 8E050058 */  lw    $a1, 0x58($s0)
/* 195C2C 8026734C 8E020000 */  lw    $v0, ($s0)
/* 195C30 80267350 8E06005C */  lw    $a2, 0x5c($s0)
/* 195C34 80267354 8E070060 */  lw    $a3, 0x60($s0)
/* 195C38 80267358 00431024 */  and   $v0, $v0, $v1
/* 195C3C 8026735C 0C044898 */  jal   create_shadow_type
/* 195C40 80267360 AE020000 */   sw    $v0, ($s0)
/* 195C44 80267364 AE02009C */  sw    $v0, 0x9c($s0)
/* 195C48 80267368 92020072 */  lbu   $v0, 0x72($s0)
/* 195C4C 8026736C 3C014038 */  lui   $at, 0x4038
/* 195C50 80267370 44811800 */  mtc1  $at, $f3
/* 195C54 80267374 44801000 */  mtc1  $zero, $f2
/* 195C58 80267378 44820000 */  mtc1  $v0, $f0
/* 195C5C 8026737C 00000000 */  nop   
/* 195C60 80267380 46800021 */  cvt.d.w $f0, $f0
/* 195C64 80267384 46220003 */  div.d $f0, $f0, $f2
/* 195C68 80267388 46200020 */  cvt.s.d $f0, $f0
/* 195C6C 8026738C E60000A0 */  swc1  $f0, 0xa0($s0)
/* 195C70 80267390 8FBF0014 */  lw    $ra, 0x14($sp)
/* 195C74 80267394 8FB00010 */  lw    $s0, 0x10($sp)
/* 195C78 80267398 03E00008 */  jr    $ra
/* 195C7C 8026739C 27BD0018 */   addiu $sp, $sp, 0x18


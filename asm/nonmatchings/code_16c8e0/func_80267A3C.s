.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80267A3C
/* 19631C 80267A3C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 196320 80267A40 308400FF */  andi  $a0, $a0, 0xff
/* 196324 80267A44 30A500FF */  andi  $a1, $a1, 0xff
/* 196328 80267A48 30C600FF */  andi  $a2, $a2, 0xff
/* 19632C 80267A4C 8FA20038 */  lw    $v0, 0x38($sp)
/* 196330 80267A50 8FA8003C */  lw    $t0, 0x3c($sp)
/* 196334 80267A54 8FA30040 */  lw    $v1, 0x40($sp)
/* 196338 80267A58 8FA90044 */  lw    $t1, 0x44($sp)
/* 19633C 80267A5C 30E700FF */  andi  $a3, $a3, 0xff
/* 196340 80267A60 AFBF0020 */  sw    $ra, 0x20($sp)
/* 196344 80267A64 00431821 */  addu  $v1, $v0, $v1
/* 196348 80267A68 01094821 */  addu  $t1, $t0, $t1
/* 19634C 80267A6C 3042FFFF */  andi  $v0, $v0, 0xffff
/* 196350 80267A70 3108FFFF */  andi  $t0, $t0, 0xffff
/* 196354 80267A74 3063FFFF */  andi  $v1, $v1, 0xffff
/* 196358 80267A78 3129FFFF */  andi  $t1, $t1, 0xffff
/* 19635C 80267A7C AFA20010 */  sw    $v0, 0x10($sp)
/* 196360 80267A80 AFA80014 */  sw    $t0, 0x14($sp)
/* 196364 80267A84 AFA30018 */  sw    $v1, 0x18($sp)
/* 196368 80267A88 0C099E1F */  jal   func_8026787C
/* 19636C 80267A8C AFA9001C */   sw    $t1, 0x1c($sp)
/* 196370 80267A90 8FBF0020 */  lw    $ra, 0x20($sp)
/* 196374 80267A94 03E00008 */  jr    $ra
/* 196378 80267A98 27BD0028 */   addiu $sp, $sp, 0x28


.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel bind_trigger
/* 0E8BD0 802C4220 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0E8BD4 802C4224 AFB20038 */  sw    $s2, 0x38($sp)
/* 0E8BD8 802C4228 0080902D */  daddu $s2, $a0, $zero
/* 0E8BDC 802C422C 3C020100 */  lui   $v0, 0x100
/* 0E8BE0 802C4230 00A22825 */  or    $a1, $a1, $v0
/* 0E8BE4 802C4234 AFB3003C */  sw    $s3, 0x3c($sp)
/* 0E8BE8 802C4238 8FB30058 */  lw    $s3, 0x58($sp)
/* 0E8BEC 802C423C 3C02802C */  lui   $v0, 0x802c
/* 0E8BF0 802C4240 2442667C */  addiu $v0, $v0, 0x667c
/* 0E8BF4 802C4244 AFB00030 */  sw    $s0, 0x30($sp)
/* 0E8BF8 802C4248 00E0802D */  daddu $s0, $a3, $zero
/* 0E8BFC 802C424C AFB10034 */  sw    $s1, 0x34($sp)
/* 0E8C00 802C4250 8FB1005C */  lw    $s1, 0x5c($sp)
/* 0E8C04 802C4254 8FA30060 */  lw    $v1, 0x60($sp)
/* 0E8C08 802C4258 27A40010 */  addiu $a0, $sp, 0x10
/* 0E8C0C 802C425C AFBF0040 */  sw    $ra, 0x40($sp)
/* 0E8C10 802C4260 AFA50010 */  sw    $a1, 0x10($sp)
/* 0E8C14 802C4264 AFA60018 */  sw    $a2, 0x18($sp)
/* 0E8C18 802C4268 AFA00024 */  sw    $zero, 0x24($sp)
/* 0E8C1C 802C426C AFA2001C */  sw    $v0, 0x1c($sp)
/* 0E8C20 802C4270 0C0515DB */  jal   create_trigger
/* 0E8C24 802C4274 AFA30028 */   sw    $v1, 0x28($sp)
/* 0E8C28 802C4278 AC520010 */  sw    $s2, 0x10($v0)
/* 0E8C2C 802C427C AC400014 */  sw    $zero, 0x14($v0)
/* 0E8C30 802C4280 AC510018 */  sw    $s1, 0x18($v0)
/* 0E8C34 802C4284 AC50001C */  sw    $s0, 0x1c($v0)
/* 0E8C38 802C4288 AC530020 */  sw    $s3, 0x20($v0)
/* 0E8C3C 802C428C 8FBF0040 */  lw    $ra, 0x40($sp)
/* 0E8C40 802C4290 8FB3003C */  lw    $s3, 0x3c($sp)
/* 0E8C44 802C4294 8FB20038 */  lw    $s2, 0x38($sp)
/* 0E8C48 802C4298 8FB10034 */  lw    $s1, 0x34($sp)
/* 0E8C4C 802C429C 8FB00030 */  lw    $s0, 0x30($sp)
/* 0E8C50 802C42A0 03E00008 */  jr    $ra
/* 0E8C54 802C42A4 27BD0048 */   addiu $sp, $sp, 0x48


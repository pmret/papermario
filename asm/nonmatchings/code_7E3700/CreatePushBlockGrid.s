.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CreatePushBlockGrid
/* 7E4160 802832E0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 7E4164 802832E4 AFB10014 */  sw    $s1, 0x14($sp)
/* 7E4168 802832E8 0080882D */  daddu $s1, $a0, $zero
/* 7E416C 802832EC AFBF0034 */  sw    $ra, 0x34($sp)
/* 7E4170 802832F0 AFBE0030 */  sw    $fp, 0x30($sp)
/* 7E4174 802832F4 AFB7002C */  sw    $s7, 0x2c($sp)
/* 7E4178 802832F8 AFB60028 */  sw    $s6, 0x28($sp)
/* 7E417C 802832FC AFB50024 */  sw    $s5, 0x24($sp)
/* 7E4180 80283300 AFB40020 */  sw    $s4, 0x20($sp)
/* 7E4184 80283304 AFB3001C */  sw    $s3, 0x1c($sp)
/* 7E4188 80283308 AFB20018 */  sw    $s2, 0x18($sp)
/* 7E418C 8028330C AFB00010 */  sw    $s0, 0x10($sp)
/* 7E4190 80283310 8E30000C */  lw    $s0, 0xc($s1)
/* 7E4194 80283314 8E050000 */  lw    $a1, ($s0)
/* 7E4198 80283318 0C0B1EAF */  jal   get_variable
/* 7E419C 8028331C 26100004 */   addiu $s0, $s0, 4
/* 7E41A0 80283320 8E050000 */  lw    $a1, ($s0)
/* 7E41A4 80283324 26100004 */  addiu $s0, $s0, 4
/* 7E41A8 80283328 0220202D */  daddu $a0, $s1, $zero
/* 7E41AC 8028332C 0C0B1EAF */  jal   get_variable
/* 7E41B0 80283330 0040902D */   daddu $s2, $v0, $zero
/* 7E41B4 80283334 8E050000 */  lw    $a1, ($s0)
/* 7E41B8 80283338 26100004 */  addiu $s0, $s0, 4
/* 7E41BC 8028333C 0220202D */  daddu $a0, $s1, $zero
/* 7E41C0 80283340 0C0B1EAF */  jal   get_variable
/* 7E41C4 80283344 0040A82D */   daddu $s5, $v0, $zero
/* 7E41C8 80283348 8E050000 */  lw    $a1, ($s0)
/* 7E41CC 8028334C 26100004 */  addiu $s0, $s0, 4
/* 7E41D0 80283350 0220202D */  daddu $a0, $s1, $zero
/* 7E41D4 80283354 0C0B1EAF */  jal   get_variable
/* 7E41D8 80283358 0040A02D */   daddu $s4, $v0, $zero
/* 7E41DC 8028335C 8E050000 */  lw    $a1, ($s0)
/* 7E41E0 80283360 26100004 */  addiu $s0, $s0, 4
/* 7E41E4 80283364 0220202D */  daddu $a0, $s1, $zero
/* 7E41E8 80283368 0C0B1EAF */  jal   get_variable
/* 7E41EC 8028336C 0040F02D */   daddu $fp, $v0, $zero
/* 7E41F0 80283370 0220202D */  daddu $a0, $s1, $zero
/* 7E41F4 80283374 8E050000 */  lw    $a1, ($s0)
/* 7E41F8 80283378 0C0B1EAF */  jal   get_variable
/* 7E41FC 8028337C 0040B82D */   daddu $s7, $v0, $zero
/* 7E4200 80283380 02B40018 */  mult  $s5, $s4
/* 7E4204 80283384 26100004 */  addiu $s0, $s0, 4
/* 7E4208 80283388 0220202D */  daddu $a0, $s1, $zero
/* 7E420C 8028338C 8E050000 */  lw    $a1, ($s0)
/* 7E4210 80283390 00008812 */  mflo  $s1
/* 7E4214 80283394 0C0B1EAF */  jal   get_variable
/* 7E4218 80283398 0040B02D */   daddu $s6, $v0, $zero
/* 7E421C 8028339C 2404001C */  addiu $a0, $zero, 0x1c
/* 7E4220 802833A0 0C00AB0A */  jal   general_heap_malloc
/* 7E4224 802833A4 0040982D */   daddu $s3, $v0, $zero
/* 7E4228 802833A8 00129080 */  sll   $s2, $s2, 2
/* 7E422C 802833AC 0040802D */  daddu $s0, $v0, $zero
/* 7E4230 802833B0 3C01802E */  lui   $at, 0x802e
/* 7E4234 802833B4 00320821 */  addu  $at, $at, $s2
/* 7E4238 802833B8 AC30BC88 */  sw    $s0, -0x4378($at)
/* 7E423C 802833BC 0C00AB0A */  jal   general_heap_malloc
/* 7E4240 802833C0 0220202D */   daddu $a0, $s1, $zero
/* 7E4244 802833C4 1660000D */  bnez  $s3, .L802833FC
/* 7E4248 802833C8 AE020000 */   sw    $v0, ($s0)
/* 7E424C 802833CC 1A200018 */  blez  $s1, .L80283430
/* 7E4250 802833D0 0000282D */   daddu $a1, $zero, $zero
/* 7E4254 802833D4 0220202D */  daddu $a0, $s1, $zero
.L802833D8:
/* 7E4258 802833D8 8E020000 */  lw    $v0, ($s0)
/* 7E425C 802833DC 00451021 */  addu  $v0, $v0, $a1
/* 7E4260 802833E0 24A50001 */  addiu $a1, $a1, 1
/* 7E4264 802833E4 A0400000 */  sb    $zero, ($v0)
/* 7E4268 802833E8 00A4102A */  slt   $v0, $a1, $a0
/* 7E426C 802833EC 1440FFFA */  bnez  $v0, .L802833D8
/* 7E4270 802833F0 00000000 */   nop   
/* 7E4274 802833F4 080A0D0D */  j     .L80283434
/* 7E4278 802833F8 A2150004 */   sb    $s5, 4($s0)

.L802833FC:
/* 7E427C 802833FC 0000282D */  daddu $a1, $zero, $zero
/* 7E4280 80283400 1A20000B */  blez  $s1, .L80283430
/* 7E4284 80283404 0260302D */   daddu $a2, $s3, $zero
/* 7E4288 80283408 0220202D */  daddu $a0, $s1, $zero
/* 7E428C 8028340C 00C51021 */  addu  $v0, $a2, $a1
.L80283410:
/* 7E4290 80283410 8E030000 */  lw    $v1, ($s0)
/* 7E4294 80283414 90420000 */  lbu   $v0, ($v0)
/* 7E4298 80283418 00651821 */  addu  $v1, $v1, $a1
/* 7E429C 8028341C 24A50001 */  addiu $a1, $a1, 1
/* 7E42A0 80283420 A0620000 */  sb    $v0, ($v1)
/* 7E42A4 80283424 00A4102A */  slt   $v0, $a1, $a0
/* 7E42A8 80283428 1440FFF9 */  bnez  $v0, .L80283410
/* 7E42AC 8028342C 00C51021 */   addu  $v0, $a2, $a1
.L80283430:
/* 7E42B0 80283430 A2150004 */  sb    $s5, 4($s0)
.L80283434:
/* 7E42B4 80283434 A2140005 */  sb    $s4, 5($s0)
/* 7E42B8 80283438 AE1E0008 */  sw    $fp, 8($s0)
/* 7E42BC 8028343C AE17000C */  sw    $s7, 0xc($s0)
/* 7E42C0 80283440 AE160010 */  sw    $s6, 0x10($s0)
/* 7E42C4 80283444 AE000014 */  sw    $zero, 0x14($s0)
/* 7E42C8 80283448 8FBF0034 */  lw    $ra, 0x34($sp)
/* 7E42CC 8028344C 8FBE0030 */  lw    $fp, 0x30($sp)
/* 7E42D0 80283450 8FB7002C */  lw    $s7, 0x2c($sp)
/* 7E42D4 80283454 8FB60028 */  lw    $s6, 0x28($sp)
/* 7E42D8 80283458 8FB50024 */  lw    $s5, 0x24($sp)
/* 7E42DC 8028345C 8FB40020 */  lw    $s4, 0x20($sp)
/* 7E42E0 80283460 8FB3001C */  lw    $s3, 0x1c($sp)
/* 7E42E4 80283464 8FB20018 */  lw    $s2, 0x18($sp)
/* 7E42E8 80283468 8FB10014 */  lw    $s1, 0x14($sp)
/* 7E42EC 8028346C 8FB00010 */  lw    $s0, 0x10($sp)
/* 7E42F0 80283470 24020002 */  addiu $v0, $zero, 2
/* 7E42F4 80283474 03E00008 */  jr    $ra
/* 7E42F8 80283478 27BD0038 */   addiu $sp, $sp, 0x38


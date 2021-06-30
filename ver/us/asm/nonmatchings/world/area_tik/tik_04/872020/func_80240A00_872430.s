.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A00_872430
/* 872430 80240A00 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 872434 80240A04 AFB60048 */  sw        $s6, 0x48($sp)
/* 872438 80240A08 0080B02D */  daddu     $s6, $a0, $zero
/* 87243C 80240A0C AFBF0050 */  sw        $ra, 0x50($sp)
/* 872440 80240A10 AFB7004C */  sw        $s7, 0x4c($sp)
/* 872444 80240A14 AFB50044 */  sw        $s5, 0x44($sp)
/* 872448 80240A18 AFB40040 */  sw        $s4, 0x40($sp)
/* 87244C 80240A1C AFB3003C */  sw        $s3, 0x3c($sp)
/* 872450 80240A20 AFB20038 */  sw        $s2, 0x38($sp)
/* 872454 80240A24 AFB10034 */  sw        $s1, 0x34($sp)
/* 872458 80240A28 AFB00030 */  sw        $s0, 0x30($sp)
/* 87245C 80240A2C F7B60060 */  sdc1      $f22, 0x60($sp)
/* 872460 80240A30 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 872464 80240A34 8EC2013C */  lw        $v0, 0x13c($s6)
/* 872468 80240A38 0C044181 */  jal       get_shadow_by_index
/* 87246C 80240A3C 8C440000 */   lw       $a0, ($v0)
/* 872470 80240A40 0040B82D */  daddu     $s7, $v0, $zero
/* 872474 80240A44 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 872478 80240A48 24040012 */   addiu    $a0, $zero, 0x12
/* 87247C 80240A4C 0C046B4C */  jal       get_model_from_list_index
/* 872480 80240A50 0040202D */   daddu    $a0, $v0, $zero
/* 872484 80240A54 27B40018 */  addiu     $s4, $sp, 0x18
/* 872488 80240A58 0280202D */  daddu     $a0, $s4, $zero
/* 87248C 80240A5C 27B3001C */  addiu     $s3, $sp, 0x1c
/* 872490 80240A60 0260282D */  daddu     $a1, $s3, $zero
/* 872494 80240A64 27B20020 */  addiu     $s2, $sp, 0x20
/* 872498 80240A68 0240302D */  daddu     $a2, $s2, $zero
/* 87249C 80240A6C 27B50024 */  addiu     $s5, $sp, 0x24
/* 8724A0 80240A70 02A0382D */  daddu     $a3, $s5, $zero
/* 8724A4 80240A74 27B10028 */  addiu     $s1, $sp, 0x28
/* 8724A8 80240A78 C4400098 */  lwc1      $f0, 0x98($v0)
/* 8724AC 80240A7C C442009C */  lwc1      $f2, 0x9c($v0)
/* 8724B0 80240A80 C44400A0 */  lwc1      $f4, 0xa0($v0)
/* 8724B4 80240A84 3C01447A */  lui       $at, 0x447a
/* 8724B8 80240A88 4481B000 */  mtc1      $at, $f22
/* 8724BC 80240A8C 27B0002C */  addiu     $s0, $sp, 0x2c
/* 8724C0 80240A90 E7B6002C */  swc1      $f22, 0x2c($sp)
/* 8724C4 80240A94 E7A00018 */  swc1      $f0, 0x18($sp)
/* 8724C8 80240A98 E7A2001C */  swc1      $f2, 0x1c($sp)
/* 8724CC 80240A9C E7A40020 */  swc1      $f4, 0x20($sp)
/* 8724D0 80240AA0 AFB10010 */  sw        $s1, 0x10($sp)
/* 8724D4 80240AA4 0C04497A */  jal       entity_raycast_down
/* 8724D8 80240AA8 AFB00014 */   sw       $s0, 0x14($sp)
/* 8724DC 80240AAC 8FA5002C */  lw        $a1, 0x2c($sp)
/* 8724E0 80240AB0 0C044A17 */  jal       set_standard_shadow_scale
/* 8724E4 80240AB4 02E0202D */   daddu    $a0, $s7, $zero
/* 8724E8 80240AB8 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 8724EC 80240ABC C7A4001C */  lwc1      $f4, 0x1c($sp)
/* 8724F0 80240AC0 C6E2001C */  lwc1      $f2, 0x1c($s7)
/* 8724F4 80240AC4 3C014090 */  lui       $at, 0x4090
/* 8724F8 80240AC8 4481A000 */  mtc1      $at, $f20
/* 8724FC 80240ACC AEE0002C */  sw        $zero, 0x2c($s7)
/* 872500 80240AD0 46141082 */  mul.s     $f2, $f2, $f20
/* 872504 80240AD4 00000000 */  nop
/* 872508 80240AD8 E6E00010 */  swc1      $f0, 0x10($s7)
/* 87250C 80240ADC E6E40014 */  swc1      $f4, 0x14($s7)
/* 872510 80240AE0 C7A60020 */  lwc1      $f6, 0x20($sp)
/* 872514 80240AE4 C7A80024 */  lwc1      $f8, 0x24($sp)
/* 872518 80240AE8 C6E00024 */  lwc1      $f0, 0x24($s7)
/* 87251C 80240AEC C7A40028 */  lwc1      $f4, 0x28($sp)
/* 872520 80240AF0 46140002 */  mul.s     $f0, $f0, $f20
/* 872524 80240AF4 00000000 */  nop
/* 872528 80240AF8 E6E60018 */  swc1      $f6, 0x18($s7)
/* 87252C 80240AFC E6E80028 */  swc1      $f8, 0x28($s7)
/* 872530 80240B00 E6E40030 */  swc1      $f4, 0x30($s7)
/* 872534 80240B04 E6E2001C */  swc1      $f2, 0x1c($s7)
/* 872538 80240B08 E6E00024 */  swc1      $f0, 0x24($s7)
/* 87253C 80240B0C 8EC2013C */  lw        $v0, 0x13c($s6)
/* 872540 80240B10 0C044181 */  jal       get_shadow_by_index
/* 872544 80240B14 8C440004 */   lw       $a0, 4($v0)
/* 872548 80240B18 0040B82D */  daddu     $s7, $v0, $zero
/* 87254C 80240B1C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* 872550 80240B20 24040014 */   addiu    $a0, $zero, 0x14
/* 872554 80240B24 0C046B4C */  jal       get_model_from_list_index
/* 872558 80240B28 0040202D */   daddu    $a0, $v0, $zero
/* 87255C 80240B2C 0280202D */  daddu     $a0, $s4, $zero
/* 872560 80240B30 0260282D */  daddu     $a1, $s3, $zero
/* 872564 80240B34 0240302D */  daddu     $a2, $s2, $zero
/* 872568 80240B38 C4400098 */  lwc1      $f0, 0x98($v0)
/* 87256C 80240B3C C442009C */  lwc1      $f2, 0x9c($v0)
/* 872570 80240B40 C44400A0 */  lwc1      $f4, 0xa0($v0)
/* 872574 80240B44 02A0382D */  daddu     $a3, $s5, $zero
/* 872578 80240B48 E7B6002C */  swc1      $f22, 0x2c($sp)
/* 87257C 80240B4C E7A00018 */  swc1      $f0, 0x18($sp)
/* 872580 80240B50 E7A2001C */  swc1      $f2, 0x1c($sp)
/* 872584 80240B54 E7A40020 */  swc1      $f4, 0x20($sp)
/* 872588 80240B58 AFB10010 */  sw        $s1, 0x10($sp)
/* 87258C 80240B5C 0C04497A */  jal       entity_raycast_down
/* 872590 80240B60 AFB00014 */   sw       $s0, 0x14($sp)
/* 872594 80240B64 8FA5002C */  lw        $a1, 0x2c($sp)
/* 872598 80240B68 0C044A17 */  jal       set_standard_shadow_scale
/* 87259C 80240B6C 02E0202D */   daddu    $a0, $s7, $zero
/* 8725A0 80240B70 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 8725A4 80240B74 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* 8725A8 80240B78 C6E2001C */  lwc1      $f2, 0x1c($s7)
/* 8725AC 80240B7C AEE0002C */  sw        $zero, 0x2c($s7)
/* 8725B0 80240B80 46141082 */  mul.s     $f2, $f2, $f20
/* 8725B4 80240B84 00000000 */  nop
/* 8725B8 80240B88 E6E00010 */  swc1      $f0, 0x10($s7)
/* 8725BC 80240B8C E6E40014 */  swc1      $f4, 0x14($s7)
/* 8725C0 80240B90 C7A60020 */  lwc1      $f6, 0x20($sp)
/* 8725C4 80240B94 C7A80024 */  lwc1      $f8, 0x24($sp)
/* 8725C8 80240B98 C6E00024 */  lwc1      $f0, 0x24($s7)
/* 8725CC 80240B9C C7A40028 */  lwc1      $f4, 0x28($sp)
/* 8725D0 80240BA0 46140002 */  mul.s     $f0, $f0, $f20
/* 8725D4 80240BA4 00000000 */  nop
/* 8725D8 80240BA8 E6E60018 */  swc1      $f6, 0x18($s7)
/* 8725DC 80240BAC E6E80028 */  swc1      $f8, 0x28($s7)
/* 8725E0 80240BB0 E6E40030 */  swc1      $f4, 0x30($s7)
/* 8725E4 80240BB4 E6E2001C */  swc1      $f2, 0x1c($s7)
/* 8725E8 80240BB8 E6E00024 */  swc1      $f0, 0x24($s7)
/* 8725EC 80240BBC 8FBF0050 */  lw        $ra, 0x50($sp)
/* 8725F0 80240BC0 8FB7004C */  lw        $s7, 0x4c($sp)
/* 8725F4 80240BC4 8FB60048 */  lw        $s6, 0x48($sp)
/* 8725F8 80240BC8 8FB50044 */  lw        $s5, 0x44($sp)
/* 8725FC 80240BCC 8FB40040 */  lw        $s4, 0x40($sp)
/* 872600 80240BD0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 872604 80240BD4 8FB20038 */  lw        $s2, 0x38($sp)
/* 872608 80240BD8 8FB10034 */  lw        $s1, 0x34($sp)
/* 87260C 80240BDC 8FB00030 */  lw        $s0, 0x30($sp)
/* 872610 80240BE0 D7B60060 */  ldc1      $f22, 0x60($sp)
/* 872614 80240BE4 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 872618 80240BE8 24020002 */  addiu     $v0, $zero, 2
/* 87261C 80240BEC 03E00008 */  jr        $ra
/* 872620 80240BF0 27BD0068 */   addiu    $sp, $sp, 0x68

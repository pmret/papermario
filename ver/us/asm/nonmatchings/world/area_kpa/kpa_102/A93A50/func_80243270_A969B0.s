.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80245DA0_A994E0
.word L802433CC_A96B0C, L802433DC_A96B1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802433F4_A96B34, L80243414_A96B54, L80243434_A96B74, L802434DC_A96C1C, L802434DC_A96C1C, L8024344C_A96B8C, L80243464_A96BA4, L8024347C_A96BBC, L80243494_A96BD4, L802434B4_A96BF4, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434DC_A96C1C, L802434CC_A96C0C, 0, 0, 0

.section .text

glabel func_80243270_A969B0
/* A969B0 80243270 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A969B4 80243274 AFB40040 */  sw        $s4, 0x40($sp)
/* A969B8 80243278 0080A02D */  daddu     $s4, $a0, $zero
/* A969BC 8024327C AFBF0048 */  sw        $ra, 0x48($sp)
/* A969C0 80243280 AFB50044 */  sw        $s5, 0x44($sp)
/* A969C4 80243284 AFB3003C */  sw        $s3, 0x3c($sp)
/* A969C8 80243288 AFB20038 */  sw        $s2, 0x38($sp)
/* A969CC 8024328C AFB10034 */  sw        $s1, 0x34($sp)
/* A969D0 80243290 AFB00030 */  sw        $s0, 0x30($sp)
/* A969D4 80243294 8E920148 */  lw        $s2, 0x148($s4)
/* A969D8 80243298 86440008 */  lh        $a0, 8($s2)
/* A969DC 8024329C 8E90000C */  lw        $s0, 0xc($s4)
/* A969E0 802432A0 0C00EABB */  jal       get_npc_unsafe
/* A969E4 802432A4 00A0882D */   daddu    $s1, $a1, $zero
/* A969E8 802432A8 0280202D */  daddu     $a0, $s4, $zero
/* A969EC 802432AC 8E050000 */  lw        $a1, ($s0)
/* A969F0 802432B0 0C0B1EAF */  jal       evt_get_variable
/* A969F4 802432B4 0040A82D */   daddu    $s5, $v0, $zero
/* A969F8 802432B8 AFA00010 */  sw        $zero, 0x10($sp)
/* A969FC 802432BC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A96A00 802432C0 8C630030 */  lw        $v1, 0x30($v1)
/* A96A04 802432C4 AFA30014 */  sw        $v1, 0x14($sp)
/* A96A08 802432C8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A96A0C 802432CC 8C63001C */  lw        $v1, 0x1c($v1)
/* A96A10 802432D0 AFA30018 */  sw        $v1, 0x18($sp)
/* A96A14 802432D4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A96A18 802432D8 8C630024 */  lw        $v1, 0x24($v1)
/* A96A1C 802432DC AFA3001C */  sw        $v1, 0x1c($sp)
/* A96A20 802432E0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A96A24 802432E4 8C630028 */  lw        $v1, 0x28($v1)
/* A96A28 802432E8 27B30010 */  addiu     $s3, $sp, 0x10
/* A96A2C 802432EC AFA30020 */  sw        $v1, 0x20($sp)
/* A96A30 802432F0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A96A34 802432F4 3C0142F0 */  lui       $at, 0x42f0
/* A96A38 802432F8 44810000 */  mtc1      $at, $f0
/* A96A3C 802432FC 8C63002C */  lw        $v1, 0x2c($v1)
/* A96A40 80243300 0040802D */  daddu     $s0, $v0, $zero
/* A96A44 80243304 E7A00028 */  swc1      $f0, 0x28($sp)
/* A96A48 80243308 A7A0002C */  sh        $zero, 0x2c($sp)
/* A96A4C 8024330C 12200019 */  beqz      $s1, .L80243374
/* A96A50 80243310 AFA30024 */   sw       $v1, 0x24($sp)
/* A96A54 80243314 8EA20000 */  lw        $v0, ($s5)
/* A96A58 80243318 2403FDFF */  addiu     $v1, $zero, -0x201
/* A96A5C 8024331C 00431024 */  and       $v0, $v0, $v1
/* A96A60 80243320 34420008 */  ori       $v0, $v0, 8
/* A96A64 80243324 3C030020 */  lui       $v1, 0x20
/* A96A68 80243328 00431025 */  or        $v0, $v0, $v1
/* A96A6C 8024332C AEA20000 */  sw        $v0, ($s5)
/* A96A70 80243330 8E420000 */  lw        $v0, ($s2)
/* A96A74 80243334 00431025 */  or        $v0, $v0, $v1
/* A96A78 80243338 AE420000 */  sw        $v0, ($s2)
/* A96A7C 8024333C C6A0003C */  lwc1      $f0, 0x3c($s5)
/* A96A80 80243340 3C014059 */  lui       $at, 0x4059
/* A96A84 80243344 44811800 */  mtc1      $at, $f3
/* A96A88 80243348 44801000 */  mtc1      $zero, $f2
/* A96A8C 8024334C 46000021 */  cvt.d.s   $f0, $f0
/* A96A90 80243350 46220002 */  mul.d     $f0, $f0, $f2
/* A96A94 80243354 00000000 */  nop
/* A96A98 80243358 2402000A */  addiu     $v0, $zero, 0xa
/* A96A9C 8024335C AE40006C */  sw        $zero, 0x6c($s2)
/* A96AA0 80243360 AE400074 */  sw        $zero, 0x74($s2)
/* A96AA4 80243364 4620010D */  trunc.w.d $f4, $f0
/* A96AA8 80243368 E6440070 */  swc1      $f4, 0x70($s2)
/* A96AAC 8024336C A6A0008E */  sh        $zero, 0x8e($s5)
/* A96AB0 80243370 AE820070 */  sw        $v0, 0x70($s4)
.L80243374:
/* A96AB4 80243374 2402FFFB */  addiu     $v0, $zero, -5
/* A96AB8 80243378 A2A200AB */  sb        $v0, 0xab($s5)
/* A96ABC 8024337C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* A96AC0 80243380 30620004 */  andi      $v0, $v1, 4
/* A96AC4 80243384 10400007 */  beqz      $v0, .L802433A4
/* A96AC8 80243388 00000000 */   nop
/* A96ACC 8024338C 824200B4 */  lb        $v0, 0xb4($s2)
/* A96AD0 80243390 14400053 */  bnez      $v0, .L802434E0
/* A96AD4 80243394 0000102D */   daddu    $v0, $zero, $zero
/* A96AD8 80243398 2402FFFB */  addiu     $v0, $zero, -5
/* A96ADC 8024339C 00621024 */  and       $v0, $v1, $v0
/* A96AE0 802433A0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802433A4:
/* A96AE4 802433A4 8E820070 */  lw        $v0, 0x70($s4)
/* A96AE8 802433A8 2443FFF6 */  addiu     $v1, $v0, -0xa
/* A96AEC 802433AC 2C620029 */  sltiu     $v0, $v1, 0x29
/* A96AF0 802433B0 1040004A */  beqz      $v0, L802434DC_A96C1C
/* A96AF4 802433B4 00031080 */   sll      $v0, $v1, 2
/* A96AF8 802433B8 3C018024 */  lui       $at, %hi(jtbl_80245DA0_A994E0)
/* A96AFC 802433BC 00220821 */  addu      $at, $at, $v0
/* A96B00 802433C0 8C225DA0 */  lw        $v0, %lo(jtbl_80245DA0_A994E0)($at)
/* A96B04 802433C4 00400008 */  jr        $v0
/* A96B08 802433C8 00000000 */   nop
dlabel L802433CC_A96B0C
/* A96B0C 802433CC 0280202D */  daddu     $a0, $s4, $zero
/* A96B10 802433D0 0200282D */  daddu     $a1, $s0, $zero
/* A96B14 802433D4 0C090904 */  jal       func_80242410_A95B50
/* A96B18 802433D8 0260302D */   daddu    $a2, $s3, $zero
dlabel L802433DC_A96B1C
/* A96B1C 802433DC 0280202D */  daddu     $a0, $s4, $zero
/* A96B20 802433E0 0200282D */  daddu     $a1, $s0, $zero
/* A96B24 802433E4 0C090913 */  jal       func_8024244C_A95B8C
/* A96B28 802433E8 0260302D */   daddu    $a2, $s3, $zero
/* A96B2C 802433EC 08090D38 */  j         .L802434E0
/* A96B30 802433F0 0000102D */   daddu    $v0, $zero, $zero
dlabel L802433F4_A96B34
/* A96B34 802433F4 0280202D */  daddu     $a0, $s4, $zero
/* A96B38 802433F8 0200282D */  daddu     $a1, $s0, $zero
/* A96B3C 802433FC 0C090976 */  jal       func_802425D8_A95D18
/* A96B40 80243400 0260302D */   daddu    $a2, $s3, $zero
/* A96B44 80243404 8E830070 */  lw        $v1, 0x70($s4)
/* A96B48 80243408 24020010 */  addiu     $v0, $zero, 0x10
/* A96B4C 8024340C 14620034 */  bne       $v1, $v0, .L802434E0
/* A96B50 80243410 0000102D */   daddu    $v0, $zero, $zero
dlabel L80243414_A96B54
/* A96B54 80243414 0280202D */  daddu     $a0, $s4, $zero
/* A96B58 80243418 0200282D */  daddu     $a1, $s0, $zero
/* A96B5C 8024341C 0C090A72 */  jal       func_802429C8_A96108
/* A96B60 80243420 0260302D */   daddu    $a2, $s3, $zero
/* A96B64 80243424 8E830070 */  lw        $v1, 0x70($s4)
/* A96B68 80243428 24020011 */  addiu     $v0, $zero, 0x11
/* A96B6C 8024342C 1462002C */  bne       $v1, $v0, .L802434E0
/* A96B70 80243430 0000102D */   daddu    $v0, $zero, $zero
dlabel L80243434_A96B74
/* A96B74 80243434 0280202D */  daddu     $a0, $s4, $zero
/* A96B78 80243438 0200282D */  daddu     $a1, $s0, $zero
/* A96B7C 8024343C 0C090AAF */  jal       func_80242ABC_A961FC
/* A96B80 80243440 0260302D */   daddu    $a2, $s3, $zero
/* A96B84 80243444 08090D38 */  j         .L802434E0
/* A96B88 80243448 0000102D */   daddu    $v0, $zero, $zero
dlabel L8024344C_A96B8C
/* A96B8C 8024344C 0280202D */  daddu     $a0, $s4, $zero
/* A96B90 80243450 0200282D */  daddu     $a1, $s0, $zero
/* A96B94 80243454 0C090B40 */  jal       func_80242D00_A96440
/* A96B98 80243458 0260302D */   daddu    $a2, $s3, $zero
/* A96B9C 8024345C 08090D38 */  j         .L802434E0
/* A96BA0 80243460 0000102D */   daddu    $v0, $zero, $zero
dlabel L80243464_A96BA4
/* A96BA4 80243464 0280202D */  daddu     $a0, $s4, $zero
/* A96BA8 80243468 0200282D */  daddu     $a1, $s0, $zero
/* A96BAC 8024346C 0C090B4F */  jal       func_80242D3C_A9647C
/* A96BB0 80243470 0260302D */   daddu    $a2, $s3, $zero
/* A96BB4 80243474 08090D38 */  j         .L802434E0
/* A96BB8 80243478 0000102D */   daddu    $v0, $zero, $zero
dlabel L8024347C_A96BBC
/* A96BBC 8024347C 0280202D */  daddu     $a0, $s4, $zero
/* A96BC0 80243480 0200282D */  daddu     $a1, $s0, $zero
/* A96BC4 80243484 0C090BC2 */  jal       func_80242F08_A96648
/* A96BC8 80243488 0260302D */   daddu    $a2, $s3, $zero
/* A96BCC 8024348C 08090D38 */  j         .L802434E0
/* A96BD0 80243490 0000102D */   daddu    $v0, $zero, $zero
dlabel L80243494_A96BD4
/* A96BD4 80243494 0280202D */  daddu     $a0, $s4, $zero
/* A96BD8 80243498 0200282D */  daddu     $a1, $s0, $zero
/* A96BDC 8024349C 0C090BDD */  jal       func_80242F74_A966B4
/* A96BE0 802434A0 0260302D */   daddu    $a2, $s3, $zero
/* A96BE4 802434A4 8E830070 */  lw        $v1, 0x70($s4)
/* A96BE8 802434A8 24020018 */  addiu     $v0, $zero, 0x18
/* A96BEC 802434AC 1462000C */  bne       $v1, $v0, .L802434E0
/* A96BF0 802434B0 0000102D */   daddu    $v0, $zero, $zero
dlabel L802434B4_A96BF4
/* A96BF4 802434B4 0280202D */  daddu     $a0, $s4, $zero
/* A96BF8 802434B8 0200282D */  daddu     $a1, $s0, $zero
/* A96BFC 802434BC 0C090C2A */  jal       func_802430A8_A967E8
/* A96C00 802434C0 0260302D */   daddu    $a2, $s3, $zero
/* A96C04 802434C4 08090D38 */  j         .L802434E0
/* A96C08 802434C8 0000102D */   daddu    $v0, $zero, $zero
dlabel L802434CC_A96C0C
/* A96C0C 802434CC 0280202D */  daddu     $a0, $s4, $zero
/* A96C10 802434D0 0200282D */  daddu     $a1, $s0, $zero
/* A96C14 802434D4 0C090C66 */  jal       func_80243198_A968D8
/* A96C18 802434D8 0260302D */   daddu    $a2, $s3, $zero
dlabel L802434DC_A96C1C
/* A96C1C 802434DC 0000102D */  daddu     $v0, $zero, $zero
.L802434E0:
/* A96C20 802434E0 8FBF0048 */  lw        $ra, 0x48($sp)
/* A96C24 802434E4 8FB50044 */  lw        $s5, 0x44($sp)
/* A96C28 802434E8 8FB40040 */  lw        $s4, 0x40($sp)
/* A96C2C 802434EC 8FB3003C */  lw        $s3, 0x3c($sp)
/* A96C30 802434F0 8FB20038 */  lw        $s2, 0x38($sp)
/* A96C34 802434F4 8FB10034 */  lw        $s1, 0x34($sp)
/* A96C38 802434F8 8FB00030 */  lw        $s0, 0x30($sp)
/* A96C3C 802434FC 03E00008 */  jr        $ra
/* A96C40 80243500 27BD0050 */   addiu    $sp, $sp, 0x50

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414A8_D51498
/* D51498 802414A8 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D5149C 802414AC AFB10014 */  sw        $s1, 0x14($sp)
/* D514A0 802414B0 0080882D */  daddu     $s1, $a0, $zero
/* D514A4 802414B4 AFBF001C */  sw        $ra, 0x1c($sp)
/* D514A8 802414B8 AFB20018 */  sw        $s2, 0x18($sp)
/* D514AC 802414BC AFB00010 */  sw        $s0, 0x10($sp)
/* D514B0 802414C0 F7BA0038 */  sdc1      $f26, 0x38($sp)
/* D514B4 802414C4 F7B80030 */  sdc1      $f24, 0x30($sp)
/* D514B8 802414C8 F7B60028 */  sdc1      $f22, 0x28($sp)
/* D514BC 802414CC F7B40020 */  sdc1      $f20, 0x20($sp)
/* D514C0 802414D0 8E30000C */  lw        $s0, 0xc($s1)
/* D514C4 802414D4 8E050000 */  lw        $a1, ($s0)
/* D514C8 802414D8 0C0B1EAF */  jal       evt_get_variable
/* D514CC 802414DC 26100004 */   addiu    $s0, $s0, 4
/* D514D0 802414E0 8E050000 */  lw        $a1, ($s0)
/* D514D4 802414E4 26100004 */  addiu     $s0, $s0, 4
/* D514D8 802414E8 0220202D */  daddu     $a0, $s1, $zero
/* D514DC 802414EC 0C0B210B */  jal       evt_get_float_variable
/* D514E0 802414F0 0040902D */   daddu    $s2, $v0, $zero
/* D514E4 802414F4 8E050000 */  lw        $a1, ($s0)
/* D514E8 802414F8 26100004 */  addiu     $s0, $s0, 4
/* D514EC 802414FC 0220202D */  daddu     $a0, $s1, $zero
/* D514F0 80241500 0C0B210B */  jal       evt_get_float_variable
/* D514F4 80241504 46000686 */   mov.s    $f26, $f0
/* D514F8 80241508 0220202D */  daddu     $a0, $s1, $zero
/* D514FC 8024150C 8E050000 */  lw        $a1, ($s0)
/* D51500 80241510 0C0B210B */  jal       evt_get_float_variable
/* D51504 80241514 46000606 */   mov.s    $f24, $f0
/* D51508 80241518 0220202D */  daddu     $a0, $s1, $zero
/* D5150C 8024151C 3C05FD05 */  lui       $a1, 0xfd05
/* D51510 80241520 34A50F80 */  ori       $a1, $a1, 0xf80
/* D51514 80241524 0C0B210B */  jal       evt_get_float_variable
/* D51518 80241528 46000586 */   mov.s    $f22, $f0
/* D5151C 8024152C 2402FFFF */  addiu     $v0, $zero, -1
/* D51520 80241530 1242000A */  beq       $s2, $v0, .L8024155C
/* D51524 80241534 46000506 */   mov.s    $f20, $f0
/* D51528 80241538 0C04417A */  jal       get_entity_by_index
/* D5152C 8024153C 0240202D */   daddu    $a0, $s2, $zero
/* D51530 80241540 0040182D */  daddu     $v1, $v0, $zero
/* D51534 80241544 24020002 */  addiu     $v0, $zero, 2
/* D51538 80241548 4614C000 */  add.s     $f0, $f24, $f20
/* D5153C 8024154C E47A0048 */  swc1      $f26, 0x48($v1)
/* D51540 80241550 E4760050 */  swc1      $f22, 0x50($v1)
/* D51544 80241554 08090558 */  j         .L80241560
/* D51548 80241558 E460004C */   swc1     $f0, 0x4c($v1)
.L8024155C:
/* D5154C 8024155C 24020002 */  addiu     $v0, $zero, 2
.L80241560:
/* D51550 80241560 8FBF001C */  lw        $ra, 0x1c($sp)
/* D51554 80241564 8FB20018 */  lw        $s2, 0x18($sp)
/* D51558 80241568 8FB10014 */  lw        $s1, 0x14($sp)
/* D5155C 8024156C 8FB00010 */  lw        $s0, 0x10($sp)
/* D51560 80241570 D7BA0038 */  ldc1      $f26, 0x38($sp)
/* D51564 80241574 D7B80030 */  ldc1      $f24, 0x30($sp)
/* D51568 80241578 D7B60028 */  ldc1      $f22, 0x28($sp)
/* D5156C 8024157C D7B40020 */  ldc1      $f20, 0x20($sp)
/* D51570 80241580 03E00008 */  jr        $ra
/* D51574 80241584 27BD0040 */   addiu    $sp, $sp, 0x40

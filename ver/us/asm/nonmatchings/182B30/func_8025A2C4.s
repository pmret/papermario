.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025A2C4
/* 188BA4 8025A2C4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 188BA8 8025A2C8 AFB20018 */  sw        $s2, 0x18($sp)
/* 188BAC 8025A2CC 0080902D */  daddu     $s2, $a0, $zero
/* 188BB0 8025A2D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 188BB4 8025A2D4 00A0882D */  daddu     $s1, $a1, $zero
/* 188BB8 8025A2D8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 188BBC 8025A2DC 00C0982D */  daddu     $s3, $a2, $zero
/* 188BC0 8025A2E0 AFBF0028 */  sw        $ra, 0x28($sp)
/* 188BC4 8025A2E4 AFB50024 */  sw        $s5, 0x24($sp)
/* 188BC8 8025A2E8 AFB40020 */  sw        $s4, 0x20($sp)
/* 188BCC 8025A2EC AFB00010 */  sw        $s0, 0x10($sp)
/* 188BD0 8025A2F0 8E3000C0 */  lw        $s0, 0xc0($s1)
/* 188BD4 8025A2F4 820206C1 */  lb        $v0, 0x6c1($s0)
/* 188BD8 8025A2F8 8FB50040 */  lw        $s5, 0x40($sp)
/* 188BDC 8025A2FC 10400033 */  beqz      $v0, .L8025A3CC
/* 188BE0 8025A300 00E0A02D */   daddu    $s4, $a3, $zero
/* 188BE4 8025A304 16400018 */  bnez      $s2, .L8025A368
/* 188BE8 8025A308 00000000 */   nop
/* 188BEC 8025A30C 0C0B7830 */  jal       spr_get_player_palettes
/* 188BF0 8025A310 96240088 */   lhu      $a0, 0x88($s1)
/* 188BF4 8025A314 AE0206D0 */  sw        $v0, 0x6d0($s0)
/* 188BF8 8025A318 0040202D */  daddu     $a0, $v0, $zero
/* 188BFC 8025A31C 24020002 */  addiu     $v0, $zero, 2
/* 188C00 8025A320 A20206CD */  sb        $v0, 0x6cd($s0)
/* 188C04 8025A324 8C830008 */  lw        $v1, 8($a0)
/* 188C08 8025A328 2402FFFF */  addiu     $v0, $zero, -1
/* 188C0C 8025A32C 50620024 */  beql      $v1, $v0, .L8025A3C0
/* 188C10 8025A330 A20006C2 */   sb       $zero, 0x6c2($s0)
/* 188C14 8025A334 0080182D */  daddu     $v1, $a0, $zero
/* 188C18 8025A338 0040202D */  daddu     $a0, $v0, $zero
.L8025A33C:
/* 188C1C 8025A33C 920206CD */  lbu       $v0, 0x6cd($s0)
/* 188C20 8025A340 24420001 */  addiu     $v0, $v0, 1
/* 188C24 8025A344 A20206CD */  sb        $v0, 0x6cd($s0)
/* 188C28 8025A348 00021600 */  sll       $v0, $v0, 0x18
/* 188C2C 8025A34C 00021583 */  sra       $v0, $v0, 0x16
/* 188C30 8025A350 00431021 */  addu      $v0, $v0, $v1
/* 188C34 8025A354 8C420000 */  lw        $v0, ($v0)
/* 188C38 8025A358 1444FFF8 */  bne       $v0, $a0, .L8025A33C
/* 188C3C 8025A35C 00000000 */   nop
/* 188C40 8025A360 080968F0 */  j         .L8025A3C0
/* 188C44 8025A364 A20006C2 */   sb       $zero, 0x6c2($s0)
.L8025A368:
/* 188C48 8025A368 96240088 */  lhu       $a0, 0x88($s1)
/* 188C4C 8025A36C 0C0B7A90 */  jal       spr_get_npc_palettes
/* 188C50 8025A370 00000000 */   nop
/* 188C54 8025A374 AE0206D0 */  sw        $v0, 0x6d0($s0)
/* 188C58 8025A378 0040202D */  daddu     $a0, $v0, $zero
/* 188C5C 8025A37C A20006CD */  sb        $zero, 0x6cd($s0)
/* 188C60 8025A380 8C830000 */  lw        $v1, ($a0)
/* 188C64 8025A384 2402FFFF */  addiu     $v0, $zero, -1
/* 188C68 8025A388 5062000D */  beql      $v1, $v0, .L8025A3C0
/* 188C6C 8025A38C A20006C2 */   sb       $zero, 0x6c2($s0)
/* 188C70 8025A390 0080182D */  daddu     $v1, $a0, $zero
/* 188C74 8025A394 0040202D */  daddu     $a0, $v0, $zero
.L8025A398:
/* 188C78 8025A398 920206CD */  lbu       $v0, 0x6cd($s0)
/* 188C7C 8025A39C 24420001 */  addiu     $v0, $v0, 1
/* 188C80 8025A3A0 A20206CD */  sb        $v0, 0x6cd($s0)
/* 188C84 8025A3A4 00021600 */  sll       $v0, $v0, 0x18
/* 188C88 8025A3A8 00021583 */  sra       $v0, $v0, 0x16
/* 188C8C 8025A3AC 00431021 */  addu      $v0, $v0, $v1
/* 188C90 8025A3B0 8C420000 */  lw        $v0, ($v0)
/* 188C94 8025A3B4 1444FFF8 */  bne       $v0, $a0, .L8025A398
/* 188C98 8025A3B8 00000000 */   nop
/* 188C9C 8025A3BC A20006C2 */  sb        $zero, 0x6c2($s0)
.L8025A3C0:
/* 188CA0 8025A3C0 A60006CA */  sh        $zero, 0x6ca($s0)
/* 188CA4 8025A3C4 A60006C8 */  sh        $zero, 0x6c8($s0)
/* 188CA8 8025A3C8 A20006C1 */  sb        $zero, 0x6c1($s0)
.L8025A3CC:
/* 188CAC 8025A3CC 820206CD */  lb        $v0, 0x6cd($s0)
/* 188CB0 8025A3D0 18400024 */  blez      $v0, .L8025A464
/* 188CB4 8025A3D4 0000482D */   daddu    $t1, $zero, $zero
/* 188CB8 8025A3D8 0200502D */  daddu     $t2, $s0, $zero
.L8025A3DC:
/* 188CBC 8025A3DC 8E0206D0 */  lw        $v0, 0x6d0($s0)
/* 188CC0 8025A3E0 00091880 */  sll       $v1, $t1, 2
/* 188CC4 8025A3E4 00621821 */  addu      $v1, $v1, $v0
/* 188CC8 8025A3E8 00091140 */  sll       $v0, $t1, 5
/* 188CCC 8025A3EC 8C660000 */  lw        $a2, ($v1)
/* 188CD0 8025A3F0 02023821 */  addu      $a3, $s0, $v0
/* 188CD4 8025A3F4 10C00016 */  beqz      $a2, .L8025A450
/* 188CD8 8025A3F8 AD4706D4 */   sw       $a3, 0x6d4($t2)
/* 188CDC 8025A3FC 0000402D */  daddu     $t0, $zero, $zero
.L8025A400:
/* 188CE0 8025A400 94C20000 */  lhu       $v0, ($a2)
/* 188CE4 8025A404 90C50001 */  lbu       $a1, 1($a2)
/* 188CE8 8025A408 24C60002 */  addiu     $a2, $a2, 2
/* 188CEC 8025A40C 25080001 */  addiu     $t0, $t0, 1
/* 188CF0 8025A410 000219C2 */  srl       $v1, $v0, 7
/* 188CF4 8025A414 3063000F */  andi      $v1, $v1, 0xf
/* 188CF8 8025A418 00022082 */  srl       $a0, $v0, 2
/* 188CFC 8025A41C 3084000F */  andi      $a0, $a0, 0xf
/* 188D00 8025A420 00021302 */  srl       $v0, $v0, 0xc
/* 188D04 8025A424 30A50001 */  andi      $a1, $a1, 1
/* 188D08 8025A428 000212C0 */  sll       $v0, $v0, 0xb
/* 188D0C 8025A42C 00031980 */  sll       $v1, $v1, 6
/* 188D10 8025A430 00431025 */  or        $v0, $v0, $v1
/* 188D14 8025A434 00042040 */  sll       $a0, $a0, 1
/* 188D18 8025A438 00441025 */  or        $v0, $v0, $a0
/* 188D1C 8025A43C 00A22825 */  or        $a1, $a1, $v0
/* 188D20 8025A440 A4E50000 */  sh        $a1, ($a3)
/* 188D24 8025A444 29020010 */  slti      $v0, $t0, 0x10
/* 188D28 8025A448 1440FFED */  bnez      $v0, .L8025A400
/* 188D2C 8025A44C 24E70002 */   addiu    $a3, $a3, 2
.L8025A450:
/* 188D30 8025A450 820206CD */  lb        $v0, 0x6cd($s0)
/* 188D34 8025A454 25290001 */  addiu     $t1, $t1, 1
/* 188D38 8025A458 0122102A */  slt       $v0, $t1, $v0
/* 188D3C 8025A45C 1440FFDF */  bnez      $v0, .L8025A3DC
/* 188D40 8025A460 254A0004 */   addiu    $t2, $t2, 4
.L8025A464:
/* 188D44 8025A464 860206C8 */  lh        $v0, 0x6c8($s0)
/* 188D48 8025A468 1C400010 */  bgtz      $v0, .L8025A4AC
/* 188D4C 8025A46C 240300FF */   addiu    $v1, $zero, 0xff
/* 188D50 8025A470 04420001 */  bltzl     $v0, .L8025A478
/* 188D54 8025A474 00021023 */   negu     $v0, $v0
.L8025A478:
/* 188D58 8025A478 00021040 */  sll       $v0, $v0, 1
/* 188D5C 8025A47C 3C018028 */  lui       $at, %hi(D_802840B4)
/* 188D60 8025A480 00220821 */  addu      $at, $at, $v0
/* 188D64 8025A484 942240B4 */  lhu       $v0, %lo(D_802840B4)($at)
/* 188D68 8025A488 A6220068 */  sh        $v0, 0x68($s1)
/* 188D6C 8025A48C 00021400 */  sll       $v0, $v0, 0x10
/* 188D70 8025A490 00021403 */  sra       $v0, $v0, 0x10
/* 188D74 8025A494 14430005 */  bne       $v0, $v1, .L8025A4AC
/* 188D78 8025A498 2404003C */   addiu    $a0, $zero, 0x3c
/* 188D7C 8025A49C 0C00A67F */  jal       rand_int
/* 188D80 8025A4A0 A6200068 */   sh       $zero, 0x68($s1)
/* 188D84 8025A4A4 2442001E */  addiu     $v0, $v0, 0x1e
/* 188D88 8025A4A8 A60206C8 */  sh        $v0, 0x6c8($s0)
.L8025A4AC:
/* 188D8C 8025A4AC 16A00004 */  bnez      $s5, .L8025A4C0
/* 188D90 8025A4B0 00000000 */   nop
/* 188D94 8025A4B4 960206C8 */  lhu       $v0, 0x6c8($s0)
/* 188D98 8025A4B8 2442FFFF */  addiu     $v0, $v0, -1
/* 188D9C 8025A4BC A60206C8 */  sh        $v0, 0x6c8($s0)
.L8025A4C0:
/* 188DA0 8025A4C0 16400006 */  bnez      $s2, .L8025A4DC
/* 188DA4 8025A4C4 0220202D */   daddu    $a0, $s1, $zero
/* 188DA8 8025A4C8 0260282D */  daddu     $a1, $s3, $zero
/* 188DAC 8025A4CC 0C096657 */  jal       func_8025995C
/* 188DB0 8025A4D0 0280302D */   daddu    $a2, $s4, $zero
/* 188DB4 8025A4D4 0809693A */  j         .L8025A4E8
/* 188DB8 8025A4D8 00000000 */   nop
.L8025A4DC:
/* 188DBC 8025A4DC 0260282D */  daddu     $a1, $s3, $zero
/* 188DC0 8025A4E0 0C0965B0 */  jal       func_802596C0
/* 188DC4 8025A4E4 0280302D */   daddu    $a2, $s4, $zero
.L8025A4E8:
/* 188DC8 8025A4E8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 188DCC 8025A4EC 8FB50024 */  lw        $s5, 0x24($sp)
/* 188DD0 8025A4F0 8FB40020 */  lw        $s4, 0x20($sp)
/* 188DD4 8025A4F4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 188DD8 8025A4F8 8FB20018 */  lw        $s2, 0x18($sp)
/* 188DDC 8025A4FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 188DE0 8025A500 8FB00010 */  lw        $s0, 0x10($sp)
/* 188DE4 8025A504 03E00008 */  jr        $ra
/* 188DE8 8025A508 27BD0030 */   addiu    $sp, $sp, 0x30

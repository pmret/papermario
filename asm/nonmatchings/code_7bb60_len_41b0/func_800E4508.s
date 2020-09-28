.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E4508
/* 7D9B8 800E4508 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 7D9BC 800E450C AFB00030 */  sw        $s0, 0x30($sp)
/* 7D9C0 800E4510 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7D9C4 800E4514 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7D9C8 800E4518 AFBF0038 */  sw        $ra, 0x38($sp)
/* 7D9CC 800E451C AFB10034 */  sw        $s1, 0x34($sp)
/* 7D9D0 800E4520 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 7D9D4 800E4524 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 7D9D8 800E4528 C6140064 */  lwc1      $f20, 0x64($s0)
/* 7D9DC 800E452C 4480B000 */  mtc1      $zero, $f22
/* 7D9E0 800E4530 00000000 */  nop       
/* 7D9E4 800E4534 4616A032 */  c.eq.s    $f20, $f22
/* 7D9E8 800E4538 00000000 */  nop       
/* 7D9EC 800E453C 45010021 */  bc1t      .L800E45C4
/* 7D9F0 800E4540 0200882D */   daddu    $s1, $s0, $zero
/* 7D9F4 800E4544 27A20028 */  addiu     $v0, $sp, 0x28
/* 7D9F8 800E4548 0000202D */  daddu     $a0, $zero, $zero
/* 7D9FC 800E454C 0200282D */  daddu     $a1, $s0, $zero
/* 7DA00 800E4550 C6000028 */  lwc1      $f0, 0x28($s0)
/* 7DA04 800E4554 C602002C */  lwc1      $f2, 0x2c($s0)
/* 7DA08 800E4558 C6040030 */  lwc1      $f4, 0x30($s0)
/* 7DA0C 800E455C 27A60020 */  addiu     $a2, $sp, 0x20
/* 7DA10 800E4560 E7A00020 */  swc1      $f0, 0x20($sp)
/* 7DA14 800E4564 E7A20024 */  swc1      $f2, 0x24($sp)
/* 7DA18 800E4568 E7A40028 */  swc1      $f4, 0x28($sp)
/* 7DA1C 800E456C C6000088 */  lwc1      $f0, 0x88($s0)
/* 7DA20 800E4570 27A70024 */  addiu     $a3, $sp, 0x24
/* 7DA24 800E4574 AFA20010 */  sw        $v0, 0x10($sp)
/* 7DA28 800E4578 E7B40014 */  swc1      $f20, 0x14($sp)
/* 7DA2C 800E457C 0C037B01 */  jal       do_lateral_collision
/* 7DA30 800E4580 E7A00018 */   swc1     $f0, 0x18($sp)
/* 7DA34 800E4584 C602005C */  lwc1      $f2, 0x5c($s0)
/* 7DA38 800E4588 3C014120 */  lui       $at, 0x4120
/* 7DA3C 800E458C 44810000 */  mtc1      $at, $f0
/* 7DA40 800E4590 C7A40024 */  lwc1      $f4, 0x24($sp)
/* 7DA44 800E4594 C7A60028 */  lwc1      $f6, 0x28($sp)
/* 7DA48 800E4598 46001083 */  div.s     $f2, $f2, $f0
/* 7DA4C 800E459C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 7DA50 800E45A0 4602A501 */  sub.s     $f20, $f20, $f2
/* 7DA54 800E45A4 E604002C */  swc1      $f4, 0x2c($s0)
/* 7DA58 800E45A8 E6060030 */  swc1      $f6, 0x30($s0)
/* 7DA5C 800E45AC 4616A03C */  c.lt.s    $f20, $f22
/* 7DA60 800E45B0 00000000 */  nop       
/* 7DA64 800E45B4 45000002 */  bc1f      .L800E45C0
/* 7DA68 800E45B8 E6000028 */   swc1     $f0, 0x28($s0)
/* 7DA6C 800E45BC 4600B506 */  mov.s     $f20, $f22
.L800E45C0:
/* 7DA70 800E45C0 E6340064 */  swc1      $f20, 0x64($s1)
.L800E45C4:
/* 7DA74 800E45C4 8FBF0038 */  lw        $ra, 0x38($sp)
/* 7DA78 800E45C8 8FB10034 */  lw        $s1, 0x34($sp)
/* 7DA7C 800E45CC 8FB00030 */  lw        $s0, 0x30($sp)
/* 7DA80 800E45D0 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 7DA84 800E45D4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 7DA88 800E45D8 03E00008 */  jr        $ra
/* 7DA8C 800E45DC 27BD0050 */   addiu    $sp, $sp, 0x50

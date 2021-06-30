.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel peach_make_disguise_npc
/* 7FA2C 800E657C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 7FA30 800E6580 0080282D */  daddu     $a1, $a0, $zero
/* 7FA34 800E6584 AFB10024 */  sw        $s1, 0x24($sp)
/* 7FA38 800E6588 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 7FA3C 800E658C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 7FA40 800E6590 27A60010 */  addiu     $a2, $sp, 0x10
/* 7FA44 800E6594 AFBF0028 */  sw        $ra, 0x28($sp)
/* 7FA48 800E6598 14A00003 */  bnez      $a1, .L800E65A8
/* 7FA4C 800E659C AFB00020 */   sw       $s0, 0x20($sp)
/* 7FA50 800E65A0 080399AC */  j         .L800E66B0
/* 7FA54 800E65A4 0000102D */   daddu    $v0, $zero, $zero
.L800E65A8:
/* 7FA58 800E65A8 3C040004 */  lui       $a0, 4
/* 7FA5C 800E65AC 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 7FA60 800E65B0 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 7FA64 800E65B4 24020025 */  addiu     $v0, $zero, 0x25
/* 7FA68 800E65B8 A62200B0 */  sh        $v0, 0xb0($s1)
/* 7FA6C 800E65BC 24020026 */  addiu     $v0, $zero, 0x26
/* 7FA70 800E65C0 A62200B2 */  sh        $v0, 0xb2($s1)
/* 7FA74 800E65C4 A225000C */  sb        $a1, 0xc($s1)
/* 7FA78 800E65C8 A065007F */  sb        $a1, 0x7f($v1)
/* 7FA7C 800E65CC 8223000C */  lb        $v1, 0xc($s1)
/* 7FA80 800E65D0 34840148 */  ori       $a0, $a0, 0x148
/* 7FA84 800E65D4 AFA40010 */  sw        $a0, 0x10($sp)
/* 7FA88 800E65D8 00031040 */  sll       $v0, $v1, 1
/* 7FA8C 800E65DC 00431021 */  addu      $v0, $v0, $v1
/* 7FA90 800E65E0 000210C0 */  sll       $v0, $v0, 3
/* 7FA94 800E65E4 3C01800F */  lui       $at, %hi(world_actions_peachDisguises)
/* 7FA98 800E65E8 00220821 */  addu      $at, $at, $v0
/* 7FA9C 800E65EC 8C227C1C */  lw        $v0, %lo(world_actions_peachDisguises)($at)
/* 7FAA0 800E65F0 00031880 */  sll       $v1, $v1, 2
/* 7FAA4 800E65F4 AFA00018 */  sw        $zero, 0x18($sp)
/* 7FAA8 800E65F8 AFA0001C */  sw        $zero, 0x1c($sp)
/* 7FAAC 800E65FC AFA20014 */  sw        $v0, 0x14($sp)
/* 7FAB0 800E6600 3C05800F */  lui       $a1, %hi(D_800F7C7C)
/* 7FAB4 800E6604 00A32821 */  addu      $a1, $a1, $v1
/* 7FAB8 800E6608 8CA57C7C */  lw        $a1, %lo(D_800F7C7C)($a1)
/* 7FABC 800E660C 0C00E219 */  jal       _create_npc_standard
/* 7FAC0 800E6610 00C0202D */   daddu    $a0, $a2, $zero
/* 7FAC4 800E6614 0040202D */  daddu     $a0, $v0, $zero
/* 7FAC8 800E6618 3C018011 */  lui       $at, %hi(D_8010C96C)
/* 7FACC 800E661C AC24C96C */  sw        $a0, %lo(D_8010C96C)($at)
/* 7FAD0 800E6620 0C00E2B7 */  jal       get_npc_by_index
/* 7FAD4 800E6624 00000000 */   nop
/* 7FAD8 800E6628 0040802D */  daddu     $s0, $v0, $zero
/* 7FADC 800E662C 0C00EAFF */  jal       disable_npc_shadow
/* 7FAE0 800E6630 0200202D */   daddu    $a0, $s0, $zero
/* 7FAE4 800E6634 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* 7FAE8 800E6638 3C0142B4 */  lui       $at, 0x42b4
/* 7FAEC 800E663C 44810000 */  mtc1      $at, $f0
/* 7FAF0 800E6640 00000000 */  nop
/* 7FAF4 800E6644 4602003E */  c.le.s    $f0, $f2
/* 7FAF8 800E6648 00000000 */  nop
/* 7FAFC 800E664C 45000008 */  bc1f      .L800E6670
/* 7FB00 800E6650 00000000 */   nop
/* 7FB04 800E6654 3C014387 */  lui       $at, 0x4387
/* 7FB08 800E6658 44810000 */  mtc1      $at, $f0
/* 7FB0C 800E665C 00000000 */  nop
/* 7FB10 800E6660 4600103C */  c.lt.s    $f2, $f0
/* 7FB14 800E6664 00000000 */  nop
/* 7FB18 800E6668 45010005 */  bc1t      .L800E6680
/* 7FB1C 800E666C 00000000 */   nop
.L800E6670:
/* 7FB20 800E6670 3C014334 */  lui       $at, 0x4334
/* 7FB24 800E6674 44810000 */  mtc1      $at, $f0
/* 7FB28 800E6678 080399A2 */  j         .L800E6688
/* 7FB2C 800E667C 00000000 */   nop
.L800E6680:
/* 7FB30 800E6680 44800000 */  mtc1      $zero, $f0
/* 7FB34 800E6684 00000000 */  nop
.L800E6688:
/* 7FB38 800E6688 44050000 */  mfc1      $a1, $f0
/* 7FB3C 800E668C 0C00ECD0 */  jal       set_npc_yaw
/* 7FB40 800E6690 0200202D */   daddu    $a0, $s0, $zero
/* 7FB44 800E6694 C6200028 */  lwc1      $f0, 0x28($s1)
/* 7FB48 800E6698 E6000038 */  swc1      $f0, 0x38($s0)
/* 7FB4C 800E669C C620002C */  lwc1      $f0, 0x2c($s1)
/* 7FB50 800E66A0 E600003C */  swc1      $f0, 0x3c($s0)
/* 7FB54 800E66A4 C6200030 */  lwc1      $f0, 0x30($s1)
/* 7FB58 800E66A8 0200102D */  daddu     $v0, $s0, $zero
/* 7FB5C 800E66AC E4400040 */  swc1      $f0, 0x40($v0)
.L800E66B0:
/* 7FB60 800E66B0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 7FB64 800E66B4 8FB10024 */  lw        $s1, 0x24($sp)
/* 7FB68 800E66B8 8FB00020 */  lw        $s0, 0x20($sp)
/* 7FB6C 800E66BC 03E00008 */  jr        $ra
/* 7FB70 800E66C0 27BD0030 */   addiu    $sp, $sp, 0x30

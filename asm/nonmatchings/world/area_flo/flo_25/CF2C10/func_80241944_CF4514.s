.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241944_CF4514
/* CF4514 80241944 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CF4518 80241948 AFB40040 */  sw        $s4, 0x40($sp)
/* CF451C 8024194C 0080A02D */  daddu     $s4, $a0, $zero
/* CF4520 80241950 AFBF0048 */  sw        $ra, 0x48($sp)
/* CF4524 80241954 AFB50044 */  sw        $s5, 0x44($sp)
/* CF4528 80241958 AFB3003C */  sw        $s3, 0x3c($sp)
/* CF452C 8024195C AFB20038 */  sw        $s2, 0x38($sp)
/* CF4530 80241960 AFB10034 */  sw        $s1, 0x34($sp)
/* CF4534 80241964 AFB00030 */  sw        $s0, 0x30($sp)
/* CF4538 80241968 8E920148 */  lw        $s2, 0x148($s4)
/* CF453C 8024196C 86440008 */  lh        $a0, 8($s2)
/* CF4540 80241970 8E90000C */  lw        $s0, 0xc($s4)
/* CF4544 80241974 0C00EABB */  jal       get_npc_unsafe
/* CF4548 80241978 00A0882D */   daddu    $s1, $a1, $zero
/* CF454C 8024197C 0280202D */  daddu     $a0, $s4, $zero
/* CF4550 80241980 8E050000 */  lw        $a1, ($s0)
/* CF4554 80241984 0C0B1EAF */  jal       get_variable
/* CF4558 80241988 0040A82D */   daddu    $s5, $v0, $zero
/* CF455C 8024198C AFA00010 */  sw        $zero, 0x10($sp)
/* CF4560 80241990 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF4564 80241994 8C630030 */  lw        $v1, 0x30($v1)
/* CF4568 80241998 AFA30014 */  sw        $v1, 0x14($sp)
/* CF456C 8024199C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF4570 802419A0 8C63001C */  lw        $v1, 0x1c($v1)
/* CF4574 802419A4 AFA30018 */  sw        $v1, 0x18($sp)
/* CF4578 802419A8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF457C 802419AC 8C630024 */  lw        $v1, 0x24($v1)
/* CF4580 802419B0 AFA3001C */  sw        $v1, 0x1c($sp)
/* CF4584 802419B4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF4588 802419B8 8C630028 */  lw        $v1, 0x28($v1)
/* CF458C 802419BC 27B30010 */  addiu     $s3, $sp, 0x10
/* CF4590 802419C0 AFA30020 */  sw        $v1, 0x20($sp)
/* CF4594 802419C4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CF4598 802419C8 3C0142F0 */  lui       $at, 0x42f0
/* CF459C 802419CC 44810000 */  mtc1      $at, $f0
/* CF45A0 802419D0 8C63002C */  lw        $v1, 0x2c($v1)
/* CF45A4 802419D4 0040802D */  daddu     $s0, $v0, $zero
/* CF45A8 802419D8 E7A00028 */  swc1      $f0, 0x28($sp)
/* CF45AC 802419DC A7A0002C */  sh        $zero, 0x2c($sp)
/* CF45B0 802419E0 12200007 */  beqz      $s1, .L80241A00
/* CF45B4 802419E4 AFA30024 */   sw       $v1, 0x24($sp)
/* CF45B8 802419E8 02A0202D */  daddu     $a0, $s5, $zero
/* CF45BC 802419EC 0240282D */  daddu     $a1, $s2, $zero
/* CF45C0 802419F0 0280302D */  daddu     $a2, $s4, $zero
/* CF45C4 802419F4 0C09048A */  jal       func_80241228_CF3DF8
/* CF45C8 802419F8 0200382D */   daddu    $a3, $s0, $zero
/* CF45CC 802419FC AE800070 */  sw        $zero, 0x70($s4)
.L80241A00:
/* CF45D0 80241A00 2402FFFE */  addiu     $v0, $zero, -2
/* CF45D4 80241A04 A2A200AB */  sb        $v0, 0xab($s5)
/* CF45D8 80241A08 8E4300B0 */  lw        $v1, 0xb0($s2)
/* CF45DC 80241A0C 30620004 */  andi      $v0, $v1, 4
/* CF45E0 80241A10 10400007 */  beqz      $v0, .L80241A30
/* CF45E4 80241A14 00000000 */   nop      
/* CF45E8 80241A18 824200B4 */  lb        $v0, 0xb4($s2)
/* CF45EC 80241A1C 1440003A */  bnez      $v0, .L80241B08
/* CF45F0 80241A20 0000102D */   daddu    $v0, $zero, $zero
/* CF45F4 80241A24 2402FFFB */  addiu     $v0, $zero, -5
/* CF45F8 80241A28 00621024 */  and       $v0, $v1, $v0
/* CF45FC 80241A2C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241A30:
/* CF4600 80241A30 8E830070 */  lw        $v1, 0x70($s4)
/* CF4604 80241A34 2C620015 */  sltiu     $v0, $v1, 0x15
/* CF4608 80241A38 10400032 */  beqz      $v0, .L80241B04
/* CF460C 80241A3C 00031080 */   sll      $v0, $v1, 2
/* CF4610 80241A40 3C018024 */  lui       $at, %hi(D_80244F40)
/* CF4614 80241A44 00220821 */  addu      $at, $at, $v0
/* CF4618 80241A48 8C224F40 */  lw        $v0, %lo(D_80244F40)($at)
/* CF461C 80241A4C 00400008 */  jr        $v0
/* CF4620 80241A50 00000000 */   nop      
/* CF4624 80241A54 0280202D */  daddu     $a0, $s4, $zero
/* CF4628 80241A58 0200282D */  daddu     $a1, $s0, $zero
/* CF462C 80241A5C 0C090010 */  jal       func_80240040_CF2C10
/* CF4630 80241A60 0260302D */   daddu    $a2, $s3, $zero
/* CF4634 80241A64 0280202D */  daddu     $a0, $s4, $zero
/* CF4638 80241A68 0200282D */  daddu     $a1, $s0, $zero
/* CF463C 80241A6C 0C09007C */  jal       func_802401F0_CF2DC0
/* CF4640 80241A70 0260302D */   daddu    $a2, $s3, $zero
/* CF4644 80241A74 080906C2 */  j         .L80241B08
/* CF4648 80241A78 0000102D */   daddu    $v0, $zero, $zero
/* CF464C 80241A7C 0280202D */  daddu     $a0, $s4, $zero
/* CF4650 80241A80 0200282D */  daddu     $a1, $s0, $zero
/* CF4654 80241A84 0C090206 */  jal       func_80240818_CF33E8
/* CF4658 80241A88 0260302D */   daddu    $a2, $s3, $zero
/* CF465C 80241A8C 0280202D */  daddu     $a0, $s4, $zero
/* CF4660 80241A90 0200282D */  daddu     $a1, $s0, $zero
/* CF4664 80241A94 0C090236 */  jal       func_802408D8_CF34A8
/* CF4668 80241A98 0260302D */   daddu    $a2, $s3, $zero
/* CF466C 80241A9C 080906C2 */  j         .L80241B08
/* CF4670 80241AA0 0000102D */   daddu    $v0, $zero, $zero
/* CF4674 80241AA4 0280202D */  daddu     $a0, $s4, $zero
/* CF4678 80241AA8 0200282D */  daddu     $a1, $s0, $zero
/* CF467C 80241AAC 0C090307 */  jal       func_80240C1C_CF37EC
/* CF4680 80241AB0 0260302D */   daddu    $a2, $s3, $zero
/* CF4684 80241AB4 0280202D */  daddu     $a0, $s4, $zero
/* CF4688 80241AB8 0200282D */  daddu     $a1, $s0, $zero
/* CF468C 80241ABC 0C090325 */  jal       func_80240C94_CF3864
/* CF4690 80241AC0 0260302D */   daddu    $a2, $s3, $zero
/* CF4694 80241AC4 080906C2 */  j         .L80241B08
/* CF4698 80241AC8 0000102D */   daddu    $v0, $zero, $zero
/* CF469C 80241ACC 0280202D */  daddu     $a0, $s4, $zero
/* CF46A0 80241AD0 0200282D */  daddu     $a1, $s0, $zero
/* CF46A4 80241AD4 0C09054E */  jal       func_80241538_CF4108
/* CF46A8 80241AD8 0260302D */   daddu    $a2, $s3, $zero
/* CF46AC 80241ADC 0280202D */  daddu     $a0, $s4, $zero
/* CF46B0 80241AE0 0200282D */  daddu     $a1, $s0, $zero
/* CF46B4 80241AE4 0C09059A */  jal       func_80241668_CF4238
/* CF46B8 80241AE8 0260302D */   daddu    $a2, $s3, $zero
/* CF46BC 80241AEC 080906C2 */  j         .L80241B08
/* CF46C0 80241AF0 0000102D */   daddu    $v0, $zero, $zero
/* CF46C4 80241AF4 0280202D */  daddu     $a0, $s4, $zero
/* CF46C8 80241AF8 0200282D */  daddu     $a1, $s0, $zero
/* CF46CC 80241AFC 0C09063A */  jal       func_802418E8_CF44B8
/* CF46D0 80241B00 0260302D */   daddu    $a2, $s3, $zero
.L80241B04:
/* CF46D4 80241B04 0000102D */  daddu     $v0, $zero, $zero
.L80241B08:
/* CF46D8 80241B08 8FBF0048 */  lw        $ra, 0x48($sp)
/* CF46DC 80241B0C 8FB50044 */  lw        $s5, 0x44($sp)
/* CF46E0 80241B10 8FB40040 */  lw        $s4, 0x40($sp)
/* CF46E4 80241B14 8FB3003C */  lw        $s3, 0x3c($sp)
/* CF46E8 80241B18 8FB20038 */  lw        $s2, 0x38($sp)
/* CF46EC 80241B1C 8FB10034 */  lw        $s1, 0x34($sp)
/* CF46F0 80241B20 8FB00030 */  lw        $s0, 0x30($sp)
/* CF46F4 80241B24 03E00008 */  jr        $ra
/* CF46F8 80241B28 27BD0050 */   addiu    $sp, $sp, 0x50

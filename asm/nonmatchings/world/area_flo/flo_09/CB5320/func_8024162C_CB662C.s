.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024162C_CB662C
/* CB662C 8024162C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CB6630 80241630 AFB40040 */  sw        $s4, 0x40($sp)
/* CB6634 80241634 0080A02D */  daddu     $s4, $a0, $zero
/* CB6638 80241638 AFBF0048 */  sw        $ra, 0x48($sp)
/* CB663C 8024163C AFB50044 */  sw        $s5, 0x44($sp)
/* CB6640 80241640 AFB3003C */  sw        $s3, 0x3c($sp)
/* CB6644 80241644 AFB20038 */  sw        $s2, 0x38($sp)
/* CB6648 80241648 AFB10034 */  sw        $s1, 0x34($sp)
/* CB664C 8024164C AFB00030 */  sw        $s0, 0x30($sp)
/* CB6650 80241650 8E920148 */  lw        $s2, 0x148($s4)
/* CB6654 80241654 86440008 */  lh        $a0, 8($s2)
/* CB6658 80241658 8E90000C */  lw        $s0, 0xc($s4)
/* CB665C 8024165C 0C00EABB */  jal       get_npc_unsafe
/* CB6660 80241660 00A0882D */   daddu    $s1, $a1, $zero
/* CB6664 80241664 0280202D */  daddu     $a0, $s4, $zero
/* CB6668 80241668 8E050000 */  lw        $a1, ($s0)
/* CB666C 8024166C 0C0B1EAF */  jal       get_variable
/* CB6670 80241670 0040A82D */   daddu    $s5, $v0, $zero
/* CB6674 80241674 AFA00010 */  sw        $zero, 0x10($sp)
/* CB6678 80241678 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CB667C 8024167C 8C630030 */  lw        $v1, 0x30($v1)
/* CB6680 80241680 AFA30014 */  sw        $v1, 0x14($sp)
/* CB6684 80241684 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CB6688 80241688 8C63001C */  lw        $v1, 0x1c($v1)
/* CB668C 8024168C AFA30018 */  sw        $v1, 0x18($sp)
/* CB6690 80241690 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CB6694 80241694 8C630024 */  lw        $v1, 0x24($v1)
/* CB6698 80241698 AFA3001C */  sw        $v1, 0x1c($sp)
/* CB669C 8024169C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CB66A0 802416A0 8C630028 */  lw        $v1, 0x28($v1)
/* CB66A4 802416A4 27B30010 */  addiu     $s3, $sp, 0x10
/* CB66A8 802416A8 AFA30020 */  sw        $v1, 0x20($sp)
/* CB66AC 802416AC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* CB66B0 802416B0 3C0142F0 */  lui       $at, 0x42f0
/* CB66B4 802416B4 44810000 */  mtc1      $at, $f0
/* CB66B8 802416B8 8C63002C */  lw        $v1, 0x2c($v1)
/* CB66BC 802416BC 0040802D */  daddu     $s0, $v0, $zero
/* CB66C0 802416C0 E7A00028 */  swc1      $f0, 0x28($sp)
/* CB66C4 802416C4 A7A0002C */  sh        $zero, 0x2c($sp)
/* CB66C8 802416C8 12200006 */  beqz      $s1, .L802416E4
/* CB66CC 802416CC AFA30024 */   sw       $v1, 0x24($sp)
/* CB66D0 802416D0 02A0202D */  daddu     $a0, $s5, $zero
/* CB66D4 802416D4 0240282D */  daddu     $a1, $s2, $zero
/* CB66D8 802416D8 0280302D */  daddu     $a2, $s4, $zero
/* CB66DC 802416DC 0C090542 */  jal       func_80241508_CB6508
/* CB66E0 802416E0 0200382D */   daddu    $a3, $s0, $zero
.L802416E4:
/* CB66E4 802416E4 2402FFFE */  addiu     $v0, $zero, -2
/* CB66E8 802416E8 A2A200AB */  sb        $v0, 0xab($s5)
/* CB66EC 802416EC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* CB66F0 802416F0 30620004 */  andi      $v0, $v1, 4
/* CB66F4 802416F4 10400007 */  beqz      $v0, .L80241714
/* CB66F8 802416F8 00000000 */   nop      
/* CB66FC 802416FC 824200B4 */  lb        $v0, 0xb4($s2)
/* CB6700 80241700 1440003C */  bnez      $v0, .L802417F4
/* CB6704 80241704 0000102D */   daddu    $v0, $zero, $zero
/* CB6708 80241708 2402FFFB */  addiu     $v0, $zero, -5
/* CB670C 8024170C 00621024 */  and       $v0, $v1, $v0
/* CB6710 80241710 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241714:
/* CB6714 80241714 8E830070 */  lw        $v1, 0x70($s4)
/* CB6718 80241718 2C62000F */  sltiu     $v0, $v1, 0xf
/* CB671C 8024171C 10400034 */  beqz      $v0, .L802417F0
/* CB6720 80241720 00031080 */   sll      $v0, $v1, 2
/* CB6724 80241724 3C018024 */  lui       $at, 0x8024
/* CB6728 80241728 00220821 */  addu      $at, $at, $v0
/* CB672C 8024172C 8C2241B8 */  lw        $v0, 0x41b8($at)
/* CB6730 80241730 00400008 */  jr        $v0
/* CB6734 80241734 00000000 */   nop      
/* CB6738 80241738 0280202D */  daddu     $a0, $s4, $zero
/* CB673C 8024173C 0200282D */  daddu     $a1, $s0, $zero
/* CB6740 80241740 0C0900C8 */  jal       func_80240320_CB5320
/* CB6744 80241744 0260302D */   daddu    $a2, $s3, $zero
/* CB6748 80241748 0280202D */  daddu     $a0, $s4, $zero
/* CB674C 8024174C 0200282D */  daddu     $a1, $s0, $zero
/* CB6750 80241750 0C090134 */  jal       func_802404D0_CB54D0
/* CB6754 80241754 0260302D */   daddu    $a2, $s3, $zero
/* CB6758 80241758 080905FD */  j         .L802417F4
/* CB675C 8024175C 0000102D */   daddu    $v0, $zero, $zero
/* CB6760 80241760 0280202D */  daddu     $a0, $s4, $zero
/* CB6764 80241764 0200282D */  daddu     $a1, $s0, $zero
/* CB6768 80241768 0C0902BE */  jal       UnkNpcAIFunc1
/* CB676C 8024176C 0260302D */   daddu    $a2, $s3, $zero
/* CB6770 80241770 0280202D */  daddu     $a0, $s4, $zero
/* CB6774 80241774 0200282D */  daddu     $a1, $s0, $zero
/* CB6778 80241778 0C0902EE */  jal       func_80240BB8_CB5BB8
/* CB677C 8024177C 0260302D */   daddu    $a2, $s3, $zero
/* CB6780 80241780 080905FD */  j         .L802417F4
/* CB6784 80241784 0000102D */   daddu    $v0, $zero, $zero
/* CB6788 80241788 0280202D */  daddu     $a0, $s4, $zero
/* CB678C 8024178C 0200282D */  daddu     $a1, $s0, $zero
/* CB6790 80241790 0C0903BF */  jal       UnkNpcAIFunc2
/* CB6794 80241794 0260302D */   daddu    $a2, $s3, $zero
/* CB6798 80241798 0280202D */  daddu     $a0, $s4, $zero
/* CB679C 8024179C 0200282D */  daddu     $a1, $s0, $zero
/* CB67A0 802417A0 0C0903DD */  jal       func_80240F74_CB5F74
/* CB67A4 802417A4 0260302D */   daddu    $a2, $s3, $zero
/* CB67A8 802417A8 080905FD */  j         .L802417F4
/* CB67AC 802417AC 0000102D */   daddu    $v0, $zero, $zero
/* CB67B0 802417B0 0280202D */  daddu     $a0, $s4, $zero
/* CB67B4 802417B4 0200282D */  daddu     $a1, $s0, $zero
/* CB67B8 802417B8 0C0903F8 */  jal       func_80240FE0_CB5FE0
/* CB67BC 802417BC 0260302D */   daddu    $a2, $s3, $zero
/* CB67C0 802417C0 080905FD */  j         .L802417F4
/* CB67C4 802417C4 0000102D */   daddu    $v0, $zero, $zero
/* CB67C8 802417C8 0280202D */  daddu     $a0, $s4, $zero
/* CB67CC 802417CC 0200282D */  daddu     $a1, $s0, $zero
/* CB67D0 802417D0 0C090445 */  jal       func_80241114_CB6114
/* CB67D4 802417D4 0260302D */   daddu    $a2, $s3, $zero
/* CB67D8 802417D8 080905FD */  j         .L802417F4
/* CB67DC 802417DC 0000102D */   daddu    $v0, $zero, $zero
/* CB67E0 802417E0 0280202D */  daddu     $a0, $s4, $zero
/* CB67E4 802417E4 0200282D */  daddu     $a1, $s0, $zero
/* CB67E8 802417E8 0C09045E */  jal       func_80241178_CB6178
/* CB67EC 802417EC 0260302D */   daddu    $a2, $s3, $zero
.L802417F0:
/* CB67F0 802417F0 0000102D */  daddu     $v0, $zero, $zero
.L802417F4:
/* CB67F4 802417F4 8FBF0048 */  lw        $ra, 0x48($sp)
/* CB67F8 802417F8 8FB50044 */  lw        $s5, 0x44($sp)
/* CB67FC 802417FC 8FB40040 */  lw        $s4, 0x40($sp)
/* CB6800 80241800 8FB3003C */  lw        $s3, 0x3c($sp)
/* CB6804 80241804 8FB20038 */  lw        $s2, 0x38($sp)
/* CB6808 80241808 8FB10034 */  lw        $s1, 0x34($sp)
/* CB680C 8024180C 8FB00030 */  lw        $s0, 0x30($sp)
/* CB6810 80241810 03E00008 */  jr        $ra
/* CB6814 80241814 27BD0050 */   addiu    $sp, $sp, 0x50
/* CB6818 80241818 00000000 */  nop       
/* CB681C 8024181C 00000000 */  nop       

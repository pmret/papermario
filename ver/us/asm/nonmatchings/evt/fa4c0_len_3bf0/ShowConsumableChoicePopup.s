.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel ShowConsumableChoicePopup
/* FAFEC 802D663C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* FAFF0 802D6640 AFB00010 */  sw        $s0, 0x10($sp)
/* FAFF4 802D6644 0080802D */  daddu     $s0, $a0, $zero
/* FAFF8 802D6648 AFB3001C */  sw        $s3, 0x1c($sp)
/* FAFFC 802D664C 3C138011 */  lui       $s3, %hi(gPlayerData)
/* FB000 802D6650 2673F290 */  addiu     $s3, $s3, %lo(gPlayerData)
/* FB004 802D6654 AFB10014 */  sw        $s1, 0x14($sp)
/* FB008 802D6658 3C11802E */  lui       $s1, %hi(D_802DB830)
/* FB00C 802D665C 2631B830 */  addiu     $s1, $s1, %lo(D_802DB830)
/* FB010 802D6660 AFBF0020 */  sw        $ra, 0x20($sp)
/* FB014 802D6664 AFB20018 */  sw        $s2, 0x18($sp)
/* FB018 802D6668 8E12014C */  lw        $s2, 0x14c($s0)
/* FB01C 802D666C 54A00001 */  bnel      $a1, $zero, .L802D6674
/* FB020 802D6670 AE000070 */   sw       $zero, 0x70($s0)
.L802D6674:
/* FB024 802D6674 8E030070 */  lw        $v1, 0x70($s0)
/* FB028 802D6678 10600005 */  beqz      $v1, .L802D6690
/* FB02C 802D667C 24020001 */   addiu    $v0, $zero, 1
/* FB030 802D6680 1062004B */  beq       $v1, $v0, .L802D67B0
/* FB034 802D6684 0000102D */   daddu    $v0, $zero, $zero
/* FB038 802D6688 080B5A0F */  j         .L802D683C
/* FB03C 802D668C 00000000 */   nop
.L802D6690:
/* FB040 802D6690 0C03805E */  jal       disable_player_input
/* FB044 802D6694 00000000 */   nop
/* FB048 802D6698 0C038045 */  jal       disable_player_static_collisions
/* FB04C 802D669C 00000000 */   nop
/* FB050 802D66A0 0C03BD8A */  jal       partner_disable_input
/* FB054 802D66A4 00000000 */   nop
/* FB058 802D66A8 0C03A5EE */  jal       close_status_menu
/* FB05C 802D66AC 00000000 */   nop
/* FB060 802D66B0 0000482D */  daddu     $t1, $zero, $zero
/* FB064 802D66B4 0120402D */  daddu     $t0, $t1, $zero
/* FB068 802D66B8 3C0C8008 */  lui       $t4, %hi(gItemTable)
/* FB06C 802D66BC 258C78E0 */  addiu     $t4, $t4, %lo(gItemTable)
/* FB070 802D66C0 3C0B8009 */  lui       $t3, %hi(D_8008A680)
/* FB074 802D66C4 256BA680 */  addiu     $t3, $t3, %lo(D_8008A680)
/* FB078 802D66C8 240A0001 */  addiu     $t2, $zero, 1
/* FB07C 802D66CC 0260382D */  daddu     $a3, $s3, $zero
/* FB080 802D66D0 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* FB084 802D66D4 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* FB088 802D66D8 8C620000 */  lw        $v0, ($v1)
/* FB08C 802D66DC 0220302D */  daddu     $a2, $s1, $zero
/* FB090 802D66E0 34420040 */  ori       $v0, $v0, 0x40
/* FB094 802D66E4 AC620000 */  sw        $v0, ($v1)
.L802D66E8:
/* FB098 802D66E8 84E401B4 */  lh        $a0, 0x1b4($a3)
/* FB09C 802D66EC 5080001F */  beql      $a0, $zero, .L802D676C
/* FB0A0 802D66F0 25080001 */   addiu    $t0, $t0, 1
/* FB0A4 802D66F4 8E430028 */  lw        $v1, 0x28($s2)
/* FB0A8 802D66F8 8C620000 */  lw        $v0, ($v1)
/* FB0AC 802D66FC 18400008 */  blez      $v0, .L802D6720
/* FB0B0 802D6700 0000282D */   daddu    $a1, $zero, $zero
.L802D6704:
/* FB0B4 802D6704 54820003 */  bnel      $a0, $v0, .L802D6714
/* FB0B8 802D6708 24630004 */   addiu    $v1, $v1, 4
/* FB0BC 802D670C 080B59C8 */  j         .L802D6720
/* FB0C0 802D6710 24050001 */   addiu    $a1, $zero, 1
.L802D6714:
/* FB0C4 802D6714 8C620000 */  lw        $v0, ($v1)
/* FB0C8 802D6718 1C40FFFA */  bgtz      $v0, .L802D6704
/* FB0CC 802D671C 00000000 */   nop
.L802D6720:
/* FB0D0 802D6720 50A00012 */  beql      $a1, $zero, .L802D676C
/* FB0D4 802D6724 25080001 */   addiu    $t0, $t0, 1
/* FB0D8 802D6728 84E301B4 */  lh        $v1, 0x1b4($a3)
/* FB0DC 802D672C 00031940 */  sll       $v1, $v1, 5
/* FB0E0 802D6730 006C1821 */  addu      $v1, $v1, $t4
/* FB0E4 802D6734 84620004 */  lh        $v0, 4($v1)
/* FB0E8 802D6738 000210C0 */  sll       $v0, $v0, 3
/* FB0EC 802D673C 004B1021 */  addu      $v0, $v0, $t3
/* FB0F0 802D6740 8C420000 */  lw        $v0, ($v0)
/* FB0F4 802D6744 ACC80108 */  sw        $t0, 0x108($a2)
/* FB0F8 802D6748 ACCA018C */  sw        $t2, 0x18c($a2)
/* FB0FC 802D674C ACC20000 */  sw        $v0, ($a2)
/* FB100 802D6750 8C620000 */  lw        $v0, ($v1)
/* FB104 802D6754 ACC20084 */  sw        $v0, 0x84($a2)
/* FB108 802D6758 8C620014 */  lw        $v0, 0x14($v1)
/* FB10C 802D675C 25290001 */  addiu     $t1, $t1, 1
/* FB110 802D6760 ACC20294 */  sw        $v0, 0x294($a2)
/* FB114 802D6764 24C60004 */  addiu     $a2, $a2, 4
/* FB118 802D6768 25080001 */  addiu     $t0, $t0, 1
.L802D676C:
/* FB11C 802D676C 2902000A */  slti      $v0, $t0, 0xa
/* FB120 802D6770 1440FFDD */  bnez      $v0, .L802D66E8
/* FB124 802D6774 24E70002 */   addiu    $a3, $a3, 2
/* FB128 802D6778 15200004 */  bnez      $t1, .L802D678C
/* FB12C 802D677C 2402000C */   addiu    $v0, $zero, 0xc
/* FB130 802D6780 AE000084 */  sw        $zero, 0x84($s0)
/* FB134 802D6784 080B5A0F */  j         .L802D683C
/* FB138 802D6788 24020001 */   addiu    $v0, $zero, 1
.L802D678C:
/* FB13C 802D678C 0220202D */  daddu     $a0, $s1, $zero
/* FB140 802D6790 AE220318 */  sw        $v0, 0x318($s1)
/* FB144 802D6794 AE290324 */  sw        $t1, 0x324($s1)
/* FB148 802D6798 0C03D390 */  jal       btl_create_popup_menu
/* FB14C 802D679C AE200328 */   sw       $zero, 0x328($s1)
/* FB150 802D67A0 24020001 */  addiu     $v0, $zero, 1
/* FB154 802D67A4 AE000074 */  sw        $zero, 0x74($s0)
/* FB158 802D67A8 080B5A0E */  j         .L802D6838
/* FB15C 802D67AC AE020070 */   sw       $v0, 0x70($s0)
.L802D67B0:
/* FB160 802D67B0 8E020074 */  lw        $v0, 0x74($s0)
/* FB164 802D67B4 14400008 */  bnez      $v0, .L802D67D8
/* FB168 802D67B8 24420001 */   addiu    $v0, $v0, 1
/* FB16C 802D67BC 8622032C */  lh        $v0, 0x32c($s1)
/* FB170 802D67C0 1040001D */  beqz      $v0, .L802D6838
/* FB174 802D67C4 AE020078 */   sw       $v0, 0x78($s0)
/* FB178 802D67C8 0C03C4EC */  jal       hide_popup_menu
/* FB17C 802D67CC 00000000 */   nop
/* FB180 802D67D0 8E020074 */  lw        $v0, 0x74($s0)
/* FB184 802D67D4 24420001 */  addiu     $v0, $v0, 1
.L802D67D8:
/* FB188 802D67D8 AE020074 */  sw        $v0, 0x74($s0)
/* FB18C 802D67DC 2842000F */  slti      $v0, $v0, 0xf
/* FB190 802D67E0 14400016 */  bnez      $v0, .L802D683C
/* FB194 802D67E4 0000102D */   daddu    $v0, $zero, $zero
/* FB198 802D67E8 0C03C54E */  jal       destroy_popup_menu
/* FB19C 802D67EC 00000000 */   nop
/* FB1A0 802D67F0 8E030078 */  lw        $v1, 0x78($s0)
/* FB1A4 802D67F4 240200FF */  addiu     $v0, $zero, 0xff
/* FB1A8 802D67F8 54620005 */  bnel      $v1, $v0, .L802D6810
/* FB1AC 802D67FC 2462FFFF */   addiu    $v0, $v1, -1
/* FB1B0 802D6800 2402FFFF */  addiu     $v0, $zero, -1
/* FB1B4 802D6804 AE020084 */  sw        $v0, 0x84($s0)
/* FB1B8 802D6808 080B5A0F */  j         .L802D683C
/* FB1BC 802D680C 24020001 */   addiu    $v0, $zero, 1
.L802D6810:
/* FB1C0 802D6810 00021080 */  sll       $v0, $v0, 2
/* FB1C4 802D6814 00511021 */  addu      $v0, $v0, $s1
/* FB1C8 802D6818 8C430108 */  lw        $v1, 0x108($v0)
/* FB1CC 802D681C 00031040 */  sll       $v0, $v1, 1
/* FB1D0 802D6820 00531021 */  addu      $v0, $v0, $s3
/* FB1D4 802D6824 AE030088 */  sw        $v1, 0x88($s0)
/* FB1D8 802D6828 844301B4 */  lh        $v1, 0x1b4($v0)
/* FB1DC 802D682C 24020001 */  addiu     $v0, $zero, 1
/* FB1E0 802D6830 080B5A0F */  j         .L802D683C
/* FB1E4 802D6834 AE030084 */   sw       $v1, 0x84($s0)
.L802D6838:
/* FB1E8 802D6838 0000102D */  daddu     $v0, $zero, $zero
.L802D683C:
/* FB1EC 802D683C 8FBF0020 */  lw        $ra, 0x20($sp)
/* FB1F0 802D6840 8FB3001C */  lw        $s3, 0x1c($sp)
/* FB1F4 802D6844 8FB20018 */  lw        $s2, 0x18($sp)
/* FB1F8 802D6848 8FB10014 */  lw        $s1, 0x14($sp)
/* FB1FC 802D684C 8FB00010 */  lw        $s0, 0x10($sp)
/* FB200 802D6850 03E00008 */  jr        $ra
/* FB204 802D6854 27BD0028 */   addiu    $sp, $sp, 0x28

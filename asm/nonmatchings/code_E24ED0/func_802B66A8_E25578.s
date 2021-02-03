.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B66A8_E25578
/* E25578 802B66A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2557C 802B66AC AFB00010 */  sw        $s0, 0x10($sp)
/* E25580 802B66B0 3C10802B */  lui       $s0, %hi(D_802B6DB0_E25C80)
/* E25584 802B66B4 26106DB0 */  addiu     $s0, $s0, %lo(D_802B6DB0_E25C80)
/* E25588 802B66B8 AFBF0018 */  sw        $ra, 0x18($sp)
/* E2558C 802B66BC AFB10014 */  sw        $s1, 0x14($sp)
/* E25590 802B66C0 8E040000 */  lw        $a0, ($s0)
/* E25594 802B66C4 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E25598 802B66C8 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E2559C 802B66CC AC80001C */  sw        $zero, 0x1c($a0)
/* E255A0 802B66D0 8E230000 */  lw        $v1, ($s1)
/* E255A4 802B66D4 04630033 */  bgezl     $v1, .L802B67A4
/* E255A8 802B66D8 3C04FEFF */   lui      $a0, 0xfeff
/* E255AC 802B66DC 3C027FFF */  lui       $v0, 0x7fff
/* E255B0 802B66E0 3442FFFF */  ori       $v0, $v0, 0xffff
/* E255B4 802B66E4 00621024 */  and       $v0, $v1, $v0
/* E255B8 802B66E8 3C030020 */  lui       $v1, 0x20
/* E255BC 802B66EC 00431025 */  or        $v0, $v0, $v1
/* E255C0 802B66F0 AE220000 */  sw        $v0, ($s1)
/* E255C4 802B66F4 AC800018 */  sw        $zero, 0x18($a0)
/* E255C8 802B66F8 A22000B6 */  sb        $zero, 0xb6($s1)
/* E255CC 802B66FC AE200054 */  sw        $zero, 0x54($s1)
/* E255D0 802B6700 0C0AD8A9 */  jal       func_802B62A4_E25174
/* E255D4 802B6704 A62000BC */   sh       $zero, 0xbc($s1)
/* E255D8 802B6708 8E030000 */  lw        $v1, ($s0)
/* E255DC 802B670C 0040282D */  daddu     $a1, $v0, $zero
/* E255E0 802B6710 AC650010 */  sw        $a1, 0x10($v1)
/* E255E4 802B6714 3C038011 */  lui       $v1, %hi(gPlayerData+0x1)
/* E255E8 802B6718 8063F291 */  lb        $v1, %lo(gPlayerData+0x1)($v1)
/* E255EC 802B671C 24020002 */  addiu     $v0, $zero, 2
/* E255F0 802B6720 14620008 */  bne       $v1, $v0, .L802B6744
/* E255F4 802B6724 24020001 */   addiu    $v0, $zero, 1
/* E255F8 802B6728 24102117 */  addiu     $s0, $zero, 0x2117
/* E255FC 802B672C 3C040006 */  lui       $a0, 6
/* E25600 802B6730 04A10012 */  bgez      $a1, .L802B677C
/* E25604 802B6734 3484001A */   ori      $a0, $a0, 0x1a
/* E25608 802B6738 3C040006 */  lui       $a0, 6
/* E2560C 802B673C 080AD9DF */  j         .L802B677C
/* E25610 802B6740 34840018 */   ori      $a0, $a0, 0x18
.L802B6744:
/* E25614 802B6744 14620008 */  bne       $v1, $v0, .L802B6768
/* E25618 802B6748 24102115 */   addiu    $s0, $zero, 0x2115
/* E2561C 802B674C 24102116 */  addiu     $s0, $zero, 0x2116
/* E25620 802B6750 3C040006 */  lui       $a0, 6
/* E25624 802B6754 04A10009 */  bgez      $a1, .L802B677C
/* E25628 802B6758 34840016 */   ori      $a0, $a0, 0x16
/* E2562C 802B675C 3C040006 */  lui       $a0, 6
/* E25630 802B6760 080AD9DF */  j         .L802B677C
/* E25634 802B6764 34840014 */   ori      $a0, $a0, 0x14
.L802B6768:
/* E25638 802B6768 3C040006 */  lui       $a0, 6
/* E2563C 802B676C 04A10003 */  bgez      $a1, .L802B677C
/* E25640 802B6770 34840012 */   ori      $a0, $a0, 0x12
/* E25644 802B6774 3C040006 */  lui       $a0, 6
/* E25648 802B6778 34840010 */  ori       $a0, $a0, 0x10
.L802B677C:
/* E2564C 802B677C 0C037FBF */  jal       func_800DFEFC
/* E25650 802B6780 00000000 */   nop
/* E25654 802B6784 0200202D */  daddu     $a0, $s0, $zero
/* E25658 802B6788 0C052736 */  jal       play_sound_at_player
/* E2565C 802B678C 0000282D */   daddu    $a1, $zero, $zero
/* E25660 802B6790 3C02802B */  lui       $v0, %hi(D_802B6DB0_E25C80)
/* E25664 802B6794 8C426DB0 */  lw        $v0, %lo(D_802B6DB0_E25C80)($v0)
/* E25668 802B6798 AC40000C */  sw        $zero, 0xc($v0)
/* E2566C 802B679C AC400014 */  sw        $zero, 0x14($v0)
/* E25670 802B67A0 3C04FEFF */  lui       $a0, 0xfeff
.L802B67A4:
/* E25674 802B67A4 3484FFFF */  ori       $a0, $a0, 0xffff
/* E25678 802B67A8 8E220000 */  lw        $v0, ($s1)
/* E2567C 802B67AC 3C03802B */  lui       $v1, %hi(D_802B6DB0_E25C80)
/* E25680 802B67B0 8C636DB0 */  lw        $v1, %lo(D_802B6DB0_E25C80)($v1)
/* E25684 802B67B4 00442024 */  and       $a0, $v0, $a0
/* E25688 802B67B8 AE240000 */  sw        $a0, ($s1)
/* E2568C 802B67BC 8C620018 */  lw        $v0, 0x18($v1)
/* E25690 802B67C0 28420003 */  slti      $v0, $v0, 3
/* E25694 802B67C4 10400007 */  beqz      $v0, .L802B67E4
/* E25698 802B67C8 3C020004 */   lui      $v0, 4
/* E2569C 802B67CC 00821024 */  and       $v0, $a0, $v0
/* E256A0 802B67D0 10400004 */  beqz      $v0, .L802B67E4
/* E256A4 802B67D4 3C022000 */   lui      $v0, 0x2000
/* E256A8 802B67D8 00821025 */  or        $v0, $a0, $v0
/* E256AC 802B67DC 080ADA03 */  j         .L802B680C
/* E256B0 802B67E0 AE220000 */   sw       $v0, ($s1)
.L802B67E4:
/* E256B4 802B67E4 3C04802B */  lui       $a0, %hi(D_802B6DB0_E25C80)
/* E256B8 802B67E8 8C846DB0 */  lw        $a0, %lo(D_802B6DB0_E25C80)($a0)
/* E256BC 802B67EC 8C830018 */  lw        $v1, 0x18($a0)
/* E256C0 802B67F0 28620002 */  slti      $v0, $v1, 2
/* E256C4 802B67F4 10400003 */  beqz      $v0, .L802B6804
/* E256C8 802B67F8 24620001 */   addiu    $v0, $v1, 1
/* E256CC 802B67FC 080ADA03 */  j         .L802B680C
/* E256D0 802B6800 AC820018 */   sw       $v0, 0x18($a0)
.L802B6804:
/* E256D4 802B6804 0C0ADA08 */  jal       func_802B6820_E256F0
/* E256D8 802B6808 00000000 */   nop
.L802B680C:
/* E256DC 802B680C 8FBF0018 */  lw        $ra, 0x18($sp)
/* E256E0 802B6810 8FB10014 */  lw        $s1, 0x14($sp)
/* E256E4 802B6814 8FB00010 */  lw        $s0, 0x10($sp)
/* E256E8 802B6818 03E00008 */  jr        $ra
/* E256EC 802B681C 27BD0020 */   addiu    $sp, $sp, 0x20

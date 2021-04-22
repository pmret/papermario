.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416F0_9C6AD0
/* 9C6AD0 802416F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C6AD4 802416F4 10A0000B */  beqz      $a1, .L80241724
/* 9C6AD8 802416F8 AFBF0010 */   sw       $ra, 0x10($sp)
/* 9C6ADC 802416FC 3C038025 */  lui       $v1, %hi(D_80251C64)
/* 9C6AE0 80241700 8C631C64 */  lw        $v1, %lo(D_80251C64)($v1)
/* 9C6AE4 80241704 8C620000 */  lw        $v0, ($v1)
/* 9C6AE8 80241708 3C048025 */  lui       $a0, %hi(D_80251C68)
/* 9C6AEC 8024170C 8C841C68 */  lw        $a0, %lo(D_80251C68)($a0)
/* 9C6AF0 80241710 34420010 */  ori       $v0, $v0, 0x10
/* 9C6AF4 80241714 AC620000 */  sw        $v0, ($v1)
/* 9C6AF8 80241718 8C820000 */  lw        $v0, ($a0)
/* 9C6AFC 8024171C 34420010 */  ori       $v0, $v0, 0x10
/* 9C6B00 80241720 AC820000 */  sw        $v0, ($a0)
.L80241724:
/* 9C6B04 80241724 3C048025 */  lui       $a0, %hi(D_80251C60)
/* 9C6B08 80241728 8C841C60 */  lw        $a0, %lo(D_80251C60)($a0)
/* 9C6B0C 8024172C 8C85000C */  lw        $a1, 0xc($a0)
/* 9C6B10 80241730 8CA20018 */  lw        $v0, 0x18($a1)
/* 9C6B14 80241734 8CA30020 */  lw        $v1, 0x20($a1)
/* 9C6B18 80241738 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 9C6B1C 8024173C ACA20018 */  sw        $v0, 0x18($a1)
/* 9C6B20 80241740 8CA20024 */  lw        $v0, 0x24($a1)
/* 9C6B24 80241744 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 9C6B28 80241748 ACA30020 */  sw        $v1, 0x20($a1)
/* 9C6B2C 8024174C 8CA30028 */  lw        $v1, 0x28($a1)
/* 9C6B30 80241750 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 9C6B34 80241754 ACA20024 */  sw        $v0, 0x24($a1)
/* 9C6B38 80241758 8CA2001C */  lw        $v0, 0x1c($a1)
/* 9C6B3C 8024175C 2463FFF6 */  addiu     $v1, $v1, -0xa
/* 9C6B40 80241760 ACA30028 */  sw        $v1, 0x28($a1)
/* 9C6B44 80241764 8CA30018 */  lw        $v1, 0x18($a1)
/* 9C6B48 80241768 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 9C6B4C 8024176C 18600003 */  blez      $v1, .L8024177C
/* 9C6B50 80241770 ACA2001C */   sw       $v0, 0x1c($a1)
/* 9C6B54 80241774 080905E6 */  j         .L80241798
/* 9C6B58 80241778 0000102D */   daddu    $v0, $zero, $zero
.L8024177C:
/* 9C6B5C 8024177C 0C016914 */  jal       remove_effect
/* 9C6B60 80241780 ACA00018 */   sw       $zero, 0x18($a1)
/* 9C6B64 80241784 3C048025 */  lui       $a0, %hi(D_80251C40)
/* 9C6B68 80241788 8C841C40 */  lw        $a0, %lo(D_80251C40)($a0)
/* 9C6B6C 8024178C 0C048D70 */  jal       free_dynamic_entity
/* 9C6B70 80241790 00000000 */   nop
/* 9C6B74 80241794 24020002 */  addiu     $v0, $zero, 2
.L80241798:
/* 9C6B78 80241798 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C6B7C 8024179C 03E00008 */  jr        $ra
/* 9C6B80 802417A0 27BD0018 */   addiu    $sp, $sp, 0x18

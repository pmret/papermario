.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AE0_B356B0
/* B356B0 80240AE0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B356B4 80240AE4 AFB40040 */  sw        $s4, 0x40($sp)
/* B356B8 80240AE8 0080A02D */  daddu     $s4, $a0, $zero
/* B356BC 80240AEC AFBF0044 */  sw        $ra, 0x44($sp)
/* B356C0 80240AF0 AFB3003C */  sw        $s3, 0x3c($sp)
/* B356C4 80240AF4 AFB20038 */  sw        $s2, 0x38($sp)
/* B356C8 80240AF8 AFB10034 */  sw        $s1, 0x34($sp)
/* B356CC 80240AFC AFB00030 */  sw        $s0, 0x30($sp)
/* B356D0 80240B00 8E910148 */  lw        $s1, 0x148($s4)
/* B356D4 80240B04 00A0902D */  daddu     $s2, $a1, $zero
/* B356D8 80240B08 86240008 */  lh        $a0, 8($s1)
/* B356DC 80240B0C 0C00EABB */  jal       get_npc_unsafe
/* B356E0 80240B10 00C0982D */   daddu    $s3, $a2, $zero
/* B356E4 80240B14 8E430014 */  lw        $v1, 0x14($s2)
/* B356E8 80240B18 04600031 */  bltz      $v1, .L80240BE0
/* B356EC 80240B1C 0040802D */   daddu    $s0, $v0, $zero
/* B356F0 80240B20 0260202D */  daddu     $a0, $s3, $zero
/* B356F4 80240B24 AFA00010 */  sw        $zero, 0x10($sp)
/* B356F8 80240B28 8E460024 */  lw        $a2, 0x24($s2)
/* B356FC 80240B2C 8E470028 */  lw        $a3, 0x28($s2)
/* B35700 80240B30 0C01242D */  jal       func_800490B4
/* B35704 80240B34 0220282D */   daddu    $a1, $s1, $zero
/* B35708 80240B38 10400029 */  beqz      $v0, .L80240BE0
/* B3570C 80240B3C 0000202D */   daddu    $a0, $zero, $zero
/* B35710 80240B40 0200282D */  daddu     $a1, $s0, $zero
/* B35714 80240B44 0000302D */  daddu     $a2, $zero, $zero
/* B35718 80240B48 860300A8 */  lh        $v1, 0xa8($s0)
/* B3571C 80240B4C 3C013F80 */  lui       $at, 0x3f80
/* B35720 80240B50 44810000 */  mtc1      $at, $f0
/* B35724 80240B54 3C014000 */  lui       $at, 0x4000
/* B35728 80240B58 44811000 */  mtc1      $at, $f2
/* B3572C 80240B5C 3C01C1A0 */  lui       $at, 0xc1a0
/* B35730 80240B60 44812000 */  mtc1      $at, $f4
/* B35734 80240B64 2402000F */  addiu     $v0, $zero, 0xf
/* B35738 80240B68 AFA2001C */  sw        $v0, 0x1c($sp)
/* B3573C 80240B6C 44833000 */  mtc1      $v1, $f6
/* B35740 80240B70 00000000 */  nop       
/* B35744 80240B74 468031A0 */  cvt.s.w   $f6, $f6
/* B35748 80240B78 44073000 */  mfc1      $a3, $f6
/* B3574C 80240B7C 27A20028 */  addiu     $v0, $sp, 0x28
/* B35750 80240B80 AFA20020 */  sw        $v0, 0x20($sp)
/* B35754 80240B84 E7A00010 */  swc1      $f0, 0x10($sp)
/* B35758 80240B88 E7A20014 */  swc1      $f2, 0x14($sp)
/* B3575C 80240B8C 0C01BFA4 */  jal       fx_emote
/* B35760 80240B90 E7A40018 */   swc1     $f4, 0x18($sp)
/* B35764 80240B94 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B35768 80240B98 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B3576C 80240B9C C60C0038 */  lwc1      $f12, 0x38($s0)
/* B35770 80240BA0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B35774 80240BA4 8C460028 */  lw        $a2, 0x28($v0)
/* B35778 80240BA8 0C00A720 */  jal       atan2
/* B3577C 80240BAC 8C470030 */   lw       $a3, 0x30($v0)
/* B35780 80240BB0 0200202D */  daddu     $a0, $s0, $zero
/* B35784 80240BB4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B35788 80240BB8 3C060020 */  lui       $a2, 0x20
/* B3578C 80240BBC 0C012530 */  jal       func_800494C0
/* B35790 80240BC0 E480000C */   swc1     $f0, 0xc($a0)
/* B35794 80240BC4 8E220018 */  lw        $v0, 0x18($s1)
/* B35798 80240BC8 9442002A */  lhu       $v0, 0x2a($v0)
/* B3579C 80240BCC 30420001 */  andi      $v0, $v0, 1
/* B357A0 80240BD0 14400029 */  bnez      $v0, .L80240C78
/* B357A4 80240BD4 2402000A */   addiu    $v0, $zero, 0xa
/* B357A8 80240BD8 0809031E */  j         .L80240C78
/* B357AC 80240BDC 2402000C */   addiu    $v0, $zero, 0xc
.L80240BE0:
/* B357B0 80240BE0 8602008C */  lh        $v0, 0x8c($s0)
/* B357B4 80240BE4 14400025 */  bnez      $v0, .L80240C7C
/* B357B8 80240BE8 00000000 */   nop      
/* B357BC 80240BEC 9602008E */  lhu       $v0, 0x8e($s0)
/* B357C0 80240BF0 2442FFFF */  addiu     $v0, $v0, -1
/* B357C4 80240BF4 A602008E */  sh        $v0, 0x8e($s0)
/* B357C8 80240BF8 00021400 */  sll       $v0, $v0, 0x10
/* B357CC 80240BFC 1440001F */  bnez      $v0, .L80240C7C
/* B357D0 80240C00 00000000 */   nop      
/* B357D4 80240C04 8E820074 */  lw        $v0, 0x74($s4)
/* B357D8 80240C08 2442FFFF */  addiu     $v0, $v0, -1
/* B357DC 80240C0C 10400019 */  beqz      $v0, .L80240C74
/* B357E0 80240C10 AE820074 */   sw       $v0, 0x74($s4)
/* B357E4 80240C14 8E220018 */  lw        $v0, 0x18($s1)
/* B357E8 80240C18 9442002A */  lhu       $v0, 0x2a($v0)
/* B357EC 80240C1C 30420010 */  andi      $v0, $v0, 0x10
/* B357F0 80240C20 14400007 */  bnez      $v0, .L80240C40
/* B357F4 80240C24 00000000 */   nop      
/* B357F8 80240C28 C600000C */  lwc1      $f0, 0xc($s0)
/* B357FC 80240C2C 3C014334 */  lui       $at, 0x4334
/* B35800 80240C30 44816000 */  mtc1      $at, $f12
/* B35804 80240C34 0C00A6C9 */  jal       clamp_angle
/* B35808 80240C38 460C0300 */   add.s    $f12, $f0, $f12
/* B3580C 80240C3C E600000C */  swc1      $f0, 0xc($s0)
.L80240C40:
/* B35810 80240C40 8E440008 */  lw        $a0, 8($s2)
/* B35814 80240C44 000417C2 */  srl       $v0, $a0, 0x1f
/* B35818 80240C48 00822021 */  addu      $a0, $a0, $v0
/* B3581C 80240C4C 00042043 */  sra       $a0, $a0, 1
/* B35820 80240C50 0C00A67F */  jal       rand_int
/* B35824 80240C54 24840001 */   addiu    $a0, $a0, 1
/* B35828 80240C58 8E430008 */  lw        $v1, 8($s2)
/* B3582C 80240C5C 000327C2 */  srl       $a0, $v1, 0x1f
/* B35830 80240C60 00641821 */  addu      $v1, $v1, $a0
/* B35834 80240C64 00031843 */  sra       $v1, $v1, 1
/* B35838 80240C68 00621821 */  addu      $v1, $v1, $v0
/* B3583C 80240C6C 0809031F */  j         .L80240C7C
/* B35840 80240C70 A603008E */   sh       $v1, 0x8e($s0)
.L80240C74:
/* B35844 80240C74 24020004 */  addiu     $v0, $zero, 4
.L80240C78:
/* B35848 80240C78 AE820070 */  sw        $v0, 0x70($s4)
.L80240C7C:
/* B3584C 80240C7C 8FBF0044 */  lw        $ra, 0x44($sp)
/* B35850 80240C80 8FB40040 */  lw        $s4, 0x40($sp)
/* B35854 80240C84 8FB3003C */  lw        $s3, 0x3c($sp)
/* B35858 80240C88 8FB20038 */  lw        $s2, 0x38($sp)
/* B3585C 80240C8C 8FB10034 */  lw        $s1, 0x34($sp)
/* B35860 80240C90 8FB00030 */  lw        $s0, 0x30($sp)
/* B35864 80240C94 03E00008 */  jr        $ra
/* B35868 80240C98 27BD0048 */   addiu    $sp, $sp, 0x48

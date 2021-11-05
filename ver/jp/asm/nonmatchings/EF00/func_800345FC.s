.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800345FC
/* F9FC 800345FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* FA00 80034600 AFB00010 */  sw        $s0, 0x10($sp)
/* FA04 80034604 3C10800A */  lui       $s0, %hi(D_8009E731)
/* FA08 80034608 2610E731 */  addiu     $s0, $s0, %lo(D_8009E731)
/* FA0C 8003460C AFBF0018 */  sw        $ra, 0x18($sp)
/* FA10 80034610 AFB10014 */  sw        $s1, 0x14($sp)
/* FA14 80034614 82110000 */  lb        $s1, ($s0)
/* FA18 80034618 12200005 */  beqz      $s1, .L80034630
/* FA1C 8003461C 24020002 */   addiu    $v0, $zero, 2
/* FA20 80034620 12220022 */  beq       $s1, $v0, .L800346AC
/* FA24 80034624 00000000 */   nop
/* FA28 80034628 0800D218 */  j         .L80034860
/* FA2C 8003462C 00000000 */   nop
.L80034630:
/* FA30 80034630 0C00F879 */  jal       func_8003E1E4
/* FA34 80034634 00000000 */   nop
/* FA38 80034638 0C00E57C */  jal       func_800395F0
/* FA3C 8003463C 00000000 */   nop
/* FA40 80034640 0C037DC8 */  jal       func_800DF720
/* FA44 80034644 00000000 */   nop
/* FA48 80034648 0C016680 */  jal       func_80059A00
/* FA4C 8003464C 00000000 */   nop
/* FA50 80034650 3C02800A */  lui       $v0, %hi(D_8009A638)
/* FA54 80034654 8C42A638 */  lw        $v0, %lo(D_8009A638)($v0)
/* FA58 80034658 8C430004 */  lw        $v1, 4($v0)
/* FA5C 8003465C 3C02800A */  lui       $v0, %hi(D_8009A62C)
/* FA60 80034660 8C42A62C */  lw        $v0, %lo(D_8009A62C)($v0)
/* FA64 80034664 1462007E */  bne       $v1, $v0, .L80034860
/* FA68 80034668 24020004 */   addiu    $v0, $zero, 4
/* FA6C 8003466C 3C01800A */  lui       $at, %hi(D_8009E730)
/* FA70 80034670 A022E730 */  sb        $v0, %lo(D_8009E730)($at)
/* FA74 80034674 24020002 */  addiu     $v0, $zero, 2
/* FA78 80034678 3C04800A */  lui       $a0, %hi(D_8009A630)
/* FA7C 8003467C 2484A630 */  addiu     $a0, $a0, %lo(D_8009A630)
/* FA80 80034680 A2020000 */  sb        $v0, ($s0)
/* FA84 80034684 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* FA88 80034688 8CA5417C */  lw        $a1, %lo(gGameStatusPtr)($a1)
/* FA8C 8003468C 8C820000 */  lw        $v0, ($a0)
/* FA90 80034690 94A30148 */  lhu       $v1, 0x148($a1)
/* FA94 80034694 34420008 */  ori       $v0, $v0, 8
/* FA98 80034698 AC820000 */  sw        $v0, ($a0)
/* FA9C 8003469C 3063FF0F */  andi      $v1, $v1, 0xff0f
/* FAA0 800346A0 34630010 */  ori       $v1, $v1, 0x10
/* FAA4 800346A4 0800D218 */  j         .L80034860
/* FAA8 800346A8 A4A30148 */   sh       $v1, 0x148($a1)
.L800346AC:
/* FAAC 800346AC 3C06800A */  lui       $a2, %hi(D_8009E730)
/* FAB0 800346B0 24C6E730 */  addiu     $a2, $a2, %lo(D_8009E730)
/* FAB4 800346B4 80C30000 */  lb        $v1, ($a2)
/* FAB8 800346B8 04600056 */  bltz      $v1, .L80034814
/* FABC 800346BC 90C20000 */   lbu      $v0, ($a2)
/* FAC0 800346C0 10600005 */  beqz      $v1, .L800346D8
/* FAC4 800346C4 2442FFFF */   addiu    $v0, $v0, -1
/* FAC8 800346C8 A0C20000 */  sb        $v0, ($a2)
/* FACC 800346CC 00021600 */  sll       $v0, $v0, 0x18
/* FAD0 800346D0 1440004C */  bnez      $v0, .L80034804
/* FAD4 800346D4 00000000 */   nop
.L800346D8:
/* FAD8 800346D8 3C048007 */  lui       $a0, %hi(D_80077920)
/* FADC 800346DC 24847920 */  addiu     $a0, $a0, %lo(D_80077920)
/* FAE0 800346E0 24050002 */  addiu     $a1, $zero, 2
/* FAE4 800346E4 2402FFFF */  addiu     $v0, $zero, -1
/* FAE8 800346E8 0C017BE8 */  jal       func_8005EFA0
/* FAEC 800346EC A0C20000 */   sb       $v0, ($a2)
/* FAF0 800346F0 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* FAF4 800346F4 2610417C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* FAF8 800346F8 8E030000 */  lw        $v1, ($s0)
/* FAFC 800346FC 9462015C */  lhu       $v0, 0x15c($v1)
/* FB00 80034700 0C053A3A */  jal       func_8014E8E8
/* FB04 80034704 A462015E */   sh       $v0, 0x15e($v1)
/* FB08 80034708 0C00EB9A */  jal       func_8003AE68
/* FB0C 8003470C 00000000 */   nop
/* FB10 80034710 8E020000 */  lw        $v0, ($s0)
/* FB14 80034714 0C016AD4 */  jal       func_8005AB50
/* FB18 80034718 A0510070 */   sb       $s1, 0x70($v0)
/* FB1C 8003471C 0C00AB18 */  jal       func_8002AC60
/* FB20 80034720 00000000 */   nop
/* FB24 80034724 0C017F54 */  jal       nuContRmbForceStop
/* FB28 80034728 00000000 */   nop
/* FB2C 8003472C 0C0539C8 */  jal       func_8014E720
/* FB30 80034730 0000202D */   daddu    $a0, $zero, $zero
/* FB34 80034734 0C044512 */  jal       func_80111448
/* FB38 80034738 0000202D */   daddu    $a0, $zero, $zero
/* FB3C 8003473C 0C046BD5 */  jal       func_8011AF54
/* FB40 80034740 00000000 */   nop
/* FB44 80034744 0C05343C */  jal       func_8014D0F0
/* FB48 80034748 00000000 */   nop
/* FB4C 8003474C 0C052BAA */  jal       func_8014AEA8
/* FB50 80034750 00000000 */   nop
/* FB54 80034754 0C049770 */  jal       func_80125DC0
/* FB58 80034758 00000000 */   nop
/* FB5C 8003475C 0C048D0D */  jal       func_80123434
/* FB60 80034760 00000000 */   nop
/* FB64 80034764 0C04A0B2 */  jal       func_801282C8
/* FB68 80034768 00000000 */   nop
/* FB6C 8003476C 3C048020 */  lui       $a0, %hi(D_80200000)
/* FB70 80034770 24840000 */  addiu     $a0, $a0, %lo(D_80200000)
/* FB74 80034774 3C050003 */  lui       $a1, 3
/* FB78 80034778 0C0528E6 */  jal       func_8014A398
/* FB7C 8003477C 34A58000 */   ori      $a1, $a1, 0x8000
/* FB80 80034780 0C05186C */  jal       func_801461B0
/* FB84 80034784 00000000 */   nop
/* FB88 80034788 0C03A6D4 */  jal       func_800E9B50
/* FB8C 8003478C 00000000 */   nop
/* FB90 80034790 0C04D85C */  jal       func_80136170
/* FB94 80034794 00000000 */   nop
/* FB98 80034798 0C0B0C77 */  jal       func_802C31DC
/* FB9C 8003479C 00000000 */   nop
/* FBA0 800347A0 0C00E05F */  jal       func_8003817C
/* FBA4 800347A4 00000000 */   nop
/* FBA8 800347A8 0C0457B2 */  jal       func_80115EC8
/* FBAC 800347AC 0000202D */   daddu    $a0, $zero, $zero
/* FBB0 800347B0 0C0529CC */  jal       func_8014A730
/* FBB4 800347B4 00000000 */   nop
/* FBB8 800347B8 0C053A36 */  jal       func_8014E8D8
/* FBBC 800347BC 00000000 */   nop
/* FBC0 800347C0 3C01800A */  lui       $at, %hi(D_8009E734)
/* FBC4 800347C4 AC22E734 */  sw        $v0, %lo(D_8009E734)($at)
/* FBC8 800347C8 0C053A2B */  jal       func_8014E8AC
/* FBCC 800347CC 0000202D */   daddu    $a0, $zero, $zero
/* FBD0 800347D0 0C053F43 */  jal       func_8014FD0C
/* FBD4 800347D4 00000000 */   nop
/* FBD8 800347D8 3C048007 */  lui       $a0, %hi(D_8007792C)
/* FBDC 800347DC 0C017F64 */  jal       func_8005FD90
/* FBE0 800347E0 2484792C */   addiu    $a0, $a0, %lo(D_8007792C)
/* FBE4 800347E4 0C090E0C */  jal       func_80243830
/* FBE8 800347E8 00000000 */   nop
/* FBEC 800347EC 3C04800A */  lui       $a0, %hi(D_8009A630)
/* FBF0 800347F0 2484A630 */  addiu     $a0, $a0, %lo(D_8009A630)
/* FBF4 800347F4 8C820000 */  lw        $v0, ($a0)
/* FBF8 800347F8 2403FFF7 */  addiu     $v1, $zero, -9
/* FBFC 800347FC 00431024 */  and       $v0, $v0, $v1
/* FC00 80034800 AC820000 */  sw        $v0, ($a0)
.L80034804:
/* FC04 80034804 3C02800A */  lui       $v0, %hi(D_8009E730)
/* FC08 80034808 8042E730 */  lb        $v0, %lo(D_8009E730)($v0)
/* FC0C 8003480C 04410014 */  bgez      $v0, .L80034860
/* FC10 80034810 00000000 */   nop
.L80034814:
/* FC14 80034814 3C10800A */  lui       $s0, %hi(D_8009E730)
/* FC18 80034818 2610E730 */  addiu     $s0, $s0, %lo(D_8009E730)
/* FC1C 8003481C 82020000 */  lb        $v0, ($s0)
/* FC20 80034820 2842FFF6 */  slti      $v0, $v0, -0xa
/* FC24 80034824 14400007 */  bnez      $v0, .L80034844
/* FC28 80034828 0000202D */   daddu    $a0, $zero, $zero
/* FC2C 8003482C 0C090EFD */  jal       func_80243BF4
/* FC30 80034830 0080282D */   daddu    $a1, $a0, $zero
/* FC34 80034834 92020000 */  lbu       $v0, ($s0)
/* FC38 80034838 2442FFFF */  addiu     $v0, $v0, -1
/* FC3C 8003483C 0800D216 */  j         .L80034858
/* FC40 80034840 A2020000 */   sb       $v0, ($s0)
.L80034844:
/* FC44 80034844 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* FC48 80034848 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* FC4C 8003484C 8C440010 */  lw        $a0, 0x10($v0)
/* FC50 80034850 0C090EFD */  jal       func_80243BF4
/* FC54 80034854 8C450020 */   lw       $a1, 0x20($v0)
.L80034858:
/* FC58 80034858 3C01800A */  lui       $at, %hi(D_8009E732)
/* FC5C 8003485C A420E732 */  sh        $zero, %lo(D_8009E732)($at)
.L80034860:
/* FC60 80034860 8FBF0018 */  lw        $ra, 0x18($sp)
/* FC64 80034864 8FB10014 */  lw        $s1, 0x14($sp)
/* FC68 80034868 8FB00010 */  lw        $s0, 0x10($sp)
/* FC6C 8003486C 03E00008 */  jr        $ra
/* FC70 80034870 27BD0020 */   addiu    $sp, $sp, 0x20

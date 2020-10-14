.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel start_script_in_group
/* E7F80 802C35D0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E7F84 802C35D4 AFB10014 */  sw        $s1, 0x14($sp)
/* E7F88 802C35D8 0080882D */  daddu     $s1, $a0, $zero
/* E7F8C 802C35DC AFB40020 */  sw        $s4, 0x20($sp)
/* E7F90 802C35E0 00A0A02D */  daddu     $s4, $a1, $zero
/* E7F94 802C35E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* E7F98 802C35E8 00C0982D */  daddu     $s3, $a2, $zero
/* E7F9C 802C35EC AFB50024 */  sw        $s5, 0x24($sp)
/* E7FA0 802C35F0 00E0A82D */  daddu     $s5, $a3, $zero
/* E7FA4 802C35F4 3C03802E */  lui       $v1, %hi(gCurrentScriptListPtr)
/* E7FA8 802C35F8 8C63A890 */  lw        $v1, %lo(gCurrentScriptListPtr)($v1)
/* E7FAC 802C35FC 0000282D */  daddu     $a1, $zero, $zero
/* E7FB0 802C3600 AFBF0028 */  sw        $ra, 0x28($sp)
/* E7FB4 802C3604 AFB20018 */  sw        $s2, 0x18($sp)
/* E7FB8 802C3608 AFB00010 */  sw        $s0, 0x10($sp)
.L802C360C:
/* E7FBC 802C360C 8C620000 */  lw        $v0, ($v1)
/* E7FC0 802C3610 10400006 */  beqz      $v0, .L802C362C
/* E7FC4 802C3614 28A20080 */   slti     $v0, $a1, 0x80
/* E7FC8 802C3618 24A50001 */  addiu     $a1, $a1, 1
/* E7FCC 802C361C 28A20080 */  slti      $v0, $a1, 0x80
/* E7FD0 802C3620 1440FFFA */  bnez      $v0, .L802C360C
/* E7FD4 802C3624 24630004 */   addiu    $v1, $v1, 4
/* E7FD8 802C3628 28A20080 */  slti      $v0, $a1, 0x80
.L802C362C:
/* E7FDC 802C362C 14400003 */  bnez      $v0, .L802C363C
/* E7FE0 802C3630 24040168 */   addiu    $a0, $zero, 0x168
.L802C3634:
/* E7FE4 802C3634 080B0D8D */  j         .L802C3634
/* E7FE8 802C3638 00000000 */   nop      
.L802C363C:
/* E7FEC 802C363C 0C00AB39 */  jal       heap_malloc
/* E7FF0 802C3640 00A0902D */   daddu    $s2, $a1, $zero
/* E7FF4 802C3644 00122080 */  sll       $a0, $s2, 2
/* E7FF8 802C3648 3C03802E */  lui       $v1, %hi(gCurrentScriptListPtr)
/* E7FFC 802C364C 8C63A890 */  lw        $v1, %lo(gCurrentScriptListPtr)($v1)
/* E8000 802C3650 3C05802E */  lui       $a1, %hi(gNumScripts)
/* E8004 802C3654 24A5A488 */  addiu     $a1, $a1, %lo(gNumScripts)
/* E8008 802C3658 00832021 */  addu      $a0, $a0, $v1
/* E800C 802C365C 8CA30000 */  lw        $v1, ($a1)
/* E8010 802C3660 0040802D */  daddu     $s0, $v0, $zero
/* E8014 802C3664 AC900000 */  sw        $s0, ($a0)
/* E8018 802C3668 24630001 */  addiu     $v1, $v1, 1
/* E801C 802C366C 16000003 */  bnez      $s0, .L802C367C
/* E8020 802C3670 ACA30000 */   sw       $v1, ($a1)
.L802C3674:
/* E8024 802C3674 080B0D9D */  j         .L802C3674
/* E8028 802C3678 00000000 */   nop      
.L802C367C:
/* E802C 802C367C 36620001 */  ori       $v0, $s3, 1
/* E8030 802C3680 3C03802E */  lui       $v1, 0x802e
/* E8034 802C3684 24639CA0 */  addiu     $v1, $v1, -0x6360
/* E8038 802C3688 A2020000 */  sb        $v0, ($s0)
/* E803C 802C368C A2000002 */  sb        $zero, 2($s0)
/* E8040 802C3690 A2140003 */  sb        $s4, 3($s0)
/* E8044 802C3694 8C620000 */  lw        $v0, ($v1)
/* E8048 802C3698 2405000F */  addiu     $a1, $zero, 0xf
/* E804C 802C369C AE020144 */  sw        $v0, 0x144($s0)
/* E8050 802C36A0 24420001 */  addiu     $v0, $v0, 1
/* E8054 802C36A4 AC620000 */  sw        $v0, ($v1)
/* E8058 802C36A8 2402FFFF */  addiu     $v0, $zero, -1
/* E805C 802C36AC A2020006 */  sb        $v0, 6($s0)
/* E8060 802C36B0 A2020007 */  sb        $v0, 7($s0)
/* E8064 802C36B4 A2150004 */  sb        $s5, 4($s0)
/* E8068 802C36B8 3C01802E */  lui       $at, 0x802e
/* E806C 802C36BC C4209CA8 */  lwc1      $f0, -0x6358($at)
/* E8070 802C36C0 2603003C */  addiu     $v1, $s0, 0x3c
/* E8074 802C36C4 AE110008 */  sw        $s1, 8($s0)
/* E8078 802C36C8 AE11015C */  sw        $s1, 0x15c($s0)
/* E807C 802C36CC AE110164 */  sw        $s1, 0x164($s0)
/* E8080 802C36D0 AE000060 */  sw        $zero, 0x60($s0)
/* E8084 802C36D4 AE000064 */  sw        $zero, 0x64($s0)
/* E8088 802C36D8 AE000068 */  sw        $zero, 0x68($s0)
/* E808C 802C36DC AE00006C */  sw        $zero, 0x6c($s0)
/* E8090 802C36E0 AE020148 */  sw        $v0, 0x148($s0)
/* E8094 802C36E4 AE02014C */  sw        $v0, 0x14c($s0)
/* E8098 802C36E8 AE000160 */  sw        $zero, 0x160($s0)
/* E809C 802C36EC AE000154 */  sw        $zero, 0x154($s0)
/* E80A0 802C36F0 AE000158 */  sw        $zero, 0x158($s0)
/* E80A4 802C36F4 E6000150 */  swc1      $f0, 0x150($s0)
.L802C36F8:
/* E80A8 802C36F8 AC600084 */  sw        $zero, 0x84($v1)
/* E80AC 802C36FC 24A5FFFF */  addiu     $a1, $a1, -1
/* E80B0 802C3700 04A1FFFD */  bgez      $a1, .L802C36F8
/* E80B4 802C3704 2463FFFC */   addiu    $v1, $v1, -4
/* E80B8 802C3708 24050002 */  addiu     $a1, $zero, 2
/* E80BC 802C370C 26020008 */  addiu     $v0, $s0, 8
.L802C3710:
/* E80C0 802C3710 AC4000C4 */  sw        $zero, 0xc4($v0)
/* E80C4 802C3714 24A5FFFF */  addiu     $a1, $a1, -1
/* E80C8 802C3718 04A1FFFD */  bgez      $a1, .L802C3710
/* E80CC 802C371C 2442FFFC */   addiu    $v0, $v0, -4
/* E80D0 802C3720 0C0B0C52 */  jal       find_script_labels
/* E80D4 802C3724 0200202D */   daddu    $a0, $s0, $zero
/* E80D8 802C3728 3C02802E */  lui       $v0, %hi(D_802D9CA4)
/* E80DC 802C372C 8C429CA4 */  lw        $v0, %lo(D_802D9CA4)($v0)
/* E80E0 802C3730 10400012 */  beqz      $v0, .L802C377C
/* E80E4 802C3734 00000000 */   nop      
/* E80E8 802C3738 92020000 */  lbu       $v0, ($s0)
/* E80EC 802C373C 30420020 */  andi      $v0, $v0, 0x20
/* E80F0 802C3740 1040000E */  beqz      $v0, .L802C377C
/* E80F4 802C3744 00000000 */   nop      
/* E80F8 802C3748 3C05802E */  lui       $a1, %hi(gScriptListCount)
/* E80FC 802C374C 24A5AC98 */  addiu     $a1, $a1, %lo(gScriptListCount)
/* E8100 802C3750 8CA20000 */  lw        $v0, ($a1)
/* E8104 802C3754 00022080 */  sll       $a0, $v0, 2
/* E8108 802C3758 3C01802E */  lui       $at, 0x802e
/* E810C 802C375C 00240821 */  addu      $at, $at, $a0
/* E8110 802C3760 AC32A898 */  sw        $s2, -0x5768($at)
/* E8114 802C3764 8E030144 */  lw        $v1, 0x144($s0)
/* E8118 802C3768 24420001 */  addiu     $v0, $v0, 1
/* E811C 802C376C ACA20000 */  sw        $v0, ($a1)
/* E8120 802C3770 3C01802E */  lui       $at, %hi(gScriptIdList)
/* E8124 802C3774 00240821 */  addu      $at, $at, $a0
/* E8128 802C3778 AC23AA98 */  sw        $v1, %lo(gScriptIdList)($at)
.L802C377C:
/* E812C 802C377C 0C0B0CE4 */  jal       func_802C3390
/* E8130 802C3780 0200202D */   daddu    $a0, $s0, $zero
/* E8134 802C3784 3C03802E */  lui       $v1, 0x802e
/* E8138 802C3788 24639CA0 */  addiu     $v1, $v1, -0x6360
/* E813C 802C378C 8C620000 */  lw        $v0, ($v1)
/* E8140 802C3790 14400004 */  bnez      $v0, .L802C37A4
/* E8144 802C3794 0200102D */   daddu    $v0, $s0, $zero
/* E8148 802C3798 24020001 */  addiu     $v0, $zero, 1
/* E814C 802C379C AC620000 */  sw        $v0, ($v1)
/* E8150 802C37A0 0200102D */  daddu     $v0, $s0, $zero
.L802C37A4:
/* E8154 802C37A4 8FBF0028 */  lw        $ra, 0x28($sp)
/* E8158 802C37A8 8FB50024 */  lw        $s5, 0x24($sp)
/* E815C 802C37AC 8FB40020 */  lw        $s4, 0x20($sp)
/* E8160 802C37B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* E8164 802C37B4 8FB20018 */  lw        $s2, 0x18($sp)
/* E8168 802C37B8 8FB10014 */  lw        $s1, 0x14($sp)
/* E816C 802C37BC 8FB00010 */  lw        $s0, 0x10($sp)
/* E8170 802C37C0 03E00008 */  jr        $ra
/* E8174 802C37C4 27BD0030 */   addiu    $sp, $sp, 0x30

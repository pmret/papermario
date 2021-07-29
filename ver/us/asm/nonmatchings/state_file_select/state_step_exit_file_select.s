.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80098300
.word L80035B7C_10F7C, L80035BDC_10FDC, L80035C10_11010, L80035C2C_1102C, L80035C80_11080, L80035CCC_110CC, L80035D00_11100, 0

.section .text

glabel state_step_exit_file_select
/* 10F40 80035B40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 10F44 80035B44 AFBF0014 */  sw        $ra, 0x14($sp)
/* 10F48 80035B48 0C0912F1 */  jal       func_80244BC4
/* 10F4C 80035B4C AFB00010 */   sw       $s0, 0x10($sp)
/* 10F50 80035B50 3C03800A */  lui       $v1, %hi(D_800A0931)
/* 10F54 80035B54 80630931 */  lb        $v1, %lo(D_800A0931)($v1)
/* 10F58 80035B58 0040802D */  daddu     $s0, $v0, $zero
/* 10F5C 80035B5C 2C620007 */  sltiu     $v0, $v1, 7
/* 10F60 80035B60 10400069 */  beqz      $v0, .L80035D08
/* 10F64 80035B64 00031080 */   sll      $v0, $v1, 2
/* 10F68 80035B68 3C01800A */  lui       $at, %hi(jtbl_80098300)
/* 10F6C 80035B6C 00220821 */  addu      $at, $at, $v0
/* 10F70 80035B70 8C228300 */  lw        $v0, %lo(jtbl_80098300)($at)
/* 10F74 80035B74 00400008 */  jr        $v0
/* 10F78 80035B78 00000000 */   nop
glabel L80035B7C_10F7C
/* 10F7C 80035B7C 0000282D */  daddu     $a1, $zero, $zero
/* 10F80 80035B80 2404002C */  addiu     $a0, $zero, 0x2c
/* 10F84 80035B84 0080382D */  daddu     $a3, $a0, $zero
/* 10F88 80035B88 2406FFFF */  addiu     $a2, $zero, -1
/* 10F8C 80035B8C 3C038016 */  lui       $v1, %hi(D_8015A2D0)
/* 10F90 80035B90 2463A2D0 */  addiu     $v1, $v1, %lo(D_8015A2D0)
.L80035B94:
/* 10F94 80035B94 80620003 */  lb        $v0, 3($v1)
/* 10F98 80035B98 10470003 */  beq       $v0, $a3, .L80035BA8
/* 10F9C 80035B9C 00000000 */   nop
/* 10FA0 80035BA0 54460005 */  bnel      $v0, $a2, .L80035BB8
/* 10FA4 80035BA4 24840001 */   addiu    $a0, $a0, 1
.L80035BA8:
/* 10FA8 80035BA8 90620000 */  lbu       $v0, ($v1)
/* 10FAC 80035BAC 30420008 */  andi      $v0, $v0, 8
/* 10FB0 80035BB0 00A22821 */  addu      $a1, $a1, $v0
/* 10FB4 80035BB4 24840001 */  addiu     $a0, $a0, 1
.L80035BB8:
/* 10FB8 80035BB8 28820040 */  slti      $v0, $a0, 0x40
/* 10FBC 80035BBC 1440FFF5 */  bnez      $v0, .L80035B94
/* 10FC0 80035BC0 24630020 */   addiu    $v1, $v1, 0x20
/* 10FC4 80035BC4 14A00050 */  bnez      $a1, .L80035D08
/* 10FC8 80035BC8 24020001 */   addiu    $v0, $zero, 1
/* 10FCC 80035BCC 3C01800A */  lui       $at, %hi(D_800A0931)
/* 10FD0 80035BD0 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
/* 10FD4 80035BD4 0800D742 */  j         .L80035D08
/* 10FD8 80035BD8 00000000 */   nop
glabel L80035BDC_10FDC
/* 10FDC 80035BDC 12000008 */  beqz      $s0, .L80035C00
/* 10FE0 80035BE0 24020002 */   addiu    $v0, $zero, 2
/* 10FE4 80035BE4 3C04800A */  lui       $a0, %hi(D_800A0932)
/* 10FE8 80035BE8 24840932 */  addiu     $a0, $a0, %lo(D_800A0932)
/* 10FEC 80035BEC 0C04E0AB */  jal       update_exit_map_screen_overlay
/* 10FF0 80035BF0 00000000 */   nop
/* 10FF4 80035BF4 00021400 */  sll       $v0, $v0, 0x10
/* 10FF8 80035BF8 10400043 */  beqz      $v0, .L80035D08
/* 10FFC 80035BFC 24020002 */   addiu    $v0, $zero, 2
.L80035C00:
/* 11000 80035C00 3C01800A */  lui       $at, %hi(D_800A0931)
/* 11004 80035C04 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
/* 11008 80035C08 0800D742 */  j         .L80035D08
/* 1100C 80035C0C 00000000 */   nop
glabel L80035C10_11010
/* 11010 80035C10 0C0912C0 */  jal       filemenu_cleanup
/* 11014 80035C14 00000000 */   nop
/* 11018 80035C18 0C051FB1 */  jal       set_windows_visible
/* 1101C 80035C1C 0000202D */   daddu    $a0, $zero, $zero
/* 11020 80035C20 24020003 */  addiu     $v0, $zero, 3
/* 11024 80035C24 3C01800A */  lui       $at, %hi(D_800A0931)
/* 11028 80035C28 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
glabel L80035C2C_1102C
/* 1102C 80035C2C 0C009C22 */  jal       set_time_freeze_mode
/* 11030 80035C30 0000202D */   daddu    $a0, $zero, $zero
/* 11034 80035C34 1600000B */  bnez      $s0, .L80035C64
/* 11038 80035C38 2402000A */   addiu    $v0, $zero, 0xa
/* 1103C 80035C3C 0C00CD3C */  jal       set_game_mode
/* 11040 80035C40 24040002 */   addiu    $a0, $zero, 2
/* 11044 80035C44 3C04FFFE */  lui       $a0, 0xfffe
/* 11048 80035C48 3C03800A */  lui       $v1, %hi(gOverrideFlags)
/* 1104C 80035C4C 2463A650 */  addiu     $v1, $v1, %lo(gOverrideFlags)
/* 11050 80035C50 8C620000 */  lw        $v0, ($v1)
/* 11054 80035C54 3484FFFF */  ori       $a0, $a0, 0xffff
/* 11058 80035C58 00441024 */  and       $v0, $v0, $a0
/* 1105C 80035C5C 0800D742 */  j         .L80035D08
/* 11060 80035C60 AC620000 */   sw       $v0, ($v1)
.L80035C64:
/* 11064 80035C64 3C01800A */  lui       $at, %hi(D_800A0930)
/* 11068 80035C68 A0220930 */  sb        $v0, %lo(D_800A0930)($at)
/* 1106C 80035C6C 24020004 */  addiu     $v0, $zero, 4
/* 11070 80035C70 3C01800A */  lui       $at, %hi(D_800A0931)
/* 11074 80035C74 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
/* 11078 80035C78 0800D742 */  j         .L80035D08
/* 1107C 80035C7C 00000000 */   nop
glabel L80035C80_11080
/* 11080 80035C80 3C10800A */  lui       $s0, %hi(D_800A0930)
/* 11084 80035C84 26100930 */  addiu     $s0, $s0, %lo(D_800A0930)
/* 11088 80035C88 82020000 */  lb        $v0, ($s0)
/* 1108C 80035C8C 92030000 */  lbu       $v1, ($s0)
/* 11090 80035C90 18400003 */  blez      $v0, .L80035CA0
/* 11094 80035C94 2462FFFF */   addiu    $v0, $v1, -1
/* 11098 80035C98 0800D742 */  j         .L80035D08
/* 1109C 80035C9C A2020000 */   sb       $v0, ($s0)
.L80035CA0:
/* 110A0 80035CA0 3C014000 */  lui       $at, 0x4000
/* 110A4 80035CA4 44816000 */  mtc1      $at, $f12
/* 110A8 80035CA8 0C00AFB7 */  jal       set_curtain_scale_goal
/* 110AC 80035CAC 00000000 */   nop
/* 110B0 80035CB0 2402000A */  addiu     $v0, $zero, 0xa
/* 110B4 80035CB4 A2020000 */  sb        $v0, ($s0)
/* 110B8 80035CB8 24020005 */  addiu     $v0, $zero, 5
/* 110BC 80035CBC 3C01800A */  lui       $at, %hi(D_800A0931)
/* 110C0 80035CC0 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
/* 110C4 80035CC4 0800D742 */  j         .L80035D08
/* 110C8 80035CC8 00000000 */   nop
glabel L80035CCC_110CC
/* 110CC 80035CCC 3C04800A */  lui       $a0, %hi(D_800A0930)
/* 110D0 80035CD0 24840930 */  addiu     $a0, $a0, %lo(D_800A0930)
/* 110D4 80035CD4 80820000 */  lb        $v0, ($a0)
/* 110D8 80035CD8 90830000 */  lbu       $v1, ($a0)
/* 110DC 80035CDC 18400003 */  blez      $v0, .L80035CEC
/* 110E0 80035CE0 2462FFFF */   addiu    $v0, $v1, -1
/* 110E4 80035CE4 0800D742 */  j         .L80035D08
/* 110E8 80035CE8 A0820000 */   sb       $v0, ($a0)
.L80035CEC:
/* 110EC 80035CEC 24020006 */  addiu     $v0, $zero, 6
/* 110F0 80035CF0 3C01800A */  lui       $at, %hi(D_800A0931)
/* 110F4 80035CF4 A0220931 */  sb        $v0, %lo(D_800A0931)($at)
/* 110F8 80035CF8 0800D742 */  j         .L80035D08
/* 110FC 80035CFC 00000000 */   nop
glabel L80035D00_11100
/* 11100 80035D00 0C00CD3C */  jal       set_game_mode
/* 11104 80035D04 24040007 */   addiu    $a0, $zero, 7
.L80035D08:
/* 11108 80035D08 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1110C 80035D0C 8FB00010 */  lw        $s0, 0x10($sp)
/* 11110 80035D10 03E00008 */  jr        $ra
/* 11114 80035D14 27BD0018 */   addiu    $sp, $sp, 0x18

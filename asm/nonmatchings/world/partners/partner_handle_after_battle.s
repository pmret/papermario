.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_handle_after_battle
/* 84B74 800EB6C4 3C028011 */  lui       $v0, %hi(D_8010CFD8)
/* 84B78 800EB6C8 8C42CFD8 */  lw        $v0, %lo(D_8010CFD8)($v0)
/* 84B7C 800EB6CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 84B80 800EB6D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 84B84 800EB6D4 3C118011 */  lui       $s1, %hi(D_8010EBB0)
/* 84B88 800EB6D8 2631EBB0 */  addiu     $s1, $s1, %lo(D_8010EBB0)
/* 84B8C 800EB6DC AFBF0018 */  sw        $ra, 0x18($sp)
/* 84B90 800EB6E0 10400035 */  beqz      $v0, .L800EB7B8
/* 84B94 800EB6E4 AFB00010 */   sw       $s0, 0x10($sp)
/* 84B98 800EB6E8 3C108011 */  lui       $s0, %hi(D_8010CFDC)
/* 84B9C 800EB6EC 2610CFDC */  addiu     $s0, $s0, %lo(D_8010CFDC)
/* 84BA0 800EB6F0 0C0B1059 */  jal       does_script_exist
/* 84BA4 800EB6F4 8E040000 */   lw       $a0, ($s0)
/* 84BA8 800EB6F8 10400003 */  beqz      $v0, .L800EB708
/* 84BAC 800EB6FC 00000000 */   nop
/* 84BB0 800EB700 0C0B102B */  jal       kill_script_by_ID
/* 84BB4 800EB704 8E040000 */   lw       $a0, ($s0)
.L800EB708:
/* 84BB8 800EB708 3C028011 */  lui       $v0, %hi(D_8010CFEC)
/* 84BBC 800EB70C 8C42CFEC */  lw        $v0, %lo(D_8010CFEC)($v0)
/* 84BC0 800EB710 24050014 */  addiu     $a1, $zero, 0x14
/* 84BC4 800EB714 8C440018 */  lw        $a0, 0x18($v0)
/* 84BC8 800EB718 0C0B0CF8 */  jal       start_script
/* 84BCC 800EB71C 24060020 */   addiu    $a2, $zero, 0x20
/* 84BD0 800EB720 3C038011 */  lui       $v1, %hi(D_8010C930)
/* 84BD4 800EB724 8C63C930 */  lw        $v1, %lo(D_8010C930)($v1)
/* 84BD8 800EB728 8C440144 */  lw        $a0, 0x144($v0)
/* 84BDC 800EB72C 3C018011 */  lui       $at, %hi(D_8010CFD4)
/* 84BE0 800EB730 AC22CFD4 */  sw        $v0, %lo(D_8010CFD4)($at)
/* 84BE4 800EB734 AC43014C */  sw        $v1, 0x14c($v0)
/* 84BE8 800EB738 2403000A */  addiu     $v1, $zero, 0xa
/* 84BEC 800EB73C AE040000 */  sw        $a0, ($s0)
/* 84BF0 800EB740 A0430004 */  sb        $v1, 4($v0)
/* 84BF4 800EB744 24020001 */  addiu     $v0, $zero, 1
/* 84BF8 800EB748 3C018011 */  lui       $at, %hi(D_8010CFE8)
/* 84BFC 800EB74C AC22CFE8 */  sw        $v0, %lo(D_8010CFE8)($at)
/* 84C00 800EB750 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 84C04 800EB754 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 84C08 800EB758 80420012 */  lb        $v0, 0x12($v0)
/* 84C0C 800EB75C 24030006 */  addiu     $v1, $zero, 6
/* 84C10 800EB760 1043000C */  beq       $v0, $v1, .L800EB794
/* 84C14 800EB764 00000000 */   nop
/* 84C18 800EB768 82220003 */  lb        $v0, 3($s1)
/* 84C1C 800EB76C 14430009 */  bne       $v0, $v1, .L800EB794
/* 84C20 800EB770 2403FFFE */   addiu    $v1, $zero, -2
/* 84C24 800EB774 3C04800F */  lui       $a0, %hi(gPlayerStatusPtr)
/* 84C28 800EB778 8C847B30 */  lw        $a0, %lo(gPlayerStatusPtr)($a0)
/* 84C2C 800EB77C 8C820004 */  lw        $v0, 4($a0)
/* 84C30 800EB780 00431024 */  and       $v0, $v0, $v1
/* 84C34 800EB784 2403FFFD */  addiu     $v1, $zero, -3
/* 84C38 800EB788 00431024 */  and       $v0, $v0, $v1
/* 84C3C 800EB78C AC820004 */  sw        $v0, 4($a0)
/* 84C40 800EB790 A2200003 */  sb        $zero, 3($s1)
.L800EB794:
/* 84C44 800EB794 3C028011 */  lui       $v0, %hi(D_8010CFEC)
/* 84C48 800EB798 8C42CFEC */  lw        $v0, %lo(D_8010CFEC)($v0)
/* 84C4C 800EB79C 8C420038 */  lw        $v0, 0x38($v0)
/* 84C50 800EB7A0 10400005 */  beqz      $v0, .L800EB7B8
/* 84C54 800EB7A4 00000000 */   nop
/* 84C58 800EB7A8 3C048011 */  lui       $a0, %hi(D_8010C930)
/* 84C5C 800EB7AC 8C84C930 */  lw        $a0, %lo(D_8010C930)($a0)
/* 84C60 800EB7B0 0040F809 */  jalr      $v0
/* 84C64 800EB7B4 00000000 */   nop
.L800EB7B8:
/* 84C68 800EB7B8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 84C6C 800EB7BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 84C70 800EB7C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 84C74 800EB7C4 03E00008 */  jr        $ra
/* 84C78 800EB7C8 27BD0020 */   addiu    $sp, $sp, 0x20

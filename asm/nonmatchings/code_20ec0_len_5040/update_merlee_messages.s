.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_merlee_messages
/* 20F68 80045B68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20F6C 80045B6C AFB10014 */  sw        $s1, 0x14($sp)
/* 20F70 80045B70 0000882D */  daddu     $s1, $zero, $zero
/* 20F74 80045B74 AFB00010 */  sw        $s0, 0x10($sp)
/* 20F78 80045B78 3C10800A */  lui       $s0, %hi(D_800A0BC0)
/* 20F7C 80045B7C 26100BC0 */  addiu     $s0, $s0, %lo(D_800A0BC0)
/* 20F80 80045B80 AFBF0018 */  sw        $ra, 0x18($sp)
.L80045B84:
/* 20F84 80045B84 86020010 */  lh        $v0, 0x10($s0)
/* 20F88 80045B88 50400007 */  beql      $v0, $zero, .L80045BA8
/* 20F8C 80045B8C 26310001 */   addiu    $s1, $s1, 1
/* 20F90 80045B90 8E020004 */  lw        $v0, 4($s0)
/* 20F94 80045B94 50400004 */  beql      $v0, $zero, .L80045BA8
/* 20F98 80045B98 26310001 */   addiu    $s1, $s1, 1
/* 20F9C 80045B9C 0040F809 */  jalr      $v0
/* 20FA0 80045BA0 0200202D */   daddu    $a0, $s0, $zero
/* 20FA4 80045BA4 26310001 */  addiu     $s1, $s1, 1
.L80045BA8:
/* 20FA8 80045BA8 2A220020 */  slti      $v0, $s1, 0x20
/* 20FAC 80045BAC 1440FFF5 */  bnez      $v0, .L80045B84
/* 20FB0 80045BB0 2610001C */   addiu    $s0, $s0, 0x1c
/* 20FB4 80045BB4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 20FB8 80045BB8 8FB10014 */  lw        $s1, 0x14($sp)
/* 20FBC 80045BBC 8FB00010 */  lw        $s0, 0x10($sp)
/* 20FC0 80045BC0 03E00008 */  jr        $ra
/* 20FC4 80045BC4 27BD0020 */   addiu    $sp, $sp, 0x20

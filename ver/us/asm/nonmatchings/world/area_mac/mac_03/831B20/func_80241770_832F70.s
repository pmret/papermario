.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241770_832F70
/* 832F70 80241770 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 832F74 80241774 AFBF0010 */  sw        $ra, 0x10($sp)
/* 832F78 80241778 10A00003 */  beqz      $a1, .L80241788
/* 832F7C 8024177C 8C86000C */   lw       $a2, 0xc($a0)
/* 832F80 80241780 3C018025 */  lui       $at, %hi(D_80248C6C_83A46C)
/* 832F84 80241784 AC208C6C */  sw        $zero, %lo(D_80248C6C_83A46C)($at)
.L80241788:
/* 832F88 80241788 3C038025 */  lui       $v1, %hi(D_80248C6C_83A46C)
/* 832F8C 8024178C 24638C6C */  addiu     $v1, $v1, %lo(D_80248C6C_83A46C)
/* 832F90 80241790 8C620000 */  lw        $v0, ($v1)
/* 832F94 80241794 54400003 */  bnel      $v0, $zero, .L802417A4
/* 832F98 80241798 AC600000 */   sw       $zero, ($v1)
/* 832F9C 8024179C 080905EE */  j         .L802417B8
/* 832FA0 802417A0 0000102D */   daddu    $v0, $zero, $zero
.L802417A4:
/* 832FA4 802417A4 8CC50000 */  lw        $a1, ($a2)
/* 832FA8 802417A8 3C068025 */  lui       $a2, %hi(D_80248C70_83A470)
/* 832FAC 802417AC 0C0B2026 */  jal       evt_set_variable
/* 832FB0 802417B0 8CC68C70 */   lw       $a2, %lo(D_80248C70_83A470)($a2)
/* 832FB4 802417B4 24020002 */  addiu     $v0, $zero, 2
.L802417B8:
/* 832FB8 802417B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 832FBC 802417BC 03E00008 */  jr        $ra
/* 832FC0 802417C0 27BD0018 */   addiu    $sp, $sp, 0x18

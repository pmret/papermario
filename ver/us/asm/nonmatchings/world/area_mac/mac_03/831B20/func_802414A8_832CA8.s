.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414A8_832CA8
/* 832CA8 802414A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 832CAC 802414AC 3C058025 */  lui       $a1, %hi(D_802513E8)
/* 832CB0 802414B0 8CA513E8 */  lw        $a1, %lo(D_802513E8)($a1)
/* 832CB4 802414B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 832CB8 802414B8 0C0B1EAF */  jal       evt_get_variable
/* 832CBC 802414BC 0000202D */   daddu    $a0, $zero, $zero
/* 832CC0 802414C0 0040182D */  daddu     $v1, $v0, $zero
/* 832CC4 802414C4 24020001 */  addiu     $v0, $zero, 1
/* 832CC8 802414C8 14620006 */  bne       $v1, $v0, .L802414E4
/* 832CCC 802414CC 24020002 */   addiu    $v0, $zero, 2
/* 832CD0 802414D0 44800000 */  mtc1      $zero, $f0
/* 832CD4 802414D4 00000000 */  nop
/* 832CD8 802414D8 44050000 */  mfc1      $a1, $f0
/* 832CDC 802414DC 0809053F */  j         .L802414FC
/* 832CE0 802414E0 0000202D */   daddu    $a0, $zero, $zero
.L802414E4:
/* 832CE4 802414E4 14620008 */  bne       $v1, $v0, .L80241508
/* 832CE8 802414E8 24040001 */   addiu    $a0, $zero, 1
/* 832CEC 802414EC 44800000 */  mtc1      $zero, $f0
/* 832CF0 802414F0 00000000 */  nop
/* 832CF4 802414F4 44050000 */  mfc1      $a1, $f0
/* 832CF8 802414F8 00000000 */  nop
.L802414FC:
/* 832CFC 802414FC 00A0302D */  daddu     $a2, $a1, $zero
/* 832D00 80241500 0C01C5A4 */  jal       playFX_50
/* 832D04 80241504 00A0382D */   daddu    $a3, $a1, $zero
.L80241508:
/* 832D08 80241508 8FBF0010 */  lw        $ra, 0x10($sp)
/* 832D0C 8024150C 03E00008 */  jr        $ra
/* 832D10 80241510 27BD0018 */   addiu    $sp, $sp, 0x18

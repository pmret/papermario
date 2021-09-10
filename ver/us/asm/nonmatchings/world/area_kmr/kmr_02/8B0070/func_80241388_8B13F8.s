.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241388_8B13F8
/* 8B13F8 80241388 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B13FC 8024138C 3C058025 */  lui       $a1, %hi(D_80257F40)
/* 8B1400 80241390 8CA57F40 */  lw        $a1, %lo(D_80257F40)($a1)
/* 8B1404 80241394 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B1408 80241398 0C0B1EAF */  jal       evt_get_variable
/* 8B140C 8024139C 0000202D */   daddu    $a0, $zero, $zero
/* 8B1410 802413A0 0040182D */  daddu     $v1, $v0, $zero
/* 8B1414 802413A4 24020001 */  addiu     $v0, $zero, 1
/* 8B1418 802413A8 14620006 */  bne       $v1, $v0, .L802413C4
/* 8B141C 802413AC 24020002 */   addiu    $v0, $zero, 2
/* 8B1420 802413B0 44800000 */  mtc1      $zero, $f0
/* 8B1424 802413B4 00000000 */  nop
/* 8B1428 802413B8 44050000 */  mfc1      $a1, $f0
/* 8B142C 802413BC 080904F7 */  j         .L802413DC
/* 8B1430 802413C0 0000202D */   daddu    $a0, $zero, $zero
.L802413C4:
/* 8B1434 802413C4 14620008 */  bne       $v1, $v0, .L802413E8
/* 8B1438 802413C8 24040001 */   addiu    $a0, $zero, 1
/* 8B143C 802413CC 44800000 */  mtc1      $zero, $f0
/* 8B1440 802413D0 00000000 */  nop
/* 8B1444 802413D4 44050000 */  mfc1      $a1, $f0
/* 8B1448 802413D8 00000000 */  nop
.L802413DC:
/* 8B144C 802413DC 00A0302D */  daddu     $a2, $a1, $zero
/* 8B1450 802413E0 0C01C5A4 */  jal       playFX_50
/* 8B1454 802413E4 00A0382D */   daddu    $a3, $a1, $zero
.L802413E8:
/* 8B1458 802413E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B145C 802413EC 03E00008 */  jr        $ra
/* 8B1460 802413F0 27BD0018 */   addiu    $sp, $sp, 0x18

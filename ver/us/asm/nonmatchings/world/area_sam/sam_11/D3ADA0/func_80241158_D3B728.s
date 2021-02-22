.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241158_D3B728
/* D3B728 80241158 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3B72C 8024115C 10A0000B */  beqz      $a1, .L8024118C
/* D3B730 80241160 AFBF0010 */   sw       $ra, 0x10($sp)
/* D3B734 80241164 3C038025 */  lui       $v1, %hi(func_80251474)
/* D3B738 80241168 8C631474 */  lw        $v1, %lo(func_80251474)($v1)
/* D3B73C 8024116C 8C620000 */  lw        $v0, ($v1)
/* D3B740 80241170 3C048025 */  lui       $a0, %hi(D_80251478)
/* D3B744 80241174 8C841478 */  lw        $a0, %lo(D_80251478)($a0)
/* D3B748 80241178 34420010 */  ori       $v0, $v0, 0x10
/* D3B74C 8024117C AC620000 */  sw        $v0, ($v1)
/* D3B750 80241180 8C820000 */  lw        $v0, ($a0)
/* D3B754 80241184 34420010 */  ori       $v0, $v0, 0x10
/* D3B758 80241188 AC820000 */  sw        $v0, ($a0)
.L8024118C:
/* D3B75C 8024118C 3C048025 */  lui       $a0, %hi(D_80251470)
/* D3B760 80241190 8C841470 */  lw        $a0, %lo(D_80251470)($a0)
/* D3B764 80241194 8C85000C */  lw        $a1, 0xc($a0)
/* D3B768 80241198 8CA20018 */  lw        $v0, 0x18($a1)
/* D3B76C 8024119C 8CA30020 */  lw        $v1, 0x20($a1)
/* D3B770 802411A0 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D3B774 802411A4 ACA20018 */  sw        $v0, 0x18($a1)
/* D3B778 802411A8 8CA20024 */  lw        $v0, 0x24($a1)
/* D3B77C 802411AC 2463FFF6 */  addiu     $v1, $v1, -0xa
/* D3B780 802411B0 ACA30020 */  sw        $v1, 0x20($a1)
/* D3B784 802411B4 8CA30028 */  lw        $v1, 0x28($a1)
/* D3B788 802411B8 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D3B78C 802411BC ACA20024 */  sw        $v0, 0x24($a1)
/* D3B790 802411C0 8CA2001C */  lw        $v0, 0x1c($a1)
/* D3B794 802411C4 2463FFF6 */  addiu     $v1, $v1, -0xa
/* D3B798 802411C8 ACA30028 */  sw        $v1, 0x28($a1)
/* D3B79C 802411CC 8CA30018 */  lw        $v1, 0x18($a1)
/* D3B7A0 802411D0 2442FFF6 */  addiu     $v0, $v0, -0xa
/* D3B7A4 802411D4 18600003 */  blez      $v1, .L802411E4
/* D3B7A8 802411D8 ACA2001C */   sw       $v0, 0x1c($a1)
/* D3B7AC 802411DC 08090480 */  j         .L80241200
/* D3B7B0 802411E0 0000102D */   daddu    $v0, $zero, $zero
.L802411E4:
/* D3B7B4 802411E4 0C016914 */  jal       remove_effect
/* D3B7B8 802411E8 ACA00018 */   sw       $zero, 0x18($a1)
/* D3B7BC 802411EC 3C048025 */  lui       $a0, %hi(D_80251450)
/* D3B7C0 802411F0 8C841450 */  lw        $a0, %lo(D_80251450)($a0)
/* D3B7C4 802411F4 0C048D70 */  jal       func_801235C0
/* D3B7C8 802411F8 00000000 */   nop
/* D3B7CC 802411FC 24020002 */  addiu     $v0, $zero, 2
.L80241200:
/* D3B7D0 80241200 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3B7D4 80241204 03E00008 */  jr        $ra
/* D3B7D8 80241208 27BD0018 */   addiu    $sp, $sp, 0x18

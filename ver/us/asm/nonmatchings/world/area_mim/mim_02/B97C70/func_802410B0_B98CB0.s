.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410B0_B98CB0
/* B98CB0 802410B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B98CB4 802410B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B98CB8 802410B8 10A00003 */  beqz      $a1, .L802410C8
/* B98CBC 802410BC 8C86000C */   lw       $a2, 0xc($a0)
/* B98CC0 802410C0 3C018024 */  lui       $at, %hi(D_802416AC_B992AC)
/* B98CC4 802410C4 AC2016AC */  sw        $zero, %lo(D_802416AC_B992AC)($at)
.L802410C8:
/* B98CC8 802410C8 3C038024 */  lui       $v1, %hi(D_802416AC_B992AC)
/* B98CCC 802410CC 246316AC */  addiu     $v1, $v1, %lo(D_802416AC_B992AC)
/* B98CD0 802410D0 8C620000 */  lw        $v0, ($v1)
/* B98CD4 802410D4 54400003 */  bnel      $v0, $zero, .L802410E4
/* B98CD8 802410D8 AC600000 */   sw       $zero, ($v1)
/* B98CDC 802410DC 0809043E */  j         .L802410F8
/* B98CE0 802410E0 0000102D */   daddu    $v0, $zero, $zero
.L802410E4:
/* B98CE4 802410E4 8CC50000 */  lw        $a1, ($a2)
/* B98CE8 802410E8 3C068024 */  lui       $a2, %hi(D_802416B0_B992B0)
/* B98CEC 802410EC 0C0B2026 */  jal       evt_set_variable
/* B98CF0 802410F0 8CC616B0 */   lw       $a2, %lo(D_802416B0_B992B0)($a2)
/* B98CF4 802410F4 24020002 */  addiu     $v0, $zero, 2
.L802410F8:
/* B98CF8 802410F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* B98CFC 802410FC 03E00008 */  jr        $ra
/* B98D00 80241100 27BD0018 */   addiu    $sp, $sp, 0x18

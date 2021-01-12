.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802429A0_EEFAA0
/* EEFAA0 802429A0 AC800084 */  sw        $zero, 0x84($a0)
/* EEFAA4 802429A4 3C038011 */  lui       $v1, %hi(D_8011762C)
/* EEFAA8 802429A8 8063762C */  lb        $v1, %lo(D_8011762C)($v1)
/* EEFAAC 802429AC 2402000E */  addiu     $v0, $zero, 0xe
/* EEFAB0 802429B0 10620004 */  beq       $v1, $v0, .L802429C4
/* EEFAB4 802429B4 24020001 */   addiu    $v0, $zero, 1
/* EEFAB8 802429B8 24020010 */  addiu     $v0, $zero, 0x10
/* EEFABC 802429BC 14620002 */  bne       $v1, $v0, .L802429C8
/* EEFAC0 802429C0 24020001 */   addiu    $v0, $zero, 1
.L802429C4:
/* EEFAC4 802429C4 AC820084 */  sw        $v0, 0x84($a0)
.L802429C8:
/* EEFAC8 802429C8 03E00008 */  jr        $ra
/* EEFACC 802429CC 24020002 */   addiu    $v0, $zero, 2

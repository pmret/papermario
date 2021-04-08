.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E18_EEDF18
/* EEDF18 80240E18 AC800084 */  sw        $zero, 0x84($a0)
/* EEDF1C 80240E1C 3C038011 */  lui       $v1, %hi(D_8011762C)
/* EEDF20 80240E20 8063762C */  lb        $v1, %lo(D_8011762C)($v1)
/* EEDF24 80240E24 2402000E */  addiu     $v0, $zero, 0xe
/* EEDF28 80240E28 10620004 */  beq       $v1, $v0, .L80240E3C
/* EEDF2C 80240E2C 24020001 */   addiu    $v0, $zero, 1
/* EEDF30 80240E30 24020010 */  addiu     $v0, $zero, 0x10
/* EEDF34 80240E34 14620002 */  bne       $v1, $v0, .L80240E40
/* EEDF38 80240E38 24020001 */   addiu    $v0, $zero, 1
.L80240E3C:
/* EEDF3C 80240E3C AC820084 */  sw        $v0, 0x84($a0)
.L80240E40:
/* EEDF40 80240E40 03E00008 */  jr        $ra
/* EEDF44 80240E44 24020002 */   addiu    $v0, $zero, 2
/* EEDF48 80240E48 00000000 */  nop
/* EEDF4C 80240E4C 00000000 */  nop

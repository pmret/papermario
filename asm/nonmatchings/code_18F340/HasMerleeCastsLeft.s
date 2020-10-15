.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel HasMerleeCastsLeft
/* 1902A8 802619C8 AC800084 */  sw        $zero, 0x84($a0)
/* 1902AC 802619CC 3C028011 */  lui       $v0, 0x8011
/* 1902B0 802619D0 8042F51A */  lb        $v0, -0xae6($v0)
/* 1902B4 802619D4 18400002 */  blez      $v0, .L802619E0
/* 1902B8 802619D8 24020001 */   addiu    $v0, $zero, 1
/* 1902BC 802619DC AC820084 */  sw        $v0, 0x84($a0)
.L802619E0:
/* 1902C0 802619E0 03E00008 */  jr        $ra
/* 1902C4 802619E4 24020002 */   addiu    $v0, $zero, 2

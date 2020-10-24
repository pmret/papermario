.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419AC_84457C
/* 84457C 802419AC 3C038011 */  lui       $v1, 0x8011
/* 844580 802419B0 8063EBB3 */  lb        $v1, -0x144d($v1)
/* 844584 802419B4 24020009 */  addiu     $v0, $zero, 9
/* 844588 802419B8 54620003 */  bnel      $v1, $v0, .L802419C8
/* 84458C 802419BC AC800084 */   sw       $zero, 0x84($a0)
/* 844590 802419C0 24020001 */  addiu     $v0, $zero, 1
/* 844594 802419C4 AC820084 */  sw        $v0, 0x84($a0)
.L802419C8:
/* 844598 802419C8 03E00008 */  jr        $ra
/* 84459C 802419CC 24020002 */   addiu    $v0, $zero, 2

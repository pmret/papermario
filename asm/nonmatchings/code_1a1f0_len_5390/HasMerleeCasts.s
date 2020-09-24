.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel HasMerleeCasts
/* 1A7F4 8003F3F4 AC800084 */  sw        $zero, 0x84($a0)
/* 1A7F8 8003F3F8 3C028011 */  lui       $v0, 0x8011
/* 1A7FC 8003F3FC 8042F51A */  lb        $v0, -0xae6($v0)
/* 1A800 8003F400 18400002 */  blez      $v0, .L8003F40C
/* 1A804 8003F404 24020001 */   addiu    $v0, $zero, 1
/* 1A808 8003F408 AC820084 */  sw        $v0, 0x84($a0)
.L8003F40C:
/* 1A80C 8003F40C 03E00008 */  jr        $ra
/* 1A810 8003F410 24020002 */   addiu    $v0, $zero, 2

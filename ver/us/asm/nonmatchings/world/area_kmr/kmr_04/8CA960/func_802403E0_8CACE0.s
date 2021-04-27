.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403E0_8CACE0
/* 8CACE0 802403E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8CACE4 802403E4 3C048024 */  lui       $a0, %hi(dro_01_dup_GetCurrentCameraYawClamped180)
/* 8CACE8 802403E8 24843770 */  addiu     $a0, $a0, %lo(dro_01_dup_GetCurrentCameraYawClamped180)
/* 8CACEC 802403EC 3C028024 */  lui       $v0, %hi(D_80241BF0_8CC4F0)
/* 8CACF0 802403F0 24421BF0 */  addiu     $v0, $v0, %lo(D_80241BF0_8CC4F0)
/* 8CACF4 802403F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8CACF8 802403F8 AC820000 */  sw        $v0, ($a0)
/* 8CACFC 802403FC 3C028024 */  lui       $v0, %hi(D_80242070_8CC970)
/* 8CAD00 80240400 24422070 */  addiu     $v0, $v0, %lo(D_80242070_8CC970)
/* 8CAD04 80240404 AC820004 */  sw        $v0, 4($a0)
/* 8CAD08 80240408 24020030 */  addiu     $v0, $zero, 0x30
/* 8CAD0C 8024040C A4820008 */  sh        $v0, 8($a0)
/* 8CAD10 80240410 A482000A */  sh        $v0, 0xa($a0)
/* 8CAD14 80240414 24020002 */  addiu     $v0, $zero, 2
/* 8CAD18 80240418 AC82000C */  sw        $v0, 0xc($a0)
/* 8CAD1C 8024041C 0C0496CB */  jal       set_message_images
/* 8CAD20 80240420 AC800010 */   sw       $zero, 0x10($a0)
/* 8CAD24 80240424 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8CAD28 80240428 24020002 */  addiu     $v0, $zero, 2
/* 8CAD2C 8024042C 03E00008 */  jr        $ra
/* 8CAD30 80240430 27BD0018 */   addiu    $sp, $sp, 0x18

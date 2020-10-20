.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AED410
/* AED410 80240000 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* AED414 80240004 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* AED418 80240008 9043007E */  lbu       $v1, 0x7e($v0)
/* AED41C 8024000C 306300FE */  andi      $v1, $v1, 0xfe
/* AED420 80240010 A043007E */  sb        $v1, 0x7e($v0)
/* AED424 80240014 90820087 */  lbu       $v0, 0x87($a0)
/* AED428 80240018 3C018011 */  lui       $at, 0x8011
/* AED42C 8024001C A022F2A2 */  sb        $v0, -0xd5e($at)
/* AED430 80240020 03E00008 */  jr        $ra
/* AED434 80240024 24020002 */   addiu    $v0, $zero, 2

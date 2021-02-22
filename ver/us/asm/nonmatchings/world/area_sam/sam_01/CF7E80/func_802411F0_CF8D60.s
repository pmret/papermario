.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411F0_CF8D60
/* CF8D60 802411F0 3C028025 */  lui       $v0, %hi(D_8024DF20)
/* CF8D64 802411F4 8C42DF20 */  lw        $v0, %lo(D_8024DF20)($v0)
/* CF8D68 802411F8 8C42000C */  lw        $v0, 0xc($v0)
/* CF8D6C 802411FC AC40001C */  sw        $zero, 0x1c($v0)
/* CF8D70 80241200 03E00008 */  jr        $ra
/* CF8D74 80241204 24020002 */   addiu    $v0, $zero, 2
